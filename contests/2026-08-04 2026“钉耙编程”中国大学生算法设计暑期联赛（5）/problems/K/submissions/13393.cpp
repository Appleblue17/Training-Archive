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
const int N=2e5+5, mod=998244353;
int T, n, m;
vector<int> e[N];
int qv[N], qk[N], qa[N][11];
int dfn[N], timer, dep[N], seq[N];
void dfs(int x, int fa){
    dep[x]=dep[fa]+1;
    dfn[x]=++timer; seq[timer]=x;
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y, x);
        seq[++timer]=x;
    }
}
int lg[N], st[20][N];
void pre(){
    for(int i=2; i<=timer; ++i) lg[i]=lg[i>>1]+1;
    for(int i=1; i<=timer; ++i) st[0][i]=seq[i];
    for(int i=1; i<=lg[timer]; ++i){
        for(int j=1; j+(1<<i)-1<=timer; ++j){
            st[i][j]=dep[st[i-1][j]]<dep[st[i-1][j+(1<<(i-1))]]?st[i-1][j]:st[i-1][j+(1<<(i-1))];
        }
    }
}
inline int lca(int x, int y){
    x=dfn[x]; y=dfn[y];
    if(x>y) swap(x, y);
	int t=lg[y-x+1];
    return dep[st[t][x]]<dep[st[t][y-(1<<t)+1]]?st[t][x]:st[t][y-(1<<t)+1];
}
inline int dis(int x, int y){
    return dep[x]+dep[y]-2*dep[lca(x, y)];
}
vector<pii> fr[N];
bool ban[N];
int sz[N], mxs[N];
void dfs1(int x, int fa, int allsz, int &rt){
    sz[x]=1; mxs[x]=0;
    for(auto y:e[x]) {
        if(y==fa||ban[y]) continue;
        dfs1(y, x, allsz, rt);
        sz[x]+=sz[y];
        mxs[x]=max(mxs[x], sz[y]);
    }
    if(rt==0||max(mxs[x], allsz-sz[x])<max(mxs[rt], allsz-sz[rt])) rt=x;
}
void dfs2(int x, int fa, int id, int rt){
    sz[x]=1; fr[x].ep(rt, id);
    for(auto y:e[x]) {
        if(y==fa||ban[y]) continue;
        dfs2(y, x, id, rt);
        sz[x]+=sz[y];
    }
}
void work(int x, int allsz){
    int rt=x;
    dfs1(x, 0, allsz, rt);
    fr[rt].ep(rt, rt);
    for(auto y:e[rt]){
        if(!ban[y]) dfs2(y, rt, y, rt);
    }
    ban[rt]=1;
    for(auto y:e[rt]){
        if(!ban[y]) work(y, sz[y]);
    }
}
struct info{
    int mx1, c1, mx2, c2;
    info(int _mx1=0, int _c1=0, int _mx2=0, int _c2=0){
        mx1=_mx1; c1=_c1; mx2=_mx2; c2=_c2;
    }
};
inline info operator +(info x, info y){
    info ret;
    vector<pii> v;
    v.ep(mapa(x.mx1, x.c1));
    v.ep(mapa(x.mx2, x.c2));
    v.ep(mapa(y.mx1, y.c1));
    v.ep(mapa(y.mx2, y.c2));
    sort(v.begin(), v.end());
    ret.mx1=v.back().fi; ret.c1=v.back().se;
    for(int i=2; i>=0; --i){
        if(v[i].se!=ret.c1){
            ret.mx2=v[i].fi; ret.c2=v[i].se;
            return ret;
        }
    }
    return ret;
}
info tr[N*60]; int ls[N*60], rs[N*60];
int rt[N], idx;
void add(int &p, int l, int r, int L, int R, int v, int c){
    if(!p){
        p=++idx;
        tr[p]=tr[0]; ls[p]=rs[p]=0;
    }
    if(L<=l&&r<=R){
        tr[p]=tr[p]+(info){v, c, 0, 0};
        return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid) add(ls[p], l, mid, L, R, v, c);
    if(R>mid) add(rs[p], mid+1, r, L, R, v, c);
}
void get(int p, int l, int r, int x, info &ret){
    if(!p) {
        return ;
    }
    ret=ret+tr[p];
    if(l==r) {
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) get(ls[p], l, mid, x, ret);
    else get(rs[p], mid+1, r, x, ret);
}
void solve(){
    read(n); read(m);
    timer=0;
    idx=0;
    for(int i=1; i<=n; ++i) {
        e[i].clear(); fr[i].clear();
        ban[i]=0; rt[i]=0;
    }
    for(int i=1, x, y; i<n; ++i){
        read(x); read(y);
        e[x].push_back(y); e[y].push_back(x);
    }
    dfs(1, 0);
    pre();
    work(1, n);
    for(int i=1, op, l, r, x; i<=m; ++i){
        read(op);
        if(op==1){
            read(qv[i]); read(l); read(r); read(qk[i]);
            for(int j=0; j<=qk[i]; ++j) read(qa[i][j]); 
            for(auto [fa, c]:fr[qv[i]]){
                int d=dis(fa, qv[i]);
                if(d>r) continue;
                // cout<<fa<<' '<<max(0, l-d)<<' '<<r-d<<' '<<i<<' '<<c<<endl;
                if(fa==qv[i]) c=0;
                add(rt[fa], 0, n-1, max(0, l-d), r-d, i, c);
            }
        }
        else{
            read(x);
            int id=0;
            for(auto [fa, c]:fr[x]){
                int d=dis(fa, x);
                info cur;
                get(rt[fa], 0, n-1, d, cur);
                // cout<<fa<<' '<<d<<endl;
                // cout<<cur.mx1<<' '<<cur.c1<<' '<<cur.mx2<<' '<<cur.c2<<endl;
                if(cur.c1!=c) id=max(id, cur.mx1);
                else id=max(id, cur.mx2);
            }
            // cout<<"ans:";
            if(id==0){
                printf("0\n");
                continue;
            }
            ll ans=0, pw=1;
            int d=dis(qv[id], x);
            for(int j=0; j<=qk[id]; ++j, pw=pw*d%mod){
                ans=(ans+pw*qa[id][j])%mod;
            }
            printf("%lld\n", ans);
        }
    }
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