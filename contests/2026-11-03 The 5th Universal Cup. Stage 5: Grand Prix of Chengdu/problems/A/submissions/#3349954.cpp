#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=4e6+5;
int T, n;
int a[N];
int ans;
int h[N], h2[N];
int val[N];
void work(int p, int l, int r){
    if(l==r){
        ++ans;
        h[l]=h2[l]=a[l];
        val[p]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    work(p<<1, l, mid); work(p<<1|1, mid+1, r);
    unordered_map<int, int> mp;
    for(int i=l; i<=mid; ++i){
        mp[h[i]-(i<<20ll)]++;
    }
    for(int i=mid+1; i<=r; ++i){
        ans+=mp[(i<<20ll)-h2[i]];
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
    scanf("%llu", &n);
    for(int i=1; i<=n; ++i) a[i]=i<<20ll;
    ans=0;
    work(1, 1, n);
    printf("%llu\n", ans);
}
signed main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    int T;scanf("%llu",&T);while(T--){
        solve();
    }
}