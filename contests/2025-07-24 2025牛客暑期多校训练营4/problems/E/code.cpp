#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+6, mod=998244353;
const int inv2=(mod+1)/2;
int n, m;
int tr[N<<2];
int a[N];
vector<int> tem;
int dfn[N], top[N], seq[N], timer;
int qry(int p, int l, int r, int L, int R){
    if(tr[p]==1){
        return R+1;
    }
    if(L<=l&&r<=R){
        if(l==r){
            tem.push_back(seq[l]);
            return l;
        }
        int mid=(l+r)>>1;
        if(tr[p<<1]>1) return qry(p<<1, l, mid, L, R);
        return qry(p<<1|1, mid+1, r, L, R);
    }
    int mid=(l+r)>>1, ret=R+1;
    if(L<=mid) ret=qry(p<<1, l, mid, L, R);
    if(R>mid&&ret==R+1) ret=qry(p<<1|1, mid+1, r, L, R);
    return ret;
}
int qry2(int p, int l, int r, int L, int R){
    if(tr[p]==1){
        return L-1;
    }
    if(L<=l&&r<=R){
        if(l==r){
            tem.push_back(seq[l]);
            return l;
        }
        int mid=(l+r)>>1;
        if(tr[p<<1|1]>1) return qry2(p<<1|1, mid+1, r, L, R);
        return qry2(p<<1, l, mid, L, R);
    }
    int mid=(l+r)>>1, ret=L-1;
    if(R>mid) ret=qry2(p<<1|1, mid+1, r, L, R);
    if(L<=mid&&ret==L-1) ret=qry2(p<<1, l, mid, L, R);
    return ret;
}
void fnd2(int l, int r){
    int cr=r;
    while(tem.size()<25&&l<=cr){
        cr=qry2(1, 1, n, l, cr)-1;
    }
}
void fnd(int l, int r){
    int cl=l;
    while(tem.size()<25&&cl<=r){
        cl=qry(1, 1, n, cl, r)+1;
    }
}
vector<int> e[N];
int f[N], sz[N], son[N], dep[N];
void dfs(int x, int fa){
    f[x]=fa;
    dep[x]=dep[fa]+1;
    sz[x]=1;
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y, x);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]]) son[x]=y;
    }
}
void dfs2(int x, int tp){
    top[x]=tp;
    dfn[x]=++timer; seq[timer]=x;
    if(son[x]) dfs2(son[x], tp);
    for(auto y:e[x]){
        if(y==f[x]||y==son[x]) continue;
        dfs2(y, y);
    }
}
  
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
int lca(int x, int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x, y);
        x=f[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}
ll dp;
int dis(int x, int y){
    return dep[x]+dep[y]-2*dep[lca(x, y)]-1;
}
int main() {
    // freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
    // freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1, x, y; i<n; ++i){
        scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    dfs(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    while(m--){
        int tp, l, r; scanf("%d%d%d", &tp, &l, &r);
        if(tp==1){
            if(l==r){
                printf("%d\n", (a[l]==24));
                continue;
            }
            if(a[l]>24){
                printf("0\n");
                continue;
            }
            dp=1<<(a[l]-1);
            tem.clear();
            int lst=l; int mr=r;
            int w=lca(l, r);
            if(l!=w){
                l=f[l];
                while(top[l]!=top[w]){
                    fnd2(dfn[top[l]], dfn[l]);
                    l=f[top[l]];
                }
                fnd2(dfn[w], dfn[l]);
            }
            vector<pair<int, int> > vec;
            while(top[r]!=top[w]){
                vec.push_back(make_pair(dfn[top[r]], dfn[r]));
                r=f[top[r]];
            }
            if(w!=r) fnd(dfn[w]+1, dfn[r]);
            reverse(vec.begin(), vec.end());
            for(auto t:vec) fnd(t.first, t.second);
            if(tem.size()>24){
                printf("0\n");
                continue;
            }
            if(tem.empty()||tem.back()!=mr) tem.push_back(mr); 
            bool flag=0;
            for(auto t:tem){
                if(a[t]>24) flag=1;
            }
            if(flag){
                printf("0\n");
                continue;
            }
            for(auto t:tem){
                int d=dis(lst, t);
                ll ndp=dp;
                for(int j=1; j<=24&&j<=d; ++j) ndp|=(dp<<j), ndp&=(1<<24)-1;
                dp=ndp;
                ndp=(dp<<a[t])&((1<<24)-1);
                int cur=1;
                while(dp){
                    if(cur*a[t]>24) break;
                    if(dp&1) ndp|=1<<(cur*a[t]-1);
                    dp>>=1; ++cur;
                }
                dp=ndp;
                lst=t;
            }
            // cout<<endl;
            printf("%d\n", (dp>>23)&1);
        }
        else{
            a[l]=r;
            mdf(1, 1, n, dfn[l]);
        }
    }
}
