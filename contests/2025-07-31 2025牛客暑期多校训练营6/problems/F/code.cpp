#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
const int N=1e5+5,M=70,mod=998244353,inv2=(mod+1)/2;
 
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1ll;
    }
    return tot;
}
 
int mul[M],inv[M];
int S1[M][M];
 
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
     
    S1[0][0]=1;
    for(int i=1;i<=lim;i++){
        for(int j=1;j<=i;j++) S1[i][j]=(1ll*(i-1)*S1[i-1][j]%mod+S1[i-1][j-1])%mod;
    }
}
void gmod(int &x){
    x%=mod;
}
int ID(int x){
    return (x & 1)?mod-1:1;
}
 
int n,m;
int f[N][M],g[N][M],dep[N][M];
int ans[M];
 
int F[M],G[N*2];
signed main(){
    init(M-1);
    cin>>n;
    m=ceil(log2(n))*4;
    // cout<<m<<endl;
     
    for(int i=0;i<=m;i++) dep[n][i]=i;
    for(int t=n;t>=2;t--){
        int ls=t/2,rs=(t+1)/2;
        for(int i=0;i<=m;i++){
            gmod(dep[ls][i]+=1ll*dep[t][i]*i%mod);
            gmod(dep[rs][i]+=1ll*dep[t][i]*i%mod);
        }
    }
     
    // for(int t=1;t<=n;t++){
    //     cout<<t<<": ";
    //     for(int i=0;i<=m;i++) cout<<dep[t][i]<<" ";
    //     cout<<endl;
    // }
     
    for(int i=0;i<=m;i++) f[1][i]=g[1][i]=i;
    for(int i=0;i<=m;i++) gmod(ans[i]+=dep[1][i]);
     
    for(int t=2;t<=n;t++){
        // cout<<t<<": "<<endl;
        int ls=t/2,rs=(t+1)/2;
        for(int i=0;i<=m;i++){
            int wf=1ll*(f[ls][i]+f[rs][i])*inv2%mod;
            int wg=1ll*(g[ls][i]+g[rs][i])*inv2%mod;
            gmod(f[t][i]+=1ll*(1+wf+1ll*(wf+mod-i)*i%mod)%mod*i%mod);
            gmod(g[t][i]+=1ll*(1+wg+1ll*(wg+mod-i)*i%mod)%mod*i%mod);
             
            int tmp=(1ll*f[ls][i]*g[rs][i]%mod+1ll*f[rs][i]*g[ls][i]%mod)%mod*inv2%mod;
            gmod(tmp+=mod-1ll*i*i%mod+1); // 不允许两边都不选
            gmod(ans[i]+=1ll*tmp*dep[t][i]%mod);
        }
        // cout<<"  "; for(int i=0;i<=m;i++) cout<<f[t][i]<<" "; cout<<endl;
        // cout<<"  "; for(int i=0;i<=m;i++) cout<<g[t][i]<<" "; cout<<endl;
    }
     
    // for(int i=0;i<=m;i++) cout<<ans[i]<<" "; cout<<endl;
     
    for(int i=0;i<=m;i++){
        for(int j=0;i+j<=m;j++){
            F[i+j]=(F[i+j]+1ll*ans[i]*inv[i]%mod*inv[j]%mod*ID(j)%mod)%mod;
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=i;j++){
            G[j]=(G[j]+1ll*F[i]*S1[i][j]%mod*ID(i-j)%mod)%mod;
        }
    }
    for(int i=1;i<=n*2;i++) printf("%d\n",G[i]);
}
