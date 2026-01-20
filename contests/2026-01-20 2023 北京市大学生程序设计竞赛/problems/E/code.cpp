#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int n, m, a[N], b[N];
int dp[N][N];
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1; i<=m; ++i) scanf("%d", &b[i]);
    memset(dp, 0x3f, sizeof dp);
    dp[n][m]=0;
    for(int i=n; i>=0; --i){
        for(int j=m; j>=0; --j){
            if(j) dp[i][j-1]=min(dp[i][j-1], dp[i][j]+1);
            if(i) dp[i-1][j]=min(dp[i-1][j], dp[i][j]+1);
            if(i&&j&&a[i]==b[j]) dp[i-1][j-1]=min(dp[i-1][j-1], dp[i][j]);
            if(i&&j&&a[i]==1) dp[i-1][j-1]=min(dp[i-1][j-1], dp[i][j]);
            if(i&&j&&b[j]==1) dp[i-1][j-1]=min(dp[i-1][j-1], dp[i][j]);
        }
    }
    int ans=1e9;
    for(int i=0; i<=n; ++i) ans=min(ans, dp[i][0]);
    for(int i=0; i<=m; ++i) ans=min(ans, dp[0][i]);
    printf("%d\n", ans);
}
