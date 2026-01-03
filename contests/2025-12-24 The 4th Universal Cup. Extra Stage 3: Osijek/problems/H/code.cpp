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
typedef unsigned int uint;
#define ep emplace_back
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=1e6+5, mod=1e9+7;
int T, n, m;
vector<pii> e[N];
namespace LCA{
	int dep[N], sz[N], son[N], ft[N], top[N];
	void dfs(int x, int fa){
		dep[x]=dep[fa]+1; ft[x]=fa; sz[x]=1;
		for(auto [y, id]:e[x]){
			if(y==fa) continue;
			dfs(y, x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]]) son[x]=y;
		}
	}
	void dfs2(int x, int tp){
		top[x]=tp;
		if(son[x]){
			dfs2(son[x], tp);
		}
		for(auto [y, id]:e[x]){
			if(y==ft[x]||y==son[x]) continue;
			dfs2(y, y);
		}
	}
	int lca(int x, int y){
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]]) swap(x, y);
			x=ft[top[x]];
		}
		return dep[x]<dep[y]?x:y;
	}
	void pre(){
		dfs(1, 0); dfs2(1, 1);
	}
}
using LCA::lca;
int ex[N], ey[N], ew[N];
mt19937_64 rnd(1234);
ll ans=0;
int dis[N];
ull msk[N];
void dfs(int x, int fa){
    for(auto [y, id]:e[x]) if(y!=fa){
        dis[y]=dis[x]+ew[id];
        dis[y]%=mod;
        msk[y]^=msk[x];
        dfs(y, x);
    }
}
int perm[N];
namespace VTT{
    int dfn[N], timer, sz[N], dep[N];
    void dfs(int x, int fa){
        dfn[x]=++timer; sz[x]=1; dep[x]=dep[fa]+1;
        for(auto [y, id]:e[x]){
            if(y==fa) continue;
            dfs(y, x); sz[x]+=sz[y];
        }
    }
    int stk[N], top;
    vector<int> g[N];
    int sum[N], val[N];
    int all;
    int cd[N];
    void dfs(int x){
        sum[x]=val[x];
        for(auto y:g[x]){
            dfs(y);
            sum[x]+=sum[y];
            ans+=1ll*sum[y]*(all-sum[y])%mod*(dis[y]+mod-dis[x]);
            ans%=mod;
        }
    }
    void solve(int l, int r){
        if(l==r) return ;
        sort(perm+l, perm+r+1, [&](int x, int y){return dfn[x]<dfn[y];});
        all=r-l+1;
        int rt=1;
        stk[top=1]=rt; 
        g[rt].clear();
        for(int i=l, t=perm[i]; i<=r; ++i, t=perm[i]){
            val[t]=1;
            if(t==rt) continue;
            int lc=lca(stk[top], t);
            if(lc!=stk[top]){
                while(dfn[stk[top-1]]>dfn[lc]) g[stk[top-1]].ep(stk[top]), --top;
                if(lc!=stk[top-1]) g[lc].clear(), g[lc].ep(stk[top]), stk[top]=lc;
                else g[lc].ep(stk[top]), --top;
            }
            g[t].clear(); stk[++top]=t;
        }
        for(int i=1; i<top; ++i) g[stk[i]].ep(stk[i+1]);
        dfs(1);
        for(int i=l; i<=r; ++i) val[perm[i]]=0;
    }
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test2.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n); read(m);
	for(int i=1; i<n; ++i){
        read(ex[i]); read(ey[i]); read(ew[i]);
        e[ex[i]].ep(ey[i], i);
        e[ey[i]].ep(ex[i], i);
    }
    LCA::pre();
    for(int i=1, k, x; i<=m; ++i){
        read(k);
        if(k==0) continue;
        if(k==1){
            read(x);
            continue;
        }
        ull sum=0;
        for(int j=1; j<k; ++j){
            read(x); ull tem=rnd();
            if(LCA::dep[ex[x]]>LCA::dep[ey[x]]) msk[ex[x]]^=tem;
            else msk[ey[x]]^=tem;
            sum^=tem;
        }
        read(x); 
        if(LCA::dep[ex[x]]>LCA::dep[ey[x]]) msk[ex[x]]^=sum;
        else msk[ey[x]]^=sum;
    }
    dfs(1, 0);
    for(int i=1; i<=n; ++i) perm[i]=i;
    sort(perm+1, perm+n+1, [&](int x, int y){return msk[x]<msk[y];});
    VTT::dfs(1, 0);
    for(int l=1, r=1; l<=n; l=r+1){
        r=l;
        while(r+1<=n&&msk[perm[r+1]]==msk[perm[l]]) ++r;
        VTT::solve(l, r);
    }
    cout<<ans%mod;
    return 0;
}

