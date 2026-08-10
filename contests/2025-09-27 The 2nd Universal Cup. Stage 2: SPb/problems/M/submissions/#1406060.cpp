#include <bits/stdc++.h>
using namespace std;
const int N=8e5+5,mod=998244353;

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


namespace DIV{
    int A[N],B[N],C[N],D[N];
    void solve(int *q,int *r,int *f,int *g,int n,int m){
        for(int i=0;i<=n;i++) A[i]=C[i]=f[i];
        for(int i=0;i<=m;i++) B[i]=D[i]=g[i];
        
        reverse(A,A+n+1);
        reverse(B,B+m+1);
        
        INV::solve(B,B,n-m);
        NTT::solve(q,A,B,n,n-m);
        
        for(int i=n-m+1;i<=n+n-m;i++) q[i]=0;
        reverse(q,q+n-m+1);
        
        NTT::solve(D,D,q,m,n-m);
        for(int i=0;i<=n;i++) r[i]=(C[i]+mod-D[i])%mod;
    }
    
}

namespace Recursion{
    int A[N],T[N],P[N],tmp[N];
    int solve(int *F,int *a,int x,int n){
        int ans=0;
        memset(A,0,sizeof(A));
        memset(T,0,sizeof(T));
        A[1]=1; T[0]=1;
        
        memset(P,0,sizeof(P));
        for(int i=0;i<n;i++) P[i]=(mod-F[n-i])%mod;
        
        P[n]=1;
        while(x){
            if(x & 1){
                NTT::solve(T,T,A,n,n);
                DIV::solve(tmp,T,T,P,2*n,n);
            }
            NTT::solve(A,A,A,n,n);
            DIV::solve(tmp,A,A,P,2*n,n);
            x>>=1;
        }
        for(int i=0;i<n;i++) gmod(ans+=1ll*a[i]*T[i]%mod);
        return ans;
    }
}


int n,m;
char S[N];

int nxt[N];
void getnxt(char *s,int n){
    nxt[0]=-1;
    int i=0,j=-1;
    while(i<n){
        if(j==-1 || s[i]==s[j]){
            i++,j++;
            nxt[i]=j;
        }
        else j=nxt[j];
    }
}

int a[N],F[N],B[N];
int G[N],P[N];

int main(){
    NTT::pre(4e5);
    scanf("%d%d",&n,&m); m-=n;
    scanf("\n%s",S);
    
    getnxt(S,n);
    
    int x=nxt[n];
    while(x){
        // cout<<x<<endl;
        B[n-x]++;
        x=nxt[x];
    }
    B[0]++;
    // for(int i=0;i<=n;i++) cout<<B[i]<<" "; cout<<endl;
    
    F[n]++;
    for(int i=0;i<=n;i++){
        gmod(F[i]+=B[i]);
        gmod(F[i+1]+=mod-26ll*B[i]%mod);
    }
    // for(int i=0;i<=n;i++) cout<<F[i]<<" "; cout<<endl;
    
    INV::solve(P,F,n);
    
    for(int i=1;i<=n;i++) G[i]=(mod-F[i])%mod;
    // for(int i=0;i<=n;i++) cout<<G[i]<<" "; cout<<endl;
    
    int ans=Recursion::solve(G,P,m,n);
    cout<<ans;
}


