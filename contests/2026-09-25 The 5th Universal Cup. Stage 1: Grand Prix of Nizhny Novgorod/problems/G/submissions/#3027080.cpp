#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=5e5+5,mod=998244353;
int k,n,alc;
int a[N];


int f[N];
void fwt(int *f,int n){
    for(int k=1;k<n;k<<=1){
        for(int i=0;i<n;i+=k*2){
            for(int j=i;j<i+k;j++){
                f[j] += f[j+k];
            }
        }
    }
}

signed main(){
    cin>>k>>n;
    alc=(1<<k)-1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]) f[a[i]^alc]++;
    }
    fwt(f,1<<k);
    
    // for(int mac=0;mac<(1<<k);mac++) cout<<f[mac]<<" "; cout<<endl;
    
    for(int mac=0;mac<(1<<k);mac++){
        if(!f[mac]){
            // cout<<mac<<endl;
            for(int i=1;i<=n;i++){
                if((a[i] | mac) == mac) printf("%d ",a[i]);
            }
            for(int i=1;i<=n;i++){
                if((a[i] | mac) != mac) printf("%d ",a[i]);
            }
            return 0;
        }
    }
    
}