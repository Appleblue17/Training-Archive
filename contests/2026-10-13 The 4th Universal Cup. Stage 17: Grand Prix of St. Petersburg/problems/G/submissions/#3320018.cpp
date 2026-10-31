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
const int N=2e5+5, inf=1e9;
int T, n, m;
char col[N];
vector<int> e[N];
char qc[2];
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
vector<array<int, 4> > fr[N];
bool ban[N];
int sz[N], mxs[N], mxid[N];
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
void dfs2(int x, int fa, int id, int rt, int d){
    sz[x]=1; 
    array<int, 4> a={rt, id, ++mxid[rt], fa};
    fr[x].ep(a);
    for(auto y:e[x]) {
        if(y==fa||ban[y]) continue;
        dfs2(y, x, id, rt, d+1);
        sz[x]+=sz[y];
    }
}
void work(int x, int allsz){
    int rt=x;
    dfs1(x, 0, allsz, rt);
    array<int, 4> a={rt, rt, ++mxid[rt], 0};
    fr[rt].ep(a);
    for(auto y:e[rt]){
        if(!ban[y]) dfs2(y, rt, y, rt, 1);
    }
    ban[rt]=1;
    for(auto y:e[rt]){
        if(!ban[y]) work(y, sz[y]);
    }
}
struct info{
    int mn1, c1, v1, mn2, c2, v2;
    info(int _mn1=inf, int _c1=0, int _v1=0, int _mn2=inf, int _c2=0, int _v2=0){
        mn1=_mn1; c1=_c1; v1=_v1; mn2=_mn2; c2=_c2; v2=_v2;
    }
};
inline info operator +(info x, info y){
    info ret;
    vector<pair<pii, int> > v;
    v.ep(mapa(mapa(x.mn1, x.c1), x.v1));
    v.ep(mapa(mapa(x.mn2, x.c2), x.v2));
    v.ep(mapa(mapa(y.mn1, y.c1), y.v1));
    v.ep(mapa(mapa(y.mn2, y.c2), y.v2));
    sort(v.begin(), v.end());
    ret.mn1=v[0].fi.fi; ret.c1=v[0].fi.se; ret.v1=v[0].se;
    for(int i=1; i<4; ++i){
        if(v[i].fi.se!=ret.c1){
            ret.mn2=v[i].fi.fi; ret.c2=v[i].fi.se; ret.v2=v[i].se;
            return ret;
        }
    }
    return ret;
}
info trg[N*20], trr[N*20]; int ls[N*20], rs[N*20];
int rt[N], idx;
void add(int &p, int l, int r, int id, int d, int c, int v, char tp){
    if(!p){
        p=++idx;
        trr[p]=trr[0]; trg[p]=trg[0]; ls[p]=rs[p]=0;
    }
    if(l==r){
        if(tp=='R') trr[p].mn1=d, trr[p].c1=c, trr[p].v1=v;
        if(tp=='G') trg[p].mn1=d, trg[p].c1=c, trg[p].v1=v;
        return ;
    }
    int mid=(l+r)>>1;
    if(id<=mid) add(ls[p], l, mid, id, d, c, v, tp);
    else add(rs[p], mid+1, r, id, d, c, v, tp);
    trr[p]=trr[ls[p]]+trr[rs[p]];
    trg[p]=trg[ls[p]]+trg[rs[p]];
}
void del(int &p, int l, int r, int id, char tp){
    if(l==r){
        if(tp=='R') trr[p]=trr[0];
        if(tp=='G') trg[p]=trg[0];
        return ;
    }
    int mid=(l+r)>>1;
    if(id<=mid) del(ls[p], l, mid, id, tp);
    else del(rs[p], mid+1, r, id, tp);
    trr[p]=trr[ls[p]]+trr[rs[p]];
    trg[p]=trg[ls[p]]+trg[rs[p]];
}
void solve(){
    read(n); read(m);
    timer=0;
    idx=0;
    for(int i=1; i<=n; ++i) {
        e[i].clear(); 
        fr[i].clear(); 
        mxid[i]=0;
        ban[i]=0; 
        rt[i]=0;
    }
    for(int i=1, x, y; i<n; ++i){
        read(x); read(y);
        e[x].push_back(y); e[y].push_back(x);
    }
    dfs(1, 0);
    pre();
    work(1, n);
    scanf("%s", col+1);
    for(int x=1; x<=n; ++x){
        reverse(fr[x].begin(), fr[x].end());
        // cout<<outid[x]<<endl;
        for(auto [fa, c, id, oid]:fr[x]){
            int d=dis(fa, x);
            if(fa==x) c=0;
            if(col[x]=='R'){
                add(rt[fa], 1, mxid[fa], id, d, c, x, 'R');
            }
            if(col[x]=='G'){
                add(rt[fa], 1, mxid[fa], id, d, c, x, 'G');
            }
        }
    }
    for(int i=1, op, x; i<=m; ++i){
        read(op);
        if(op==1){
            read(x); scanf("%s", qc+1);
            
            for(auto [fa, c, id, oid]:fr[x]){
                int d=dis(fa, x);
                if(fa==x) c=0;
                if(col[x]=='R'){
                    del(rt[fa], 1, mxid[fa], id, 'R');
                }
                if(col[x]=='G'){
                    del(rt[fa], 1, mxid[fa], id, 'G');
                }
                if(qc[1]=='R'){
                    add(rt[fa], 1, mxid[fa], id, d, c, x, 'R');
                }
                if(qc[1]=='G'){
                    add(rt[fa], 1, mxid[fa], id, d, c, x, 'G');
                }
            }
            col[x]=qc[1];
        }
        else{
            read(x);
            info mnr, mng;
            for(auto [fa, c, id, oid]:fr[x]){
                int d=dis(fa, x);
                if(x==fa){
                    mnr=trr[rt[x]];
                    mng=trg[rt[x]];
                }
                else{
                    if(trr[rt[fa]].c1!=c) mnr=mnr+(info){trr[rt[fa]].mn1+d, oid, trr[rt[fa]].v1, inf, 0, 0};
                    else mnr=mnr+(info){trr[rt[fa]].mn2+d, oid, trr[rt[fa]].v2, inf, 0, 0};
                    if(trg[rt[fa]].c1!=c) mng=mng+(info){trg[rt[fa]].mn1+d, oid, trg[rt[fa]].v1, inf, 0, 0};
                    else mng=mng+(info){trg[rt[fa]].mn2+d, oid, trg[rt[fa]].v2, inf, 0, 0};
                }
            }
            int ans=1e9;
            // cout<<mnr.mn1<<' '<<mnr.c1<<' '<<mnr.v1<<' '<<mnr.mn2<<' '<<mnr.c2<<' '<<mnr.v2<<endl;
            // cout<<mng.mn1<<' '<<mng.c1<<' '<<mng.v1<<' '<<mng.mn2<<' '<<mng.c2<<' '<<mng.v2<<endl;
            if(mnr.c1!=mng.c1){
                if(mnr.v1!=0&&mng.v1!=0) ans=min(ans, dis(mnr.v1, mng.v1));
            }
            if(mnr.c2!=mng.c1){
                if(mnr.v2!=0&&mng.v1!=0) ans=min(ans, dis(mnr.v2, mng.v1));
            }
            if(mnr.c1!=mng.c2){
                if(mnr.v1!=0&&mng.v2!=0) ans=min(ans, dis(mnr.v1, mng.v2));
            }
            if(mnr.c2!=mng.c2){
                if(mnr.v2!=0&&mng.v2!=0) ans=min(ans, dis(mnr.v2, mng.v2));
            }
            if(ans==1e9) ans=-1;
            printf("%d\n", ans);
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
