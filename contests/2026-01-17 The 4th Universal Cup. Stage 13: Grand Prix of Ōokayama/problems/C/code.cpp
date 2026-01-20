#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=55,M=3880,INF=1e9;
int n,X,Y,K,mod;

int C[N][N];

void init(int lim){
    for(int i=0;i<=lim;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
}
void gmod(int &x){
    x%=mod;
}

vector <int> dp[N][N][N];

signed main(){
    cin>>n>>X>>Y>>K>>mod;
    init(N-5);
    for(int t=0;t<=n;t++){
        for(int i=0;i<=t;i++){
            for(int j=0;i+j<=t;j++){
                int k=t-i-j;
                int lim=2*(i*j+j*k+i*k);
                dp[t][i][j].resize(lim+1);
            }
        }
    }
    
    dp[0][0][0][0]=1;
    for(int t=0;t<n;t++){
        for(int i=0;i<=t;i++){
            for(int j=0;i+j<=t;j++){
                int k=t-i-j;
                int lim=2*(i*j+j*k+i*k);
                for(int p=0;p<=lim;p++){
                    int val=dp[t][i][j][p];
                    if(!val) continue;
                    
                    gmod(dp[t+1][i+1][j][p+t-i+j]+=val);
                    gmod(dp[t+1][i][j+1][p+t-j+k]+=val);
                    gmod(dp[t+1][i][j][p+t-k+i]+=val);
                }
            }
        }
    }
    
    int ans=0;
    for(int t=0;t<=n;t++){
        int nK=K-t*(n-t);
        if(nK<0) continue;
        for(int i=0;i<=t && i<=X;i++){
            for(int j=0;i+j<=t && j<=Y;j++){
                int k=t-i-j;
                int lim=2*(i*j+j*k+i*k);
                for(int p=0;p<=lim && p<=nK;p++){
                    if(nK-p<dp[n-t][X-i][Y-j].size()){
                        // cout<<t<<" "<<i<<" "<<j<<" "<<p<<": "<<dp[t][i][j][p]<<" "<<dp[n-t][X-i][Y-j][nK-p]%mod<<endl;
                        gmod(ans+=1ll*dp[t][i][j][p]*dp[n-t][X-i][Y-j][nK-p]%mod*C[n][t]%mod);
                    }
                }
            }
        }
    }
    cout<<ans;
}
