#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3300,INF=1e18;

int T,n,m,X,Y,Z;
int a[N],b[N];

int dp[N][N];

void gmin(int &x,int y){
    x=min(x,y);
}

signed main(){
    cin>>T;
    while(T--){
        scanf("%lld%lld%lld%lld%lld",&n,&m,&X,&Y,&Z);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
        
        for(int i=1;i<=m+1;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=INF;
            }
        }
        
        dp[1][1]=X;
        for(int t=1;t<=m+1;t++){
            for(int _=1;_<=5;_++){
                for(int i=1;i<n;i++){
                    gmin(dp[t][i+1],dp[t][i]+Z);
                    gmin(dp[t+1][i+1],dp[t][i]+abs(a[i]-b[t])*Y);
                }
                gmin(dp[t][1],dp[t][n]+Z+X);
                gmin(dp[t+1][1],dp[t][n]+abs(a[n]-b[t])*Y+X);
            }
        }
        
        int ans=dp[m+1][1]-X;
        // for(int i=2;i<=n;i++) ans=min(ans,dp[m+1][i]+Z*(n-i+1));
        printf("%lld\n",ans);
    }
}