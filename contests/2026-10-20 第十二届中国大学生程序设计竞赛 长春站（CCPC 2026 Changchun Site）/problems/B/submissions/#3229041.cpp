#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define fi first
#define se second
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
#define ep emplace_back
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=1e5+5;
const ll inf=1e18;
int S, T;
int n, m, W, H, K;
int fa[N];
int val[N], w[N];
vector<pii> sch[N];
int fl[N];
ll h[N], dis[N]; pii fr[N];
bool vis[N];
vector<pil> e[N], g[N];
unordered_map<int, int> mp[N];
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n); read(m); read(W); read(H); read(K);
    for(int i=1; i<=W+H; ++i) read(fa[i]);
    for(int i=1; i<=W; ++i) read(val[i]);
    int idx=W+H+n*m+2;
    for(int i=W+1, l, d, t; i<=W+H; ++i){
        read(l);
        for(int j=1; j<=l; ++j){
            read(d); read(t);
            ++idx;
            sch[i].ep((d-1)*m+t+W+H, idx);
            mp[i][(d-1)*m+t+W+H]=idx;
        }
    }
    for(int i=1; i<=W; ++i) w[i]=val[i]-val[fa[i]];
    S=W+H+n*m+1; T=S+1;
    for(int i=1; i<=W+H; ++i) if(fa[i]==0) fa[i]=S;
    ll ans=0;
    for(int _=1; _<=K; ++_){
        for(int i=1; i<=T; ++i) {
            e[i].clear(); g[i].clear();
            dis[i]=inf; vis[i]=0;
        }
        for(int i=1; i<=W; ++i){
            e[fa[i]].ep(i, 1ll*w[i]*fl[i]+h[fa[i]]-h[i]);
            if(fl[i]!=0){
                g[i].ep(fa[i], 1ll*w[i]*(1-fl[i])+h[i]-h[fa[i]]);
            }
        }
        for(int i=W+1; i<=W+H; ++i){
            if(fl[i]){
                g[i].ep(fa[i], h[i]-h[fa[i]]);
            }
            else{
                e[fa[i]].ep(i, h[fa[i]]-h[i]);
            }
            for(auto [t, id]:sch[i]){
                if(fl[id]) {
                    g[t].ep(i, h[t]-h[i]);
                }
                else if(!fl[i]&&!fl[t]){
                    e[i].ep(t, h[i]-h[t]);
                }
            }
        }
        for(int i=W+H+1; i<=W+H+n*m; ++i){
            if(fl[i]){
                g[T].ep(i, h[T]-h[i]);
            }
            else{
                e[i].ep(T, h[i]-h[T]);
            }
        }
        priority_queue<pli, vector<pli>, greater<pli> > pq;
        dis[S]=0;
        pq.push(mapa(0, S));
        while(!pq.empty()){
            int x=pq.top().se; pq.pop();
            if(vis[x]) continue;
            vis[x]=1;
            for(auto [y, z]:e[x]){
                if(dis[y]>dis[x]+z){
                    dis[y]=dis[x]+z;
                    fr[y]=mapa(x, 0);
                    pq.push(mapa(dis[y], y));
                }
            }
            for(auto [y, z]:g[x]){
                if(dis[y]>dis[x]+z){
                    dis[y]=dis[x]+z;
                    fr[y]=mapa(x, 1);
                    pq.push(mapa(dis[y], y));
                }
            }
        }
        if(dis[T]==inf) {
            printf("-1\n");
            return 0;
        }
        ans+=dis[T]-(h[S]-h[T]);
        for(int i=1; i<=T; ++i) if(dis[i]!=inf) h[i]+=dis[i];
        int x=T;
        while(x!=S){
            
            if(fr[x].se==0) {
                if(x==T) ++fl[fr[x].fi];
                else ++fl[x];
                if(x>=W+H+1&&x!=T&&fr[x].fi>=W+1&&fr[x].fi<=W+H) ++fl[mp[fr[x].fi][x]];
            }
            else {
                if(fr[x].fi==T) --fl[x];
                else{
                    --fl[fr[x].fi];
                }
                if(fr[x].fi>=W+H+1&&fr[x].fi!=T&&x>=W+1&&x<=W+H) --fl[mp[x][fr[x].fi]];
            }
            x=fr[x].fi;
        }
    }
    printf("%lld\n", ans);
	return 0;
}
