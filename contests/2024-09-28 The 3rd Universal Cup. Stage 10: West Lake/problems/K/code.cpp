#pragma GCC optimize(2)
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
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=1005;
int Test, n, nn;
int px[N], py[N];
int col[N], id[N];
ll f[N][N], g[N][N];
ll crs[N][N];
inline ll cross(int i, int j){
	return (ll)px[i]*py[j]-(ll)px[j]*py[i];
}
inline void chkmx(ll &x, ll y){
	if(x<y) x=y;
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(Test);
	while(Test--){
		read(n);
		for(int i=1; i<=n; ++i) read(col[i]), id[i]=col[i];
		sort(col+1, col+n+1);
		nn=unique(col+1, col+n+1)-col-1;
		for(int i=1; i<=n; ++i) id[i]=lower_bound(col+1, col+nn+1, id[i])-col;
		for(int i=1; i<=n; ++i){
			read(px[i]); read(py[i]);
			px[i+n]=px[i]; py[i+n]=py[i];
			id[i+n]=id[i];
		}
		for(int i=1; i<=n*2; ++i) for(int j=1; j<=n*2; ++j) crs[i][j]=cross(i, j);
		for(int i=0; i<=n*2+1; ++i) for(int j=0; j<=n*2+1; ++j) f[i][j]=g[i][j]=-1e18;
        ll ans=0;
		for(int i=2*n; i; --i){
            for(int j=i+1; j<=2*n&&j<=i+n; ++j){
                for(int h=i+1; h<j; ++h) g[i][j]=max(g[i][j], f[h][j]+crs[i][h]);
                if(id[i]==id[j]){
                    f[i][j]=crs[i][j];
                    for(int h=i+1; h<j; ++h) f[i][j]=max(f[i][j], g[i][h]+crs[h][j]);
                    chkmx(ans, f[i][j]-crs[i][j]);
                }
            }
        }
		printf("%lld\n", ans);
	}
	return 0;
}
