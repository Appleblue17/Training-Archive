#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,INF=1e9;

int n;
char S[N];

int f[N][6];
char fx[6]={'s','p','b','s','u'};
int w[6]={-1,-1,0,1,1};


int main(){
    scanf("%d",&n);
    scanf("\n%s",S+1);
    
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=5;j++) f[i][j]=INF;
    
    f[1][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<5;j++){
            if(f[i][j]>=INF) continue;
            f[i+1][j]=min(f[i+1][j],f[i][j]);
            if(S[i]==fx[j]){
                f[i+1][j+1]=min(f[i+1][j+1],f[i][j]+w[j]*i);
            }
        }
        // for(int j=0;j<=5;j++) cout<<f[i][j]<<" "; cout<<endl;
    }
    int ans=INF;
    for(int i=1;i<=n+1;i++) ans=min(ans,f[i][5]);
    cout<<ans-6;
}
