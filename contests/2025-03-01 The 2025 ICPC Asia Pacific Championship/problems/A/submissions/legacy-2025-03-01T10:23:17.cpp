#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2200;
int n,m,ans;
char S[N][N],T[N][N];

int c[N];

signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("\n%s",S[i]+1);
    }
    
    for(int f=0;f<=1;f++){
        for(int i=1;i<=n;i++) c[i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                c[i]+=(S[i][j]=='.');
            }
            ans+=c[i]*(c[i]-1)*(c[i]-2)*(c[i]-3);
        }
        
        for(int j=1;j<=m;j++){
            int s0=0,s1=0,s2=0;
            for(int i=1;i<=n;i++){
                if(S[i][j]!='.')continue;
                int x=c[i]-1;
                s0++;
                s1+=x;
                s2+=x*x;
            }
            ans+=s1*s1-s2;
            
            ans+=(s2-s1)*(s0-1)*2;
        }
        
        
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                T[j][i]=S[i][j];
            }
        }
        swap(S,T);
        swap(n,m);
    }
    cout<<ans;
}