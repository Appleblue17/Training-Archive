#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,mod=998244353;
 
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
int s1[N],s2[N],s3[N];
 
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
     
    invv[1]=1;
    for(int i=2;i<=lim;i++) invv[i]=(mod-mod/i)*invv[mod%i]%mod;
     
    for(int i=1;i<=lim;i++){
        s1[i]=(s1[i-1]+invv[i])%mod;
        s2[i]=(s2[i-1]+invv[i]*invv[i]%mod)%mod;
        s3[i]=(s3[i-1]+invv[i]*invv[i]%mod*invv[i]%mod)%mod;
    }
}
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return mul[m]*inv[n]%mod*inv[m-n]%mod;
}
void gmod(int &x){
    x%=mod;
}
 
 
int T,n;
signed main() {
    init(N-5);
     
    cin>>T;
    while(T--){
        scanf("%lld",&n);
        int ans=0;
        int S1=0,S2=0,S3=0;
        S1=mul[n]*s1[n]%mod;
        S2=mul[n]*(s1[n]*s1[n]%mod+mod-s2[n])%mod;
        S3=mul[n]*(s1[n]*s1[n]%mod*s1[n]%mod+mod-s1[n]*s2[n]%mod*3%mod+s3[n]*2%mod)%mod;
         
        ans=(S1+S2*3%mod+S3)%mod;
        printf("%lld\n",ans);
    }
     
     
}
