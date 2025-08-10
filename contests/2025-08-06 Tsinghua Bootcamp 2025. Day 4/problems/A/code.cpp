#include<bits/stdc++.h>
using namespace std;
#define int long long  
const int N=1e6+5;
int T, n, m;
int a[N], sum[N];
int tr1[N<<2], tr2[N<<2], tag[N<<2];
void build(int p, int l, int r){
    tag[p]=0;
    if(l==r){
        tr1[p]=tr2[p]=(sum[n]-2*sum[l])/2;
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    tr1[p]=max(tr1[p<<1], tr1[p<<1|1]);
    tr2[p]=min(tr2[p<<1], tr2[p<<1|1]);
}
void down(int p){
    if(tag[p]!=0){
        tr1[p<<1]+=tag[p]; tr2[p<<1]+=tag[p]; tag[p<<1]+=tag[p];
        tr1[p<<1|1]+=tag[p]; tr2[p<<1|1]+=tag[p]; tag[p<<1|1]+=tag[p];
        tag[p]=0;
    }
}
void mdf(int p, int l, int r, int L, int R, int w){
    if(L<=l&&r<=R){
        tr1[p]+=w; tr2[p]+=w; tag[p]+=w;
        return ;
    }
    down(p);
    int mid=(l+r)>>1;
    if(L<=mid) mdf(p<<1, l, mid, L, R, w);
    if(R>mid) mdf(p<<1|1, mid+1, r, L, R, w);
    tr1[p]=max(tr1[p<<1], tr1[p<<1|1]);
    tr2[p]=min(tr2[p<<1], tr2[p<<1|1]);
}
void solve(){
    scanf("%lld%lld", &n, &m);
    a[0]=0;
    for(int i=1; i<=n; ++i){
        scanf("%lld", &a[i]);
        a[0]+=a[i];
    }
    a[0]/=n;
    for(int i=1; i<=n; ++i) a[i]-=a[0];
    for(int i=1; i<=n; ++i) sum[i]=sum[i-1]+a[i];
    build(1, 1, n);
    int x, y, w;
    while(m--){
        scanf("%lld%lld%lld", &x, &y, &w);
        if(x>y) swap(x, y), w=-w;
        mdf(1, 1, n, x, y-1, w);
        printf("%lld\n", max(tr1[1], -tr2[1]));
    }
}
signed main(){
    scanf("%lld", &T);
    while(T--){
        solve();
    }
}