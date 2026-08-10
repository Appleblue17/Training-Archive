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
int T, n, m;
vector<int> e[N];
int sz[N], son[N], dep[N], dfn[N], top[N], timer, pos[N], f[N];
void dfs(int x, int fa){
    f[x]=fa;
    sz[x]=1;
    dep[x]=dep[fa]+1;
    for(auto y:e[x]) if(y^fa) {
        dfs(y, x);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]]) son[x]=y;
    }
}
void dfs2(int x, int tp){
    top[x]=tp; dfn[x]=++timer; pos[timer]=x;
    if(son[x]) dfs2(son[x], tp);
    for(auto y:e[x]) if((y^f[x])&&(y^son[x])){
        dfs2(y, y);
    }
}
int a[N];
int tr[N<<2];
void build(int p, int l, int r){
    if(l==r){
        tr[p]=a[pos[l]];
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    tr[p]=tr[p<<1]+tr[p<<1|1];
}
void mdf(int p, int l, int r, int x){
    if(l==r){
        tr[p]^=1;
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) mdf(p<<1, l, mid, x);
    else mdf(p<<1|1, mid+1, r, x);
    tr[p]=tr[p<<1]+tr[p<<1|1];
}
void fnd(int p, int l, int r, int L, int R, int &res){
    if(!tr[p]) return ;
    if(L<=l&&r<=R){
        if(l==r) {
            res=-pos[l];
            return ;
        }
        int mid=(l+r)>>1;
        if(tr[p<<1]) fnd(p<<1, l, mid, L, R, res);
        else fnd(p<<1|1, mid+1, r, L, R, res);
        return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid) fnd(p<<1, l, mid, L, R, res);
    if(R>mid&&res>0) fnd(p<<1|1, mid+1, r, L, R, res);
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	read(n);
    for(int i=1, x, y; i<n; ++i){
        read(x); read(y);
        e[x].ep(y); e[y].ep(x);
    }
    e[n+1].ep(1);
    dfs(n+1, 0);
    dfs2(n+1, n+1);
    for(int i=1; i<=n; ++i) read(a[i]);
    a[n+1]=1;
    build(1, 1, n+1);
    for(int i=1, x; i<=n; ++i){
        read(x);
        if(x!=0){
            a[x]^=1;
            mdf(1, 1, n+1, dfn[x]);
        }
        int ans=0, lim=min(n, 2*(n/i+2));
        x=i;
        while(ans<lim&&x!=n+1){
            ++ans;
            int res=i;
            int w=x, lstx=x;
            while(res&&x!=0){
                if(dep[x]-dep[top[x]]<=res){
                    res-=dep[x]-dep[top[x]];
                    fnd(1, 1, n+1, dfn[top[x]], dfn[x], w);
                    w=abs(w);
                    if(res==0) break;
                    --res;
                    x=f[top[x]];
                    if(a[x]) w=x;
                }
                else{
                    fnd(1, 1, n+1, dfn[x]-res, dfn[x], w);
                    w=abs(w);
                    break;
                }
            }
            x=w;
            if(w==lstx) break;
        }
        if(x!=n+1){
            printf("-1 ");
        }
        else{
            printf("%d ", ans);
        }
    }
	return 0;
}