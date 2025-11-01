#pragma GCC Optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define N 510
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ull,ull> puu;
//mt19937_64 rng(GetTickCount());
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int mo=1e9+7;
using namespace std;
ll a[N],b[N],U[N][N],D[N][N],siz[N],f[N][N];
ll t,n,m,x,y,ans,k,q;
vector<int> g[N];
void dfs(int u,int fa){
    siz[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v == fa)continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
    //memset(f,48,sizeof(f));
    //f[0][0]=0;
    int i=0,sm=1;
    for(int k=1;k<=n;k++){
        i=0;sm=1;
        //memset(f,48,sizeof(f));
        for(int ii=0;ii<=g[u].size();ii++){
            for(int jj=0;jj<=min(siz[u],k-1);jj++){
                f[ii][jj]=1e18;
            }
        }
        f[0][0]=0;
        for(int v:g[u]){
            if(v == fa)continue;
            i++;
            sm += siz[v];
            if(i == 1){
                f[i][0] = min(f[i][0],f[i-1][0]+U[v][k]);
                for(int j=0;j<=min(sm,k-1);j++){
                    int w=j;
                    f[i][j] = min(f[i][j],f[i-1][j-w]+D[v][w]);
                }
                continue;
            }
            for(int j=0;j<=min(sm,k-1);j++){
                f[i][j] = min(f[i][j],f[i-1][j]+U[v][k]);
                for(int w=1;w<=min(j,siz[v]);w++){
                    f[i][j] = min(f[i][j],f[i-1][j-w]+D[v][w]);
                }
                //printf("u=%lld,k=%lld,f[%lld][%lld]=%lld\n",u,k,i,j,f[i][j]);
            }
        }
        for(int j=0;j<=min(k-1,sm);j++){
            U[u][k-j-1] = min(U[u][k-j-1],f[i][j]+k*a[u]);
        }
        D[u][k] = min(D[u][k],f[i][k-1]+k*a[u]);
    }
    //for(int k=0;k<=n;k++){
    //    printf("U[%lld][%lld]=%lld,D[%lld][%lld]=%lld\n",u,k,U[u][k],u,k,D[u][k]);fflush(stdout);
    //}
    
}
void solve(){
	
    memset(U,48,sizeof(U));
    memset(D,48,sizeof(D));
    ans=U[0][0];
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
        g[i].clear();
        siz[i]=0;
	}
	for(int i=1;i<n;i++){
		int x,y;
        scanf("%lld%lld",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
	}
	dfs(1,0);
    //for(int i=0;i<=500;i++){
    //    ans = min(ans,min(U[1][i],D[1][i]));
    //}
    ans = U[1][0];
    printf("%lld\n",ans);
}
signed main(){
	int T;
    scanf("%lld",&T);
	for(int i=1;i<=T;i++){
		solve();
	}
}

