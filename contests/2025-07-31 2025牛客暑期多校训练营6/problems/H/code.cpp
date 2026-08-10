#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1550,M=7e6+5,mod=998244353,inv2=(mod+1)/2;
 
int n,V,mx;
int W[N];
 
int f[M];
 
struct abc{
    int v,w;
}p[N];
int id;
bool operator <(abc X,abc Y){
    return X.w*Y.v>Y.w*X.v;
}
 
 
signed main(){
    // freopen("1.txt","w",stdout);
     
    scanf("%lld%lld",&n,&V);
    for(int i=1;i<=n;i++){
        int a,b; scanf("%lld%lld",&a,&b);
        W[a]=max(W[a],b);
        mx=max(mx,a);
    }
    for(int i=1;i<=mx;i++){
        if(W[i]) p[++id]={i,W[i]};
    }
    sort(p+1,p+id+1);
     
    int nw=id,cur;
    for(int i=1;nw>1 && i<=V;i++){
        cur=i;
        f[i]=f[i-1];
         
        while(nw>1 && i>mx*mx/(nw-1)) nw--;
        for(int t=1;t<=nw;t++){
            if(i>=p[t].v) f[i]=max(f[i],f[i-p[t].v]+p[t].w);
        }
        // cout<<i<<" "<<f[i]<<endl;
    }
    // cout<<cur<<endl;
     
    int tot=0;
    for(int i=1;i<=cur;i++) tot=(tot+f[i])%mod;
    if(V==cur){
        cout<<tot;
    }
    else{
        int v0=p[1].v,w0=p[1].w%mod;
        for(int i=cur;i>cur-v0;i--){
            int c=(V-i)/v0%mod;
            tot=(tot+f[i]%mod*c%mod+c*(c+1)%mod*inv2%mod*w0%mod)%mod;
            // f[i]*c + c(c+1)/2*w0;
        }
        cout<<tot;
    }
     
}
