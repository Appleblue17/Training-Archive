#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
typedef long long ll;
int T, n, m;
int col[N];
typedef pair<int, int> pii;
vector<pair<int, int> > e[N];
#define fi first
#define se second
#define mapa make_pair
int dfn[N], timer, dep[N];
ll dis[N];
int dfn2[N*2], timer2, pos[N];
void dfs(int x, int fa){
    dfn[x]=++timer; dep[x]=dep[fa]+1; 
    dfn2[++timer2]=x; pos[x]=timer2;
    for(auto edg:e[x]){
        dis[edg.first]=dis[x]+edg.second;
        dfs(edg.first, x);
        dfn2[++timer2]=x;
    }
}
int lg[N*2], st[20][N*2];
void pre(){
    for(int i=2; i<=timer2; ++i) lg[i]=lg[i>>1]+1;
    for(int i=1; i<=timer2; ++i) st[0][i]=dfn2[i];
    for(int i=1; i<=lg[timer2]; ++i){
        for(int j=1; j+(1<<i)-1<=timer2; ++j){
            st[i][j]=dep[st[i-1][j]]<dep[st[i-1][j+(1<<(i-1))]]?st[i-1][j]:st[i-1][j+(1<<(i-1))];
        }
    }
}
int t;
inline int lca(int x, int y){
    x=pos[x]; y=pos[y];
    if(x>y) x^=y^=x^=y;
    t=lg[y-x+1];
    return dep[st[t][x]]<dep[st[t][y-(1<<t)+1]]?st[t][x]:st[t][y-(1<<t)+1];
}
inline ll D(int x, int y){
    return dis[x]+dis[y]-2ll*dis[lca(x, y)];
}
int qtp[N], qx[N], qc[N], qd[N];
struct node{
    pii r1, r2, p1, p2;
    node(pii _r1=mapa(0, 0), pii _r2=mapa(0, 0), pii _p1=mapa(0, 0), pii _p2=mapa(0, 0)){r1=_r1, r2=_r2, p1=_p1, p2=_p2;}
    inline friend node operator +(node x, node y){
        node ret=x;
        ll nrd=-1, npd=-1; ll temd;
        if(x.r1.fi!=0){
            nrd=D(x.r1.fi, x.r2.fi);
        }
        if(x.p1.fi!=0){
            npd=D(x.p1.fi, x.p2.fi);
        }
        
        if(y.r1.fi!=0){
            if((temd=D(y.r1.fi, y.r2.fi))>npd) {
                npd=temd; ret.p1=y.r1; ret.p2=y.r2;
            }
            if(temd>nrd){
                nrd=temd; ret.r1=y.r1; ret.r2=y.r2;
            }
        }
        if(y.p1.fi!=0){
            if((temd=D(y.p1.fi, y.p2.fi))>npd) {
                npd=temd; ret.p1=y.p1; ret.p2=y.p2;
            }
            if(y.p1.se!=y.p2.se&&temd>nrd){
                nrd=temd; ret.r1=y.p1; ret.r2=y.p2;
            }
        }
        
        if(x.r1.fi!=0&&y.r1.fi!=0){
            if((temd=D(x.r1.fi, y.r1.fi))>npd) {
                npd=temd; ret.p1=x.r1; ret.p2=y.r1;
            }
            if(x.r1.se!=y.r1.se&&temd>nrd){
                nrd=temd; ret.r1=x.r1; ret.r2=y.r1;
            }
        }
        if(x.r1.fi!=0&&y.r2.fi!=0){
            if((temd=D(x.r1.fi, y.r2.fi))>npd) {
                npd=temd; ret.p1=x.r1; ret.p2=y.r2;
            }
            if(x.r1.se!=y.r2.se&&temd>nrd){
                nrd=temd; ret.r1=x.r1; ret.r2=y.r2;
            }
        }
        if(x.r1.fi!=0&&y.p1.fi!=0){
            if((temd=D(x.r1.fi, y.p1.fi))>npd) {
                npd=temd; ret.p1=x.r1; ret.p2=y.p1;
            }
            if(x.r1.se!=y.p1.se&&temd>nrd){
                nrd=temd; ret.r1=x.r1; ret.r2=y.p1;
            }
        }
        if(x.r1.fi!=0&&y.p2.fi!=0){
            if((temd=D(x.r1.fi, y.p2.fi))>npd) {
                npd=temd; ret.p1=x.r1; ret.p2=y.p2;
            }
            if(x.r1.se!=y.p2.se&&temd>nrd){
                nrd=temd; ret.r1=x.r1; ret.r2=y.p2;
            }
        }
        
        if(x.r2.fi!=0&&y.r1.fi!=0){
            if((temd=D(x.r2.fi, y.r1.fi))>npd) {
                npd=temd; ret.p1=x.r2; ret.p2=y.r1;
            }
            if(x.r2.se!=y.r1.se&&temd>nrd){
                nrd=temd; ret.r1=x.r2; ret.r2=y.r1;
            }
        }
        if(x.r2.fi!=0&&y.r2.fi!=0){
            if((temd=D(x.r2.fi, y.r2.fi))>npd) {
                npd=temd; ret.p1=x.r2; ret.p2=y.r2;
            }
            if(x.r2.se!=y.r2.se&&temd>nrd){
                nrd=temd; ret.r1=x.r2; ret.r2=y.r2;
            }
        }
        if(x.r2.fi!=0&&y.p1.fi!=0){
            if((temd=D(x.r2.fi, y.p1.fi))>npd) {
                npd=temd; ret.p1=x.r2; ret.p2=y.p1;
            }
            if(x.r2.se!=y.p1.se&&temd>nrd){
                nrd=temd; ret.r1=x.r2; ret.r2=y.p1;
            }
        }
        if(x.r2.fi!=0&&y.p2.fi!=0){
            if((temd=D(x.r2.fi, y.p2.fi))>npd) {
                npd=temd; ret.p1=x.r2; ret.p2=y.p2;
            }
            if(x.r2.se!=y.p2.se&&temd>nrd){
                nrd=temd; ret.r1=x.r2; ret.r2=y.p2;
            }
        }
        
        if(x.p1.fi!=0&&y.r1.fi!=0){
            if((temd=D(x.p1.fi, y.r1.fi))>npd) {
                npd=temd; ret.p1=x.p1; ret.p2=y.r1;
            }
            if(x.p1.se!=y.r1.se&&temd>nrd){
                nrd=temd; ret.r1=x.p1; ret.r2=y.r1;
            }
        }
        if(x.p1.fi!=0&&y.r2.fi!=0){
            if((temd=D(x.p1.fi, y.r2.fi))>npd) {
                npd=temd; ret.p1=x.p1; ret.p2=y.r2;
            }
            if(x.p1.se!=y.r2.se&&temd>nrd){
                nrd=temd; ret.r1=x.p1; ret.r2=y.r2;
            }
        }
        if(x.p1.fi!=0&&y.p1.fi!=0){
            if((temd=D(x.p1.fi, y.p1.fi))>npd) {
                npd=temd; ret.p1=x.p1; ret.p2=y.p1;
            }
            if(x.p1.se!=y.p1.se&&temd>nrd){
                nrd=temd; ret.r1=x.p1; ret.r2=y.p1;
            }
        }
        if(x.p1.fi!=0&&y.p2.fi!=0){
            if((temd=D(x.p1.fi, y.p2.fi))>npd) {
                npd=temd; ret.p1=x.p1; ret.p2=y.p2;
            }
            if(x.p1.se!=y.p2.se&&temd>nrd){
                nrd=temd; ret.r1=x.p1; ret.r2=y.p2;
            }
        }
        
        if(x.p2.fi!=0&&y.r1.fi!=0){
            if((temd=D(x.p2.fi, y.r1.fi))>npd) {
                npd=temd; ret.p1=x.p2; ret.p2=y.r1;
            }
            if(x.p2.se!=y.r1.se&&temd>nrd){
                nrd=temd; ret.r1=x.p2; ret.r2=y.r1;
            }
        }
        if(x.p2.fi!=0&&y.r2.fi!=0){
            if((temd=D(x.p2.fi, y.r2.fi))>npd) {
                npd=temd; ret.p1=x.p2; ret.p2=y.r2;
            }
            if(x.p2.se!=y.r2.se&&temd>nrd){
                nrd=temd; ret.r1=x.p2; ret.r2=y.r2;
            }
        }
        if(x.p2.fi!=0&&y.p1.fi!=0){
            if((temd=D(x.p2.fi, y.p1.fi))>npd) {
                npd=temd; ret.p1=x.p2; ret.p2=y.p1;
            }
            if(x.p2.se!=y.p1.se&&temd>nrd){
                nrd=temd; ret.r1=x.p2; ret.r2=y.p1;
            }
        }
        if(x.p2.fi!=0&&y.p2.fi!=0){
            if((temd=D(x.p2.fi, y.p2.fi))>npd) {
                npd=temd; ret.p1=x.p2; ret.p2=y.p2;
            }
            if(x.p2.se!=y.p2.se&&temd>nrd){
                nrd=temd; ret.r1=x.p2; ret.r2=y.p2;
            }
        }
        return ret;
    }
}emp;
node tr[N<<2];
void clr(int p, int l, int r){
    tr[p]=emp;
    if(l==r) return ;
    int mid=(l+r)>>1;
    clr(p<<1, l, mid); clr(p<<1|1, mid+1, r);
}
void add(int p, int l, int r, int x, node v){
    if(l==r){
        tr[p]=v;
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) add(p<<1, l, mid, x, v);
    else add(p<<1|1, mid+1, r, x, v);
    tr[p]=tr[p<<1]+tr[p<<1|1];
}
struct DS{
    struct node{
        int p1, p2;
        node(int _p1=0, int _p2=0){p1=_p1, p2=_p2;}
        inline friend node operator +(node x, node y){
            node ret;
            ret.p1=0; ret.p2=0;
            vector<int> vec;
            if(x.p1!=0) vec.push_back(x.p1);
            if(x.p2!=0) vec.push_back(x.p2);
            if(y.p1!=0) vec.push_back(y.p1);
            if(y.p2!=0) vec.push_back(y.p2);
            ll npd=-1; ll temd;
            for(auto u:vec){
                for(auto v:vec){
                    temd=D(u, v);
                    if(temd>npd){
                        npd=temd;
                        ret.p1=u; ret.p2=v; 
                    }
                }
            }
            return ret;
        }
    }emp;
    node tr[N*65]; int ls[N*65], rs[N*65];
    vector<int> dust;
    int idx;
    int rt[N];
    void clr(){
        idx=0;
        for(int i=1; i<=m; ++i) rt[i]=0;
        dust.clear();
    }
    int gen(){
        if(!dust.empty()){
            int x=dust.back();
            dust.pop_back();
            return x;
        }
        return ++idx;
    }
    void del(int &p, int l, int r, int x){
        if(l==r){
            dust.push_back(p);
            p=0;
            return ;
        }
        int mid=(l+r)>>1;
        if(x<=mid) del(ls[p], l, mid, x);
        else del(rs[p], mid+1, r, x);
        tr[p]=tr[ls[p]]+tr[rs[p]];
        if(tr[p].p1==0){
            dust.push_back(p);
            p=0;
        }
    }
    void add(int &p, int l, int r, int x){
        if(!p) p=gen(), ls[p]=0, rs[p]=0;
        if(l==r){
            tr[p]=(node){x, x};
            return ;
        }
        int mid=(l+r)>>1;
        if(x<=mid) add(ls[p], l, mid, x);
        else add(rs[p], mid+1, r, x);
        tr[p]=tr[ls[p]]+tr[rs[p]];
    }
}tree;
void solve(){
    scanf("%d%d", &m, &col[1]);
    n=1;
    for(int i=1; i<=m; ++i){
        scanf("%d", &qtp[i]);
        if(qtp[i]==0){
            ++n;
            scanf("%d%d%d", &qx[i], &qc[i], &qd[i]);
            e[qx[i]].push_back(mapa(n, qd[i]));
            qx[i]=n;
            col[n]=0;
        }
        else{
            scanf("%d%d", &qx[i], &qc[i]);
        }
    }
    timer=0; timer2=0;
    dfs(1, 0);
    pre();
    clr(1, 1, m);
    tree.clr();
    tree.add(tree.rt[col[1]], 1, n, 1);
    add(1, 1, m, col[1], (node){mapa(0, 0), mapa(0, 0), mapa(1, col[1]), mapa(1, col[1])});
    for(int i=1; i<=m; ++i){
        if(col[qx[i]]){
            tree.del(tree.rt[col[qx[i]]], 1, n, qx[i]);
            add(1, 1, m, col[qx[i]], (node){mapa(0, 0), mapa(0, 0), mapa(tree.tr[tree.rt[col[qx[i]]]].p1, col[qx[i]]), mapa(tree.tr[tree.rt[col[qx[i]]]].p2, col[qx[i]])});
        }
        col[qx[i]]=qc[i];
        tree.add(tree.rt[col[qx[i]]], 1, n, qx[i]);
        add(1, 1, m, col[qx[i]], (node){mapa(0, 0), mapa(0, 0), mapa(tree.tr[tree.rt[col[qx[i]]]].p1, col[qx[i]]), mapa(tree.tr[tree.rt[col[qx[i]]]].p2, col[qx[i]])});
        // cout<<tr[1].r1.fi<<' '<<tr[1].r2.fi<<endl;
        if(tr[1].r1.se==tr[1].r2.se) printf("0\n");
        else printf("%lld\n", D(tr[1].r1.fi, tr[1].r2.fi));
    }
    for(int i=1; i<=n; ++i) e[i].clear();
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    scanf("%d", &T); 
    for(int i=1; i<=T; ++i){
        solve();
    }
}
