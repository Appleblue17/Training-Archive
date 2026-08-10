#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,INF=1e18,mod=998244353;
int T,n;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1ll;
    }
    return tot;
}

bool notpr[N];
int pr[N],pid,mu[N];

int mul[N],inv[N];
void init(int lim){
    mu[1]=1;
    for(int i=2;i<=lim;i++){
        if(!notpr[i]) pr[++pid]=i,mu[i]=mod-1;
        for(int j=1;j<=pid && pr[j]<=lim/i;j++){
            notpr[i*pr[j]]=1;
            if(i%pr[j]) mu[i*pr[j]]=(mod-mu[i])%mod;
            else break;
        }
    }
    
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
int binom(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return mul[m]*inv[n]%mod*inv[m-n]%mod;
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

int f[N],p[N],s[N];
int A[N],B[N],C[N];

signed main(){
    init(N-5);
    NTT::pre(1e6);
    
    // for(int i=1;i<=10;i++) cout<<mu[i]<<" "; cout<<endl;
    
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) f[i]=p[i]=s[i]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n/i;j++)
                gmod(f[i*j]+=mu[i]*j%mod);
        }
        // for(int i=1;i<=n;i++) cout<<f[i]<<" "; cout<<endl;
        
        for(int i=1;i<=n;i++){
            int m=n/i;
            for(int j=0;j<=m;j++) A[m-j]=mul[i*j];
            for(int j=0;j<=m;j++) B[j]=inv[i*j];
            NTT::solve(C,A,B,m,m);
            for(int j=1;j<=m;j++) gmod(p[i*j]+=f[i]*inv[i*j]%mod*C[m-j]%mod);
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n/i;j++)
                gmod(s[i]+=j*p[i*j]%mod);
        }
        // for(int i=1;i<=n;i++) cout<<s[i]<<" "; cout<<endl;
        
        int ans=0;
        for(int i=1;i<=n;i++) gmod(ans+=s[i]*f[i]%mod);
        cout<<ans<<endl;
    }
}