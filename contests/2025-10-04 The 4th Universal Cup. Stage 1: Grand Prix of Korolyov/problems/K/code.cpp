#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
const int inf=2e9+100;
int n, m, d;
int a[N];
int ans[N], ql[N], qr[N];
vector<int> vec[N];
int mx[N<<2], tagadd[N<<2], tagcov[N<<2];
void build(int p, int l, int r){
    mx[p]=inf; tagadd[p]=0; tagcov[p]=-1;
    if(l==r) return ;
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
}
void up(int p){
    mx[p]=min(mx[p<<1], mx[p<<1|1]);
}
void down(int p){
    if(tagcov[p]!=-1){
        mx[p<<1]=tagcov[p];
        mx[p<<1|1]=tagcov[p];
        tagcov[p<<1]=tagcov[p];
        tagadd[p<<1]=0;
        tagcov[p<<1|1]=tagcov[p];
        tagadd[p<<1|1]=0;
        tagcov[p]=-1;
    }
    if(tagadd[p]!=0){
        mx[p<<1]+=tagadd[p];
        mx[p<<1|1]+=tagadd[p];
        tagadd[p<<1]+=tagadd[p];
        tagadd[p<<1|1]+=tagadd[p];
        tagadd[p]=0;
    }
}
void st(int p, int l, int r, int x, int v){
    if(l==r){
        mx[p]=v;
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(x<=mid) st(p<<1, l, mid, x, v);
    else st(p<<1|1, mid+1, r, x, v);
    up(p);
}
void mdfadd(int p, int l, int r, int L, int R, int v){
    if(L>R) return ;
    if(L<=l&&r<=R){
        mx[p]+=v; tagadd[p]+=v;
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(L<=mid) mdfadd(p<<1, l, mid, L, R, v);
    if(R>mid) mdfadd(p<<1|1, mid+1, r, L, R, v);
    up(p);
}
void mdfcov(int p, int l, int r, int L, int R, int v){
    if(L>R) return ;
    if(L<=l&&r<=R){
        mx[p]=v; tagadd[p]=0; tagcov[p]=v;
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(L<=mid) mdfcov(p<<1, l, mid, L, R, v);
    if(R>mid) mdfcov(p<<1|1, mid+1, r, L, R, v);
    up(p);
}
int get(int p, int l, int r, int x){
    if(l==r) return mx[p];
    int mid=(l+r)>>1;
    down(p);
    if(x<=mid) return get(p<<1, l, mid, x);
    return get(p<<1|1, mid+1, r, x);
}
int fnd(int p, int l, int r, int w){
    if(l==r) {
        if(mx[p]<=w) return l;
        return l-1;
    }
    int mid=(l+r)>>1;
    down(p);
    if(mx[p<<1|1]<=w) return fnd(p<<1|1, mid+1, r, w);
    return fnd(p<<1, l, mid, w);
}
inline int calc(int x, int i){
    if(x>=a[i]) return max(a[i]-1, x-a[i]);
    return x;
}
void dfs(int p, int l, int r){
    if(l==r) {
        printf("%d ", mx[p]);
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    dfs(p<<1, l, mid); dfs(p<<1|1, mid+1, r);
}
signed main(){
    // freopen("K.in", "r", stdin);
    // freopen("K1.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &d);
    for(int i=1; i<=n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i=1; i<=m; ++i){
        scanf("%lld%lld", &ql[i], &qr[i]);
        vec[qr[i]].push_back(i);
    }
    build(1, 1, n);
    for(int i=1; i<=n; ++i){
        // cout<<"i="<<i<<endl;
        // cout<<"a[i]="<<a[i]<<endl;
        int p1=fnd(1, 1, n, a[i]-1);
        // cout<<"p1="<<p1<<endl;
        if(p1<i){
            int p2=fnd(1, 1, n, 2*a[i]-1);
            // cout<<"p2="<<p2<<endl;
            if(p2<i){
                mdfcov(1, 1, n, p1+1, p2, a[i]-1);
            }
            mdfadd(1, 1, n, p2+1, i-1, -a[i]);
        }
        st(1, 1, n, i, calc(d, i));
        // dfs(1, 1, n);
        // putchar('\n');
        for(auto t:vec[i]){
            ans[t]=get(1, 1, n, ql[t]);
        }
    }
    for(int i=1; i<=m; ++i) printf("%lld\n", ans[i]);
}
