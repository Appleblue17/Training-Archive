#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
const int N=2e6+50,mod=1e9+7;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1;
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

void gmod(int &x){
    x%=mod;
}

int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return 1ll*mul[m]*inv[n]%mod*inv[m-n]%mod;
}

int T,n,m,c,d,a,b;

signed main(){
    init(N-5);
    
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&n,&m,&c,&d);
        int iv=ksm((c+d)%mod,mod-2);
        a=1ll*c*iv%mod,b=1ll*d*iv%mod;
        
        if(!m){
            printf("%lld\n",ksm(a,n+1));
            continue;
        }
        if(!n){
            printf("%lld\n",1ll*ksm(a,m-1)*b%mod*b%mod);
            continue;
        }
        if(!a){
            if(m==n+1) printf("1\n");
            else printf("0\n");
            continue;
        }
        
        int bb=1ll*b*b%mod;
        int aa=ksm(1ll*a*a%mod,mod-2);
        
        int ans=0,s1=1,s2=ksm(a,n+m+1);
        for(int k=1;2*k-1<=n+m;k++){
            s1=1ll*s1*bb%mod;
            s2=1ll*s2*aa%mod;
            gmod(ans+=1ll*s1*s2%mod*C(m-1,k-1)%mod*C(n+1,k)%mod);
        }
        printf("%lld\n",ans);
    }
}