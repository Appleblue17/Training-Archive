#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,INF=1e9;

int L,n;
int p[N];

int f[N],g[N];
bool check(int k){
    f[1]=p[1]+k;
    for(int i=2;i<=n;i++){
        if(p[i]>f[i-1]+k) f[i]=-INF;
        else f[i]=p[i]+(k-2*max(0ll,p[i]-f[i-1]));
    }
    
    
    g[n]=p[n]-k;
    for(int i=n-1;i>=1;i--){
        if(p[i]<g[i+1]-k) g[i]=INF;
        else g[i]=p[i]-(k-2*max(0ll,g[i+1]-p[i]));
    }
    
    // for(int i=1;i<=n;i++) cout<<f[i]<<" "; cout<<endl;
    // for(int i=1;i<=n;i++) cout<<g[i]<<" "; cout<<endl;
    
    for(int i=1;i<n;i++){
        if(g[i+1]<=f[i]) return 1;
    }
    return 0;
}

signed main(){
    cin>>L>>n;
    for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
    int l=0,r=L,tot=r;
    
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) tot=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<tot;
}

