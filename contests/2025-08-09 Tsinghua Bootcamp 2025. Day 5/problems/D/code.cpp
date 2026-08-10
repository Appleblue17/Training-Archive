#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+5,mod=998244353;
int n,ans;

int ksm(int a,int x){
    if(x<0) return 0;
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}
void gmod(int &x){
    x%=mod;
}

signed main(){
    cin>>n;
    int A=0;
    gmod(A+=ksm(4,n-1));
    gmod(A+=ksm(4,n-2));
    gmod(A+=2*ksm(4,n-3)%mod);
    gmod(A+=2*ksm(4,n-4)%mod);
    
    for(int i=0;i<=n-2;i++){
        gmod(A+=ksm(4,n-2-i));
    }
    
    int B=0;
    gmod(B+=3*ksm(4,n-1)%mod);
    
    int C=0;
    // i=0
    gmod(C+=ksm(4,n-1));
    for(int i=1;i<=n-1;i++){
        gmod(C+=2*ksm(3,i-1)%mod*ksm(4,n-i-1)%mod);
    }
    
    int D=0;
    for(int i=0;i<=n-2;i++){
        gmod(D+=ksm(4,n-2-i));
    }
    
    int E=0;
    gmod(E+=2*ksm(4,n-3)%mod);
    gmod(E+=3*ksm(4,n-4)%mod);
    gmod(E+=4*ksm(4,n-5)%mod);
    gmod(E+=3*ksm(4,n-6)%mod);
    gmod(E+=3*ksm(4,n-7)%mod);
    
    // cout<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<E<<endl;
    cout<<(A+B+C+D+E)%mod;
}