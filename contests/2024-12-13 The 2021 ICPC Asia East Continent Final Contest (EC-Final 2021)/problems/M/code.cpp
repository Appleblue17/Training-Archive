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
const int N=1e6+5;
int T, n; ll m;
ll a[N];
struct node{
	ll x; int tp, cnt;
	inline bool operator <(const node &t)const{
		return x<t.x;
	}
};
bool check(ll lim){
	ll h=lim/2;
	vector<node> vec;
	for(int i=1; i<=n; ++i){
		vec.push_back((node){a[i]+1, 0, 2});
		vec.push_back((node){a[i]+h+1, 0, -1});
		vec.push_back((node){a[i]+lim-h+1, 0, -1});
		vec.push_back((node){h-a[i], 1, 1});
		vec.push_back((node){lim-h-a[i], 1, 1});
		vec.push_back((node){lim-a[i], 1, -2});
	}
	sort(vec.begin(), vec.end());
	__int128 sum=0, lst=0, lsum=0, rsum=0;
	for(int i=0; i+1<(int)vec.size(); ++i){
		if(vec[i].tp==0){
			lsum+=vec[i].cnt;
		}
		else{
			rsum+=vec[i].cnt;
		}
		if(vec[i].x==vec[i+1].x) continue;
		if(lsum>=rsum){
			sum+=rsum*(vec[i+1].x-vec[i].x);
			lst+=(lsum-rsum)*(vec[i+1].x-vec[i].x);
		}
		else{
			lst+=lsum*(vec[i+1].x-vec[i].x);
			__int128 cur=min(rsum*(vec[i+1].x-vec[i].x), lst);
			sum+=cur; lst-=cur;
		}
		if(sum>=m) return true;
	}
	return false;
}
void solve(){
	read(n); read(m); m*=2;
	for(int i=1; i<=n; ++i) read(a[i]);
	ll L=1, R=1e15, mid, ret=0;
	while(L<=R){
		mid=(L+R)/2;
		if(check(mid)){
			ret=mid; R=mid-1;
		}
		else{
			L=mid+1;
		}
	}
	printf("%lld\n", ret);
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

