#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,INF=1e9;
int T, n;
int a[N], b[N];

struct nod{
    int to,nxt,f;
}e[N*2];
int head[N],cnt;
void add(int u,int v,int f){
    e[++cnt]={v,head[u],f};
    head[u]=cnt;
}
void qadd(int u,int v,int w){
    // cout<<" add "<<u<<" "<<v<<" "<<w<<endl;
    add(u,v,w);
    add(v,u,0);
}


int siz,st,ed;
int dis[N];
queue <int> q;
bool bfs(){
    for(int i=1;i<=siz;i++) dis[i]=INF;
    dis[st]=0;
    q.push(st);
    while(q.size()){
        int u=q.front(); q.pop();
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to;
            if(!e[i].f || dis[v]<INF) continue;
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
    return (dis[ed]<INF);
}

int cur[N];
int dfs(int u,int flow){
    if(u==ed) return flow;
    int del=flow;
    for(int i=cur[u];i && del;i=e[i].nxt){
        cur[u]=i;
        int v=e[i].to;
        if(e[i].f && dis[v]==dis[u]+1){
            int x=dfs(v,min(del,e[i].f));
            del-=x;
            e[i].f-=x,e[i^1].f+=x;
        }
    }
    return flow-del;
}

int dinic(){
    int tot=0;
    while(bfs()){
        for(int i=1;i<=siz;i++) cur[i]=head[i];
        tot+=dfs(st,INF);
    }
    return tot;
}


void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    int num=0;
    for(int i=1; i<=n; ++i) scanf("%d", &b[i]), num+=(a[i]==b[i]);
    if(num==n){
        printf("Yes\n");
        return ;
    }
    for(int i=1; i<=n; ++i){
        if((a[i] & b[i])!=b[i]){
            printf("No\n");
            return;
        }
    }
    
    siz=n+2; st=siz-1,ed=siz;
    for(int i=1;i<=siz;i++) head[i]=0;
    cnt=1;
    
    for(int mac=0;mac<n;mac++){
        qadd(st,mac+1,1);
        for(int i=0;i<=18;i++){
            if(mac>>i & 1){
                qadd(mac+1,(mac^(1<<i))+1,INF);
            }
        }
    }
    for(int i=1;i<=n;i++){
        qadd(b[i]+1,ed,1);
    }
    
    int res=dinic();
    if(res==n) printf("Yes\n");
    else printf("No\n");
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
