// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
const int N=2e5+5,K=110,mod=998244353;

int T,n,k;
vector <int> Gr[N];

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1;
    }
    return tot;
}
int mul[N],inv[N];
int invv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
    
    invv[1]=1;
    for(int i=2;i<=lim;i++) invv[i]=1ll*(mod-mod/i)*invv[mod%i]%mod;
}

inline void read(int &x){
    x=0; char c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c-'0'), c=getchar();
}

vector <int> f[N],g[N],h[N];

int siz[N];
int F[K],G[K],H[K],W[K];
void gmod(int &x){
    x%=mod;
}

void dfs(int u,int fa){
    f[u].resize(1);
    g[u].resize(1);
    h[u].resize(1);
    f[u][0]=1,g[u][0]=1,h[u][0]=0;
    
    siz[u]=0;
    
    for(int v: Gr[u]){
        if(v==fa) continue;
        dfs(v,u);
        
        int nsiz=min(k,siz[u]+siz[v]+1);
        for(int t=0;t<=nsiz;t++){
            F[t]=G[t]=H[t]=0;
        }
        
        for(int t=0;t<=siz[u];t++){
            for(int i=0;i<=siz[v] && i+t<=nsiz;i++){
                gmod(F[t+i]+=1ll*f[u][t]*f[v][i]%mod);
                gmod(F[t+i+1]+=1ll*f[u][t]*f[v][i]%mod);
                
                gmod(G[t+i]+=1ll*g[u][t]*f[v][i]%mod);
                gmod(G[t+i]+=1ll*f[u][t]*g[v][i]%mod);
                gmod(G[t+i+1]+=1ll*g[u][t]*f[v][i]%mod);
                
                gmod(H[t+i]+=1ll*h[u][t]*f[v][i]%mod);
                gmod(H[t+i]+=1ll*g[u][t]*g[v][i]%mod);
                gmod(H[t+i]+=1ll*f[u][t]*h[v][i]%mod);
                gmod(H[t+i+1]+=1ll*h[u][t]*f[v][i]%mod);
                gmod(H[t+i+1]+=1ll*f[u][t]*h[v][i]%mod);
            }
        }
        f[u].resize(nsiz+1);
        g[u].resize(nsiz+1);
        h[u].resize(nsiz+1);
        for(int i=0;i<=nsiz;i++){
            f[u][i]=F[i];
            g[u][i]=G[i];
            h[u][i]=H[i];
        }
        siz[u]=nsiz;
    }
}

int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return 1ll*mul[m]*inv[n]%mod*inv[m-n]%mod;
}

signed main(){
    init(N-5);
    
    read(T);
    while(T--){
        read(n); read(n); read(k);
        
        for(int i=1;i<=n;i++){
            Gr[i].clear();
            f[i].resize(0);
            g[i].resize(0);
            h[i].resize(0);
        }
        
        for(int i=1;i<n;i++){
            int u,v; read(u),read(v);
            Gr[u].push_back(v);
            Gr[v].push_back(u);
        }
        
        dfs(1,0);
        
        for(int t=0;t<=k;t++){
            int ans=1ll*(1ll*h[1][t]*2%mod+1ll*n*C(n-1,t)%mod)%mod*ksm(C(n-1,t),mod-2)%mod;
            printf("%d ",ans);
        }
        printf("\n");
    }
}