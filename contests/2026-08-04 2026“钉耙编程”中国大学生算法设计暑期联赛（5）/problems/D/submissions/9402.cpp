#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
__int128 n,m,c;
int T;
__int128 w[N];
const int mo = 1e9+7;
const int mod = 1e9+7;


__int128 fpow(__int128 x,__int128  y){
    x%=mo;
    int ret=1;
    while(y){
        if(y&1) ret=ret*x%mod;
        x=x*x%mod; y>>=1;
    }
    return ret;
}

__int128 sm1,sm2,wsm,d,sm,ism,ismn;

void solve(){
    //cout << 861111120ll * 36 % mo << endl;
    scanf("%lld%lld%lld",&n,&m,&c);
    d=0;sm=0;
    sm1 = sm2 = wsm = d = sm = ism = ismn = 0;
    int ans=0;
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
        sm+=w[i];
        sm2 += w[i]*i;
    }
    wsm = sm;
    sm%=mo;
    //cout << (int)sm << endl;
    ism = fpow(sm,mo-2);
    ismn = fpow(ism,n);
    //cout << (int)ismn << endl;
    int j=0;
    for(int i=1;i<=m;i++){
        int pm = (fpow(sm1%mo,n)%mo+mo)%mo;
        sm1 += w[i];
        sm2 -= w[i]*i;
        int p = (fpow(sm1%mo,n)%mo+mo)%mo;
        
        if(wsm*(i+c) >= sm1*i + sm2){
            sm1 -= w[i];
            sm2 += w[i]*i;
            j=i;
            break;
        }
        ans += (p-pm+mo)%mo * (i-c*n%mo+mo)%mo;
        ans %= mo;
        //d+=w[i];d%=mo;
        //ans += fpow(d,n)*ismn%mo;
    }
    //cout << ans << endl;
    ans = ans*ismn%mo;
    //printf("ans=%lld,j=%lld\n",ans,j);
    //for(int i=j;i<=m;i++){
        //p+=w[i]*i;p%=mo;
        //ans ++;
        // ans += 1 - (sm2/sm1)
        //int p = (mo + fpow(wsm%mo,n) - fpow(sm1%mo,n))%mo;
        //p = p*ismn;
        __int128 p = (wsm-sm1)%mo*fpow(wsm,mo-2)%mo;
        p = (1-p+mo)%mo;
        p %= mo;
        __int128 val = ((sm2)%mo)%mo*fpow((wsm-sm1)%mo,mo-2)%mo;
        //printf("%lld %lld %lld %lld %lld\n",p,(int)sm2,(int)wsm,(int)sm1,val);
        //printf("%lld/%lld\n",(int)sm2,(int)(wsm-sm1)%mo);
        __int128 i1p = fpow((1-p+mo)%mo,mo-2);
        
        __int128 pp = (p-fpow(p,n+1)+mo)%mo * i1p%mo;
        
        ans += (val*pp%mo - (pp-n*fpow(p,n+1)%mo+mo)%mo * i1p % mo * c % mo + mo)%mo * fpow(p,mo-2) % mo * (1-p+mo)%mo;
        
        
        
        
        //ans += (val*p%mo*i1p%mo - c*p%mo*i1p%mo*i1p%mo+mo)%mo;
    //}
    ans %= mo;
    //cout << ans << endl;
    //ans = ans * ismn % mo;
    printf("%lld\n",ans);
}

signed main(){
    //frc[0]=1;
    //for(int i=1; i<N; ++i) frc[i]=frc[i-1]*i%mod;
    //inv[N-1]=fpow(frc[N-1], mod-2);
    //for(int i=N-2; i>=0; --i) inv[i]=inv[i+1]*(i+1)%mod;
    cin>>T;
    while(T--){
        solve();
        
    }
    
}