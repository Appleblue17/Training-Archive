#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,mod=1e9+7;
 
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
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return mul[m]*inv[n]%mod*inv[m-n]%mod;
}
void gmod(int &x){
    x%=mod;
}
 
 
int T,n,k;
signed main() {
    init(N-5);
    cin>>T;
    while(T--){
    scanf("%lld%lld",&n,&k);
    printf("%lld\n",k*ksm(n-k+1,mod-2)%mod);
    }
}