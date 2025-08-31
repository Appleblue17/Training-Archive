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
const ll inf=1e18;
int n; ll m;
vector<int> e[N];
int a[N];
ll f[N], g[N];
int sz[N];
int p[N];
ll pre[N], suf[N];
int sum[N];
void dfs(int x, int fa){
	sz[x]=1;
	for(auto y:e[x]) if(y^fa){
		dfs(y, x); sz[x]+=sz[y];
	}
	f[x]=a[x]+min(0ll, m-2*sz[x]);
	int cnt=0;
	for(auto y:e[x]) if(y^fa) p[++cnt]=y;
	if(!cnt){
		g[x]=a[x];
		return ;
	}
	sort(p+1, p+cnt+1, [&](int x, int y){return f[x]+2*sz[x]<f[y]+2*sz[y];});
	for(int i=1; i<=cnt; ++i) sum[i]=sum[i-1]+sz[p[i]]*2;
	pre[0]=inf;
	for(int i=1; i<=cnt; ++i){
		f[x]=min(f[x], f[p[i]]-1-sum[i-1]);
	}
	for(int i=1; i<=cnt; ++i){
		pre[i]=min(pre[i-1], f[p[i]]-1-sum[i-1]);
	}
	suf[cnt+1]=inf;
	for(int i=cnt; i>=1; --i){
		suf[i]=min(f[p[i]], suf[i+1]-sz[p[i]]*2);
	}
	g[x]=-inf;
	for(int i=1; i<=cnt; ++i){
		ll cur=a[x]+min(0ll, m-2*(sz[x]-sz[p[i]]));
		cur=min(cur, pre[i-1]);
		cur=min(cur, suf[i+1]-sum[i-1]);
		cur=min(cur, g[p[i]]-1-2*(sz[x]-sz[p[i]]-1));
		g[x]=max(g[x], cur);
	}
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n); read(m);
	for(int i=1, x, y; i<n; ++i){
		read(x); read(y);
		e[x].ep(y); e[y].ep(x);
	}
	for(int i=1; i<=n; ++i) read(a[i]);
	dfs(1, 0);
	g[1]=max(g[1], -1ll);
	printf("%lld\n", g[1]);
	return 0;
}

