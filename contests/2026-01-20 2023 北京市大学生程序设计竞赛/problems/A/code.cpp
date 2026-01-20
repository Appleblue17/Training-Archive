#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
vector <int> G[N];
int deg[N];

int f[N];
void dfs(int u,int fa){
    if(deg[u]==1){
        f[u]=1;
        return ;
    }
    int tot=0;
    for(int v: G[u]){
        if(v==fa) continue;
        dfs(v,u);
        tot+=f[v];
    }
    f[u]=(tot>=2);
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    
    if(deg[1]==1) return cout<<"You win, temporarily.",0;
    dfs(1,0);
    if(f[1]) cout<<"You win, temporarily.";
    else cout<<"Wasted.";
}
