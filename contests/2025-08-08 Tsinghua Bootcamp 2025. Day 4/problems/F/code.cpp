#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5,mod=998244353;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1;
    }
    return tot;
}

int mul[N],inv[N],invS[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
    
    invS[0]=1;
    for(int i=1;i<=lim;i++) invS[i]=(invS[i-1]+inv[i])%mod;
}

void gmod(int &x){
    x%=mod;
}
void gmodn(int &x){
    x+=x>>31 & mod;
}

int cal(int n){
    if(n<0) return 0;
    return 1ll*mul[n]*invS[n]%mod;
}

int n,st,ed;
vector <int> G[N];
int pat[N],id;

int dfs0(int u,int fa){
    if(u==st){
        pat[++id]=u;
        return 1;
    }
    for(int v: G[u]){
        if(v==fa) continue;
        if(dfs0(v,u)){
            pat[++id]=u;
            return 1;
        }
    }
    return 0;
}

int dp[N];
int BAN;
void dfs(int u,int fa){
    for(int v: G[u]){
        if(v==fa || v==BAN) continue;
        dfs(v,u);
    }
    
    int k=0,sum=0;
    for(int v: G[u]){
        if(v==fa || v==BAN) continue;
        k++;
        gmod(sum+=dp[v]);
    }
    if(k){
        dp[u]=(cal(k)+mod-1+1ll*cal(k-1)*sum%mod)%mod;
    }
}

int f[N],g[N],A[N],B[N],D[N],E[N],F[N];
int a[N];

signed main(){
    init(N-5);
    scanf("%d%d%d",&n,&st,&ed);
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    dfs0(ed,0);
    
    for(int t=1;t<=id;t++){
        int u=pat[t],L=pat[t-1],R=pat[t+1];
        BAN=L;
        dfs(u,R);
        A[t]=dp[u];
        
        int k=0,sum=0,sum2=0;
        for(int v: G[u]){
            if(v==L || v==R) continue;
            a[++k]=(dp[v]+1)%mod;
            gmod(sum+=a[k]);
            gmod(sum2+=1ll*a[k]*a[k]%mod);
        }
        
        int tot=0;
        for(int i=0;i<=k-2;i++) gmod(tot+=1ll*mul[k-2]*inv[k-2-i]%mod*(i+1)%mod);
        
        int s1=(1ll*sum*sum%mod+mod-sum2)%mod;
        int s2=1ll*sum*(k-1)%mod;
        
        B[t]=1ll*tot*s1%mod;
        F[t]=1ll*tot*s2%mod;
        
        D[t]=(cal(k)+mod-1)%mod;
        
        E[t]=1ll*cal(k-1)*sum%mod;
    }
    
    f[1]=1;
    for(int i=1;i<id;i++){
        int val=(f[i]+g[i])%mod;
        
        gmod(f[i+1]+=val);
        gmod(f[i+2]+=val);
        gmod(f[i+3]+=val);
        
        gmod(f[i+1]+=1ll*f[i]*A[i]%mod);
        gmod(f[i+2]+=1ll*val*B[i+1]%mod);
        gmod(f[i+2]+=1ll*val*D[i+1]%mod);
        
        gmod(g[i+1]+=1ll*val*E[i+1]%mod);
        
        gmod(f[i+3]+=1ll*val*E[i+2]%mod);
        gmod(f[i+3]+=1ll*val*E[i+1]%mod);
        gmod(f[i+3]+=1ll*val*D[i+2]%mod);
        gmod(f[i+3]+=1ll*val*E[i+1]%mod*D[i+2]%mod);
        gmod(f[i+3]+=1ll*val*F[i+2]%mod);
        
        gmod(f[i+3]+=1ll*val*D[i+1]%mod*D[i+2]%mod);
        gmod(f[i+3]+=1ll*val*D[i+1]%mod);
        gmod(f[i+3]+=1ll*val*D[i+1]%mod*E[i+2]%mod);
        gmod(f[i+3]+=1ll*val*F[i+1]%mod);
        gmod(f[i+3]+=1ll*val*F[i+1]%mod*D[i+2]%mod);
        gmod(f[i+3]+=1ll*val*D[i+1]%mod*F[i+2]%mod);
    }
    
    // cout<<f[id]<<" "<<g[id]<<endl;
    cout<<(f[id]+g[id])%mod;
}