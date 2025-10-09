#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=4400,mod=998244353;

void gmod(int &x){
    x%=mod;
}

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
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int ID(int x){
    return (x & 1)?mod-1:1;
}
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return 1ll*mul[m]*inv[n]%mod*inv[m-n]%mod;
}

int n,m;
int p[N],s[N],b[N];

int f[N][N],g[N][N];


signed main(){
    init(N-5);
    scanf("%lld%lld",&m,&n);
    
    int sp=0;
    for(int i=0;i<=m;i++) scanf("%lld",&p[i]),sp+=p[i];
    sp=ksm(sp,mod-2);
    for(int i=0;i<=m;i++){
        p[i]=p[i]*sp%mod;
        s[i]=(s[i-1]+p[i])%mod;
    }
    // for(int i=0;i<=m;i++) cout<<s[i]<<" "; cout<<endl;
    
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
    
    for(int j=1;j<=m+1;j++) f[0][j]=s[j-1];
    
    for(int i=1;i<=n;i++){
        int tmp=ksm(f[i-1][i],b[i]);
        for(int j=i+1;j<=m+1;j++){
            f[i][j]=(ksm(f[i-1][j],b[i])+mod-tmp)%mod;
        }
    }
    
    g[n][m+1]=1;
    for(int i=n;i>=1;i--){
        int tmp=ksm(f[i-1][i],b[i]-1);
        for(int j=i+1;j<=m+1;j++){
            gmod(g[i-1][j]+=g[i][j]*ksm(f[i-1][j],b[i]-1)%mod*b[i]%mod);
            gmod(g[i-1][i]+=mod-g[i][j]*tmp%mod*b[i]%mod);
            // g[i][j]=(g[i-1][j]*ksm(f[i-1][j],b[i]-1)%mod+mod-g[i-1][i]*ksm(f[i-1][i],b[i]-1)%mod)%mod*b[i]%mod;
        }
        // for(int j=0;j<=m+1;j++) cout<<g[i][j]%mod<<" ";
        // cout<<endl;
    }
    
    
    for(int t=0;t<=m;t++){
        int ans=0;
        for(int j=t+1;j<=m+1;j++) gmod(ans+=g[0][j]*p[t]%mod);
        printf("%lld\n",ans);
    }
}
