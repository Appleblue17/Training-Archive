#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,mod=998244353;

int n;
vector <int> G[N];

void gmod(int &x){
    x%=mod;
}

int f[N],g[N];
void dfs(int u,int fa){
    bool fl=1;
    f[u]=1,g[u]=0;
    for(int v: G[u]){
        if(v==fa) continue;
        fl=0;
        dfs(v,u);
        
        gmod(g[u]=g[u]*(f[v]+g[v])%mod+f[u]*g[v]%mod);
        gmod(f[u]=f[u]*(f[v]+g[v])%mod);
    }
    if(fl){
        f[u]=g[u]=1;
    }
    
    // cout<<u<<": "<<f[u]<<" "<<g[u]<<endl;
}


signed main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v; scanf("%lld%lld",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    
    cout<<f[1];
}
