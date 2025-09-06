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
int n, m;
struct DS{
	const int B=600;
	ll mn[N], a[N];
	int pos[N], lp[N], rp[N];
	void init(){
		for(int i=1; i<=n; ++i){
			pos[i]=(i-1)/B+1;
			a[i]=1e18;
		}
		for(int i=1; i<=pos[n]; ++i){
			mn[i]=1e18;
			lp[i]=rp[i-1]+1; rp[i]=rp[i-1]+B;
		}
		rp[pos[n]]=n;
	}
	inline void apply(int x, ll v){
		a[x]=min(a[x], v);
		mn[pos[x]]=min(mn[pos[x]], v);
	}
	ll get(int l, int r){
		ll ret=1e18;
		if(pos[l]==pos[r]){
			for(int i=l; i<=r; ++i) ret=min(ret, a[i]);
			return ret;
		}
		for(int i=l; i<=rp[pos[l]]; ++i) ret=min(ret, a[i]);
		for(int i=pos[l]+1; i<pos[r]; ++i) ret=min(ret, mn[i]);
		for(int i=lp[pos[r]]; i<=r; ++i) ret=min(ret, a[i]);
		return ret;
	}
}D;
vector<pii> ask[N]; vector<int> item[N];
ll ans[N];
int px[N], py[N];
unordered_map<ll, vector<int> > h[30];
inline ll hs(int x, int y){
	return 200000000ll*x+y;
}
int dx[9]={-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[9]={1, 1, 1, 0, 0, 0, -1, -1, -1};
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	read(n); read(m);
	for(int i=1; i<=n; ++i){
		read(px[i]); read(py[i]);
		for(int o=0; o<=28; ++o){
			int cx=px[i]>>o, cy=py[i]>>o;
			for(int k=0; k<9; ++k){
				int wx=cx+dx[k], wy=cy+dy[k];
				if(h[o].find(hs(wx, wy))!=h[o].end()){
					vector<int> &cur=h[o][hs(wx, wy)];
					vector<int> nxt;
					if(o==0){
						if(!cur.empty()) item[i].ep(cur[0]), nxt.ep(cur[0]);
					}
					else{
						for(auto t:cur) {
							item[i].ep(t);
							if(1ll*(px[i]-px[t])*(px[i]-px[t])+1ll*(py[i]-py[t])*(py[i]-py[t])>=1ll<<(o*2-2)){
								nxt.ep(t);
							}
						}
					}
					cur=nxt;
				}
			}
			h[o][hs(cx, cy)].push_back(i);
		}
	}
	for(int i=1, l, r; i<=m; ++i){
		read(l); read(r);
		ask[r].ep(l, i);
	}
	D.init();
	for(int i=1; i<=n; ++i){
		for(auto t:item[i]){
			D.apply(t, 1ll*(px[i]-px[t])*(px[i]-px[t])+1ll*(py[i]-py[t])*(py[i]-py[t]));
		}
		for(auto t:ask[i]){
			ans[t.se]=D.get(t.fi, i);
		}
	}
	for(int i=1; i<=m; ++i) printf("%lld\n", ans[i]);
	return 0;
}

