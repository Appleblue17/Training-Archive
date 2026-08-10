#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,mod=1e9+7;
int p,q,r,n;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}
void gmod(int &x){
    x%=mod;
}

int f[N],g[N],ans[N];

signed main(){
    cin>>p>>q>>r;
    p=p*ksm(1000,mod-2)%mod;
    q=q*ksm(1000,mod-2)%mod;
    r=r*ksm(1000,mod-2)%mod;
    
    int w=(p+q+mod-p*q%mod)%mod;
    
    cin>>n;
    int cnt=0;
    f[0]=1;

    for(int i=1;i<=n;i++){
        int x; scanf("%lld",&x);
        
        int A=min(x,max(0ll,80-cnt)),B=x-A;
        
        int prob0=ksm(1+mod-p,A)*ksm(1+mod-w,B)%mod;
        int prob1=0;
        if(A) gmod(prob1+=A*p%mod*ksm(1+mod-p,A-1)%mod*ksm(1+mod-w,B)%mod);
        if(B) gmod(prob1+=B*w%mod*ksm(1+mod-p,A)%mod*ksm(1+mod-w,B-1)%mod);
        int prob2=(1+mod-prob0+mod-prob1)%mod;
        
        // cout<<" "<<i<<": "<<A<<" "<<B<<": "<<prob0<<" "<<prob1<<" "<<prob2<<endl;
        
        f[i]=f[i-1]*prob0%mod;
        g[i]=(f[i-1]*prob1%mod+g[i-1]*prob0%mod);
        
        gmod(ans[i]+=(f[i-1]+g[i-1])%mod*prob2%mod+g[i-1]*prob1%mod);
        
        gmod(ans[i+1]+=g[i]*r%mod);
        g[i]=g[i]*(1+mod-r)%mod;
        
        cnt+=x;
    }
    
    for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
}
