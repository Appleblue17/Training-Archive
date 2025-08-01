#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5,mod=998244353,inv2=(mod+1)/2;
 
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1ll;
    }
    return tot;
}
 
int mul[N],inv[N];
int invv[N];
 
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
    int A[N],B[N],C[N],rev[N];
    int init(int n){
		int lim=0;
		while((1<<lim)<=n) lim++;
		for(int i=0;i<=(1<<lim)-1;i++)
			rev[i]=(rev[i>>1]>>1) | ((i & 1)<<(lim-1));
		return lim;
	}
	void ntt(int *f,int n,int opt){
		for(int i=0;i<=n-1;i++)
			if(i<rev[i]) swap(f[i],f[rev[i]]);
		for(int l=1;l<n;l<<=1){
			int tmp=ksm(3,(mod-1)/(l*2));
			if(opt==-1) tmp=ksm(tmp,mod-2);
			for(int i=0;i<=n-1;i+=l<<1){
				int omegf=1;
				for(int j=0;j<l;j++){
					int x=f[i+j],y=omegf*f[i+j+l]%mod;
					f[i+j]=(x+y)%mod,f[i+j+l]=(x-y+mod)%mod;
					omegf=omegf*tmp%mod;
				}
			}
		}
		if(opt==-1){
			int t=ksm(n,mod-2);
			for(int i=0;i<n;i++)
				f[i]=f[i]*t%mod;
		}
	}
    void solve(int *s,int* f,int* g,int n,int m){
        if(n+m<=150){
            for(int i=0;i<=n+m;i++) C[i]=0;
            for(int i=0;i<=n;i++)
                for(int j=0;j<=m;j++)
                    gmod(C[i+j]+=f[i]*g[j]%mod);
            for(int i=0;i<=n+m;i++) s[i]=C[i];
            return ;
        }
        int lim=init(n+m);
        for(int i=0;i<(1<<lim);i++) A[i]=B[i]=0;
        for(int i=0;i<=n;i++) A[i]=f[i];
        for(int i=0;i<=m;i++) B[i]=g[i];
        ntt(A,(1<<lim),1);
        ntt(B,(1<<lim),1);
        for(int i=0;i<(1<<lim);i++) C[i]=A[i]*B[i]%mod;
        ntt(C,(1<<lim),-1);
        for(int i=0;i<=n+m;i++) s[i]=C[i];
    }
}
namespace INV{
	int A[N],B[N],S[N];
	void solve(int *s,int *f,int n){
		S[0]=ksm(f[0],mod-2);
		S[1]=0;
		for(int len=2;len/2<=n;len<<=1){
			int lim=len<<1;
			for(int i=0;i<len;i++) A[i]=f[i],B[i]=S[i];
			for(int i=len;i<lim;i++) A[i]=B[i]=0;
			NTT::init(lim-1);
			NTT::ntt(A,lim,1);
			NTT::ntt(B,lim,1);
			for(int j=0;j<lim;j++)
				S[j]=(2*B[j]%mod+mod-A[j]*B[j]%mod*B[j]%mod)%mod;
			NTT::ntt(S,lim,-1);
			for(int j=len;j<lim;j++) S[j]=0;
		}
		for(int i=0;i<=n;i++) s[i]=S[i];
	}
}

int T,n,m,k;
int a[N],c[N];
int A[N],B[N];

int FL[N],GL[N],FR[N],GR[N],F[N],G[N],H[N];
vector <int> P[N*4],Q[N*4];
void solve(int l,int r,int o){
    if(l==r){
        P[o]=vector<int>{A[l]*c[l]%mod};
        Q[o]=vector<int>{1,mod-B[l]};
        return ;
    }
    
    int mid=(l+r)>>1,lim=r-l+1,len=lim/2;
    solve(l,mid,o<<1);
    solve(mid+1,r,o<<1|1);
    
    for(int i=0;i<len;i++) FL[i]=P[o<<1][i],FR[i]=P[o<<1|1][i];
    for(int i=0;i<=len;i++) GL[i]=Q[o<<1][i],GR[i]=Q[o<<1|1][i];
    for(int i=len;i<=lim;i++) FL[i]=FR[i]=0;
    for(int i=len+1;i<=lim;i++) GL[i]=GR[i]=0;
    
    int val=GL[len]*GR[len]%mod;
    
    NTT::init(lim-1);
    NTT::ntt(FL,lim,1);
    NTT::ntt(GL,lim,1);
    NTT::ntt(FR,lim,1);
    NTT::ntt(GR,lim,1);
    
    for(int i=0;i<lim;i++){
        F[i]=(FL[i]*GR[i]%mod+GL[i]*FR[i]%mod)%mod;
        G[i]=GL[i]*GR[i]%mod;
    }
    NTT::ntt(F,lim,-1);
    NTT::ntt(G,lim,-1);
    gmod(G[0]+=mod-val);
    G[lim]=val;
    
    P[o].resize(lim);
    Q[o].resize(lim+1);
    for(int i=0;i<lim;i++) P[o][i]=F[i];
    for(int i=0;i<=lim;i++) Q[o][i]=G[i];
}

int pre1[N],pre2[N];

signed main(){
    init(N-5);
    int ss=0;
    cin>>T;
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&k);
        ss+=n;
        for(int i=0;i<n*2;i++) A[i]=B[i]=c[i]=0;
        
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        reverse(a+1,a+n+1);
        
        int im=ksm(m,mod-2),in=ksm(n-1,mod-2);
        int alc=mul[n-1]%mod*ksm(m,2*(n-1))%mod;
        
        int w=0;
        for(int l=1;l<=n-1;l++) gmod(w+=ksm(im,l-1)*inv[l]%mod);
        c[1]=w*im%mod;
        
        for(int l=1;l<=n;l++){
            gmod(pre1[l]=pre1[l-1]+ksm(im,l-1)*l%mod*inv[l+1]%mod);
            gmod(pre2[l]=pre2[l-1]+ksm(im,l-1)*inv[l+1]%mod);
        }
        
        for(int i=2;i<n;i++){
            c[i]=(pre1[n-i]+pre2[n-i]*(m-1)%mod*im%mod+mod-1)*im%mod;
        }
        c[n]=mod-im;
        
        for(int i=1;i<=n;i++) gmod(c[i]+=1);
        
        for(int i=0;i<n;i++) A[i]=A[n*2-1-i]=a[i+1];
        B[0]=(n+mod-3)%mod; B[1]=B[n*2-1]=1;
        
        NTT::init(n*2-1);
        NTT::ntt(A,n*2,1);
        NTT::ntt(B,n*2,1);
        NTT::ntt(c,n*2,1);
        
        solve(0,n*2-1,1);
        
        for(int i=0;i<n;i++) F[i]=P[1][i],G[i]=Q[1][i];
        INV::solve(G,G,n-1);
        NTT::solve(H,F,G,n-1,n-1);
        
        for(int t=0;t<k;t++) printf("%lld\n",H[t]*ksm(n*2,mod-2)%mod*alc%mod);
    }
    assert(ss<=131072);
}