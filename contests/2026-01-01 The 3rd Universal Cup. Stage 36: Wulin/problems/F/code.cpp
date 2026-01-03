#include<bits/stdc++.h>
using namespace std;
const int N=110000;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair

int n,k,m,c[N],dis[N][2],ori[N][2];
vector<int> g[N];

struct zt{
    int u,st,dis;
};

void solve(){
    
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
        g[i].clear();
    }
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
    }
    
    for(int C=1;C<=50;C++){
        queue<zt> q;
        for(int i=1;i<=n;i++){
            for(int o=0;o<=1;o++){
                dis[i][o]=1e6;
                ori[i][o]=0;
            }
        }
        for(int i=1;i<=n;i++){
            if(c[i] == C){
                //dis[i][0]=0;
                //ori[i][0]=i;
                zt t;t.u = i;t.dis = 0;t.st = i;
                q.push(t);
            }
        }
        //printf("start bfs C=%d\n",C);
        while(!q.empty()){
            zt u = q.front();q.pop();
            zt t=u;
            //printf("u=%d,dis=%d,st=%d\n",u.u,u.dis,u.st);fflush(stdout);
            for(int i=0;i<g[u.u].size();i++){
                int v = g[u.u][i];
                if(v == u.st)continue;
                int d = u.dis + 1;
                if(1e6 == dis[v][0]){
                    dis[v][0] = d;
                    ori[v][0] = u.st;
                    t.dis = d;t.u = v;q.push(t);
                }
                else if(1e6 == dis[v][1]){
                    if(ori[v][0] == u.st)continue;
                    dis[v][1] = d;
                    t.dis = d;t.u = v;q.push(t);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(c[i] == C){
                if(dis[i][0] < k || dis[i][1] < k){
                    printf("NO\n");
                    return;
                }
            }
            
        }
    }
    printf("YES\n");
    
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}
