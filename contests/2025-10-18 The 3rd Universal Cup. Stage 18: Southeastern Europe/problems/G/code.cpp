#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,INF=1e12;
int n,ans;
int a[N];

int f[N],g[N];
map <int,int> mp1,mp2;
int mx;

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),mp1[a[i]]=mp2[a[i]]=-INF;
    
    for(int i=0;i<=n;i++) f[i]=g[i]=-INF;
    
    for(int i=1;i<=n;i++){
        f[i]=max(mx,mp2[a[i]])+1;
        g[i]=max(mp1[a[i]],mp2[a[i]])+1;
        
        mp1[a[i]]=max(mp1[a[i]],max(f[i],g[i]));
        mp2[a[i]]=max(mp2[a[i]],g[i]);
        mx=max(mx,g[i]);
        
        // cout<<f[i]<<" "<<g[i]<<endl;
        ans=max(ans,g[i]);
    }
    cout<<ans;
}
