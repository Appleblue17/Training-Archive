#include <bits/stdc++.h>
using namespace std;
int T;
signed main(){
    cin>>T;
    while(T--){
        int a,b,c,d; cin>>a>>b>>c>>d;
        int l=a+c,r=b+d;
        
        if(l/10!=r/10) cout<<9<<endl;
        else{
            int x=l/10,tot=0;
            while(x) tot=max(tot,x%10),x/=10;
            cout<<max(tot,r%10)<<endl;
        }
    }
    
}
