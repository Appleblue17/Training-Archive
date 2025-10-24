#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=330,INF=1e18;
int T,n,sn;
int a[N];
vector <int> G[N];

int dp[N][N][N];

void gmax(int &x,int y){
    x=max(x,y);
}

bool inside[N][N][N];
int ins[N][N];
int X,Y,FL;
vector <int> V;
void dfs(int u,int fa){
    if(u==Y){
        FL=1;
        return ;
    }
    if(u<=sn) V.push_back(u);
    for(int v: G[u]){
        if(v==fa) continue;
        dfs(v,u);
    }
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n; n++;
        for(int i=1;i<n;i++) scanf("%lld",&a[i]);
        
        for(int i=1;i<n;i++){
            int u,v; scanf("%lld%lld",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        sn=n;
        for(int i=1;i<=sn;i++){
            if(G[i].size()==1){
                n++;
                G[i].push_back(n);
                // cout<<" add "<<i<<" "<<n<<endl;
            }
        }
        for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++){
                ins[x][y]=0;
                for(int t=1;t<=n;t++) inside[x][y][t]=0;
            }
        }
        
        for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++){
                if(x==y) continue;
                X=x,Y=y;
                // cout<<x<<" "<<y<<": ";
                for(int u: G[x]){
                    FL=0;
                    V.clear();
                    dfs(u,x);
                    if(FL){
                        for(int t: V) inside[x][y][t]=1;
                        // for(int t: V) cout<<t<<" ";
                        ins[x][y]=V.size();
                        break;
                    }
                }
                // cout<<endl;
            }
        }
        
        for(int t=0;t<=sn;t++){
            for(int x=1;x<=n;x++){
                for(int y=1;y<=n;y++){
                    dp[t][x][y]=-INF;
                }
            }
        }
        
        for(int u=1;u<=n;u++){
            for(int x: G[u]){
                for(int y: G[u]){
                    if(x==y) continue;
                    dp[0][x][y]=0;
                }
            }
        }
        
        int ans=0;
        for(int t=0;t<=sn;t++){
            // cout<<t<<": "<<endl;
            for(int x=1;x<=n;x++){
                for(int y=1;y<=n;y++){
                    if(dp[t][x][y]<0) continue;
                    // cout<<"  "<<t<<" "<<x<<" "<<y<<": "<<dp[t][x][y]<<endl;
                    ans=max(ans,dp[t][x][y]);
                    gmax(dp[t+1][x][y],dp[t][x][y]);
                    
                    for(int u: G[x]){
                        if(inside[x][y][u]) continue;
                        int sum=ins[x][y];
                        if(t<=sum){
                            gmax(dp[t+1][u][y],dp[t][x][y]+a[t]);
                        }
                    }
                    for(int u: G[y]){
                        if(inside[x][y][u]) continue;
                        int sum=ins[x][y];
                        if(t<=sum){
                            gmax(dp[t+1][x][u],dp[t][x][y]+a[t]);
                        }
                    }
                    
                }
            }
        }
        for(int i=1;i<=n;i++) G[i].clear();
        cout<<ans<<endl;
    }
    
}
