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
int fa[N], sz[N];
ll hs(int x, int y){
	if(x>y) swap(x, y);
	return 10000000ll*x+y;
}
unordered_map<ll, int> h;
vector<int> bin[N];
int rx(int x){
	if(x>n) return x-n;
	return x;
}
ll ans;
void del(int x){
	int f1=fa[x], f2=fa[x+n];
	if(f1==f2){
		sz[f1]--;
		ans-=sz[f1];
		return ;
	}
	--sz[f1]; --sz[f2]; --h[hs(f1, f2)];
	ans-=sz[f1]+sz[f2]-h[hs(f1, f2)];
}
void add(int x){
	int f1=fa[x], f2=fa[x+n];
	if(f1==f2){
		ans+=sz[f1];
		sz[f1]++;
		return ;
	}
	ans+=sz[f1]+sz[f2]-h[hs(f1, f2)];
	++sz[f1]; ++sz[f2]; ++h[hs(f1, f2)];
}
void merge(int x, int y){
	x=fa[x]; y=fa[y];
	if(x==y) return ;
	if(bin[y].size()>bin[x].size()) swap(x, y);
	for(auto t:bin[y]){
		del(rx(t));
		fa[t]=x;
		bin[x].ep(t);
		add(rx(t));
	}
	bin[y].clear();
}
void solve(){
	read(n); read(m);
	for(int i=1; i<=n*2; ++i){
		fa[i]=i;
		sz[i]=1;
		bin[i].ep(i);
	}
	for(int i=1; i<=n; ++i) h[hs(i, i+n)]=1;
	for(int i=1, x, y; i<=m; ++i){
		read(x); read(y);
		merge(x, y+n);
		printf("%lld\n", ans);
	}
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	T=1;
	while(T--){
		solve();
	}
	return 0;
}

