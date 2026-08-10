#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5,mod=998244353;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}
void gmod(int &x){
    x%=mod;
} 
void gmodn(int &x){
    x+=(x>>31 & mod);
}

int mul[N],inv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
}


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
        for(int i=(n>>1);i;i>>=1){
            for(int *t=g,*j=f;j!=f+n;j+=(i<<1),t++){
                for(int *k=j;k!=j+i;k++){
                    v=(*t)*k[i]%mod;
                    gmodn(k[i]=(*k)-v);
                    gmodn((*k)+=v-mod);
                }
            }
        }
    }
    
    void intt(int *f,int n){
        int v;
        for(int i=1;i<n;i<<=1){
            for(int *t=g,*j=f;j!=f+n;j+=(i<<1),t++){
                for(int *k=j;k!=j+i;k++){
                    gmodn(v=(*k)+k[i]-mod);
                    k[i]=(*t)*(*k-k[i]+mod)%mod;
                    *k=v;
                }
            }
        }
        reverse(f+1,f+n);
        for(int i=0;i<n;i++) f[i]=f[i]*in%mod;
    }
    
    int A[N],B[N],C[N];
    void solve(int *s,int *f,int *g,int n,int m){
        int lim=init(n+m);
        for(int i=0;i<(1<<lim);i++) A[i]=B[i]=0;
        for(int i=0;i<=n;i++) A[i]=f[i];
        for(int i=0;i<=m;i++) B[i]=g[i];
        ntt(A,1<<lim);
        ntt(B,1<<lim);
        
        for(int i=0;i<(1<<lim);i++) C[i]=A[i]*B[i]%mod;
        intt(C,1<<lim);
        for(int i=0;i<=n+m;i++) s[i]=C[i];
    }
}

int n,k,m;

int F[N],S[N];

void ksm(int *s,int *f,int x,int n){
    memset(s,0,sizeof(s));
    s[0]=1;
    
    while(x){
        if(x & 1){
            NTT::solve(s,s,f,n,n);
        }
        NTT::solve(f,f,f,n,n);
        x>>=1;
    }
}


signed main(){
    NTT::pre(2e5);
    init(N-5);
    cin>>n>>k>>m;
    
    for(int i=0;i<=n;i++) F[i]=ksm(k,i)*mul[i]%mod;
    
    ksm(S,F,k,m);
    // for(int i=0;i<=m;i++) cout<<S[i]<<" "; cout<<endl;
    
    int ans=0;
    for(int i=0;i<=m;i++) gmod(ans+=S[i]*inv[i]%mod);
    cout<<ans;
}
