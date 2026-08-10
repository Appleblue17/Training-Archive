#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
ll N,W;
__int128 n, m, w;
__int128 ans;

__int128 Sum(__int128 x){
    return x*(x+1)*(2*x+1)/6;
}
__int128 Top(__int128 m){
    return ((2*n+1)*m-m*m)/2;
}
void Prin(__int128 x){
    if(x<=0)return;
    Prin(x/10);
    putchar(x%10+48);
}
__int128 bf(__int128 m,__int128 w){
    __int128 ans=0;
    while(m>=w){
        ans += Top(m);
        m -= m/w;
        //printf("bfm = ");Prin(m);putchar('\n');
    }
    ans += Top(m);
    return ans;
}
void solve(){
    scanf("%lld%lld", &N, &W);
    n = N;w = W;
    m = n;
    
    ans = 0;
    while(m > w*w){
        
        ans += Top(m);
        m -= m/w;
        //printf("prem=");Prin(m);putchar('\n');
    }
    //int C=0;
    while(m >= w){
        //C++;if(C>100)break;
        __int128 k = m%w;
        __int128 d = m/w;
        __int128 cnt = k/d+1;
        //printf("m=");Prin(m);putchar('\n');
        ans += (2*n+1)*(m+m-(cnt-1)*d)*cnt/4-(cnt*m*m-d*m*cnt*(cnt-1)+d*d*Sum(cnt-1))/2;
        m -= cnt*d;
    }
    ans += Top(m);
    //if(ans != bf(N,w)){
    //    Prin(ans);putchar(' ');Prin(bf(N,w));putchar(' ');
    //}
    Prin(ans);putchar('\n');
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        solve();
    }
}