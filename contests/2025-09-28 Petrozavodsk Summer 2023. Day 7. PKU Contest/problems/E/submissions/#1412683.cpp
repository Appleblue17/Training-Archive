#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int calc(int n, int m){
    int x=0, y=0;
    int dx=1, dy=1;
    int ret=0;
    while(1){
        if(x+dx<0) dx*=-1;
        if(x+dx>n) dx*=-1;
        if(y+dy<0) dy*=-1;
        if(y+dy>m) dy*=-1;
        x+=dx; y+=dy;
        ++ret;
        if(x==0&&y==0) break;
    }
    return ret;
}
ll calc2(int n, int m){
    return 2ll*n*m/__gcd(n, m);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m; 
        scanf("%d%d", &n, &m);
        printf("%lld\n", calc2(n, m));
    }
    // for(int i=2; i<=10; ++i){
    //     for(int j=2; j<=10; ++j){
    //         cout<<i<<' '<<j<<' '<<calc(i, j)<<' '<<calc2(i, j)<<endl;
    //     }
    // }
}
