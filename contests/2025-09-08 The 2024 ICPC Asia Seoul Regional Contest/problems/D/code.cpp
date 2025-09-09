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
int n, m, q;
int ph[N], pa[N], pid[N];
vector<pii> vec;
struct node{
	int son[2], fa;
}tr[N];
#define s(x, o) tr[x].son[o]
#define fa(x) tr[x].fa
void rotate(int x){
	int y=fa(x), z=fa(y);
	int k=s(y, 1)==x;
	if(fa(y)) s(z, s(z, 1)==y)=x;
	fa(x)=z;
	s(y, k)=s(x, k^1); fa(s(x, k^1))=y;
	s(x, k^1)=y; fa(y)=x;
}
void splay(int x){
	while(fa(x)){
		int y=fa(x), z=fa(y);
		if(fa(y)){
			if((s(y, 1)==x)^(s(z, 1)==y)) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
}
void swp(int x, int y){
	splay(x); splay(y);
	swap(s(x, 0), s(y, 0));
	fa(s(x, 0))=x; fa(s(y, 0))=y;
}
vector<int> op[N];
int p[N], rev[N];
int rt[N];
int sz[N*60], ls[N*60], rs[N*60], idx;
void addd(int &p, int l, int r, int x, int v){
	if(!p) p=++idx;
	sz[p]+=v;
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(x<=mid) addd(ls[p], l, mid, x, v);
	else addd(rs[p], mid+1, r, x, v);
}
void add(int x, int y, int v){
	for(; x<=n; x+=(x&-x)) addd(rt[x], 1, n, y, v);
}
int qryy(int &p, int l, int r, int L, int R){
	if(!p) return 0;
	if(L<=l&&r<=R) return sz[p];
	int mid=(l+r)>>1, ret=0;
	if(L<=mid) ret=qryy(ls[p], l, mid, L, R);
	if(R>mid) ret+=qryy(rs[p], mid+1, r, L, R);
	return ret;
}
int qry(int l1, int r1, int l2, int r2){
	if(l1>r1||l2>r2) return 0;
	int ret=0;
	for(; r1; r1-=(r1&-r1)){
		ret+=qryy(rt[r1], 1, n, l2, r2);
	}
	for(--l1; l1; l1-=(l1&-l1)){
		ret-=qryy(rt[l1], 1, n, l2, r2);
	}
	return ret;
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	read(n); read(m); read(q);
	for(int i=1; i<=m; ++i){
		read(ph[i]); read(pa[i]);
		vec.ep(ph[i], pa[i]);
	}
	for(int i=m+1; i<=m+q; ++i){
		read(ph[i]); read(pa[i]);
		vec.ep(ph[i], pa[i]);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for(int i=1; i<=m+q; ++i){
		pid[i]=lower_bound(vec.begin(), vec.end(), mapa(ph[i], pa[i]))-vec.begin()+1;
	}
	for(int i=1; i<=(int)vec.size(); ++i){
		op[vec[i-1].se].ep(i<<1);
		op[vec[i-1].se+1].ep(i<<1|1);
	}
	for(int i=1; i<=n; ++i){
		p[i]=i;
		int rt=i+(vec.size()<<1|1);
		for(auto t:op[i]){
			s(rt, 1)=t; fa(t)=rt; rt=t;
		}
	}
	vector<int> init;
	for(int i=1; i<=m; ++i){
		swp(pid[i]<<1, pid[i]<<1|1);
		init.ep(pid[i]);
	}
	sort(init.begin(), init.end());
	for(auto t:init){
		swap(p[vec[t-1].se], p[vec[t-1].se+1]);
	}
	for(int i=1; i<=n; ++i) rev[p[i]]=i;
	ll cur=0;
	for(int i=1; i<=n; ++i){
		add(i, p[i], 1);
		cur+=qry(1, i-1, p[i]+1, n);
	}
	for(int i=m+1; i<=m+q; ++i){
		swp(pid[i]<<1, pid[i]<<1|1);
		int u=pid[i]<<1, v=pid[i]<<1|1;
		while(s(u, 0)) u=s(u, 0);
		while(s(v, 0)) v=s(v, 0);
		u-=(vec.size()<<1|1), v-=(vec.size()<<1|1);
		u=rev[u]; v=rev[v];
		// cout<<u<<' '<<v<<' '<<p[u]<<' '<<p[v]<<endl;
		cur-=qry(1, u-1, p[u]+1, n)+qry(u+1, n, 1, p[u]-1);
		add(u, p[u], -1);
		cur-=qry(1, v-1, p[v]+1, n)+qry(v+1, n, 1, p[v]-1);
		add(v, p[v], -1);
		add(u, p[v], 1);
		cur+=qry(1, u-1, p[v]+1, n)+qry(u+1, n, 1, p[v]-1);
		add(v, p[u], 1);
		cur+=qry(1, v-1, p[u]+1, n)+qry(v+1, n, 1, p[u]-1);
		swap(p[u], p[v]); rev[p[u]]=u; rev[p[v]]=v;
		printf("%lld\n", cur);
	}
	return 0;
}
