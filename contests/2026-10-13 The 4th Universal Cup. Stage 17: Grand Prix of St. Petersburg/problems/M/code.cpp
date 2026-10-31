#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
#define ep emplace_back
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=1e6+5;
int Test, a, b, m;
int tp[N], l[N], r[N];
int sum[N];
int w[N];
int S, T, tot;
int lin[N], nxt[N], to[N], val[N];
int way[N];
void in(int x, int y, int z){
    // cout<<x<<' '<<y<<' '<<z<<endl;
    to[++tot]=y; val[tot]=z; nxt[tot]=lin[x]; lin[x]=tot;
}
int dep[N];
bool bfs(){
    for(int i=1; i<=T; ++i) dep[i]=0;
    queue<int> q; q.push(S);
    dep[S]=1;
    way[S]=lin[S];
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int i=lin[x]; i; i=nxt[i]){
            int y=to[i];
            if(val[i]&&(!dep[y])){
                dep[y]=dep[x]+1;
                way[y]=lin[y];
                if(y==T) return 1;
                q.push(y);
            }
        }
    }
    return 0;
}
int dfs(int x, int now){
    if(x==T) return now;
    int ret=0;
    for(int i=way[x]; i&&ret<now; i=nxt[i]){
        int y=to[i];
        way[x]=i;
        if(val[i]&&dep[y]==dep[x]+1){
            int res=dfs(y, min(val[i], now-ret));
            if(res==0) dep[y]=0;
            val[i]-=res;
            val[i^1]+=res;
            ret+=res;
        }
    }
    return ret;
}
void solve(){
    read(a); read(b); read(m);
    for(int i=1; i<=m*2+1; ++i) sum[i]=0, w[i]=0;
    for(int i=1; i<=m; ++i){
        read(tp[i]); read(l[i]); read(r[i]); ++r[i];
        sum[l[i]]++; sum[r[i]]--;
        if(tp[i]==2) --w[l[i]], ++w[r[i]];
    }
    for(int i=1; i<=m*2; ++i) {
        sum[i]+=sum[i-1];
        if(sum[i]>a+b) {
            printf("No\n");
            return ;
        }
    }
    tot=1;
    for(int i=1; i<=m*2+4; ++i) lin[i]=0;
    for(int i=1; i<=m; ++i) if(tp[i]==1) {
        in(l[i], r[i], 1); in(r[i], l[i], 0);
    }
    for(int i=1; i<m*2; ++i){
        in(i, i+1, a+b-sum[i]); in(i+1, i, 0);
    }
    in(m*2+2, 1, a); in(1, m*2+2, 0); 
    in(m*2, m*2+1, a); in(m*2+1, m*2, 0);
    in(m*2+1, m*2+2, 1e9); in(m*2+2, m*2+1, 0);
    int cut=tot;
    S=m*2+3, T=S+1;
    for(int i=1; i<=m*2+1; ++i){
        if(w[i]==0) continue;
        if(w[i]>0) in(S, i, w[i]), in(i, S, 0);
        else in(i, T, -w[i]), in(T, i, 0);
    }
    while(bfs()) dfs(S, 1);
    for(int i=cut+1; i<=tot; i+=2) {
        if(val[i]!=0) {printf("No\n"); return ;}
    }
    printf("Yes\n");
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(Test);
	while(Test--){
		solve();
	}
	return 0;
}
