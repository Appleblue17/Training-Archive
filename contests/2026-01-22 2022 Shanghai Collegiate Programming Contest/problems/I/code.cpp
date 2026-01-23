#include <bits/stdc++.h>
using namespace std;
// #define double long double
const int N=220;
const double eps=1e-10;
int n;
double dp[N][N][N],ans;

int main(){
    cin>>n;
    dp[0][0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;i+j*2<=n;j++){
            for(int k=0;i+j*2+k*2<=n;k++){
                int p=n-i-j*2-k*2;
                double val=dp[i][j][k];
                if(val<eps) continue;
                
                int A=(2*j)*(2*j-2);
                int B=(2*j)*(2*k)*2;
                int C=(2*j)*p*2;
                int D=(2*k)*(2*k-1);
                int E=(2*k)*p*2;
                int F=p*(p-1);
                int sum=A+B+C+D+E+F;
                if(!sum) continue;
                if(j>=2) dp[i+2][j-2][k+1]+=val*A/sum;
                if(j) dp[i+2][j-1][k]+=val*B/sum;
                if(j) dp[i+1][j-1][k+1]+=val*C/sum;
                if(k) dp[i+2][j][k-1]+=val*D/sum;
                dp[i+1][j][k]+=val*E/sum;
                dp[i][j+1][k]+=val*F/sum;
                
                // cout<<i<<" "<<j<<" "<<k<<" "<<p<<": "<<val<<" | "<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<E<<" "<<F<<endl;
                ans+=val*(n*n)/sum;
            }
        }
    }
    cout<<setprecision(9)<<fixed<<ans;
    
}
