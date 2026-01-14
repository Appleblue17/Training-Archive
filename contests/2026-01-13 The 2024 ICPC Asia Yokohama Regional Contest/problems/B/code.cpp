#include <bits/stdc++.h>
using namespace std;
#define int long long

int L,R;

signed main(){
    
    cin>>L>>R;
    
    for(int t=60;t>=0;t--){
        if((L>>t & 1ll)!=(R>>t & 1ll)){
            int ans=(L>>t)<<t;
            
            L &= (1ll<<t)-1;
            if(L){
                int x=t;
                while(!(L>>x) & 1ll) x--;
                // cout<<L<<" "<<x<<endl;
                if(L==(1ll<<x)) ans |= (1ll<<x);
                else ans |= 1ll<<(x+1);
            }
            
            cout<<ans;
            return 0;
        }
        
    }
    cout<<L;
    
    
}
