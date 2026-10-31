#include<bits/stdc++.h>
using namespace std;
typedef __int128 lint;
const lint inf=(lint)1e18*(lint)1e18;
const int N=5e5+5;
typedef long long ll;
int T, n; ll x, y;
ll a[N], b[N];
void write(lint x){
    if(x>=10) {write(x/10);}
    putchar(x%10+'0');
}
ll dif[N], lev[N];
int rk[N];
void solve(){
    scanf("%d%lld%lld", &n, &x, &y);
    lint ans=inf;
    for(int i=1; i<=n; ++i){
        scanf("%lld%lld", &a[i], &b[i]);
        if(b[i-1]-a[i]+a[i-1]>=b[i]){
            --i; --n;
        }
    }
    ll mxb=0;
    ll sumdif=0;
    for(int i=1; i<=n; ++i){
        rk[i]=i;
        dif[i]=a[i]-a[i-1]+b[i]-b[i-1];
        lev[i]=b[i-1]+a[i-1]-a[i];
        // cout<<dif[i]<<' '<<lev[i]<<endl;
        sumdif+=dif[i];
        mxb=max(mxb, b[i]);
    }
    sort(rk+1, rk+n+1, [&](int x, int y){return lev[x]<lev[y];});
    vector<ll> X;
    X.push_back(0);
    for(int i=1; i<=n; ++i){
        X.push_back(b[i]); 
        if(lev[i]>0&&lev[i]<=mxb) X.push_back(lev[i]);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    int pos=0;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    ll sumb=0;
    for(auto cur:X){
        while(pos<n&&lev[rk[pos+1]]<=cur){
            ++pos;
            sumdif-=dif[rk[pos]];
            pq.push(b[rk[pos]]);
            sumb+=b[rk[pos]];
        }
        while(!pq.empty()&&pq.top()<=cur) sumb-=pq.top(), pq.pop();
        lint cost=(lint)x*cur+(lint)y*(sumb-cur*(ll)pq.size()+sumdif);
        ans=min(ans, cost);
    }
    write(ans);
    putchar('\n');
}
signed main(){
    // freopen("H0.in", "r", stdin);
    // freopen("H.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        solve();
    }
}