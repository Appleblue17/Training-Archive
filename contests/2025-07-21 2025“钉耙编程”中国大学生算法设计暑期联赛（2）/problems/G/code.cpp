#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5500,mod=1e9+7;
int T,n,R;
int a[N];

void gmod(int &x){
    x%=mod;
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
int invv[N];
void init(int lim){
    invv[1]=1;
    for(int i=2;i<=lim;i++) invv[i]=(mod-mod/i)*invv[mod%i]%mod;
}
int ID(int x){
    return (x & 1ll)?mod-1:1;
}

int f[N],g[N][N];

signed main(){
    init(N-5);
    
    cin>>T;
    while(T--){
        scanf("%lld%lld",&n,&R);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=n-1;i>=1;i--){
            a[i]=max(a[i],a[i+1]);
        }
        
        for(int i=1;i<=n;i++){
            int tot=1;
            for(int l=1;l<=n+i-1;l++){
                tot=tot*(R-a[i]-l+2)%mod;
                tot=tot*invv[l]%mod;
                g[i][i+l-1]=tot;
                // cout<<i<<" "<<l<<": "<<tot<<endl;
            }
        }
        
        f[0]=1;
        for(int i=1;i<=n;i++){
            f[i]=0;
            for(int j=0;j<i;j++){
                gmod(f[i]+=f[j]*g[j+1][i]%mod*ID(i-j+1)%mod);
            }
            // cout<<f[i]<<" ";
        }
        printf("%lld\n",f[n]);
    }
}