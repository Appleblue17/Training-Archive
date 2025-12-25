#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5, mod=1e9+7;
int n, m;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
vector<pii> e[N];
int px[N], py[N], pw[N];
ll result=0;
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
vector<int> bin[N];
bool ban[N]; 
int msk[N];
mt19937 rnd(1234);
vector<int> col[N];
namespace VTT{
    int dfn[N], timer, sz[N], dep[N];
    void dfs(int x, int fa){
        dfn[x]=++timer; sz[x]=1; dep[x]=dep[fa]+1;
        for(auto [y, id]:e[x]){
            if(y==fa) continue;
            dfs(y, x); sz[x]+=sz[y];
        }
    }
    int tr[N];
    void add(int x, int v){
        for(; x<=n; x+=(x&-x)) tr[x]+=v;
    }
    int get(int l, int r){
        int ret=0;
        for(; r>0; r-=(r&-r)) ret+=tr[r];
        for(--l; l>0; l-=(l&-l)) ret-=tr[l];
        return ret;
    }
    int deg[N], stk[N], top;
    void check(int id, vector<int> &q){
        vector<int> p;
        for(auto t:q) p.push_back(px[t]), p.push_back(py[t]);
        if(p.empty()) return ;
        sort(p.begin(), p.end(), [&](int x, int y){return dfn[x]<dfn[y];});
        p.erase(unique(p.begin(), p.end()), p.end());
        int rt=p[0];
        for(auto t:p) rt=lca(rt, t);
        stk[top=1]=rt; deg[rt]=0;
        vector<int> tem; tem.push_back(rt);
        for(auto t:p){
            if(t==rt) continue;
            int lc=lca(stk[top], t);
            if(lc!=stk[top]){
                while(dfn[stk[top-1]]>dfn[lc]) ++deg[stk[top-1]], ++deg[stk[top]], --top;
                if(lc!=stk[top-1]) deg[lc]=0, tem.push_back(lc), ++deg[lc], ++deg[stk[top]], stk[top]=lc;
                else ++deg[lc], ++deg[stk[top]], --top;
            }
            deg[t]=0; tem.push_back(t); stk[++top]=t;
        }
        for(int i=1; i<top; ++i) ++deg[stk[i]], ++deg[stk[i+1]];
        int mx=0;
        for(auto t:tem) mx=max(mx, deg[t]);
        if(mx>2){
            for(auto t:q){
                ban[t]=1;
            }
        }
        else{
            for(auto t:q){
				col[t].push_back(id);
            }
        }
    }
}
bool del[N];
int sz[N], mx[N]; ll dis[N];
vector<int> cur;
int cnt[N], H[N], cccc[N], ccc[N];
void dfs(int x, int fa){
    sz[x]=1; cur.push_back(x);
    mx[x]=0;
    for(auto [y, id]:e[x]){
        if(y==fa||del[y]) continue;
        dfs(y, x);
        sz[x]+=sz[y];
        mx[x]=max(mx[x], sz[y]);
    }
}
void dfs2(int x, int fa, int id){
	for(auto c:col[id]) {
		++cnt[c];
	}
	for(auto [y, cid]:e[x]){
		if(y==fa||del[y]) continue;
		dfs2(y, x, cid);
	}
}
void dfs5(int x, int fa, int id){
	for(auto c:col[id]) {
		--cnt[c];
	}
	for(auto [y, cid]:e[x]){
		if(y==fa||del[y]) continue;
		dfs5(y, x, cid);
	}
}
void dfs6(int x, int fa){
	for(auto [y, id]:e[x]){
		if(y==fa||del[y]) continue;
        for(auto c:col[id]) ++ccc[c];
		dfs6(y, x);
	}
}
void dfs7(int x, int fa){
	for(auto [y, id]:e[x]){
		if(y==fa||del[y]) continue;
        for(auto c:col[id]) --ccc[c];
		dfs7(y, x);
	}
}
unordered_map<int, int> sum, sum2;
void dfs3(int x, int fa, int id, int num, int hs){
    if(ban[id]) return ;
	for(auto c:col[id]){
		if(H[c]==0) ++num;
		++H[c];
		if(H[c]==cnt[c]){
			--num;
			if(H[c]!=cccc[c]) hs^=msk[c];
			if(ccc[c]!=cccc[c]) ++num;
		}
	}
	dis[x]=dis[fa]+pw[id];
	if(num==0){
		result+=sum[hs]%mod;
		result+=dis[x]%mod*sum2[hs]%mod;
        result%=mod;
	}
	for(auto [y, cid]:e[x]){
		if(y==fa||del[y]) continue;
		dfs3(y, x, cid, num, hs);
	}
    for(auto c:col[id]){
		--H[c];
	}
}
void dfs4(int x, int fa, int id, int num, int hs){
    if(ban[id]) return ;
	for(auto c:col[id]){
		if(H[c]==0) ++num;
		++H[c];
		if(H[c]==cnt[c]){
			--num;
			if(H[c]!=cccc[c]) hs^=msk[c];
			if(ccc[c]!=cccc[c]) ++num;
		}
	}
	dis[x]=dis[fa]+pw[id];
	if(num==0){
		sum[hs]+=dis[x]%mod;
        sum[hs]%=mod;
		sum2[hs]++;
	}
	for(auto [y, cid]:e[x]){
		if(y==fa||del[y]) continue;
		dfs4(y, x, cid, num, hs);
	}
    for(auto c:col[id]){
		--H[c];
	}
}
void solve(int rt){
    cur.clear();
    dfs(rt, 0);
    if(sz[rt]==1) {
        del[rt]=1;
        return ;
    }
    int cen=rt;
    for(auto t:cur) if(max(mx[t], sz[rt]-sz[t])<max(mx[cen], sz[rt]-sz[cen])) cen=t;
	vector<pii> subtrt;
    for(auto [y, id]:e[cen]){
        if(!del[y]) subtrt.emplace_back(y, id); 
    }
	sum.clear(); sum2.clear();
    dfs6(cen, 0);
	dis[cen]=0; sum2[0]=1;
    for(auto [t, id]:subtrt){
		dfs2(t, cen, id);
        dfs3(t, cen, id, 0, 0);
        dfs4(t, cen, id, 0, 0);
		dfs5(t, cen, id);
    }
    dfs7(cen, 0);
    del[cen]=1;
    for(auto [t, id]:subtrt) solve(t);
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<n; ++i){
        scanf("%d%d%d", &px[i], &py[i], &pw[i]);
        e[px[i]].emplace_back(py[i], i);
        e[py[i]].emplace_back(px[i], i);
    }
    LCA::pre();
    VTT::dfs(1, 0);
    for(int i=1, x, k; i<=m; ++i){
        scanf("%d", &k);
        while(k--){
            scanf("%d", &x);
            bin[i].push_back(x);
        }
		sort(bin[i].begin(), bin[i].end());
		bin[i].erase(unique(bin[i].begin(), bin[i].end()), bin[i].end());
		if(bin[i].size()==1) continue;
        VTT::check(i, bin[i]);
        cccc[i]=bin[i].size();
		msk[i]=rnd();
    }
    solve(1);
    printf("%lld\n", result%mod);
}
