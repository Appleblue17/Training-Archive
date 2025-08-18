#include <bits/stdc++.h>
using namespace std;
const int N=550;
int T,n,mod;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1;
    }
    return tot;
}
void gmodn(int &x){
    x+=x>>31 & mod;
}
void gmod(int &x){
    x%=mod;
}

int C[N][N],mul[N];
void init(int lim){
    for(int i=0;i<=lim;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    
    mul[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
}

int dp[N][N][N][2];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>mod;
        init(n);
        
        dp[0][0][0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i;j++)
                for(int k=0;k<=j;k++)
                    for(int f=0;f<=1;f++)
                        dp[i][j][k][f]=0;
            for(int j=0;j<=i;j++){
                for(int k=0;k<=j;k++){
                    for(int f=0;f<=1;f++){
                        int val=dp[i-1][j][k][f];
                        if(!val) continue;
                        gmod(dp[i][j][k][f]+=1ll*val*j%mod);
                        
                        gmod(dp[i][j+1][k+1][0]+=val);
                        
                        if(!f){
                            if(k) gmod(dp[i][j][k-1][1]+=mod-1ll*val*k%mod);
                        }
                        else{
                            gmod(dp[i][j][k][1]+=mod-val);
                        }
                        
                        gmod(dp[i][j+1][k][1]+=mod-val);
                    }
                }
            }
        }
        
        for(int t=1;t<=n;t++){
            // cout<<t<<": "<<endl;
            int tot=0;
            for(int j=0;j<=t;j++){
                for(int k=0;k<=j;k++){
                    for(int f=0;f<=1;f++){
                        int val=dp[t][j][k][f];
                        if(!val) continue;
                        int w=1ll*C[t-(j-k)][k]%mod*mul[k]%mod;
                        // cout<<j<<" "<<k<<" "<<f<<": "<<val<<"  "<<w<<endl;
                        gmod(tot+=1ll*val*w%mod);
                    }
                }
            }
            // cout<<"! "<<tot<<" "<<(ksm(t,t)+mod-tot)%mod<<endl;
            printf("%d ",(ksm(t,t)+mod-tot)%mod);
        }
        printf("\n");
        
        
    }
}