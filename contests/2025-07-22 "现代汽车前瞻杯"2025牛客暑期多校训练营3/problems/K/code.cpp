#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5500,mod=998244353;
 
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1;
    }
    return tot;
}
 
int mul[N],inv[N],invv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
     
    invv[0]=invv[1]=1;
    for(int i=2;i<=lim;i++) invv[i]=1ll*(mod-mod/i)*invv[mod%i]%mod;
}
 
void gmod(int &x){
    x%=mod;
}
 
int T,n;
int p[N];
int ban1[N],ban2[N],val[N],pos[N];
int sp[N],nxt[N];
int f[N][N],g[N][N];
 
signed main(){
    init(N-5);
     
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        for(int i=0;i<=n+1;i++){
            ban1[i]=ban2[i]=0;
            val[i]=pos[i]=0;
            sp[i]=nxt[i]=0;
            for(int j=0;j<=n+1;j++) f[i][j]=g[i][j]=0;
        }
         
        for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
        int mx=0; sp[0]=1;
        for(int i=1;i<=n;i++){
            if(!p[i]) continue;
            if(p[i]>mx) sp[i]=1,mx=p[i];
            else ban1[i]=1,ban2[p[i]]=1;
        }
        nxt[n+1]=n+1;
        for(int i=n;i>=1;i--){
            if(sp[i]) nxt[i]=i;
            else nxt[i]=nxt[i+1];
        }
        for(int i=n;i>=1;i--) pos[i]=pos[i+1]+(!ban1[i]);
        for(int i=n;i>=1;i--) val[i]=val[i+1]+(!ban2[i]);
         
        g[n+1][0]=1;
        for(int i=n;i>=1;i--){
            int x=p[i];
            // cout<<i<<" "<<x<<": "<<endl;
            if(!sp[i]){
                for(int j=0;j<=n;j++){
                    gmod(f[i][j]+=(f[i+1][j]+g[i+1][j])%mod);
                    if(!ban1[i]){
                        gmod(g[i][j+1]+=(f[i+1][j]+g[i+1][j])%mod*invv[i-1]%mod);
                    }
                }
            }
            else{
                // select
                for(int t=i+1;t<=nxt[i+1];t++){
                    if(val[x+1]<=pos[t]){
                        for(int j=0;j<=val[x+1];j++){
                            gmod(g[i][val[x]]+=g[t][j]*invv[i-1]%mod);
                        }
                    }
                }
                 
                // not select
                for(int j=0;j<val[x+1];j++){
                    gmod(f[i][j+1]+=(f[i+1][j]+g[i+1][j])%mod);
                }
            }
        }
         
        int ans=0;
        for(int j=0;j<=n;j++) gmod(ans+=g[1][j]);
        cout<<ans*mul[n-1]%mod<<endl;
    }
}
