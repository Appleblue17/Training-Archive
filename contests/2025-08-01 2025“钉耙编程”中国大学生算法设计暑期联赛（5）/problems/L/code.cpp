#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,mod=1e9+7;
 
int T,n,k;
int a[N], b[N];
signed main() {
    cin>>T;
    while(T--){
        scanf("%lld", &n);
        for(int i=1; i<=n; ++i){
            scanf("%lld", &a[i]);
        }
        vector<int> vec;
        for(int i=1; i<=n; ++i){
            scanf("%lld", &b[i]);
            vec.push_back(a[i]-b[i]);
        }
        sort(vec.begin(), vec.end());
        int ans=1e18;
        for(int i=1; i<(int)vec.size(); ++i){
            ans=min(ans, vec[i]-vec[i-1]);
        }
        vec.clear();
        for(int i=1; i<=n; ++i){
            vec.push_back(a[i]+b[i]);
        }
        sort(vec.begin(), vec.end());
        for(int i=1; i<(int)vec.size(); ++i){
            ans=min(ans, vec[i]-vec[i-1]);
        }
        printf("%lld\n", ans);
    }
}