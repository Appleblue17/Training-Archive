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
const int N=1e6+5, mod=998244353;
int T, n, m;
using u32=uint32_t;
using i32=int32_t;
using u64=uint64_t;
using i64=int64_t;
static u32 _m,m2,inv,r2;
u32 getinv(){
    u32 inv=_m;
    for(int i=0;i<4;++i) inv*=2-inv*_m;
    return inv;
}
struct Mont{
private :
    u32 x;
public :
    static u32 reduce(u64 x){ 
        u32 y=(x+u64(u32(x)*inv)*_m)>>32;
        return i32(y)<0?y+_m:y;
    }
    Mont(){ ; }
    Mont(i32 x):x(reduce(u64(x)*r2)) { }
    Mont& operator += (const Mont &rhs) { return x+=rhs.x-m2,i32(x)<0&&(x+=m2),*this; }
    Mont& operator -= (const Mont &rhs) { return x-=rhs.x,i32(x)<0&&(x+=m2),*this; }
    Mont& operator *= (const Mont &rhs) { return x=reduce(u64(x)*rhs.x),*this; }
    friend Mont operator + (Mont x,const Mont &y) { return x+=y; }
    friend Mont operator - (Mont x,const Mont &y) { return x-=y; }
    friend Mont operator * (Mont x,const Mont &y) { return x*=y; }
    i32 get(){ 
        u32 res=reduce(x);
        return res>=_m?res-_m:res;
    }
};
void Init(int _m) { 
    ::_m=_m,m2=_m*2;
    inv=-getinv();
    r2=-u64(_m)%_m;
}
struct info{
    Mont A, B, C, AB, BC, AC, ABC, w, Aw, Bw, Cw, ABw, BCw, ACw, ans;
};
struct tag{
    ll x, y, z;
	tag(ll _x=0, ll _y=0, ll _z=0){x=_x; y=_y; z=_z;}
	void clr(){
		x=0; y=0; z=0;
	}
	bool empty(){
		return x==0&&y==0&&z==0;
	}
};
inline info operator +(info x, info y){
    info z;
    z.A=x.A+y.A; z.B=x.B+y.B; z.C=x.C+y.C; 
	z.AB=x.AB+y.AB; z.BC=x.BC+y.BC; z.AC=x.AC+y.AC;
	z.ABC=x.ABC+y.ABC; 
	z.w=x.w+y.w;
    z.Aw=x.Aw+y.Aw; z.Bw=x.Bw+y.Bw; z.Cw=x.Cw+y.Cw; 
	z.ABw=x.ABw+y.ABw; z.BCw=x.BCw+y.BCw; z.ACw=x.ACw+y.ACw;
	z.ans=x.ans+y.ans;
	return z;
}
inline info operator *(info t, tag o){
    info r;
	r.A=t.A+o.x; r.B=t.B+o.y; r.C=t.C+o.z;
	r.AB=t.AB+t.A*o.y+t.B*o.x+o.x*o.y;
	r.BC=t.BC+t.B*o.z+t.C*o.y+o.y*o.z;
	r.AC=t.AC+t.A*o.z+t.C*o.x+o.x*o.z;
	r.ABC=t.ABC;
	r.ABC+=o.x*t.BC+o.y*t.AC+o.z*t.AB;
	r.ABC+=o.x*o.y*t.C+t.A*o.y*o.z+o.x*t.B*o.z;
	r.ABC+=o.x*o.y*o.z;
	r.w=t.w;
	r.Aw=t.Aw+t.w*o.x; r.Bw=t.Bw+t.w*o.y; r.Cw=t.Cw+t.w*o.z;
	r.ABw=t.ABw+t.Aw*o.y+t.Bw*o.x+t.w*o.x*o.y;
	r.BCw=t.BCw+t.Bw*o.z+t.Cw*o.y+t.w*o.y*o.z;
	r.ACw=t.ACw+t.Aw*o.z+t.Cw*o.x+t.w*o.x*o.z;
	r.ans=t.ans;
	r.ans+=o.x*t.BCw+o.y*t.ACw+o.z*t.ABw;
	r.ans+=o.x*o.y*t.Cw+t.Aw*o.y*o.z+o.x*t.Bw*o.z;
	r.ans+=t.w*o.x*o.y*o.z;
	return r;
}
inline tag operator *(tag a, tag b){
	tag ret;
	ret.x=a.x+b.x; ret.y=a.y+b.y; ret.z=a.z+b.z;
	return ret;
}
inline tag operator *(tag a, int len){
	tag ret=a;
	ret.x*=len; ret.y*=len; ret.z*=len;
	return ret;
}
int a[N], lg[N];
int argmx[20][N];
int gmx(int l, int r){
	int t=lg[r-l+1];
	return a[argmx[t][l]]>a[argmx[t][r-(1<<t)+1]]?argmx[t][l]:argmx[t][r-(1<<t)+1];
}
int rt, idx, ls[N], rs[N], val[N], w[N], pos[N];
vector<int> e[N];
void build(int &p, int l, int r){
	if(l>r) return ;
	p=++idx;
	int mid=gmx(l, r); 
	val[p]=a[mid]; pos[mid]=p;
	build(ls[p], l, mid-1);
	build(rs[p], mid+1, r);
	if(ls[p]) e[p].ep(ls[p]);
	if(rs[p]) e[p].ep(rs[p]);
}
int sz[N], son[N], f[N], dep[N];
int top[N], dfn[N], seq[N], timer;
void dfs(int x, int fa){
	f[x]=fa; dep[x]=dep[fa]+1; sz[x]=1;
	w[x]=val[x]-val[fa];
	for(auto y:e[x]) {
		dfs(y, x);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]]) son[x]=y;
	}
}
void dfs2(int x, int tp){
	dfn[x]=++timer; seq[timer]=x; top[x]=tp;
	if(son[x]) dfs2(son[x], tp);
	for(auto y:e[x]) if(y^son[x]) dfs2(y, y);
}
info tr[N<<2]; tag tg[N<<2]; 
void init(int p, int l, int r){
	if(l==r){
		tr[p].w=w[seq[l]];
		return ;
	}
	int mid=(l+r)>>1;
	init(p<<1, l, mid); init(p<<1|1, mid+1, r);
	tr[p]=tr[p<<1]+tr[p<<1|1];
}
void apply(int p, tag v){
	tr[p]=tr[p]*v;
	tg[p]=tg[p]*v;
}
inline void down(int p){
	if(!tg[p].empty()){
		apply(p<<1, tg[p]);
		apply(p<<1|1, tg[p]);
		tg[p].clr();
	}
}
void mdf(int p, int l, int r, int L, int R, tag v){
	// if(l==r){
	if(L<=l&&r<=R){
		apply(p, v);
		return ;
	}
	int mid=(l+r)>>1;
	down(p);
	if(L<=mid) mdf(p<<1, l, mid, L, R, v);
	if(R>mid) mdf(p<<1|1, mid+1, r, L, R, v);
	tr[p]=tr[p<<1]+tr[p<<1|1];
}
char op[2];
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	Init(mod);
	read(n); read(m);
	for(int i=1; i<=n; ++i) read(a[i]), argmx[0][i]=i;
	for(int i=2; i<=n; ++i) lg[i]=lg[i>>1]+1;
	for(int t=1; t<=lg[n]; ++t){
		for(int i=1; i+(1<<t)-1<=n; ++i){
			argmx[t][i]=(a[argmx[t-1][i]]>a[argmx[t-1][i+(1<<(t-1))]])?argmx[t-1][i]:argmx[t-1][i+(1<<(t-1))];
		}
	}
	build(rt, 1, n);
	dfs(1, 0); dfs2(1, 1);
	// for(int i=1; i<=n; ++i) cout<<w[i]<<' ';
	// cout<<endl;
	// for(int i=1; i<=n; ++i) cout<<seq[i]<<' ';
	// cout<<endl;
	init(1, 1, n);
	int x; 
	while(m--){
		scanf("%s", op+1); read(x);
		x=pos[x];
		while(x){
			if(op[1]=='A') mdf(1, 1, n, dfn[top[x]], dfn[x], tag(1, 0, 0));
			if(op[1]=='B') mdf(1, 1, n, dfn[top[x]], dfn[x], tag(0, 1, 0));
			if(op[1]=='C') mdf(1, 1, n, dfn[top[x]], dfn[x], tag(0, 0, 1));
			x=f[top[x]];
		}
		printf("%lld\n", tr[1].ans.get());
		// dfs(1, 1, n);
	}
	return 0;
}

