#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int T,n,a[N];

bool check(int k){
    for(int i=1;i<=n;i++){
        if(a[i]*2>k) return 0;
        k-=a[i];
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        
        int l=0,r=1e18,tot=r;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)) tot=mid,r=mid-1;
            else l=mid+1;
        }
        cout<<tot<<endl;
    }
    
    
}