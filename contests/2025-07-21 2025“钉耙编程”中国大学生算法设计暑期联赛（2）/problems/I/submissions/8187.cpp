#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
int T;
int n, m;
int a[N];
vector<int> e[N];
const int B=350;
// const int B=2;
bool big[N];
int dfn[N], seq[N], son[N], sz[N], f[N], dep[N];
void dfs(int x, int fa){
    son[x]=0; sz[x]=1;
    f[x]=fa; dep[x]=dep[fa]+1;
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y, x);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]]) son[x]=y;
    }
}
vector<int> bin[N], bin2[N];
int top[N], timer;
int rk[N];
void dfs2(int x, int tp){
    dfn[x]=++timer; seq[timer]=x; top[x]=tp;
    if(!bin2[x].empty()) bin[tp].push_back(x);
    if(son[x]) dfs2(son[x], tp);
    for(auto y:e[x]){
        if(y==son[x]||y==f[x]) continue;
        dfs2(y, y);
    }
}
int tr[N<<2];
void build(int p, int l, int r){
    if(l==r){
        tr[p]=a[seq[l]];
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    tr[p]=max(tr[p<<1], tr[p<<1|1]);
}
void mdf(int p, int l, int r, int x){
    if(l==r){
        tr[p]=a[seq[l]];
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) mdf(p<<1, l, mid, x);
    else mdf(p<<1|1, mid+1, r, x);
    tr[p]=max(tr[p<<1], tr[p<<1|1]);
}
int addtag[N];
int get(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R) return tr[p];
    int mid=(l+r)>>1, ret=0;
    if(L<=mid) ret=max(ret, get(p<<1, l, mid, L, R));
    if(R>mid) ret=max(ret, get(p<<1|1, mid+1, r, L, R));
    return ret;
}
int qry(int x, int y){
    int rx, ry;
    int ret=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x, y);
        ret=max(ret, get(1, 1, n, dfn[top[x]], dfn[x]));
        for(auto t:bin[top[x]]){
            if(dfn[t]>dfn[x]) continue;
            int cur=a[t];
            for(auto t2:bin2[t]) cur+=addtag[t2];
            ret=max(ret, cur);
        }
        ret=max(ret, a[top[x]]);
        x=f[top[x]];
    }
    if(dfn[x]>dfn[y]) swap(x, y);
    for(auto t:bin[top[x]]){
        if(dfn[t]<dfn[x]||dfn[t]>dfn[y]) continue;
        int cur=a[t];
        for(auto t2:bin2[t]) cur+=addtag[t2];
        ret=max(ret, cur);
    }
    if(top[x]==x) ret=max(ret, a[x]);
    return max(ret, get(1, 1, n, dfn[x], dfn[y]));
}
void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]), e[i].clear();
    for(int i=1, x, y; i<n; ++i){
        scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    for(int i=1; i<=n; ++i) big[i]=e[i].size()>=B, bin[i].clear(), bin2[i].clear();
    vector<int> bignode;
    for(int i=1; i<=n; ++i) if(big[i]==1) bignode.push_back(i);
    for(int i=0; i<(int)bignode.size(); ++i){
        addtag[i]=0; rk[bignode[i]]=i;
        for(auto y:e[bignode[i]]) bin2[y].push_back(bignode[i]);
    }
    dfs(1, 0);
    timer=0;
    dfs2(1, 1);
    build(1, 1, n);
    while(m--){
        int tp; scanf("%d", &tp);
        if(tp==1){
            int x, y; scanf("%d%d", &x, &y);
            int ans=qry(x, y);
            printf("%d\n", ans);
        }
        else{
            int x, z; scanf("%d%d", &x, &z);
            if(big[x]){
                addtag[x]+=z;
            }
            else{
                for(auto y:e[x]) {
                    a[y]+=z; 
                    if(y==f[x]||y==son[x]) mdf(1, 1, n, dfn[y]);
                }
            }
        }
    }
}
int main(){
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        solve();
    }
}