#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
int n, m;
vector<pii> e[N];
int val[N], p[N];

namespace dis1{
    int dis[N]; bool v[N];
    void solve(){
        priority_queue<pii> q;
        for(int i=1; i<=n; ++i) dis[i]=1e9;
        dis[1]=0; q.push(mapa(0, 1));
        while(!q.empty()){
            int x=q.top().se; q.pop();
            if(v[x]) continue;
            v[x]=1;
            for(auto [y, id]:e[x]) {
                if(dis[y]>dis[x]+1){
                    dis[y]=dis[x]+1;
                    q.push(make_pair(-dis[y], y));
                }
            }
        }
    }
}
namespace dis2{
    int dis[N]; bool v[N];
    int fr[N], fa[N];
    int f[N][20];
    int dis2[N];
    bool ontree[N];
    vector<int> g[N];
    int lca(int x, int y){
        if(dis[x]<dis[y]) swap(x, y);
        for(int i=19; i>=0; --i) if(dis[f[x][i]]>=dis[y]) x=f[x][i];
        if(x==y) return x;
        for(int i=19; i>=0; --i) if(f[x][i]!=f[y][i]) x=f[x][i], y=f[y][i];
        return f[x][0];
    }
    struct myheap{
        priority_queue<int> p, q;
        void push(int x){
            p.push(-x);
        }
        void pop(int x){
            q.push(-x);
        }
        int top(){
            while(!q.empty()&&p.top()==q.top()) p.pop(), q.pop();
            if(p.empty()) return 1e9;
            return -p.top();
        }
        int sz(){
            return p.size()+q.size();
        }
    }st[N];
    int strt[N];
    vector<int> add[N], del[N];
    void dfs(int x){
        if(g[x].empty()){
            strt[x]=x;
            for(auto t:add[x]) st[x].push(t);
            for(auto t:del[x]) st[x].pop(t);
            dis2[x]=st[x].top()-dis[x];
            return ;
        }
        for(auto y:g[x]) dfs(y);
        sort(g[x].begin(), g[x].end(), [&](int x, int y){return st[strt[x]].sz()>st[strt[y]].sz();});
        strt[x]=strt[g[x][0]];
        for(int i=1, y; i<(int)g[x].size(); ++i){
            y=g[x][i];
            while(!st[strt[y]].p.empty()) st[strt[x]].p.push(st[strt[y]].p.top()), st[strt[y]].p.pop();
            while(!st[strt[y]].q.empty()) st[strt[x]].q.push(st[strt[y]].q.top()), st[strt[y]].q.pop();
        }
        for(auto t:add[x]) st[strt[x]].push(t);
        for(auto t:del[x]) st[strt[x]].pop(t);
        dis2[x]=st[strt[x]].top()-dis[x];
    }
    void solve(){
        priority_queue<pii> q;
        for(int i=1; i<=n; ++i) dis[i]=1e9;
        dis[n]=0; q.push(mapa(0, n));
        while(!q.empty()){
            int x=q.top().se; q.pop();
            if(v[x]) continue;
            v[x]=1;
            for(auto [y, id]:e[x]) {
                if(dis[y]>dis[x]+1){
                    dis[y]=dis[x]+1; fr[y]=id; fa[y]=x;
                    q.push(make_pair(-dis[y], y));
                }
            }
        }
        dis[0]=-1;
        for(int i=1; i<n; ++i) ontree[fr[i]]=1;
        for(int i=1; i<n; ++i) g[fa[i]].push_back(i), f[i][0]=fa[i];
        for(int i=1; i<20; ++i) for(int j=1; j<=n; ++j) f[j][i]=f[f[j][i-1]][i-1];
        for(int x=1; x<n; ++x) {
            for(auto [y, id]:e[x]) if(!ontree[id]){
                add[x].push_back(dis[x]+dis[y]+1);
                del[lca(x, y)].push_back(dis[x]+dis[y]+1);
            }
        }
        dfs(n);
        dis2[n]=0;
    }
}
int dis[N]; bool v[N];
bool check(int lim){
    if(dis2::dis2[1]>lim) return false;
    priority_queue<pii> q;
    for(int i=1; i<=n; ++i) dis[i]=1e9, v[i]=0;
    dis[1]=0; q.push(mapa(0, 1));
    while(!q.empty()){
        int x=q.top().se; q.pop();
        if(v[x]) continue;
        v[x]=1;
        for(auto [y, id]:e[x]) {
            if(dis[x]+1+dis2::dis2[y]<=lim&&dis[y]>dis[x]+1){
                dis[y]=dis[x]+1;
                q.push(make_pair(-dis[y], y));
            }
        }
    }
    return dis[n]!=1e9;
}
signed main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) p[i]=i;
    for(int i=1, x, y; i<=m; ++i){
        scanf("%d%d", &x, &y);
        e[x].push_back(mapa(y, i)); e[y].push_back(mapa(x, i));
    }
    dis1::solve();
    dis2::solve();
    int L=1, R=2*n, mid, ret=-1;
    while(L<=R){
        mid=(L+R)>>1;
        if(check(mid)){
            ret=mid; R=mid-1;
        }
        else{
            L=mid+1;
        }
    }
    printf("%d\n", ret);
}
