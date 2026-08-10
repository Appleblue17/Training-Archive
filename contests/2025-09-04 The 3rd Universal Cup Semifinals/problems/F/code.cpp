#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5,mod=1e9+7,inv2=(mod+1)/2;

int n,m=22;
int a[N];

void gmod(int &x){
    x%=mod;
}

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
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return 1ll*mul[m]*inv[n]%mod*inv[m-n]%mod;
}

int ID(int x){
    return (x & 1)?mod-1:1;
}

int F[M],G[M],H[M];
void fwt_xor(int *f,int n){
    for(int l=1;l<n;l<<=1){
        for(int i=0;i<n;i+=l<<1){
            for(int j=0;j<l;j++){
                int x=f[i+j],y=f[i+j+l];
                gmod(f[i+j]=x+y);
                gmod(f[i+j+l]=x+mod-y);
            }
        }
    }
}

int f[N],g[N];

int s(int n,int m,int k){
    int tot=0;
    for(int t=0;t<=n;t++){
		int sum=0;
        for(int q=0;q<=k && q<=t;q++){
            gmod(sum+=1ll*C(n-k,t-q)*C(k,q)%mod*ID(k-q)%mod);
        }
		gmod(tot+=1ll*sum*ksm((2*t-n+mod)%mod,m)%mod);
    }
    return 1ll*tot*ksm(inv2,n)%mod;
}

signed main(){
    init(N-5);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x; scanf("%d",&x);
        F[x]++;
    }
    
    fwt_xor(F,1<<m);
    for(int mac=0;mac<(1<<m);mac++) G[mac]=1,H[mac]=1ll*F[mac]*F[mac]%mod;
    // for(int mac=0;mac<(1<<m);mac++) cout<<F[mac]<<" "; cout<<endl;
    
    for(int t=2;t<=24;t+=2){
        int tot=0;
        for(int mac=0;mac<(1<<m);mac++){
            G[mac]=1ll*G[mac]*H[mac]%mod;
            gmod(tot+=G[mac]);
            // cout<<mac<<" "<<g[mac]<<" "<<inv[t]<<endl;
        }
        f[t]=1ll*tot*ksm(inv2,m)%mod;
        
        // cout<<t<<" "<<tot<<endl;
        // if(tot>0) cout<<t<<endl;
    }
    f[0]=1;
    // for(int t=0;t<=24;t++) cout<<f[t]<<" "; cout<<endl;
    
    for(int k=0;k<=24;k+=2){
        g[k]=f[k];
        for(int i=0;i<k;i+=2){
            gmod(g[k]+=mod-1ll*g[i]*s(n,k,i)%mod*inv[i]%mod);
            
            // cout<<" "<<n<<" "<<k<<" "<<i<<": "<<s(n,k,i)<<endl;
        }
    }
    
    // for(int t=0;t<=24;t+=2) cout<<g[t]<<" "; cout<<endl;
    
    for(int t=2;t<=24;t+=2){
        if(g[t]){
            cout<<"Yes"<<endl<<t;
            return 0;
        }
    }
    printf("No");
}
