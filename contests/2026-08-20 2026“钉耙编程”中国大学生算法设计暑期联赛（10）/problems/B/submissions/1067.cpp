#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=12e5+5,mod=998244353;
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
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

int ID(int x){
    return (x & 1)?mod-1:1;
}

void gmodn(int &x){ x+=x>>31 & mod; }
void gmod(int &x) { x%=mod; }

namespace NTT{
    int in,g[N];
    void pre(int tl) {
        int l=__lg(tl)+1;
        int n=(1 << l);
        g[0]=1;
        g[n]=ksm(31,1 << (21-l));
        for(int i=l;i;i--) g[1 << (i-1)]=1ll*g[1 << i]*g[1 << i]%mod;
        for(int i=0;i<n;i++) g[i]=1ll*g[i & (i-1)]*g[i & (-i)]%mod;
    }
    int init(int tl) {
        int l=__lg(tl)+1;
        in=mod-((mod-1) >> l);
        return l;
    }
    void ntt(int *f, int n) {
        int v;
        for(int i=(n>>1);i;i >>= 1)
            for(int *t=g,*j=f;j!=f+n;j+=(i << 1),t++)
                for(int *k=j;k!=j+i;k++){
                    v=1ll*(*t)*k[i]%mod;
                    gmodn(k[i]=(*k)-v);
                    gmodn((*k)+=v-mod);
                }
    }
    void intt(int *f, int n) {
        int v;
        for(int i=1;i<n;i<<=1)
            for(int *t=g,*j=f;j!=f+n;j+=(i << 1),t++)
                for(int *k=j;k!=j+i;k++){
                    gmodn(v=(*k)+k[i]-mod);
                    k[i]=1ll*(*t)*(*k-k[i]+mod)%mod;
                    *k=v;
                }
        reverse(f+1,f+n);
        for(int i=0;i<n;i++) f[i]=1ll*f[i]*in%mod;
    }
    
    int A[N],B[N],C[N];
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
        ntt(A,(1<<lim));
        ntt(B,(1<<lim));
        
        for(int i=0;i<(1<<lim);i++) C[i]=1ll*A[i]*B[i]%mod;
        intt(C,(1<<lim));
        for(int i=0;i<=n+m;i++) s[i]=C[i];
    }
}


int F[N],G[N],H[N];


int solve(int k,int p){
    if(p==1) return 1;
    
    for(int i=0;i<=k;i++) F[i]=ksm(i,k)%mod*inv[i]%mod;
    for(int i=0;i<=k;i++) G[i]=ID(i)*inv[i]%mod;
    NTT::solve(H,F,G,k,k);
    
    // for(int i=0;i<=k;i++) cout<<H[i]<<" "; cout<<endl;
    
    int tot=0,ip=ksm(p,mod-2);
    for(int i=0;i<=k;i++) gmod(tot+=H[i]*mul[i]%mod*ksm(1+mod-p,i)%mod*ksm(ip,i+1)%mod);
    return tot*p%mod*ksm(1+mod-p,mod-2)%mod;
}

int T,k,p;

signed main(){
    init(N-5);
    NTT::pre(8e5);
    
    cin>>T;
    while(T--){
        cin>>k>>p;
        int x=solve(k,p),y=solve(k*2,p);
        cout<<(y+mod-x*x%mod)%mod<<endl;
    }
    
    
}