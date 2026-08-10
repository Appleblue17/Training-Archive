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
ll a[N], dis[N]; int fr[N];
vector<pii> e[N];
bool v[N];
struct node{
	int x, y; ll z;
};
vector<node> vec;
int fa[N];
int get(int x){
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
bool merge(int x, int y){
	x=get(x); y=get(y);
	if(x==y) return false;
	fa[x]=y; return true;
}
void solve(){
	read(n); read(m);
	priority_queue<pair<ll, int> > pq;
	for(int i=1; i<=n; ++i) {
		read(dis[i]); fr[i]=i; fa[i]=i; v[i]=0;
		a[i]=dis[i];
		e[i].clear();
		pq.push(mapa(-dis[i], i));
	}
	for(int i=1, x, y, z; i<=m; ++i){
		read(x); read(y); read(z);
		e[x].ep(y, z); e[y].ep(x, z);
	}
	while(!pq.empty()){
		int x=pq.top().se; pq.pop();
		if(v[x]) continue;
		v[x]=1;
		for(auto edg:e[x]){
			int y=edg.fi, z=edg.se;
			if(dis[y]>dis[x]+z){
				fr[y]=fr[x];
				dis[y]=dis[x]+z;
				pq.push(mapa(-dis[y], y));
			}
		}
	}
	ll ans=0;
	for(int i=1; i<=n; ++i){
		if(fr[i]!=i){
			ans+=dis[i]+a[i];
			assert(merge(i, fr[i]));
		}
	}
	vec.clear();
	for(int x=1; x<=n; ++x){
		for(auto edg:e[x]) {
			int y=edg.fi;
			if(x>y) continue;
			if(fr[x]!=fr[y]){
				vec.ep((node){fr[x], fr[y], dis[x]+dis[y]+edg.se});
			}
		}
	}
	sort(vec.begin(), vec.end(), [&](node x, node y){return x.z<y.z;});
	for(auto t:vec){
		if(merge(t.x, t.y)){
			ans+=t.z;
		}
	}
	a[0]=a[1];
	for(int i=1; i<=n; ++i){
		ans-=a[i];
		a[0]=min(a[0], a[i]);
	}
	ans+=a[0];
	printf("%lld\n", ans);
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
