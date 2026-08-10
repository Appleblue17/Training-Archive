#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5.1e5+5,mod=998244353;
 
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
int invv[N];
 
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
     
    invv[1]=1;
    for(int i=2;i<=lim;i++) invv[i]=(mod-mod/i)*invv[mod%i]%mod;
}
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return mul[m]*inv[n]%mod*inv[m-n]%mod;
}
void gmod(int &x){
    x%=mod;
}
 
 
int T,n,a[N][2],nxt[N][2];

void solve(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        nxt[i][0]=nxt[i][1]=0;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i][0]);
        //cout << a[i][0] << endl;
        if(i>1){
            nxt[a[i-1][0]][0]=a[i][0];
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i][0]);
        if(i>1){
            nxt[a[i-1][0]][1]=a[i][0];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(nxt[i][0] != nxt[i][1] || (nxt[i][0]==0) || (nxt[i][1]==0))ans++;
    }
    printf("%lld\n",ans);
}

signed main() {
    scanf("%lld",&T);
     while(T--)solve();
}