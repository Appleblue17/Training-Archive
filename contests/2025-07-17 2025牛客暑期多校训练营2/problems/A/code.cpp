#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,mod=998244353;
int T,n;
int a[N];
int pw[N];
 
signed main(){
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*2%mod;
     
    cin>>T;
    while(T--){
        scanf("%lld",&n);
        int alc=0;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]),alc+=(a[i]==-1);
         
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i-1]!=1 && a[i]!=0){
                ans=(ans+pw[alc-(a[i-1]==-1)-(a[i]==-1)])%mod;
            }
        }
        printf("%lld\n",ans);
    }
     
     
}
