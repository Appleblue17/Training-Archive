#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5, mod=998244353;
inline ll ksm(ll a, ll x){
    ll tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}
int T, n, m;
ll frc[N], inv[N];
inline ll C(int x, int y){
    if(x<0||y<0||x-y<0) return 0;
    return frc[x]*inv[y]%mod*inv[x-y]%mod;
}
vector<int> e[N];
int mxd[N];
vector<int> f[N];
void dfs1(int x){
    mxd[x]=0;
    for(auto y:e[x]) {
        dfs1(y);
        mxd[x]=max(mxd[x], mxd[y]+1);
    }
    f[x].clear();
    for(int i=0; i<=mxd[x]; ++i) f[x].push_back(0);
}
void dfs2(int x){
    f[x][0]=1;
    for(auto y:e[x]){
        dfs2(y);
        for(int i=0; i<=mxd[y]; ++i){
            f[x][i+1]+=f[y][i];
        }
    }
}
int g[1300][2600];
int ans;
void dfs3(int d, int x){
    for(int j=1; j<=mxd[1]*2+10; ++j) {
        int u=g[d][j];
        if(j<=mxd[x]) u+=f[x][j];
        ans=(C(u, m-1)+ans)%mod;
        // cout<<x<<' '<<j<<' '<<g[d][j]<<' '<<u-g[d][j]<<endl;
        g[d+1][j]=0;
    }
    for(int j=0; j<=mxd[1]*2+10; ++j) g[d+1][j+1]=g[d][j];
    for(auto y:e[x]){
        for(int j=0; j<=mxd[x]; ++j){
            g[d+1][j+1]+=f[x][j];
            if(j-1>=0&&j-1<=mxd[y]) g[d+1][j+1]-=f[y][j-1];
        }
        dfs3(d+1, y);
        for(int j=0; j<=mxd[x]; ++j){
            g[d+1][j+1]-=f[x][j];
            if(j-1>=0&&j-1<=mxd[y]) g[d+1][j+1]+=f[y][j-1];
        }
    }
}
void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i){
        e[i].clear();
    }
    for(int i=2, x; i<=n; ++i){
        scanf("%d", &x);
        e[x].push_back(i);
    }
    if(m==1){
        printf("%d\n", n);
        return ;
    }
    dfs1(1);
    dfs2(1);
    for(int i=0; i<=mxd[1]+5; ++i){
        for(int j=0; j<=mxd[1]*2+10; ++j){
            g[i][j]=0;
        }
    }
    ans=0;
    dfs3(0, 1);
    // if(m==2) ans=ksm(2, mod-2)*ans%mod;
    printf("%d\n", ans);
}
signed main(){
    frc[0]=1;
    for(int i=1; i<N; ++i) frc[i]=frc[i-1]*i%mod;
    inv[N-1]=ksm(frc[N-1], mod-2);
    for(int i=N-2; i>=0; --i) inv[i]=inv[i+1]*(i+1)%mod;
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
