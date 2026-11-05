#pragma GCC optimize(2)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace std;
const int N=1e6+5;
int T, n;
int a[N];
int ans;
int h[N], h2[N];
int val[N<<2];
void work(int p, int l, int r){
    if(l==r){
        ++ans;
        h[l]=h2[l]=a[l];
        val[p]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    work(p<<1, l, mid); work(p<<1|1, mid+1, r);
__gnu_pbds::gp_hash_table <int, int> mp;
    for(int i=l; i<=mid; ++i){
        mp[h[i]-a[i]]++;
    }
    for(int i=mid+1; i<=r; ++i){
        if(mp.find(a[i]-h2[i])!=mp.end()) ans+=mp[a[i]-h2[i]];
    }
    for(int i=l; i<=mid; ++i){
        h[i]=(h[i]+val[p<<1|1])/2;
    }
    for(int i=mid+1; i<=r; ++i){
        h2[i]=(h2[i]+val[p<<1])/2;
    }
    val[p]=(val[p<<1]+val[p<<1|1])/2;
}
void solve(){
    scanf("%lld", &n);
    for(int i=1; i<=n; ++i) a[i]=i<<20ll;
    ans=0;
    work(1, 1, n);
    printf("%lld\n", ans);
}
signed main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    int T;scanf("%lld",&T);while(T--){
        solve();
    }
}