#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,k;
int c[N];

vector <int> G[N];

struct abc{
    int u,x,d;
};
queue <abc> q;
bool vis[N][N];

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    int ans=0;
    for(int st=1;st<=n;st++){
        for(int i=1;i<=n;i++)
            for(int j=0;j<=k;j++)
                vis[i][j]=0;
        while(q.size()) q.pop();
        
        q.push({st,0,0});
        vis[st][0]=1;
        while(q.size()){
            abc tmp=q.front(); q.pop();
            int u=tmp.u,x=tmp.x,d=tmp.d;
            ans=max(ans,d);
            // cout<<" "<<u<<" "<<x<<" "<<d<<endl;
            
            if(x>0){
                if(!vis[u][x-1]){
                    q.push({u,x-1,d+1});
                    vis[u][x-1]=1;
                }
            }
            if(x<k){
                if(!vis[u][x+1]){
                    q.push({u,x+1,d+1});
                    vis[u][x+1]=1;
                }
            }
            
            for(int v: G[u]){
                int nx=(c[u]==c[v])?x:k-x;
                if(!vis[v][nx]){
                    q.push({v,nx,d+1});
                    vis[v][nx]=1;
                }
            }
            
        }
    }
    
    cout<<ans;
}
