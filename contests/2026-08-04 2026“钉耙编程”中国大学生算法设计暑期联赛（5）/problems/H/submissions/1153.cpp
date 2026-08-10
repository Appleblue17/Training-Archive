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
int tr[N<<2];
void add(int p, int l, int r, int x, int v){
    tr[p]=max(tr[p], v);
    if(l==r) return ;
    int mid=(l+r)>>1;
    if(x<=mid) add(p<<1, l, mid, x, v);
    else add(p<<1|1, mid+1, r, x, v);
}
int get(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R){
        return tr[p];
    }
    int mid=(l+r)>>1, ret=0;
    if(L<=mid) ret=get(p<<1, l, mid, L, R);
    if(R>mid) ret=max(ret, get(p<<1|1, mid+1, r, L, R));
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
            add(rt, 1, n, a[it].fi, a[it].se-a[it].fi+1);
            ++it;
        }
        // cout<<cur<<' '<<ql[cur]<<' '<<qr[cur]<<endl;
        int rk=upper_bound(bin.begin(), bin.end(), ql[cur])-bin.begin();
        ans[cur]=get(rt, 1, n, rk, n);
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