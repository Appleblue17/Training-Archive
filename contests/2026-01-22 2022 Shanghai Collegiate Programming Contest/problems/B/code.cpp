#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int n,m;
void NO(){
    printf("?");
    exit(0);
}

struct nod{
    int to,nxt,w;
}e[N*2];
int head[N],cnt;
void add(int u,int v,int w){
    // cout<<u<<" "<<v<<" "<<w<<endl;
    e[++cnt]={v,head[u],w};
    head[u]=cnt;
}


vector < pair<int,int> > G[N];
int col[N],val[N];
int COL;
void dfs(int u){
    if(col[u]!=-1) return ;
    col[u]=COL;
    
    for(auto e: G[u]){
        int v=e.first,w=e.second;
        if(col[v]==-1){
            val[v]=val[u]+w;
            dfs(v);
        }
        else if(val[v]!=val[u]+w) NO();
    }
}

int dis[N];
bool vis[N];
int ct[N];
queue <int> q;

signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int l,r,w; scanf("%d%d%d",&l,&r,&w);
        int x=(r-l+1)+w;
        if(x & 1) NO();
        w=x/2;
        l--;
        G[l].push_back({r,w});
        G[r].push_back({l,-w});
    }
    
    memset(col,-1,sizeof(col));
    for(int u=0;u<=n;u++){
        if(col[u]!=-1) continue;
        COL=u;
        dfs(u);
    }
    
    for(int i=1;i<=n;i++) add(i,0,-(i+1)/2);
    add(0,n,n/2);
    
    for(int i=0;i<n;i++){
        add(i,i+1,1);
        add(i+1,i,0);
    }
    
    for(int i=0;i<=n;i++){
        if(col[i]==i) continue;
        int x=col[i];
        add(x,i,val[i]);
        add(i,x,-val[i]);
    }
    
    memset(dis,0x7f,sizeof(dis));
    dis[0]=0;
    q.push(0); vis[0]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        vis[u]=0;
        ct[u]++;
        if(ct[u]>=n+1) NO();
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to;
            if(dis[u]+e[i].w<dis[v]){
                dis[v]=dis[u]+e[i].w;
                if(!vis[v]) q.push(v),vis[v]=1;
            }
                
        }
    }
    
    // for(int i=0;i<=n;i++) cout<<dis[i]<<" ";
    // cout<<endl;
    
    printf("! ");
    for(int i=1;i<=n;i++){
        if(dis[i]>dis[i-1]) putchar('(');
        else putchar(')');
    }
}

