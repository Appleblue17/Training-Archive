#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5, mod=998244353;
int T, n, m, w;
typedef pair<int, int> pii;
#define fi first
#define se second
vector<pii> e[N];
bool vis[N];
vector<int> g[N];
int dp[N], up[N];
ll frc[N], inv[N];
ll fpow(ll x,ll  y){
    ll ret=1;
    while(y){
        if(y&1) ret=ret*x%mod;
        x=x*x%mod; y>>=1;
    }
    return ret;
}
int C(int x, int y){
    if(x<0||y<0||x-y<0) return 0;
    return frc[x]*inv[y]%mod*inv[x-y]%mod;
}
void dfs(int x, int fa){
    bool isleaf=1;
    for(auto y:g[x]) if(y!=fa){
        dfs(y, x); isleaf=0;
    }
    if(isleaf){
        dp[x]=1; up[x]=0;
        return ;
    }
    dp[x]=1; up[x]=0;
    unordered_map<int, int> h;
    int sum=0;
    for(auto y:g[x]) if(y!=fa){
        dp[x]=1ll*dp[x]*dp[y]%mod;
        if(up[y]+1==w){
            continue;
        }
        h[up[y]+1]++;
    }
    for(auto [v, cnt]:h){
        if(v*2==w) {
            if(cnt&1) {
                if(up[x]!=0) up[x]=v;
                else {
                    dp[x]=0;
                    return ;
                }
            }
            continue;
        }
        if(h[w-v]==h[v]) continue;
        if(h[w-v]==h[v]+1) {
            if(up[x]!=0) up[x]=w-v;
            else {
                dp[x]=0;
                return ;
            }
            continue;
        }
        if(h[w-v]==h[v]-1){
            if(up[x]!=0) up[x]=v;
            else {
                dp[x]=0;
                return ;
            }
            continue;
        }
        dp[x]=0;
        return;
    }
    if(up[x]!=0) h[up[x]]--;
    for(auto [v, cnt]:h){
        if(v*2==w){
            dp[x]=C(cnt, cnt/2)*dp[x]%mod;
        }
        else if(v<w-v){
            dp[x]=1ll*cnt*cnt%mod*dp[x]%mod;
        }
    }
}
void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) e[i].clear();
    for(int i=1, x, y, z; i<n; ++i){
        scanf("%d%d%d", &x, &y, &z);
        e[z].push_back(make_pair(x, y));
    }
    if(e[2].size()){
        printf("0\n");
        return ;
    }
    ll ans=1;
    for(int i=3; i<=n; ++i){
        if(e[i].empty()) continue;
        w=i-1;
        for(auto [x, y]:e[i]){
            g[x].push_back(y); g[y].push_back(x);
        }
        for(auto [x, y]:e[i]){
            if(vis[x]) continue;
            dfs(x, 0);
            if(up[x]+1!=w&&up[x]!=0){
                printf("0\n");
                return ;
            }
            ans=ans*dp[x]%mod;
        }
        for(auto [x, y]:e[i]){
            g[x].clear(); g[y].clear();
            vis[x]=vis[y]=0;
        }
    }
    printf("%lld\n", ans);
}
int main(){
    frc[0]=1;
    for(int i=1; i<N; ++i) frc[i]=frc[i-1]*i%mod;
    inv[N-1]=fpow(frc[N-1], mod-2);
    for(int i=N-2; i>=0; --i) inv[i]=inv[i+1]*(i+1)%mod;
    scanf("%d", &T);
    while(T--){
        solve();
    }
}