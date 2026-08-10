#include <bits/stdc++.h>
using namespace std;
const int N=8e5+5,mod=998244353;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}
void gmod(int &x){
    x%=mod;
}
void gmodn(int &x){
    x+=x>>31 & mod;
}

namespace NTT{
    int in,g[N];
    void pre(int tl){
        int l=__lg(tl)+1;
        int n=(1<<l);
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

int n,m,ans[N];
int buc[N],b[N];
int A[N];

vector <int> P[N*4],Q[N*4];
int F[N];

void solve(int l,int r,int o){
    if(l==r){
        ans[l]=(Q[o][0]+1ll*Q[o][1]*b[l]%mod)%mod;
        P[o]=vector<int>{b[l],1};
        return ;
    }
    int mid=(l+r)>>1;
    int len=r-l+1,lenl=mid-l+1,lenr=r-mid;
    int ls=o<<1,rs=o<<1|1;
    
    P[o].resize(len+1);
    
    Q[ls].resize(lenl+1);
    for(int i=0;i<=lenl;i++) Q[ls][i]=Q[o][i+len-lenl];
    solve(l,mid,ls);
    
    
    NTT::solve(F,Q[o].data(),P[ls].data(),len,lenl);
    Q[rs].resize(lenr+1);
    for(int i=0;i<=lenr;i++) Q[rs][i]=F[i+len-lenr];
    
    solve(mid+1,r,rs);
    NTT::solve(P[o].data(),P[ls].data(),P[rs].data(),lenl,lenr);
}

signed main(){
    NTT::pre(4e5);
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int c; scanf("%d",&c);
        b[i]=buc[c];
        buc[c]++;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int x; scanf("%d",&x);
        A[n-x]++;
    }
    
    Q[1].resize(n+1);
    for(int i=0;i<=n;i++) Q[1][i]=A[i];
    solve(1,n,1);
    
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}