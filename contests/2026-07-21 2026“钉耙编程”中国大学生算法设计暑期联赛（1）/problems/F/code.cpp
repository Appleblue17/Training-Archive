#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,mod=998244353,inv2=(mod+1)/2,inv6=(mod+1)/6;
int T,n;
int a[N];
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1ll;
    }
    return tot;
}
void gmod(int &x){
    x%=mod;
}

signed main(){
    scanf("%lld", &T);
    while(T--){
        int ans=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        if(n==1) ans=a[1];
        else{
            for(int k=1;k<=n;k++){
                int w;
                if(k>1 && k<n) w=((n-3)*inv6%mod+1)%mod;
                else w=((n-2)*inv6%mod+1)%mod;
                gmod(ans+=w*a[k]%mod);
                
            }
        }
        printf("%lld\n",ans);
    }
}