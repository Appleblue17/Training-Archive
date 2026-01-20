#include <bits/stdc++.h>
using namespace std;
const int N=4e5+5;

int n,m,q;
vector <int> G[N];

int p[N];

int dep[N];
int fat[N][22];
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    fat[u][0]=fa;
    for(int i=1;i<=20;i++) fat[u][i]=fat[fat[u][i-1]][i-1];
    
    for(int v: G[u]){
        if(v==fa) continue;
        dfs(v,u);
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--){
        if(dep[x]-(1<<i)>=dep[y]) x=fat[x][i];
    }
    if(x==y) return x;
    for(int i=20;i>=0;i--){
        if(fat[x][i]!=fat[y][i]) x=fat[x][i],y=fat[y][i];
    }
    return fat[x][0];
}
int gdis(int x,int y){
    int lc=lca(x,y);
    // cout<<x<<" "<<y<<": "<<lc<<endl;
    return dep[x]+dep[y]-2*dep[lc];
}
bool check(int x,int y,int z){
    return (gdis(x,y)+gdis(y,z)==gdis(x,z));
}

int ans;
void upd(int pos,int w){
    if(pos>=2 && pos<m){
        if(check(p[pos-1],p[pos],p[pos+1])) ans+=w;
    }
    
}

int main(){
    cin>>n>>m>>q;
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    // return 0;
    for(int i=1;i<=m;i++) scanf("%d",&p[i]);
    for(int i=2;i<m;i++) upd(i,1);
    
    while(q--){
        int pos,val; scanf("%d%d",&pos,&val);
        
        upd(pos-1,-1);
        upd(pos,-1);
        upd(pos+1,-1);
        
        p[pos]=val;
        
        upd(pos-1,1);
        upd(pos,1);
        upd(pos+1,1);
        
        printf("%d\n",m-ans);
    }
    
    
}
