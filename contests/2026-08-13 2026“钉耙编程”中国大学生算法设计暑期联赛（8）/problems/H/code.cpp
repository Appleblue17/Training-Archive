#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=2200,INF=1e9;

int T,n,ans1,ans2;
vector <int> G[N];

int rd(){
    int tot=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}

int deg[N];


int fat[N][N],siz[N][N];
vector <pair<int,int> > V[N];

int RT;
void dfs0(int u,int fa,int dep){
    fat[RT][u]=fa;
    siz[RT][u]=1;
    V[dep].push_back({RT,u});
    
    for(int v: G[u]){
        if(v==fa) continue;
        dfs0(v,u,dep+1);
        siz[RT][u]+=siz[RT][v];
    }
}


int dp[N][N];

int S2(int n){
    return n*(n+1)/2;
}

signed main(){
    T=rd();
    while(T--){
        n=rd();
        for(int i=1;i<=n;i++) G[i].clear(),deg[i]=0;
        for(int i=0;i<=n;i++) V[i].clear();
        ans1=ans2=-INF;
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                dp[i][j]=-INF;
                fat[i][j]=siz[i][j]=0;
            }
        
        for(int i=1;i<n;i++){
            int u=rd(),v=rd();
            G[u].push_back(v);
            G[v].push_back(u);
            deg[u]++,deg[v]++;
        }
        int cnt=0;
        for(int i=1;i<=n;i++) cnt+=(deg[i]==1);
        if(cnt==2) ans1=2*n-1;
        else ans1=n+1;
        
        for(int u=1;u<=n;u++){
            RT=u;
            dfs0(u,0,0);
            
            int tot=S2(n);
            for(int v: G[u]) tot-=S2(siz[u][v]);
            dp[u][u]=tot;
            // cout<<u<<" "<<u<<": "<<dp[u][u]<<endl;
        }
        
        for(int t=1;t<n;t++){
            for(auto e: V[t]){
                int x=e.first,y=e.second;
                int nx=fat[y][x],ny=fat[x][y];
                dp[x][y]=dp[y][x]=max(dp[nx][y],dp[x][ny])+siz[x][y]*siz[y][x];
                ans2=max(ans2,dp[x][y]);
                
                // cout<<x<<" "<<y<<": "<<dp[x][y]<<endl;
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
}