#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=22;
int T,n,sum;
int a[N];
inline void read(int &x){
    x=0; char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c-'0'), c=getchar();
}
bool check(int k){
    int mn=0,mx=0;
    for(int i=1;i<=13;i++){
        int L=(3*k-sum+a[i]+1)/2,R=a[i]/3;
        L=max(L,0);
        if(L>R) return 0;
        mn+=L,mx+=R;
    }
    if(mn<=k) return 1;
    return 0;
}

signed main(){
    read(T);
    while(T--){
        int mx=0; sum=0;
        for(int i=1;i<=13;i++) read(a[i]),mx+=a[i]/3,sum+=a[i];
        
        int l=0,r=min(mx,sum/4),tot=0;
        while(l<=r){
            int mid=(l+r)>>1;
            // cout<<l<<" "<<r<<" "<<mid<<endl;
            if(check(mid)) tot=mid,l=mid+1;
            else r=mid-1;
        }
        printf("%d\n",tot);
    }
}