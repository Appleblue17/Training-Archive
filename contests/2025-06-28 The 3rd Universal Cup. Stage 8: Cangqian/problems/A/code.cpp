#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
#define ep emplace_back
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=1e6+5, mod=998244353;
int T, n, m;
int a[N];
ll frc[N], inv[N];
ll ksm(ll x, ll y){
	ll ret=1;
	while(y){
		if(y&1) ret=ret*x%mod;
		x=x*x%mod; y>>=1;
	}
	return ret;
}
inline ll C(int x, int y){
	if(x<0||y<0||x-y<0) return 0;
	return frc[x]*inv[y]%mod*inv[x-y]%mod;
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
        if(n+m<=150){
            for(int i=0; i<=n+m; ++i) C[i]=0;
            for(int i=0; i<=n; ++i){
                for(int j=0; j<=m; ++j){
                    gmodn(C[i+j]+=1ll*f[i]*g[j]%mod-mod);
                }
            }
            for(int i=0; i<=n+m; ++i) s[i]=C[i];
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
void solve(){
	read(n); read(m);
	for(int i=1; i<=n*m; ++i) read(a[i]);
	sort(a+1, a+n*m+1);
	vector<int> f, g;
	f.resize(n*m+1); g.resize(n*m+1);
	for(int i=0; i<=n*m; ++i) f[i]=inv[i];
	for(int i=1; i<=n*m; ++i) g[i]=frc[i-1]*a[i]%mod;
	reverse(f.begin(), f.end());
	vector<int> h;
	h.resize(n*m*2+2);
	NTT::solve(h.data(), f.data(), g.data(), f.size()-1, g.size()-1);
	// for(int i=0; i<h.size(); ++i){
	// 	cout<<"h: "<<i<<' '<<h[i]<<endl;
	// }
	ll ans=0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			ll cur=0;
			int cnt=i*m+j*n-i*j;
			cur=h[cnt+n*m]*inv[cnt-1]%mod;
			// for(int w=cnt; w<=n*m; ++w){
			// 	cur=(cur+C(w-1, cnt-1)*a[w])%mod;
			// }
			cur=cur*C(n, i)%mod*C(m, j)%mod;
			cur=cur*frc[cnt]%mod*frc[n*m-cnt]%mod;
			if((i+j)&1){
				ans=(ans+cur)%mod;
			}
			else{
				ans=(ans+mod-cur)%mod;
			}
		}
	}
	for(int i=1; i<=n; ++i){
		ll cur=0;
		int cnt=i*m;
		cur=h[cnt+n*m]*inv[cnt-1]%mod;
		// for(int w=cnt; w<=n*m; ++w){
		// 	cur=(cur+C(w-1, cnt-1)*a[w])%mod;
		// }
		cur=cur*C(n, i)%mod;
		cur=cur*frc[cnt]%mod*frc[n*m-cnt]%mod;
		if(i&1){
			ans=(ans+cur)%mod;
		}
		else{
			ans=(ans+mod-cur)%mod;
		}
	}
	for(int j=1; j<=m; ++j){
		ll cur=0;
		int cnt=j*n;
		cur=h[cnt+n*m]*inv[cnt-1]%mod;
		// for(int w=cnt; w<=n*m; ++w){
		// 	cur=(cur+C(w-1, cnt-1)*a[w])%mod;
		// }
		cur=cur*C(m, j)%mod;
		cur=cur*frc[cnt]%mod*frc[n*m-cnt]%mod;
		if(j&1){
			ans=(ans+cur)%mod;
		}
		else{
			ans=(ans+mod-cur)%mod;
		}
	}
	printf("%lld\n", ans);
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	
    NTT::pre(1e6);
	frc[0]=1;
	for(int i=1; i<N; ++i) frc[i]=frc[i-1]*i%mod;
	inv[N-1]=ksm(frc[N-1], mod-2);
	for(int i=N-2; i>=0; --i) inv[i]=inv[i+1]*(i+1)%mod;
	read(T);
	while(T--){
		solve();
	}
	return 0;
}

