#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,a[N],ans;
 
int f[2][2];
 
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
     
    for(int t=0;t<=30;t++){
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            int x=(a[i]>>t & 1);
            int y=__builtin_parity(a[i] & ((1<<t)-1));
            f[x][y]++;
        }
        ans+=(f[0][0]*f[1][0]+f[0][1]*f[1][1])*(1ll<<t);
    }
    cout<<ans;
}
