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
const int N=1e5+5;
int T, n, m;
int ax[N<<1], av[N<<1];
struct frac{
	int up, down;
	frac(int _u=0, int _d=1){up=_u; down=_d;}
	bool operator <(const frac &t)const{
		return 1ll*up*t.down<1ll*t.up*down;
	}
	bool operator <=(const frac &t)const{
		return 1ll*up*t.down<=1ll*t.up*down;
	}
}ans[N];
vector<int> bin[N<<2];
int qa[N], qb[N];
void add(int p, int l, int r, int L, int R, int x){
	if(L<=l&&r<=R) {
		bin[p].ep(x); return ;
	}
	int mid=(l+r)>>1;
	if(L<=mid) add(p<<1, l, mid, L, R, x);
	if(R>mid) add(p<<1|1, mid+1, r, L, R, x);
}
int stk[N], top;
int id[N];
int cross(int x, int y, int xx, int yy){
	if(1ll*x*yy==1ll*y*xx) return 0;
	else if(1ll*x*yy>1ll*y*xx) return 1;
	else return -1;
}
void dfs(int p, int l, int r){
	for(int i=l; i<=r; ++i) id[i]=i;
	sort(id+l, id+r+1, [&](int x, int y){return (av[x]==av[y])?ax[x]<ax[y]:av[x]<av[y];});
	sort(bin[p].begin(), bin[p].end(), [&](int x, int y){return av[x]<av[y];});
	int it=l;
	top=0;
	for(auto t:bin[p]){
		while(it<=r&&av[id[it]]<av[t]){
			while(top>=2&&cross(av[stk[top]]-av[stk[top-1]], ax[stk[top]]-ax[stk[top-1]], av[id[it]]-av[stk[top]], ax[id[it]]-ax[stk[top]])>0) --top;
			stk[++top]=id[it]; ++it;
		}
		int l=1, r=top;
		while(l+2<r){
			int lmid=l+(r-l)/3;
			int rmid=r-(r-l)/3;
			if((frac){ax[t]-ax[stk[lmid]], av[t]-av[stk[lmid]]}<=(frac){ax[t]-ax[stk[rmid]], av[t]-av[stk[rmid]]}){
				r=rmid-1;
			}
			else{
				l=lmid+1;
			}
		}
		for(int i=l; i<=r; ++i){
			if(ans[t-n]<(frac){ax[stk[i]]-ax[t], av[t]-av[stk[i]]}){
				ans[t-n]=(frac){ax[stk[i]]-ax[t], av[t]-av[stk[i]]};
			}
		}
	}
	
	sort(id+l, id+r+1, [&](int x, int y){return (av[x]==av[y])?ax[x]>ax[y]:av[x]>av[y];});
	sort(bin[p].begin(), bin[p].end(), [&](int x, int y){return av[x]>av[y];});
	it=l;
	top=0;
	for(auto t:bin[p]){
		while(it<=r&&av[id[it]]>av[t]){
			while(top>=2&&cross(av[stk[top]]-av[stk[top-1]], ax[stk[top]]-ax[stk[top-1]], av[id[it]]-av[stk[top]], ax[id[it]]-ax[stk[top]])>0) --top;
			stk[++top]=id[it]; ++it;
		}
		int l=1, r=top;
		while(l+2<r){
			int lmid=l+(r-l)/3;
			int rmid=r-(r-l)/3;
			if((frac){ax[stk[lmid]]-ax[t], av[stk[lmid]]-av[t]}<=(frac){ax[stk[rmid]]-ax[t], av[stk[rmid]]-av[t]}){
				r=rmid-1;
			}
			else{
				l=lmid+1;
			}
		}
		for(int i=l; i<=r; ++i){
			if(ans[t-n]<(frac){ax[t]-ax[stk[i]], av[stk[i]]-av[t]}){
				ans[t-n]=(frac){ax[t]-ax[stk[i]], av[stk[i]]-av[t]};
			}
		}
	}
	if(l==r) return ;
	int mid=(l+r)>>1;
	dfs(p<<1, l, mid); dfs(p<<1|1, mid+1, r);
}
void solve(){
	read(n); read(m);
	for(int i=1; i<=n; ++i){
		read(ax[i]); read(av[i]);
	}
	for(int i=1; i<=n*4; ++i) bin[i].clear();
	for(int i=1, l, r; i<=m; ++i){
		read(l); read(r); read(ax[i+n]); read(av[i+n]);
		add(1, 1, n, l, r, i+n);
		ans[i]=(frac){-1, 1};
	}
	dfs(1, 1, n);
	for(int i=1; i<=m; ++i){
		if(ans[i].up<0) printf("-1\n");
		else{
			int d=__gcd(ans[i].up, ans[i].down);
			printf("%d/%d\n", ans[i].up/d, ans[i].down/d);
		}
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