#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=300+5;
int n,h,x[N],f[N][N],dp[N];

void solve(){
    scanf("%lld%lld",&n,&h);
    for(int i=1;i<=n;i++){
        scanf("%lld",&x[i]);
    }
    memset(f,48,sizeof(f));
    memset(dp,48,sizeof(dp));
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int len=2;len<=n;len++){
        for(int l=1,r=l+len-1;r<=n;l++,r=l+len-1){
            //printf("len=%lld,l=%lld,r=%lld\n",len,l,r);
            for(int k=l;k+1<=r;k++){
                if((x[r]-x[l]+1)/2 > h)continue;
                f[l][r] = min(f[l][r],f[l][k]+f[k+1][r]+(x[r]-x[l]+1)/2*2-1-(x[k]-x[l]+1)/2-(x[r]-x[k+1]+1)/2);
                //printf("f[%lld][%lld]=%lld\n",l,r,f[l][r]);
            }
        }
    }
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i] = min(dp[i],dp[j]+f[j+1][i]+h-(x[i]-x[j+1]+1)/2);
        }
    }
    printf("%lld\n",dp[n]);
}

signed main(){
    //int T;
    //scanf("%d",&T);
    //while(T--)
    solve();
    
}
