#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
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
const int N=1e6+5, inf=1e9;
const ll inf2=1e18;
int Task, n, m, k;
int s[205][105], a[205][205];
int p1[205][105], p2[205][205], p0[205][205];
ll dis[N];
int S, SS, TT, T;
int lin[N], nxt[N], fr[N], to[N], val[N], w[N], pre[N];
int tot;
void in(int x, int y, int z, int _w){
    nxt[++tot]=lin[x]; lin[x]=tot; fr[tot]=x; to[tot]=y; val[tot]=z; w[tot]=_w;
}
void link(int x, int y, int z, int _w){
    in(x, y, z, _w); in(y, x, 0, -_w);
}
bool v[N];
bool bfs(){
    for(int i=1; i<=T; ++i) dis[i]=inf2, v[i]=0, pre[i]=0;
    queue<int> q;
    q.push(S); dis[S]=0; v[S]=1;
    while(!q.empty()){
        int x=q.front(); q.pop();
        v[x]=0;
        for(int i=lin[x]; i; i=nxt[i]){
            int y=to[i];
            if(val[i]&&dis[y]>dis[x]+w[i]){
                dis[y]=dis[x]+w[i];
                pre[y]=i;
                if(!v[y]){
                    v[y]=1;
                    q.push(y);
                }
            }
        }
    }
    return dis[T]<inf2;
}
int totflow; ll totcost;
void arg(){
    int u, v=T, fl=inf;
    while(v!=S) u=pre[v], fl=min(fl, val[u]), v=fr[u];
    v=T;
    while(v!=S) u=pre[v], val[u]-=fl, val[u^1]+=fl, v=fr[u];
    totcost+=fl*dis[T]; totflow+=fl; 
}
int id[205][205], idx;
void solve(){
    read(n); read(m); read(k);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            read(s[i][j]);
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            read(a[i][j]);
        }
    }
    if(n==1||m==1){
        for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j){
            if(s[i][j]!=s[1][1]){
                printf("Impossible\n");
                return ;
            }
        }
        printf("0\n");
        return ;
    }
    for(int i=0; i<=n+1; ++i) for(int j=0; j<=m+1; ++j) p0[i][j]=p1[i][j]=p2[i][j]=0;
    int W=(s[1][2]+s[2][1]+k-s[1][1])%k;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j){
        p0[i][j]=(W+k-s[i][j])%k;
    }
    for(int i=1; i<=n; ++i){
        for(int j=m; j>=2; --j){
            p1[i][j-1]=p0[i][j]; p0[i][j]=(p0[i][j]+p2[i-1][j])%k;
        }
        for(int j=1; j<=m; ++j){
            p2[i][j]=(p0[i][j]+k-p1[i][j])%k;
        }
        if(p0[i+1][1]!=p2[i][1]){
            printf("Impossible\n");
            return ;
        }
        for(int j=2; j<=m; ++j){
            p0[i+1][j]=(p0[i+1][j]+k-p2[i][j])%k;
        }
    }
    p2[n][m]=0;
    for(int j=1; j<=m; ++j) if(p2[n][j]!=0){
        printf("Impossible\n");
        return ;
    }
    if((p1[n][m-1]+p2[n-1][m]+k-p0[n][m])%k!=0){
        printf("Impossible\n");
        return ;
    }
    ll ans=a[1][1]*p0[1][1];
    for(int i=1; i<=n; ++i) for(int j=1; j<m; ++j) {
        ans+=a[i][j+1]*p1[i][j];
    }
    for(int i=1; i<n; ++i) for(int j=1; j<=m; ++j) {
        ans+=a[i+1][j]*p2[i][j];
    }
    tot=1;
    idx=0;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j){
        id[i][j]=++idx;
    }
    SS=++idx; TT=++idx; S=++idx; T=++idx;
    for(int i=1; i<=T; ++i) lin[i]=0;
    link(SS, id[1][1], inf, a[1][1]);
    link(id[n][m], TT, inf, 0);
    link(TT, SS, inf, 0);
    int cnts=0, cntt=0;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(j!=m) link(id[i][j], id[i][j+1], inf, a[i][j+1]);
            if(i!=n) link(id[i][j], id[i+1][j], inf, a[i+1][j]);
            int cur=p1[i][j-1]+p2[i-1][j]-p1[i][j]-p2[i][j];
            if(cur>=k){
                link(S, id[i][j], 1, 0);
                ++cnts;
            }
            else if(cur<=-k){
                link(id[i][j], T, 1, 0);
                ++cntt;
            }
        }
    }
    link(SS, T, cnts, 0);
    link(S, TT, cntt, 0);
    totflow=0; totcost=0;
    while(bfs()){
        arg();
    }
    if(totflow!=cnts+cntt){
        printf("Impossible\n");
    }
    else{
        printf("%lld\n", 1ll*totcost*k+ans);
    }
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	read(Task);
	while(Task--){
		solve();
	}
	return 0;
}