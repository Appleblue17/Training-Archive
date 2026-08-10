#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1100,mod=1e9+9;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
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


struct complx {
    int A=0,B=0; // A+B \omega
    void pr(){
        cout<<A<<","<<B<<" ";
    }
};
const complx I={1,0},omega={0,1},omega2={-1,-1};

complx operator +(complx x,complx y){
    return (complx){(x.A+y.A)%mod,(x.B+y.B)%mod};
}
complx operator *(complx x,complx y){
    return (complx){(x.A*y.A%mod+mod-x.B*y.B%mod)%mod,(x.B*y.A%mod+x.A*y.B%mod+mod-x.B*y.B%mod)%mod};
}
complx operator *(complx x,int y){
    return (complx){x.A*y%mod,x.B*y%mod};
}
complx ksm(complx a,int x){
    complx tot=I;
    while(x){
        if(x & 1) tot=tot*a;
        a=a*a;
        x>>=1;
    }
    return tot;
}

complx fx[3];

int n,m,k;
int A,B,C;
complx ans;

signed main(){
    init(N-5);
    cin>>n>>m>>k;
    A=(k+3)/3;
    B=(k+2)/3;
    C=(k+1)/3;
    // cout<<A<<" "<<B<<" "<<C<<endl;
    fx[0]=I*A+I*B+I*C;
    fx[1]=I*A+omega*B+omega2*C;
    fx[2]=I*A+omega2*B+omega*C;
    
    for(int i=0;i<=n;i++){
        for(int j=0;i+j<=n;j++){
            int t=n-i-j;
            int w=mul[n]*inv[i]%mod*inv[j]%mod*inv[t]%mod;
            
            complx x=ksm(fx[0],i)*ksm(fx[1],j)*ksm(fx[2],t);
            complx y=ksm(fx[1],i)*ksm(fx[2],j)*ksm(fx[0],t);
            complx z=ksm(fx[2],i)*ksm(fx[0],j)*ksm(fx[1],t);
            complx sum=x+y+z;
            complx tot=ksm(sum,m);
            ans=ans+tot*w;
        }
    }
    int inv3=ksm(3,mod-2);
    cout<<ans.A*ksm(inv3,n+m)%mod;
}
