#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,mod=998244353;

int n,ans;
vector <int> G[N];

int a[N];


signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    int cur = 0;
    for(int i=1;i<=n;i++){
        if(cur < a[i]){
            if(ans==0)ans++;
            ans += (a[i]-cur)+1;
            //printf("ans=%lld,cur=%lld,a[i]=%lld\n",ans,cur,a[i]);
        }
        cur = a[i];
        
    }
    printf("%lld",ans);
}
