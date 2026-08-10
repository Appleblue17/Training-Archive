#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+5,mod=998244353;
int T,n;
char S[N];
int a[N];

void gmodn(int &x){
    x+=x>>31 & mod;
}
void gmod(int &x){
    x%=mod;
}
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1ll;
    }
    return tot;
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


int mul[N],inv[N];
int pw[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
    
    pw[0]=1;
    for(int i=1;i<=lim;i++) pw[i]=pw[i-1]*10%mod;
}
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return mul[m]*inv[n]%mod*inv[m-n]%mod;
}
int ID(int x){
    return (x & 1)?mod-1:1;
}

int p[N];
vector <int> F[N],G[N],F0[N],G0[N];

int FF[N],FG[N],F0F[N],GF[N],GG[N],G0F[N],FF0[N],FG0[N],F0F0[N],GF0[N],GG0[N],G0F0[N];

void vecinit(int o,int len){
    F[o].clear(); F[o].resize(len+1);
    G[o].clear(); G[o].resize(len+1);
    F0[o].clear(); F0[o].resize(len+1);
    G0[o].clear(); G0[o].resize(len+1);
}

void solve(int l,int r,int o){
    int mid=(l+r)>>1,L=o<<1,R=o<<1|1;
    int lenL=mid-l+1,lenR=r-mid,len=r-l+1;
    vecinit(o,len);
    
    if(l==r){
        int x=a[l];
        p[o]=x;
        return ;
    }
    
    solve(l,mid,L);
    solve(mid+1,r,R);
    
    gmod(p[o]=p[L]*pw[lenR]%mod+p[R]);
    
    if(len>=2){
        NTT::solve(FF,F[L].data(),F[R].data(),lenL-1,lenR-1);
        NTT::solve(FG,F[L].data(),G[R].data(),lenL-1,lenR-1);
        NTT::solve(F0F,F0[L].data(),F[R].data(),lenL-1,lenR-1);
        for(int i=0;i<len;i++){
            F[o][i]=(FG[i]+F0F[i])%mod;
            if(i) gmod(F[o][i]+=FF[i-1]);
            
            // if(i) gmod(F[o][i]+=p[L]*F[R][i-1]%mod+F[L][i-1]*p[R]%mod);
            // gmod(F[o][i]+=p[L]*G[R][i]%mod+F[R][i]);
            // gmod(F[o][i]+=F[L][i]*pw[lenR]%mod+F0[L][i]*p[R]%mod);
        }
        for(int i=0;i<=lenL;i++){
            if(i) gmod(F[o][i]+=F[L][i-1]*p[R]%mod);
            gmod(F[o][i]+=F[L][i]*pw[lenR]%mod+F0[L][i]*p[R]%mod);
        }
        for(int i=0;i<=lenR;i++){
            if(i) gmod(F[o][i]+=p[L]*F[R][i-1]%mod);
            gmod(F[o][i]+=p[L]*G[R][i]%mod+F[R][i]);
        }
        
        NTT::solve(GF,G[L].data(),F[R].data(),lenL-1,lenR-1);
        NTT::solve(GG,G[L].data(),G[R].data(),lenL-1,lenR-1);
        NTT::solve(G0F,G0[L].data(),F[R].data(),lenL-1,lenR-1);
        for(int i=0;i<len;i++){
            G[o][i]=(GG[i]+G0F[i])%mod;
            if(i) gmod(G[o][i]+=GF[i-1]);
            
            // if(i) gmod(G[o][i]+=pw[lenL]*F[R][i-1]%mod+G[L][i-1]*p[R]%mod);
            // gmod(G[o][i]+=pw[lenL]*G[R][i]%mod);
            // gmod(G[o][i]+=G[L][i]*pw[lenR]%mod+G0[L][i]*p[R]%mod);
        }
        
        for(int i=0;i<=lenL;i++){
            if(i) gmod(G[o][i]+=G[L][i-1]*p[R]%mod);
            gmod(G[o][i]+=G[L][i]*pw[lenR]%mod+G0[L][i]*p[R]%mod);
        }
        for(int i=0;i<=lenR;i++){
            if(i) gmod(G[o][i]+=pw[lenL]*F[R][i-1]%mod);
            gmod(G[o][i]+=pw[lenL]*G[R][i]%mod);
        }
        
        NTT::solve(FF0,F[L].data(),F0[R].data(),lenL-1,lenR-1);
        NTT::solve(FG0,F[L].data(),G0[R].data(),lenL-1,lenR-1);
        NTT::solve(F0F0,F0[L].data(),F0[R].data(),lenL-1,lenR-1);
        for(int i=0;i<len;i++){
            F0[o][i]=(FG0[i]+F0F0[i])%mod;
            if(i) gmod(F0[o][i]+=FF0[i-1]);
            
            // if(i) gmod(F0[o][i]+=p[L]*F0[R][i-1]%mod+F0[L][i-1]);
            // gmod(F0[o][i]+=p[L]*G0[R][i]%mod+F0[R][i]);
            // gmod(F0[o][i]+=F0[L][i]);
        }
        for(int i=0;i<=lenL;i++){
            if(i) gmod(F0[o][i]+=F0[L][i-1]);
            gmod(F0[o][i]+=F0[L][i]);
        }
        for(int i=0;i<=lenR;i++){
            if(i) gmod(F0[o][i]+=p[L]*F0[R][i-1]%mod);
            gmod(F0[o][i]+=p[L]*G0[R][i]%mod+F0[R][i]);
        }
        
        NTT::solve(GF0,G[L].data(),F0[R].data(),lenL-1,lenR-1);
        NTT::solve(GG0,G[L].data(),G0[R].data(),lenL-1,lenR-1);
        NTT::solve(G0F0,G0[L].data(),F0[R].data(),lenL-1,lenR-1);
        for(int i=0;i<len;i++){
            G0[o][i]=(GG0[i]+G0F0[i])%mod;
            if(i) gmod(G0[o][i]+=GF0[i-1]);
            
            // if(i) gmod(G0[o][i]+=pw[lenL]*F0[R][i-1]%mod+G0[L][i-1]);
            // gmod(G0[o][i]+=pw[lenL]*G0[R][i]%mod);
            // gmod(G0[o][i]+=G0[L][i]);
        }
        for(int i=0;i<=lenL;i++){
            if(i) gmod(G0[o][i]+=G0[L][i-1]);
            gmod(G0[o][i]+=G0[L][i]);
        }
        for(int i=0;i<=lenR;i++){
            if(i) gmod(G0[o][i]+=pw[lenL]*F0[R][i-1]%mod);
            gmod(G0[o][i]+=pw[lenL]*G0[R][i]%mod);
        }
        
        gmod(F[o][1]+=p[L]*p[R]%mod);
        gmod(G[o][1]+=pw[lenL]*p[R]%mod);
        gmod(F0[o][1]+=p[L]);
        gmod(G0[o][1]+=pw[lenL]);
    }
    
    // cout<<" "<<l<<" "<<r<<" "<<o<<": "<<endl;
    // cout<<"  p = "<<p[o]<<endl;
    // cout<<"  F: "; for(int i=0;i<len;i++) cout<<F[o][i]<<" "; cout<<endl;
    // cout<<"  G: "; for(int i=0;i<len;i++) cout<<G[o][i]<<" "; cout<<endl;
    // cout<<"  F0: "; for(int i=0;i<len;i++) cout<<F0[o][i]<<" "; cout<<endl;
    // cout<<"  G0: "; for(int i=0;i<len;i++) cout<<G0[o][i]<<" "; cout<<endl;
    
    // cout<<"  total: "; cout<<p[o]<<" | "; for(int i=1;i<len;i++) cout<<F[o][i]<<" "; cout<<endl;
}

signed main(){
    init(N-5);
    NTT::pre(2e5);
    
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        scanf("\n%s",S+1);
        for(int i=1;i<=n;i++) a[i]=S[i]-'0';
        
        solve(1,n,1);
        
        printf("%lld ",p[1]);
        for(int i=1;i<n;i++) printf("%lld ",F[1][i]);
        printf("\n");
        
        
    }
}