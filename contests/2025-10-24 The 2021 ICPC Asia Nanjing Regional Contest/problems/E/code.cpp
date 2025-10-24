#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=1e5+5;
struct mat{
    int a[4][4];
    mat(){memset(a, 0, sizeof a);}
    bool check(){
        for(int i=0; i<4; ++i){
            for(int j=0; j<4; ++j){
                if(a[i][j]!=(i==j)){
                    return true;
                }
            }
        }
        return false;
    }
}tr[N<<2], tag[N<<2], bs;
inline mat operator *(mat x, mat y){
    mat z;
    for(int k=0; k<4; ++k){
        for(int i=0; i<4; ++i)if(x.a[i][k]){
            for(int j=0; j<4; ++j){
                z.a[i][j]=(1ll*x.a[i][k]*y.a[k][j]+z.a[i][j])%mod;
            }
        }
    }
    return z;
}
inline mat operator +(mat x, mat y){
    mat z;
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            z.a[i][j]=(x.a[i][j]+y.a[i][j])%mod;
        }
    }
    return z;
}
int n, m, q;
void build(int p, int l, int r){
    tag[p]=bs;
    if(l==r){
        scanf("%d", &tr[p].a[0][1]);
        tr[p].a[0][1]=(tr[p].a[0][1]+mod)%mod;
        tr[p].a[0][0]=1ll*tr[p].a[0][1]*tr[p].a[0][1]%mod;
        tr[p].a[0][2]=1;
        tr[p].a[0][3]=1ll*tr[p].a[0][1]*tr[p].a[0][1]%mod;
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    tr[p]=tr[p<<1]+tr[p<<1|1];
}
void apply(int p, mat x){
    tr[p]=tr[p]*x;
    tag[p]=tag[p]*x;
}
void down(int p){
    if(tag[p].check()){
        apply(p<<1, tag[p]);
        apply(p<<1|1, tag[p]);
        tag[p]=bs;
    }
}
mat tem;
void mdf(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R){
        apply(p, tem);
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(L<=mid) mdf(p<<1, l, mid, L, R);
    if(R>mid) mdf(p<<1|1, mid+1, r, L, R);
    tr[p]=tr[p<<1]+tr[p<<1|1];
}
int qry(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R){
        return tr[p].a[0][3];
    }
    int mid=(l+r)>>1;
    down(p);
    int ret=0;
    if(L<=mid) ret=qry(p<<1, l, mid, L, R);
    if(R>mid) ret=(ret+qry(p<<1|1, mid+1, r, L, R))%mod;
    return ret;
}
void fnd(int p, int l, int r, int x){
    if(l==r){
        printf("%d %d %d %d\n", tr[p].a[0][0], tr[p].a[0][1], tr[p].a[0][2], tr[p].a[0][3]);
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(x<=mid) fnd(p<<1, l, mid, x);
    else fnd(p<<1|1, mid+1, r, x);
}
int ml[N], mr[N], mv[N];
int ans[N];
vector<int> add[N], del[N];
int ql[N], qr[N];
int main(){
    scanf("%d%d%d", &n, &m, &q);
    bs.a[0][0]=bs.a[1][1]=bs.a[2][2]=bs.a[3][3]=1;
    build(1, 1, n);
    for(int i=1; i<=m; ++i){
        scanf("%d%d%d", &ml[i], &mr[i], &mv[i]);
        mv[i]=(mv[i]+mod)%mod;
    }
    for(int i=1, x, y; i<=q; ++i){
        scanf("%d%d%d%d", &ql[i], &qr[i], &x, &y);
        add[y].push_back(i);
        if(x) del[x-1].push_back(i);
    }
    for(auto t:add[0]){
        ans[t]=(ans[t]+qry(1, 1, n, ql[t], qr[t]))%mod;
    }
    for(auto t:del[0]){
        ans[t]=(ans[t]+mod-qry(1, 1, n, ql[t], qr[t]))%mod;
    }
    for(int i=1; i<=m; ++i){
        tem=bs;
        tem.a[0][3]=1;
        if(ml[i]>1) mdf(1, 1, n, 1, ml[i]-1);
        if(mr[i]<n) mdf(1, 1, n, mr[i]+1, n);
        tem.a[1][0]=2ll*mv[i]%mod;
        tem.a[2][0]=1ll*mv[i]*mv[i]%mod;
        tem.a[2][1]=mv[i];
        tem.a[1][3]=2ll*mv[i]%mod;
        tem.a[2][3]=1ll*mv[i]*mv[i]%mod;
        mdf(1, 1, n, ml[i], mr[i]);
        for(auto t:add[i]){
            ans[t]=(ans[t]+qry(1, 1, n, ql[t], qr[t]))%mod;
        }
        for(auto t:del[i]){
            ans[t]=(ans[t]+mod-qry(1, 1, n, ql[t], qr[t]))%mod;
        }
    }
    for(int i=1; i<=q; ++i) printf("%d\n", ans[i]);
}
