#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n, m;
int a[N];
int tr[N];
void upd(int x, int v){
    for(; x>0; x-=(x&-x)) tr[x]=max(tr[x], v);
}
int get(int x){
    int ret=1;
    for(; x<=n; x+=(x&-x)) ret=max(ret, tr[x]);
    return ret;
}
vector<int> fac[N];
int ans[N];
vector<pair<int, int> > qry[N];
int pos[N][2];
signed main(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=2; i<N; ++i){
        for(int j=i; j<N; j+=i) fac[j].push_back(i);
    }
    scanf("%d", &m);
    for(int i=1, l, r; i<=m; ++i){
        scanf("%d%d", &l, &r);
        qry[r].emplace_back(l, i);
    }
    for(int i=1; i<=n; ++i){
        for(auto t:fac[a[i]]){
            pos[t][1]=pos[t][0]; pos[t][0]=i;
            upd(pos[t][1], t);
        }
        for(auto [l, id]:qry[i]) ans[id]=get(l);
    }
    for(int i=1; i<=m; ++i) printf("%d\n", ans[i]);
}
