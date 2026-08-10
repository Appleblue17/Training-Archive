#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int n,m=1e6+1,ans;
int a[N],b[N];

vector <int> G[N];

int deg[N];
bool vis[N];
int cntV,cntE;
void dfs(int u){
    if(vis[u]) return ;
    vis[u]=1;
    
    cntV++;
    cntE+=deg[u];
    for(int v: G[u]){
        if(!vis[v]) dfs(v);
    }
    
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]++;
    for(int i=1;i<=n;i++) scanf("%d",&b[i]),b[i]++;
    
    for(int i=1;i<=n;i++){
        int u=a[i],v=b[i];
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    
    for(int i=1;i<=m;i++){
        if(vis[i]) continue;
        cntV=cntE=0;
        dfs(i);
        cntE/=2;
        if(cntE==cntV-1) ans+=cntV-1;
        else ans+=cntV;
    }
    cout<<ans;
}

