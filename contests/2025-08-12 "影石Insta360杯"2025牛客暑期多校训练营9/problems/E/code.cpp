#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define int long long
const int N=1e5+5,M=5e6+5,K=220,mod=998244353;
 
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}
 
int mul[M],inv[M],invv[M];
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
int ID(int x){
    return (x & 1)?mod-1:1;
}
void gmod(int &x){
    x%=mod;
}
 
void no(){
    cout<<0;
    exit(0);
}
 
int k,n,m;
pair <int,int> p[N],q[N];
map <int,int> mp,mq;
 
int X[N],Y[N];
 
int dp[K][K][K];
void pre(int m,int n,int k){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[k][i][j]=0;
        }
    }
    dp[k][0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            int val=dp[k][i][j];
            if(!val) continue;
            gmod(dp[k][i][j+1]+=val);
            gmod(dp[k][i+1][j]+=1ll*val*(j+k-i)%mod);
        }
    }
}
 
 
int cal(int m,int n,int x){
    if(x<=n) return dp[x][n][m];
    int alc=mul[x]*inv[x-n-1]%mod;
    // cout<<"OK"<<endl;
     
    int tot=0;
    for(int i=0;i<=n;i++){
        int y=dp[i][n][m];
        gmod(tot+=1ll*y*alc%mod*invv[x-i]%mod*inv[n-i]%mod*inv[i]%mod*ID(n-i)%mod);
    }
    return tot;
}
 
signed main() {
    init(M-5);
    scanf("%lld%lld%lld",&k,&n,&m);
     
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        p[i]=MP(x,y);
    }
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%lld%lld",&x,&y); x++;
        q[i]=MP(x,y);
    }
    sort(p+1,p+n+1);
    sort(q+1,q+m+1);
     
    for(int i=1;i<=n;i++) mp[p[i].first]=i;
    for(int i=1;i<=m;i++) mq[q[i].first]=i;
     
    for(int t=m;t>=1;t--){
        if(!q[t].second) continue;
         
        int pos=q[t].first;
        while(1){
            int x=mp[pos],y=mq[pos];
            // cout<<" "<<pos<<" "<<x<<" "<<y<<endl;
            if(x){
                q[y].second-=p[x].second;
                if(q[y].second<0) no();
                X[x]+=p[x].second;
                p[x].second=0;
            }
             
            if(!q[y].second) break;
            int z=mp[pos-2];
            if(!z) no();
             
            p[z].second-=q[y].second;
            if(p[z].second<0) no();
            Y[z]+=q[y].second;
            q[y].second=0;
            pos-=2;
        }
    }
     
    // for(int i=1;i<=n;i++) cout<<p[i].first<<" "<<p[i].second<<": "<<X[i]<<" "<<Y[i]<<endl;
     
    int lim=200;
    for(int i=0;i<=lim;i++) pre(lim,lim,i);
     
    int k=0,ans=1;
    for(int i=1;i<=n;i++){
        if(k<0) no();
        int ret=cal(Y[i],X[i],k);
        // cout<<X[i]<<" "<<Y[i]<<" "<<k<<": "<<ret<<endl;
        ans=1ll*ans*ret%mod;
        k+=Y[i]-X[i];
    }
    cout<<ans;
}
