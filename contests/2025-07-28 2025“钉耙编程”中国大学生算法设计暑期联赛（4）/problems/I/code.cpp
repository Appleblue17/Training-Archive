#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1100000,mod=998244353,INF=1e9;
int T,n,m;

int a[N];


void solve(){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            printf("NO\n");
            return;
        }
        ans += a[i]-2;
    }
    if(ans < -2)printf("NO\n");
    else printf("YES\n");
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        solve();
    }
}