#include <bits/stdc++.h>
// #define int long long
using namespace std;
const int N=1e5+5,M=355,mod=998244353;

int T,n,k;
vector <int> G[N];

void gmod(int &x){
    x%=mod;
}

namespace task1{
    int dp[N][M];
    int siz[N];
    int tmp[N];
    
    void dfs(int u,int fa){
        for(int i=0;i<=k+1;i++) dp[u][i]=0;
        siz[u]=1;
        dp[u][0]=0;
        dp[u][1]=1;
        
        for(int v: G[u]){
            if(v==fa) continue;
            dfs(v,u);
            
            int nsiz=siz[u]+siz[v];
            for(int i=0;i<=min(k+1,nsiz);i++) tmp[i]=0;
            for(int i=0;i<=min(k+1,siz[u]);i++){
                for(int j=0;j<=min(k+1,siz[v]) && i+j<=k+1;j++){
                    gmod(tmp[i+j]+=1ll*dp[u][i]*dp[v][j]%mod);
                }
            }
            for(int i=0;i<=min(k+1,nsiz);i++) dp[u][i]=tmp[i];
            
            siz[u]=nsiz;
        }
        
        gmod(dp[u][0]+=dp[u][k]+dp[u][k+1]);
        
        // cout<<u<<": ";
        // for(int i=0;i<=min(siz[u],k+1);i++) cout<<dp[u][i]<<" ";
        // cout<<endl;
    }
    
    void solve(){
        dfs(1,0);
        printf("%lld\n",dp[1][0]);
    }
}
namespace task2{
    int f[N][M],g[N][M];
    
    
    int ans;
    int siz[N];
    int tmp1[N],tmp2[N];
    
    void dfs(int u,int fa){
        siz[u]=1;
        f[u][0]=1; f[u][1]=0;
        g[u][0]=0; g[u][1]=0;
        
        for(int v: G[u]){
            if(v==fa) continue;
            dfs(v,u);
        }
        
        int rem=1;
        
        // cout<<"start "<<u<<endl;
        
        for(int v: G[u]){
            if(v==fa) continue;
            int r=siz[v]-siz[v]/k*k;
            rem+=r;
            // cout<<"  > "<<v<<" "<<r<<endl;
            
            int nsiz=siz[u]+siz[v];
            for(int i=0;i<=nsiz/k;i++) tmp1[i]=tmp2[i]=0;
            
            for(int i=0;i<=siz[u]/k;i++){
                for(int j=0;j<=siz[v]/k;j++){
                    gmod(tmp1[i+j]+=1ll*f[u][i]*f[v][j]%mod);
                    gmod(tmp2[i+j]+=1ll*f[u][i]*g[v][j]%mod);
                    gmod(tmp2[i+j]+=1ll*g[u][i]*f[v][j]%mod);
                }
            }
            for(int i=0;i<=nsiz/k;i++){
                f[u][i]=tmp1[i];
                g[u][i]=tmp2[i];
            }
            
            siz[u]=nsiz;
        }
        
        if(rem>=k){
            for(int i=0;i<=siz[u]/k;i++){
                g[u][i]=f[u][i];
                f[u][i]=0;
            }
            rem-=k;
        }
        
        int sp=0;
        for(int i=siz[u]/k;i>=0;i--){
            int tot=rem+k-i;
            if(tot<0 || tot>k+1) g[u][i]=0;
            
            if(tot==k+1){
                gmod(f[u][i+1]+=g[u][i]);
            }
            if(tot==k){
                gmod(f[u][i]+=g[u][i]);
            }
        }
        
        
        // cout<<"  "<<u<<", "<<"total rem = "<<rem<<endl;
        // cout<<"    ";
        // for(int i=0;i<=siz[u]/k;i++) cout<<f[u][i]<<" "; cout<<endl;
        // cout<<"    ";
        // for(int i=0;i<=siz[u]/k;i++) cout<<g[u][i]<<" "; cout<<endl;
        
    }
    
    void solve(){
        dfs(1,0);
        if(n%k>n/k) ans=0;
        else ans=f[1][n%k];
        printf("%lld\n",ans);
    }
}


signed main(){
    // freopen("Bin.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<n;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        if(1ll*k*k<=n) task1::solve();
        else task2::solve();
    }
}

