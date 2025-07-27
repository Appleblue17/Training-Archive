#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=1e6+5;
int T, n, m;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair
#define ep emplace_back
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
int a[N];
int tr[N];
void add(int x){
	++x;
	for(; x<=n+1; x+=(x&-x)) ++tr[x];
}
int get(int x){
	int ret=0;
	for(; x; x-=(x&-x)) ret+=tr[x];
	return ret;
}
int c[N];
ll dp[N];
void solve(){
	read(n);
	ll res=0;
	for(int i=1; i<=n; ++i) {
		read(a[i]); 
		if(a[i]>i){
			res+=a[i]-max(i, a[i-1]);
			a[i]=max(i, a[i-1]);
		}
	}
	for(int i=1; i<=n; ++i) a[i]=i-a[i], res+=a[i];
	for(int i=1; i<=n+1; ++i) tr[i]=0;
	for(int i=n; i>=1; --i){
		c[i]=get(a[i]);
		add(a[i]);
	}
	// for(int i=1; i<=n; ++i) cout<<a[i]<<' ';
	// cout<<endl;
	// for(int i=1; i<=n; ++i) cout<<c[i]<<' ';
	// cout<<endl;
	for(int i=1; i<=n; ++i) dp[i]=1e18;
	dp[0]=0;
	for(int i=1; i<=n; ++i){
		if(a[i]==0) continue;
		dp[a[i]]=min(dp[a[i]], dp[a[i]-1]-(n-i+1-c[i])+c[i]);
	}
	ll mndp=0;
	for(int i=1; i<=n; ++i) mndp=min(mndp, dp[i]);
	printf("%lld\n", res+mndp);
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    read(T);
    while(T--){
        solve();
    }
    
    
}