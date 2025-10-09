#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
int n, a[3][N];
ll sum[3][N];
void solve(){
    scanf("%d", &n);
    for(int i=1; i<=2; ++i){
        for(int j=1; j<=n; ++j){
            scanf("%d", &a[i][j]);
            sum[i][j]=sum[i][j-1]+a[i][j];
        }
    }
    ll tot=sum[1][n]+sum[2][n];
    ll dt=sum[1][n]-sum[2][n];
    if(n%2==0){
        dt=max(dt, 2ll*sum[1][n/2]+2ll*sum[2][n/2]-tot);
        dt=min(dt, 2ll*sum[1][n/2+1]+2ll*sum[2][n/2+1]-tot);
    }
    else{
        dt=max(dt, 2ll*sum[1][n/2]+2ll*sum[2][n/2]-tot);
        dt=min(dt, 2ll*sum[1][n/2+1]+2ll*sum[2][n/2+1]-tot);
    }
    printf("%lld\n", (tot+dt)/2);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
