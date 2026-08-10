#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,M=220,INF=1e9;
int T,n,m,q;

struct abc{
    int to,nxt;
}e[N*2];
int head[N],cnt;
void add(int u,int v){
    e[++cnt]={v,head[u]};
    head[u]=cnt;
}



int col[N],COL;
vector <int> V[N];
int v[N],id;
void dfs(int u){
    if(col[u]) return ;
    col[u]=COL;
    V[COL].push_back(u);
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(!col[v]) dfs(v);
    }
}



int dis[M][N];
int que[N*2],h,t;

bool check(int x,int y){
    if(col[x]!=col[y]) return 1;
    if(V[col[x]].size()<=20000) return 0;
    for(int i=1;i<=id;i++){
        int a=dis[i][x],b=dis[i][y];
        if(a+b<=20000){
            // cout<<x<<" "<<y<<": "<<i<<" "<<v[i]<<"  "<<a<<" "<<b<<endl;
            return 0;
        }
    }
    return 1;
}

mt19937 rng(123);
int main(){
    // freopen("1.txt","w",stdout);
    // cout<<sizeof(dis)/1024/1024;
    // return 0;
    scanf("%d%d%d",&n,&m,&q);
    
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    
    for(int i=1;i<=n;i++){
        if(col[i]) continue;
        COL++;
        dfs(i);
        // cout<<i<<": "<<V[COL].size()<<endl;
        if(V[COL].size()>20000){
            for(int i=1;i<=V[COL].size()/500;i++){
                int t=rng()%V[COL].size();
                v[++id]=V[COL][t];
            }
        }
    }
    // cout<<id<<endl;
    // for(int i=1;i<=id;i++) cout<<i<<" "<<v[i]<<" "<<abs(v[i]-72242)+abs(v[i]-75342)<<endl;
    
    for(int x=1;x<=id;x++){
        for(int j=1;j<=n;j++) dis[x][j]=INF;
        
        int st=v[x];
        h=1,t=0;
        que[++t]=st; dis[x][st]=0;
        while(h<=t){
            int u=que[h]; h++;
            for(int i=head[u];i;i=e[i].nxt){
                int v=e[i].to;
                if(dis[x][v]==INF){
                    que[++t]=v;
                    dis[x][v]=dis[x][u]+1;
                }
            }
        }
        // cout<<x<<endl;
    }
    
    
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        
        if(check(x,y)) printf("YES\n");
        else printf("NO\n");
    }
    
}
