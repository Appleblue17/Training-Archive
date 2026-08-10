#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N=2e6+5;
int T,n;
vector<int> e[N];
int deg[N];
int sz[N];
int ft[N];
void dfs(int x, int fa){
    ft[x]=fa;
    sz[x]=1;
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y, x);
        sz[x]+=sz[y];
    }
}
int cnt[N];
bool flag[N];
int f2;
void dfs2(int x, int fa){
    flag[x]=0;
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs2(y, x);
        flag[x]|=flag[y];
    }
    if(flag[x]&&cnt[x]>=4){
        f2=1;
    }
    if(cnt[x]<2) flag[x]=0;
    else flag[x]|=cnt[x]>=4;
}
void solve(){
    //scanf("%d",&n);
    for(int i=1;i<=n;i++)deg[i]=0, e[i].clear();
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        deg[u]++;deg[v]++;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int f=0;
    for(int i=1;i<=n;i++){
        if(deg[i]>2)f=1;
    }
    if(f==0){
        printf("1\n");
        return ;
    }
    f=0;
    dfs(1, 0);
    for(int x=1; x<=n; ++x){
        cnt[x]=0;
        for(auto y:e[x]){
            if(y==ft[x]) continue;
            if(sz[y]>=2) ++cnt[x];
        }
        if(n-sz[x]>=2) ++cnt[x];
        if(cnt[x]>=5){
            f=1;
        }
    }
    for(int x=1; x<=n; ++x){
        for(auto y:e[x]){
            if(cnt[x]>=4&&cnt[y]>=4){
                f=1;
            }
        }
    }
    f2=0;
    dfs2(1, 0);
    if(f==0&&f2==0){
        printf("2\n");
        return ;
    }
    printf("%d\n", 3);
}

signed main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        solve();
    }
}
