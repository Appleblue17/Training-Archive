#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n, m;
typedef pair<int, int> pii;
#define fi first
#define se second
pii a[N];
int ans[N];
int id[N];
int ql[N], qr[N];
int rt, idx;
int tr[N];
void upd(int x, int v){
    for(; x; x-=(x&-x)) tr[x]=max(tr[x], v);
}
int get(int x){
    int ret=0;
    for(; x<=n; x+=(x&-x)) ret=max(ret, tr[x]);
    return ret;
}
void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i){
        scanf("%d%d", &a[i].fi, &a[i].se);
        swap(a[i].fi, a[i].se);
    }
    vector<int> bin;
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i){
        swap(a[i].fi, a[i].se);
        bin.push_back(a[i].fi);
    }
    sort(bin.begin(), bin.end());
    bin.erase(unique(bin.begin(), bin.end()), bin.end());
    for(int i=1; i<=m; ++i){
        id[i]=i;
        scanf("%d%d", &ql[i], &qr[i]);
    }
    sort(id+1, id+m+1, [&](int x, int y){return qr[x]<qr[y];});
    int it=1;
    for(int i=1; i<=n*4; ++i) tr[i]=0;
    for(int i=1; i<=m; ++i){
        int cur=id[i];
        while(it<=n&&a[it].se<=qr[cur]){
            int rk=lower_bound(bin.begin(), bin.end(), a[it].fi)-bin.begin()+1;
            upd(rk, a[it].se-a[it].fi+1);
            ++it;
        }
        // cout<<cur<<' '<<ql[cur]<<' '<<qr[cur]<<endl;
        int rk=lower_bound(bin.begin(), bin.end(), ql[cur])-bin.begin()+1;
        ans[cur]=get(rk);
    }
    for(int i=1; i<=m; ++i){
        printf("%d\n", ans[i]);
    }
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}