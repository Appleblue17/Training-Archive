#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5,mod=998244353;
 
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1ll;
    }
    return tot;
}
 
int mul[N],inv[N],pw2[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
    
    pw2[0]=1;
    for(int i=1;i<=lim;i++) pw2[i]=2ll*pw2[i-1]%mod;
}
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return 1ll*mul[m]*inv[n]%mod*inv[m-n]%mod;
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

int T,n,m,K;
int a[N],c[N],A[N],F[N];
int g[N],s[N];

int pre1[N],pre2[N];
int pre[19][N];


int P[N],Q[N],W[N];
vector<int> solve(int n,vector <int> V){
    if(n==1) return V;
    
    vector <int> L,R,SL,SR,S;
    L.resize(n/2),R.resize(n/2); S.resize(n);
    for(int i=0;i<n/2;i++){
        L[i]=V[i*2];
        gmodn(R[i]=V[(i*2+n-1)%n]+V[(i*2+1)%n]-mod);
    }
    
    SL=solve(n/2,L);
    SR=solve(n/2,R);
    
    int t=NTT::init(n-1);
    for(int i=0;i<n/2;i++) Q[i]=1ll*SL[i]*inv[i]%mod;
    for(int i=n/2;i<n;i++) Q[i]=0;
    NTT::ntt(Q,n);
    for(int i=0;i<n;i++) W[i]=1ll*pre[t][i]*Q[i]%mod;
    NTT::intt(W,n);
    for(int i=0;i<n/2;i++) S[i*2]=1ll*W[i]*mul[i]%mod;
    
    for(int i=0;i<n/2;i++) Q[i]=1ll*SR[i]*inv[i]%mod;
    for(int i=n/2;i<n;i++) Q[i]=0;
    NTT::ntt(Q,n);
    for(int i=0;i<n;i++) W[i]=1ll*pre[t][i]*Q[i]%mod;
    NTT::intt(W,n);
    for(int i=0;i<n/2;i++) S[i*2+1]=1ll*W[i]*mul[i]%mod;
    
    return S;
}

signed main(){
    init(N-5);
    
    NTT::pre((1<<18)-1);
    for(int t=1;t<=18;t++){
        for(int i=0;i<(1<<(t-1));i++) pre[t][i]=1ll*inv[i]*pw2[i]%mod;
        NTT::init((1<<t)-1);
        NTT::ntt(pre[t],1<<t);
    }
    
    cin>>T;
    while(T--){
        scanf("%d%d%d",&n,&m,&K);
        K--;
        
        for(int i=0;i<n*2;i++) A[i]=c[i]=0;
        
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        reverse(a+1,a+n+1);
        
        int im=ksm(m,mod-2),in=ksm(n-1,mod-2);
        int alc=1ll*mul[n-1]%mod*ksm(m,2*(n-1))%mod;
        
        int w=0;
        for(int l=1,s=1;l<=n-1;l++,s=1ll*s*im%mod) gmodn(w+=1ll*s*inv[l]%mod-mod);
        c[1]=1ll*w*im%mod;
        
        for(int l=1,s=1;l<=n;l++,s=1ll*s*im%mod){
            gmodn(pre1[l]=pre1[l-1]+1ll*s*l%mod*inv[l+1]%mod-mod);
            gmodn(pre2[l]=pre2[l-1]+1ll*s*inv[l+1]%mod-mod);
        }
        
        for(int i=2;i<n;i++){
            c[i]=1ll*(pre1[n-i]+1ll*pre2[n-i]*(m-1)%mod*im%mod+mod-1)*im%mod;
        }
        c[n]=mod-im;
        
        for(int i=1;i<=n;i++) gmodn(c[i]+=1-mod);
        
        for(int i=0;i<n;i++) A[i]=A[n*2-1-i]=a[i+1];
        
        NTT::init(n*2-1);
        NTT::ntt(A,n*2);
        NTT::ntt(c,n*2);
        for(int i=0;i<n*2;i++) F[i]=1ll*A[i]*c[i]%mod;
        NTT::intt(F,n*2);
        
        vector <int> V; V.resize(n*2);
        for(int i=0;i<n*2;i++) V[i]=F[i];
        vector <int> S=solve(n*2,V);
        
        for(int i=0;i<=K;i++) P[i]=1ll*S[i]*inv[i]%mod;
        for(int i=0,s=1;i<=K;i++,s=1ll*s*(n+mod-3)%mod) Q[i]=1ll*s*inv[i]%mod;
        NTT::solve(W,P,Q,K,K);
        
        for(int i=0;i<=K;i++) printf("%lld\n",1ll*W[i]*mul[i]%mod*alc%mod);
    }
}