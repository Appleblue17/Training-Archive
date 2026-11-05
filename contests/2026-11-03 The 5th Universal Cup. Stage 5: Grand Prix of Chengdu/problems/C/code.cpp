#include<bits/stdc++.h>
// #define int long long
using namespace std;
const int N=102,mod=998244353;

int T,n,m;
int p[N],v[N];


int dp[N][N][N*N];
void gmod(int &x){
    if(x>=mod) x-=mod;
}

int f[N][N];

int solve(){
    f[0][0]=1;
    int L=0,R=0;
    for(int i=1;i<=m;i++){
        if(p[i]==1 && v[i]) return 0;
        
        
        int d=p[i]-p[i-1],s=v[i]-v[i-1];
        
        while(d*L+d*(d+1)/2<s) L++;
        while(d*R>s) R--;
        
        for(int j=L;j<=R+d;j++) f[i][j]=0;
        
        for(int x=L;x<=R;x++){
            int r=s-d*x;
            if(r<0) continue;
            for(int j=0;j<=d;j++){
                gmod(f[i][x+j]+=1ll*f[i-1][x]*dp[d][j][r]%mod);
                // cout<<i-1<<","<<x<<" -> "<<i<<","<<x+j<<"  * "<<dp[d][j][r]<<endl;
                // cout<<"     "<<d<<" "<<j<<" "<<r<<endl;
            }
        }
        R+=d;
    }
    int ans=0;
    for(int x=L;x<=R;x++) gmod(ans+=f[m][x]);
    for(int i=1;i<=n-p[m];i++) ans=ans*2%mod;
    return ans;
}

signed main(){
    int lim=100;
    dp[0][0][0]=1;
    for(int i=1;i<=lim;i++){
        for(int t=0;t<i;t++){
            for(int j=0;j<=i*(i-1)/2;j++){
                int val=dp[i-1][t][j];
                gmod(dp[i][t][j]+=val);
                gmod(dp[i][t+1][j+i]+=val);
            }
        }
    }
    
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);
        p[0]=1,v[0]=0;
        for(int i=1;i<=m;i++) scanf("%d%d",&p[i],&v[i]);
        
        int ans=solve();
        printf("%d\n",ans);
    }
}