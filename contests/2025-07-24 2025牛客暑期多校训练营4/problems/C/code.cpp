#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+5,mod=998244353;
 
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1ll;
    }
    return tot;
}
 
int mul[N],inv[N],invv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
 
    invv[1]=1;
    for(int i=2;i<=lim;i++) invv[i]=(mod-mod/i)*invv[mod%i]%mod;
}
 
int n,m,k,ans;
int C(int m,int n){
    int tot=inv[n];
    for(int i=m;i>=m-n+1;i--) tot=tot*(i%mod)%mod;
    return tot;
}
 
signed main(){
    init(N-5);
    cin>>n>>m>>k;
    int t=k-(m*(n-1)-m+1);
    // cout<<t<<endl;
     
    if(t<0 || t>m || m-1-t<0 || m-1-t>m*(n-1)) ans=0;
    else{
        ans=C(m,t)*C(m*(n-1),m-1-t)%mod*invv[m]%mod*mul[m]%mod;
    }
    cout<<ans;
}
