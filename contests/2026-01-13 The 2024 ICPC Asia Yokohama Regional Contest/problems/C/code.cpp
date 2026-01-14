#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n, m;
int p[N];
typedef pair<int, int> pii;
#define fi first
#define se second
vector<pii> e[N];
int dis[N];
bool vis[N];
signed main(){
    scanf("%lld%lld", &n, &m);
    for(int i=1; i<=n; ++i){
        scanf("%lld", &p[i]);
    }
    for(int i=1, x, y, z; i<=m; ++i){
        scanf("%lld%lld%lld", &x, &y, &z);
        e[x].push_back(make_pair(y, z));
        e[y].push_back(make_pair(x, z));
    }
    for(int i=2; i<=n; ++i) dis[i]=1e18;
    priority_queue<pii> pq;
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        int x=pq.top().se; pq.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(auto [y, z]:e[x]){
            if(dis[y]>dis[x]+z){
                dis[y]=dis[x]+z;
                pq.push(make_pair(-dis[y], y));
            }
        }
    }
    int ans=0;
    for(int i=1; i<=n; ++i) ans+=dis[i]*p[i];
    printf("%lld\n", ans);
}
