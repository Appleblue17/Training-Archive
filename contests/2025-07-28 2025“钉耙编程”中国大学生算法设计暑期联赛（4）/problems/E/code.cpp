#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=330,mod=998244353,INF=1e9;
int T,n,m,rt;
char S[N];
bool vis[N];

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
void gmod(int &x){
    x%=mod;
}


vector<int> G[N];
int sz[N],siz[N],sonx[N];

void dfs(int u){
    siz[u]=1;
    for(int v: G[u]){
        dfs(v);
        siz[u]+=siz[v];
        sonx[u]+=(siz[v]==1);
    }
}

int p[N],pid;
bool buc[N];

int dp[N][N];

signed main(){
    init(N-5);
    
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        scanf("%s",S+1);
        m=strlen(S+1);
        
        for(int i=1;i<=n;i++){
            G[i].clear(),vis[i]=0;
            sz[i]=siz[i]=sonx[i]=0;
        }
        
        for(int i=1;i<=n;i++){
            scanf("%lld",&sz[i]);
            for(int j=1;j<=sz[i];j++){
                int x; scanf("%lld",&x);
                vis[x]=1;
                G[i].push_back(x);
            }
        }
        if(n==1){
            printf("1\n");
            continue;
        }
        
        for(int i=1;i<=n;i++) if(!vis[i]) rt=i;
        // cout<<"rt = "<<rt<<endl;
        dfs(rt);
        
        pid=0;
        for(int i=1;i<=m;i++){
            if(S[i]=='D') p[++pid]=i;
        }
        p[pid+1]=m+1;
        
        memset(dp,0,sizeof(dp));
        
        dp[1][rt]=1;
        for(int i=1;i<=pid;i++){
            // cout<<i<<": ";
            // for(int u=1;u<=n;u++) cout<<dp[i][u]<<" "; cout<<endl;
            
            for(int u=1;u<=n;u++){
                if(!dp[i][u]) continue;
                int x=sonx[u],y=sz[u]-x;
                // cout<<" start "<<u<<" "<<x<<" "<<y<<endl;
                
                for(int t=1;t<=sz[u];t++) buc[t]=0;
                
                int nw=1,k=0;
                for(int j=i+1;j<=pid+1;j++){
                    for(int t=p[j-1]+1;t<=p[j]-1;t++){
                        if(S[t]=='L') nw=max(nw-1,1ll);
                        else nw=min(nw+1,sz[u]);
                    }
                    if(j<=pid){
                        if(!buc[nw]){
                            // cout<<"  "<<i<<" "<<j<<": "<<sz[u]<<", "<<nw<<" "<<k<<endl;
                            
                            for(int v: G[u]){
                                if(siz[v]>1){
                                    int tot=C(x-k+y-1,x-k)*mul[x]%mod*mul[y-1]%mod*inv[x+y]%mod;
                                    // cout<<"      "<<v<<": "<<tot<<endl;
                                    gmod(dp[j][v]+=dp[i][u]*tot%mod);
                                }
                            }
                            
                            k++;
                            buc[nw]=1;
                        }
                    }
                    else{
                        // cout<<"  "<<i<<" "<<j<<": "<<sz[u]<<", "<<nw<<" "<<k<<endl;
                        for(int v: G[u]){
                            if(buc[nw] && siz[v]==1){
                                int tot=C(x-k+y,x-k)*mul[x-1]%mod*mul[y]%mod*inv[x+y]%mod;
                                // cout<<"    > "<<v<<": "<<tot<<"  "<<x<<" "<<y<<" "<<k<<endl;
                                gmod(dp[j][v]+=dp[i][u]*tot%mod);
                            }
                            if(!buc[nw]){
                                if(siz[v]!=1){
                                    int tot=C(x-k+y-1,x-k)*mul[x]%mod*mul[y-1]%mod*inv[x+y]%mod;
                                    // cout<<"    > "<<v<<": "<<tot<<endl;
                                    gmod(dp[j][v]+=dp[i][u]*tot%mod);
                                }
                                else{
                                    int tot=C(x-k-1+y,x-k-1)*mul[x-1]%mod*mul[y]%mod*inv[x+y]%mod;
                                    // cout<<"    > "<<v<<": "<<tot<<endl;
                                    gmod(dp[j][v]+=dp[i][u]*tot%mod);
                                }
                            }
                        }
                    }
                    
                }
            }
        }
        
        int ans=0;
        for(int u=1;u<=n;u++){
            // cout<<dp[pid+1][u]<<" ";
            gmod(ans+=dp[pid+1][u]*u%mod);
        }
        // cout<<endl;
        printf("%lld\n",ans);
        
    }
}