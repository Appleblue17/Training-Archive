// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define MP make_pair
const int N=1e6+5,mo=1e9+7;

typedef long long ll;

ll ksm(ll a,ll b){
    ll ret=1,base=a;
    while(b>0){
        if(b&1)ret = ret*base%mo;
        base = base*base%mo;
        b/=2;
    }
    return ret%mo;
}


ll n,m,f[N],a[N],mxl[N],lb,pre[N],sm[N];

inline void read(ll &x){
    x=0; char c=getchar();
    bool flag=0;
    if(c=='-') flag=1;
    while(c<'0'||c>'9') {
        c=getchar();
        if(c=='-') flag=1;
    }
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c-'0'), c=getchar();
    if(flag) x=-x;
}

void solve(){
    read(n);read(m);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
    for(int i=0;i<=n;i++){
        mxl[i]=0;
        f[i]=0;
    }
    f[0]=1;
    for(int i=1;i<=m;i++){
        ll l,r;
        read(l);read(r);
        mxl[r] = max(mxl[r],l);
    }
    //for(int i=1;i<=n;i++){
    //    printf("mxl[%d]=%lld\n",i,mxl[i]);fflush(stdout);
    //}
    lb=0;pre[0]=1;
    ll inv10 = ksm(10,mo-2);
    //cout << inv10 << endl;
    sm[0]=1;
    for(int i=1;i<=n;i++){
        
        if(lb == 0)f[i]=sm[i-1]*a[i]%mo;
        else f[i]=((sm[i-1]-sm[lb-1]*pre[i-1]%mo*ksm(pre[lb-1],mo-2)%mo+mo)%mo)*a[i]% mo;
        
        if(a[i]==10){
            lb = i;
            pre[i-1]=0;
            pre[i]=1;
            sm[i] = sm[i-1]*(10-a[i])+f[i];
            sm[i]%=mo;
            continue;
        }
        
        pre[i] = pre[i-1] * (10-a[i])%mo;
        
        lb = max(lb,mxl[i]);
        sm[i] = sm[i-1]*(10-a[i])+f[i];
        sm[i]%=mo;
        
        /*while(mxl[i] > lb){
            lb++;
            sm -= f[lb-1]*pre[i]%mo*ksm(pre[lb-1],mo-2)%mo;
            sm = (sm+mo)%mo;
        }
        sm %= mo;*/
        
        
        
        
        //printf("i=%d,f=%lld,sm=%lld,pre=%lld\n",i,f[i],sm[i],pre[i]);
    }
    
    ll ans=((sm[n]-sm[lb-1]*pre[n]%mo*ksm(pre[lb-1],mo-2)%mo+mo)%mo);
    //cout << ans << endl;
    for(int i=1;i<=n;i++)ans = ans*inv10%mo;
    printf("%lld\n",ans%mo);
}

signed main(){
    //freopen("I.in","r",stdin);
    //freopen("I.out","w",stdout);
    ll T;
    read(T);
    while(T--){solve();}
}