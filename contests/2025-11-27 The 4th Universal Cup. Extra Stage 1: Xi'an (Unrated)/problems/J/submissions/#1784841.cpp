#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5;
int T,n,m;
int c[N],nc[N],dep[N],fa[N][20],len[N];
vector<int> g[N],w[N];

void dfs(int u,int f){
    fa[u][0] = f;
    int mn=3e9,smn=3e9,amn=-1;
    
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v == f)continue;
        dep[v] = dep[u]+1;
        dfs(v,u);
        if(nc[v] < mn){
            smn = mn;
            mn = nc[v];
            amn = v;
        }
        else if(nc[v] < smn){
            smn = nc[v];
        }
    }
    
    nc[u] = min(c[u],mn+smn);
    
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v == f){
            w[u].push_back(-1);
            continue;
        }
        if(v != amn)w[u].push_back(mn);
        else w[u].push_back(smn);
        //printf("u=%lld,v=%lld,w=%lld\n",u,v,w[u][i]);
    }
}

void dfs2(int u,int f){
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v == f)continue;
        len[v] = len[u] + w[u][i];
        dfs2(v,u);
    }
}

int lca(int u,int v){
    if(dep[u]>dep[v])return lca(v,u);
    
    int dif = dep[v]-dep[u];
    
    for(int j=19;j>=0;j--){
        if(dif >= (1<<j)){
            v = fa[v][j];
            dif -= (1<<j);
        }
    }
    //printf("u=%lld,v=%lld,dif=%lld\n",u,v,dif);
    if(u == v)return u;
    else return -1;
}

void solve(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
        g[i].clear();
        w[i].clear();
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    fa[0][0]=0;
    dep[1]=0;
    len[1]=0;
    dfs(1,0);
    dfs2(1,0);
    //for(int i=1;i<=n;i++){
    //    printf("len[%lld]=%lld\n",i,len[i]);
    //}
    for(int j=1;j<=19;j++){
        for(int i=1;i<=n;i++){
            fa[i][j] = fa[fa[i][j-1]][j-1];
        }
    }
    
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        if(lca(x,y) == y){
            printf("%lld\n",len[x] - len[y]);
        }
        else{
            printf("-1\n");
        }
    }
}
signed main(){
    scanf("%lld",&T);
    while(T--){
        solve();
    }
    
}
