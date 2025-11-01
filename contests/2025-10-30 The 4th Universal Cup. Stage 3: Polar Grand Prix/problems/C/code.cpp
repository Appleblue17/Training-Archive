#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
typedef long long ll;
int n, m, q;
int id[N];
int pp[N], pv[N]; string ps[N];
string a[N];
int b[N];
ll rp[N], rv[N], lis[N]; int len;
struct sgt{
    int mx[N<<2];
    void clr(int p, int l, int r){
        mx[p]=0;
        if(l==r) return ;
        int mid=(l+r)>>1;
        clr(p<<1, l, mid); clr(p<<1|1, mid+1, r);
    }
    void mdf(int p, int l, int r, int x, int v){
        if(l==r){
            mx[p]=v;
            return ;
        }
        int mid=(l+r)>>1;
        if(x<=mid) mdf(p<<1, l, mid, x, v);
        else mdf(p<<1|1, mid+1, r, x, v);
        mx[p]=max(mx[p<<1], mx[p<<1|1]);
    }
    int get(int p, int l, int r, int L, int R){
        if(L>R) return 0;
        if(L<=l&&r<=R){
            return mx[p];
        }
        int mid=(l+r)>>1, ret=0;
        if(L<=mid) ret=get(p<<1, l, mid, L, R);
        if(R>mid) ret=max(ret, get(p<<1|1, mid+1, r, L, R));
        return ret;
    }
}T1;
struct sgt2{
    ll sum[N<<2], tag1[N<<2], tag2[N<<2];
    void clr(int p, int l, int r){
        sum[p]=0; tag1[p]=1; tag2[p]=0;
        if(l==r) return ;
        int mid=(l+r)>>1;
        clr(p<<1, l, mid); clr(p<<1|1, mid+1, r);
    }
    void apply(int p, ll t1, ll t2){
        sum[p]=sum[p]*t1+t2;
        tag1[p]=tag1[p]*t1;
        tag2[p]=tag2[p]*t1+t2;
    }
    void down(int p){
        if(tag1[p]!=1||tag2[p]!=0){
            apply(p<<1, tag1[p], tag2[p]);
            apply(p<<1|1, tag1[p], tag2[p]);
            tag1[p]=1; tag2[p]=0;
        }
    }
    void add(int p, int l, int r, int L, int R, ll v){
        if(L>R) return ;
        if(L<=l&&r<=R){
            apply(p, 1, v);
            return ;
        }
        int mid=(l+r)>>1;
        down(p);
        if(L<=mid) add(p<<1, l, mid, L, R, v);
        if(R>mid) add(p<<1|1, mid+1, r, L, R, v);
        sum[p]=sum[p<<1]+sum[p<<1|1];
    }
    void rev(int p, int l, int r, int L, int R){
        if(L<=l&&r<=R){
            apply(p, -1, 0);
            return ;
        }
        int mid=(l+r)>>1;
        down(p);
        if(L<=mid) rev(p<<1, l, mid, L, R);
        if(R>mid) rev(p<<1|1, mid+1, r, L, R);
        sum[p]=sum[p<<1]+sum[p<<1|1];
    }
    ll fnd(int p, int l, int r, int x){
        if(l==r) return sum[p];
        int mid=(l+r)>>1;
        down(p);
        if(x<=mid) return fnd(p<<1, l, mid, x);
        return fnd(p<<1|1, mid+1, r, x);
    }
}T2;
ll ans[N];
vector<pair<int, int> > qry[N];
void solve(){
    cin>>m>>n>>q;
    unordered_map<string, int> h;
    for(int i=1; i<=m; ++i){
        cin>>pp[i]>>pv[i]>>ps[i];
        h[ps[i]]=i;
    }
    for(int i=1; i<=n; ++i) {
        cin>>a[i]; b[i]=h[a[i]];
        rv[i]=pv[b[i]];
        rp[i]=1ll*pp[b[i]]*N+n-i;
        lis[i]=rp[i];
    }
    sort(lis+1, lis+n+1);
    len=unique(lis+1, lis+n+1)-lis-1;
    for(int i=1; i<=n; ++i){
        rp[i]=lower_bound(lis+1, lis+len+1, rp[i])-lis;
    }
    T1.clr(1, 1, n);
    T2.clr(1, 1, n);
    for(int i=1, l, r; i<=q; ++i){
        cin>>l>>r;
        qry[r].emplace_back(l, i);
    }
    for(int i=1; i<=n; ++i){
        int x=T1.get(1, 1, n, rp[i], n);
        ll lstv=T2.fnd(1, 1, n, x+1);
        T2.rev(1, 1, n, x+1, i);
        T2.add(1, 1, n, x+1, i, rv[i]);
        ll curv=T2.fnd(1, 1, n, x+1);
        T2.add(1, 1, n, 1, x, curv-lstv);
        T1.mdf(1, 1, n, rp[i], i);
        for(auto t:qry[i]) ans[t.second]=T2.fnd(1, 1, n, t.first);
    }
    for(int i=1; i<=q; ++i){
        printf("%lld\n", ans[i]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
}
