#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n, m;
int ex[N], ey[N];
vector<int> e[N];
struct union_set{
    int fa[N];
    int get(int x){
        if(x==fa[x]) return x;
        return fa[x]=get(fa[x]);
    }
    void merge(int x, int y){
        x=get(x); y=get(y);
        fa[x]=y;
    }
    void init(){
        for(int i=1; i<=n; ++i) fa[i]=i;
    }
}S;
bool oddocc, evenocc;
bool vis[N]; int col[N];
int f[N][20], dep[N];
vector<int> g[N];
int deg[N];
void dfs(int x){
    vis[x]=1; dep[x]=dep[f[x][0]]+1;
    for(auto y:e[x]) {
        if(!vis[y]){
            col[y]=col[x]^1;
            g[x].push_back(y);
            f[y][0]=x;
            for(int i=1; i<20; ++i) f[y][i]=f[f[y][i-1]][i-1];
            deg[x]++; deg[y]++;
            dfs(y);
        }
        else if(col[x]==col[y]){
            oddocc=1;
        }
    }
}
int sum[N];
void dfs2(int x){
    for(auto y:g[x]) dfs2(y), sum[x]+=sum[y];
}
void dfs3(int x){
    for(auto y:g[x]) sum[y]+=sum[x], dfs3(y);
}
int lca(int x, int y){
    if(dep[x]<dep[y]) swap(x, y);
    // cout<<"!!!"<<x<<' '<<y<<endl;
    for(int i=19; i>=0; --i) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    // cout<<"???"<<x<<' '<<y<<endl;
    if(x==y) return x;
    for(int i=19; i>=0; --i) if(f[x][i]!=f[y][i]) x=f[x][i], y=f[y][i];
    return f[x][0];
}
vector<int> bin[N];
int main(){
    scanf("%d%d", &n, &m);
    S.init();
    for(int i=1, x, y; i<=m; ++i){
        scanf("%d%d", &x, &y);
        S.merge(x, y);
        e[x].push_back(y); e[y].push_back(x);
        ex[i]=x; ey[i]=y;
    }
    if(n<=3){
        printf("-1\n");
        return 0;
    }
    if(m==0){
        printf("5\n");
        return 0;
    }
    if(m==1){
        printf("4\n");
        return 0;
    }
    if(m==2){
        printf("3\n");
        return 0;
    }
    for(int i=1; i<=n; ++i) if(i==S.get(i)) dfs(i);
    bool flag1=0;
    for(int i=1; i<=m; ++i){
        if(e[ex[i]].size()>=2&&e[ey[i]].size()>=2) flag1=1;
    }
    if(flag1){
        for(int i=1, x, y; i<=m; ++i) {
            x=ex[i]; y=ey[i];
            if(dep[x]>dep[y]) swap(x, y);
            if(x==f[y][0]) continue;
            if(col[x]!=col[y]) evenocc=1;
            else ++sum[x], ++sum[y], sum[lca(x, y)]-=2;
        }
        for(int i=1; i<=n; ++i) if(i==S.get(i)) dfs2(i), dfs3(i);
        for(int i=1, x, y; i<=m; ++i){
            x=ex[i]; y=ey[i];
            if(dep[x]>dep[y]) swap(x, y);
            if(x==f[y][0]) continue;
            if(col[x]!=col[y]) continue;
            // cout<<x<<' '<<y<<' '<<lca(x, y)<<' '<<dep[x]<<' '<<dep[y]<<' '<<dep[lca(x, y)]<<endl;
            if(sum[x]+sum[y]-2*sum[lca(x, y)]!=dep[x]+dep[y]-2*dep[lca(x, y)]){
                evenocc=1;
            }
        }
        // cout<<evenocc<<endl;
        int ans=0;
        bool flag=1;
        for(int i=1; i<=n; ++i) bin[S.get(i)].push_back(i);
        for(int i=1; i<=n; ++i) if(bin[i].size()>1){
            sort(bin[i].begin(), bin[i].end(), [&](int x, int y){return deg[x]>deg[y];});
            for(int j=1; j<(int)bin[i].size(); ++j) if(deg[bin[i][j]]!=1) flag=0;
        }
        if(flag){
            if(!oddocc) ans++;
            if(!evenocc) ans+=2;
        }
        else{
            if(!oddocc) ans++;
            if(!evenocc) ans++;
        }
        printf("%d\n", ans);
        return 0;
    }
    int mxd=0;
    for(int i=1; i<=n; ++i) mxd=max(mxd, (int)e[i].size());
    if(mxd>=2){
        if(mxd>=3) printf("2\n");
        else printf("3\n");
        return 0;
    }
    printf("3\n");
}
