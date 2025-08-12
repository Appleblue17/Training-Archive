#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int T, n;
int son[N][2];
ll f[N][30];
int dep[N], sz[N];
int ans;
void dfs(int x){
    if(dep[x]>=30){
        ++ans;
    }
    if(son[x][0]){
        dep[son[x][0]]=dep[x]+1;
        dfs(son[x][0]);
        if(dep[son[x][0]]>=30) son[x][0]=0;
    }
    if(son[x][1]){
        dep[son[x][1]]=dep[x]+1;
        dfs(son[x][1]);
        if(dep[son[x][1]]>=30) son[x][1]=0;
    }
}
void dfs2(int x){
    sz[x]=1;
    if(son[x][0]) dfs2(son[x][0]), sz[x]+=sz[son[x][0]];
    if(son[x][1]) dfs2(son[x][1]), sz[x]+=sz[son[x][1]];
    f[x][0]=sz[x]; 
    for(int i=1; i<30; ++i){
        f[x][i]=1e18;
        f[x][i]=min(f[x][i], f[son[x][0]][i-1]+f[son[x][1]][i-1]);
        if(i>1){
            f[x][i]=min(f[x][i], f[son[x][0]][i-2]+f[son[x][1]][i-1]);
            f[x][i]=min(f[x][i], f[son[x][0]][i-1]+f[son[x][1]][i-2]);
        }
    }
}
void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d%d", &son[i][0], &son[i][1]);
    f[0][1]=1; f[0][2]=2;
    for(int i=3; i<30; ++i) f[0][i]=f[0][i-1]+f[0][i-2]+1;
    ans=0;
    dfs(1);
    dfs2(1);
    ll res=1e18;
    for(int i=0; i<30; ++i) res=min(res, f[1][i]);
    printf("%lld\n", res+ans);
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
