#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int Task, n, m, S, T;
int lin[N], nxt[N], to[N], tot, f[N];
void in(int x, int y, int z){
    nxt[++tot]=lin[x]; lin[x]=tot; to[tot]=y; f[tot]=z;
    nxt[++tot]=lin[y]; lin[y]=tot; to[tot]=x; f[tot]=0;
}
int dep[N], cur[N];
bool bfs(){
    for(int i=1; i<=T; ++i){
        dep[i]=0; cur[i]=0;
    }
    queue<int> q;
    dep[S]=1; cur[S]=lin[S]; q.push(S);
    while(q.size()){
        int x=q.front(); q.pop();
        for(int i=lin[x]; i; i=nxt[i]){
            int y=to[i], z=f[i];
            if(z&&dep[y]==0){
                dep[y]=dep[x]+1; cur[y]=lin[y];
                if(y==T) return true;
                q.push(y);
            }
        }
    }
    return false;
}
int dfs(int x, int now){
    if(x==T) return now;
    int ret=0;
    for(int i=cur[x]; i&&ret<now; i=nxt[i]){
        int y=to[i], z=f[i];
        cur[x]=i;
        if(z&&dep[y]==dep[x]+1){
            int res=dfs(y, min(z, now-ret));
            if(res==0) dep[y]=0;
            f[i]-=res; f[i^1]+=res;
            ret+=res;
        }
    }
    return ret;
}
int dinic(){
    int ret=0, fl=0;
    while(bfs()){
        fl=dfs(S, 1e9);
        while(fl) ret+=fl, fl=dfs(S, 1e9);
    }
    return ret;
}
int px[N], py[N];
int col[N];
int ans[N];
void build(){
    for(int i=1; i<=T; ++i) lin[i]=0;
    tot=1;
    for(int i=1; i<=n*2; ++i){
        if(col[i]==1) in(S, i, 1);
        else in(i, T, 1);
    }
    for(int i=1; i<=m; ++i){
        if(col[px[i]]==1) in(px[i], py[i], 1);
        else in(py[i], px[i], 1);
    }
}
void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i){
        col[i]=1; col[i+n]=2;
        ans[i]=ans[i+n]=0;
    }
    for(int i=1; i<=m; ++i){
        scanf("%d%d", &px[i], &py[i]);
        py[i]+=n;
    }
    S=2*n+1, T=S+1;
    build();
    dinic();
    for(int i=lin[S]; i; i=nxt[i]){
        int x=to[i];
        if(!dep[x]&&!f[i]) ans[x]=1;
    }
    for(int i=1; i<=n; ++i){
        col[i]=2; col[i+n]=1;
    }
    build();
    dinic();
    for(int i=lin[S]; i; i=nxt[i]){
        int x=to[i];
        if(!dep[x]&&!f[i]) ans[x]=1;
    }
    int ca=n, cb=n;
    for(int i=1; i<=n; ++i) ca-=ans[i], cb-=ans[i+n];
    printf("%lld\n", 1ll*ca*cb);
}
int main(){
    scanf("%d", &Task);
    while(Task--){
        solve();
    }
}
