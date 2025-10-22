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
const int N=1e6+5;
int T, n; ll m;
vector<pii> e[N];
int rt;
ll lim;
vector<ll> pre[N], suf[N];
vector<int> pre2[N], suf2[N];
int cnt_lf[N], mxcnt[N]; ll sum_dis[N], mx_dis[N];
int rk[N], sz[N], isleaf[N];
void dfs0(int x, int fa){
	pre[x].ep(0); suf[x].ep(0);
	pre2[x].ep(0); suf2[x].ep(0);
	for(auto [y, z]:e[x]) if(y^fa){
		dfs0(y, x);
		pre[x].ep(0); suf[x].ep(0);
		pre2[x].ep(0); suf2[x].ep(0);
		rk[y]=++sz[x];
	}
	pre[x].ep(0); suf[x].ep(0);
	pre2[x].ep(0); suf2[x].ep(0);
	if(sz[x]==0){
		isleaf[x]=1;
	}
}
void dfs(int x, int fa){
	cnt_lf[x]=0; sum_dis[x]=0; mx_dis[x]=0; mxcnt[x]=0;
	if(isleaf[x]) {
		cnt_lf[x]=1;
		mxcnt[x]=1;
		return ;
	}
	for(auto [y, z]:e[x]) if(y^fa){
		dfs(y, x);
		cnt_lf[x]+=cnt_lf[y];
		sum_dis[x]+=sum_dis[y]+(ll)z*cnt_lf[y];
		mx_dis[x]=max(mx_dis[x], mx_dis[y]+z);
		pre[x][rk[y]]=suf[x][rk[y]]=mx_dis[y]+z;
		mxcnt[x]=max(mxcnt[x], cnt_lf[y]);
		pre2[x][rk[y]]=suf2[x][rk[y]]=cnt_lf[y];
	}
	for(int i=1; i<=sz[x]; ++i) pre[x][i]=max(pre[x][i], pre[x][i-1]);
	for(int i=sz[x]; i>=1; --i) suf[x][i]=max(suf[x][i], suf[x][i+1]);
	for(int i=1; i<=sz[x]; ++i) pre2[x][i]=max(pre2[x][i], pre2[x][i-1]);
	for(int i=sz[x]; i>=1; --i) suf2[x][i]=max(suf2[x][i], suf2[x][i+1]);
}
ll mx;
void dfs2(int x, int fa, int cntf, ll sumf, ll mxf, int mxcntf){
	for(auto [y, z]:e[x]) if(y^fa){
		int cnta=cntf+cnt_lf[x]-cnt_lf[y];
		ll suma=sumf+sum_dis[x]-sum_dis[y]-(ll)z*cnt_lf[y];
		ll mxa=max(mxf, max(pre[x][rk[y]-1], suf[x][rk[y]+1]));
		int cnt2a=max(mxcntf, max(pre2[x][rk[y]-1], suf2[x][rk[y]+1]));
		int cntb=cnt_lf[y];
		ll sumb=sum_dis[y];
		ll mxb=mx_dis[y];
		int cnt2b=mxcnt[y];
		if(mxb+mxa+z<=lim){
			ll mnd=max(0ll, z+mxb-lim/2);
			ll mxd=min((ll)z, lim/2-mxa);
			if(mnd<=mxd){
				ll tem=lim/2*(cnta+cntb)-suma-sumb-(ll)z*cntb+(ll)mxd*(cntb-cnta);
				if(lim&1){
					if(mxd==0) tem+=max(cnt2a, cntb);
					else if(mxd==z) tem+=max(cnta, cnt2b);
					else tem+=max(cnta, cntb);
				}
				mx=max(mx, tem);	
				tem=lim/2*(cnta+cntb)-suma-sumb-(ll)z*cntb+(ll)mnd*(cntb-cnta);
				if(lim&1){
					if(mnd==0) tem+=max(cnt2a, cntb);
					else if(mnd==z) tem+=max(cnta, cnt2b);
					else tem+=max(cnta, cntb);
				}
				mx=max(mx, tem);
				ll c=mnd+1;
				if(c<=mxd){
					tem=lim/2*(cnta+cntb)-suma-sumb-(ll)z*cntb+(ll)c*(cntb-cnta);
					if(lim&1){
						if(c==0) tem+=max(cnt2a, cntb);
						else if(c==z) tem+=max(cnta, cnt2b);
						else tem+=max(cnta, cntb);
					}
					mx=max(mx, tem);
				}
				c=mxd-1;
				if(c>=mnd){
					tem=lim/2*(cnta+cntb)-suma-sumb-(ll)z*cntb+(ll)c*(cntb-cnta);
					if(lim&1){
						if(c==0) tem+=max(cnt2a, cntb);
						else if(c==z) tem+=max(cnta, cnt2b);
						else tem+=max(cnta, cntb);
					}
					mx=max(mx, tem);
				}
			}
			if(lim&1){
				ll c=mnd-1, tem;
				if(c>=0&&c<=mxd){
					tem=lim/2*(cnta+cntb)-suma-sumb-(ll)z*cntb+(ll)c*(cntb-cnta);
					tem+=cntb;
					mx=max(mx, tem);
				}
				c=mxd+1;
				if(c<=z&&c>=mnd){
					tem=lim/2*(cnta+cntb)-suma-sumb-(ll)z*cntb+(ll)c*(cntb-cnta);
					tem+=cnta;
					mx=max(mx, tem);
				}
			}
		}
		if(!isleaf[y]){
			int cnt_nxt=cntf+cnt_lf[x]-cnt_lf[y];
			ll sum_nxt=sumf+sum_dis[x]-sum_dis[y]-(ll)z*cnt_lf[y]+(ll)z*cnt_nxt;
			ll mx_nxt=max(mxf, max(pre[x][rk[y]-1], suf[x][rk[y]+1]))+z;
			dfs2(y, x, cnt_nxt, sum_nxt, mx_nxt, cnt_nxt);
		}
	}
}
bool check(){
	mx=0;
	dfs2(rt, 0, 0, 0, 0, 0);
	return mx>=m;
}
void solve(){
	read(n); read(m);
	for(int i=1, x, y, z; i<n; ++i){
		read(x); read(y); read(z);
		e[x].ep(y, z); e[y].ep(x, z);
	}
	if(n==2){
		printf("%lld\n", m+e[1][0].se);
		return ;
	}
	for(int i=1; i<=n; ++i) if(e[i].size()>e[rt].size()) rt=i;
	dfs0(rt, 0);
	dfs(rt, 0);
	ll L=1, R=1e13, mid, ret=0;
	while(L<=R){
		mid=(L+R)>>1;
		lim=mid;
		if(check()){
			ret=mid; R=mid-1;
		}
		else{
			L=mid+1;
		}
	}
	printf("%lld\n", ret);
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	solve();
	return 0;
}
