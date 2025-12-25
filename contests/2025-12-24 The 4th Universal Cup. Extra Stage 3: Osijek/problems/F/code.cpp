#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,mod=998244353,inv2=(mod+1)/2;
int n,ans;
int a[N];

signed main(){
    cin>>n;
    
    int c0=0,c1=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(!a[i]) c0++;
        else c1++;
    }
    if(c0!=n/2 || c1!=(n+1)/2) return cout<<0,0;
    if(!a[1]) return cout<<0,0;
    
    if(n%2){
        ans=1;
        int x=1;
        for(int i=n;i>=2 && x>=0;i--){
            if(!a[i]) x++,ans=ans*inv2%mod;
            else{
                // cout<<i<<": "<<x<<endl;
                ans=ans*x%mod*(x-1)%mod*2%mod;
                x--;
            }
        }
        
        cout<<ans;
    }
    else{
        ans=1;
        int x=0;
        for(int i=n;i>=1 && x>=0;i--){
            if(!a[i]) x++,ans=ans*inv2%mod;
            else{
                // cout<<i<<": "<<x<<" "<<(x%mod*(x-1)%mod*2%mod+x*2%mod)%mod<<endl;
                ans=ans*(x%mod*(x-1)%mod*2%mod+x*2%mod)%mod;
                x--;
            }
        }
        cout<<ans;
    }
}
