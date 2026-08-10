#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,INF=1e18;
int T,n,m,k;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
vector<pii> bin[N];
int it[N];
int ans[N];
int c[N];
void solve(){
    scanf("%lld%lld%lld", &n, &m, &k);
    k=min(k, n);
    for(int i=1; i<=n; ++i) bin[i].clear(), it[i]=0;
    for(int i=1, a, b; i<=m; ++i){
        scanf("%lld%lld%lld", &a, &b, &c[i]);
        bin[a].push_back(mapa(b, i));
    }
    multiset<pii> s;
    for(int i=1; i<=k; ++i) s.insert(mapa(0, 0));
    priority_queue<pii> pq;
    for(int i=1; i<=n; ++i) if(!bin[i].empty()){
        pq.push(mapa(-bin[i][0].fi, i));
    }
    while(!s.empty()){
        pii x=*s.begin();
        s.erase(s.find(x));
        if(x.se!=0){
            int id=x.se;
            ++it[id];
            if(it[id]<(int)bin[id].size()){
                pq.push(mapa(-bin[id][it[id]].fi, id));
            }
        }
        if(pq.empty()){
            continue;
        }
        pii cur=pq.top(); pq.pop();
        int id=cur.se;
        int pos=it[id];
        int reff=bin[id][pos].se;
        int tim=max(x.fi, -cur.fi);
        ans[reff]=tim;
        s.insert(mapa(tim+c[reff], id));
    }
    for(int i=1; i<=m; ++i) printf("%lld ", ans[i]);
    putchar('\n');
}
signed main(){
    scanf("%lld", &T);
    while(T--){
        solve();
    }
}