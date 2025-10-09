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
const int N=1e5+5;
int T, n, m;
int ans[N];
vector<int> e[N];
struct Neighbors{
    bool v[N];
    int get_s(int x, int fa){
        if(v[x]) return 0;
        int ret=1;
        for(auto y:e[x]) if(y!=fa) 
            ret+=get_s(y, x);
        return ret;
    }
    int get_rt(int x, int fa, int siz, int &rt){
        if(v[x]) return 0;
        int sum=1, mx=0;
        for(auto y:e[x]){
            if(y==fa) continue;
            int t=get_rt(y, x, siz, rt);
            mx=max(mx,t); sum+=t;
        }
        mx=max(mx, siz-sum);
        if(mx<=siz/2) rt=x;
        return sum;
    }
    int rt, fa[N];
    void devide(int x){
        v[x]=1;
        for(auto y:e[x]){
            if(v[y]) continue;
            int nrt=-1;
            get_rt(y, -1, get_s(y, -1), nrt); devide(nrt); fa[nrt]=x;
        }
    }
    int dfn, st[20][N<<1], pos[N], lg[N<<1], dep[N];
    void dis_pre(int x, int fa, int cd){
        st[0][++dfn]=x; pos[x]=dfn; dep[x]=cd;
        for(auto y:e[x]){
            if(y==fa) continue;
            dis_pre(y, x, cd+1);
            st[0][++dfn]=x;
        }
    }
    void lca_pre(){
        for(int i=2; i<=dfn; i++) lg[i]=lg[i>>1]+1;
        for(int i=1; i<=lg[dfn]; i++){
            for(int j=1; j+(1<<i)-1<=dfn; j++){
                st[i][j]=dep[st[i-1][j]]<dep[st[i-1][j+(1<<(i-1))]]?
                st[i-1][j]:st[i-1][j+(1<<(i-1))];
            }
        }
    }
    int lca(int x, int y){
        x=pos[x], y=pos[y];
        if(x>y) swap(x, y);
        int t=lg[y-x+1];
        return dep[st[t][x]]<dep[st[t][y-(1<<t)+1]]?
        st[t][x]:st[t][y-(1<<t)+1];
    } 
    int get_dis(int x, int y){
        return dep[x]+dep[y]-2*dep[lca(x, y)];
    }
    vector<int> item[2][N];
    void ins(int x){
        for(int i=x; i; i=fa[i]){
            item[0][i].ep(get_dis(x, i));
            if(fa[i]) {
                item[1][i].ep(get_dis(x, fa[i]));
            }
        }
    }
    int get(int x, int k){
        int ret=0;
        int pre=0;
        for(int i=x; i; pre=i, i=fa[i]){
            int len=k-get_dis(x, i);
            if(len<0) continue;
            ret+=upper_bound(item[0][i].begin(), item[0][i].end(), len)-item[0][i].begin();
            if(pre) ret-=upper_bound(item[1][pre].begin(), item[1][pre].end(), len)-item[1][pre].begin();
        }
        return ret;
    }
    void build(){
        dfn=0;
        for(int i=1; i<=n; ++i) v[i]=0, item[0][i].clear(), item[1][i].clear();
        get_rt(1, -1, n, rt);
        fa[rt]=0;
        devide(rt);
        dis_pre(rt, -1, 1);
        lca_pre();
        for(int i=1; i<=n; ++i) ins(i);
        for(int i=1; i<=n; ++i) sort(item[0][i].begin(), item[0][i].end()), sort(item[1][i].begin(), item[1][i].end());
    }
}D1;
struct Neighbors2{
    struct node{
        int id, k, mul;
    };
    int dfn[N], son[N], seq[N], top[N], len[N], sz[N], f[N], dep[N];
    int timer;
    vector<node> qry[N];
    void dfs(int x, int fa){
        f[x]=fa; sz[x]=1; son[x]=0; dep[x]=dep[fa]+1;
        for(auto y:e[x]) if(y^fa){
            dfs(y, x);
            sz[x]+=sz[y];
            if(sz[y]>sz[son[x]]) son[x]=y;
        }
    }
    void dfs2(int x, int tp){
        top[x]=tp; ++len[tp]; dfn[x]=++timer; seq[timer]=x;
        if(son[x]) dfs2(son[x], tp);
        for(auto y:e[x]) if(y!=f[x]&&y!=son[x]){
            len[y]=0;
            dfs2(y, y);
        }
    }
    void build(){
        for(int i=1; i<=n; ++i) qry[i].clear();
        timer=0;
        dfs(1, 0);
        len[1]=0;
        dfs2(1, 1);
    }
    void ins(int x, node tem){
        while(x){
            qry[x].ep(tem);
            x=f[top[x]];
        }
    }
    int tr[N<<1];
    vector<pii> back;
    void add(int x, int v, bool flag){
        if(flag) back.ep(x, -v);
        ++x;
        for(; x<=n*2; x+=(x&-x)) tr[x]+=v;
    }
    int get(int x){
        int ret=0;
        for(x=min(x+1, n*2); x>0; x-=(x&-x)) ret+=tr[x];
        return ret;
    }
    void solve(){
        //calculated at lca exactly once
        for(int i=1; i<=n; ++i) if(i==top[i]){
            //到链顶，不含重链子树，提前在链顶轻重切换处容斥
            for(int j=0; j<len[i]; ++j){
                int x=seq[dfn[i]+j];
                //i's subtree 
                add(0, 1, 1); 
                //i's father
                add(dep[x]-dep[i]+1, -1, 1);
                if(son[x]){
                    for(int k=dfn[son[x]]+sz[son[x]]; k<dfn[x]+sz[x]; ++k){
                        //i's subtree 
                        add(dep[seq[k]]-dep[x], 1, 1);
                        //i's father
                        add(dep[seq[k]]-dep[i]+1, -1, 1);
                    }
                }
                for(auto t:qry[x]) ans[t.id]+=t.mul*get(t.k);
            }
            for(auto t:back) add(t.fi, t.se, 0);
            back.clear();
            //重链子树，仍需容斥
            for(int j=len[i]-1; j>0; --j){
                int x=seq[dfn[i]+j];
                add(dep[x]-dep[i], 1, 1);
                if(son[x]){
                    for(int k=dfn[son[x]]+sz[son[x]]; k<dfn[x]+sz[x]; ++k){
                        add(dep[seq[k]]-dep[i], 1, 1);
                    }
                }
                for(auto t:qry[f[x]]) ans[t.id]+=t.mul*(get(t.k+dep[x]-dep[i]-1)-get(t.k-1));
            }
            for(auto t:back) add(t.fi, t.se, 0);
            back.clear();
        }
    }
}D2;
int f[N][20], dep[N];
void dfs(int x, int fa){
    f[x][0]=fa; dep[x]=dep[fa]+1;
    for(int i=1; i<20; ++i) f[x][i]=f[f[x][i-1]][i-1];
    for(auto y:e[x]) if(y^fa){
        dfs(y, x);
    }
}
inline int lca(int x, int y){
    if(dep[x]<dep[y]) swap(x, y);
    for(int i=19; i>=0; --i) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return x;
    for(int i=19; i>=0; --i) if(f[x][i]^f[y][i]) x=f[x][i], y=f[y][i];
    return f[x][0];
}
inline int dis(int x, int y){
    return dep[x]+dep[y]-2*dep[lca(x, y)];
}
inline int jump(int x, int d){
    for(int i=19; i>=0; --i) if((d>>i)&1){
        x=f[x][i];
    }
    return x;
}
int qtp[N], qx[N], qy[N];
inline ll path_hash(int x, int y){
    if(x>y) swap(x, y);
    return 1000000000ll*x+y;
}
int px[N], py[N], idx;
vector<int> item[N<<2];
void ins(int p, int l, int r, int L, int R, int x){
    if(L<=l&&r<=R){
        item[p].ep(x);
        return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid) ins(p<<1, l, mid, L, R, x);
    if(R>mid) ins(p<<1|1, mid+1, r, L, R, x);
}
struct tree_info{
    int state, px, py, len;
}info[30];
inline int fnd(int x, int y, int z){
    int u=lca(x, y), v=lca(x, z), w=lca(y, z);
    if(dep[u]<dep[v]) swap(u, v);
    if(dep[u]<dep[w]) swap(u, w);
    return u;
}
inline tree_info operator +(tree_info cur, int t){
    if(cur.state==0){
        cur.state=1;
        cur.px=px[t]; cur.py=py[t];
        cur.len=0;
        return cur;
    }
    int lca1=fnd(cur.px, px[t], py[t]), lca2=fnd(cur.py, px[t], py[t]);
    if(lca1!=lca2){
        if(cur.state==1){
            cur.px=lca1; cur.py=lca2;
            return cur;
        }
        return cur;
    }
    if(cur.state==1){
        int top=fnd(cur.px, cur.py, lca1);
        if(top==lca1){
            cur.px=cur.py=top;
            return cur;
        }
        cur.state=2;
        cur.px=top; cur.py=lca1; cur.len=dis(top, lca1);
        return cur;
    }
    int d1=dis(cur.px, lca1), d2=dis(cur.py, lca1);
    if(cur.len>=d1&&cur.len>=d2){
        return cur;
    }
    if(d1>=d2){
        cur.len=d1; cur.py=lca1;
    }
    else{
        cur.len=d2; cur.px=lca1;
    }
    return cur;
}
void solve(int o, int p, int l, int r){
    for(auto t:item[p]){
        info[o]=info[o]+t;
    }
    if(l==r){
        if(qtp[l]!=3) return ;
        if(info[o].state==0){
            ans[l]=0;
            return ;
        }
        if(dep[info[o].px]<dep[info[o].py]) swap(info[o].px, info[o].py);
        if(info[o].state==1){
            int w=lca(info[o].px, info[o].py);
            ans[l]=D1.get(w, qx[l]);
            D2.ins(info[o].px, (Neighbors2::node){l, qx[l], 1});
            D2.ins(info[o].py, (Neighbors2::node){l, qx[l], 1});
            D2.ins(w, (Neighbors2::node){l, qx[l], -2});
        }
        else {
            if(qx[l]*2<info[o].len){
                ans[l]=0;
                return ;
            }
            if(info[o].len&1){
                int p1=jump(info[o].px, info[o].len/2), p2=f[p1][0];
                ans[l]=D1.get(p2, qx[l]-info[o].len/2-1);
                D2.ins(p1, (Neighbors2::node){l, qx[l]-info[o].len/2-1, 1});
                D2.ins(p2, (Neighbors2::node){l, qx[l]-info[o].len/2-1, -1});
            }
            else{
                ans[l]=D1.get(jump(info[o].px, info[o].len/2), qx[l]-info[o].len/2);
            }
        }
        return ;
    }
    int mid=(l+r)>>1;
    info[o+1]=info[o];
    solve(o+1, p<<1, l, mid);
    info[o+1]=info[o];
    solve(o+1, p<<1|1, mid+1, r);
}
void solve(){
    read(n); read(m);
    for(int i=1; i<=n; ++i) e[i].clear();
    for(int i=1, x, y; i<n; ++i){
        read(x); read(y);
        e[x].ep(y); e[y].ep(x);
    }
    D1.build(); D2.build();
    dfs(1, 0);
    unordered_map<ll, vector<pii> > h;
    idx=0;
    for(int i=1; i<=m*4; ++i) item[i].clear();
    for(int i=1; i<=m; ++i){
        read(qtp[i]);
        if(qtp[i]==3){
            read(qx[i]);
            ans[i]=0;
            continue;
        }
        read(qx[i]); read(qy[i]);
        if(qtp[i]==1){
            ++idx;
            px[idx]=qx[i]; py[idx]=qy[i];
            h[path_hash(qx[i], qy[i])].ep(idx, i);
        }
        else{
            pii tem=h[path_hash(qx[i], qy[i])].back();
            h[path_hash(qx[i], qy[i])].pop_back();
            ins(1, 1, m, tem.se, i, tem.fi);
        }
    }
    for(auto t:h){
        for(auto tt:t.se){
            ins(1, 1, m, tt.se, m, tt.fi);
        }
    }
    info[0].state=0;
    solve(0, 1, 1, m);
    D2.solve();
    for(int i=1; i<=m; ++i) if(qtp[i]==3){
        printf("%d\n", ans[i]);
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

