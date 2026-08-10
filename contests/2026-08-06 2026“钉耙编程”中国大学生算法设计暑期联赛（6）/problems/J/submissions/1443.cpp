#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,INF=1e18;
int T,n,m;
int A[N],sm[N],ans;
vector<int> g[N];
inline void read(int& x){
    x=0;char c=getchar();bool f=0;
    for(;c<'0'||c>'9';c=getchar())f|=(c=='-');
    for(;c>='0'&&c<='9';c=getchar())
        x=(x<<1)+(x<<3)+(c^48);
    x=(f)?(-x):x;
}  

void solve(){
    int x, y; read(x); read(y);
    if(y==0){
        printf("0\n");
        return ;
    }
    long long ans=1ll*x*y+1ll*y*(y-1)/2ll-x;
    int k=(x-1)/2;
    printf("%lld\n", ans+max(1ll*(k+1)*(x-k), 1ll*(k+2)*(x-k-1)));
}

signed main(){
    read(T);
    while(T--){
        solve();
        
    }
    
    
}