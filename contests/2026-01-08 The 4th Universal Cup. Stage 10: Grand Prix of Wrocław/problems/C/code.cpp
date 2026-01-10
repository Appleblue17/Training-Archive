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
const int N=1e6+5;
int T, n, m;
vector<pii> e[N];
int f[N], g[N];
#define fail {printf("-1\n"); exit(0);}
void dfs(int x, int fa){
    if(e[x].size()==1){
        f[x]=1;
    }
    for(auto [y, z]:e[x]) if(y^fa){
        dfs(y, x);
        if(f[y]>z){
            f[y]=z-((f[y]^z)&1);
        }
        if(f[y]<0) fail
        f[x]+=f[y];
    }
}
ll ans=0;
void dfs2(int x, int fa){
    for(auto [y, z]:e[x]) if(y^fa) g[x]+=f[y];
    for(auto [y, z]:e[x]) if(y^fa){
        g[y]=g[x]-f[y];
        if(g[y]>z){
            g[y]=z-((g[y]^z)&1);
        }
        if(g[y]<0) fail
        ans+=min(f[y], g[y]);
        dfs2(y, x);
    }
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n);
    for(int i=1, x, y, z; i<n; ++i){
        read(x); read(y); read(z);
        e[x].ep(y, z);
        e[y].ep(x, z);
    }
    if(n==2){
        if(e[1][0].se==0) printf("-1\n");
        else printf("1\n");
        return 0;
    }
    int rt=1;
    for(int i=2; i<=n; ++i) if(e[i].size()>e[rt].size()) rt=i;
    dfs(rt, 0);
    
    dfs2(rt, 0);
    
    printf("%lld\n", ans);
	return 0;
}

