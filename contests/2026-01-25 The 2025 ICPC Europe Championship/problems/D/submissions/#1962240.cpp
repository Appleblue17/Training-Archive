#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=220,INF=1e9;
int n,s[N];
pair <int,int> a[N];
int dp[N][N][N],rec[N][N][N];

vector <int> V;

vector <string> F[N*2];
string ANS[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;i++){
        double x; cin>>x;
        a[i]={-round(x*10000),i};
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--) s[i]=s[i+1]+(-a[i].first);
    
    for(int i=0;i<=n;i++){
        for(int j=0;j+i<=n;j++){
            for(int k=0;k+i+j<=n && k<=j;k++){
                dp[i][j][k]=INF;
            }
        }
    }
    dp[0][1][0]=0;
    for(int t=0;t<=n;t++){
        for(int i=0;i<=t;i++){
            for(int j=(t-i+1)/2;j+i<=t;j++){
                // k<=j => p-i<=2*j
                int k=t-i-j;
                int val=dp[i][j][k];
                if(val>=INF) continue;
                // cout<<" "<<t<<" "<<i<<" "<<j<<" "<<k<<": "<<val<<endl;
                
                for(int p=0;p<=j;p++){
                    // cout<<" -> "<<t+1<<" "<<i+j-p<<" "<<k+p<<" "<<p<<": "<<val+s[i+j-p+1]<<endl;
                    int nval=val+s[i+j-p+1];
                    if(nval<dp[i+j-p][k+p][p]){
                        dp[i+j-p][k+p][p]=nval;
                        rec[i+j-p][k+p][p]=j;
                    }
                }
            }
        }
    }
    // cout<<dp[n][0][0]<<endl;
    
    int i=n,j=0,k=0;
    while(i+j+k>1){
        int lj=rec[i][j][k];
        int lp=k;
        int li=i+lp-lj;
        int lk=j-lp;
        
        V.push_back(lp);
        
        i=li,j=lj,k=lk;
        // cout<<i<<" "<<j<<" "<<k<<endl;
    }
    reverse(V.begin(),V.end());
    // for(int x: V) cout<<x<<" "; cout<<endl;
    
    F[0].push_back("");
    for(int i=0;i<V.size();i++){
        for(int t=1;t<=V[i];t++){
            string &S=F[i].back();
            F[i+1].push_back(S+".");
            F[i+2].push_back(S+"-");
            
            F[i].pop_back();
        }
    }
    
    int id=0;
    for(int i=1;i<V.size();i++){
        for(string &S: F[i]){
            id++;
            ANS[a[id].second]=S;
        }
    }
    for(int i=1;i<=n;i++) cout<<ANS[i]<<endl;
}
