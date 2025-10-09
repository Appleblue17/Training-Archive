#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=550,mod=998244353;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}
void gmod(int &x){
    x%=mod;
}

int invv[N],mul[N],inv[N],S1[N][N];
void init(int lim){
    invv[1]=1;
    for(int i=2;i<=lim;i++) invv[i]=(mod-mod/i)*invv[mod%i]%mod;
    
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
    
    S1[0][0]=1;
    for(int i=1;i<=lim;i++){
        for(int j=1;j<=i;j++) gmod(S1[i][j]=S1[i-1][j-1]+S1[i-1][j]*(i-1)%mod);
    }
}
int ID(int x){
    return (x & 1ll)?mod-1:1;
}


int n;
vector <int> G[N];

int x;
int f[N][N],g[N][N],h[N][N];
int f0[N],g0[N],h0[N];
int P[N],Q[N],R[N];
int siz[N];



void dfs(int u,int fa){
    siz[u]=1;
    f[u][0]=1; f[u][1]=0;
    g[u][0]=1; g[u][1]=0;
    
    for(int v: G[u]){
        if(v==fa) continue;
        dfs(v,u);
        
        int nsiz=siz[u]+siz[v];
        
        for(int i=0;i<=nsiz;i++) P[i]=Q[i]=R[i]=0;
        for(int i=0;i<=siz[v];i++){
            gmod(P[i]=f[v][i]+(g0[v]*(i==0)+mod-g[v][i])%mod*x%mod+(h0[v]*(i==0)+mod-h[v][i])%mod);
        }
        
        for(int i=0;i<=siz[u];i++){
            for(int j=0;j<=siz[v];j++){
                gmod(Q[i+j]+=f[u][i]*P[j]%mod);
                gmod(R[i+j]+=g[u][i]*f[v][j]%mod);
            }
        }
        
        for(int i=0;i<=nsiz;i++){
            f[u][i]=Q[i];
            g[u][i]=R[i];
        }
        
        siz[u]=nsiz;
    }
    
    // cout<<u<<": "<<endl;
    // cout<<"  "; for(int i=0;i<=siz[u];i++) cout<<f[u][i]<<" "; cout<<endl;
    // cout<<"  "; for(int i=0;i<=siz[u];i++) cout<<g[u][i]<<" "; cout<<endl;
    
    for(int i=siz[u];i>=1;i--){
        f[u][i]=f[u][i-1]*invv[i]%mod;
        g[u][i]=g[u][i-1]*invv[i]%mod;
    }
    f[u][0]=g[u][0]=0;
    
    for(int i=0;i<=siz[u];i++) gmod(h[u][i]=f[u][i]+mod-g[u][i]);
    f0[u]=g0[u]=h0[u]=0;
    for(int i=0;i<=siz[u];i++){
        gmod(f0[u]+=f[u][i]);
        gmod(g0[u]+=g[u][i]);
        gmod(h0[u]+=h[u][i]);
    }
    
    // cout<<u<<": "<<f0[u]<<" "<<g0[u]<<" "<<h0[u]<<endl;
    // cout<<"  "; for(int i=0;i<=siz[u];i++) cout<<f[u][i]<<" "; cout<<endl;
    // cout<<"  "; for(int i=0;i<=siz[u];i++) cout<<g[u][i]<<" "; cout<<endl;
    // cout<<"  "; for(int i=0;i<=siz[u];i++) cout<<h[u][i]<<" "; cout<<endl;
}

int y[N],s[N],ans[N];


signed main(){
    init(N-5);
    
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    for(int k=1;k<=n;k++){
        x=k;
        // cout<<"-------- "<<k<<" ---------"<<endl;
        dfs(1,0);
        
        int res=(g0[1]*x%mod+h0[1])%mod;
        // cout<<"res: "<<res*mul[n]%mod<<endl;
        y[k]=res*mul[n]%mod;
    }
    
    // for(int i=0;i<=n;i++) cout<<y[i]<<" "; cout<<endl;
    
    for(int i=0;i<=n;i++){
        for(int j=0;i+j<=n;j++){
            gmod(s[i+j]+=y[i]*inv[i]%mod*ID(j)%mod*inv[j]%mod);
        }
    }
    
    // for(int i=0;i<=n;i++) cout<<s[i]<<" "; cout<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            gmod(ans[j]+=s[i]*ID(i-j)%mod*S1[i][j]%mod);
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
    
}


