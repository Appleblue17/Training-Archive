#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+5,mod=998244353;
int n,M,p,q;
 
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
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
 
void gmod(int &x){
    x%=mod;
}
 
struct abc{
    int M[3][3];
    abc(int x=0){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                M[i][j]=(i==j)*x;
            }
        }
    }
};
abc operator +(abc X,abc Y){
    abc S;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            gmod(S.M[i][j]=X.M[i][j]+Y.M[i][j]);
        }
    }
    return S;
}
abc operator *(abc X,abc Y){
    abc S;
    for(int i=0;i<3;i++){
        for(int k=0;k<3;k++){
            for(int j=0;j<3;j++){
                gmod(S.M[i][k]+=X.M[i][j]*Y.M[j][k]%mod);
            }
        }
    }
    return S;
}
 
abc ksm(abc A,int x){
    abc T(1);
    while(x){
        if(x & 1) T=T*A;
        A=A*A;
        x>>=1;
    }
    return T;
}
int pre0[N],pre1[N];
 
int g[N],h[N];
int s1[N],s2[N];
 
signed main(){
    // freopen("1.txt","w",stdout);
    init(N-5);
     
    cin>>n>>M>>p; q=(1+mod-p)%mod;
    if(p==1){
        for(int i=0;i<=M;i++) printf("%lld ",n);
        return 0;
    }
    int ip=ksm((1+mod-p)%mod,mod-2);
    int pn=ksm(p,n);
     
     
    abc P;
    P.M[0][0]=p,P.M[0][2]=1;
    P.M[1][1]=p,P.M[1][2]=q;
    P.M[2][2]=1;
     
    abc Q=ksm(P,n);
    int A=Q.M[0][2],B=Q.M[1][2];
     
    int x=A*ksm(1+mod-B,mod-2)%mod;
     
    g[0]=(pn+mod-1)%mod*ksm(p-1,mod-2)%mod;
    h[0]=(1+pn*(n-1)%mod+mod-g[0])%mod*ksm(p-1,mod-2)%mod;
     
    int prod=1;
    for(int m=0;m<M;m++){
        prod=(n+m)%mod*prod%mod;
        g[m+1]=(g[m]+mod-p*prod%mod*inv[m+1]%mod*ksm(p,n-1)%mod)%mod*ip%mod;
        h[m+1]=(h[m]+p*g[m+1]%mod+mod-n%mod*prod%mod*inv[m+1]%mod*pn%mod)%mod*ip%mod;
         
        // cout<<g[m]<<" "<<h[m]<<endl;
    }
    // cout<<endl;
     
    int s1=0,s2=0;
    prod=1;
    for(int m=0;m<=M;m++){
        int val=prod*inv[m]%mod*pn%mod*ksm(q,m)%mod;
        gmod(s1+=(n+m)%mod*val%mod);
        gmod(s2+=val);
        int ans=s1,sum=s2;
         
        gmod(ans+=(1+mod-sum)%mod*x%mod);
        gmod(ans+=(g[m]*(m+1)%mod+h[m])%mod*ksm(q,m+1)%mod);
        prod=(n+m)%mod*prod%mod;
        printf("%lld ",ans);
    }
     
}
