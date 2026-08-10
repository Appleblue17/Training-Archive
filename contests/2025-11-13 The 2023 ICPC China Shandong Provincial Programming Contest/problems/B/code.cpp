#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
int n, m;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
pii a[N];
int lenb[N], lenc[N];
vector<pii> b[N], c[N];
unordered_map<int, vector<pii> > h;
unordered_map<int, ll> cnt;
unordered_map<int, int> it;
int sz[N];
queue<int> que;
void upd(int x, int y){
    cnt[x]+=y;
    while(it[x]<(int)h[x].size()&&cnt[x]>=h[x][it[x]].fi){
        --sz[h[x][it[x]].se];
        if(sz[h[x][it[x]].se]==0){
            que.push(h[x][it[x]].se);
        }
        ++it[x];
    }
}
signed main(){
    scanf("%d", &m);
    for(int i=1; i<=m; ++i){
        scanf("%d%d", &a[i].fi, &a[i].se);
    }
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d", &lenb[i]);
        b[i].resize(lenb[i]);
        for(int j=0; j<lenb[i]; ++j){
            scanf("%d%d", &b[i][j].fi, &b[i][j].se);
            h[b[i][j].fi].push_back(mapa(b[i][j].se, i));
        }
        sz[i]=lenb[i];
        if(sz[i]==0){
            que.push(i);
        }
        scanf("%d", &lenc[i]);
        c[i].resize(lenc[i]);
        for(int j=0; j<lenc[i]; ++j){
            scanf("%d%d", &c[i][j].fi, &c[i][j].se);
        }
    }
    for(auto &t:h){
        sort(t.se.begin(), t.se.end());
        it[t.fi]=0;
    }
    for(int i=1; i<=m; ++i){
        upd(a[i].fi, a[i].se);
    }
    int ans=0;
    while(!que.empty()){
        ++ans;
        int x=que.front(); que.pop();
        for(auto t:c[x]){
            upd(t.fi, t.se);
        }
    }
    printf("%d\n", ans);
}
