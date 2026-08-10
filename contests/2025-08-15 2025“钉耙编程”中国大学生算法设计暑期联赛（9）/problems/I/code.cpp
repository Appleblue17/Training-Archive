#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,mod=998244353;
int T,n,p,k;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1ll;
    }
    return tot;
}

namespace task1{
    int invv[N];
    void solve(){
        // cout<<"task1"<<endl;
        invv[1]=1;
        for(int i=2;i<p;i++) invv[i]=(p-p/i)*invv[p%i]%p;
        
        __int128 tot=0;
        for(int i=1;i<p;i++){
            __int128 tmp=(__int128)invv[i]*i+((__int128)invv[i]<<(k*2))+((__int128)i<<k)+((__int128)1<<(k*3));
            tot^=tmp;
        }
        int ans=tot%mod;
        cout<<ans<<endl;
    }
}

namespace task2{
    
    void solve(){
        // cout<<"task2"<<endl;
        int n=p-1;
        int tot=((n%2==0)?n%mod:0)+(n%4==1 || n%4==2);
        tot%=mod;
        // cout<<n<<" "<<tot<<" "<<sum<<endl;
        
        int ans=(ksm(2,k)+ksm(4,k))%mod*tot%mod;
        ans=(ans+1)%mod;
        n%=mod;
        ans=(ans+n*n%mod)%mod;
        cout<<ans<<endl;
    }
}

signed main(){
    cin>>T;
    while(T--){
        cin>>p;
        k=(p-1)/119+1;
        // cout<<k<<endl;
        // task2::solve();
        
        // cout<<k<<endl;
        if(k<=26) task1::solve();
        else task2::solve();
    }
}