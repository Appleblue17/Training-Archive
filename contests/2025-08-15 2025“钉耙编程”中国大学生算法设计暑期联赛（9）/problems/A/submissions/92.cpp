#include <bits/stdc++.h>
using namespace std;
#define int long long
int T,n;
int a[10];

signed main(){
    cin>>T;
    while(T--){
        for(int i=0;i<10;i++) scanf("%lld",&a[i]);
        
        int ans=a[0]+a[4]+a[8];
        int x=a[1]+a[3]+a[5]+a[7],y=a[2],z=a[6]+a[9];
        
        if(x>y) swap(x,y);
        // cout<<x<<" "<<y<<" "<<z<<endl;
        if(x+z<=y) ans+=x+z;
        else ans+=(x+y+z)/2;
        printf("%lld\n",ans);
    }
}