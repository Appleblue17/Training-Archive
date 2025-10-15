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
#define ep emplace_back
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=2e5+5;
const int B=30;
int T, n, m;
bitset<N> f[N/B+2], h, g[1005];
int a[N];
void solve(){
	read(n); read(m);
	for(int i=1; i<=n; ++i){
		read(a[i]);
		for(int j=max(1, a[i]-m); j<=1000&&j<=a[i]+m; ++j){
			g[j][i]=1;
		}
	}
	f[0][1]=1; 
	int idx=0;
	for(int i=B+1; i<=n; i+=B){
		h=f[idx];
		++idx;
		for(int j=B-1; j>=0; --j){
			h=(h>>1)&(g[a[i-j]]);
			h[i-j]=1; 
		}
		f[idx]=h;
	}
	for(int i=1; i<=n; ++i){
		int L=(i-1)/B+1, R=idx, mid, ret=L-1;
		while(L<=R){
			mid=(L+R)>>1;
			if(2*i-mid*B-1>=1&&f[mid][2*i-mid*B-1]){
				ret=mid; L=mid+1;
			}
			else{
				R=mid-1;
			}
		}
		ret=max(i, ret*B+1);
		while(ret<n){
			++ret;
			if(2*i-ret<=0||abs(a[ret]-a[2*i-ret])>m){
				--ret; break;
			}
		}
		printf("%d ", (ret-i)*2+1);
	}
	putchar('\n');
	
	
	f[0].reset();
	f[0][2]=1; 
	idx=0;
	for(int i=B+1; i<=n; i+=B){
		h=f[idx];
		++idx;
		for(int j=B-1; j>=0; --j){
			h=(h>>1)&(g[a[i-j]]);
			h[i-j+1]=1; 
		}
		f[idx]=h;
	}
	for(int i=2; i<=n; ++i){
		int L=(i-2)/B+1, R=idx, mid, ret=L-1;
		while(L<=R){
			mid=(L+R)>>1;
			if(2*i-1-mid*B-1>=1&&f[mid][2*i-1-mid*B-1]){
				ret=mid; L=mid+1;
			}
			else{
				R=mid-1;
			}
		}
		ret=max(i-1, ret*B+1);
		while(ret<n){
			++ret;
			if(2*i-1-ret<=0||abs(a[ret]-a[2*i-1-ret])>m){
				--ret; break;
			}
		}
		printf("%d ", (ret-i+1)*2);
	}
	putchar('\n');
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	solve();
	return 0;
}

