#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=1e6+5;
int n,m;
long long ans;
int a[N],d[N];


signed main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    
    for(int i=2;i<=m;i++){
        for(int j=0;j<=m;j+=i) d[j]++;
    }
    
    for(int i=1;i<=n;i++){
        int g=0;
        for(int t=1;t<=min(i-1,n-i);t++){
            g=__gcd(g,abs(a[i-t]-a[i+t]));
            ans+=d[g];
        }
    }
    
    for(int i=1;i<n;i++){
        // i, i+1
        int g=0;
        for(int t=0;t<=min(i-1,n-1-i);t++){
            g=__gcd(g,abs(a[i-t]-a[i+1+t]));
            ans+=d[g];
        }
    }
    
    cout<<ans;
}