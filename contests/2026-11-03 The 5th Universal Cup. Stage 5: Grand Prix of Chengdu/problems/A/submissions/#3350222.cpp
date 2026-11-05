#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
typedef unsigned long long ull;
int T, n;
ll a[N];
ll ans;
ll h[N], h2[N];
ll val[N<<2];
const int SZ = 70000000;
struct Hash_Table {
	ull ky[SZ];
	int val[SZ],ne[SZ],h[SZ],idx;
	int &operator [] (ull u) {
		int c = u % SZ;
		for (int i = h[c]; i;i = ne[i])
			if (ky[i] == u) return val[i];
		return ne[++idx] = h[c], h[c] = idx, ky[idx] = u, val[idx] = 0;
	}
}mp;
void work(int p, int l, int r){
    if(l==r){
        ++ans;
        h[l]=h2[l]=a[l];
        val[p]=a[l];
        return ;
    }
    if(l+1==r){
        ans+=3;
        val[p]=(a[l]+a[r])/2;
        h[l]=val[p]; h[r]=a[r];
        h2[r]=val[p]; h2[l]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    work(p<<1, l, mid); work(p<<1|1, mid+1, r);
    for(int i=mid+1; i<=r; ++i){
        mp[a[i]-h2[i]]++;
    }
    for(int i=l; i<=mid; ++i){
        ans+=mp[h[i]-a[i]];
    }
    for(int i=mid+1; i<=r; ++i){
        mp[a[i]-h2[i]]--;
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
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) a[i]=(ll)i<<20ll;
    ans=0;
    work(1, 1, n);
    printf("%lld\n", ans);
}
signed main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    int T;scanf("%d",&T);while(T--){
        solve();
    }
}