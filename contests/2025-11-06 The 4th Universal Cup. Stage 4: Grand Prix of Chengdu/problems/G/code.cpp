#include<bits/stdc++.h>
using namespace std;
#define int long long
int T, n, k, m;
signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k>>m;
        int c1=n/k-1;
        // int c2=min(1+m, n-(n/k-1));
        int c2=min(m, n-n/k);
        m-=c2; c2+=1;
        int w=min(c1, m);
        c1-=w; c2+=w;
        int ans=0;
        ans+=c1/2; c1%=2;
        if(c1){
            --c2; ++ans;
        }
        ans+=c2;
        cout<<ans<<endl;
    }
    
}
