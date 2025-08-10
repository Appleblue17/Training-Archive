#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int inf=1e9;
const int N=1e6+5;
int n, m, s, f;
vector<pair<int, int> > e[N];
priority_queue<pair<int, int> > pq;
int dis[N]; bool vis[N];
unordered_map<int, int> h[N];
int idx;
void dij(int S){
    for(int i=1; i<=idx; ++i) dis[i]=inf*inf;
    for(auto t:h[S]) dis[t.second]=0, pq.push(make_pair(0, t.second));
    while(!pq.empty()){
        int x=pq.top().second; pq.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(auto edg:e[x]){
            int y=edg.second, z=edg.first;
            if(dis[y]>dis[x]+z){
                dis[y]=dis[x]+z;
                pq.push(make_pair(-dis[y], y));
            }
        }
    }
}
signed main(){
    scanf("%lld%lld%lld%lld", &n, &m, &s, &f);
    idx=1;
    for(int i=1; i<=m; ++i){
        int x, xx, y, yy;
        scanf("%lld%lld%lld%lld", &x, &xx, &y, &yy);
        if(h[x].find(xx)==h[x].end()) h[x][xx]=++idx;
        if(h[y].find(yy)==h[y].end()) h[y][yy]=++idx;
        e[h[x][xx]].push_back(make_pair(1, h[y][yy]));
        e[h[y][yy]].push_back(make_pair(1, h[x][xx]));
    }
    for(int i=1; i<=n; ++i){
        ++idx;
        for(auto x:h[i]){
            e[idx].push_back(make_pair(0, x.second));
            e[x.second].push_back(make_pair(inf, idx));
        }
    }
    dij(s);
    int mn=1e18;
    for(auto t:h[f]) mn=min(mn, dis[t.second]);
    printf("%lld %lld\n", mn/inf, mn%inf);
}