#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n, m;
vector<int> e[N];
int sz[N], son[N], f[N][20], dep[N];
void dfs(int x){
    sz[x]=1; son[x]=0; dep[x]=dep[f[x][0]]+1;
    for(auto y:e[x]){
        dfs(y);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]]) son[x]=y;
    }
}
int top[N];
vector<int> vec[N];
int cnt[N];
void dfs2(int x, int tp){
    top[x]=tp; vec[tp].push_back(x);
    if(son[x]) dfs2(son[x], tp);
    for(auto y:e[x]) if(y^son[x]) dfs2(y, y);
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=2; i<=n; ++i){
        scanf("%d", &f[i][0]);
        e[f[i][0]].push_back(i);
    }
    for(int i=1; i<20; ++i){
        for(int j=1; j<=n; ++j) f[j][i]=f[f[j][i-1]][i-1];
    }
    dfs(1);
    dfs2(1, 1);
    cnt[1]=1;
    for(int i=1, u, l, r; i<=m; ++i){
        scanf("%d%d%d", &u, &l, &r);
        int res=u;
        while(true){
            if(cnt[top[res]]==0) {
                res=f[top[res]][0];
                continue;
            }
            res=vec[top[res]][min(cnt[top[res]]-1, dep[res]-dep[top[res]])];
            break;
        }
        if(dep[u]==dep[res]){
            printf("%d\n", l);
            return 0;
        }
        int dis=dep[u]-dep[res];
        if(dis<=r-l+1){
            printf("%d\n", l+dis-1);
            return 0;
        }
        int dt=dis-(r-l+1);
        for(int t=19; t>=0; --t) if((dt>>t)&1) u=f[u][t];
        while(u!=res){
            ++cnt[top[u]];
            u=f[u][0];
        }
    }
    printf("-1");
}
