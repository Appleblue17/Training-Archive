#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
typedef long long ll;
const ll inf=1e15;
int n, m, S, T;
int tot;
int lin[N], to[N], nxt[N]; ll val[N];
int way[N];
void in(int x, int y, ll z){
    //cout<<x<<' '<<y<<' '<<z<<endl;
    to[++tot]=y; val[tot]=z; nxt[tot]=lin[x]; lin[x]=tot;
}
int dep[N];
bool bfs(){
    for(int i=1; i<=T; ++i) dep[i]=0;
    queue<int> q;
    q.push(S);
    dep[S]=1; way[S]=lin[S];
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int i=lin[x]; i; i=nxt[i]){
            int y=to[i];
            if(val[i]&&(!dep[y])){
                dep[y]=dep[x]+1;
                way[y]=lin[y];
                if(y==T) return 1;
                q.push(y);
            }
        }
    }
    return 0;
}
ll dfs(int x, ll now){
    if(x==T) return now;
    ll ret=0;
    for(int i=way[x]; i&&ret<now; i=nxt[i]){
        int y=to[i];
        way[x]=i;
        if(val[i]&&dep[y]==dep[x]+1){
            ll res=dfs(y, min(val[i], now-ret));
            if(res==0) dep[y]=0;
            val[i]-=res;
            val[i^1]+=res;
            ret+=res;
        }
    }
    return ret;
}
ll calc(){
    ll ans=0; ll fl=0;
    while(bfs()){
        fl=dfs(S, inf);
        ans+=fl;
        while(fl){
            fl=dfs(S, inf);
            ans+=fl;
        }
    }
    return ans;
}
int main(){
    tot=1;
    scanf("%d%d", &n, &m);
    if(n==1){
        int c; scanf("%d", &c);
        printf("%d\n", c);
        return 0;
    }
    for(int i=1, v; i<n; ++i){
        scanf("%d", &v);
        in(i+n-1, i, v);
        in(i, i+n-1, 0);
    }
    S=3*n; T=3*n+1;
    for(int i=1, v; i<=n; ++i){
        scanf("%d", &v);
        if(i==1) {
            in(3*n-2, i+n-1, v);
            in(i+n-1, 3*n-2, v);
        }
        else if(i==n){
            in(2*n-2, 3*n-1, v);
            in(3*n-1, 2*n-2, v);
        }
        else{
            in(i-1+n-1, i+n-1, v);
            in(i+n-1, i-1+n-1, v);
        }
    }
    for(int i=1, v; i<n; ++i){
        scanf("%d", &v);
        in(i+2*n-2, i+n-1, v);
        in(i+n-1, i+2*n-2, 0);
    }
    for(int i=1; i<n; ++i){
        in(S, i+2*n-2, inf);
        in(i+2*n-2, S, 0);
        in(i, T, inf);
        in(T, i, 0);
    }
    in(S, 3*n-2, inf);
    in(3*n-2, S, 0);
    in(3*n-1, T, inf);
    in(T, 3*n-1, 0);
    while(m--){
        int i, j, v;
        scanf("%d%d%d", &i, &j, &v);
        in(j+n-1, i+n-1, 0);
        in(i+n-1, j+n-1, v);
        //in(i+2*n-2, j, 0);
        //in(j, i+2*n-2, v);
    }
    printf("%lld\n", calc());
}
