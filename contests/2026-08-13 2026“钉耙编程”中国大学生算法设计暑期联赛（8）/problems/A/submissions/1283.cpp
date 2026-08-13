#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=998244353;

int T,n,m,k;

int rd(){
    int tot=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}
vector<int> e[N];
int a[N];
bool ins[N];
vector<int> g[N];
bool vis[N];
bool check(int lim){
    for(int i=1; i<=n; ++i) g[i].clear(), vis[i]=0;
    for(int i=lim+1; i<=n; ++i){
        g[a[i]]=e[a[i]];
    }
    queue<int> que;
    que.push(1);
    while(!que.empty()){
        int x=que.front(); que.pop();
        if(x==n) return true;
        for(auto y:g[x]){
            if(!vis[y]) vis[y]=1, que.push(y);
        }
    }
    return false;
}
void solve(){
    n=rd(); m=rd(); k=rd();
    for(int i=1; i<=n; ++i){
        e[i].clear();
        ins[i]=0;
    }
    for(int i=1, x, y; i<=m; ++i){
        x=rd(); y=rd();
        e[x].push_back(y);
    }
    for(int i=1; i<=k; ++i) {
        a[i]=rd();
        ins[a[i]]=1;
    }
    int w=k;
    for(int i=1; i<=n; ++i) if(!ins[i]) a[++w]=i;
    if(!check(0)){
        printf("NO\n");
        return ;
    }
    int l=0, r=n, mid, ret=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            ret=mid; l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    if(ret>=k) printf("YES\n");
    else printf("%d\n", ret);
}
signed main(){
    T=rd();
    while(T--){
        solve();
    }
    
    
}