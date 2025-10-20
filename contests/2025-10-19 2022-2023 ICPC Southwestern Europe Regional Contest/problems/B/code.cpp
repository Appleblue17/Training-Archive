#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,m;
int a[N];

double f[N][N];
double dp[N][N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i];
    
    for(int t=1;t<=m;t++){
        int x=a[t];
        memset(dp,0,sizeof(dp));
        dp[0][x]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!dp[i][j]) continue;
                for(int k=j+1;k<=n;k++){
                    dp[i+1][k]+=dp[i][j]/(n-j);
                }
            }
        }
        
        for(int i=1;i<=n;i++) f[t][i]=dp[i][n];
        // for(int i=1;i<=n;i++) cout<<f[t][i]<<" "; cout<<endl;
    }
    
    for(int t=1;t<=m;t++){
        double ans=0;
        for(int i=0;i<=n;i++){
            if(!f[t][i]) continue;
            double tot=1;
            for(int j=1;j<=m;j++){
                if(j==t) continue;
                double sum=0;
                for(int k=i;k<=n;k++) sum+=f[j][k];
                tot*=sum;
            }
            ans+=tot*f[t][i];
        }
        printf("%.10lf ",ans);
    }
    
    
}
