#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n;
inline void read(int& x){
    x=0;char c=getchar();bool f=0;
    for(;c<'0'||c>'9';c=getchar())f|=(c=='-');
    for(;c>='0'&&c<='9';c=getchar())
        x=(x<<1)+(x<<3)+(c^48);
    x=(f)?(-x):x;
}  
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
vector<pii> e[N];
int ans[N];
void opt(int x, int fa){
    for(auto [y, id]:e[x]) if(y!=fa){
        ans[id]=y; opt(y, x);
    }
}
int ex[N], ey[N];
int dp[N][2];
int rt;
bool fail;
// 0 -> up;  1 -> down
void dfs(int x, int fa, int rid){
    if(e[x].size()==1){
        dp[x][0]=1; dp[x][1]=0;
        return ;
    }
    vector<int> v1, v01, v0;
    for(auto [y, id]:e[x]){
        if(y==fa) continue;
        dfs(y, x, id);
        ex[id]=x; ey[id]=y;
        if(fail) return ;
        if(dp[y][0]&&dp[y][1]) v01.push_back(id);
        else if(dp[y][0]) v0.push_back(id);
        else if(dp[y][1]) v1.push_back(id);
    }
    dp[x][0]=dp[x][1]=0;
    // cout<<"x:"<<x<<endl;
    // cout<<"v1:";
    // for(auto t:v1) cout<<t<<' '; cout<<endl;
    // cout<<"v0:";
    // for(auto t:v0) cout<<t<<' '; cout<<endl;
    // cout<<"v01:";
    // for(auto t:v01) cout<<t<<' '; cout<<endl;
    {
        int max1=0;
        for(auto t:v1) max1=max(max1, t);
        int cnt=0;
        for(auto t:v0) cnt+=(t>max1);
        for(auto t:v01) cnt+=(t>max1);
        if(x!=rt) cnt+=(rid>max1);
        if(cnt>=2) dp[x][1]=1;
    }
    {
        int max1=0, max01=0;
        for(auto t:v1) max1=max(max1, t);
        for(auto t:v01) max01=max(max01, t);
        int cnt=0;
        int maxx=max(max1, max01);
        for(auto t:v0) cnt+=(t>maxx);
        if(x!=rt) cnt+=(rid>maxx);
        if(cnt==0) dp[x][1]=1;
    }
    {
        int max1=0;
        for(auto t:v1) max1=max(max1, t);
        if(x!=rt) max1=max(max1, rid);
        int cnt=0;
        for(auto t:v0) cnt+=(t>max1);
        for(auto t:v01) cnt+=(t>max1);
        if(cnt>=2) dp[x][0]=1;
    }
    {
        int max1=0, max01=0;
        for(auto t:v1) max1=max(max1, t);
        if(x!=rt) max1=max(max1, rid);
        for(auto t:v01) max01=max(max01, t);
        int maxx=max(max1, max01);
        int cnt=0;
        for(auto t:v0) cnt+=(t>maxx);
        if(cnt==0) dp[x][0]=1;
    }
    if(dp[x][0]==0&&dp[x][1]==0){
        fail=1;
    }
}
void dfs2(int x, int fa, int rid, int dir){
    if(e[x].size()==1){
        return ;
    }
    vector<int> v1, v01, v0;
    for(auto [y, id]:e[x]){
        if(y==fa) continue;
        if(dp[y][0]&&dp[y][1]) v01.push_back(id);
        else if(dp[y][0]) v0.push_back(id);
        else if(dp[y][1]) v1.push_back(id);
    }
    if(x!=rt){
        if(dir==0) v1.push_back(rid);
        else v0.push_back(rid);
    }
    {
        int max1=0;
        for(auto t:v1) max1=max(max1, t);
        int cnt=0;
        for(auto t:v0) cnt+=(t>max1);
        for(auto t:v01) cnt+=(t>max1);
        if(cnt>=2) {
            for(auto t:v1) {
                if(t==rid) continue;
                ans[t]=ey[t];
                dfs2(ey[t], x, t, 1);
            }
            for(auto t:v0) {
                if(t==rid) continue;
                ans[t]=ex[t];
                dfs2(ey[t], x, t, 0);
            }
            for(auto t:v01) {
                if(t==rid) continue;
                ans[t]=ex[t];
                dfs2(ey[t], x, t, 0);
            }
        }
        else{
            for(auto t:v1) {
                if(t==rid) continue;
                ans[t]=ey[t];
                dfs2(ey[t], x, t, 1);
            }
            for(auto t:v0) {
                if(t==rid) continue;
                ans[t]=ex[t];
                dfs2(ey[t], x, t, 0);
            }
            for(auto t:v01) {
                if(t==rid) continue;
                ans[t]=ey[t];
                dfs2(ey[t], x, t, 1);
            }
        }
    }
    
}
void solve(){
    read(n);
    for(int i=1; i<=n; ++i) e[i].clear();
    for(int i=1, x, y; i<n; ++i){
        read(x); read(y);
        e[x].push_back(mapa(y, i));
        e[y].push_back(mapa(x, i));
    }
    if(n==2){
        printf("2\n1\n");
        return ;
    }
    for(int i=1; i<n; ++i) if(e[i].size()!=1) rt=i;
    fail=0;
    dfs(rt, 0, -1);
    // cout<<rt<<endl;
    // for(int i=1; i<=n; ++i) cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
    if(fail){
        printf("2\n");
        opt(1, 0);
        for(int i=1; i<n; ++i){
            printf("%d%c", ans[i], " \n"[i==n-1]);
        }
        return ;
    }
    else{
        printf("1\n");
        dfs2(rt, 0, -1, 0);
        for(int i=1; i<n; ++i){
            printf("%d%c", ans[i], " \n"[i==n-1]);
        }
    }
}
int main(){
    read(T);
    while(T--){
        solve();
    }
}