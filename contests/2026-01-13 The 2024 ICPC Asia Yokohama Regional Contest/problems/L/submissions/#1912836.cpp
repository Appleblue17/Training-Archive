#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
int n, d, R;
int a[N], s[N];
int f[N][N], mxg[N][N];
bool check(int k, int l, int r){
    int sum=s[r]-s[l-1];
    int w=(k+1)*R;
    // cout<<k<<' '<<l<<' '<<r<<' '<<sum<<' '<<w<<endl;
    if(sum%d==w%d) return true;
    return false;
}
int dp[N];
signed main(){
    scanf("%lld%lld%lld", &n, &d, &R);
    for(int i=1; i<=n; ++i){
        scanf("%lld", &a[i]);
        s[i]=s[i-1]+a[i];
    }
    for(int len=1; len<=n; ++len){
        for(int l=1, r=len; r<=n; ++l, ++r){
            if(check(0, l, r)) mxg[l][r]=1;
            for(int mid=l; mid+1<=r; ++mid){
                f[l][r]=max(f[l][r], f[l][mid]+f[mid+1][r]);
                f[l][r]=max(f[l][r], f[l][mid]+mxg[mid+1][r]);
                f[l][r]=max(f[l][r], mxg[l][mid]+f[mid+1][r]);
                if(check(mxg[l][mid]+mxg[mid+1][r], l, r)) mxg[l][r]=max(mxg[l][r], mxg[l][mid]+mxg[mid+1][r]);
            }
            for(int i=0; i<=f[l][r]; ++i){
                if(check(i, l, r)) mxg[l][r]=max(mxg[l][r], i+1);
            }
            // cout<<l<<' '<<r<<' '<<f[l][r]<<' '<<mxg[l][r]<<endl;
        }
    }
    memset(dp, -0x3f, sizeof dp);
    dp[0]=0;
    for(int i=1; i<=n; ++i){
        for(int j=i; j>=1; --j){
            if(mxg[j][i]!=0){
                dp[i]=max(dp[i], dp[j-1]+(s[i]-s[j-1]-R*mxg[j][i])/d);
            }
            for(int k=0; k<=f[j][i]; ++k){
                if(check(k, j, i)) dp[i]=max(dp[i], dp[j-1]+(s[i]-s[j-1]-R*(k+1))/d);
            }
        }
        dp[i]=max(dp[i], dp[i-1]);
    }
    printf("%lld\n", dp[n]);
}
