#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1.1e6+5;

int n;
int a[N];

void FWTxor(int *f,int n){
    for(int k=1;k<n;k*=2){
        for(int i=0;i<n;i+=k*2){
            for(int j=i;j<i+k;j++){
                int x=f[j],y=f[j+k];
                f[j]=x+y;
                f[j+k]=x-y;
            }
        }
        
    }
}


signed main(){
    scanf("%lld",&n);
    int sum=0;
    for(int i=0;i<(1<<n);i++) scanf("%lld",&a[i]),sum+=a[i];
    
    
    FWTxor(a,1<<n);
    // for(int i=0;i<(1<<n);i++) cout<<a[i]<<" "; cout<<endl;
    for(int i=0;i<(1<<n);i++) printf("%lld ",(sum-a[i])/2);
}
