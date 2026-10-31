#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+5,mod=998244353,inv2=(mod+1)/2;
int n,m,r,ans;

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
int binom(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return mul[m]*inv[n]%mod*inv[m-n]%mod;
}
int ID(int x){
    return (x & 1)?mod-1:1;
}
void gmod(int &x){
    x%=mod;
}

int buc[N];
int w[N];
int f[N];

signed main(){
    init(N-5);
    cin>>n>>m>>r;
    for(int i=1;i<=m;i++){
        int x; scanf("%lld",&x); buc[x]++;
    }
    
    int coef=ksm(inv2,n)*binom(n,r)%mod;
    for(int i=0;i<=n;i++)
        for(int j=0;j+i<=n;j++)
            gmod(w[i+j]+=binom(r,i)*ID(r-i)%mod*binom(n-r,j)%mod);
    
    for(int i=0;i<=n;i++) f[i]=binom(n,i)*ID(i)%mod;
    // for(int i=0;i<=n;i++) cout<<f[i]<<" "; cout<<endl;
    
    for(int p=0;p<=n;p++){
        int tot=1;
        for(int i=0;i<=n;i++) tot=tot*ksm(f[i],buc[i])%mod;
        gmod(ans+=tot*w[p]%mod);
        
        for(int i=0;i<n;i++) gmod(f[i+1]+=f[i]);
        // cout<<"  -> "; for(int i=0;i<=n;i++) cout<<f[i]<<" "; cout<<endl;
        
        f[n]=0;
        for(int i=n;i>=1;i--) f[i]=(f[i]+f[i-1])%mod;
        
        // for(int i=0;i<=n;i++) cout<<f[i]<<" "; cout<<endl;
    }
    cout<<ans*coef%mod<<endl;
}