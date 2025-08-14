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
int T, n, m;
int fa[N], a[N], w[N];
vector<int> e[N], g[N];
int dep[N];
int dfn[N], timer, low[N], scc[N], scccnt;
int stk[N], top; bool ins[N];
void tarjan(int x){
    low[x]=dfn[x]=++timer;
    stk[++top]=x; ins[x]=true;
    for(auto y:e[x]){
        if(!dfn[y]) tarjan(y), low[x]=min(low[x], low[y]);
        else if(ins[y]) low[x]=min(low[x], dfn[y]);
    }
    if(low[x]==dfn[x]){
        scccnt++;
        do{
            scc[x]=scccnt;
            x=stk[top--];  ins[x]=false;
        }while(low[x]!=dfn[x]);
    }
}
int pos[N], sz[N];
void dfs(int x){
    dfn[x]=++timer; pos[timer]=x; sz[x]=1;
    for(auto y:g[x]) dfs(y), sz[x]+=sz[y], w[x]+=w[y];
}
bitset<10001> f[10001];
int main(){
    // freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
    // freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
    read(n);
    for(int i=1; i<=n; ++i) read(a[i]);
    for(int i=1, x, y; i<n; ++i){
        read(x); read(y);
        fa[y]=x;
        e[x].ep(y);
    }
    read(m);
    unordered_map<ll, bool> h;
    for(int i=1, x, y; i<=m; ++i){
        read(x); read(y);
        if(x==y) continue;
        if(h.find(1000000000ll*x+y)==h.end()) e[x].ep(y);
        h[1000000000ll*x+y]=1;
    }
    int rt=1;
    for(int i=2; i<=n; ++i) if(!fa[i]) rt=i;
    tarjan(rt);
    for(int i=1; i<=n; ++i) fa[i]=0;
    for(int x=1; x<=n; ++x){
        w[scc[x]]+=a[x];
        for(auto y:e[x]){
            if(scc[x]!=scc[y]){
                g[scc[x]].ep(scc[y]);
                fa[scc[y]]=scc[x];
            }
        }
    }
    rt=1;
    for(int i=2; i<=scccnt; ++i) if(!fa[i]) rt=i;
    // cout<<rt<<endl;
    timer=0;
    dfs(rt);
    f[0][0]=1;
    for(int i=1; i<=timer; ++i){
        // cout<<pos[i]<<' '<<sz[pos[i]]<<' '<<w[pos[i]]<<endl;
        f[i+sz[pos[i]]-1]|=f[i-1]<<w[pos[i]];
        f[i]|=f[i-1];
    }
    cout<<f[timer].count();
    return 0;
}
