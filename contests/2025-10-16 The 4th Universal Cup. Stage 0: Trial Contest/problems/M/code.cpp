#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5,INF=1e18;

int n,k;
int a[N];

signed main(){
    // freopen("Min.txt","r",stdin);
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    
    int cur=1;
    while(n-cur+1>3 && k--){
        sort(a+cur,a+n+1);
        while(cur<=n && !a[cur]) cur++;
        for(int t=cur+1;t<=n;t++) a[t]-=a[t-1];
        
        // cout<<cur<<endl;
        // if(n-cur+1<=10) for(int t=cur;t<=n;t++) cout<<a[t]<<" "; cout<<endl;
    }
    
    // cout<<k<<": "<<a[n-2]<<" "<<a[n-1]<<" "<<a[n]<<endl;
    while(k>0){
        sort(a+cur,a+n+1);
        while(cur<=n && !a[cur]) cur++;
        if(cur!=n-2) break;
        
        // cout<<k<<": "<<a[n-2]<<" "<<a[n-1]<<" "<<a[n]<<endl;
        
        int &x=a[cur],&y=a[cur+1],&z=a[cur+2];
        int lim=min(k,y/x);
        
        int l=1,r=lim,tot=l;
        while(l<=r){
            int mid=(l+r)>>1;
            __int128 num=mid;
            __int128 sum=num*y-num*(num+1)/2*x;
            if(sum<=z-y) tot=mid,l=mid+1;
            else r=mid-1;
        }
        
        __int128 sum=tot*y-tot*(tot+1)/2*x;
        z-=sum;
        y-=tot*x;
        k-=tot;
        
        // cout<<" go "<<tot<<" -> "<<x<<" "<<y<<" "<<z<<endl;
    }
    
    
    while(k>0){
        sort(a+cur,a+n+1);
        while(cur<=n && !a[cur]) cur++;
        if(cur!=n-1) break;
        
        // cout<<k<<": "<<a[n-1]<<" "<<a[n]<<endl;
        
        int &x=a[cur],&y=a[cur+1];
        int lim=min(k,y/x);
        
        y-=lim*x;
        k-=lim;
        
        // cout<<" go "<<tot<<" -> "<<x<<" "<<y<<" "<<z<<endl;
    }
    
    for(int i=1;i<=n;i++) printf("%lld ",a[i]);
}
