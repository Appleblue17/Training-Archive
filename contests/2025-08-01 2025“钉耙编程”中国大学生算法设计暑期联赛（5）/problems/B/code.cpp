#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int T,n,m,k,p;
int a[N],b[N];


bool check(int x){
    int block=0;
    for(int i=1;i<=n;i++){
        if(x*k<=a[i]){
            block+=x;
            b[i]=0;
        }
        else{
            block+=a[i]/k;
            b[i]=a[i]%k;
        }
    }
    block=min(block,x*p);
    if(block*k>=m) return 1; 
    int rem=m-block*k;
    int r=x*p-block;
    sort(b+1,b+n+1);
    
    int sum=0;
    for(int i=n;i>=max(1ll,n-r+1);i--){
        sum+=b[i];
    }
    return (sum>=rem);
}

signed main() {
    cin>>T;
    while(T--){
        scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        
        int l=0,r=m,tot=r+1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)) tot=mid,r=mid-1;
            else l=mid+1;
        }
        printf("%lld\n",tot);
    }
}