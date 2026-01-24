#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=12e5+5,mod=998244353,inv2=(mod+1)/2;

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

namespace NTT{
    // MAX: n+m
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
        for(int i=(n>>1);i;i>>=1)
            for(int *t=g,*j=f;j!=f+n;j+=(i<<1),t++)
                for(int *k=j;k!=j+i;k++){
                    v=1ll*(*t)*k[i]%mod;
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
                    k[i]=1ll*(*t)*(*k+mod-k[i])%mod;
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
            
            NTT::init(lim-1);
            NTT::ntt(A,lim);
            NTT::ntt(B,lim);
            for(int i=0;i<lim;i++)
                S[i]=(2*B[i]%mod+mod-1ll*A[i]*B[i]%mod*B[i]%mod)%mod;
            NTT::intt(S,lim);
            for(int i=len;i<lim;i++) S[i]=0;
        }
        for(int i=0;i<=n;i++) s[i]=S[i];
    }
}


namespace LN{
	int A[N],B[N];
	void solve(int *s,int *f,int n){
		for(int i=0;i<=n;i++) A[i]=f[i],B[i]=0;
		for(int i=1;i<=n;i++) B[i-1]=1ll*f[i]*i%mod;

		INV::solve(A,A,n);
		NTT::solve(A,A,B,n,n);

		for(int i=n-1;i>=0;i--) A[i+1]=1ll*A[i]*ksm(i+1,mod-2)%mod;
		A[0]=0;

		for(int i=0;i<=n;i++) s[i]=A[i];
	}
}

namespace EXP{
	int A[N],B[N],C[N],S[N];
	void solve(int *s,int *f,int n){
		A[0]=B[0]=C[0]=0; S[0]=1;
		for(int len=2;len<=(n<<1);len<<=1){
			int lim=len<<1;
			for(int i=0;i<=min(len-1,n);i++) A[i]=f[i];
            for(int i=0;i<len;i++) B[i]=S[i];
			
			LN::solve(C,B,len-1);
			for(int i=0;i<len;i++) gmodn(C[i]=A[i]-C[i]);
			C[0]=(C[0]+1)%mod;
			NTT::init(lim-1);
			NTT::ntt(B,lim);
			NTT::ntt(C,lim);
			for(int j=0;j<lim;j++) S[j]=1ll*B[j]*C[j]%mod;
			
			NTT::intt(S,lim);
			for(int j=len;j<lim;j++) S[j]=0;
		}
		for(int i=0;i<=n;i++) s[i]=S[i];
	}
}

namespace N_COEF_PROBLEM{
    // MAX: 6n+O(1)
    // Solve S_k = [x^n] f^k
    // Require f_0 = 0
    
    int A[N],B[N],C[N],D[N],P[N];
    void pr(int *f,int n,int d){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=d*2;j++) cout<<f[i*(d*2+1)+j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    void solve(int *s,int *f,int n){
        int sn=n;
        
        int d=1; // deg of y
        for(int i=0;i<=n*3+2;i++) A[i]=B[i]=0;
        A[0]=B[0]=1; // A = 1
        for(int i=0;i<=n;i++) B[i*3+1]=(mod-f[i])%mod; // B = 1-yF
        
        while(n){
            int siz=n*(d*2+1)+d*2;
            for(int i=0;i<=siz;i++) P[i]=0;
            for(int i=0;i<=n;i++){
                for(int j=0;j<=d;j++){
                    int id=i*(d*2+1)+j;
                    P[id]=1ll*B[id]*ID(i)%mod;
                }
            }
            
            NTT::solve(C,A,P,siz,siz);
            NTT::solve(D,B,P,siz,siz);
            
            int nn=n/2,nd=d*2,nsiz=n*(d*2+1)+d*2;
            for(int i=0;i<=nsiz;i++) A[i]=B[i]=0;
            
            for(int i=(n & 1);i<=nn*2+1;i+=2){
                for(int j=0;j<=d*2;j++){
                    int id=i*(d*2+1)+j;
                    int nid=(i/2)*(nd*2+1)+j;
                    A[nid]=C[id];
                }
            }
            for(int i=0;i<=nn*2;i+=2){
                for(int j=0;j<=d*2;j++){
                    int id=i*(d*2+1)+j;
                    int nid=(i/2)*(nd*2+1)+j;
                    B[nid]=D[id];
                }
            }
            
            n=nn,d=nd;
        }
        
        n=sn;
        INV::solve(P,B,n);
        NTT::solve(A,A,P,n,n);
        for(int i=0;i<=n;i++) s[i]=A[i];
    }
}

int n,m;
int F[N],G[N];


signed main(){
    NTT::pre(6e5);
    init(N-5);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x; scanf("%lld",&x); F[x-2]++;
    }
    N_COEF_PROBLEM::solve(G,F,n-2);
    
    for(int k=1;k<=n-2;k++){
        // cout<<k<<": "<<1ll*mul[n+k-2]*inv[n-1]%mod<<" "<<1ll*G[k]*inv[k]%mod<<endl;
        int ans=1ll*mul[n+k-2]*inv[n-1]%mod*G[k]%mod*inv[k]%mod;
        printf("%lld\n",ans);
    }
}

