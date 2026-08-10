#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
const int N=6e5+5,INF=1e18;
int T,n,m,q,ans[N];
 
vector < pair<int,int> > G[N],IG[N];
 
 
bool vis[N];
struct abc{
    int num,dis;
};
bool operator <(abc X,abc Y){
    if(X.dis==Y.dis) return X.num<Y.num;
    return X.dis>Y.dis;
}
priority_queue<abc> que;
 
void dijkstra(int st, int dis[N], vector< pair<int,int> > G[N]){
    for(int i=1;i<=n;i++) dis[i]=INF,vis[i]=0;
    dis[st]=0;
    que.push((abc){st,0});
    while(!que.empty()){
        abc tmp=que.top();
        que.pop();
        int u=tmp.num;
        if(vis[u]) continue;
        vis[u]=1;
        for(pair<int,int> edg: G[u]){
            int v=edg.first,w=edg.second;
            if(!vis[v] && dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                que.push((abc){v,dis[v]});
            }
        }
    }
}
 
int U[N],V[N],W[N],X[N];
pair<int,int> qry[N];
 
int dis1[N],dis2[N];
 
pair<int,int> P[N];
int p[N],pid;
 
bool check(int x,int y,int z){
    __int128 A=P[x].first-P[y].first,B=P[x].second-P[y].second;
    if(B<0) A=-A,B=-B;
     
    __int128 C=P[z].first-P[y].first,D=P[z].second-P[y].second;
    if(D<0) C=-C,D=-D;
     
    // if(1.0*A/B>1.0*C/D) return 1;
    if(A*D>C*B) return 1;
    return 0;
}
 
signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear(),IG[i].clear();
         
        for(int i=1;i<=m;i++){
            int u,v,w,x;
            scanf("%lld%lld%lld%lld",&u,&v,&w,&x);
            U[i]=u,V[i]=v,W[i]=w,X[i]=x;
            G[u].push_back(MP(v,w));
            IG[v].push_back(MP(u,w));
        }
         
        scanf("%lld",&q);
        for(int i=1;i<=q;i++){
            int k; scanf("%lld",&k);
            qry[i]=MP(k,i);
        }
        sort(qry+1,qry+q+1);
         
        dijkstra(1,dis1,G);
        dijkstra(n,dis2,IG);
         
         
        // for(int i=1;i<=n;i++) cout<<dis1[i]<<" "; cout<<endl;
        // for(int i=1;i<=n;i++) cout<<dis2[i]<<" "; cout<<endl;
         
        for(int i=1;i<=m;i++){
            int u=U[i],v=V[i],w=W[i],x=X[i];
            P[i]=MP(dis1[u]+dis2[v]+w,X[i]);
            // cout<<P[i].first<<" "<<P[i].second<<endl;
        }
        sort(P+1,P+m+1);
        // cout<<endl;
        pid=0;
        for(int i=1;i<=m;i++){
            int A=P[i].first,B=P[i].second;
            if(A>=INF) continue;
            if(!pid || B>P[p[pid]].second){
                while(pid>1 && check(p[pid-1],p[pid],i)) pid--;
                p[++pid]=i;
            }
        }
        for(int i=1;i<=pid;i++){
            int A=P[p[i]].first,B=P[p[i]].second;
            // cout<<A<<" "<<B<<endl;
            // cout<<A-B*3<<endl;
        }
         
        int cur=1;
        for(int i=1;i<=q;i++){
            int k=qry[i].first;
            while(cur+1<=pid){
                int x=p[cur],y=p[cur+1];
                if(P[x].first-k*P[x].second<=P[y].first-k*P[y].second) break;
                cur++;
            }
            int x=p[cur];
            ans[qry[i].second]=P[x].first-k*P[x].second;
        }
        for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
    }
}
