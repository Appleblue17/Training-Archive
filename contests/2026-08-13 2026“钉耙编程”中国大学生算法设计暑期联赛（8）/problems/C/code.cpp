#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,M=350,mod=998244353;

int T,n,q;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}
int mul[N],inv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return mul[m]*inv[n]%mod*inv[m-n]%mod;
}

void gmod(int &x){
    x%=mod;
}

int rd(){
    int tot=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}

int B;
int pre[M][N];
int f[N],s[N];

int cal(int n,int k){
    if(n<=0) return 1;
    if(k<=B) return pre[k][n];
    else{
        int tot=1;
        for(int t=1;(k-1)*(t-1)<=n-t && t<=n;t++) gmod(tot+=C(n-(k-1)*(t-1),t));
        return tot;
    }
}

int wrapper(int n,int k){
    int res=cal(n,k);
    // cout<<n<<" "<<k<<": "<<res<<endl;
    return res;
}

signed main(){
    init(N-5);
    
    T=rd();
    while(T--){
        n=rd(); q=rd();
        
        B=sqrt(n);
        // cout<<B<<endl;
        // B=0;
        
        for(int k=1;k<=B;k++){
            for(int i=1;i<=n;i++){
                if(i<=k) f[i]=1;
                else f[i]=(s[i-k]+1)%mod;
                s[i]=(s[i-1]+f[i])%mod;
                
                pre[k][i]=(s[i]+1)%mod;
            }
        }
        
        while(q--){
            int x,k; x=rd(),k=rd();
            int ans=(wrapper(n,k)+mod-wrapper(x-k,k)*wrapper(n-x-k+1,k)%mod)%mod;
            printf("%lld\n",ans);
        }
    }
    
    
}