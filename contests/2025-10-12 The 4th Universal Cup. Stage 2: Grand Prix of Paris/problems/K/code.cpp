#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5, mod=998244353;
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}
int T, n, m;
int a[N];
int rt[N], idx, ls[N*70], rs[N*70], mul[N*70], inv[N*70], sum[N*70];
void upd(int &p, int q, int l, int r, int x, int invx){
    p=++idx;
    if(q==0) inv[p]=1, mul[p]=1;
    else inv[p]=inv[q], mul[p]=mul[q];
    ls[p]=ls[q]; rs[p]=rs[q];
    sum[p]=sum[q]+x-1;
    mul[p]=mul[p]*x%mod;
    inv[p]=inv[p]*invx%mod;
    if(l==r){
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) upd(ls[p], ls[q], l, mid, x, invx);
    else upd(rs[p], rs[q], mid+1, r, x, invx);
}
#define fi first
#define se second
#define mapa make_pair

int get(int p, int q, int l, int r, int L, int R){
    if(L>R) return 1;
    if(L<=l&&r<=R){
        if(mul[q]==0) return 1;
        if(p==0) return mul[q];
        return inv[p]*mul[q]%mod;
    }
    int mid=(l+r)>>1, ret=1;
    if(L<=mid) ret=get(ls[p], ls[q], l, mid, L, R);
    if(R>mid) ret=ret*get(rs[p], rs[q], mid+1, r, L, R)%mod;
    return ret;
}
pair<int, int> fnd(int p, int q, int l, int r, int lim){
    if(l==r){
        if(l==1) return mapa(1, 0);
        if(lim>=sum[q]-sum[p]){
            return mapa(1, l);
        }
        int cnt=(sum[q]-sum[p])/(l-1);
        int w=lim/(l-1)+1;
        int x=ksm(l, cnt-w)*(l-lim%(l-1))%mod;
        // cout<<cnt<<' '<<w<<' '<<lim<<endl;
        return mapa(x, l);
    }
    int mid=(l+r)>>1;
    if(sum[ls[q]]-sum[ls[p]]>=lim){
        return fnd(ls[p], ls[q], l, mid, lim);
    }
    else{
        return fnd(rs[p], rs[q], mid+1, r, lim-(sum[ls[q]]-sum[ls[p]]));
    }
}
signed main(){
    scanf("%lld%lld", &n, &m);
    for(int i=1; i<=n; ++i){
        scanf("%lld", &a[i]);
        upd(rt[i], rt[i-1], 1, mod-1, a[i], ksm(a[i], mod-2));
        // cout<<mul[rt[i]]<<endl;
    }
    int l, r, k;
    while(m--){
        scanf("%lld%lld%lld", &l, &r, &k);
        pair<int, int> pos=fnd(rt[l-1], rt[r], 1, mod-1, k);
        // cout<<pos.fi<<' '<<pos.se<<endl;
        
        int res=get(rt[l-1], rt[r], 1, mod-1, pos.se+1, mod-1);
        res=pos.fi*res%mod;
        
        printf("%lld\n", res);
    }
}
