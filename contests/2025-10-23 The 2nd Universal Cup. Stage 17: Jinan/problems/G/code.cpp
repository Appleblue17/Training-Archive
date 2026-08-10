#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5,mod=1e9+7;
int T,n,m;
char S[N];
vector <int> col[N];

vector < pair<int,int> > G[N];
void add(int u,int v,int w){
    // cout<<" add "<<u<<" "<<v<<" "<<w<<endl;
    G[u].push_back({v,w});
    G[v].push_back({u,w});
}

bool vis[N],c[N];
bool dfs(int u){
    if(vis[u]) return 1;
    vis[u]=1;
    for(pair<int,int> e: G[u]){
        int v=e.first,w=e.second;
        if(!vis[v]){
            c[v]=c[u]^w;
            if(!dfs(v)) return 0;
        }
        else if(c[v]!=c[u]^w) return 0;
    }
    return 1;
}

int solve(){
    for(int i=1;i<=m;i++) col[i].clear();
    for(int i=1;i<=n;i++) G[i].clear(),vis[i]=c[i]=0;
    
    int tot=0;
    for(int i=1;i<=n;i++){
        scanf("\n%s",S+1);
        for(int j=1;j<=m;j++){
            if(S[j]=='1'){
                col[j].push_back(i);
                tot++;
            }
        }
    }
    if(tot>m) return 0;
    
    for(int j=1;j<=m;j++){
        if(col[j].size()>2) return 0;
        if(col[j].size()==2){
            int x=col[j][0],y=col[j][1];
            add(x,y,1);
        }
    }
    
    int ans=1;
    for(int i=1;i<=(m+1)/2;i++){
        int j=m+1-i;
        if(!col[i].size() || !col[j].size()) continue;
        
        int u=col[i][0];
        for(int x: col[i]) add(u,x,0);
        for(int y: col[j]) add(u,y,0);
    }
    
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(!dfs(i)) return 0;
        ans=1ll*ans*2%mod;
    }
    return ans;
}

signed main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        
        int ans=solve();
        printf("%d\n",ans);
    }
}
