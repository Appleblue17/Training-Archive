#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,INF=1e18;

int n,k,ans;
int a[N],b[N];
vector <int> G[N];

int s[N];
void dfs(int u,int fa){
    s[u]=b[u];
    
    for(int v: G[u]){
        if(v==fa) continue;
        dfs(v,u);
        s[u]+=b[v];
    }
    if(s[u]>k){
        cout<<"-1";
        exit(0);
    }
    
    for(int v: G[u]){
        if(v==fa) continue;
        if(a[v]==-1){
            int ret=min(k-s[u],k-s[v]);
            ans+=ret;
            b[v]+=ret; s[u]+=ret; s[v]+=ret;
        }
    }
}


signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]!=-1) b[i]=a[i],ans+=b[i];
    }
    for(int i=1;i<n;i++){
        int u,v; scanf("%lld%lld",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    
    if(a[1]==-1){
        int ret=k-s[1];
        ans+=ret; s[1]+=ret;
    }
    
    cout<<ans;
}
