#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=2005,INF=1e9;
int T,n;
int a[N];
int buc[N*2];

signed main(){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        
        long long ans=0;
        for(int t=1;t<=n;t++){
            memset(buc,0,sizeof(buc));
            
            int s=0; buc[n]+=t;
            for(int i=t-1;i>=1;i--){
                if(a[i]<a[t]) s--;
                else s++;
                buc[s+n]+=i;
            }
            
            ans+=1ll*a[t]*t*buc[n];
            s=0;
            for(int i=t+1;i<=n;i++){
                if(a[i]<a[t]) s--;
                else s++;
                ans+=1ll*a[t]*i*buc[n-s];
            }
        }
        printf("%lld\n",ans);
    }
    
}