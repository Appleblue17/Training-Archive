#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5,M=1e6+5,INF=1e18;

int T,n,m,k;
int p[N],mp[N];

struct nod{
    int to,nxt,w,ban;
}e[M*2];
int head[N],cnt;
void add(int u,int v,int w){
    e[++cnt]={v,head[u],w,0};
    head[u]=cnt;
}

struct def{
    int num,dis;
};
bool operator <(def X,def Y){
    if(X.dis==Y.dis) return X.num>Y.num;
    return Y.dis<X.dis;
}
priority_queue <def> q;
int dis[N],col[N];
bool vis[N];

void dijkstra(){
    for(int i=1;i<=n;i++){
        vis[i]=0;
        col[i]=i;
        if(dis[i]<INF) q.push({i,dis[i]});
    }
    
    while(!q.empty()){
        def tmp=q.top(); q.pop();
        int u=tmp.num;
        if(vis[u]) continue;
        vis[u]=1;
        
        for(int i=head[u];i;i=e[i].nxt){
            if(e[i].ban) continue;
            int v=e[i].to,w=e[i].w;
            if(!vis[v] && dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                col[v]=col[u];
                q.push({v,dis[v]});
            }
        }
    }
}

int ds[N];
int ans[N];

signed main(){
    // freopen("1.txt","w",stdout);
    cin>>T;
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&k);
        for(int i=1;i<=n;i++) head[i]=0,mp[i]=0,ans[i]=INF;
        cnt=0;
        
        for(int i=1;i<=k;i++){
            scanf("%lld",&p[i]);
            mp[p[i]]=i;
        }
        for(int i=1;i<=m;i++){
            int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        
        for(int i=1;i<=n;i++) dis[i]=INF;
        dis[1]=0;
        
        dijkstra();
        int lim=0;
        for(int i=1;i<=n;i++){
            ds[i]=dis[i];
            if(mp[i]) lim=max(lim,ds[i]);
        }
        
        for(int i=1;i<=n;i++) dis[i]=(mp[i]==0)*INF;
        dijkstra();
        
        for(int u=1;u<=n;u++){
            for(int i=head[u];i;i=e[i].nxt){
                int v=e[i].to,w=e[i].w;
                int disx=ds[u],disy=ds[v];
                int dx=dis[u],dy=dis[v];
                
                // cout<<"  "<<u<<" "<<v<<": "<<disx<<" "<<disy<<" "<<dx<<" "<<dy<<" "<<w<<endl;
                
                if(disy<disx) swap(disx,disy),swap(dx,dy);
                int diff=disy-disx;
                int tot=(disy*2+(w-diff))+min(dx*2+(w+diff),dy*2+(w-diff));
                if(tot>lim*2){
                    // cout<<"del "<<u<<" "<<v<<endl;
                    e[i].ban=1;
                }
            }
        }
        
        for(int i=1;i<=n;i++) dis[i]=(mp[i]==0)*INF;
        dijkstra();
        
        for(int u=1;u<=n;u++){
            for(int i=head[u];i;i=e[i].nxt){
                if(e[i].ban) continue;
                int v=e[i].to,w=e[i].w;
                if(col[u]!=col[v]){
                    int tot=dis[u]+dis[v]+w;
                    ans[col[u]]=min(ans[col[u]],tot);
                    ans[col[v]]=min(ans[col[v]],tot);
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     cout<<i<<": "; dis[i].pr();
        // }
        // cout<<endl;
        
        for(int i=1;i<=k;i++) printf("%.1lf ",max(0ll,lim*2-ans[p[i]])/2.0);
        printf("\n");
    }
    
}
