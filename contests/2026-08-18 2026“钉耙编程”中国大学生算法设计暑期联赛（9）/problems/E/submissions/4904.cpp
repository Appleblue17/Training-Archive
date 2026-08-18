#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=998244353;
// #define int long long
int Test, n, m;
int rd(){
    char c=getchar();
    int tot=0;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}
int a[N], b[N];
int sz[N*40], ls[N*40], rs[N*40];
int idx;
int nxt[N];
int rt[N];
void del(int &p, int l, int r, int L){
    if(!p) return ;
    if(L<=l){
        p=++idx;
        return ;
    }
    int mid=(l+r)>>1;
    ++idx;
    ls[idx]=ls[p]; rs[idx]=rs[p];
    p=idx;
    if(L>mid){
        del(rs[p], mid+1, r, L);
        sz[p]=sz[ls[p]]+sz[rs[p]];
        return ;
    }
    rs[p]=0;
    del(ls[p], l, mid, L);
    sz[p]=sz[ls[p]]+sz[rs[p]];
}
void add(int &p, int l, int r, int x){
    ++idx; sz[idx]=sz[p]+1; ls[idx]=ls[p]; rs[idx]=rs[p]; p=idx;
    if(l==r) return ;
    int mid=(l+r)>>1;
    if(x<=mid) add(ls[p], l, mid, x);
    else add(rs[p], mid+1, r, x);
}
int get(int p, int l, int r, int L){
    if(!p) return 0;
    if(L<=l) return sz[p];
    int mid=(l+r)>>1;
    if(L>mid) return get(rs[p], mid+1, r, L);
    return sz[rs[p]]+get(ls[p], l, mid, L);
}
void solve(){
    n=rd();
    for(int i=1; i<=n; ++i) a[i]=rd(), b[i]=a[i];
    sort(b+1, b+n+1);
    m=unique(b+1, b+n+1)-b-1;
    for(int i=1; i<=n; ++i) a[i]=lower_bound(b+1, b+m+1, a[i])-b;
    for(int i=1; i<=idx; ++i) sz[i]=ls[i]=rs[i]=0;
    idx=0;
    for(int i=1; i<=n; ++i){
        rt[i]=rt[i-1];
        if(a[i]!=m) del(rt[i], 1, m, a[i]+1);
        add(rt[i], 1, m, a[i]);
    }
    for(int i=2, j=0; i<=n; ++i){
        bool flg=0;
        while(true){
            if(get(rt[j], 1, m, a[i]+1)==get(rt[j], 1, m, a[j+1]+1)){
                flg=1; break;
            }
            if(j==0) break;
            j=nxt[j];
        }
        if(flg) ++j;
        nxt[i]=j;
    }
    for(int i=1; i<=n; ++i) printf("%d%c", nxt[i], " \n"[i==n]);
}
signed main(){
    // freopen("5.out", "w", stdout);
    Test=rd();
    while(Test--){
        solve();
    }
    
    
}