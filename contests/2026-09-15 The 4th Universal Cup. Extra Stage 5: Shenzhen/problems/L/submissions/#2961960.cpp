#include <bits/stdc++.h>
using namespace std;
const int N=3010;
int T,n,m,p[N],v[N],w[N],id[N];

bool cmp(int i,int j){
    return v[i] < v[j];
}

double f[N][N];

void solve(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++){
        p[i] = v[i] = w[i] = 0;
        for(int j=0;j<=m;j++){
            f[i][j] = -1e30;
        }
    }
    double ans = -1e30;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&p[i],&v[i],&w[i]);
        id[i] = i;
    }
    sort(id+1,id+n+1,cmp);
    f[0][0] = 0;
    for(int i=1;i<=n;i++){
        int u = id[i];
        for(int j=0;j<=m;j++){
            f[i][j] = max(f[i][j],f[i-1][j]);
            if(j-w[u] >= 0)f[i][j] = max(f[i][j],f[i-1][j-w[u]]*(1.0-p[u]/100.0) + p[u]/100.0*v[u]);
            ans = max(ans,f[i][j]);
        }
    }
    printf("%.10lf\n",ans);
}

signed main(){
    scanf("%d",&T);
    while(T--){
        solve();
    }
}