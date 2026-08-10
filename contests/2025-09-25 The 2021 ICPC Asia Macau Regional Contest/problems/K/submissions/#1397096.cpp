#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
const int N=110000;
int T,n,m;
vector<int> g[N],va[N],ans;

int fa[N],lst[N],val[N];

void dfs(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i],w = va[u][i];
        if(v == fa)continue;
        dfs(v,u);
        lst[v]=u,val[v]=w;
        //printf("lst[%d]=%d\n",v,u);fflush(stdout);
    }
}

int findfa(int x){
    if(fa[x]==x)return x;
    return fa[x]=findfa(fa[x]);
}

void solve(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        fa[i]=i,g[i].clear(),lst[i]=0;
        va[i].clear();
    }
    ans.clear();
    bool f=0;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(f)continue;
        int fx = findfa(x),fy = findfa(y);
        //printf("fx=%d,fy=%d\n",fx,fy);
        if(fx == fy){
            dfs(x,0);
            int u = y;
            ans.push_back(i);
            while(u != x){
                ans.push_back(val[u]);
                u = lst[u];
            }
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++){
                if(i+1 != ans.size())printf("%d ",ans[i]);
                else printf("%d\n",ans[i]);
            }
            f=1;
        }
        else{
            fa[fx]=fy;
            g[x].push_back(y);g[y].push_back(x);
            va[x].push_back(i);va[y].push_back(i);
        }
    }
    if(!f)printf("-1\n");
}

signed main(){
    scanf("%d",&T);
    while(T--){
        solve();
    }
}
