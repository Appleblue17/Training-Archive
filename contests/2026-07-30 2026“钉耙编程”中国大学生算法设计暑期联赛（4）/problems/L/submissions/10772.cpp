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
int Test, n, m;
struct sgt{
	int rt[N];
	int idx;
	int sz[N*60], ls[N*60], rs[N*60];
	int gen(int p){
		++idx; 
		sz[idx]=sz[p];
		ls[idx]=ls[p];
		rs[idx]=rs[p];
		return idx;
	}
	void add(int &p, int q, int l, int r, int x){
		p=gen(q);
		++sz[p];
		if(l==r) return ;
		int mid=(l+r)>>1;
		if(x<=mid) add(ls[p], ls[q], l, mid, x);
		else add(rs[p], rs[q], mid+1, r, x);
	}
	int lim;
	int fnd(int p, int q, int l, int r, int L, int R){
		if(L<=l&&r<=R){
			if(lim>sz[p]-sz[q]){
				lim-=sz[p]-sz[q];
				return -1;
			}
			if(l==r) return l;
			int mid=(l+r)>>1;
			if(lim<=sz[ls[p]]-sz[ls[q]]) return fnd(ls[p], ls[q], l, mid, L, R);
			lim-=sz[ls[p]]-sz[ls[q]];
			return fnd(rs[p], rs[q], mid+1, r, L, R);
		}
		int mid=(l+r)>>1, ret=-1;
		if(L<=mid) ret=fnd(ls[p], ls[q], l, mid, L, R);
		if(R>mid&&ret==-1) ret=fnd(rs[p], rs[q], mid+1, r, L, R);
		return ret;
	}
}T;
char s[N];
int x[N], y[N], c[N], sa[N], ht[N], rk[N];
void get_sa(){
	for(int i=1; i<=n*2; ++i) y[i]=0;
	for(int i=1; i<='z'; ++i) c[i]=0;
	for(int i=1; i<=n; ++i) c[x[i]=s[i]]++;
	int m='z';
	for(int i=2; i<=m; ++i) c[i]+=c[i-1];
	for(int i=n; i; --i) sa[c[x[i]]--]=i;
	for(int k=1; k<=n; k<<=1){
		int num=0;
		for(int i=n-k+1; i<=n; ++i) y[++num]=i;
		for(int i=1; i<=n; ++i){
			if(sa[i]>k) y[++num]=sa[i]-k;
		}
		for(int i=1; i<=m; ++i) c[i]=0;
		for(int i=1; i<=n; ++i) c[x[i]]++;
		for(int i=2; i<=m; ++i) c[i]+=c[i-1];
		for(int i=n; i; --i) sa[c[x[y[i]]]--]=y[i], y[i]=0;
		for(int i=1; i<=n; ++i) swap(x[i], y[i]);
		x[sa[1]]=1; num=1;
		for(int i=2; i<=n; ++i) x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?num:++num;
		if(num==n) break;
		m=num;
	}
}
void get_ht(){
	for(int i=1; i<=n; ++i) rk[sa[i]]=i;
	for(int i=1, k=0; i<=n; ++i){
		if(rk[i]==1) continue;
		if(k) --k;
		int j=sa[rk[i]-1];
		while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) ++k;
		ht[rk[i]]=k;
	}
}
int stt[20][N], lg[N];
void build_stt(){
	for(int i=2; i<=n; ++i) lg[i]=lg[i>>1]+1;
	for(int i=1; i<=n; ++i) stt[0][i]=ht[i];
	for(int t=1; t<=lg[n]; ++t){
		for(int i=1; i+(1<<t)-1<=n; ++i){
			stt[t][i]=min(stt[t-1][i], stt[t-1][i+(1<<(t-1))]);
		}
	}
}
int lcp(int x, int y){
	if(x==y) return n-x+1;
	x=rk[x]; y=rk[y];
	if(x>y) swap(x, y);
	++x;
	int t=lg[y-x+1];
	return min(stt[t][x], stt[t][y-(1<<t)+1]);
}
int ql[N], qr[N];
set<int> st[N]; int rt[N];
int p[N];
vector<pii> bin[N];
struct BIT{
	pii tr[N];
	void clr(){
		for(int i=1; i<=n+1; ++i) tr[i]=mapa(-1e9, 0);
	}
	void upd(int x, pii v){
		for(; x<=n+1; x+=(x&-x)) tr[x]=max(tr[x], v);
	}
	pii get(int x){
		pii ret=mapa(-1e9, 0);
		for(; x; x-=(x&-x)) ret=max(ret, tr[x]);
		return ret;
	}
}T1, T2;
vector<int> qry[N];
pii ans[N];
void solve(){
	read(n); read(m);
	scanf("%s", s+1);
	get_sa();
	get_ht();
	build_stt();
	for(int i=1; i<=n; ++i) qry[i].clear();
	for(int i=1; i<=m; ++i) {
		read(ql[i]), read(qr[i]);
		qry[ql[i]].ep(i);
	}
	for(int i=1; i<=n; ++i) st[i].clear(), st[i].insert(i), rt[i]=i, p[i]=i, bin[i].clear();
	sort(p+2, p+n+1, [&](int x, int y){return ht[x]<ht[y];});
	for(int i=n; ht[p[i]]; --i){
		int l=rt[sa[p[i]-1]], r=rt[sa[p[i]]];
		if(st[l].size()>st[r].size()) swap(l, r);
		for(auto t:st[l]){
			set<int>::iterator it=st[r].lower_bound(t);
			if(it!=st[r].end()){
				bin[t].ep(*it, ht[p[i]]);
			}
			if(it!=st[r].begin()){
				--it;
				bin[*it].ep(t, ht[p[i]]);
			}
		}
		for(auto t:st[l]) st[r].insert(t), rt[t]=r;
	}
	T1.clr(); T2.clr();
	T.idx=0;
	for(int i=1; i<=n+1; ++i) T.rt[i]=0;
	T.add(T.rt[n], T.rt[n+1], 1, n, rk[n]);
	for(int l=n-1; l>=1; --l){
		T.add(T.rt[l], T.rt[l+1], 1, n, rk[l]);
		for(auto [r, v]:bin[l]){
			T1.upd(r+v, mapa(v, -min(rk[l], rk[r])));
			T2.upd(n+2-(r+v), mapa(-r, -min(rk[l], rk[r])));
		}
		for(auto id:qry[l]){
			int r=qr[id];
			pii v1=T1.get(r+1), v2=T2.get(n+1-r);
			v2.fi+=r+1;
			ans[id]=max(v1, v2);
		}
	}
	for(int i=1; i<=m; ++i){
		int H=ans[i].fi;
		int t=-ans[i].se, id=sa[t];
		int lp=t, rp=t;
		int l=ql[i], r=qr[i];
		{
			int lv=1, rv=t-1, mid;
			while(lv<=rv){
				mid=(lv+rv)>>1;
				if(lcp(sa[mid], id)>=H) {
					lp=mid; rv=mid-1;
				}
				else{
					lv=mid+1;
				}
			}
		}
		{
			int lv=t+1, rv=n, mid;
			while(lv<=rv){
				mid=(lv+rv)>>1;
				if(lcp(sa[mid], id)>=H) {
					rp=mid; lv=mid+1;
				}
				else{
					rv=mid-1;
				}
			}
		}
		int ansl, ansr;
		if(rk[r-H+1]>=lp&&rk[r-H+1]<=rp){
			ansl=r-H+1;
			T.lim=1;
			ansr=sa[T.fnd(T.rt[l], T.rt[r-H+1], 1, n, lp, rp)];
		}
		else{
			T.lim=1;
			ansl=sa[T.fnd(T.rt[l], T.rt[r-H+1], 1, n, lp, rp)];
			T.lim=2;
			ansr=sa[T.fnd(T.rt[l], T.rt[r-H+1], 1, n, lp, rp)];			
		}
		printf("%d %d %d\n", H, ansl, ansr);
	}
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(Test);
	while(Test--){
		solve();
	}
	return 0;
}