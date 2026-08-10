#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define Pii pair<int,int>
#define MP make_pair
const int N=550,M=2e6+5,INF=1e9;

mt19937_64 rng(123456);
ull rd[N];

int T_,n;
char S_[N];

vector <int> G[N];


int dep[M],dis[M];
int S,T;
int lin[M],nxt[M],to[M],val[M],w[M],cur[M];
int tot;
inline void in(int x,int y,int z,int _w){
    nxt[++tot]=lin[x];
    lin[x]=tot;
    to[tot]=y;
    val[tot]=z;
    w[tot]=_w;
}
inline void link(int x,int y,int z,int _w){
    in(x,y,z,_w);
    in(y,x,0,-_w);
}
bool v[M],vis[M];
inline bool bfs(){
    for(int i=1;i<=T;i++){
        dep[i]=0;
        dis[i]=INF;
        v[i]=vis[i]=0;
        cur[i]=lin[i];
    }
    deque<int> q;
    q.push_back(S); dis[S]=0; dep[S]=1;
    while(!q.empty()){
        int x=q.front(); q.pop_front();
        v[x]=0;
        for(int i=lin[x];i;i=nxt[i]){
            int y=to[i];
            if(val[i] && dis[y]>dis[x]+w[i]){
                dis[y]=dis[x]+w[i];
                dep[y]=dep[x]+1;
                if(!v[y]){
                    v[y]=1;
                    if(!q.empty() && dis[y]<dis[q.front()]) q.push_front(y);
                    else q.push_back(y);
                }
            }
        }
    }
    return dis[T]<INF;
}

int totflow,totcost;
inline int dfs(int x,int nw){
    if(x==T){
        totflow+=nw;
        totcost+=dis[T]*nw;
        return nw;
    }
    vis[x]=1;
    int ret=0;
    for(int i=cur[x];i && ret<nw;i=nxt[i]){
        int y=to[i];
        cur[x]=i;
        if(!vis[y] && val[i] && dep[y]==dep[x]+1 && dis[y]==dis[x]+w[i]){
            int res=dfs(y,min(val[i],nw-ret));
            if(!res) dep[y]=0;
            val[i]-=res;
            val[i^1]+=res;
            ret+=res;
        }
    }
    if(ret==nw) vis[x]=0;
    return ret;
}

void runflow(){
    totflow=totcost=0;
    while(bfs()){
        int fl=dfs(S,INF);
        while(fl){
            fl=dfs(S,INF);
        }
    }
}


int id;

int U,NUM,CNT;
map <ull,int> mp;
vector <int> V[M];

int pat[N];
void dfs(int dep,int nw,ull has){
    if(CNT>=n) return ;
    if(dep==NUM){
        // for(int i=0;i<NUM;i++) cout<<pat[i]<<" ";
        // cout<<": "<<has<<endl;
        if(!mp[has]){
            mp[has]=++id;
            V[id].clear();
            for(int i=0;i<NUM;i++) V[id].push_back(pat[i]);
        }
        link(U,mp[has],1,NUM);
        CNT++;
        return ;
    }
    
    for(int i=nw+1;i<G[U].size();i++){
        pat[dep]=G[U][i];
        dfs(dep+1,i,has^rd[G[U][i]]);
        if(CNT>=n) return ;
    }
}

int main(){
    for(int i=0;i<N;i++) rd[i]=rng();
    
    scanf("%d",&T_);
    while(T_--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            G[i].clear();
        }
        int m=n*n+n+10;
        for(int i=1;i<=m;i++) lin[i]=0;
        tot=1;
        mp.clear();
        
        for(int i=1;i<n;i++){
            scanf("\n%s",S_+1);
            for(int j=1;j<=n-i;j++){
                if(S_[j]=='1'){
                    G[i].push_back(i+j);
                    G[i+j].push_back(i);
                }
            }
        }
        
        id=n;
        for(int u=1;u<=n;u++){
            // cout<<u<<": "<<endl;
            U=u;
            CNT=0;
            for(int t=1;t<=G[u].size() && CNT<n;t++){
                NUM=t;
                dfs(0,-1,0);
            }
        }
        
        // cout<<"  "<<n<<" "<<id<<endl;
        
        S=id+1,T=id+2;
        for(int i=1;i<=n;i++) link(S,i,1,0);
        for(int i=n+1;i<=id;i++) link(i,T,1,0);
        
        runflow();
        if(totflow<n){
            printf("-1\n");
            continue;
        }
        
        // printf("%d\n",totcost);
        
        for(int u=1;u<=n;u++){
            for(int i=lin[u];i;i=nxt[i]){
                int v=to[i],w=val[i^1];
                if(v==S) continue;
                if(w){
                    // cout<<"  "<<u<<" "<<v<<endl;
                    printf("%d ",V[v].size());
                    for(int x: V[v]) printf("%d ",x);
                    printf("\n");
                    break;
                }
            }
        }
        
    }
    
    
}