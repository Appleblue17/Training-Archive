#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,mod=998244353,INF=1e9;
int T,n;
int a[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
        
        int ans1=0,ans2=0;
        
        int l=1,r=n;
        while(l<=n && !a[l]) l++;
        while(r>=1 && !a[r]) r--;
        
        if(l>n){
            ans1=n*(n+1)/2%mod;
            ans2=(n+1)*(n+1)%mod;
        }
        else{
            ans1=l*(n-r+1)%mod;
            int mn=INF,mx=-INF;
            for(int i=l;i<=r;i++){
                if(!a[i]) continue;
                mn=min(mn,a[i]),mx=max(mx,a[i]);
            }
            ans2=(mn+n+1)*(n-mx+1)%mod;
        }
        cout<<sum<<" "<<ans1*ans2%mod<<endl;
    }
}