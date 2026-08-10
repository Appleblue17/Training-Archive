#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=62,INF=1e18;
int x;

int dp[N][N][N][N];

signed main(){
    cin>>x;
    int lim=__lg(x);
    // cout<<lim<<endl;
    
    for(int n=1;(1ll<<(n-1))<=x;n++){
        for(int c=1;c<=n;c++){
            // (c<<n)<=2*x
            if((c<<(n-1))>x) break;
            int y=(c<<n)-x;
            if(y<0) continue;
            
            // cout<<"search "<<c<<" "<<n<<endl;
            
            for(int t=0;t<=lim+1;t++){
                for(int j=0;j<=c;j++){
                    for(int i=0;i<=j;i++){
                        for(int k=0;k<=n;k++){
                            dp[t][i][j][k]=-1;
                        }
                    }
                }
            }
            
            dp[0][0][0][0]=0;
            for(int t=0;t<=lim;t++){
                int plim=(t<=n)?n:0;
                for(int j=0;j<=c;j++){
                    for(int i=0;i<=j;i++){
                        for(int k=0;k<=n;k++){
                            if(dp[t][i][j][k]==-1) continue;
                            
                            for(int p=0;p<=plim;p++){
                                int ni=i+p,nj=j+p,nk=k+p*(n-t);
                                if(nj>c || nk>n) break;
                                if((ni & 1)==(y>>t & 1)){
                                    dp[t+1][ni/2][nj][nk]=p;
                                }
                            }
                            
                        }
                    }
                }
            }
            
            int ret=dp[lim+1][0][c][n];
            if(ret!=-1){
                // cout<<"find sol: "<<n<<" "<<c<<endl;
                cout<<"Yes"<<endl;
                cout<<n<<endl;
                
                int id=0;
                int i=0,j=c,k=n;
                for(int t=lim;t>=0;t--){
                    int p=dp[t+1][i][j][k];
                    // cout<<n-t<<": "<<p<<endl;
                    for(int x=1;x<=p;x++){
                        id++;
                        for(int y=1;y<=n-t;y++) cout<<id<<" ";
                    }
                    
                    i=i*2+(y>>t & 1)-p;
                    j=j-p;
                    k=k-p*(n-t);
                }
                
                return 0;
            }
            
        }
    }
    cout<<"No";
    
}
