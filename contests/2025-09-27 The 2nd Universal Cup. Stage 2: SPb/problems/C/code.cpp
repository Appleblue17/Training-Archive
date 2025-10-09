#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10005;
int n, m;
int efr[N], eto[N], eval[N];
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
vector<pii> e[N];
int f[N];
bool ont[N];
int vis[N];
int dfn[N], timer, pos[N], dep[N];
int val[N], upid[N]; ll dis[N];
vector<int> eid, vid;
bool ins[N];
void dfs(int x, int fa, int curid){
    f[x]=fa; vis[x]=curid;
    dfn[++timer]=x; dep[x]=dep[fa]+1; pos[x]=timer;
    vid.push_back(x);
    for(auto [y, id]:e[x]){
        if(vis[y]) {
            if(!ont[id]&&!ins[id]) eid.push_back(id), ins[id]=1;
            continue;
        }
        ont[id]=1; upid[y]=id; dis[y]=dis[x]+eval[id];
        dfs(y, x, curid);
    }
}
int lg[N], st[20][N];
void pre(){
    for(int i=2; i<=timer; ++i) lg[i]=lg[i>>1]+1;
    for(int i=1; i<=timer; ++i) st[0][i]=dfn[i];
    for(int i=1; i<=lg[timer]; ++i){
        for(int j=1; j+(1<<i)-1<=timer; ++j){
            st[i][j]=dep[st[i-1][j]]<dep[st[i-1][j+(1<<(i-1))]]?st[i-1][j]:st[i-1][j+(1<<(i-1))];
        }
    }
}
int t;
inline int lca(int x, int y){
    x=pos[x]; y=pos[y];
    if(x>y) x^=y^=x^=y;
    t=lg[y-x+1];
    return dep[st[t][x]]<dep[st[t][y-(1<<t)+1]]?st[t][x]:st[t][y-(1<<t)+1];
}
void dfs2(int x){
    dis[x]=dis[f[x]]+val[x];
    for(auto [y, id]:e[x]) if(ont[id]&&y!=f[x]){
        dfs2(y);
    }
}
inline ll D(int x, int y){
    return dis[x]+dis[y]-2ll*dis[lca(x, y)];
}
ll cirlen[N];
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i){
        scanf("%d%d%d", &efr[i], &eto[i], &eval[i]);
        e[efr[i]].push_back(mapa(eto[i], i));
        e[eto[i]].push_back(mapa(efr[i], i));
    }
    int idx=0;
    ll ans=0;
    for(int u=1; u<=n; ++u) if(!vis[u]){
        ++idx; timer=0;
        eid.clear(); vid.clear();
        dfs(u, 0, idx);
        pre();
        for(auto i:eid) {
            cirlen[i]=D(efr[i], eto[i])+eval[i];
            // cout<<efr[i]<<' '<<eto[i]<<endl;
            // cout<<dis[efr[i]]<<' '<<dis[eto[i]]<<endl;
            // cout<<"???"<<endl;
            ans=__gcd(ans, cirlen[i]);
        }
        for(auto i:vid) val[i]=0;
        for(int o=0; o<(int)eid.size(); ++o) if(!ont[eid[o]]){
            int i=eid[o];
            int cx=efr[i], cy=eto[i];
            vector<int> vec;
            while(cx!=cy){
                if(dep[cx]<dep[cy]) swap(cx, cy);
                val[cx]=eval[upid[cx]];
                vec.push_back(cx);
                cx=f[cx];
            }
            dfs2(u);
            for(int p=o+1; p<(int)eid.size(); ++p) if(!ont[eid[p]]){
                int j=eid[p];
                // cout<<D(efr[i], eto[i])<<endl;
                ans=__gcd(ans, cirlen[i]+cirlen[j]-2ll*D(efr[j], eto[j]));
            }
            for(auto t:vec) val[t]=0;
        }
    }
    printf("%lld\n", ans);
}
