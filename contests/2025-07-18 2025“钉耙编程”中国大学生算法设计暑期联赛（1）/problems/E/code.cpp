#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=500005,INF=1e9;
int T, n, m;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
vector<pii> e[N];
void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) e[i].clear();
    for(int i=1, x, y, z; i<=m; ++i){
        scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(mapa(y, z));
        e[y].push_back(mapa(x, z));
    }
    deque<pair<int, int> > que;
    int ans=INF;
    map<pii, int> h;
    que.push_back(mapa(1, 0));
    while(!que.empty()){
        int col=que.front().se, x=que.front().fi;
        que.pop_front();
        if(x==n) ans=min(ans, h[mapa(x, col)]);
        for(auto edg:e[x]){
            int y=edg.fi, cur=edg.se;
            if(h.find(mapa(y, cur))==h.end()){
                h[mapa(y, cur)]=h[mapa(x, col)]+(cur!=col);
                if(cur==col) que.push_front(mapa(y, cur));
                else que.push_back(mapa(y, cur));
            }
        }
    }
    printf("%d\n", ans);
}
signed main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}