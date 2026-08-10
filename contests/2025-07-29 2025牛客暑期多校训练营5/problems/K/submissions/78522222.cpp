#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5, M=5e6+5, mod=998244353;
int n, m, k;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
vector<pii> e[N];
int flg[N]; int rev[N];
int f[N][20], dfn[N], sz[N], lp[N], rp[N], dep[N], timer;
void dfs(int x, int fa){
    f[x][0]=fa; dep[x]=dep[fa]+1;
    for(int i=1; i<20; ++i) f[x][i]=f[f[x][i-1]][i-1];
    dfn[x]=lp[x]=++timer; sz[x]=1;
    for(auto edg:e[x]){
        int y=edg.fi, id=edg.se;
        if(y==fa) continue;
        if(flg[id]) rev[flg[id]]=y;
        dfs(y, x);
        sz[x]+=sz[y];
    }
    rp[x]=dfn[x]+sz[x]-1;
}
int lca(int x, int y){
    if(dep[x]<=dep[y]) swap(x, y);
    for(int i=19; i>=0; --i) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return x; 
    for(int i=19; i>=0; --i) if(f[x][i]^f[y][i]) x=f[x][i], y=f[y][i];
    return f[x][0];
}
 
int F[M], G[M],ANS[M];
 
int mul[M],inv[M];
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1ll;
    }
    return tot;
}
 
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return 1ll*mul[m]*inv[n]%mod*inv[m-n]%mod;
}
 
void FWTor(int *f,int n,int opt){
    for(int i=1;i<n;i<<=1)
        for(int j=0;j<n;j+=(i<<1))
            for(int k=j;k<j+i;k++){
                if(opt==1) f[k+i]=(f[k+i]+f[k])%mod;
                else f[k+i]=(f[k+i]+mod-f[k])%mod;
            }
}
bool in(int x, int y){
    return dfn[x]>=lp[y]&&dfn[x]<=rp[y];
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1, x, y; i<n; ++i){
        scanf("%d%d", &x, &y);
        e[x].push_back(mapa(y, i));
        e[y].push_back(mapa(x, i));
    }
    for(int i=1, x; i<=m; ++i){
        scanf("%d", &x); flg[x]=i;
    }
    dfs(1, 0);
    for(int i=1, s, t; i<=k; ++i){
        scanf("%d%d", &s, &t);
        int z=lca(s, t);
        int state=0;
        for(int j=1; j<=m; ++j){
            int x=rev[j];
            if(in(x, z)&&x!=z&&(in(s, x)||in(t, x))){
                state|=1<<(j-1);
            }
        }
        // cout<<state<<endl;
        ++G[state];
    }
    int L=1, R=m, mid, ret=0, ret2=0;
    init(M-1);
     
    for(int i=0; i<(1<<m); ++i) F[i]=G[i], ANS[i]=0;
    FWTor(F,1<<m,1);
    int alc=(1<<m)-1;
    ret2=-1,ret=0;
    for(int i=0;i<=m;i++){
        int tot=0;
        for(int mac=0;mac<(1<<m);mac++){
            ANS[mac]=(ANS[mac]+C(F[mac],i))%mod;
            if(__builtin_parity(mac^alc) & 1) tot=(tot+mod-ANS[mac])%mod;
            else tot=(tot+ANS[mac])%mod;
        }
         
        if(tot){
            ret2=i; ret=tot;
            break;
        }
    }
     
    // while(L<=R){
    //     mid=(L+R)>>1;
    //     for(int i=0; i<(1<<m); ++i) F[i]=G[i], ANS[i]=0;
    //     FWTor(F,1<<m,1);
    //     for(int mac=0;mac<(1<<m);mac++){
    //         for(int i=0;i<=mid;i++)
    //             ANS[mac]=(ANS[mac]+C(F[mac],i))%mod;
    //     }
    //     cout<<mid<<": ";
    //     for(int i=0;i<(1<<m);i++) cout<<ANS[i]<<" "; cout<<endl;
    //     FWTor(ANS,1<<m,-1);
    //     cout<<ANS[(1<<m)-1]<<endl;
    //     if(ANS[(1<<m)-1]!=0){
    //         ret2=mid; ret=ANS[(1<<m)-1]; R=mid-1;
    //     }
    //     else{
    //         L=mid+1;
    //     }
    // }
    if(ret==0){
        printf("-1\n");
    }
    else{
        printf("%d %d\n", ret2, ret);
    }
}
