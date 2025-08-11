#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
using namespace std;

#define eb emplace_back
typedef pair<int, int> PII;
#define mp make_pair
#define fi first
#define se second

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? -1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f; 
}

const int N = 4e5 + 10;
int n, p[N];
vector<int> g[N];

int dep[N], par[N], siz[N], son[N];
void dfs1(int u, int fa) {
	par[u] = fa;
	dep[u] = dep[fa] + 1;
	siz[u] = 1;
	son[u] = 0;

	for(auto v : g[u]) if(v != fa) {
		dfs1(v, u);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]]) son[u] = v;
	}
}

int top[N];
void dfs2(int u, int tp) {
	top[u] = tp;
	if(son[u]) dfs2(son[u], tp);
	for(auto v : g[u]) if(v != par[u] && v != son[u])
		dfs2(v, v);
}

void clear() {
	rep(i, 1, n)
		g[i].clear(), 
		par[i] = dep[i] = siz[i] = son[i] = top[i] = 0;
}

int lca(int x, int y) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = par[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	return x;
}

int dis(int x, int y) {
	int z = lca(x, y);
	return dep[x] + dep[y] - 2 * dep[z];
}

void solve() {
	
	clear();
	
	n = read();
	rep(i, 1, n) {
		int w = read() + 1;
		p[w] = i;
	}
	rep(i, 1, n - 1) {
		int u = read();
		int v = read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs1(1, 0);
	dfs2(1, 1);
	
	puts("0");
	int x = p[1];
	int y = p[2];
	printf("%d\n", (dis(x, y) + 1) >> 1);
	
	rep(i, 3, n) {
		int o = p[i];
		if(dis(o, x) > dis(x, y)) {
			if(dis(o, y) > dis(o, x)) x = o; else y = o;
		}
		else if(dis(o, y) > dis(x, y)) x = o;
		
		printf("%d\n", (dis(x, y) + 1) >> 1);
	}
}

int main() {
	int t = read(); while(t --) solve(); return 0;
}