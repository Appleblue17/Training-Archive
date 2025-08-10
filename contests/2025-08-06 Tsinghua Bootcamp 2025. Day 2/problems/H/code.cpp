#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=44,mod=1e9+9;
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}

int mul[N],inv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
void gmod(int &x){
    x%=mod;
}

int T,n,k;
vector <int> G[N];

int dep[N],fat[N],siz[N];
int f[N],g[N];
void dfs0(int u,int fa){
    fat[u]=fa;
    dep[u]=dep[fa]+1;
    siz[u]=1; f[u]=1;
    for(int v: G[u]){
        if(v==fa) continue;
        dfs0(v,u);
        siz[u]+=siz[v];
        f[u]=f[u]*f[v]%mod*inv[siz[v]]%mod;
    }
    f[u]=f[u]*mul[siz[u]-1]%mod;
}

int sz[N],dp[N];
void dfs1(int u,int fa){
    sz[u]=1; dp[u]=1;
    for(int v: G[u]){
        if(v==fa) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        dp[u]=dp[u]*dp[v]%mod*inv[sz[v]]%mod;
    }
    dp[u]=dp[u]*mul[sz[u]-1]%mod;
}

namespace task1{
    int ans;
    int st;
    void dfs(int u,int fa){
        if(dep[fa]>dep[u]){
            // from downside
            if(n-siz[fa]==k) gmod(ans+=f[st]*g[fa]%mod);
        }
        else if(u>st){
            //from upside
            if(siz[u]==k) gmod(ans+=f[st]*f[u]%mod);
        }
        
        if(G[u].size()!=2) return ;
        for(int v: G[u]){
            if(v==fa) continue;
            dfs(v,u);
        }
    }
    
    void solve(){
        ans=0;
        for(int u=2;u<=n;u++){
            if(siz[u]!=k) continue;
            st=u;
            dfs(fat[u],u);
        }
        cout<<ans*2%mod;
    }
}

namespace task2{
    int ans;
    int lim;
    
    int dp[N][N][N];
    int tmp[N][N];
    
    void dfs(int u,int fa){
        siz[u]=1;
        dp[u][1][0]=1; dp[u][1][1]=0;
        
        for(int v: G[u]){
            if(v==fa) continue;
            dfs(v,u);
            
            int nsiz=siz[u]+siz[v];
            for(int i=1;i<=nsiz;i++){
                for(int j=0;j<=nsiz;j++){
                    tmp[i][j]=0;
                }
            }
            for(int i=1;i<=siz[u];i++){
                for(int j=0;j<=siz[u];j++){
                    if(!dp[u][i][j]) continue;
                    gmod(tmp[i][j+siz[v]]+=dp[u][i][j]*f[v]%mod*inv[siz[v]]%mod);
                    gmod(tmp[i][j]+=dp[u][i][j]*f[v]%mod*inv[siz[v]]%mod);
                    
                    for(int p=1;p<=siz[v];p++){
                        for(int q=0;q<=siz[v];q++){
                            if(!dp[v][p][q]) continue;
                            gmod(tmp[i+p][j+q]+=dp[u][i][j]*dp[v][p][q]%mod);
                        }
                    }
                }
            }
            swap(dp[u],tmp);
            
            siz[u]=nsiz;
        }
    }
    
    void solve(){
        ans=0;
        dfs(1,0);
        
        for(int u=1;u<=n;u++){
            lim=(n-k)-(n-siz[u]);
            if(lim<0) continue;
            int tot=dp[u][2*k-n][lim]*g[u]%mod*inv[n-siz[u]]%mod*mul[n-k]%mod*mul[n-k]%mod*mul[2*k-n]%mod;
            if(u!=1) tot=tot*2%mod;
            gmod(ans+=tot);
        }
        cout<<ans;
    }
}

signed main(){
    init(N-1);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v; scanf("%lld%lld",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin>>k;
    
    dfs0(1,0);
    g[1]=1;
    for(int u=2;u<=n;u++){
        int fa=fat[u];
        dfs1(fa,u);
        g[u]=dp[fa];
    }
    
    if(k==1 || k==n) cout<<mul[n];
    else if(k*2<=n){
        task1::solve();
    }
    else {
        task2::solve();
    }
}