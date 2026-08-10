#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=4e5+5, B=500; 
int n;
int a[N], b[N], pos[N], sm[N],sm2[N];
int dp[N][B+1];
signed main(){
    freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    scanf("%lld", &n);
    for(int i=1; i<=n; ++i){
        scanf("%lld", &a[i]);
    }
    int cnt1=0;
    for(int i=1; i<=n; ++i){
        scanf("%lld", &b[i]);
        if(b[i])pos[++cnt1]=i;
        sm[i]=sm[i-1]+b[i];
        sm2[i]=sm2[i-1]+b[i]-(i%9==0?1:0);
    }
    //for(int i=1;i<=n;i++){
    //    printf("sm[%lld]=%lld,pos[%lld]=%lld\n",i,sm[i],i,pos[i]);
    //}
    int ans=0;
    memset(dp,-48,sizeof(dp));
    dp[0][0]=0;
    for(int i=1; i<=n; ++i){
        for(int j=0; j<=B; ++j){//j + i/9
            if(b[i]==0)dp[i][j]=max(dp[i][j],dp[i-1][j]);
            else if(j>0)dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
            if(sm2[i]-j-1 < 0)continue;
            int v = i-pos[sm2[i]-j]+pos[sm2[i]-j-1];
            //printf("i=%lld,j=%lld,v=%lld\n",i,j,v);
            //if(v>=0 && j-sm[i]+sm[v]-(i/9)+(v/9)+1 >=0)dp[i][j] = max(dp[i][j],a[i]+dp[v][j-sm[i]+sm[v]-(i/9)+(v/9)+1]);
            //if(v>=0 && 0<=j-(i/9)+(v/9)+1)dp[i][j] = max(dp[i][j],a[i]+dp[v][j-(i/9)+(v/9)+1]);
            if(v>=0)dp[i][j] = max(dp[i][j],a[i]+dp[v][j-sm2[i]+sm2[v]+1]);
            
            ans = max(ans,dp[i][j]);
            
        }
        //for(int j=0;j<=B;j++){
        //    printf("dp[%lld][%lld]=%lld\n",i,j,dp[i][j]);
        //}
        //printf("dp[%lld][%lld]=%lld\n",i,0,dp[i][0]);
    }
    printf("%lld\n",ans);
}