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
const int N=2e5+5;
const ll inf=1e10;
int T, n;
int a[N], b[N], c[N], al[N], ar[N];
ll C2(int x){
	return 1ll*x*(x+1)/2ll;
}
struct sgt{
	ll mx[N<<2], sum[N<<2], tag[N<<2]; int sz[N<<2];
	void clr(int p, int l, int r){
		tag[p]=-inf; sz[p]=0; mx[p]=-inf;
		if(l==r){
			sum[p]=-inf;
			return ;
		}
		int mid=(l+r)>>1;
		clr(p<<1, l, mid); clr(p<<1|1, mid+1, r);
		sum[p]=sum[p<<1]+sum[p<<1|1];
	}
	void down(int p, int l, int r){
		if(tag[p]!=-inf){
			int mid=(l+r)>>1;
			sum[p<<1]=tag[p]*sz[p<<1]+C2(sz[p<<1])-inf*(mid-l+1-sz[p<<1]);
			tag[p<<1]=tag[p]; 
			if(sz[p<<1]){
				mx[p<<1]=tag[p]+sz[p<<1];
			}
			sum[p<<1|1]=(tag[p]+sz[p<<1])*sz[p<<1|1]+C2(sz[p<<1|1])-inf*(r-mid-sz[p<<1|1]);
			tag[p<<1|1]=tag[p]+sz[p<<1]; 
			if(sz[p<<1|1]){
				mx[p<<1|1]=tag[p]+sz[p<<1]+sz[p<<1|1];
			}
			tag[p]=-inf;
		}
	}
	int mdf(int p, int l, int r, int L, int R, ll v){
		if(L<=l&&r<=R){
			sum[p]=v*sz[p]+C2(sz[p])-inf*(r-l+1-sz[p]);
			tag[p]=v; 
			if(sz[p]) mx[p]=v+sz[p];
			return sz[p];
		}
		int mid=(l+r)>>1;
		down(p, l, r);
		int c=0;
		if(L<=mid) c=mdf(p<<1, l, mid, L, R, v), v+=c;
		if(R>mid) c+=mdf(p<<1|1, mid+1, r, L, R, v);
		sum[p]=sum[p<<1]+sum[p<<1|1];
		mx[p]=max(mx[p<<1], mx[p<<1|1]);
		return c;
	}
	ll gmx(int p, int l, int r, int L, int R){
		if(L<=l&&r<=R){
			return mx[p];
		}
		int mid=(l+r)>>1;
		down(p, l, r);
		ll ret=-inf;
		if(L<=mid) ret=max(ret, gmx(p<<1, l, mid, L, R));
		if(R>mid) ret=max(ret, gmx(p<<1|1, mid+1, r, L, R));
		return ret;
	}
	void upd(int p, int l, int r, int x, ll v){
		if(l==r){
			sz[p]++;
			mx[p]=sum[p]=v;
			return ;
		}
		int mid=(l+r)>>1;
		down(p, l, r);
		if(x<=mid) upd(p<<1, l, mid, x, v);
		else upd(p<<1|1, mid+1, r, x, v);
		sum[p]=sum[p<<1]+sum[p<<1|1];
		mx[p]=max(mx[p<<1], mx[p<<1|1]);
		sz[p]=sz[p<<1]+sz[p<<1|1];
	}
	pii fnd(int p, int l, int r, int L, int R, ll v){
		if(L<=l&&r<=R){
			if(mx[p]<v+sz[p]) return mapa(n+1, sz[p]);
			if(l==r){
				return mapa(l, 0);
			}
			int mid=(l+r)>>1;
			down(p, l, r);
			if(mx[p<<1]<v+sz[p<<1]) return fnd(p<<1|1, mid+1, r, L, R, v+sz[p<<1]);
			return fnd(p<<1, l, mid, L, R, v);
		}
		int mid=(l+r)>>1;
		down(p, l, r);
		int ret=n+1;
		int cnt=0;
		if(L<=mid){
			pii info=fnd(p<<1, l, mid, L, R, v);
			if(info.fi!=n+1) ret=info.fi;
			else v+=info.se;
			cnt+=info.se;
		}
		if(R>mid&&ret==n+1){
			pii info=fnd(p<<1|1, mid+1, r, L, R, v);
			ret=info.fi;
			cnt+=info.se;
		}
		return mapa(ret, cnt);
	}
}TL, TR;
void solve(){
	read(n);
	for(int i=1; i<=n; ++i){
		read(a[i]); c[i]=a[i];
	}
	sort(c+1, c+n+1);
	for(int i=1; i<=n; ++i){
		read(b[i]);
		al[i]=min(a[i], b[i]); ar[i]=max(a[i], b[i]);
		a[i]=lower_bound(c+1, c+n+1, a[i])-c;
	}
	TL.clr(1, 0, n); TR.clr(1, 0, n);
	for(int i=1; i<=n; ++i){
		{
			//R
			ll lst=TR.gmx(1, 0, n, 0, a[i]-1);
			ll cur=max(lst+1, (ll)ar[i]);
			TR.upd(1, 0, n, a[i], cur);
			if(a[i]!=n) {
				int id=TR.fnd(1, 0, n, a[i]+1, n, cur).fi;
				if(id-1>=a[i]+1)
				TR.mdf(1, 0, n, a[i]+1, id-1, cur);
			}
		}
		{
			//L
			ll lst=TL.gmx(1, 0, n, 0, n+1-a[i]-1);
			ll cur=max(lst+1, (ll)-al[i]);
			TL.upd(1, 0, n, n+1-a[i], cur);
			if(a[i]!=1) {
				// cout<<TL.gmx(1, 0, n, 2, 2)<<' ';
				int id=TL.fnd(1, 0, n, n+1-a[i]+1, n, cur).fi;
				// cout<<i<<' '<<n+1-a[i]+1<<' '<<id-1<<' '<<cur<<endl;
				if(id-1>=n+1-a[i]+1)
				TL.mdf(1, 0, n, n+1-a[i]+1, id-1, cur);
			}
			// cout<<TL.sum[1]+inf*(n+1-i)<<endl;
		}
		printf("%lld%c", 2ll*(TR.sum[1]+TL.sum[1]+inf*(n+1-i)*2), " \n"[i==n]);
	}
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(T);
	while(T--){
		solve();
	}
	return 0;
}