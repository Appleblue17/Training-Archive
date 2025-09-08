#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;

signed main(){
    int ax,ay,bx,by,cx,cy;
    scanf("%lld%lld%lld%lld%lld%lld",&ax,&ay,&bx,&by,&cx,&cy);
    int x = ax - bx,y = ay - by,xx = ax - cx, yy =  ay - cy;
    __int128 s = abs(x*yy-y*xx);
    __int128 a = __gcd(abs(ax-bx),abs(ay-by));
    __int128 b = __gcd(abs(ax-cx),abs(ay-cy));
    __int128 c = __gcd(abs(bx-cx),abs(by-cy));
    __int128 d,u,mn,mx;
    if(a == 1 || b == 1 || c == 1){
        printf("-1");
        return 0;
    }
    d = a*b*c;
    u = a*b+b*c+c*a-a-b-c;
    //cout << (int)a << ' ' << (int)b << ' ' << (int)c << endl;
    //cout << (int)u << ' ' << (int)s << endl;
    //cout << (int)(s%d) << endl;
    mx = s /a/b* (d-u) / c;
    if(a < b)swap(a,b);if(b < c)swap(b,c);
    if(a < b)swap(a,b);if(b < c)swap(b,c);
    u = (a-1)*(b-1)*c + a*(c-1) + b;
    mn = s/a/b*(d-u)/c;
    printf("%lld %lld",(int)mx,(int)mn);
}

