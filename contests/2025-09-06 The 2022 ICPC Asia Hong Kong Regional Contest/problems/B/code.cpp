#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1100,mod=998244353;
int n,m,ans;
int p[N][N],q[N][N],f[N][N];

void gmod(int &x){
    x%=mod;
}


signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&p[i][j]);
            gmod(p[i][j]+=p[i][j-1]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&q[i][j]);
            gmod(q[i][j]+=q[i-1][j]);
        }
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int tot=(1+mod-p[i+1][j-1])%mod*(1+mod-q[i-1][j+1])%mod*p[i][j-1]%mod*q[i-1][j]%mod;
            gmod(ans+=tot);
        }
    }
    
    cout<<(2+ans)%mod;
}
