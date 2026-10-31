#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n, m;
char s[N], t[N];
int a[N], b[N];
int lin[N], nxt[N], to[N], tot;
void in(int x, int y){
    nxt[++tot]=lin[x]; lin[x]=tot; to[tot]=y;
}
vector<int> edcc[N]; int idx;
int dfn[N], low[N], timer, top; bool bri[N];
void tarjan(int x, int eid){
    dfn[x]=low[x]=++timer;
    for(int i=lin[x]; i; i=nxt[i]){
        int y=to[i];
        if(!dfn[y]){
            tarjan(y, i);
            low[x]=min(low[x], low[y]);
            if(dfn[x]<low[y]){
                bri[i]=bri[i^1]=1;
            }
        }
        else if(i!=(eid^1)){
            low[x]=min(low[x], dfn[y]);
        }
    }
}
int vis[N];
int sum[N];
void dfs(int x){
    edcc[idx].push_back(x); vis[x]=idx; sum[idx]^=b[x];
    for(int i=lin[x]; i; i=nxt[i]){
        if(bri[i]) continue;
        int y=to[i]; if(!vis[y]) dfs(y);
    }
}
vector<int> g[N]; int sz[N], w[N];
void clr(){
    for(int i=1; i<=n+1; ++i) dfn[i]=0, vis[i]=0, lin[i]=0;
    for(int i=1; i<=idx; ++i) edcc[i].clear(), g[i].clear(), sz[i]=w[i]=0, sum[i]=0;
    for(int i=1; i<=tot; ++i) bri[i]=0;
    tot=1; idx=0; timer=0;
}
int ql[N], qr[N];
void dfs2(int x, int fa){
    sz[x]=1; w[x]=sum[x];
    for(auto y:g[x]) if(y!=fa){
        dfs2(y, x); 
        sz[x]+=sz[y];
        w[x]^=w[y];
    }
}
void solve(){
    scanf("%d%d", &n, &m);
    scanf("%s", s+1);
    scanf("%s", t+1);
    for(int i=1; i<=n; ++i) a[i]=s[i]^t[i];
    a[n+1]=0;
    for(int i=1; i<=n+1; ++i) b[i]=a[i]^a[i-1];
    clr();
    for(int i=1; i<=m; ++i){
        scanf("%d%d", &ql[i], &qr[i]); ++qr[i];
        in(ql[i], qr[i]); in(qr[i], ql[i]);
    }
    for(int i=1; i<=n+1; ++i) if(!dfn[i]) tarjan(i, 0);
    for(int i=1; i<=n+1; ++i) if(!vis[i]) ++idx, dfs(i);
    for(int i=1; i<=m; ++i) if(vis[ql[i]]!=vis[qr[i]]){
        g[vis[ql[i]]].push_back(vis[qr[i]]);
        g[vis[qr[i]]].push_back(vis[ql[i]]);
    }
    for(int i=1; i<=idx; ++i) if(sz[i]==0){
        dfs2(i, 0);
        if(w[i]){
            for(int i=1; i<=m; ++i) printf("0"); putchar('\n');
            return ;
        }
    }
    for(int i=1; i<=m; ++i){
        if(vis[ql[i]]==vis[qr[i]]){
            printf("1"); continue;
        }
        int x=vis[ql[i]], y=vis[qr[i]];
        if(sz[x]>sz[y]) swap(x, y);
        if(w[x]) printf("0");
        else printf("1");
    }
    putchar('\n');
}

signed main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}