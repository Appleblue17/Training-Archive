#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=4e6+5;
int T, n;
mt19937_64 rnd(123);
const int mask=mt19937_64(123)();
int shift(int x){
    x^=mask;
    x^=(x<<13);
    x^=(x>>7);
    x^=(x<<17);
    x^=mask;
    return x;
}
int ans;
unordered_map<int, int> h[N], h2[N];
int w[N];
void work(int p, int l, int r){
    h[p].clear();
    if(l==r){
        ++ans;
        h[p][w[1]]=1;
        h2[p][w[1]]=1;
        return ;
    }
    int mid=(l+r)>>1;
    work(p<<1, l, mid); work(p<<1|1, mid+1, r);
    for(auto [msk, cnt]:h[p<<1]){
        if(h2[p<<1|1].find(msk)!=h2[p<<1|1].end())
        ans+=cnt*h2[p<<1|1][msk];
    }
    for(auto [msk, cnt]:h[p<<1]){
        h[p][msk]+=cnt;
        h[p][shift(msk)+w[r-mid]]+=cnt;
    }
    for(auto [msk, cnt]:h2[p<<1|1]){
        h2[p][msk]+=cnt;
        h2[p][shift(msk)+w[mid-l+1]]+=cnt;
    }
}
void solve(){
    scanf("%llu", &n);
    for(int i=1; i<=n; ++i) w[i]=rnd();
    ans=0;
    work(1, 1, n);
    printf("%llu\n", ans);
}
signed main(){
    int T;scanf("%llu",&T);while(T--){
        solve();
    }
}