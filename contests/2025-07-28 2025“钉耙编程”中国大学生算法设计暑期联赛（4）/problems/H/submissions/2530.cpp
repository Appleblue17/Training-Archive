#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+5,mod=998244353,INF=1e9;
int T,n;
int a[N];
int x, y, z;
int cnt[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        int n;
        cin>>n>>x>>y>>z;
        for(int i=1; i<=n; ++i) cnt[i]=0;
        for(int i=1; i<=n; ++i){
            cin>>a[i]; ++cnt[a[i]];
        }
        sort(cnt+1, cnt+n+1);
        vector<int> vec;
        int pre=0;
        for(int i=1; i<=n; ++i){
            if(cnt[i]-pre==0) continue;
            for(int j=1; j<=cnt[i]-pre; ++j) vec.push_back(n-i+1);
            pre=cnt[i];
        }
        int ans=n*x+(vec.size()-1)*(z-x);
        while(vec.size()>1){
            if((x-y)*(vec.back()-1)<(y-z)){
                ans-=x*(vec.back()-1)+z;
                ans+=y*vec.back();
                vec.pop_back();
            }
            else{
                break;
            }
        }
        cout<<ans<<endl;
    }
}