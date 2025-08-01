#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,mod=1e9+7;
typedef long long ll;
int T, n, m;
int p[N];
ll a[N], b[N];
vector<int> e[N];
ll ans[N];
set<pair<ll, int> > bin[N];
int fa[N]; ll sum[N];
bool sta[N];
int get(int x){
    if(x==fa[x]) return x;
    return get(fa[x]);
}
int main() {
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; ++i) e[i].clear(), bin[i].clear();
        for(int i=1; i<=n; ++i) scanf("%lld", &a[i]), p[i]=i;
        for(int i=1; i<=n; ++i) scanf("%lld", &b[i]);
        sort(p+1, p+n+1, [&](int x, int y){return a[x]<a[y];});
        for(int i=1, x, y; i<n; ++i){
            scanf("%d%d", &x, &y);
            e[x].push_back(y); e[y].push_back(x);
        }
        for(int i=1; i<=m; ++i){
            int x; ll y;
            scanf("%d%lld\n", &x, &y);
            if(y<a[x]){
                ans[i]=y;
            }
            else{
                bin[x].insert(make_pair(y, i));
            }
        }
        for(int i=1; i<=n; ++i) fa[i]=i, sum[i]=b[i], sta[i]=0;
        for(int i=1; i<=n; ++i){
            int x=p[i]; sta[x]=1; int fx=x;
            for(auto y:e[x]) if(sta[y]){
                int fy=get(y);
                while(!bin[fy].empty()){
                    pair<ll, int> cur=*bin[fy].begin();
                    if(cur.first+sum[fy]<a[x]){
                        ans[cur.second]=cur.first+sum[fy];
                        bin[fy].erase(bin[fy].begin());
                    }
                    else{
                        break;
                    }
                }
                if(bin[fy].size()>=bin[fx].size()){
                    sum[fy]+=sum[fx];
                    for(auto t:bin[fx]) bin[fy].insert(t);
                    fa[fx]=fy;
                    fx=fy;
                }
                else{
                    sum[fx]+=sum[fy];
                    for(auto t:bin[fy]) bin[fx].insert(t);
                    fa[fy]=fx;
                }
            }
        }
        int rt=get(1);
        for(auto t:bin[rt]){
            ans[t.second]=sum[rt]+t.first;
        }
        for(int i=1; i<=m; ++i){
            printf("%lld\n", ans[i]);
        }
    }
}