#include <bits/stdc++.h>
using namespace std;
const int N=6600,mod=998244353;

int n,m;
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1;
    }
    return tot;
}

vector <int> G[N];
int dp[2][N],id;
void gmod(int &x){
    x%=mod;
}
int invv[N];
void init(int lim){
    invv[1]=1;
    for(int i=2;i<=lim;i++) invv[i]=1ll*(mod-mod/i)*invv[mod%i]%mod;
}

namespace BM{
    int n,m,a[N];
    int nw[N],lennw,posnw;
    int lst[N],lenlst,poslst;
    int tmp[N],lentmp,postmp;
    
    void solve(int *s,int &len,int *a,int n){
        lst[1]=1,lenlst=1;
        for(int i=1;i<=n;i++){
            int delta=a[i];
            for(int j=1;j<=lennw;j++) delta=(delta+mod-1ll*a[i-j]*nw[j]%mod)%mod;
            int iinvd=ksm(delta,mod-2);
            if(!delta) continue;
            
            lentmp=lennw+1,postmp=i;
            tmp[1]=iinvd;
            for(int j=2;j<=lentmp;j++) tmp[j]=1ll*nw[j-1]*(mod-iinvd)%mod;
            
            int dpos=i-poslst-1;
            lennw=max(lennw,lenlst+dpos);
            for(int j=1;j<=lenlst;j++)
                nw[j+dpos]=(nw[j+dpos]+1ll*lst[j]*delta%mod)%mod;
            
            if(lentmp-postmp<lenlst-poslst){
                swap(lentmp,lenlst),swap(postmp,poslst);
                swap(tmp,lst);
            }
        }
        len=lennw;
        for(int i=1;i<=lennw;i++) s[i]=nw[i];
    } 
}

int f[N],len;
int P[N],Q[N],R[N];

signed main(){
    init(N-5);
    
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dp[0][1]=1;
    for(int t=0;t<=n*2;t++){
        f[t]=dp[id][n];
        for(int i=1;i<=n;i++) dp[id^1][i]=0;
        for(int u=1;u<n;u++){
            for(int v: G[u]){
                gmod(dp[id^1][v]+=1ll*dp[id][u]*invv[G[u].size()]%mod);
            }
        }
        id^=1;
    }
    
    // for(int i=1;i<=n*2;i++) cout<<f[i]<<" "; cout<<endl;
    BM::solve(Q,len,f,n*2);
    
    // cout<<len<<endl;
    // for(int i=1;i<=len;i++) cout<<Q[i]<<" "; cout<<endl;
    
    R[0]=1;
    for(int i=1;i<=len;i++) R[i]=(mod-Q[i])%mod;
    for(int i=0;i<=len;i++){
        for(int j=0;j<=len;j++){
            gmod(P[i+j]+=1ll*f[i]*R[j]%mod);
        }
    }
    // for(int i=0;i<=len;i++) cout<<P[i]<<" "; cout<<endl;
    // for(int i=0;i<=len;i++) cout<<R[i]<<" "; cout<<endl;
    
    int sumP=0,sumPp=0;
    int sumR=0,sumRp=0;
    for(int i=0;i<=len;i++){
        gmod(sumP+=P[i]);
        gmod(sumPp+=1ll*i*P[i]%mod);
    }
    for(int i=0;i<=len;i++){
        gmod(sumR+=R[i]);
        gmod(sumRp+=1ll*i*R[i]%mod);
    }
    // cout<<sumP<<" "<<sumPp<<" "<<sumR<<" "<<sumRp<<endl;
    int ans=1ll*(1ll*sumPp*sumR%mod+mod-1ll*sumP*sumRp%mod)%mod*ksm(1ll*sumR*sumR%mod,mod-2)%mod;
    cout<<ans;
}
