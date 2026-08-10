#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,W=1e6;

int T,n,a[N];
int L[N],R[N];

signed main(){
    cin>>T;
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        
        int tot=0,del=0;
        for(int i=1;i<=n;i++){
            a[i]*=10*W;
            L[i]=max(a[i]-5*W,0ll);
            R[i]=min(a[i]+5*W-1,1000ll*W);
            tot+=L[i];
            del+=R[i]-L[i];
        }
        
        int rem=1000*W-tot;
        if(rem<0 || rem>del) printf("No\n");
        else{
            printf("Yes\n");
            for(int i=1;i<=n;i++){
                int x=min(rem,R[i]-L[i]);
                rem-=x;
                printf("%lld ",L[i]+x);
            }
            printf("\n");
        }
        
    }
    
}
