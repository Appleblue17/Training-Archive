#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
int T, n;
int a[N];
int p[N], s[N];
void solve(){
    cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
    }
    int cur=0;
    int ans=-1e18;
    for(int i=1; i<=n; ++i){
        cur+=a[i]; ans=max(ans, cur);
        p[i]=max(p[i-1], cur);
    }
    int mn=0;
    s[n+1]=0;
    for(int i=n; i>=1; --i){
        s[i]=s[i+1]+a[i];
        ans=max(ans, p[i-1]+s[i]-mn);
        mn=min(mn, s[i]);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    
    cin>>T;
    while(T--){
        solve();
    }
}