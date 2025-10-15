#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int T, n, d;
int a[N];
#define fi first
#define se second
vector<pair<int, int> > vec[N]; 
pair<int, int> que[N]; int hh, tt;
inline bool check(int lim){
    for(int i=1; i<=n; ++i) {
        vec[i].clear();
    }
    for(int i=1; i<=n; ++i) {
        vec[max(1ll, i-d*lim)].push_back(make_pair(i+d*lim, a[i]));
    }
    hh=1; tt=0;
    for(int i=1; i<=n; ++i){
        for(auto t:vec[i]) que[++tt]=t;
        while(hh<=tt){
            if(que[hh].fi<i) ++hh;
            else break;
        }
        int dt=a[0];
        while(hh<=tt){
            if(que[hh].se>dt){
                que[hh].se-=dt;
                dt=0;
                break;
            }
            else{
                dt-=que[hh].se;
                ++hh;
            }
        }
        if(dt) return false;
    }
    return true;
}
void solve(){
    scanf("%lld%lld",&n, &d);
    a[0]=0;
    for(int i=1; i<=n; ++i) scanf("%lld", &a[i]), a[0]+=a[i];
    a[0]/=n;
    int L=0, R=n, mid, ret=n+1;
    while(L<=R){
        mid=(L+R)>>1;
        if(check(mid)){
            ret=mid; R=mid-1;
        }
        else{
            L=mid+1;
        }
    }
    printf("%lld\n", ret);
}

signed main(){
    scanf("%lld",&T);
    while(T--){
        solve();
    }
}
