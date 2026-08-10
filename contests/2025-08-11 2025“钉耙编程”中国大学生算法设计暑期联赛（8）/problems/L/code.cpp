#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=3300,mod=998244353;
int T_,n;
int a[N];
int mn[N][N];
int dp[N][N];

void gmod(int &x){
    x%=mod;
}

int main(){
    scanf("%d",&T_);
    while(T_--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        
        for(int i=1;i<=n;i++){
            mn[i][i]=a[i];
            for(int j=i+1;j<=n;j++){
                mn[i][j]=min(mn[i][j-1],a[j]);
                mn[j][i]=mn[i][j];
            }
        }
        
        for(int i=1;i<=n;i++)
            for(int j=0;j<=n;j++) dp[i][j]=0;
        
        dp[1][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++){
                // cout<<dp[i][j]<<" ";
                if(!dp[i][j]) continue;
                gmod(dp[i+1][j]+=dp[i][j]);
                if(mn[i][j+1]==a[i]) gmod(dp[i][j+1]+=dp[i][j]);
            }
            // cout<<endl;
        }
        
        printf("%d\n",dp[n][n]);
    }
}