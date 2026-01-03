#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,INF=1e9;
int n,a[N],ans;
vector <int> G[N];
bool vis[N];

stack <int> sta;
int p[N],id;


int f[N][2];
void dfs(int u,int fa){
    vis[u]=1;
    f[u][1]=1;
    for(int v: G[u]){
        if(v==fa) continue;
        dfs(v,u);
        f[u][0]+=max(f[v][0],f[v][1]);
        f[u][1]+=f[v][0];
    }
}
int g[N][2];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        
        G[a[i]].push_back(i);
    }
    
    for(int u=1;u<=n;u++){
        if(vis[u]) continue;
        while(sta.size()) sta.pop();
        
        int x=u;
        do{
            sta.push(x);
            vis[x]=1;
            
            x=a[x];
        }while(!vis[x]);
        
        id=0;
        while(!sta.empty()){
            p[id++]=sta.top();
            if(sta.top()==x) break;
            sta.pop();
        }
        
        // for(int i=0;i<id;i++) cout<<p[i]<<" "; cout<<endl;
        
        for(int i=0;i<id;i++){
            dfs(p[i],p[(i+1)%id]);
            // cout<<p[i]<<": "<<f[p[i]][0]<<" "<<f[p[i]][1]<<endl;
        }
        
        
        int tot=0;
        for(int t=0;t<=1;t++){
            if(!t) g[0][0]=f[p[0]][0],g[0][1]=-INF;
            else g[0][0]=-INF,g[0][1]=f[p[0]][1];
            
            for(int i=1;i<id;i++){
                g[i][0]=f[p[i]][0]+max(g[i-1][0],g[i-1][1]);
                g[i][1]=f[p[i]][1]+g[i-1][0];
            }
            
            if(!t) tot=max(tot,max(g[id-1][0],g[id-1][1]));
            else tot=max(tot,g[id-1][0]);
        }
        
        ans+=tot;
    }
    
    cout<<ans;
}
