#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=550,INF=1e18;

int T,n,m,s;
int K[N],c[N],qry[N];

void gmin(int &x,int y){
    x=min(x,y);
}
int dp[N][N][N];

int que[N],h,t;


signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&s);
        for(int i=1;i<=m;i++) scanf("%lld%lld",&K[i],&c[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&qry[i]);
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=m;k++){
                    dp[i][j][k]=INF;
                }
            }
        }
        dp[0][s][0]=0;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                for(int k=0;k<=m;k++){
                    int x=dp[i-1][j][k];
                    if(x>=INF) continue;
                    for(int t=-K[i];t<=K[i];t+=2*K[i]){
                        bool bomb=(j+t<1 || j+t>n);
                        int pos=max(1ll,min(n,j+t));
                        gmin(dp[i][pos][k+bomb],x+c[i]);
                    }
                }
            }
            
            for(int k=0;k<=m;k++){
                for(int t=1;t<=K[i]-1;t++){
                    gmin(dp[i][1][k+1],dp[i-1][t][k]+c[i]);
                }
                for(int t=n-K[i]+2;t<=n;t++){
                    gmin(dp[i][n][k+1],dp[i-1][t][k]+c[i]);
                }
            }
            
            for(int k=0;k<=m;k++){
                h=0,t=1;
                
                int cur=0;
                for(int j=1;j<=n;j++){
                    int L=max(1ll,j-K[i]+1),R=min(n,j+K[i]-1);
                    
                    while(cur<R){
                        cur++;
                        int x=dp[i-1][cur][k];
                        while(h>=t && dp[i-1][que[h]][k]>x) h--;
                        que[++h]=cur;
                    }
                    while(que[t]<L) t++;
                    
                    gmin(dp[i][j][k],dp[i-1][que[t]][k]);
                    // for(int t=L;t<=R;t++){
                    //     gmin(dp[i][j][k],dp[i-1][t][k]);
                    // }
                }
            }
        }
        
        // for(int j=1;j<=n;j++){
        //     for(int k=0;k<=m;k++){
        //         cout<<dp[m][j][k]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int t=1;t<=n;t++){
            int ans=-1;
            for(int k=0;k<=m;k++){
                // cout<<dp[m][t][k]<<" ";
                if(dp[m][t][k]<=qry[t]) ans=max(ans,k);
            }
            // cout<<endl;
            printf("%lld ",ans);
        }
        printf("\n");
    }
    
}