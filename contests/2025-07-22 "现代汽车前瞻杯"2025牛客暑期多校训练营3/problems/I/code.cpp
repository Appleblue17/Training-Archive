#include <bits/stdc++.h>
using namespace std;
const int N=6e5+5,mod=998244353;
 
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1;
    }
    return tot;
}
 
int mul[N],inv[N],invv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
     
    invv[1]=1;
    for(int i=2;i<=lim;i++) invv[i]=1ll*(mod-mod/i)*invv[mod%i]%mod;
}
 
void gmodn(int &x){ x+=x>>31 & mod; }
void gmod(int &x) { x%=mod; }
int pr[N];
namespace NTT{
    int A[N],B[N],C[N],rev[N];
    void pre(){
        for(int mid = 1;mid < N/2;mid <<= 1){
            int Wn = ksm(3, (mod-1)/(mid<<1)); pr[mid] = 1;
            for(int i = 1;i < mid;++ i) pr[mid+i] = 1ll*pr[mid+i-1] * Wn % mod;
        }
    }
    int init(int n){
        int lim=0;
        while((1ll<<lim)<=n) lim++;
        for(int i=0;i<=(1<<lim)-1;i++)
            rev[i]=(rev[i>>1ll]>>1ll) | ((i & 1ll)<<(lim-1));
        return lim;
    }
    void ntt(int *A,int lim, int op){
        for(int i = 0;i < lim;++ i)
            if(i < rev[i]) swap(A[i], A[rev[i]]);
        for(int mid = 1;mid < lim;mid <<= 1)
            for(int i = 0;i < lim;i += mid<<1)
                for(int j = 0;j < mid;++ j){
                    int y = 1ll*A[mid+i+j] * pr[mid+j] % mod;
                    gmodn(A[mid+i+j] = A[i+j] - y); 
                    gmodn(A[i+j] += y - mod);
                }
        if(op==-1){
            reverse(A+1, A+lim);
            int inv=ksm(lim,mod-2);
            for(int i = 0;i < lim;++ i) A[i]=1ll*A[i]*inv%mod;
        }
    }   
    void solve(int *s,int* f,int* g,int n,int m){
        if(n+m<=150){
            for(int i=0;i<=n+m;i++) C[i]=0;
            for(int i=0;i<=n;i++)
                for(int j=0;j<=m;j++)
                    gmodn(C[i+j]+=1ll*f[i]*g[j]%mod-mod);
            for(int i=0;i<=n+m;i++) s[i]=C[i];
            return ;
        }
        int lim=init(n+m);
        for(int i=0;i<(1<<lim);i++) A[i]=B[i]=0;
        for(int i=0;i<=n;i++) A[i]=f[i];
        for(int i=0;i<=m;i++) B[i]=g[i];
        ntt(A,(1<<lim),1);
        ntt(B,(1<<lim),1);
        for(int i=0;i<(1<<lim);i++) C[i]=1ll*A[i]*B[i]%mod;
        ntt(C,(1<<lim),-1);
        for(int i=0;i<=n+m;i++) s[i]=C[i];
    }
}
 
namespace INV{
    int A[N],B[N],S[N];
    void solve(int *s,int *f,int n){
        S[0]=ksm(f[0],mod-2);
        S[1]=0;
        for(int len=2;len/2<=n;len<<=1){
            int lim=len<<1;
            for(int i=0;i<len;i++) A[i]=f[i],B[i]=S[i];
            for(int i=len;i<lim;i++) A[i]=B[i]=0;
            NTT::init(lim-1);
            NTT::ntt(A,lim,1);
            NTT::ntt(B,lim,1);
            for(int j=0;j<lim;j++)
                S[j]=(2ll*B[j]%mod+mod-1ll*A[j]*B[j]%mod*B[j]%mod)%mod;
            NTT::ntt(S,lim,-1);
            for(int j=len;j<lim;j++) S[j]=0;
        }
        for(int i=0;i<=n;i++) s[i]=S[i];
    }
}
 
namespace LN{
    int A[N],B[N];
    void solve(int *s,int *f,int n){
        for(int i=0;i<=n;i++) A[i]=f[i],B[i]=0;
        for(int i=1;i<=n;i++) B[i-1]=1ll*f[i]*i%mod;
 
        INV::solve(A,A,n);
        NTT::solve(A,A,B,n,n);
 
        for(int i=n-1;i>=0;i--) A[i+1]=1ll*A[i]*invv[i+1]%mod;
        A[0]=0;
 
        for(int i=0;i<=n;i++) s[i]=A[i];
    }
}
 
namespace EXP{
    int A[N],B[N],C[N],S[N];
    void solve(int *s,int *f,int n){
        A[0]=B[0]=C[0]=0;
        S[0]=1;
        for(int len=2;len/2<=n;len<<=1){
            int lim=len<<1;
            for(int i=0;i<len;i++) A[i]=f[i],B[i]=S[i];
             
            LN::solve(C,B,len-1);
            for(int i=0;i<len;i++) C[i]=(mod-C[i]+A[i])%mod;
            C[0]=(C[0]+1)%mod;
            NTT::init(lim-1);
            NTT::ntt(B,lim,1);
            NTT::ntt(C,lim,1);
            for(int j=0;j<lim;j++) S[j]=1ll*B[j]*C[j]%mod;
             
            NTT::ntt(S,lim,-1);
            for(int j=len;j<lim;j++) S[j]=0;
        }
        for(int i=0;i<=n;i++) s[i]=S[i];
    }
}
 
int T,k;
int n=200000;
int F[N],G[N],H[N];
 
signed main(){
    init(N-5);
    NTT::pre();
     
    cin>>T>>k; k++;
     
    for(int t=1;t<=n;t++){
        G[0]=1;
        for(int i=1;i*t<=n;i++){
            G[i]=ksm(1ll*ksm(invv[t],i)*inv[i]%mod,k);
        }
        LN::solve(H,G,n/t);
        for(int i=0;i<=n/t;i++) gmod(F[i*t]+=H[i]);
    }
    // for(int i=1;i<=n;i++) cout<<F[i]<<" "; cout<<endl;
    EXP::solve(F,F,n);
     
    // for(int i=1;i<=10;i++) cout<<ksm(mul[i],k)*F[i]%mod<<" ";
    while(T--){
        int n; scanf("%d",&n);
        printf("%lld\n",1ll*ksm(mul[n],k)*F[n]%mod);
    }
}
