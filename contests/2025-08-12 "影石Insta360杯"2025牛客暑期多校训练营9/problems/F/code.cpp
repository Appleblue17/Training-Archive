#include <bits/stdc++.h>
#define int long long
int T,n;
 
 
signed main() {
    std::cin>>T;
    while(T--){
        int sx,sy,tx,ty,x1,y1,x2,y2;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        sx = x1+x2;
        sy = y1+y2;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        tx = x1+x2;
        ty = y1+y2;
        //std::cout << sx << ' ' << sy << std::endl;
        printf("%lld\n",std::max(std::abs(sx-tx),std::abs(sy-ty)));
    }
}
