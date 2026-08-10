#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int T, n, m;
int elen[N], ecol[N];
int a[N];
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
vector<pii> e[N];
int sz[N], suma[N];
int f[N][N*2], g[N*2];
int L[N], R[N];
void dfs(int x, int fa){
    L[x]=min(0, a[x]-1); R[x]=a[x];
    f[x][R[x]+n]=0;
    for(auto [y, id]:e[x]){
        if(y==fa) continue;
        dfs(y, x);
        for(int i=L[x]+L[y]; i<=R[x]+R[y]; ++i) g[i+n]=1e9;
        for(int i=L[x]; i<=R[x]; ++i){
            for(int j=L[y]; j<=R[y]; ++j){
                if((abs(j)&1)!=ecol[id]) continue;
                g[i+j+n]=min(g[i+j+n], f[x][i+n]+f[y][j+n]+elen[id]*abs(j));
            }
        }
        for(int i=L[x]+L[y]; i<=R[x]+R[y]; ++i) f[x][i+n]=g[i+n];
        L[x]+=L[y];
        R[x]+=R[y];
    }
    for(int i=R[x]-1; i>=L[x]; --i){
        f[x][i+n]=min(f[x][i+n], f[x][i+1+n]);
    }
    // for(int i=L[x]; i<=R[x]; ++i){
    //     cout<<x<<' '<<i<<' '<<f[x][i+n]<<endl;
    // }
}
void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) a[i]=0, e[i].clear();
    for(int i=1, x, y; i<n; ++i){
        scanf("%d%d%d%d", &x, &y, &elen[i], &ecol[i]);
        e[x].push_back(mapa(y, i));
        e[y].push_back(mapa(x, i));
    }
    for(int i=1; i<=n; ++i){
        for(int j=0; j<=n+m; ++j){
            f[i][j]=1e9;
        }
    }
    for(int i=1, x; i<=m; ++i){
        scanf("%d", &x); ++a[x];
    }
    dfs(1, 0);
    if(f[1][n]==1e9) f[1][n]=-1;
    printf("%d\n", f[1][n]);
    // exit(0);
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}

