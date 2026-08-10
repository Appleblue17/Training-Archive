#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
const int N=2e6+5;
typedef long long ll;
int n, m;
vector<pair<int, int> > e[N];
int val[N]; ll dis[N];
int sz[N], son[N], dep[N], top[N], f[N];
void dfs(int x, int fa){
    f[x]=fa; sz[x]=1; dep[x]=dep[fa]+1;
    for(auto [y, z]:e[x]) if(y!=fa){
        val[y]=z; dis[y]=dis[x]+z;
        dfs(y, x);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]]) son[x]=y;
    }
}
int dfn[N], seq[N], timer;
vector<int> g[N];
inline void in(int x, int y){
    // cout<<x<<"->"<<y<<endl;
    g[x].push_back(y);
}
void dfs2(int x, int tp){
    top[x]=tp;
    dfn[x]=++timer; seq[timer]=x;
    if(son[x]) dfs2(son[x], tp), in(son[x]+m, x+m);
    for(auto [y, z]:e[x]) if(y!=f[x]&&y!=son[x]){
        dfs2(y, y);
    }
}
int idx;
int id[N<<2];
void build(int p, int l, int r){
    id[p]=++idx;
    if(l==r) return ;
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    in(id[p], id[p<<1]); in(id[p], id[p<<1|1]);
}
void ins(int p, int l, int r, int x, int v){
    if(l==r) {
        in(id[p], v);
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) ins(p<<1, l, mid, x, v);
    else ins(p<<1|1, mid+1, r, x, v);
}
void upd(int p, int l, int r, int L, int R, int x){
    if(L<=l&&r<=R){
        in(x, id[p]);
        return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid) upd(p<<1, l, mid, L, R, x);
    if(R>mid) upd(p<<1|1, mid+1, r, L, R, x);
}
int lca(int x, int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x, y);
        x=f[top[x]];
    }
    if(dfn[x]>dfn[y]) return y;
    return x;
}
void work(int x, int y, int id){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x, y);
        in(id, x+m);
        x=f[top[x]];
    }
    if(dfn[x]>dfn[y]) swap(x, y);
    // cout<<dfn[x]<<' '<<dfn[y]<<endl;
    upd(1, 1, n, dfn[x], dfn[y], id);
}
int ddfn[N], ttimer, low[N], sccid[N], scccnt;
int stk[N], tp; bool vis[N];
void tarjan(int x){
    low[x]=ddfn[x]=++ttimer;
    stk[++tp]=x; vis[x]=1;
    for(auto y:g[x]){
        if(!ddfn[y]) tarjan(y), low[x]=min(low[x], low[y]);
        else if(vis[y]) low[x]=min(low[x], ddfn[y]);
    }
    if(low[x]==ddfn[x]){
        scccnt++;
        do{
            sccid[x]=scccnt;
            x=stk[tp--]; vis[x]=0;
        }while(low[x]!=ddfn[x]);
    }
}
vector<int> scc[N];
int degout[N];
int mx[N], my[N];
bool sp[N];
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1, x, y, z; i<n; ++i){
        scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(make_pair(y, z));
        e[y].push_back(make_pair(x, z));
    }
    dfs(1, 0); dfs2(1, 1); 
    idx=n+m;
    build(1, 1, n);
    for(int i=1, x, y; i<=m; ++i){
        scanf("%d%d", &x, &y);
        mx[i]=x; my[i]=y;
        if(x!=y) sp[x]=1, sp[y]=1;
        in(x+m, i); in(y+m, i);
        ins(1, 1, n, dfn[x], i);
        ins(1, 1, n, dfn[y], i);
        work(x, y, i);
    }
    // exit(0);
    for(int i=1; i<=n; ++i) if(!sp[i]){
        printf("0\n");
        return 0;
    }
    for(int i=1; i<=idx; ++i) if(!ddfn[i]) tarjan(i);
    for(int i=1; i<=m; ++i){
        scc[sccid[i]].push_back(mx[i]);
        scc[sccid[i]].push_back(my[i]);
    }
    for(int i=1; i<=idx; ++i) {
        for(auto j:g[i]) if(sccid[i]!=sccid[j]){
            ++degout[sccid[i]];
            break;
        }
    }
    ll ans=1e18;
    for(int i=1; i<=scccnt; ++i) if(degout[i]==0&&!scc[i].empty()){
        sort(scc[i].begin(), scc[i].end(), [&](int x, int y){return dfn[x]<dfn[y];});
        ll cur=0;
        for(int j=0; j+1<(int)scc[i].size(); ++j){
            cur+=dis[scc[i][j]]+dis[scc[i][j+1]]-2ll*dis[lca(scc[i][j], scc[i][j+1])];
        }
        cur+=dis[scc[i][0]]+dis[scc[i].back()]-2ll*dis[lca(scc[i][0], scc[i].back())];
        ans=min(ans, cur);
    }
    printf("%lld\n", ans);
}
