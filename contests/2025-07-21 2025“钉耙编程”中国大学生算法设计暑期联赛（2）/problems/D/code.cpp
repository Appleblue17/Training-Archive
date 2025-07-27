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
const int N=3e5+6, mod=1e9+7, inv2=(mod+1)/2;
int fpow(ll x, int y){
	ll ret=1;
	while(y){
		if(y&1) ret=ret*x%mod;
		x=x*x%mod; y>>=1;
	}
	return ret;
}
const int inv6=fpow(6, mod-2);
const int inv4=fpow(4, mod-2);
const int inv12=fpow(12, mod-2);
int Test, n, m;
char s[N];
struct node{
	int len, c[26], fa;
}sam[N];
int lst, cnt;
vector<int> e[N];
int pos[N];
int f[N][21], sz[N];
inline void extend(int i){
	int p=lst, np=lst=++cnt; int x=s[i]-'a';
	pos[i]=np; 
	sam[np].len=sam[p].len+1;
	for(; p&&!sam[p].c[x]; p=sam[p].fa) sam[p].c[x]=np;
	if(!p) sam[np].fa=1;
	else{
		int q=sam[p].c[x];
		if(sam[q].len==sam[p].len+1) sam[np].fa=q;
		else{
			int nq=++cnt;
			sam[nq]=sam[q];
			sam[nq].len=sam[p].len+1;
			sam[q].fa=sam[np].fa=nq;
			for(; p&&sam[p].c[x]==q; p=sam[p].fa) sam[p].c[x]=nq;
		}
	}
}
vector<pii> bin[N];
inline void init(){
	for(int i=1; i<=cnt; ++i) {
		e[i].clear(); bin[i].clear();
		sam[i].fa=sam[i].len=0;
		for(int t=0; t<26; ++t) sam[i].c[t]=0;
	}
	cnt=lst=1;
	for(int i=1; i<=n; ++i) extend(i);
	for(int i=2; i<=cnt; ++i) f[i][0]=sam[i].fa, sz[i]=sam[i].len-sam[sam[i].fa].len;
	for(int i=1; i<21; ++i){
		for(int j=1; j<=cnt; ++j) f[j][i]=f[f[j][i-1]][i-1];
	}
}
inline int locate(int l, int r){
	int x=pos[r];
	for(int t=20; t>=0; --t) if(sam[f[x][t]].len>=r-l+1) x=f[x][t];
	return x;
}
int qpos[N];
int lenid[N];
struct mat{
	int a[6][6];
	mat(){memset(a, 0, sizeof a);}
	bool empty(){
		bool ret=1;
		for(int i=0; i<6; ++i){
			for(int j=0; j<6; ++j){
				if(i==j) ret&=a[i][j]==1;
				else ret&=a[i][j]==0;
			}
		}
		return ret;
	}
}E;
inline mat operator *(mat x, mat y){
	mat ret;
	for(int k=0; k<6; ++k){
		for(int i=0; i<6; ++i) if(x.a[i][k]){
			for(int j=0; j<6; ++j){
				ret.a[i][j]=(1ll*x.a[i][k]*y.a[k][j]+ret.a[i][j])%mod;
			}
		}
	}
	return ret;
}
inline mat operator +(mat x, mat y){
	for(int i=0; i<6; ++i){
		for(int j=0; j<6; ++j){
			x.a[i][j]=(x.a[i][j]+y.a[i][j])%mod;
		}
	}
	return x;
}
mat tr[N<<2], tag[N<<2];
int trsz[N], mxson[N];
void dfs1(int x){
	trsz[x]=1; mxson[x]=0;
	for(auto y:e[x]){
		dfs1(y);
		trsz[x]+=trsz[y];
		if(trsz[y]>trsz[mxson[x]]) mxson[x]=y;
	}
	return ;
}
int dfn[N], seq[N], timer, top[N];
void dfs2(int x, int tp){
	top[x]=tp; dfn[x]=++timer; seq[timer]=x;
	if(mxson[x]) dfs2(mxson[x], tp);
	for(auto y:e[x]) if(y^mxson[x]) dfs2(y, y);
	return ;
}
void build(int p, int l, int r){
	tag[p]=E;
	if(l==r){
		tr[p]=tr[0]; 
		int x=seq[l];
		tr[p].a[0][0]=1ll*inv2*sz[x]%mod;
		tr[p].a[0][1]=(1ll*inv2*sz[x]%mod*sz[x]%mod+mod-1ll*sz[x]*sam[x].len%mod)%mod;
		tr[p].a[0][2]=(1ll*inv2*sz[x]%mod*sam[x].len%mod*sam[x].len%mod+1ll*inv2*sz[x]%mod*sam[x].len%mod+1ll*inv12*sz[x]%mod*(sz[x]+1)%mod*(2*sz[x]+1)%mod+mod+mod-1ll*inv4*sz[x]%mod*(sz[x]+1)%mod-1ll*inv2*sz[x]%mod*(sz[x]+1)%mod*sam[x].len%mod)%mod;
		tr[p].a[0][3]=(1ll*inv2*sz[x]*(sz[x]+1)%mod+mod-1ll*sam[x].len*sz[x]%mod)%mod;
		tr[p].a[0][4]=(1ll*inv6*sz[x]%mod*(sz[x]+1)%mod*(2*sz[x]+1)%mod+1ll*sam[x].len*sam[x].len%mod*sz[x]%mod+mod-1ll*sz[x]*sam[x].len%mod*(sz[x]+1)%mod)%mod;
		return ;
	}
	int mid=(l+r)>>1;
	build(p<<1, l, mid); build(p<<1|1, mid+1, r);
	tr[p]=tr[p<<1]+tr[p<<1|1];
}
mat curtag;
void down(int p){
	if(!tag[p].empty()){
		tag[p<<1]=tag[p<<1]*tag[p]; tr[p<<1]=tr[p<<1]*tag[p];
		tag[p<<1|1]=tag[p<<1|1]*tag[p]; tr[p<<1|1]=tr[p<<1|1]*tag[p];
		tag[p]=E;
	}
}
void mdf(int p, int l, int r, int L, int R){
	if(L<=l&&r<=R){
		tag[p]=tag[p]*curtag;
		tr[p]=tr[p]*curtag;
		return ;
	}
	int mid=(l+r)>>1;
	down(p);
	if(L<=mid) mdf(p<<1, l, mid, L, R);
	if(R>mid) mdf(p<<1|1, mid+1, r, L, R);
	tr[p]=tr[p<<1]+tr[p<<1|1];
}
void solve(){
	read(n); read(m);
	scanf("%s", s+1);
	reverse(s+1, s+n+1);
	init();
	for(int i=1, l, r; i<=m; ++i) {
		read(l); read(r);
		int cur=locate(n-r+1, n-l+1);
		bin[cur].ep(r-l+1, i);
	}
	int idx=cnt;
	for(int i=2; i<=cnt; ++i){
		if(bin[i].empty()) continue;
		vector<int> tem;
		for(auto t:bin[i]) tem.ep(t.fi);
		sort(tem.begin(), tem.end());
		tem.erase(unique(tem.begin(), tem.end()), tem.end());
		if(tem.back()==sam[i].len) tem.pop_back();
		int lstfa=sam[i].fa;
		for(auto t:tem){
			++idx;
			sam[idx].len=t; lenid[t]=idx;
			sam[idx].fa=lstfa;
			lstfa=idx;
		}
		lenid[sam[i].len]=i;
		sam[i].fa=lstfa;
		for(auto t:bin[i]){
			qpos[t.se]=lenid[t.fi];
		}
	}
	for(int i=1; i<=idx; ++i) e[i].clear();
	for(int i=2; i<=idx; ++i) e[sam[i].fa].emplace_back(i), sz[i]=sam[i].len-sam[sam[i].fa].len;
	dfs1(1);
	timer=0;
	dfs2(1, 1);
	build(1, 1, idx);
	for(int i=1; i<=m; ++i){
		curtag=E;
		curtag.a[3][1]=curtag.a[4][2]=curtag.a[2][5]=1;
		curtag.a[0][1]=2*sam[qpos[i]].len;
		curtag.a[3][2]=curtag.a[1][5]=sam[qpos[i]].len;
		curtag.a[0][5]=1ll*sam[qpos[i]].len*sam[qpos[i]].len%mod;
		int x=qpos[i]; 
		while(x){
			mdf(1, 1, idx, dfn[top[x]], dfn[x]);
			x=sam[top[x]].fa;
		}
		printf("%d\n", tr[1].a[0][5]);
	}
}
int main(){
    // freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
    // freopen("D:\\nya\\acm\\A\\test2.out","w",stdout);
	E.a[0][0]=E.a[1][1]=E.a[2][2]=E.a[3][3]=E.a[4][4]=E.a[5][5]=1;
    read(Test); 
    while(Test--){
		solve();
    }
    return 0;
}