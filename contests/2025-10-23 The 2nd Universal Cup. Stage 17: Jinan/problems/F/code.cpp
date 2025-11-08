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
inline void plu(int &x, int y){
	x+=y; 
	if(x>=mod) x-=mod;
}
inline void sub(int &x, int y){
	x-=y;
	if(x<0) x+=mod;
}
int n;
int a[N];
int dp[N], preans[N], sufans[N], ans[N];
struct fenwick{
	const int eps=4e5+5;
	int tr[N];
	void add(int x, int v){
		for(x+=eps, v=(v+mod)%mod; x<N; x+=(x&-x)) tr[x]=(tr[x]+v)%mod;
	}
	int get(int x){
		int ret=0;
		for(x+=eps; x>0; x-=(x&-x)) ret=(ret+tr[x])%mod;
		return ret;
	}
}T;
int p[N], q[N], rk[N];
void calc(int l, int r){
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	calc(l, mid);
	for(int i=l; i<=r; ++i) rk[i]=i, p[i]=0, q[i]=0;
	for(int i=mid+1; i<=r; ++i) p[i]=max(p[i-1], a[i]);
	for(int i=mid-1; i>=l; --i) q[i]=max(q[i+1], a[i+1]);
	for(int i=l; i<=r; ++i) {
		p[i]-=i; q[i]+=i;
	}
	sort(rk+l, rk+mid+1, [&](int x, int y){return q[x]<q[y];});
	int it=l;
	for(int i=mid+1; i<=r; ++i){
		while(it<=mid&&q[rk[it]]<=q[i]) {
			T.add(-p[rk[it]], dp[rk[it]]);
			++it;
		}
		dp[i]=(dp[i]+T.get(-p[i]))%mod;
	}
	for(int i=l; i<it; ++i) T.add(-p[rk[i]], -dp[rk[i]]);
	calc(mid+1, r);
}
void calc2(int l, int r){
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	calc2(l, mid);
	calc2(mid+1, r);
	
	//x \in [l+1, mid]
	for(int i=l; i<=r; ++i) rk[i]=i, p[i]=0, q[i]=0;
	for(int i=mid+1; i<=r; ++i) p[i]=max(p[i-1], a[i]);
	for(int i=l; i<=r; ++i) p[i]-=i;
	sort(rk+mid+1, rk+r+1, [&](int x, int y){return p[x]<p[y];});
	int mx=0, mx2=0;
	int it=mid+1;
	for(int i=mid-1; i>=l; --i){
		while(it<=r&&p[rk[it]]<=p[i]){
			T.add(-rk[it], sufans[rk[it]+1]);
			++it;
		}
		if(a[i+1]>a[mx]){
			mx2=mx; mx=i+1;
		}
		else if(a[i+1]>a[mx2]){
			mx2=i+1;
		}
		if(a[mx]!=a[mx2]){
			sub(ans[mx], 1ll*T.get(-(a[mx]+i))*preans[i]%mod);
			plu(ans[mx], 1ll*T.get(-(a[mx2]+i))*preans[i]%mod);
		}
	}
	for(int i=mid+1; i<it; ++i) T.add(-rk[i], -sufans[rk[i]+1]);
	
	
	
	//x \in [mid+1, r]
	for(int i=l; i<=r; ++i) rk[i]=i, p[i]=0, q[i]=0;
	for(int i=mid-1; i>=l; --i) q[i]=max(q[i+1], a[i+1]);
	for(int i=l; i<=r; ++i) q[i]+=i;
	sort(rk+l, rk+mid+1, [&](int x, int y){return q[x]<q[y];});
	mx=0; mx2=0;
	it=l;
	for(int i=mid+1; i<=r; ++i){
		while(it<=mid&&q[rk[it]]<=q[i]){
			T.add(rk[it], preans[rk[it]]);
			++it;
		}
		if(a[i]>a[mx]){
			mx2=mx; mx=i;
		}
		else if(a[i]>a[mx2]){
			mx2=i;
		}
		if(a[mx]!=a[mx2]){
			sub(ans[mx], 1ll*T.get(-(a[mx]-i))*sufans[i+1]%mod);
			plu(ans[mx], 1ll*T.get(-(a[mx2]-i))*sufans[i+1]%mod);
		}
	}
	for(int i=l; i<it; ++i) T.add(rk[i], -preans[rk[i]]);
	
}
void solve(){
	a[0]=1; a[n+1]=1;
    read(n);
	for(int i=1; i<=n; ++i) read(a[i]);
	dp[0]=1;
	calc(0, n);
	for(int i=0; i<=n; ++i) preans[i]=dp[i], dp[i]=0;
	dp[0]=1;
	reverse(a+1, a+n+1);
	calc(0, n);
	for(int i=1; i<=n+1; ++i) sufans[i]=dp[n+1-i], dp[n+1-i]=0;
	reverse(a+1, a+n+1);
	for(int i=1; i<=n; ++i) ans[i]=preans[n];
	calc2(0, n);
	for(int i=1; i<=n; ++i) printf("%d ", ans[i]);
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	solve();
	return 0;
}

