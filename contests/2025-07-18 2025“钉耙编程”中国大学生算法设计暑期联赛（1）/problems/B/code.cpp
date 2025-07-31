#include<bits/stdc++.h>
using namespace std;
const int N=2e5+6;
typedef long long ll;
int T, n, m;
struct info{
    ll A, B;
};
inline info operator +(info x, info y){
    info z;
    if(x.B>=y.A){
        z.A=x.A; z.B=y.B+x.B-y.A;
    }
    else{
        z.B=y.B; z.A=x.A+y.A-x.B;
    }
    return z;
}
info tr[N*200]; int ls[N*200], rs[N*200]; ll suma[N*200], sumb[N*200];
int rt[N], idx;
int a[N], b[N];
inline int gen(){
    ++idx;
    tr[idx]=(info){0, 0};
    ls[idx]=0; rs[idx]=0;
    return idx;
}
void build(int &p, int l, int r){
    p=gen();
    if(l==r){
        suma[p]=a[l];
        sumb[p]=b[l];
        if(suma[p]>=sumb[p]) tr[p]=(info){0, suma[p]-sumb[p]};
        else tr[p]=(info){sumb[p]-suma[p], 0};
        return ;
    }
    int mid=(l+r)>>1;
    build(ls[p], l, mid); build(rs[p], mid+1, r);
    tr[p]=tr[ls[p]]+tr[rs[p]];
    suma[p]=suma[ls[p]]+suma[rs[p]];
}
void mdf(int &p, int q, int l, int r, int x, int a, int b){
    p=gen();
    tr[p]=tr[q]; suma[p]=suma[q]; sumb[p]=sumb[q];
    ls[p]=ls[q]; rs[p]=rs[q];
    if(l==r){
        if(a==-1) sumb[p]=b;
        else suma[p]=a;
        if(suma[p]>=sumb[p]) tr[p]=(info){0, suma[p]-sumb[p]};
        else tr[p]=(info){sumb[p]-suma[p], 0};
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) mdf(ls[p], ls[q], l, mid, x, a, b);
    else mdf(rs[p], rs[q], mid+1, r, x, a, b);
    tr[p]=tr[ls[p]]+tr[rs[p]];
    suma[p]=suma[ls[p]]+suma[rs[p]];
}
int seq[N];
info tem;
void qry(int p, int l, int r, int L, int R){
    if(L>R) return ;
    if(L<=l&&r<=R){
        tem=tem+tr[p];
        return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid) qry(ls[p], l, mid, L, R);
    if(R>mid) qry(rs[p], mid+1, r, L, R);
}
int geta(int p, int l, int r, int x){
    if(l==r) return suma[p];
    int mid=(l+r)>>1;
    if(x<=mid) return geta(ls[p], l, mid, x);
    return geta(rs[p], mid+1, r, x);
}
void solve(){
    scanf("%d%d", &n, &m);
    idx=1;
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1; i<=n; ++i) scanf("%d", &b[i]);
    build(rt[0], 1, n);
    for(int i=1; i<=m; ++i){
        int tp;
        scanf("%d", &tp);
        if(tp==1){
            int x, v; scanf("%d%d", &x, &v);
            mdf(rt[i], rt[i-1], 1, n, x, v, -1);
        }
        else if(tp==2){
            int x, v; scanf("%d%d", &x, &v);
            mdf(rt[i], rt[i-1], 1, n, x, -1, v);
        }
        else if(tp==3){
            int x; scanf("%d", &x);
            rt[i]=rt[x];
        }
        else{
            rt[i]=rt[i-1];
            int k; scanf("%d", &k);
            seq[0]=0;
            for(int w=1; w<=k; ++w) scanf("%d", &seq[w]);
            ll x=0;
            for(int w=1; w<=k; ++w){
                tem=(info){0, 0};
                qry(rt[i], 1, n, seq[w-1]+1, seq[w]-1);
                if(x<=tem.A) x=tem.B;
                else x=tem.B+x-tem.A;
                x+=geta(rt[i], 1, n, seq[w]);
                x=x/2;
            }
            tem=(info){0, 0};
            qry(rt[i], 1, n, seq[k]+1, n);
            if(x<=tem.A) x=tem.B;
            else x=tem.B+x-tem.A;
            // printf("%lld %lld\n", sum[i], x);
            printf("%lld\n", suma[rt[i]]-x);
        }
    }
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}