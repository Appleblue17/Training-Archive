#include <bits/stdc++.h>
using namespace std;
const int N=1.1e6+5,mod=998244353;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1;
    }
    return tot;
}
void gmodn(int &x){
    x+=x>>31 & mod;
}
void gmod(int &x){
    x%=mod;
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
        ntt(A,1<<lim);
        ntt(B,1<<lim);
        
        for(int i=0;i<(1<<lim);i++) C[i]=1ll*A[i]*B[i]%mod;
        intt(C,1<<lim);
        for(int i=0;i<=n+m;i++) s[i]=C[i];
    }
}

int T,n,m;
int ans[N];

vector <int> V[N];
vector <int> P[N*2],Q[N*2];
int F[N],G[N],H[N],S[N];

void solve(int l,int r,int o,int sum){
    int tot;
    if(l==r){
        P[o]=V[l];
        // vector <int> A=Q[o];
        
        Q[o].resize(2*m+1);
        
        for(int i=0;i<=m;i++) F[i]=Q[o][i];
        for(int i=0;i<=2*m;i++) G[i]=P[o][i];
        NTT::solve(H,F,G,m,m*2);
        for(int i=0;i<=m*2;i++) Q[o][i]=H[i+m];
        
        
        // cout<<l<<" "<<r<<" "<<o<<": "<<endl;
        // cout<<"  P: "; for(int x: P[o]) cout<<x<<" "; cout<<endl;
        // cout<<"  A: "; for(int x: A) cout<<x<<" "; cout<<endl;
        // cout<<"  Q: "; for(int x: Q[o]) cout<<x<<" "; cout<<endl;
        
        tot=0;
        for(int i=0;i<=m*2;i++) gmod(tot+=Q[o][i]);
        // cout<<"! "<<sum<<" "<<tot<<endl;
        ans[l]=(tot+sum)%mod;
        return ;
    }
    
    int mid=(l+r)>>1,ls=o<<1,rs=o<<1|1;
    int len=(r-l+1)*m,lenl=(mid-l+1)*m,lenr=(r-mid)*m;
    
    P[o].resize(2*len+1);
    Q[o].resize(2*len+1);
    for(int i=len+1;i<=len*2;i++) assert(Q[o][i]==0);
    
    
    Q[ls].resize(lenl+1);
    for(int i=0;i<=lenl;i++) Q[ls][i]=Q[o][i];
    tot=0;
    for(int i=lenl+1;i<=len*2;i++) gmod(tot+=Q[o][i]);
    solve(l,mid,ls,(sum+tot)%mod);
    
    // vector <int> A=Q[o];
    
    for(int i=0;i<=len*2;i++) S[i]=0;
    
    for(int i=0;i<=lenl*2;i++) gmod(S[i]+=Q[ls][i]);
    
    for(int i=0;i<=lenl;i++) F[i]=0;
    for(int i=lenl+1;i<=len;i++) F[i]=Q[o][i];
    for(int i=0;i<=lenl*2;i++) G[i]=P[ls][i];
    NTT::solve(H,F,G,len,lenl*2);
    for(int i=lenl;i<=len+lenl*2;i++) gmod(S[i-lenl]+=H[i]);
    
    for(int i=0;i<=len*2;i++) Q[o][i]=S[i];
    
    // vector <int> B=Q[o];
    
    Q[rs].resize(lenr+1);
    for(int i=0;i<=lenr;i++) Q[rs][i]=Q[o][i];
    tot=0;
    for(int i=lenr+1;i<=len*2;i++) gmod(tot+=Q[o][i]);
    solve(mid+1,r,rs,(sum+tot)%mod);
    
    
   for(int i=0;i<=len*2;i++) S[i]=0;
    
    for(int i=0;i<=lenr*2;i++) gmod(S[i]+=Q[rs][i]);
    
    for(int i=0;i<=lenr;i++) F[i]=0;
    for(int i=lenr+1;i<=len*2;i++) F[i]=Q[o][i];
    for(int i=0;i<=lenr*2;i++) G[i]=P[rs][i];
    NTT::solve(H,F,G,len*2,lenr*2);
    
    for(int i=lenr;i<=len*2+lenr*2;i++) gmod(S[i-lenr]+=H[i]);
    
    for(int i=0;i<=len*2;i++) Q[o][i]=S[i];
    
    
    NTT::solve(P[o].data(),P[ls].data(),P[rs].data(),lenl*2,lenr*2);
    
    // cout<<l<<" "<<r<<" "<<o<<": "<<endl;
    // cout<<"  P: "; for(int x: P[o]) cout<<x<<" "; cout<<endl;
    // cout<<"  Q: "<<endl; 
    // cout<<"   "; for(int x: A) cout<<x<<" "; cout<<endl;
    // cout<<"   "; for(int x: B) cout<<x<<" "; cout<<endl;
    // cout<<"   "; for(int x: Q[o]) cout<<x<<" "; cout<<endl;
}

signed main(){
    NTT::pre(8e5);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int t=1;t<=n;t++){
            V[t].resize(2*m+1);
            for(int i=0;i<=m*2;i++) scanf("%d",&V[t][i]);
        }
        Q[1].clear();
        Q[1].resize(n*m);
        Q[1][0]=1;
        
        solve(1,n,1,0);
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
        printf("\n");
    }
}