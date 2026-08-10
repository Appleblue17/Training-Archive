#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5;
int T,n;
int a[N],s[N];
int ans[N];

signed main(){
    cin>>T;
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        
        for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i],ans[i]=0;
        
        int cur=n;
        for(int i=n;i>=1;i--){
            cur=min(cur,i);
            
            int l=0,r=i-1,tot=0;
            while(l<=r){
                int mid=(l+r)>>1;
                if(s[i-1]-s[mid-1]>a[i]) tot=mid,l=mid+1;
                else r=mid-1;
            }
            
            // cout<<i<<": "<<tot<<endl;
            
            int mn=i-tot+1;
            while(cur>=mn) ans[cur]=s[i]-s[i-cur],cur--;
        }
        
        for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
        printf("\n");
    }
    
}
