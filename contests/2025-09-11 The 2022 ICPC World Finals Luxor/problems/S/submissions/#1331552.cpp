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
const int N=10005;
int T, n, m;
int a[N];
ll sum[N];
ll f[N][N];
void ckmn(ll &x, ll y){
	if(x>y) x=y;
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	read(n); read(m);
    for(int i=1; i<=n; ++i) read(a[i]);
    sort(a+1, a+n+1);
	for(int i=1; i<=n; ++i) sum[i]=sum[i-1]+a[i];
	if(m>=n){
		printf("%d\n", a[n]);
		return 0;
	}
    int lim=n/(m-1)+2;
	memset(f, 0x3f, sizeof f);
	for(int i=1; i<=m+1; ++i) f[i][0]=a[i-1];
	for(int i=1; i<=n; ++i){
		for(int j=0; j<=lim; ++j){
			for(int k=2; k<=m&&k<i; ++k) if(j-1+k<=lim){
				ckmn(f[i][j-1+k], f[i][j]+sum[k]+a[k]);
			}
			for(int k=0; k<m&&k<i; ++k) if(j+k-1<=lim&&j+k-1>=0){
				ckmn(f[min(i+m-k, n+1)][j+k-1], f[i][j]+a[min(i+m-k-1, n)]+sum[k]);
			}
		}
	}
	printf("%lld\n", f[n+1][0]);
	return 0;
}
