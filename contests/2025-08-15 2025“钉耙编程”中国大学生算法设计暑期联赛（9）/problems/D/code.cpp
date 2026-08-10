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
vector<pii> e[N]; vector<int> g[N]; 
vector<pair<pii, int> > e2;
int w[N];
struct bas{
    int bs[16];
    void add(int v){
        for(int i=15; i>=0; --i){
            if((v>>i)&1){
                if(!bs[i]) {
                    bs[i]=v;
                    return ;
                }
                v^=bs[i];
            }
        }
    }
    int work(int x){
        for(int i=15; i>=0; --i){
            x=max(x, x^bs[i]);
        }
        return x;
    }
    friend bas operator +(bas x, bas y){
        for(int i=15; i>=0; --i) if(y.bs[i]){
            for(int j=i; j>=0; --j){
                if((y.bs[i]>>j)&1){
                    if(!x.bs[j]) {x.bs[j]=y.bs[i]; break;}
                    y.bs[i]^=x.bs[j];
                }
            }
        }
        return x;
    }
}tr[N<<2], tag[N<<2], tem;
int f[N], sz[N], son[N], dep[N];
void dfs(int x, int fa){
    sz[x]=1; dep[x]=dep[fa]+1; f[x]=fa;
    for(auto edg:e[x]){
        int y=edg.fi, z=edg.se;
        if(y==fa) continue;
        if(sz[y]==0){
            g[x].ep(y);
            w[y]=w[x]^z; 
            dfs(y, x);
            sz[x]+=sz[y];
            if(sz[y]>sz[son[x]]) son[x]=y;
        }
        else{
            e2.ep(mapa(mapa(x, y), z));
        }
    }
}
int dfn[N], seq[N], timer, top[N];
void dfs2(int x, int tp){
    top[x]=tp;
    dfn[x]=++timer; seq[timer]=x;
    if(son[x]) dfs2(son[x], tp);
    for(auto y:g[x]) if(y^son[x]) dfs2(y, y);
}
void mdf(int p, int l, int r, int L, int R, int x){
    tr[p].add(x);
    if(L<=l&&r<=R){tag[p].add(x); return ;}
    int mid=(l+r)>>1;
    if(L<=mid) mdf(p<<1, l, mid, L, R, x);
    if(R>mid) mdf(p<<1|1, mid+1, r, L, R, x);
}
void qry(int p, int l, int r, int L, int R){
    tem=tem+tag[p];
    if(L<=l&&r<=R){
        tem=tem+tr[p];
        return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid) qry(p<<1, l, mid, L, R);
    if(R>mid) qry(p<<1|1, mid+1, r, L, R);
}
void upd(int x, int y, int z){
    while(top[x]^top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x, y);
        mdf(1, 1, n, dfn[top[x]], dfn[x], z);
        x=f[top[x]];
    }
    if(x==y) return ;
    if(dfn[x]>dfn[y]) swap(x, y);
    mdf(1, 1, n, dfn[x]+1, dfn[y], z);
}
void solve(int x, int y){
    memset(tem.bs, 0, sizeof tem.bs);
    while(top[x]^top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x, y);
        qry(1, 1, n, dfn[top[x]], dfn[x]);
        x=f[top[x]];
    }
    if(x!=y) {
        if(dfn[x]>dfn[y]) swap(x, y);
        qry(1, 1, n, dfn[x]+1, dfn[y]);
    }
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	read(n); read(m); read(q);
    for(int i=1, x, y, z; i<=m; ++i){
        read(x); read(y); read(z);
        e[x].ep(y, z); e[y].ep(x, z);
    }
    dfs(1, 0);
    dfs2(1, 1);
    for(auto t:e2){
        int x=t.fi.fi, y=t.fi.se, z=t.se;
        z^=w[x]^w[y];
        upd(x, y, z);
    }
    int x, y;
    while(q--){
        read(x); read(y);
        solve(x, y);
        printf("%d\n", tem.work(w[x]^w[y]));
    }
	return 0;
}