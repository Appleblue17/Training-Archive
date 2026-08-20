#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n, m;
struct info{
    int c[2];
    int lc, rc;
};
info operator +(info x, info y){
    info z;
    z.lc=x.lc; z.rc=y.rc;
    z.c[0]=x.c[0]+y.c[0];
    z.c[1]=x.c[1]+y.c[1];
    z.c[0]+=x.rc^y.lc;
    z.c[1]+=x.rc^y.lc;
    return z;
};
info tr[N<<2];
int tg1[N<<2], tg2[N<<2];
void build(int p, int l, int r){
    tg1[p]=0; tg2[p]=-1;
    if(l==r){
        cin>>tr[p].lc; tr[p].rc=tr[p].lc;
        tr[p].c[0]=tr[p].c[1]=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    tr[p]=tr[p<<1]+tr[p<<1|1];
}
void flp(int p){
    swap(tr[p].c[0], tr[p].c[1]);
    tr[p].lc^=1; tr[p].rc^=1; tg1[p]^=1; if(tg2[p]!=-1) tg2[p]^=1;
}
void cov(int p, int c){
    tg1[p]=0; tg2[p]=c;
    tr[p].c[0]=tr[p].c[1]=0;
    tr[p].lc=tr[p].rc=c;
}
void down(int p){
    if(tg1[p]){
        flp(p<<1); flp(p<<1|1);
        tg1[p]=0;
    }
    if(tg2[p]!=-1){
        cov(p<<1, tg2[p]); cov(p<<1|1, tg2[p]);
        tg2[p]=-1;
    }
}
void mdf_flp(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R){
        flp(p);
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(L<=mid) mdf_flp(p<<1, l, mid, L, R);
    if(R>mid) mdf_flp(p<<1|1, mid+1, r, L, R);
    tr[p]=tr[p<<1]+tr[p<<1|1];
}
void mdf_cov(int p, int l, int r, int L, int R, int c){
    if(L<=l&&r<=R){
        cov(p, c);
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(L<=mid) mdf_cov(p<<1, l, mid, L, R, c);
    if(R>mid) mdf_cov(p<<1|1, mid+1, r, L, R, c);
    tr[p]=tr[p<<1]+tr[p<<1|1];
}
vector<info> vec;
info get(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R){
        return tr[p];
    }
    int mid=(l+r)>>1;
    down(p);
    if(R<=mid) return get(p<<1, l, mid, L, R);
    if(L>mid) return get(p<<1|1, mid+1, r, L, R);
    return get(p<<1, l, mid, L, R)+get(p<<1|1, mid+1, r, L, R);
}
void solve(){
    cin>>n>>m;
    build(1, 1, n);
    int op, l, r, c;
    while(m--){
        cin>>op>>l>>r;
        if(op==1) {
            cin>>c;
            mdf_cov(1, 1, n, l, r, c);
        }
        else if(op==2){
            mdf_flp(1, 1, n, l ,r);
        }
        else{
            cout<<get(1, 1, n, l, r).c[0]<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        solve();
    }
}