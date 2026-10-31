#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;

int T,n,m;
vector <int> V[N];

signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        V[i].resize(m+1);
        for(int j=1;j<=m;j++){
            scanf("%lld",&V[i][j]);
        }
    }
    
    int ans=0;
    for(int j=1;j<=m;j++){
        int s=0,mn=0;
        for(int i=1;i<=n;i++){
            s+=V[i][j-1]-V[i][j];
            mn=min(mn,s);
        }
        ans+=(-mn);
    }
    cout<<ans;
    
}