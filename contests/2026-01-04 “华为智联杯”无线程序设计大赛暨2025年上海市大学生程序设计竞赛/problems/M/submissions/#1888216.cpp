#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5,INF=1e18;
int n,x,y;
int a[N];
__int128 f[33];

int cal(int n,int k){
    return (n>>k)+__builtin_popcount(n & ((1<<k)-1));
}

signed main(){
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        for(int t=0;t<=30;t++) f[t]+=cal(a[i],t)*x;
    }
    
    __int128 ans=INF;
    for(int t=0;t<=30;t++) ans=min(ans,f[t]+t*y);
    cout<<(long long)ans;
}
