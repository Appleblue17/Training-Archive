#include <bits/stdc++.h>
using namespace std;
const int N=2200;
int T,n,k;
vector <int> G[N];

int f[N],g[N];
int FA[N];

bool buc[N];

void indfs(int u,int fa,int s,int stp){
    if(stp>k) return ;
    
    for(int v: G[u]){
        if(v==fa) continue;
        s^=f[v];
    }
    buc[s]=1;
    
    for(int v: G[u]){
        if(v==fa) continue;
        indfs(v,u,s^f[v],stp+1);
    }
}

void dfs(int u,int fa){
    FA[u]=fa;
    for(int v: G[u]){
        if(v==fa) continue;
        dfs(v,u);
    }
    
    // cout<<" start "<<u<<endl;
    for(int i=0;i<=n;i++) buc[i]=0;
    indfs(u,fa,0,1);
    int x=0;
    while(buc[x]) x++;
    f[u]=x;
    
    // cout<<u<<": "<<f[u]<<" | "; for(int i=0;i<=n;i++) cout<<buc[i]<<" "; cout<<endl;
}




void indfss(int u,int fa,int s,int top,int stp){
    if(!u) return ;
    if(stp>k) return ;
    
    for(int v: G[u]){
        if(v==fa || v==FA[u]) continue;
        s^=f[v];
    }
    
    // cout<<"  "<<u<<" "<<s<<" "<<top<<" "<<stp<<" -> "<<(s^g[top])<<endl;
    buc[s^g[top]]=1;
    
    for(int v: G[u]){
        if(v==fa) continue;
        if(v==FA[u]){
            indfss(v,u,s,v,stp+1);
        }
        else{
            indfss(v,u,s^f[v],top,stp+1);
        }
    }
}

void dfss(int u,int fa){
    // cout<<" start "<<u<<endl;
    
    for(int i=0;i<=n;i++) buc[i]=0;
    indfss(fa,u,0,fa,1);
    int x=0;
    while(buc[x]) x++;
    g[u]=x;
    
    // cout<<u<<": "<<g[u]<<" | "; for(int i=0;i<=n;i++) cout<<buc[i]<<" "; cout<<endl;
    
    for(int v: G[u]){
        if(v==fa) continue;
        dfss(v,u);
    }
}

void solve(){
    for(int i=1;i<=n;i++) f[i]=g[i]=0;
    
    dfs(1,0);
    // cout<<"f: "; for(int i=1;i<=n;i++) cout<<f[i]<<" "; cout<<endl;
    
    dfss(1,0);
    // cout<<"g: "; for(int i=1;i<=n;i++) cout<<g[i]<<" "; cout<<endl;
    
    for(int u=1;u<=n;u++){
        int s=g[u];
        for(int v: G[u]){
            if(v==FA[u]) continue;
            s^=f[v];
        }
        if(!s) putchar('0');
        else putchar('1');
    }
    putchar('\n');
}

signed main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) G[i].clear();
        
        for(int i=1;i<n;i++){
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        solve();
    }
    
}