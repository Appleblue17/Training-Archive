#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,m,mod;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}

void gmodn(int &x){
    x+=x>>31 & mod;
}
void gmod(int &x){
    x%=mod;
}

int mul[N],inv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
int ID(int x){
    return (x & 1)?mod-1:1;
}
int C(int m,int n){
    if(n<0 || m<0 || m<n) return 0;
    return mul[m]*inv[n]%mod*inv[m-n]%mod;
}

int S1(int k,int t,int m){
    if(!k && !t) return 1;
    int tot=0;
    for(int i=0;i*m<=k-1 && i<=t;i++){
        gmod(tot+=ID(i)*C(t,i)%mod*C(k-i*m-1,t-1)%mod);
    }
    return tot;
}
int S2(int k,int t,int m){
    return S1(k+t,t,m+1);
}

signed main(){
    cin>>n>>m>>mod;
    init(N-5);
    
    int ans=0;
    for(int t=1;t<=n;t++){
        for(int i=1;i<=m*(n-t);i++){
            int sum=0;
            // for(int j=0;j<=i;j++){
            //     gmod(sum+=S1(j,t,m));
            // }
            for(int r=0;r<=t && r*m<=i;r++){
                gmod(sum+=ID(r)*C(t,r)%mod*C(i-r*m,t)%mod);
            }
            sum=(ksm(m,t)+mod-sum)%mod;
            gmod(ans+=C(n,t)*S2(i,n-t,m)%mod*sum%mod);
        }
    }
    
    for(int x=1;x<=m;x++){
        for(int t=1;t<=n;t++){
            for(int i=x;i<=m*(n-t) && i<x*t;i+=x){
                int lim=min(m/x,t-2-i/x);
                if(lim<m/x){
                    // cout<<t<<" "<<i<<" "<<j<<": "<<C(n,t)*(S2(i/x,n-t,m/x)+mod-S2(i/x,n-t,lim))%mod<<endl;
                    gmod(ans+=mod-C(n,t)*(S2(i/x,n-t,m/x)+mod-S2(i/x,n-t,lim))%mod);
                }
            }
        }
    }
    
    gmod(ans+=ksm(m+1,n)+mod-n*m-1);
    cout<<ans*2%mod;
}

