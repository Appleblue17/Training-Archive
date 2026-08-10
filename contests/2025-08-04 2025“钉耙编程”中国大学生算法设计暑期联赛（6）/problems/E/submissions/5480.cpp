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
int a[N];
vector<int> e[N];
int dep[N], f[N][20], dfn[N], timer, sz[N];
void dfs(int x, int fa){
	f[x][0]=fa; dep[x]=dep[fa]+1;
	sz[x]=1; dfn[x]=++timer;
	for(int i=1; i<20; ++i) f[x][i]=f[f[x][i-1]][i-1];
	for(auto y:e[x]) if(y^fa){
		dfs(y, x);
		sz[x]+=sz[y];
	}
}
int kid[N], lid[N];
int lca(int x, int y){
	if(dep[x]<dep[y]) swap(x, y);
	for(int i=19; i>=0; --i) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19; i>=0; --i) if(f[x][i]^f[y][i]) x=f[x][i], y=f[y][i];
	return f[x][0];
}
int tag[N];
void apply(int l, int r){
	if(l>r) return ;
	++tag[l]; --tag[r+1];
}
int jump(int x, int top){
	for(int i=19; i>=0; --i) if(dep[f[x][i]]>dep[top]) x=f[x][i];
	return x;
}
int ans[N];
bool vis[N];
void solve(){
	read(n);
	for(int i=1; i<=n*2; ++i) {
		read(a[i]), e[i].clear();
		if(a[i]>0) kid[a[i]]=i;
		else lid[-a[i]]=i;
		tag[i]=0;
	}
	for(int i=1, x, y; i<n*2; ++i){
		read(x); read(y);
		e[x].ep(y); e[y].ep(x);
	}
	timer=0;
	dfs(1, 0);
	for(int i=1; i<=n; ++i){
		int x=kid[i], y=lid[i];
		int z=lca(x, y);
		if(z!=y){
			apply(dfn[y], dfn[y]+sz[y]-1);
			continue;
		}
		z=jump(x, y);
		apply(1, dfn[z]-1);
		apply(dfn[z]+sz[z], n*2);
	}
	for(int i=1; i<=2*n; ++i) tag[i]+=tag[i-1];
	int id=0;
	for(int i=1; i<=n; ++i){
		if(tag[dfn[kid[i]]]) ans[i]=0;
		else ans[i]=1, id=kid[i];
	}
	if(id!=0) {
		set<pii> st;
		unordered_map<int, int> hk, hl;
		st.insert(mapa(0, id));
		for(int i=1; i<=2*n; ++i) vis[i]=0;
		vis[id]=1;
		while(!st.empty()){
			int x=(*st.begin()).se;
			int tp=(*st.begin()).fi;
			st.erase(st.begin());
			if(tp==0){
				hk[a[x]]=1;
				if(hl.find(a[x])!=hl.end()){
					int y=hl[a[x]];
					st.insert(mapa(1, y));
				}
			}
			else if(tp==2){
				hl[-a[x]]=x;
				if(hk.find(-a[x])!=hk.end()){
					st.insert(mapa(1, x));
				}
				else{
					continue;
				}
			}
			for(auto y:e[x]){
				if(vis[y]) continue;
				vis[y]=1;
				if(a[y]>0){
					st.insert(mapa(0, y));
				}
				else{
					st.insert(mapa(2, y));
				}
			}
		}
		if((int)hk.size()!=n){
			for(int i=1; i<=n; ++i) ans[i]=0;
		}
	}
	for(int i=1; i<=n; ++i) printf("%d", ans[i]);
	putchar('\n');
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