#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
void read(int &x){
    x=0; char c=getchar();
    for(; c<'0'||c>'9'; c=getchar());
    for(; c>='0'&&c<='9'; c=getchar()) x=(x<<1)+(x<<3)+(c^48);
}
void readll(ll &x){
    x=0; char c=getchar();
    for(; c<'0'||c>'9'; c=getchar());
    for(; c>='0'&&c<='9'; c=getchar()) x=(x<<1ll)+(x<<3ll)+(c^48);
}
int n, idx; ll m;
set<pair<ll, int> > bin[N];
ll dt1[N]; int dt2[N];
#define fi first
#define se second
#define mapa make_pair
vector<pair<int, ll> > e[N];
int sz[N], son[N]; ll w[N];
int rt[N];
void dfs(int x){
    sz[x]=1; rt[x]=x;
    for(auto edg:e[x]){
        w[edg.fi]=edg.se;
        dfs(edg.fi);
        sz[x]+=sz[edg.fi];
        if(sz[son[x]]<sz[edg.fi]) son[x]=edg.fi;
    }
}
int ans=0;
void append(int id, ll x, int y){
    set<pair<ll, int> >::iterator it=bin[id].lower_bound(mapa(x, -1));
    if(it!=bin[id].end()&&(*it).fi==x){
        if(y<=(*it).se) return ;
    }
    if(it!=bin[id].begin()){
        --it;
        if((*it).se>=y) return ;
        ++it;
    }
    set<pair<ll, int> >::iterator p=it;
    while(p!=bin[id].end()){
        if((*p).se<=y){
            ++p;
        }
        else{
            break ;
        }
    }
    bin[id].erase(it, p);
    bin[id].insert(mapa(x, y));
}
void dfs2(int x){
    if(!son[x]) return ;
    dfs2(son[x]);
    rt[x]=rt[son[x]];
    dt1[rt[x]]+=w[son[x]]; dt2[rt[x]]+=(x>n);
    set<pair<ll, int> >::iterator it=bin[rt[x]].end();
    while(it!=bin[rt[x]].begin()){
        --it;
        if((*it).fi+dt1[rt[x]]<=m){
            ++it; break;
        }
    }
    bin[rt[x]].erase(it, bin[rt[x]].end());
    append(rt[x], 0ll-dt1[rt[x]], (x>n)-dt2[rt[x]]);
    if(!bin[rt[x]].empty()){
        ans=max(ans, (*bin[rt[x]].rbegin()).se+dt2[rt[x]]);
    }
    int y;
    for(auto edg:e[x]){
        y=edg.fi;
        if(y!=son[x]){
            dfs2(y);
            for(auto [dis, val]:bin[rt[y]]){
                dis=dis+dt1[rt[y]]+w[y]; val=val+dt2[rt[y]];
                if(dis>m) continue;
                it=bin[rt[x]].upper_bound(mapa(m-dis-dt1[rt[x]], 1e9));
                if(it!=bin[rt[x]].begin()){
                    --it;
                    ans=max(ans, val+(*it).se+dt2[rt[x]]);
                }
            }
            for(auto [dis, val]:bin[rt[y]]){
                dis=dis+dt1[rt[y]]+w[y]; val=val+dt2[rt[y]];
                if(dis>m) continue;
                append(rt[x], dis-dt1[rt[x]], val-dt2[rt[x]]);
            }
            bin[rt[y]].clear();
        }
    }
}
int main(){
    read(n); readll(m);
    idx=n;
    {
        int x; ll y; int z; ll w;
        for(int i=2; i<=n; ++i){
            read(x); readll(y); read(z);
            int lst=x; ll pre=0;
            for(int j=1; j<=z; ++j){
                readll(w);
                e[lst].push_back(mapa(idx+1, w-pre));
                pre=w; lst=idx+1; ++idx;
            }
            e[lst].push_back(mapa(i, y-pre));
        }
    }
    dfs(1);
    dfs2(1);
    printf("%d\n", ans);
}
