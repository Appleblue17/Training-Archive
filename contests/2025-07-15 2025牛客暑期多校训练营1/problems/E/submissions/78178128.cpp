#include <bits/stdc++.h>
using namespace std;
#define int long long
int T,a,b;
 
 
int solve(int x){
    if(x==3) return 1;
    return x/4+(x-1)/2-1;
}
 
signed main() {
    cin>>T;
    while(T--){
        scanf("%lld%lld",&a,&b);
        int x=abs(a*a-b*b);
        printf("%lld\n",solve(x));
    }
     
}
