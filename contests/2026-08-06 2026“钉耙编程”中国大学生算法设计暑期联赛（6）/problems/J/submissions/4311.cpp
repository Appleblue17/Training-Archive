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
long long sum(int x){
    return 1ll*x*(x+1)/2ll;
}
void solve(){
    int x, y; read(x); read(y);
    if(y==0){
        printf("0\n");
        return ;
    }
    if(x==0){
        printf("%lld\n", 1ll*y*(y-1)/2ll);
        return ;
    }
    int t=x/(y+1);
    int b=x%(y+1), a=y-b;
    long long ans=0;
    ans+=1ll*(t+2)*(t+2)*sum(b-1)-1ll*(b-1)*(t+2);
    ans+=1ll*(t+1)*(1ll*b*(t+2)-1);
    ans+=1ll*(t+1)*(t+1)*sum(a);
    ans+=1ll*(a)*(t+1)*(1ll*b*(t+2)-1);
    if(b==0){
        ans=0;
        ans+=1ll*(t+1)*(t+1)*sum(a);
        ans-=1ll*(a)*(t+1);
    }
    printf("%lld\n", ans);
}

signed main(){
    read(T);
    while(T--){
        solve();
        
    }
    
    
}