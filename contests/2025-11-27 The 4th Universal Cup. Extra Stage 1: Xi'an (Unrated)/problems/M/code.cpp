#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,mod=1e9+7;
int n,m;
int a[N],L[N],R[N];

int cal(int i,int l,int r){
    return R[i]-L[i]+1-max(0ll,min(R[i],r)-max(L[i],l)+1);
}
void gmod(int &x){
    x%=mod;
}

int f[N],g[N];

signed main(){
    scanf("%lld%lld",&n,&m);
    int all=1;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]==-1) L[i]=1,R[i]=m;
        else L[i]=R[i]=a[i];
        all=all*(R[i]-L[i]+1)%mod;
    }
    
    int alc=cal(1,1,n-1)*cal(n,1,n-1)%mod;
    
    f[1]=1;
    for(int i=2;i<=n-1;i++){
        int A=cal(i,1,n-1);
        int B=(L[i]<=1 && 1<=R[i]);
        
        f[i]=A*(f[i-1]+g[i-1])%mod;
        g[i]=B*f[i-1]%mod;
    }
    
    int ans=(f[n-1]+g[n-1])%mod;
    int anss=(all+mod-alc*ans%mod)%mod;
    
    int del=1;
    for(int i=1;i<=n;i++){
        if(!(L[i]<=1 && 1<=R[i])) del=0;
    }
    if(n & 1) gmod(anss+=mod-del);
    
    cout<<anss;
}
