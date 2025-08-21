#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=550,INF=1e9;
int n;
int p[N],q[N],dp[N][N];

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i],q[p[i]]=i;
    
    for(int k=2;k<=n;k++){
        for(int l=1;l+k-1<=n;l++){
            int r=l+k-1;
            dp[l][r]=INF;
            for(int t=l+1;t<=r;t++){
                dp[l][r]=min(dp[l][r],dp[l][t-1]+dp[t][r]+abs(q[l]-q[t]));
            }
            // cout<<l<<" "<<r<<" "<<dp[l][r]<<endl;
        }
    }
    cout<<dp[1][n];
}