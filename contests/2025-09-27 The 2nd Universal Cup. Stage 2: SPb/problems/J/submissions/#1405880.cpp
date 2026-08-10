#include<bits/stdc++.h>
using namespace std;
const int N = 50000;
int n,t;
int xs,ys,xt,yt,x[N],y[N];
vector<int> g[N],va[N],id[N];
int dist[N],lst[N],lstid[N];
bool vis[N];
void add(int u,int v,int w,int i){
    g[u].push_back(v);
    va[u].push_back(w);
    id[u].push_back(i);
    g[v].push_back(u);va[v].push_back(w);id[v].push_back(i);
}
typedef pair<int,int> pii;
#define fi first 
#define se second 
#define mp make_pair 
int S,T;
void dijk(){
    priority_queue<pii> pq;
    pq.push(mp(0,S));vis[S]=1;
    memset(dist,48,sizeof(dist));
    dist[S]=0;
    
    while(!pq.empty()){
        pii t = pq.top();pq.pop();
        int u = t.se;
        vis[u]=1;
        for(int i=0;i<g[u].size();i++){
            int v = g[u][i],w = va[u][i];
            if(vis[v])continue;
            if(dist[u]+w < dist[v]){
                dist[v]=dist[u]+w;
                lst[v]=u;
                lstid[v]=id[u][i];
                pq.push(mp(-dist[v],v));
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&t);
    scanf("%d%d%d%d",&xs,&ys,&xt,&yt);
    S = xs*101+ys,T = xt*101+yt;
    vector<int> a;
    for(int ii=1;ii<=n;ii++){
        scanf("%d%d",&x[ii],&y[ii]);
        a.clear();
        for(int i=0;i<=100;i++){
            a.push_back(x[ii]*101+i);
            a.push_back(y[ii]+i*101);
        }
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                add(a[i],a[j],t,ii);
            }
        }
    }
    for(int i=0;i<=100;i++){
        add(S,xs*101+i,abs(i-ys),0);
        add(S,ys+i*101,abs(i-xs),0);
        add(T,xt*101+i,abs(i-yt),0);
        add(T,yt+i*101,abs(i-xt),0);
    }
    
    dijk();
    
    double dis = sqrt((xs-xt)*(xs-xt)+(ys-yt)*(ys-yt));
    
    if(dist[T] > dis){
        printf("%.10lf\n",dis);
        printf("1\n");
        printf("%d %d %d\n",0,xt,yt);
        return 0;
    }
    
    vector<int> ans;
    int u = T;
    while(u != S){
        ans.push_back(lstid[u]);
        ans.push_back(u/101);ans.push_back(u%101);
        u = lst[u];
    }
    printf("%d\n%d\n",dist[T],ans.size()/3);
    for(int i=ans.size()-3;i>=0;i-=3){
        printf("%d %d %d\n",ans[i],ans[i+1],ans[i+2]);
    }
    
    
}
