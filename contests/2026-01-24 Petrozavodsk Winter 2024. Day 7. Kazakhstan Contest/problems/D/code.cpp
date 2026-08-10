#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=220,INF=1e9;

int T,n,m;
int col[N];
int trans[4][N];

struct nod{
    int to,nxt,w;
}e[N*N*2];
int head[N],cnt;
void add(int u,int v,int w){
    e[++cnt]={v,head[u],w};
    head[u]=cnt;
}

int dis[N],pre[N];
bool vis[N];
priority_queue < pair<int,int> > que;

bool bucc[4];


int ID(int x,int y){
    return (x-1)*n+y;
}
vector <int> G[N*N];
bool vs[N*N];


void dfs(int u){
    if(vs[u]) return ;
    vs[u]=1;
    for(int v: G[u]) dfs(v);
}

bool solve(){
    for(int c=0;c<4;c++){
        if(!bucc[c]) continue;
        for(int u=1;u<=n;u++){
            trans[c][u]=0;
            dis[u]=INF; pre[u]=0;
            vis[u]=0;
        }
        for(int u=1;u<=n;u++){
            if(col[u]==c){
                dis[u]=0;
                pre[u]=u;
                que.push({0,u});
            }
        }
        
        while(que.size()){
            int u=que.top().second; que.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(int i=head[u];i;i=e[i].nxt){
                int v=e[i].to;
                if(!vis[v] && (dis[u]+e[i].w<dis[v] || (dis[u]+e[i].w==dis[v] && pre[u]<pre[v]))){
                    dis[v]=dis[u]+e[i].w;
                    pre[v]=pre[u];
                    que.push({-dis[v],v});
                }
            }
        }
        
        for(int u=1;u<=n;u++){
            if(!pre[u]) return 0;
            trans[c][u]=pre[u];
        }
        
        // cout<<c<<": ";
        // for(int u=1;u<=n;u++) cout<<trans[c][u]<<" ";
        // cout<<endl;
    }
    
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            int id=ID(x,y);
            for(int c=0;c<4;c++){
                if(!bucc[c]) continue;
                int nx=trans[c][x],ny=trans[c][y],nid=ID(nx,ny);
                G[nid].push_back(id);
                // cout<<" "<<id<<" -> "<<nid<<endl;
            }
        }
    }
    for(int u=1;u<=n;u++) dfs(ID(u,u));
    for(int i=1;i<=n*n;i++)
        if(!vs[i]){
            // cout<<" ! "<<i<<endl;
            return 0;
        }
    return 1;
}

signed main(){
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) head[i]=0;
        cnt=0;
        memset(bucc,0,sizeof(bucc));
        for(int i=1;i<=n*n;i++) G[i].clear(),vs[i]=0;
        
        for(int i=1;i<=n;i++){
            scanf("%d",&col[i]); col[i]--;
            bucc[col[i]]=1;
        }
        for(int i=1;i<=m;i++){
            int u,v,w; scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        
        if(solve()) printf("YES\n");
        else printf("NO\n");
        
    }
    
    
}
