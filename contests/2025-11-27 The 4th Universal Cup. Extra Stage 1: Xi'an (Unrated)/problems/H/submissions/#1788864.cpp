#include <bits/stdc++.h>
using namespace std;
const int N=1e7+50,M=1e4+50,mod=998244353;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1ll;
    }
    return tot;
}
void gmod(int &x){
    x%=mod;
}

int mul[N],inv[N];
int S2[M][M];
void init(int lim,int mlim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
    
    S2[0][0]=1;
    for(int i=1;i<=mlim;i++){
        for(int j=1;j<=i;j++) gmod(S2[i][j]=S2[i-1][j-1]+1ll*S2[i-1][j]*j%mod);
    }
}

int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return 1ll*mul[m]*inv[n]%mod*inv[m-n]%mod;
}
int ID(int x){
    return (x & 1)?mod-1:1;
}

int n,k;

int solve1(int n){
    int tot=0;
    for(int t=1;t<=n;t++){
        gmod(tot+=1ll*ksm(t,t-1)*inv[t]%mod*ksm(n,n-t)%mod*inv[n-t]%mod);
    }
    int ans=1ll*tot*mul[n-1]%mod;
    gmod(ans+=mod-((n==1)?1:ksm(n,n-2)));
    // cout<<tot<<endl;
    return ans;
}

int F[M],G[M],H[N];

int solve2(int n,int k){
    int lim=2*k+5;
    for(int i=1;i<=k;i++){
        for(int t=1;t+i<=lim;t++){
            int val=S2[t+i-2][t];
            if(i==1 && t==1) val++;
            gmod(F[t+i]+=1ll*inv[i]*val%mod);
        }
    }
    
    int deg=2*k;
    for(int t=0;t<=deg;t++){
        int val=1ll*ID(t)*C(deg,t)%mod;
        for(int i=1;t+i<=lim;i++){
            gmod(G[t+i]+=1ll*val*F[i]%mod);
        }
    }
    // for(int i=0;i<=lim;i++) cout<<G[i]<<" ";
    // cout<<endl;
    
    int d=deg-1;
    H[0]=1,H[1]=n+d;
    for(int i=1;i<n;i++){
        H[i+1]=(1ll*(H[i]+mod-H[i-1])%mod*n%mod+1ll*(d+i)*H[i]%mod)%mod*mul[i]%mod*inv[i+1]%mod;
    }
    
    int tot=0;
    for(int t=0;t<=lim;t++){
        gmod(tot+=1ll*H[n-t]*G[t]%mod);
        // for(int i=0;i<=n-t;i++)
        //     gmod(tot+=ksm(n,n-t-i)*inv[n-t-i]%mod*C(2*k-2+i,i)%mod*G[t]%mod);
    }
    
    return 1ll*tot*mul[n]%mod;
}

signed main(){
    // cout<<sizeof(S2)/1024/1024;
    // return 0;
    init(N-5,M-5);
    cin>>n>>k;
    if(k>=n) return cout<<0,0;
    
    int ans1=solve1(n);
    // cout<<ans1<<endl;
    
    int ans2=solve2(n,k-1);
    // cout<<ans2<<endl;
    
    cout<<(ans1+mod-ans2)%mod;
}
