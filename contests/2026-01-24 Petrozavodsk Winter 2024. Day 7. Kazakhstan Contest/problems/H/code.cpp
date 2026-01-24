#pragma GCC optimize(2)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N=4005;
int n;
int a[N], sum[N];
gp_hash_table<int, int> h[N][2];
int cnt;
inline int get(int l, int r){
    r=max(r, 1); l=min(n, l);
    if(l>r) return 0;
    return sum[r]-sum[l-1];
}
int work(int l, int r, int o, int k){
    if(r-l+1<k) return 0;
    if(h[l][o].find(r*n+k)!=h[l][o].end()) return h[l][o][r*n+k];
    int ret; ++cnt;
    if(o==0){
        ret=-1e9;
        ret=max(ret, get(l, l+k-1)+work(l+k, r, o^1, k));
        if(r-l+1>=k+1) ret=max(ret, get(l, l+k)+work(l+k+1, r, o^1, k+1));
    }
    else{
        ret=1e9;
        ret=min(ret, -get(r-k+1, r)+work(l, r-k, o^1, k));
        if(r-l+1>=k+1) ret=min(ret, -get(r-k, r)+work(l, r-k-1, o^1, k+1));
    }
    return h[l][o][r*n+k]=ret;
}
mt19937 rnd(1234);
int main(){
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];
    // n=4000;
    // for(int i=1; i<=n; ++i) a[i]=rnd()%20000-10000;
    for(int i=1; i<=n; ++i) sum[i]=sum[i-1]+a[i];
    cout<<work(1, n, 0, 1)<<endl;
    // cout<<cnt<<endl;
}
