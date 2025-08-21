#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int n,m,ans;
vector <int> G[N];

int dfn[N],low[N],id;
bool vis[N];
stack <int> st;

void dfs(int u,int fa){
    low[u]=dfn[u]=++id;
    vis[u]=1;
    st.push(u);
    for(int v: G[u]){
        if(v==fa) continue;
        if(!dfn[v]){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                int sum=0;
                while(st.size()){
                    int x=st.top();
                    vis[x]=0;
                    sum++;
                    // cout<<x<<" ";
                    st.pop();
                    if(x==v) break;
                }
                sum++;
                ans+=sum%2;
                // cout<<u<<endl;
            }
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++){
        if(!dfn[i]) dfs(i,0);
    }
    cout<<m-ans+1;
}