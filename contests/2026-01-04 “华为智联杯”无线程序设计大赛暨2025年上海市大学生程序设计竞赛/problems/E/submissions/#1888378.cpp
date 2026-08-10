#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int inf=1<<30;
int T, n, m;
inline ll lcm(ll x, ll y){
    return x*y/__gcd(x, y);
}
inline ll mylcm(ll x, ll y){
    if(x==-1||y==-1) return -1;
    ll ret=lcm(x, y);
    if(ret>inf) return -1;
    return ret;
}
ll sum[N<<2]; int lp[N<<2], rp[N<<2], g[N<<2], tag[N<<2], c[N<<2];
void up(int p){
    sum[p]=sum[p<<1]+sum[p<<1|1];
    g[p]=__gcd(g[p<<1], g[p<<1|1]);
    c[p]=mylcm(c[p<<1], c[p<<1|1]);
}
void apply(int p, int x){
    tag[p]=x; g[p]=x; c[p]=x; sum[p]=1ll*x*(rp[p]-lp[p]+1);
}
void down(int p){
    if(tag[p]!=0){
        apply(p<<1, tag[p]);
        apply(p<<1|1, tag[p]);
        tag[p]=0;
    }
}
void build(int p, int l, int r){
    lp[p]=l; rp[p]=r; tag[p]=0;
    if(l==r){
        scanf("%d", &g[p]);
        sum[p]=g[p]; c[p]=g[p];
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
    up(p);
}
void mdf(int p, int l, int r, int L, int R, int x){
    if(c[p]!=-1&&__gcd(c[p], x)==c[p]) return ;
    if(c[p]!=-1) x=__gcd(c[p], x);
    if(L<=l&&r<=R){
        if(__gcd(g[p], x)==x){
            apply(p, x);
            return ;
        }
        if(l==r){
            apply(p, __gcd(g[p], x));
            return ;
        }
        down(p);
        int mid=(l+r)>>1;
        mdf(p<<1, l, mid, L, R, x);
        mdf(p<<1|1, mid+1, r, L, R, x);
        up(p);
        return ;
    }
    down(p);
    int mid=(l+r)>>1;
    if(L<=mid) mdf(p<<1, l, mid, L, R, x);
    if(R>mid) mdf(p<<1|1, mid+1, r, L, R, x);
    up(p);
}
void st(int p, int l, int r, int L, int R, int x){
    if(L<=l&&r<=R){
        apply(p, x);
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(L<=mid) st(p<<1, l, mid, L, R, x);
    if(R>mid) st(p<<1|1, mid+1, r, L, R, x);
    up(p);
}
ll get(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R){
        return sum[p];
    }
    int mid=(l+r)>>1; ll ret=0;
    down(p);
    if(L<=mid) ret=get(p<<1, l, mid, L, R);
    if(R>mid) ret+=get(p<<1|1, mid+1, r, L, R);
    return ret;
}
void solve(){
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    int op, l, r, x;
    while(m--){
        scanf("%d%d%d%d", &op, &l, &r, &x);
        if(op==0){
            st(1, 1, n, l, r, x);
        }
        else{
            mdf(1, 1, n, l, r, x);
            printf("%lld\n", get(1, 1, n, l, r));
        }
    }
}
int main(){
    // freopen("E.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
