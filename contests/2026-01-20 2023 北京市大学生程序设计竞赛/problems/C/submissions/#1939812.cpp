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
const int N=155;
int n, K, m;
int c[N];
int w[N];
int p[N];
ll f[N][N], g[N][N][10], h[N][N];
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n); read(K); read(m);
	for(int i=1; i<=n; ++i) read(c[i]);
	for(int i=1; i<=n; ++i) read(w[i]);
	for(int i=K; i<=K*2-2; ++i) read(p[i]);
	memset(f, -0x3f, sizeof f); memset(g, -0x3f, sizeof g); memset(h, -0x3f, sizeof h);
	for(int i=0; i<=n; ++i) f[i+1][i]=0;
	for(int len=1; len<=n; ++len){
		for(int l=1, r=len; r<=n; ++l, ++r){
			for(int o=w[l]; o<K; ++o) g[l][r][o]=max(g[l][r][o], f[l+1][r]-m*(o-w[l]));
			for(int k=l+1; k+1<=r; ++k) if(c[l]==c[k+1]){
				for(int o=w[l]; o<K; ++o){
					g[l][r][o]=max(g[l][r][o], f[l+1][k]+g[k+1][r][o-w[l]]);
				}
			}
			if(c[l]!=c[r+1]){
				for(int o=0; o<K; ++o) h[l][r]=max(h[l][r], g[l][r][o]+p[K]-m*(K-o));
				for(int k=l+1; k+1<=r; ++k) if(c[l]==c[k+1]){
					for(int w1=0; w1<K; ++w1){
						for(int w2=0; w2<K; ++w2) if(w1+w2>=K){
							h[l][r]=max(h[l][r], g[l][k][w1]+g[k+1][r][w2]+p[w1+w2]);
						}
					}
				}
			}
			for(int k=l; k<=r; ++k) if(c[l-1]!=c[k]){
				f[l][r]=max(f[l][r], f[l][k-1]+h[k][r]);
			}
		}
	}
	printf("%lld\n", f[1][n]);
	return 0;
}

