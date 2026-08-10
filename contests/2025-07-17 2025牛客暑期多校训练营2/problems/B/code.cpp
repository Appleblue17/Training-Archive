#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,mod=998244353;
int T,n;
int a[N];
 
 
bool vis[66];
int cal(int x){
    return 63-__builtin_clzll(x);
}
 
bool solve(){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        int x=a[i];
        for(int t=0;t<=60;t++){
            if((x>>t & 1ll) && vis[t]) return 0;
        }
        vis[cal(x)]=1;
    }
    return 1;
}
 
signed main(){
    cin>>T;
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
         
        if(solve()) puts("YES");
        else puts("NO");
    }
}
