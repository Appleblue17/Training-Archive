#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int st;
const int N=5e5+5, M=1e7+5;
int lin[N], to[M], nxt[M];
int val[M], tot;
int way[N];
void in(int x, int y, int z){
    to[++tot]=y; val[tot]=z;
    nxt[tot]=lin[x]; lin[x]=tot;
}
int dep[N]; 
int ed;
int S, T;
bool bfs(){
    for(int i=1; i<=T; ++i) dep[i]=0;
    queue<int> q;
    q.push(S);
    dep[S]=1; way[S]=lin[S];
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int i=lin[x]; i; i=nxt[i]){
            int y=to[i];
            if(val[i]&&(!dep[y])) {
                dep[y]=dep[x]+1;
                way[y]=lin[y];
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
    for(int i=way[x]; i&&ret<now; i=nxt[i]){
        int y=to[i]; way[x]=i;
        if(val[i]&&dep[y]==dep[x]+1){
            int res=dfs(y, min(val[i], now-ret));
            if(res==0) dep[y]=0;
            val[i]-=res;
            val[i^1]+=res;
            ret+=res;
        }
    }
    return ret;
}
int n;
char s[201][200001];
int sz[201];
const int p1=998244353, p2=993244853;
struct hsh{
    int x, y;
}bs, pw[N];
bool check(int K){
    T=0;
    int sum1=0, sum2=0;
    for(int i=1; i<=n; ++i) {
        if(sz[i]<K) continue;
        sum1+=sz[i]*2-K+1, sum2++;
    }
    if(sum2==0){
        return true;
    }
    T=sum1+sum2;
    S=T+1; T+=2;
    for(int i=1; i<=T; ++i) lin[i]=0;
    tot=1;
    unordered_map<long long, int> h;
    int idx=0;
    sum2=sum1;
    for(int i=1; i<=n; ++i){
        if(sz[i]<K) continue;
        ++sum2;
        in(S, sum2, 1);
        in(sum2, S, 0);
        hsh cur=(hsh){0, 0};
        for(int j=1; j<=K; ++j){
            cur.x=(131ll*cur.x+s[i][j])%p1;
            cur.y=(13331ll*cur.y+s[i][j])%p2;
        }
        for(int j=1; j+K-1<=sz[i]*2; ++j){
            if(h.find(1ll*cur.x*(p2+1)+cur.y)==h.end()){
                h[1ll*cur.x*(p2+1)+cur.y]=++idx;
            }
            int cid=h[1ll*cur.x*(p2+1)+cur.y];
            in(sum2, cid, 1); in(cid, sum2, 0);
            cur.x=131ll*cur.x%p1;
            cur.y=13331ll*cur.y%p2;
            cur.x=(1ll*cur.x+p1-1ll*s[i][(j-1)%sz[i]+1]*pw[K].x%p1+s[i][(j+K-1)%sz[i]+1])%p1;
            cur.y=(1ll*cur.y+p2-1ll*s[i][(j-1)%sz[i]+1]*pw[K].y%p2+s[i][(j+K-1)%sz[i]+1])%p2;
        }
    }
    if(idx<sum2-sum1){
        return false;
    }
    for(int i=1; i<=idx; ++i) {
        in(i, T, 1); in(T, i, 0);
    }
    int ans=0, fl=0;
    while(bfs()){
        while(fl=dfs(S, sum2-sum1)){
            ans+=fl;
        }
    }
    return ans==sum2-sum1;
}
int main(){
    scanf("%d", &n);
    pw[0]=(hsh){1, 1};
    for(int i=1; i<N; ++i){
        pw[i].x=131ll*pw[i-1].x%p1;
        pw[i].y=13331ll*pw[i-1].y%p2;
    }
    int L=1, R=1, mid, ret=1;
    for(int i=1; i<=n; ++i){
        scanf("%s", s[i]+1);
        sz[i]=strlen(s[i]+1);
        R=max(R, sz[i]);
    }
    ret=R+1;
    while(L<=R){
        mid=(L+R)/2;
        if(check(mid)) {
            ret=mid; R=mid-1;
        }
        else{
            L=mid+1;
        }
    }
    printf("%d\n", ret);
}