#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,K=220;

int n,k,mod;
int ans[N];

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

int invv[N],mul[N],inv[N],S2[K][K];
void init(int lim,int limk){
    invv[1]=1;
    for(int i=2;i<=lim;i++) invv[i]=(mod-mod/i)*invv[mod%i]%mod;
    
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
    
    S2[0][0]=1;
    for(int i=1;i<=limk;i++){
        for(int j=1;j<=i;j++) gmod(S2[i][j]=S2[i-1][j-1]+S2[i-1][j]*j%mod);
    }
}
int ID(int x){
    return (x & 1ll)?mod-1:1;
}
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return mul[m]*inv[n]%mod*inv[m-n]%mod;
}
int A(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return C(m,n)*mul[n]%mod;
}

int f[K],g[K];

signed main(){
    // freopen("1.txt","w",stdout);
    cin>>n>>k>>mod;
    
    init(N-5,K-5);
    
    int m=n-1;
    for(int i=0;i<=k;i++){
        f[i]=ksm(m+1,k-i)*ID(i)%mod*C(k,i)%mod;
    }
    for(int i=0;i<=k;i++){
        for(int j=0;j<=i;j++){
            gmod(g[j]+=f[i]*ID(i-j)%mod*S2[i][j]%mod);
        }
    }

    for(int u=2;u<=n;u++){
        int p=u-2;
        
        int tot=0;
        for(int t=0;t<=k;t++){
            // int sum=0;
            // for(int l=p;l<=m;l++){
            //     // gmod(sum+=mul[l+t]%mod*inv[l]%mod*A(l,p)%mod);
            //     gmod(sum+=mul[p]*mul[t]%mod*C(t+p,p)%mod*C(l+t,t+p)%mod);
            // }
            // gmod(tot+=sum*g[t]%mod);
            
            gmod(tot+=mul[p]*mul[t]%mod*C(t+p,p)%mod*C(m+t+1,t+p+1)%mod*g[t]%mod);
        }
        
        tot=tot*(u-1)%mod*mul[n-u]%mod*inv[n-1]%mod;
        ans[u]=tot;
    }
    
    ans[1]=ksm(n,k);
    for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
}


