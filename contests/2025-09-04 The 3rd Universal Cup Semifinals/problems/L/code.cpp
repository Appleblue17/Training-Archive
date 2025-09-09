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
int T, n, m;
ll a[N], dis[N], dis2[N];
vector<pii> e[N];
void solve(){
	read(n); read(m);
	priority_queue<pair<ll, int> > pq;
	for(int i=1; i<=n; ++i) {
		read(dis[i]); dis2[i]=1e18;
		a[i]=dis[i];
		e[i].clear();
		pq.push(mapa(-dis[i], i));
	}
	for(int i=1, x, y, z; i<=m; ++i){
		read(x); read(y); read(z);
		e[x].ep(y, z); e[y].ep(x, z);
	}
	while(!pq.empty()){
		int x=pq.top().se; ll cur=-pq.top().fi; pq.pop();
		if(cur>dis2[x]) continue;
		for(auto edg:e[x]){
			int y=edg.fi, z=edg.se;
			if(dis[y]>cur+z){
				dis2[y]=dis[y];
				dis[y]=cur+z;
				pq.push(mapa(-dis[y], y));
			}
			else if(dis2[y]>cur+z){
				dis2[y]=cur+z;
				pq.push(mapa(-dis2[y], y));
			}
		}
	}
	vector<ll> vec;
	for(int i=1; i<=n; ++i){
		if(dis[i]==a[i]){
			vec.ep(dis2[i]);
		}
		else{
			vec.ep(dis[i]);
		}
	}
	sort(vec.begin(), vec.end());
	vec.pop_back();
	ll sum=0;
	for(auto t:vec) sum+=t;
	printf("%lld\n", sum);
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	read(T);
	while(T--){
		solve();
	}
	return 0;
}
