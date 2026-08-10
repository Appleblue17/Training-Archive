#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+5,mod=998244353,inv2=(mod+1)/2;

int n,m;
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1ll;
    }
    return tot;
}

int mul[N],inv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int C(int m,int n){
    if(m<n || m<0 || n<0) return 0;
    return 1ll*mul[m]*inv[n]%mod*inv[m-n]%mod;
}
int ID(int x){
    return (x & 1ll)?mod-1:1;
}

void gmod(int &x){
    x%=mod;
}
void gmodn(int &x){
    x+=(x>>31 & mod);
}
int ans;

namespace NTT{
    int in,g[N];
    void pre(int tl){
        int l=__lg(tl)+1;
        int n=(1<<l);
        g[0]=1;
        g[n]=ksm(31,1<<(21-l));
        for(int i=l;i;i--) g[1<<(i-1)]=g[1<<i]*g[1<<i]%mod;
        for(int i=0;i<n;i++) g[i]=g[i & (i-1)]*g[i & (-i)]%mod;
    }
    int init(int tl){
        int l=__lg(tl)+1;
        in=mod-((mod-1)>>l);
        return l;
    }
    void ntt(int *f,int n){
        int v;
        for(int i=(n>>1);i;i>>=1)
            for(int *t=g,*j=f;j!=f+n;j+=(i<<1),t++)
                for(int *k=j;k!=j+i;k++){
                    v=(*t)*k[i]%mod;
                    gmodn(k[i]=(*k)-v);
                    gmodn((*k)+=v-mod);
                }
    }
    
    void intt(int *f,int n){
        int v;
        for(int i=1;i<n;i<<=1)
            for(int *t=g,*j=f;j!=f+n;j+=(i<<1),t++)
                for(int *k=j;k!=j+i;k++){
                    gmodn(v=(*k)+k[i]-mod);
                    k[i]=(*t)*(*k+mod-k[i])%mod;
                    *k=v;
                }
        reverse(f+1,f+n);
        for(int i=0;i<n;i++) f[i]=1ll*f[i]*in%mod;
    }
    
    int A[N],B[N],C[N];
    void solve(int *s,int *f,int *g,int n,int m){
        
        int lim=init(n+m);
        for(int i=0;i<(1<<lim);i++) A[i]=B[i]=0;
        for(int i=0;i<=n;i++) A[i]=f[i];
        for(int i=0;i<=m;i++) B[i]=g[i];
        ntt(A,1<<lim);
        ntt(B,1<<lim);
        
        for(int i=0;i<(1<<lim);i++) C[i]=1ll*A[i]*B[i]%mod;
        intt(C,1<<lim);
        for(int i=0;i<=n+m;i++) s[i]=C[i];
    }
}

namespace INV{
    int A[N],B[N],S[N];
    void solve(int *s,int *f,int n){
        S[0]=ksm(f[0],mod-2);
        S[1]=0;
        for(int len=2;len<=(n<<1);len<<=1){
            int lim=len<<1;
            fill(A,A+lim,0);
            fill(B,B+lim,0);
            for(int i=0;i<=min(len-1,n);i++) A[i]=f[i];
            for(int i=0;i<len;i++) B[i]=S[i];
            
            int t=NTT::init(len);
            NTT::ntt(A,lim);
            NTT::ntt(B,lim);
            for(int i=0;i<lim;i++)
                S[i]=(2*B[i]%mod+mod-A[i]*B[i]%mod*B[i]%mod)%mod;
            NTT::intt(S,lim);
            for(int i=len;i<lim;i++) S[i]=0;
        }
        for(int i=0;i<=n;i++) s[i]=S[i];
    }
}

namespace Evaluation{
    int tmp[N];
    vector <int> P[N],Q[N];
    int lenp[N],lenq[N];
    
    void solve1(int *a,int o,int l,int r){
        if(l==r){
            P[o]={1,(mod-a[l])%mod};
            return ;
        }
        int mid=(l+r)>>1,ls=o<<1,rs=o<<1|1;
        int len=r-l+1,lenl=mid-l+1,lenr=r-mid;
        solve1(a,ls,l,mid);
        solve1(a,rs,mid+1,r);
        
        P[o].resize(len+1);
        NTT::solve(P[o].data(),P[ls].data(),P[rs].data(),lenl,lenr);
    }
    
    void solve2(int *s,int *a,int o,int l,int r){
        if(l==r){
            s[l]=Q[o][0];
            return ;
        }
        int mid=(l+r)>>1,ls=o<<1,rs=o<<1|1;
        int len=r-l+1,lenl=mid-l+1,lenr=r-mid;
        
        Q[ls].resize(lenl);
        NTT::solve(tmp,Q[o].data(),P[rs].data(),len-1,lenr);
        for(int i=0;i<lenl;i++) Q[ls][i]=tmp[i+lenr];
        
        Q[rs].resize(lenr);
        NTT::solve(tmp,Q[o].data(),P[ls].data(),len-1,lenl);
        for(int i=0;i<lenr;i++) Q[rs][i]=tmp[i+lenl];
        
        solve2(s,a,ls,l,mid);
        solve2(s,a,rs,mid+1,r);
    }
    
    void solve(int *s,int *f,int *a,int n,int m){
        m=max(n,m); n=max(n,m);
        solve1(a,1,1,m);
        reverse(f,f+n+1);
        
        INV::solve(P[1].data(),P[1].data(),m);
        
        Q[1].resize(m+1);
        NTT::solve(tmp,f,P[1].data(),n,m);
        for(int i=0;i<=m;i++) Q[1][i]=tmp[i];
        
        solve2(s,a,1,1,m);
        for(int i=1;i<=m;i++)
            s[i]=(f[n]+s[i]*a[i]%mod)%mod;
    }
}

int c[N];

int f[N],a[N],s[N];

int F[N],G[N],H[N];

signed main(){
    NTT::pre(4e5);
    init(N-5);
    
    cin>>n>>m;
    
    for(int i=0;i<=n;i++) F[i]=inv[i]*min(i,n-i)%mod;
    for(int i=0;i<=n;i++) G[i]=inv[i]*ID(i)%mod;
    NTT::solve(H,F,G,n,n);
    
    for(int k=0;k<=n;k++){
        int tot=mul[n]*inv[n-k]%mod*H[k]%mod*ksm(m,n-k)%mod;
        c[k]=tot;
    }
    
    for(int k=0;k<=n;k++) f[k]=c[k];
    for(int i=1;i<=n+1;i++) a[i]=i;
    
    Evaluation::solve(s,f,a,n,n+1);
    for(int i=1;i<=n+1;i++) gmod(s[i]+=s[i-1]);
    
    if(m<=n+1) ans=s[m];
    else{
        int alc=1;
        for(int i=0;i<=n+1;i++) alc=alc*(m-i)%mod;
        
        for(int i=0;i<=n+1;i++){
            int tot=alc*ksm(m-i,mod-2)%mod;
            tot=tot*inv[i]%mod*inv[n+1-i]%mod*ID(n+1-i)%mod;
            gmod(ans+=tot*s[i]%mod);
        }
    }
    
    cout<<ans;
}
