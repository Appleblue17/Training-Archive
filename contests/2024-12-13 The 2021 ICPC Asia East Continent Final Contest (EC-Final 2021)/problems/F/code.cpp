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
const int N=4e5+5;
int n, m, c;
int a[N];
ll sum[N];
struct T1{
	struct info{
		ll ans, ls, rs, sum;
		void set(int x){
			sum=x;
			ans=max(0, x);
			ls=rs=ans;
		}
	}tr[N<<2];
	inline friend info operator +(info x, info y){
		info z;
		z.ans=max(x.ans, y.ans);
		z.sum=x.sum+y.sum;
		z.ls=max(x.ls, x.sum+y.ls);
		z.rs=max(y.rs, y.sum+x.rs);
		z.ans=max(z.ans, x.rs+y.ls);
		return z;
	}
	void build(int p, int l, int r){
		if(l==r){
			tr[p].set(a[l]);
			return ;
		}
		int mid=(l+r)>>1;
		build(p<<1, l, mid);
		build(p<<1|1, mid+1, r);
		tr[p]=tr[p<<1]+tr[p<<1|1];
	}
	void mdf(int p, int l, int r, int x, int v){
		if(l==r){
			tr[p].set(v);
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid) mdf(p<<1, l, mid, x, v);
		else mdf(p<<1|1, mid+1, r, x, v);
		tr[p]=tr[p<<1]+tr[p<<1|1];
	}
	void get(int p, int l, int r, int L, int R, info &ret){
		if(L>R) return ;
		if(L<=l&&r<=R){
			ret=ret+tr[p];
			return ;
		}
		int mid=(l+r)>>1;
		if(L<=mid) get(p<<1, l, mid, L, R, ret);
		if(R>mid) get(p<<1|1, mid+1, r, L, R, ret);
	}
}t1;
struct T2{
	ll a[N<<2], b[N<<2], mx[N<<2], taga[N<<2], tagb[N<<2];
	void build(int p, int l, int r){
		if(l==r){
			a[p]=sum[l]; b[p]=sum[l+c];
			mx[p]=b[p]-a[p];
			return ;
		}
		int mid=(l+r)>>1;
		build(p<<1, l, mid); build(p<<1|1, mid+1, r);
		a[p]=min(a[p<<1], a[p<<1|1]);
		b[p]=max(b[p<<1], b[p<<1|1]);
		mx[p]=max(max(mx[p<<1], mx[p<<1|1]), b[p<<1]-a[p<<1|1]);
	}
	void down(int p){
		if(taga[p]!=0){
			taga[p<<1]+=taga[p];
			a[p<<1]+=taga[p];
			mx[p<<1]-=taga[p];
			taga[p<<1|1]+=taga[p];
			a[p<<1|1]+=taga[p];
			mx[p<<1|1]-=taga[p];
			taga[p]=0;
		}
		if(tagb[p]!=0){
			tagb[p<<1]+=tagb[p];
			b[p<<1]+=tagb[p];
			mx[p<<1]+=tagb[p];
			tagb[p<<1|1]+=tagb[p];
			b[p<<1|1]+=tagb[p];
			mx[p<<1|1]+=tagb[p];
			tagb[p]=0;
		}
	}
	void mdfa(int p, int l, int r, int L, int R, ll v){
		if(L>R) return ;
		if(L<=l&&r<=R){
			taga[p]+=v;
			a[p]+=v;
			mx[p]-=v;
			return ;
		}
		down(p);
		int mid=(l+r)>>1;
		if(L<=mid) mdfa(p<<1, l, mid, L, R, v);
		if(R>mid) mdfa(p<<1|1, mid+1, r, L, R, v);
		a[p]=min(a[p<<1], a[p<<1|1]);
		b[p]=max(b[p<<1], b[p<<1|1]);
		mx[p]=max(max(mx[p<<1], mx[p<<1|1]), b[p<<1]-a[p<<1|1]);
	}
	void mdfb(int p, int l, int r, int L, int R, ll v){
		if(L>R) return ;
		if(L<=l&&r<=R){
			tagb[p]+=v;
			b[p]+=v;
			mx[p]+=v;
			return ;
		}
		down(p);
		int mid=(l+r)>>1;
		if(L<=mid) mdfb(p<<1, l, mid, L, R, v);
		if(R>mid) mdfb(p<<1|1, mid+1, r, L, R, v);
		a[p]=min(a[p<<1], a[p<<1|1]);
		b[p]=max(b[p<<1], b[p<<1|1]);
		mx[p]=max(max(mx[p<<1], mx[p<<1|1]), b[p<<1]-a[p<<1|1]);
	}
	void qry(int p, int l, int r, int L, int R, ll &pa, ll &pb, ll &pans){
		if(L>R) return ;
		if(L<=l&&r<=R){
			pans=max(max(pans, mx[p]), pb-a[p]);
			pa=min(pa, a[p]);
			pb=max(pb, b[p]);
			return ;
		}
		int mid=(l+r)>>1;
		down(p);
		if(L<=mid) qry(p<<1, l, mid, L, R, pa, pb, pans);
		if(R>mid) qry(p<<1|1, mid+1, r, L, R, pa, pb, pans);
	}
}t2;
struct T3{
	ll mx[N<<2], mx2[N<<2];
	void build(int p, int l, int r){
		if(l==r){
			T1::info tem; tem.set(0);
			t1.get(1, 1, n, (l-1)*c+1, l*c, tem);
			mx2[p]=tem.ans;
			mx[p]=0;
			ll pa=1e18, pb=-1e18;
			t2.qry(1, 1, n-c, (l-1)*c+1, l*c, pa, pb, mx[p]);
			return ;
		}
		int mid=(l+r)>>1;
		build(p<<1, l, mid); build(p<<1|1, mid+1, r);
		mx[p]=max(mx[p<<1], mx[p<<1|1]);
		mx2[p]=max(mx2[p<<1], mx2[p<<1|1]);
	}
	void mdf(int p, int l, int r, int x){
		if(l==r){
			T1::info tem; tem.set(0);
			t1.get(1, 1, n, (l-1)*c+1, l*c, tem);
			mx2[p]=tem.ans;
			mx[p]=0;
			ll pa=1e18, pb=-1e18;
			t2.qry(1, 1, n-c, (l-1)*c+1, l*c, pa, pb, mx[p]);
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid) mdf(p<<1, l, mid, x);
		else mdf(p<<1|1, mid+1, r, x);
		mx[p]=max(mx[p<<1], mx[p<<1|1]);
		mx2[p]=max(mx2[p<<1], mx2[p<<1|1]);
	}
	ll get(int p, int l, int r, int L, int R){
		if(L>R) return 0;
		if(L<=l&&r<=R) return max(mx[p], mx2[p]);
		int mid=(l+r)>>1; ll ret=0;
		if(L<=mid) ret=get(p<<1, l, mid, L, R);
		if(R>mid) ret=max(ret, get(p<<1|1, mid+1, r, L, R));
		return ret;
	}
}t3;
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n); read(m); read(c);
	for(int i=1; i<=n; ++i) read(a[i]), sum[i]=sum[i-1]+a[i];
	if(n==c) a[++n]=-1e9, sum[n]=sum[n-1]+a[n];
	while(n%c) a[++n]=-1e9, sum[n]=sum[n-1]+a[n];
	t1.build(1, 1, n);
	t2.build(1, 1, n-c);
	t3.build(1, 1, n/c-1);
	int tp, x, y;
	while(m--){
		read(tp); read(x); read(y);
		if(tp==1){
			t1.mdf(1, 1, n, x, y);
			t2.mdfa(1, 1, n-c, x, n-c, y-a[x]);
			t2.mdfb(1, 1, n-c, max(1, x-c), n-c, y-a[x]);
			if((x-1)/c>=1) t3.mdf(1, 1, n/c-1, (x-1)/c);
			if((x-1)/c+1<=n/c-1) t3.mdf(1, 1, n/c-1, (x-1)/c+1);
			a[x]=y;
		}
		else{
			ll ans=0;
			ll pa=1e18, pb=-1e18;
			t2.mdfa(1, 1, n-c, 1, x-1, 1e16); t2.mdfa(1, 1, n-c, y+1, n-c, 1e16);
			t2.mdfb(1, 1, n-c, 1, x-c-1, -1e16); t2.mdfb(1, 1, n-c, max(1, y-c+1), n-c, -1e16);
			t2.qry(1, 1, n-c, x, min(n-c, x+c-1), pa, pb, ans);
			pa=1e18, pb=-1e18;
			t2.qry(1, 1, n-c, max(1, y-c*2+1), y-c, pa, pb, ans);
			t2.mdfa(1, 1, n-c, 1, x-1, -1e16); t2.mdfa(1, 1, n-c, y+1, n-c, -1e16);
			t2.mdfb(1, 1, n-c, 1, x-c-1, 1e16); t2.mdfb(1, 1, n-c, max(1, y-c+1), n-c, 1e16);
			T1::info tem; tem.set(0);
			t1.get(1, 1, n, x, min(y, x+c-1), tem);
			ans=max(ans, tem.ans);
			tem.set(0);
			t1.get(1, 1, n, max(x, y-c+1), y, tem);
			ans=max(ans, tem.ans);
			if((y-1)/c>(x-1)/c+1){
				// cout<<(x-1)/c+2<<' '<<(y-1)/c-1<<endl;
				ans=max(ans, t3.get(1, 1, n/c-1, (x-1)/c+2, (y-1)/c-1));
				tem.set(0);
				t1.get(1, 1, n, ((y-1)/c-1)*c+1, ((y-1)/c)*c, tem);
				ans=max(ans, tem.ans);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
