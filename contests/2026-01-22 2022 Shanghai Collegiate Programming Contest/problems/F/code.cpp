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
const int B=3000;
ll lstans=0;
int n, m;
int f[N][16];
vector<int> e[N];
int dep[N];
int lca(int x, int y){
    if(dep[x]<dep[y]) swap(x, y);
    for(int i=15; i>=0; --i) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return x;
    for(int i=15; i>=0; --i) if(f[x][i]^f[y][i]) x=f[x][i], y=f[y][i];
    return f[x][0];
}
int lg[N];
int jump(int x, int d){
    while(d){
        x=f[x][lg[d&-d]];
        d^=d&-d;
    }
    return x;
}
void dfs(int x, int fa){
    dep[x]=dep[fa]+1;
    f[x][0]=fa;
    for(int i=1; i<16; ++i) f[x][i]=f[f[x][i-1]][i-1];
    for(auto y:e[x]) if(y^fa){
        dfs(y, x);
    }
}
struct node{
    int u, v, w, c, k;
    node(int _u=0, int _v=0, int _w=0, int _c=0, int _k=0){u=_u; v=_v; w=_w; c=_c; k=_k;}
};
vector<node> mdf, bin;
int checkpath(int u, int v, int w, int rt){
    if(dep[rt]<=dep[w]) {
        if(jump(w, dep[w]-dep[rt])==rt) return dep[u]+dep[v]-dep[w]-dep[f[w][0]];
        else return 0;
    }
    if(dep[rt]<=dep[u]&&jump(u, dep[u]-dep[rt])==rt) return dep[u]-dep[rt]+1;
    if(dep[rt]<=dep[v]&&jump(v, dep[v]-dep[rt])==rt)  return dep[v]-dep[rt]+1;
    return 0;
}
int idx;
ll ff[N*60], g[N*60]; int ls[N*60], rs[N*60];
int rt[N];
void ins(int &p, int c, ll v1, ll v2, int l=1, int r=1000000000){
    int q=++idx;
    ff[q]=ff[p]; g[q]=g[p]; ls[q]=ls[p]; rs[q]=rs[p];
    p=q;
    ff[p]+=v1; g[p]+=v2;
    if(l==r){
        return ;
    }
    int mid=(l+r)>>1;
    if(c<=mid) ins(ls[p], c, v1, v2, l, mid);
    else ins(rs[p], c, v1, v2, mid+1, r);
}
int merge(int p, int q, int l=1, int r=1000000000){
    if(p==0||q==0) return p+q;
    int ret=++idx;
    if(l==r){
        ff[ret]=ff[p]+ff[q];
        g[ret]=g[p]+g[q];
        return ret;
    }
    int mid=(l+r)>>1;
    ls[ret]=merge(ls[p], ls[q], l, mid);
    rs[ret]=merge(rs[p], rs[q], mid+1, r);
    ff[ret]=ff[ls[ret]]+ff[rs[ret]];
    g[ret]=g[ls[ret]]+g[rs[ret]];
    return ret;
}
void get(int p, int lim, int x, int l=1, int r=1000000000){
    if(p==0) return ;
    if(r<=lim) {
        lstans+=ff[p];
        lstans-=g[p]*x;
        return ;
    }
    int mid=(l+r)>>1;
    get(ls[p], lim, x, l, mid);
    if(lim>mid) get(rs[p], lim, x, mid+1, r);
}
vector<pair<int, pair<ll, ll> > > item[N];
void dfss(int x, int fa){
    rt[x]=0;
    for(auto y:e[x]) if(y^fa){
        dfss(y, x);
        rt[x]=merge(rt[x], rt[y]);
    }
    for(auto t:item[x]) ins(rt[x], t.fi, t.se.fi, t.se.se);
}
void rebuild(){
    for(int i=1; i<=idx; ++i) ff[i]=g[i]=0, ls[i]=rs[i]=0;
    idx=0;
    for(auto t:mdf) bin.ep(t);
    mdf.clear();
    for(int i=1; i<=n; ++i) item[i].clear();
    int w;
    for(auto [u, v, w, c, k]:bin){
        item[u].ep(c, mapa((ll)k*(dep[u]+1), k));
        item[v].ep(c, mapa((ll)k*(dep[v]+1), k));
        item[w].ep(c, mapa(-(ll)k*(dep[w]+1), -k));
        item[f[w][0]].ep(c, mapa(-(ll)k*(dep[f[w][0]]+1), -k));
    }
    dfss(1, 0);
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n); read(m);
    for(int i=2; i<N; ++i) lg[i]=lg[i>>1]+1;
    for(int i=1, x, y; i<n; ++i){
        read(x); read(y);
        e[x].ep(y); e[y].ep(x);
    }
    dfs(1, 0);
    int op, u, v, c, k;
    
    while(m--){
        read(op); read(u); 
        u^=lstans;
        if(op==1){
            ++n;
            f[n][0]=u; e[u].ep(n); dep[n]=dep[u]+1;
            for(int i=1; i<16; ++i) f[n][i]=f[f[n][i-1]][i-1];
        }
        else if(op==2){
            read(v); read(c); read(k);
            v^=lstans; c^=lstans; k^=lstans;
            mdf.ep((node){u, v, lca(u, v), c, k});
        }
        else{
            read(c); 
            c^=lstans;
            if(mdf.size()>B) rebuild();
            lstans=0;
            for(auto [x, y, z, cc, k]:mdf) if(cc<=c){
                lstans+=(ll)k*checkpath(x, y, z, u);
            }
            get(rt[u], c, dep[u]);
            printf("%lld\n", lstans);
            lstans&=(1ll<<31)-1;
        }
    }
    return 0;
}
