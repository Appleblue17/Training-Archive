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
const int N=6e6+5, mod=998244353;
int T, n, m;
int tr[N][2], sz[N], idx=1;
vector<int> f[N];
int pw[N];
void dfs(int x, int d){
	f[x].resize(sz[x]+1);
	if(d==0) return ;
	--d;
	if(tr[x][0]) dfs(tr[x][0], d);
	if(tr[x][1]) dfs(tr[x][1], d);
	for(int i=1; i<=sz[x]; ++i){
		if(i<=sz[tr[x][0]]) f[x][i]=f[tr[x][0]][i];
		else f[x][i]=(pw[d<<1]+f[tr[x][1]][i-sz[tr[x][0]]])%mod;
		if(i<=sz[tr[x][1]]) f[x][i]=(f[x][i]+f[tr[x][1]][i])%mod;
		else f[x][i]=(f[x][i]+pw[d<<1]+f[tr[x][0]][i-sz[tr[x][1]]])%mod;
	}
}
int calc(int x, int d, ll bs, int k){
	if(d==0) return 0;
	--d;
	if((bs>>d)&1){
		int ret=0;
		if(k<=sz[tr[x][0]]) ret=f[tr[x][0]][k];
		else ret=(f[tr[x][1]][k-sz[tr[x][0]]]+pw[d<<1])%mod;
		bs&=(1ll<<d)-1;
		if(k<=sz[tr[x][1]]) return (ret+calc(tr[x][1], d, bs, k))%mod;
		ret=(ret+bs%mod*pw[d])%mod; k-=sz[tr[x][1]];
		return (ret+calc(tr[x][0], d, bs, k))%mod;
	}
	else{
		int ret=0;
		if(k<=sz[tr[x][0]]) return (ret+calc(tr[x][0], d, bs, k))%mod;
		ret=(ret+bs%mod*pw[d])%mod; k-=sz[tr[x][0]];
		return (ret+calc(tr[x][1], d, bs, k))%mod;
	}
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	pw[0]=1;
	for(int i=1; i<=60; ++i) pw[i]=(pw[i-1]+pw[i-1])%mod;
	f[0].push_back(0);
	read(n); read(m);
	for(int j=1; j<=n; ++j){
		ll x; read(x);
		int p=1; ++sz[p];
		for(int i=59; i>=0; --i){
			if(!tr[p][(x>>i)&1]) tr[p][(x>>i)&1]=++idx;
			p=tr[p][(x>>i)&1]; ++sz[p];
		}
	}
	dfs(1, 60);
	ll l, r; int k;
	while(m--){
		read(l); read(r); read(k);
		printf("%d\n", (calc(1, 60, r+1, k)+mod-calc(1, 60, l, k))%mod);
	}
	return 0;
}

