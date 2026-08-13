#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+5,mod=998244353;

int T,n;
int a[N];


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


int rd(){
    int tot=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}

bool vis[N];
vector <int> V,P;

signed main(){
    init(N-5);
    
    T=rd();
    while(T--){
        n=rd();
        for(int i=1;i<=n*2;i++) a[i]=rd(),vis[i]=0;
        V.clear(); P.clear();
        
        for(int i=1;i<=n*2;i+=2){
            if(a[i] && a[i+1]) vis[a[i]]=vis[a[i+1]]=1;
            else if(a[i]) V.push_back(a[i]);
            else if(a[i+1]) V.push_back(a[i+1]);
        }
        
        for(int i=1;i<=n*2;i++) if(!vis[i]) P.push_back(i);
        sort(P.begin(),P.end());
        int m=P.size()/2;
        int x=0,y=0;
        for(int t: V){
            if(t<=P[m-1]) x++;
            else y++;
        }
        
        int d=m-x-y;
        int ans=0;
        if(d>=0) ans=mul[x]*mul[y]%mod*C(m-y,x)%mod*C(m-x,y)%mod*mul[d]%mod*mul[d]%mod*ksm(2,d)%mod;
        printf("%lld\n",ans);
    }
    
    
}