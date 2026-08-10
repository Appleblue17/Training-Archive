#include <bits/stdc++.h>
using namespace std;
const int N=2e7+5,mod=1e9+7,inv2=(mod+1)/2,INF=1e9;
int T,n,m,k;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1ll;
    }
    return tot;
}

int mul[N],inv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return 1ll*mul[m]*inv[n]%mod*inv[m-n]%mod;
}
void gmod(int &x){
    x+=x>>31 & mod;
}
int ID(int x){
    return (x & 1)?mod-1:1;
}

int solve(int n,int m,int k){
    int ans1=0,ans2=0;
    for(int t=0;t<=n/(k+1) && t<=m;t++){
        int s=n-t*(k+1);
        int tmp=1ll*C(m,t)*C(m-1+s,s)%mod;
        if(t & 1) gmod(ans1-=tmp);
        else gmod(ans1+=tmp-mod);
    }
    
    if(k%2){
        for(int t=0;t<=n/(k+1) && t<=m;t++){
            int s=n-t*(k+1);
            if(s & 1) continue;
            int tmp=1ll*C(m,t)*C(m/2-1+s/2,s/2)%mod;
            if(t & 1) gmod(ans2-=tmp);
            else gmod(ans2+=tmp-mod);
        }
    }
    else if(n%2==0){
        for(int t=0;t<=n/(2*k+2) && t<=m/2;t++){
            int s=n-t*(2*k+2);
            if(s & 1) continue;
            int tmp=1ll*C(m/2,t)*C(m/2-1+s/2,s/2)%mod;
            if(t & 1) gmod(ans2-=tmp);
            else gmod(ans2+=tmp-mod);
        }
    }
    return 1ll*(ans1+1ll*ans2*(m-1)%mod)*ksm(m,mod-2)%mod;
}

signed main(){
    init(N-5);
    
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        m=1<<m;
        
        cout<<solve(n,m,k)<<endl;
        
        cin>>n>>m;
        m=1<<m;
        int xorsum=0,sum=0;
        for(k=1;k<=n;k++){
            int ret=solve(n,m,k);
            xorsum^=ret;
            gmod(sum+=1ll*ret*ret%mod-mod);
        }
        cout<<xorsum<<" "<<sum<<endl;
    }
    
}