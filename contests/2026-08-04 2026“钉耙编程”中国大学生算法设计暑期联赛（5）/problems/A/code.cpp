#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+5,mod=998244353;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1ll;
    }
    return tot;
}

int mul[N],inv[N],invv[N];
void init(int lim){
	mul[0]=inv[0]=1;
	for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
	inv[lim]=ksm(mul[lim],mod-2);
	for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
    
	invv[1]=1;
	for(int i=2;i<=lim;i++) invv[i]=(mod-mod/i)*invv[mod%i]%mod;
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

namespace INV{
	int A[N],B[N],S[N];
	void solve(int *s,int *f,int n){
		S[0]=ksm(f[0],mod-2);
		S[1]=0;
		for(int len=2;len<=(n<<1);len<<=1){
			int lim=len<<1;
			for(int i=0;i<lim;i++) A[i]=B[i]=0;
			for(int i=0;i<=min(len-1,n);i++) A[i]=f[i];
			for(int i=0;i<len;i++) B[i]=S[i];
            
			int t=NTT::init(len);
			NTT::ntt(A,lim);
			NTT::ntt(B,lim);
			for(int j=0;j<lim;j++)
				S[j]=(2*B[j]%mod+mod-1ll*A[j]*B[j]%mod*B[j]%mod)%mod;
			NTT::intt(S,lim);
			for(int j=len;j<lim;j++) S[j]=0;
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
		for(int len=2;len/2<=n;len<<=1){
			int lim=len<<1;
			for(int i=0;i<lim;i++) A[i]=B[i]=C[i]=0;
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

int T,n,m,a,b,c;
int F[N],G[N];
int s[N];

int A[N],B[N],C[N];

int p[N],q[N];

signed main(){
    // freopen("1.txt","w",stdout);
    init(N-5);
    NTT::pre(4e5);
    
    cin>>T;
    while(T--){
        cin>>n>>m>>a>>b>>c;
        int valA=b*ksm(2*a%mod,mod-2)%mod,valB=(c+mod-b*b%mod*ksm(4*a%mod,mod-2)%mod)%mod;
        
        for(int i=1;i<=n*2+1;i++) B[i-1]=(mod-inv[i])%mod;
        for(int i=1;i<=n*2+1;i++) A[i-1]=(mod-inv[i]*ksm(m+1,i)%mod)%mod;
        
        INV::solve(B,B,n*2);
        NTT::solve(C,A,B,n*2,n*2);
        
        for(int i=0;i<=n*2;i++) q[i]=C[i]*mul[i]%mod;
        
        // for(int i=0;i<=n*2;i++) cout<<q[i]<<" "; cout<<endl;
        
        for(int i=0;i<=n*2;i++) A[i]=q[i]*inv[i]%mod,B[i]=ksm(valA,i)*inv[i]%mod;
        NTT::solve(C,A,B,n*2,n*2);
        for(int i=0;i<=n*2;i++) p[i]=C[i]*mul[i]%mod;
        
        // cout<<"p: "; for(int i=0;i<=n*2;i++) cout<<p[i]<<" "; cout<<endl;
        // for(int k=0;k<=n*2;k++){
        //     int tot=0;
        //     for(int t=0;t<=m;t++) gmod(tot+=ksm(t+valA,k)%mod);
        //     cout<<tot<<" ";
        // }
        // cout<<endl;
        
        for(int i=0;i<=n;i++) A[i]=p[2*i]*ksm(a,i)%mod*inv[i]%mod,B[i]=ksm(valB,i)*inv[i]%mod;
        NTT::solve(C,A,B,n,n);
        for(int i=0;i<=n;i++) s[i]=C[i]*mul[i]%mod;
        // cout<<"s: "; for(int i=0;i<=n;i++) cout<<s[i]<<" "; cout<<endl;
        
        // for(int i=1;i<=n;i++){
        //     int tot=0;
        //     for(int t=0;t<=m;t++) gmod(tot+=ksm(a*t*t%mod+b*t%mod+c,i));
        //     s[i]=tot;
        // }
        // cout<<"s: "; for(int i=0;i<=n;i++) cout<<s[i]<<" "; cout<<endl;
        for(int i=0;i<=n;i++) F[i]=s[i]*invv[i]%mod;
        // for(int i=0;i<=n;i++) cout<<F[i]<<" "; cout<<endl;
        
        EXP::solve(G,F,n);
        for(int i=0;i<=n;i++) printf("%lld ",G[i]); printf("\n");
    }
    
}