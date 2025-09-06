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
int T, n, m, q;
vector<int> e[2][N];
vector<pii> vec[N];
bool check(pii a, pii b, pii c){
	return 1ll*(b.se-a.se)*(c.fi-b.fi)>=1ll*(c.se-b.se)*(b.fi-a.fi);
}
void append(vector<pii> &x, pii y){
	while(x.size()>=2&&check(x[x.size()-2], x[x.size()-1], y)){
		x.pop_back();
	}
	x.push_back(y);
}
vector<pii> merge(vector<pii> x, vector<pii> y){
	int it1=0, it2=0;
	vector<pii> ret;
	while(it1<(int)x.size()||it2<(int)y.size()){
		if(it1==(int)x.size()) append(ret, y[it2++]);
		else if(it2==(int)y.size()) append(ret, x[it1++]);
		else if(x[it1].fi<y[it2].fi||(x[it1].fi==y[it2].fi&&x[it1].se>y[it2].se)) append(ret, x[it1++]);
		else append(ret, y[it2++]);
	}
	return ret;
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	read(n); read(m);
	for(int i=1, u, v, c; i<=m; ++i){
		read(u); read(v); read(c);
		e[c][v].ep(u);
	}
	vec[1].ep(0, 0);
	for(int i=2; i<=n; ++i){
		for(auto j:e[1][i]){
			vector<pii> cur;
			for(auto t:vec[j]) cur.ep(t.fi, t.se+1);
			vec[i]=merge(vec[i], cur);
		}
		for(auto j:e[0][i]){
			vector<pii> cur;
			for(auto t:vec[j]) cur.ep(t.fi+1, t.se);
			vec[i]=merge(vec[i], cur);
		}
	}
	read(q);
	int a, b, x;
	while(q--){
		read(a); read(b); read(x);
		ll ans=1e18;
		for(auto t:vec[x]){
			ans=min(ans, 1ll*a*t.fi+1ll*b*t.se);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

