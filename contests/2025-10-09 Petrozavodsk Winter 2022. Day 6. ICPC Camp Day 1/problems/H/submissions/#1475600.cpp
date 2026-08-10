#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=3e5+5,mod=998244353;

void gmodn(int &x){
    x+=x>>31 & mod;
}
void gmod(int &x){
    x%=mod;
}

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
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int ID(int x){
    return (x & 1)?mod-1:1;
}
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return 1ll*mul[m]*inv[n]%mod*inv[m-n]%mod;
}

namespace NTT{
    int in,g[N];
    void pre(int tl){
        int l=__lg(tl)+1;
        int n=1<<l;
        g[0]=1;
        g[n]=ksm(31,1<<(21-l));
        for(int i=l;i;i--) g[1<<(i-1)]=1ll*g[1<<i]*g[1<<i]%mod;
        for(int i=0;i<n;i++) g[i]=1ll*g[i & (i-1)]*g[i & (-i)]%mod;
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
                    v=1ll*(*t)*k[i]%mod;
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
                    k[i]=1ll*(*t)*(*k-k[i]+mod)%mod;
                    *k=v;
                }
            }
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
            for(int i=0;i<len;i++) A[i]=f[i],B[i]=S[i];
            for(int i=len;i<lim;i++) A[i]=B[i]=0;
            
            int t=NTT::init(len);
            NTT::ntt(A,lim);
            NTT::ntt(B,lim);
            for(int j=0;j<lim;j++)
                S[j]=(2ll*B[j]%mod+mod-1ll*A[j]*B[j]%mod*B[j]%mod)%mod;
            NTT::intt(S,lim);
            for(int j=len;j<lim;j++) S[j]=0;
        }
        for(int i=0;i<=n;i++) s[i]=S[i];
    }
}

int n,m;

vector <int> P[N*4];
void solve(int o,int l,int r){
    if(l==r){
        P[o]={1,l};
        return ;
    }
    int mid=(l+r)>>1;
    solve(o<<1,l,mid);
    solve(o<<1|1,mid+1,r);
    
    int lenl=P[o<<1].size()-1,lenr=P[o<<1|1].size()-1;
    P[o].resize(lenl+lenr+1);
    NTT::solve(P[o].data(),P[o<<1].data(),P[o<<1|1].data(),lenl,lenr);
}

int F[N],G[N];

signed main(){
    init(N-5);
    NTT::pre(2e5);
    cin>>n>>m;
    
    solve(1,1,m);
    // for(int x: P[1]) cout<<x<<" "; cout<<endl;
    
    for(int i=0;i<=m;i++) F[i]=P[1][i];
    INV::solve(G,F,n);
    // for(int i=0;i<=n;i++) cout<<1ll*G[i]*ID(i)%mod<<" ";
    int ans=1ll*G[n]*ID(n)%mod;
    int sum=C(m+n-1,n);
    // cout<<ans<<" "<<sum<<endl;
    cout<<1ll*ans*ksm(sum,mod-2)%mod;
}
