#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=220,mod=1e9+7;

void gmod(int &x){
    x%=mod;
}

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
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
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return mul[m]*inv[n]%mod*inv[m-n]%mod;
}
int bitc[5]={0,0,1,1,2};


int n,rt,ans;
vector <int> G[N];

int FA[N],f[N];
bool ANC[N][N];
int siz0[N];
void dfs0(int u,int fa){
    FA[u]=fa;
    int x=fa;
    while(x){
        ANC[u][x]=1;
        x=FA[x];
    }
    
    f[u]=1;
    siz0[u]=1;
    for(int v: G[u]){
        if(v==fa) continue;
        dfs0(v,u);
        siz0[u]+=siz0[v];
        f[u]=f[u]*inv[siz0[v]]%mod*f[v]%mod;
    }
    f[u]=f[u]*mul[siz0[u]-1]%mod;
}

int X;

int dp[5][N][N];
int tmp[5][N];

int trans[14][3]={
    {0,0,0},
    
    {1,1,0},
    {1,1,1},
    
    {2,2,0},
    {2,2,1},
    {2,1,2},
    
    {3,3,0},
    {3,3,1},
    {3,1,3},
    
    {4,4,0},
    {4,4,1},
    {4,2,3},
    {4,3,2},
    {4,1,4}
};

int siz[N];

void dfs(int u,int fa){
    if(u==X){
        siz[u]=siz0[u];
        for(int t=0;t<5;t++)
            for(int i=0;i<=siz[u];i++)
                dp[t][u][i]=0;
        dp[2][u][siz[u]-1]=f[u];
    }
    else{
        siz[u]=0;
        for(int t=0;t<5;t++) dp[t][u][0]=0;
        
        dp[0][u][0]=1;
        dp[1][u][0]=1;
        
        for(int v: G[u]){
            if(v==fa) continue;
            dfs(v,u);
            
            int nsiz=siz[u]+siz[v];
            for(int t=0;t<5;t++)
                for(int i=0;i<=nsiz;i++)
                    tmp[t][i]=0;
            
            for(int i=0;i<=siz[u];i++){
                for(int j=0;j<=siz[v];j++){
                    
                    for(int t=0;t<14;t++){
                        int z=trans[t][0],x=trans[t][1],y=trans[t][2];
                        
                        int sizu=siz[u]-i-bitc[x];
                        int sizv=siz[v]-j-bitc[y];
                        
                        gmod(tmp[z][i+j]+=dp[x][u][i]*dp[y][v][j]%mod*C(i+j,i)%mod*C(sizu+sizv,sizu)%mod);
                    }
                    
                }
            }
            
            for(int t=0;t<5;t++)
                for(int i=0;i<=nsiz;i++)
                    dp[t][u][i]=tmp[t][i];
            
            siz[u]=nsiz;
        }
        
        int nsiz=siz[u]+1;
        for(int t=0;t<5;t++)
            for(int i=0;i<=nsiz;i++)
                tmp[t][i]=0;
        
        for(int i=0;i<=siz[u];i++){
            gmod(tmp[0][i+1]+=dp[0][u][i]);
            gmod(tmp[1][i]+=dp[1][u][i]);
            gmod(tmp[2][i]+=dp[2][u][i]);
            gmod(tmp[3][i]+=dp[3][u][i]);
            gmod(tmp[4][i]+=dp[4][u][i]);
        }
        
        if(!ANC[X][u] && !ANC[u][X]){
            gmod(tmp[3][nsiz-1]+=f[u]*abs(u-X)%mod);
        }
        if(u==FA[X]){
            int sum=siz[X]-1;
            int tot=f[X]*inv[sum]%mod;
            for(int v: G[u]){
                if(v==fa || v==X) continue;
                tot=tot*f[v]%mod*inv[siz[v]]%mod;
                sum+=siz[v];
            }
            tot=tot*mul[sum]%mod;
            gmod(tmp[4][nsiz-2]+=tot*abs(u-X)%mod);
        }
        
        for(int t=0;t<5;t++)
            for(int i=0;i<=nsiz;i++)
                dp[t][u][i]=tmp[t][i];
        
        siz[u]=nsiz;
    }
}

signed main(){
    init(N-5);
    cin>>n>>rt;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    dfs0(rt,0);
    
    for(int u=1;u<=n;u++){
        X=u;
        dfs(rt,0);
        
        int tot=0;
        for(int i=0;i<=n;i++) gmod(tot+=dp[4][rt][i]);
        
        gmod(ans+=tot);
    }
    cout<<ans;
}


