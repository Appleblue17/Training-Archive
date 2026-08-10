#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5100;
int n,a[N],f[N][N][2],siz[N];//0 always tells the truth. 1 always lies. f records the number of 1s.
int t[N][2];
vector<int> g[N];
const int p = 998244353;
void dfs(int u,int fa){
    siz[u]=1;
    f[u][0][0]=1;f[u][1][1]=1;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v == fa)continue;
        dfs(v,u);
        int m = siz[v];
        int n = siz[u];
        for(int k=0;k<=siz[u];k++){
            for(int o=0;o<=1;o++){
                t[k][o] = f[u][k][o];
                f[u][k][o]=0;
            }
        }
        siz[u]+=siz[v];
        for(int j=0;j<=m;j++){
            
            for(int k=j;k<=j+n;k++){
                for(int o=0;o<=1;o++){
                    f[u][k][o] += t[k-j][o]*(f[v][j][0]+f[v][j][1]);
                    f[u][k][o]%=p;
                }
            }
        }
    }
    
    f[u][siz[u]-a[u]][1] = 0;
    for(int i=0;i<=siz[u];i++){
        
        if(i != siz[u]-a[u])f[u][i][0]=0;
        
        //printf("f[%lld][%lld] = %lld,%lld\n",u,i,f[u][i][0],f[u][i][1]);
    }
}
void solve(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        g[i].clear();
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            f[i][j][0]=f[i][j][1]=0;
        }
        siz[i]=0;
        t[i][0]=t[i][1]=0;
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int ans=0;
    for(int i=0;i<=siz[1];i++){
        ans += f[1][i][0]+f[1][i][1];
        ans %= p;
    }
    printf("%lld\n",ans);
    
}
signed main(){
    int T;cin >> T;
    while(T--){
        solve();
    }
}
