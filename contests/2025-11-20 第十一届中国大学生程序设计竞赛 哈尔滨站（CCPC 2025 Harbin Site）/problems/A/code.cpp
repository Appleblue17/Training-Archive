#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int T,n;
int a[N];

signed main(){
    cin>>T;
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        
        int g1=0,g2=0;
        for(int i=1;i<=n;i++) g1=__gcd(g1,a[i]);
        for(int i=1;i<n;i++) g2=__gcd(g2,abs(a[i+1]-a[i]));
        
        if(!g1 || !g2) printf("infinite\n");
        else{
            if(g1>=g2) printf("%lld 1\n",g1);
            else{
                int r=a[1]%g2;
                printf("%lld %lld\n",g2,g2/__gcd(g2,r));
            }
        }
        
    }
    
}


