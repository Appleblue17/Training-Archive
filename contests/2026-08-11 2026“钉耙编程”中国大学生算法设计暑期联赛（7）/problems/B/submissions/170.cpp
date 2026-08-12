#include <bits/stdc++.h>
using namespace std;
const int N=3e6+5,INF=1e9;

int T,n;
char S[N];
int a[N];

int dp[N][2][16];
void gmin(int &x,int y){
    x=min(x,y);
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("\n%s",S+1);
        n=strlen(S+1);
        for(int i=1;i<=n;i++) a[i]=S[i]-'0';
        
        
        for(int t=1;t<=n;t++){
            for(int i=0;i<2;i++){
                for(int mac=0;mac<16;mac++){
                    dp[t][i][mac]=INF;
                }
            }
        }
        for(int t=1;t<=n;t++) dp[t][a[t]][0]=1;
        
        int alc=0;
        for(int t=1;t<n;t++){
            int b=a[t],c=a[t+1],nmac=(1<<(b+c*2));
            alc |= nmac;
            for(int i=0;i<2;i++){
                for(int mac=0;mac<16;mac++){
                    int x=dp[t][i][mac];
                    gmin(dp[t+1][i][mac],x);
                    gmin(dp[t+1][c][mac | (1<<(i+c*2))],x+1);
                }
            }
        }
        int ans=INF;
        for(int i=0;i<2;i++){
            ans=min(ans,dp[n][i][alc]);
        }
        printf("%d\n",ans);
    }
    
}