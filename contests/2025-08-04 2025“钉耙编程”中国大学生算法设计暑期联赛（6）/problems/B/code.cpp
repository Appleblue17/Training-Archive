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
const int N=5e6+5;
int T, n, m;
int a[N];
int s[N];
ll pre[N];
ll mem[N];
ll calc(int x){
	if(mem[x]!=-1) return mem[x];
	ll sum=0;
	for(int i=1; i<=n; ++i){
		sum+=a[i]/x;
		sum+=(a[i]%x+a[1]-1)/a[1];
	}
	return mem[x]=sum;
}
void solve(){
	read(n); read(m);
	for(int i=1; i<=n; ++i) read(a[i]);
	sort(a+1, a+n+1);
	for(int i=1; i<=a[n]; ++i) s[i]=0, mem[i]=-1;
	for(int i=1; i<=n; ++i) ++s[a[i]];
	for(int i=1; i<=a[n]; ++i) s[i]+=s[i-1];
	ll res=1e18;
	int d=a[1];
	for(int i=1; i<=n; ++i){
		if(__gcd(d, a[i])!=d){
			d=__gcd(d, a[i]);
			pre[i]=0;
			for(int j=1; j<=i; ++j) {
				pre[i]+=a[j]/d;
			}
		}
		else{
			pre[i]=pre[i-1]+a[i]/d;
		}
	}
	res=pre[n];
	for(int r=n, l=n; r>=1; r=l-1){
		l=r;
		while(l-1>=1&&a[l-1]==a[l]) --l;
		ll ans=pre[l-1]+(r-l+1), id=1;
		for(int x=a[l]+1, y=a[l]*2; x<=a[n]; x+=a[l], y+=a[l]){
			y=min(y, a[n]);
			++id;
			ans+=id*(s[y]-s[x-1]);
		}
		res=min(res, ans);
		// cout<<"???"<<l<<' '<<r<<' '<<sum<<' '<<ans<<endl;
	}
	int L=a[1]+1, R=a[n], mid, ret=1;
	while(L<=R){
		mid=(L+R)>>1;
		if(calc(mid-1)>=calc(mid)){
			ret=mid; L=mid+1;
		}
		else{
			R=mid-1;
		}
	}
	for(int i=ret; i>=ret-30&&i>=1; --i) res=min(res, calc(i));
	for(int i=ret+1; i<=ret+30&&i<=a[n]; ++i) res=min(res, calc(i));
	printf("%lld\n", res);
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(T);
	while(T--){
		solve();
	}
	return 0;
}