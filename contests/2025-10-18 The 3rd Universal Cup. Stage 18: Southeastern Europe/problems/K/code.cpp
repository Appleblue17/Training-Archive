#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define int long long
int n, m; 
char s[N];
int tr[N<<2], tag[N<<2];
void apply(int p, int v){
    tr[p]<<=v;
    tag[p]+=v;
}
void down(int p){
    if(tag[p]!=0){
        apply(p<<1, tag[p]);
        apply(p<<1|1, tag[p]);
        tag[p]=0;
    }
}
void up(int p){
    tr[p]=tr[p<<1]+tr[p<<1|1];
}
void build(int p, int l, int r){
    tr[p]=r-l+1; tag[p]=0;
    if(l==r) return ;
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
}
void mul(int p, int l, int r, int L, int R){
    if(L>R) return ;
    if(L<=l&&r<=R){
        apply(p, 1);
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(L<=mid) mul(p<<1, l, mid, L, R);
    if(R>mid) mul(p<<1|1, mid+1, r, L, R);
    up(p);
}
void add(int p, int l, int r, int x, int v){
    if(l==r){
        tr[p]+=v;
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(x<=mid) add(p<<1, l, mid, x, v);
    else add(p<<1|1, mid+1, r, x, v);
    up(p);
}
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
pii fnd(int p, int l, int r, int lim){
    if(l==r){
        return mapa(l, tr[p]);
    }
    int mid=(l+r)>>1;
    down(p);
    if(tr[p<<1]>=lim) {
        return fnd(p<<1, l, mid, lim);
    }
    else {
        pii ret=fnd(p<<1|1, mid+1, r, lim-tr[p<<1]);
        ret.se+=tr[p<<1];
        return ret;
    }
}
pii fnd2(int p, int l, int r, int lim){
    if(l==r){
        return mapa(l, 0);
    }
    int mid=(l+r)>>1;
    down(p);
    if(tr[p<<1]>=lim) {
        return fnd2(p<<1, l, mid, lim);
    }
    else {
        pii ret=fnd2(p<<1|1, mid+1, r, lim-tr[p<<1]);
        ret.se+=tr[p<<1];
        return ret;
    }
}
signed main(){
    scanf("%lld%lld", &n, &m);
    scanf("%s", s+1);
    build(1, 1, n);
    int op, l, r;
    while(m--){
        scanf("%lld%lld", &op, &l);
        if(op==1){
            scanf("%lld", &r);
            pii v1=fnd(1, 1, n, l), v2=fnd2(1, 1, n, r);
            if(v1.fi==v2.fi){
                add(1, 1, n, v1.fi, r-l+1);
            }
            else{
                mul(1, 1, n, v1.fi+1, v2.fi-1);
                add(1, 1, n, v1.fi, v1.se-l+1);
                add(1, 1, n, v2.fi, r-v2.se);
            }
        }
        else{
            putchar(s[fnd(1, 1, n, l).fi]);
            putchar('\n');
        }
    }
}
