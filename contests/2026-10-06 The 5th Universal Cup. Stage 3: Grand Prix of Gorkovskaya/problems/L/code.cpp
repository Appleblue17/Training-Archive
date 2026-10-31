#include<bits/stdc++.h>
using namespace std;
const int N = 210000;
int n,rt,d;
int dis[N],nx[N],ans[2];
vector<int> g[N];
void dfs(int u,int fa){
    int tmp=0;
    for(int v:g[u]){
        if(v == fa)continue;
        dis[v] = dis[u]+1;
        dfs(v,u);
        tmp = __gcd(tmp,nx[v]+1);
    }
    //printf("u=%d,tmp=%d\n",u,tmp);
    if(g[u].size() != 2){
        d = __gcd(d,tmp);
        nx[u] = 0;
    }
    else{
        nx[u] = tmp;
    }
}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(g[i].size() == 1)rt = i;
    }
    d = 0;
    dfs(rt,0);
    //printf("rt=%d,d = %d\n",rt,d);
    ans[0]=ans[1]=0;
    for(int i=1;i<=n;i++){
        //printf("dis[%d]=%d\n",i,dis[i]);
        if(g[i].size() == 1){
            ans[(dis[i]/d)%2] = 1;
        }
    }
    if(ans[0] && ans[1]){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
}
int main(){
    int t;cin >> t;while(t--){
        solve();
    }
}