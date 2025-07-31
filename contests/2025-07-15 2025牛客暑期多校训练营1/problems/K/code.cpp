#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define MP make_pair
const int N=1e6+5;
 
int n,ans[N];
 
int d[N];
vector < pair<int,int> > V[N];
 
int eid,id;
map < pair<int,int>, int> mp;
 
int col[N];
vector <int> G[N];
 
 
int to[N];
 
bool vis[N],vs[N];
int p[N],pid;
int alc;
 
void dfs(int u,int fa){
    bool fl=0;
    vs[u]=1;
     
    // cout<<"dfs "<<u<<endl;
     
    int c=col[u];
    if(!vis[c]){
        vis[c]=1;
        alc++;
        fl=1;
    }
    ans[u]=alc;
     
    for(int v: G[u]){
        if(v==fa) continue;
        dfs(v,u);
    }
    if(fl){
        vis[c]=0;
        alc--;
    }
}
 
signed main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i]);
        // cout<<i<<": ";
        for(int j=1;j<=d[i];j++){
            int x; scanf("%d",&x);
            id++;
            V[i].push_back(MP(x,id));
            if(!mp[MP(i,x)]){
                mp[MP(i,x)]=mp[MP(x,i)]=++eid;
            }
            col[id]=mp[MP(i,x)];
             
            // cout<<id<<","<<col[id]<<" ";
        }
        // cout<<endl;
    }
     
    for(int u=1;u<=n;u++){
        for(int t=0;t<d[u];t++){
            int v=V[u][t].first,id=V[u][t].second;
             
            int x=0;
            for(int s=0;s<d[v];s++){
                if(V[v][s].first==u) x=V[v][(s+1)%d[v]].second;
            }
            to[id]=x;
            G[x].push_back(id);
        }
    }
     
    // for(int i=1;i<=id;i++){
    //     cout<<to[i]<<" "<<col[i]<<endl;
    // }
    // return 0;
     
    for(int u=1;u<=id;u++){
        if(vs[u]) continue;
         
        int x=u;
        while(!vs[x]){
            vs[x]=1;
            x=to[x];
        }
        pid=0;
        int y=x;
        do{
            y=to[y];
            p[pid++]=y;
        }while(y!=x);
         
        // cout<<u<<" "<<pid<<": ";
        // for(int i=0;i<pid;i++) cout<<p[i]<<" ";
        // cout<<endl;
         
        // for(int i=1;i<=eid;i++) cout<<vis[i]<<" "; cout<<endl;
        alc=0;
        for(int i=0;i<pid;i++){
            int c=col[p[i]];
            if(!vis[c]) vis[c]=1,alc++;
        }
        // cout<<"alc "<<alc<<endl;
         
        for(int i=0;i<pid;i++){
            dfs(p[i],p[(i+pid-1)%pid]);
        }
         
        for(int i=0;i<pid;i++){
            int c=col[p[i]];
            vis[c]=0;
        }
    }
     
    // for(int i=1;i<=id;i++) cout<<ans[i]<<" ";
    // cout<<endl;
     
    for(int u=1;u<=n;u++){
        int x=V[u][0].second;
        printf("%d\n",ans[x]);
    }
}
