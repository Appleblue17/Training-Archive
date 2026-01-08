#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=2e6+5,mod=1e9+7;
int n,m,ans=1;
bool tag[N];

vector < pair<int,int> > V[N];

vector <int> G[N];
map <int,int> mp;



bool vis[N];
int numV,numE;
bool sp;
void dfs(int u){
    if(vis[u]) return ;
    vis[u]=1;
    numV++;
    numE+=G[u].size();
    for(int v: G[u]){
        if(v==u) sp=1;
        if(vis[v]) continue;
        dfs(v);
    }
}

signed main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        V[w].push_back({u,v});
    }
    
    for(int t=1;t<=n;t++){
        // if(!V[t].size()){
        //     alc++;
        //     continue;
        // }
        if(V[t].size()<=1) continue;
        mp.clear();
        
        for(auto e: V[t]){
            int u=e.first,v=e.second;
            mp[u]++,mp[v]++;
        }
        vector <int> TMP;
        for(auto e: mp){
            if(e.second>1) TMP.push_back(e.first);
        }
        if(TMP.size()!=1) return cout<<0,0;
        tag[TMP[0]]=1;
    }
    
    for(int t=1;t<=n;t++){
        if(V[t].size()!=1) continue;
        int u=V[t][0].first,v=V[t][0].second;
        if(tag[u] && tag[v]) return cout<<0,0;
        if(tag[u]) u=v;
        if(tag[v]) v=u;
        
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    for(int u=1;u<=n;u++){
        if(vis[u]) continue;
        numV=numE=0; sp=0;
        dfs(u);
        numE/=2;
        if(numE>numV) return cout<<0,0;
        if(numE<numV) ans=1ll*ans*numV%mod;
        else if(!sp) ans=ans*2ll%mod;
    }
    
    int alc=0;
    for(int t=1;t<=n;t++){
        if(!V[t].size()) alc++;
    }
    
    for(int i=1;i<=alc;i++) ans=1ll*ans*i%mod;
    cout<<ans;
}
