#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=440,INF=1e9;
int T,n,m;
int a[N];
 
int dp[N][2];
 
int cal(int x,int y){
    if(x<0 || y<0) return INF;
    return max(0ll,y-x);
}
int solve(int x,int y){
    dp[1][0]=cal(0,x-a[1]);
    dp[1][1]=cal(0,y-a[1]);
    for(int i=2;i<=n;i++){
        dp[i][0]=min(dp[i-1][0]+cal(x-a[i-1],x-a[i]),dp[i-1][1]+cal(y-a[i-1],x-a[i]));
        dp[i][1]=min(dp[i-1][0]+cal(x-a[i-1],y-a[i]),dp[i-1][1]+cal(y-a[i-1],y-a[i]));
    }
    return min(dp[n][0]+cal(x-a[n],0),dp[n][1]+cal(y-a[n],0));
}
 
signed main(){
    cin>>T;
    while(T--){
        scanf("%lld%lld",&n,&m);
        int mx=0,mn=INF;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
        }
         
        int ans=INF;
        for(int i=mn;i<=mx*3;i++){
            for(int j=i;j<=mx*3;j++){
                if(i!=j && m==1) continue;
                ans=min(ans,solve(i,j));
            }
        }
         
        printf("%lld\n",ans);
    }
     
}
