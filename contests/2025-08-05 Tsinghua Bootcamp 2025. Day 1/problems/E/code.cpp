#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5, INF=1e9;
int n, m;
vector<int> e[N], G[N];
int dfn[N], low[N], timer, stk[N], top;
int idx=0;
int sz[N];
void tarjan(int x, int fa){
    dfn[x]=low[x]=++timer; stk[++top]=x;
    for(auto y:e[x]){
        if(y==fa) continue;
        if(!dfn[y]){
            tarjan(y, x);
            low[x]=min(low[x], low[y]);
            if(low[y]>=dfn[x]){
                ++idx;
                // cout<<idx<<": ";
                int z;
                do{
                    z=stk[top--];
                    G[idx].push_back(z);
                    G[z].push_back(idx);
                    sz[idx]++;
                    // cout<<z<<" ";
                }while(z!=y);
                G[idx].push_back(x);
                G[x].push_back(idx);
                // cout<<x<<endl;
                sz[idx]++;
            }
        }
        else if(dfn[y]<dfn[x]){
            low[x]=min(low[x], dfn[y]);
        }
    }
}

int f[N],g[N];
int dp[N][2][2];

void dfs(int u,int fa){
    bool fl=1;
    for(int v: G[u]){
        if(v==fa) continue;
        dfs(v,u);
        fl=0;
    }
    if(u<=n){
        g[u]++;
        // cout<<u<<": "<<f[u]<<" "<<g[u]<<endl;
        return ;
    }
    // cout<<"proc "<<u<<endl;
    
    for(int F=0;F<=1;F++){
        for(int t=0;t<=1;t++)
            for(int i=0;i<=1;i++)
                dp[0][t][i]=INF;
        dp[0][0][F]=0;
        
        int id=0;
        for(int v: G[u]){
            if(v==fa) continue;
            id++;
            
            for(int t=0;t<=1;t++)
                for(int i=0;i<=1;i++)
                    dp[id][t][i]=INF;
            
            for(int t=0;t<=1;t++){
                dp[id][t][0]=min(dp[id][t][0],min(dp[id-1][t][0],dp[id-1][t][1])+f[v]);
                dp[id][1][1]=min(dp[id][1][1],dp[id-1][t][0]+g[v]);
            }
        }
        
        if(F) dp[id][0][1]=dp[id][1][1]=INF;
        if(!F && sz[u]%2==1) dp[id][0][0]=dp[id][0][1]=INF;
        
        int tot=INF;
        for(int t=0;t<=1;t++)
            for(int i=0;i<=1;i++)
                tot=min(tot,dp[id][t][i]);
        
        if(!F) f[fa]+=tot;
        else g[fa]+=tot;
    }
    // cout<<" -> "<<fa<<" "<<f[fa]<<" "<<g[fa]<<endl;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1, x, y; i<=m; ++i){
        scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    if(n==1){
        printf("0\n");
        return 0;
    }
    idx=n;
    tarjan(1, 0);
    
    dfs(1,0);
    cout<<min(f[1],g[1]);
}