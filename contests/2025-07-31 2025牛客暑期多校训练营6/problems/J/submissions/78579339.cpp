#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5500,mod=998244353;
 
int n;
vector<int> G[N];
 
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1ll;
    }
    return tot;
}
 
int mul[N],inv[N];
int invv[N];
 
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
     
    invv[1]=1;
    for(int i=2;i<=lim;i++) invv[i]=(mod-mod/i)*invv[mod%i]%mod;
}
 
int ID(int x){
    return (x & 1ll)?mod-1:1;
}
void gmod(int &x){
    x%=mod;
}
 
int f[N][N],g[N][N],siz[N];
 
void dfs(int u,int fa){
    f[u][1]=1;
    g[u][0]=1;
    siz[u]=1;
    for(int v: G[u]){
        if(v==fa) continue;
        dfs(v,u);
         
        for(int i=siz[u];i>=0;i--){
            int F=f[u][i],G=g[u][i];
            f[u][i]=g[u][i]=0;
             
            for(int j=siz[v];j>=0;j--){
                gmod(f[u][i+j]+=mod-F*f[v][j]%mod);
                gmod(f[u][i+j+1]+=mod-F*g[v][j]%mod);
                 
                gmod(f[u][i+j]+=(f[v][j]+g[v][j])%mod*F%mod);
                gmod(g[u][i+j]+=(f[v][j]+g[v][j])%mod*G%mod);
            }
        }
         
        siz[u]+=siz[v];
    }
    // cout<<u<<": "<<endl;
    // for(int i=0;i<=n;i++) cout<<f[u][i]<<" ";
    // cout<<endl;
     
    for(int i=0;i<=siz[u];i++){
        gmod(f[u][i+1]+=mod-g[u][i]);
    }
     
    // for(int i=0;i<=n;i++) cout<<f[u][i]<<" ";
    // cout<<endl;
    // for(int i=0;i<=n;i++) cout<<g[u][i]<<" ";
    // cout<<endl;
}
 
signed main(){
    init(N-5);
    scanf("%lld",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
     
    dfs(1,0);
     
    int ans=0;
    for(int i=1;i<=n;i++){
        gmod(ans+=(f[1][i]+g[1][i])%mod*(n+1)%mod*invv[i+1]%mod);
    }
    cout<<ans*(mod-1)%mod;
}
