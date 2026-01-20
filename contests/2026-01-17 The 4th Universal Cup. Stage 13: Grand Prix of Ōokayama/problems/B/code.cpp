#include <bits/stdc++.h>
using namespace std;
const int N=5500,INF=1e9;
int n,p[N],a[N];

int mp[N],tmp[N];

int solve(int l,int r){
    if(l>=r) return 0;
    // cout<<l<<" "<<r<<": "<<endl;
    // cout<<"  "; for(int i=l;i<=r;i++) cout<<p[i]<<" "; cout<<endl;
    // cout<<"  "; for(int i=l;i<=r;i++) cout<<a[i]<<" "; cout<<endl;
    
    int len=r-l+1;
    for(int i=l;i<=r;i++) mp[a[i]]=i;
    
    int stp=INF,mid;
    
    int mn=INF,mx=-INF;
    for(int i=l;i<r;i++){
        int pos=mp[p[i]];
        mn=min(mn,pos);
        mx=max(mx,pos);
        
        if(mx-mn+1==i-l+1){
            int val=(mn==1)?0:r-mn+1;
            if(val<stp) stp=val,mid=l+(mx-mn);
        }
    }
    
    mn=INF,mx=-INF;
    for(int i=r;i>l;i--){
        int pos=mp[p[i]];
        mn=min(mn,pos);
        mx=max(mx,pos);
        
        if(mx-mn+1==r-i+1){
            int val=(mx==n)?0:r-mx;
            if(val<stp) stp=val,mid=r-(mx-mn)-1;
        }
    }
    // cout<<" -> "<<stp<<" "<<len<<endl;
    assert(stp<len);
    
    for(int i=l;i<=r;i++) tmp[(i-l+stp)%len+l]=a[i];
    for(int i=l;i<=r;i++) a[i]=tmp[i];
    // cout<<"  "; for(int i=l;i<=r;i++) cout<<a[i]<<" "; cout<<endl;
    
    return max(solve(l,mid),solve(mid+1,r))+stp;
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) a[i]=i;
    
    int ans=solve(1,n);
    cout<<ans;
}
