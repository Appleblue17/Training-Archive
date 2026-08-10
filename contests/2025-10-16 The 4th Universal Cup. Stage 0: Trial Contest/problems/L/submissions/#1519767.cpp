#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;

int A,B;
int P=1,Q=1;
int f[N];
int x,y,r;
//const double sqrt2 = sqrt(2);

void solve(){
    scanf("%lld%lld%lld",&r,&x,&y);
    if(x < y)swap(x,y);
    int center = floor(sqrt(2)*r/(double)x);
    int ans=0;
    for(int a=max(1ll,center-5000);a<=min(2*r/x,center+5000);a++){
        //cout << 4*r*r-a*a*x*x << endl;
        //cout << 800000000ll*800000000 << endl;
        int b = floor(sqrtl((4*r*r-a*a*x*x)/(y*y)));
        while(b*b*y*y + a*a*x*x <= 4*r*r)b++;
        b--;
        ans = max(ans,a*b);
    }
    printf("%lld\n",ans);
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--)solve();
}
