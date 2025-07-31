#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2100000,INF=1e9,mod=1e9+7,mo=mod;
typedef long long ll;
int T,n;
int a[N];
int typ[4];
inline void read(int &x){
    x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48), c=getchar();
}

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1ll;
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

void solve(){
    ll ans=0;
    ll A,B,C,D;
    A=typ[0];B=typ[1];C=typ[2];D=typ[3];
    //printf("type = %lld %lld %lld %lld\n",A,B,C,D);
    if(C==D && C==0){
        if((B)%2==1){
            printf("%lld\n",mul[n]%mod);
        }
        else{
            printf("0\n");
        }
        return;
    }
    if(C != 0){
        for(int t=1;t<=B;t+=2){
            ans += mul[B-t+C-1+D]*inv[B-t]%mo*inv[C-1]%mo*inv[D]%mo*mul[n]%mo*inv[A]%mo*inv[B+C+D]%mo*mul[A]%mo*mul[B]%mo*mul[C]%mo*mul[D]%mo;
        }
    }
    if(D != 0){
        for(int t=0;t<=B;t+=2){
            ans += mul[B-t+D-1+C]*inv[B-t]%mo*inv[D-1]%mo*inv[C]%mo*mul[n]%mo*inv[A]%mo*inv[B+C+D]%mo*mul[A]%mo*mul[B]%mo*mul[C]%mo*mul[D]%mo;
            //printf("ans += %lld\n",mul[B-t+D-1+C]*inv[B-t]%mo*inv[D-1]%mo*inv[C]%mo*mul[n]%mo*inv[A]%mo*inv[B+C+D]%mo*mul[A]*mul[B]*mul[C]*mul[D]);
        }
    }
    ans %= mo;
    printf("%lld\n",ans);
}

signed main(){
    init(N-5);
    
    int T;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        typ[0]=typ[1]=typ[2]=typ[3]=0;
        for(int i=1;i<=n;i++){
            int k;
            read(k);
            //cout << k << endl;
            int nimsum=0;
            bool isall1=1;
            for(int j=1;j<=k;j++){
                read(a[j]);
                if(a[j]!=1)isall1=0;
                nimsum ^= a[j];
            }
            bool nim=(nimsum!=0);
            bool renim=1;
            if(isall1 && nimsum==0)renim=0;
            if(!isall1 && nimsum!=0)renim=0;
            int tp=0;
            if(renim && nim)tp=1;
            if(renim==0 && nim==0)tp=0;
            if(renim==1 && nim==0)tp=2;
            if(renim==0 && nim==1)tp=3;
            typ[tp]++;
            //cout << i << ' ' << tp << endl;
        }
        
        solve();

    }
    
}