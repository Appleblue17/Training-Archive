#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,mod=998244353;

int T,n,m,k;
map < pair<int,int>, int> mp;

signed main(){
    cin>>T;
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&k);
        int ans=0;
        mp.clear();
        for(int i=1;i<=m;i++){
            int x,y; scanf("%lld%lld",&x,&y);
            if(x>y) swap(x,y);
            ans=(ans+mp[{x,y}])%mod;
            mp[{x,y}]++;
        }
        
        if(k>2) printf("0\n");
        else printf("%lld\n",ans);
    }
    
    
}