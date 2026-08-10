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
int tr[N*60], ls[N*60], rs[N*60];
int gen(){
    ++idx;
    tr[idx]=0; ls[idx]=0; rs[idx]=0;
    return idx;
}
void add(int &p, int l, int r, int x, int v){
    if(!p){
        p=gen();
    }
    tr[p]=max(tr[p], v);
    if(l==r) return ;
    int mid=(l+r)>>1;
    if(x<=mid) add(ls[p], l, mid, x, v);
    else add(rs[p], mid+1, r, x, v);
}
int get(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R){
        return tr[p];
    }
    int mid=(l+r)>>1, ret=0;
    if(L<=mid) ret=get(ls[p], l, mid, L, R);
    if(R>mid) ret=max(ret, get(rs[p], mid+1, r, L, R));
    return ret;
}
void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i){
        scanf("%d%d", &a[i].fi, &a[i].se);
        swap(a[i].fi, a[i].se);
    }
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i){
        swap(a[i].fi, a[i].se);
    }
    for(int i=1; i<=m; ++i){
        id[i]=i;
        scanf("%d%d", &ql[i], &qr[i]);
    }
    sort(id+1, id+m+1, [&](int x, int y){return qr[x]<qr[y];});
    int it=1;
    idx=0; rt=0;
    
    for(int i=1; i<=m; ++i){
        int cur=id[i];
        while(it<=n&&a[it].se<=qr[cur]){
            add(rt, 1, 1e9, a[it].fi, a[it].se-a[it].fi+1);
            ++it;
        }
        // cout<<cur<<' '<<ql[cur]<<' '<<qr[cur]<<endl;
        ans[cur]=get(rt, 1, 1e9, ql[cur], qr[cur]);
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