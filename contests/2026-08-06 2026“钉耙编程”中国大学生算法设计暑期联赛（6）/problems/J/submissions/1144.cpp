#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,INF=1e18;
int T,n,m;
int A[N],sm[N],ans;
vector<int> g[N];

void solve(){
    int x, y; cin>>x>>y;
    long long ans=1ll*x*y+1ll*y*(y-1)/2ll-x;
    int k=(x-1)/2;
    cout<<ans+max(1ll*(k+1)*(x-k), 1ll*(k+2)*(x-k-1))<<endl;
}

signed main(){
    cin>>T;
    while(T--){
        solve();
        
    }
    
    
}