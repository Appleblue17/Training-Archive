#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,INF=1e18;
int T,n;
int a[N],dp[N][4];
int W[4];

signed main(){
    cin >> T;
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        a[n+1]=0;
        
        for(int i=1;i<=n;i++){
            W[0]=max(a[i-1],a[i+1]);
            W[1]=a[i+1];
            W[2]=a[i-1];
            W[3]=0;
            for(int j=0;j<4;j++) dp[i][j]=INF;
            
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    if(j>=2 && (k & 1)) continue;
                    dp[i][k]=min(dp[i][k],dp[i-1][j]+W[k]);
                }
            }
        }
        
        int ans=INF;
        for(int j=0;j<4;j++) ans=min(ans,dp[n][j]);
        printf("%lld\n",ans);
    }
}