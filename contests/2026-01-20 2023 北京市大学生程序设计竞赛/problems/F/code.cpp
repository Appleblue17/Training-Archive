#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5+5;

int n,m,ind[N],oud[N],inval[N],del[N],id[N],nn;
vector<int> g[N],va[N],G[N],V[N],rev[N],rva[N];

int dis[3100];
bool vis[3100];

struct abc{
    int num,dis;
};

bool operator <(abc x,abc y){
    if(x.dis == y.dis)return x.num < y.num;
    return x.dis > y.dis;
}

priority_queue<abc> Q;

signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        g[u].push_back(v);
        va[u].push_back(w);
        ind[v]++;
        oud[u]++;
        rev[v].push_back(u);
        rva[v].push_back(w);
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(ind[i]==0)q.push(i);
    }
    while(!q.empty()){
        int u = q.front();q.pop();
        del[u]=1;
        for(int i=0;i<g[u].size();i++){
            int v = g[u][i];
            ind[v]--;
            if(ind[v]==0)q.push(v);
        }
    }
    for(int i=1;i<=n;i++){
        if(del[i])continue;
        if(oud[i]==0)q.push(i);
    }
    while(!q.empty()){
        int u = q.front();q.pop();
        del[u]=1;
        for(int v:rev[u]){
            if(del[v])continue;
            oud[v]--;
            if(oud[v]==0)q.push(v);
        }
    }
    
    int ans=1e18;
    
    for(int i=1;i<=n;i++){
        if(del[i])continue;
        if(ind[i]==1 && oud[i]==1){
            int pre=0,suf=0,v1,v2;
            for(int j=0;j<g[i].size();j++){
                int v = g[i][j];
                if(del[v])continue;
                suf=v;
                v1 = va[i][j];
            }
            for(int j=0;j<rev[i].size();j++){
                int v = rev[i][j];
                if(del[v])continue;
                pre=v;
                v2 = rva[i][j];
            }
            if(pre == i && suf == i){
                ans = min(ans,v2);
            }
            del[i]=1;
            g[pre].push_back(suf);
            va[pre].push_back(v1+v2);
            rev[suf].push_back(pre);
            rva[suf].push_back(v1+v2);
        }
    }
    
    for(int i=1;i<=n;i++){
        if(del[i])continue;
        id[i]=++nn;
    }
    
    for(int i=1;i<=n;i++){
        if(del[i])continue;
        for(int j=0;j<g[i].size();j++){
            int v = g[i][j];
            if(del[v])continue;
            int w = va[i][j];
            G[id[i]].push_back(id[v]);
            V[id[i]].push_back(w);
            //printf("new graph add edge %lld,%lld,%lld\n",id[i],id[v],w);
        }
    }
    
    
    
    for(int i=1;i<=nn;i++){
        memset(dis,0x7f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[i]=0;
        int mn=1e18;
        Q.push((abc){i,0});
        while(!Q.empty()){
            abc tmp = Q.top();
            Q.pop();
            int u = tmp.num;
            if(vis[u])continue;
            vis[u]=1;
            for(int j=0;j<G[u].size();j++){
                int v = G[u][j];
                int w = V[u][j];
                //printf("i=%lld,u=%lld,v=%lld,w=%lld\n",i,u,v,w);
                if(v == i){
                    mn = min(mn,dis[u]+w);
                }
                if(!vis[v] && dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                    Q.push((abc){v,dis[v]});
                }
            }
        }
        ans = min(mn,ans);
    }
    if(ans == 1e18){
        printf("-1\n");
    }
    else{
        printf("%lld\n",ans);
    }
    
    
}
