#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int T, n, m;
int a[N];
typedef long long ll;
vector<int> pos[N];
int mn[N<<2], cnt[N<<2], tag[N<<2];
void down(int p){
    if(tag[p]!=0){
        mn[p<<1]+=tag[p];
        mn[p<<1|1]+=tag[p];
        tag[p<<1]+=tag[p];
        tag[p<<1|1]+=tag[p];
        tag[p]=0;
    }
}
void up(int p){
    mn[p]=min(mn[p<<1], mn[p<<1|1]);
    cnt[p]=0;
    if(mn[p]==mn[p<<1]) cnt[p]+=cnt[p<<1];
    if(mn[p]==mn[p<<1|1]) cnt[p]+=cnt[p<<1|1];
}
void mdf(int p, int l, int r, int L, int R, int v){
    if(L>R) return ;
    if(L<=l&&r<=R){
        mn[p]+=v; tag[p]+=v;
        return ;
    }
    down(p);
    int mid=(l+r)>>1;
    if(L<=mid) mdf(p<<1, l, mid, L, R, v);
    if(R>mid) mdf(p<<1|1, mid+1, r, L, R, v);
    up(p);
}
void build(int p, int l, int r){
    tag[p]=0;
    if(l==r){
        mn[p]=0;
        cnt[p]=1;
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    up(p);
}
vector<pair<int, int> > add[N], del[N]; 
ll ans;
void get(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R){
        if(mn[p]==0) ans+=cnt[p];
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(L<=mid) get(p<<1, l, mid, L, R);
    if(R>mid) get(p<<1|1, mid+1, r, L, R);
    up(p);
}
int main(){
    for(int i=1; i<N; ++i) pos[i].push_back(0);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i){
        scanf("%d", &a[i]);
        pos[a[i]].push_back(i);
        int rk=pos[a[i]].size(); --rk;
        if(rk>=m){
            add[i].push_back(make_pair(pos[a[i]][rk-m]+1, pos[a[i]][rk-m+1]));
        }
        if(rk-1>=m){
            del[i].push_back(make_pair(pos[a[i]][rk-1-m]+1, pos[a[i]][rk-m]));
        }
    }
    build(1, 1, n);
    ans=0;
    for(int i=1; i<=n; ++i){
        for(auto t:add[i]){
            mdf(1, 1, n, t.first, t.second, 1);
        }
        for(auto t:del[i]){
            mdf(1, 1, n, t.first, t.second, -1);
        }
        get(1, 1, n, 1, i);
    }
    printf("%lld\n", ans);
}
