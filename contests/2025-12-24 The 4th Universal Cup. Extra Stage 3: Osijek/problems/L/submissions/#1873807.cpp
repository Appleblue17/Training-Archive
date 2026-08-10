#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define N 110
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
ll deg[N],typ[N],siz[N],heavy[N],dep[N];
ll t,n,m,x,y,k,q;
const int wid[30] = {0,0,0,0,2,3,3,5,5,7,7,9,9,11,13,13,15,15,17,17,19,19,21,21,23,23,25,25,0,0};
vector<int> g[N],l[N];
pii pos[N];
int ans[N][N];//1# 0.
void dfs0(int u,int fa){
    siz[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v == fa)continue;
        dfs0(v,u);
        if(siz[v]==1)l[u].push_back(v);
        siz[u]+=siz[v];
        if((siz[v]>siz[heavy[u]]) || (siz[v] == siz[heavy[u]] && v > heavy[u])){
            heavy[u]=v;
        }
    }
}
void dfsg(int u,int fa){
    for(int v:g[u]){
        if(v==fa)continue;
        dep[v]=dep[u]+1;
        dfsg(v,u);
    }
}
void node(int x,int y,int id,int tp){
    ans[x][y]=0;
    pos[id] = mapa(x,y);
    typ[id]=tp;
}
bool cmp(int v1,int v2){
    if(siz[v1] != siz[v2])return siz[v1] < siz[v2];
    else return v1<v2;
}
void dfs(int u,int fa,int x,int y,int lo,int hi){
    //printf("dfs u=%lld,fa=%lld,x=%lld,y=%lld,lo=%lld,hi=%lld,typ=%c\n",u,fa,x,y,lo,hi,typ[u]);fflush(stdout);
    int nx=x,ny=y,dir=1,nxcol,leaf2col;
    if(typ[u]=='A'){
        nxcol = 'C';
        leaf2col = 'B';
        //x = lo;
    }
    else{
        nxcol = 'A';
        leaf2col = 'D';
        dir = -1;
        //x = hi;
    }
    if(siz[u]==4){
        ny++;
        ans[nx][ny]=0;
        node(nx+dir,ny,l[u][0],leaf2col);
        //while(lo <= nx && nx <= hi){
        //    ans[nx][ny]=0;
        //    nx+=dir;
        //}
        ny++;
        ans[nx][ny]=0;
        node(nx+dir,ny,l[u][1],nxcol);
        ny++;
        ans[nx][ny]=0;
        ny++;
        ans[nx][ny]=0;
        
        node(nx+dir,ny,l[u][2],nxcol);
        //for(int i=0;i<g[u].size();i++){
        //    int v = g[u][i];
        //    if(v == fa)continue;
        //    if(siz[v]==1)continue;
            
            //dfs(v,u,nx,ny,lo,hi);
        //}
        return;
    }
    else{
        
        
        while(l[u].size() > (hi-lo)/2){

            ny++;
            for(int i=lo;i<=hi;i++){
                ans[i][ny]=0;
            }
            ny++;

            ans[nx][ny]=0;
            ans[nx][ny+1]=0;
            nx+=dir*2;
            while(lo <= nx && nx <= hi){
                node(nx,ny,l[u].back(),nxcol);
                l[u].pop_back();
                nx+=dir*2;
            }
            ny++;nx = x;
            
        }

        

        ny++;
        for(int i=lo;i<=hi;i++){
            ans[i][ny]=0;
        }
        ny++;
        ans[nx][ny]=0;
        ans[nx][ny+1]=0;
        nx+=dir*2;
        for(int v:l[u]){
            node(nx,ny,v,nxcol);
            nx += dir*2;
        }
        ny++;nx=x;
    }

        ny++;
        for(int i=lo;i<=hi;i++){
            ans[i][ny]=0;
        }
        ny++;
    if(typ[u]=='A'){
        for(int i=0;i<g[u].size();i++){
            int v = g[u][i];
            if(v == fa)continue;
            if(siz[v]==1)continue;
            int wi;
            if(v == heavy[u]){
                wi = hi+1-lo;
            }
            else{
                wi = wid[siz[v]];
            }
            node(lo+wi-1,ny,v,nxcol);
            dfs(v,u,lo+wi-1,ny,lo,lo+wi-1);
            lo = lo+wi+1;
        }
    }
    else{
        for(int i=0;i<g[u].size();i++){
            int v = g[u][i];
            if(v == fa)continue;
            if(siz[v]==1)continue;
            int wi;
            if(v == heavy[u]){
                wi = hi-lo+1;
            }
            else{
                wi = wid[siz[v]];
            }
            node(hi-wi+1,ny,v,nxcol);
            dfs(v,u,hi-wi+1,ny,hi-wi+1,hi);
            hi = hi-wi-1;
        }
    }
    
    

}
/*
ll deg[N],typ[N],siz[N],heavy[N];
ll n;
const int wid[30] = {0,0,0,0,2,3,3,5,5,5,7,9,9,11,13,13,15,15,17,17,19,19,21,21,23,23,25,25,0,0};
vector<int> g[N],l[N];
pii pos[N];
int ans[N][N];//1# 0.
*/
void solve(){
    memset(siz,0,sizeof(0));
    memset(deg,0,sizeof(deg));
    memset(typ,0,sizeof(typ));
    memset(heavy,0,sizeof(heavy));
    memset(pos,0,sizeof(pos));
    memset(ans,0,sizeof(ans));
	scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        g[i].clear();l[i].clear();
    }

	for(int i=1;i<n;i++){
		int u,v;
        scanf("%lld%lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;deg[v]++;
	}
    int rt=0,mn=n;
    deg[0]=0;
	//for(int i=1;i<=n;i++){
	//	if(deg[i]>deg[rt])rt=i;
	//}
    for(int i=1;i<=n;i++){
        memset(dep,0,sizeof(dep));
        dfsg(i,0);
        int mxd=0;
        for(int j=1;j<=n;j++){
            mxd = max(mxd,dep[j]);
        }
        if(mxd < mn){
            mn = mxd;
            rt = i;
        }
        
    }
    //if(n == 49)rt=5;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            ans[i][j]=1;
        }
    }
    
    dfs0(rt,0);
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end(),cmp);
    }
    typ[rt]='A';pos[rt] = mapa(1,1);ans[1][1]=0;
	dfs(rt,0,1,1,1,n+1);

    //typ[rt]='C';pos[rt] = mapa(9,1);ans[9][1]=0;
    //dfs(rt,0,9,1,1,9);

    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=n+1;j++){
            if(ans[i][j]==1)putchar('#');
            else putchar('.');
        }
        putchar('\n');
    }

    for(int i=1;i<=n;i++){
        printf("%lld %lld %c\n",pos[i].fi,pos[i].se,typ[i]);
    }

}
signed main(){
	int T;cin >> T;for(int i=1;i<=T;i++){
		solve();
	}
}

