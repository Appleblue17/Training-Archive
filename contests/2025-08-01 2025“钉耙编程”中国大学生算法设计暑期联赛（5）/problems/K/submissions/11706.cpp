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
int T, n, n1, n2, m1, m2;
ll by[N], wy[N];
ll lis[N]; int len1, len2;
inline int rid(int x, int d){
	//d=0 fire
	//d=1 black
	//d=2 white
	if(d==0) return x;
	if(d==1) return x+n;
	return x+n+n1;
}
vector<int> blk[N], wht[N];
vector<int> e[N];
void input(){
	read(n); read(n1); read(n2);
	read(m1); read(m2);
    for(int i=1; i<=n+n1+n2; ++i) e[i].clear();
	len1=0;
	for(int i=1; i<=n1; ++i){
		read(by[i]); read(by[i]);
		lis[++len1]=by[i];
	}
	sort(lis+1, lis+len1+1);
	len1=unique(lis+1, lis+len1+1)-lis-1;
	for(int i=1; i<=len1; ++i) blk[i].clear();
	for(int i=1; i<=n1; ++i){
		by[i]=lower_bound(lis+1, lis+len1+1, by[i])-lis;
		blk[by[i]].push_back(rid(i, 1));
	}
	len2=0;
	for(int i=1; i<=n2; ++i){
		read(wy[i]); read(wy[i]); wy[i]=-wy[i];
		lis[++len2]=wy[i];
	}
	sort(lis+1, lis+len2+1);
	len2=unique(lis+1, lis+len2+1)-lis-1;
	for(int i=1; i<=len2; ++i) wht[i].clear();
	for(int i=1; i<=n2; ++i){
		wy[i]=lower_bound(lis+1, lis+len2+1, wy[i])-lis;
		wht[wy[i]].push_back(rid(i, 2));
	}
	for(int i=1, op, u, v; i<=m1; ++i){
		read(op); read(u); read(v);
		if(op==1){
			e[rid(v, 1)].ep(rid(u, 0));
			e[rid(u, 0)].ep(rid(v, 1));
		}
		else{
			e[rid(v, 1)].ep(rid(u, 1));
			e[rid(u, 1)].ep(rid(v, 1));
		}
	}
	for(int i=1, op, u, v; i<=m2; ++i){
		read(op); read(u); read(v);
		if(op==1){
			e[rid(v, 2)].ep(rid(u, 0));
			e[rid(u, 0)].ep(rid(v, 2));
		}
		else{
			e[rid(v, 2)].ep(rid(u, 2));
			e[rid(u, 2)].ep(rid(v, 2));
		}
	}
}
struct DSU{
	int fa[N], sz[N], sum[N];
	inline int get(int x){
		if(x==fa[x]) return x;
		return get(fa[x]);
	}
	struct node{
		int rfx, rfy;
		int rszx, rszy;
		int rsumx, rsumy;
	};
	vector<node> stk;
	void merge(int x, int y){
		x=get(x); y=get(y);
		if(x==y) return ;
		if(sz[x]<sz[y]) swap(x, y);
		stk.push_back((node){x, y, sz[x], sz[y], sum[x], sum[y]});
		sz[x]+=sz[y]; sum[x]+=sum[y]; fa[y]=x;
	}
	void back(int x){
		while((int)stk.size()>x){
			node cur=stk.back(); stk.pop_back();
			fa[cur.rfx]=cur.rfx; fa[cur.rfy]=cur.rfy;
			sz[cur.rfx]=cur.rszx; sz[cur.rfy]=cur.rszy;
			sum[cur.rfx]=cur.rsumx; sum[cur.rfy]=cur.rsumy;
		}
	}
	void init(){
		for(int i=1; i<=n; ++i) fa[rid(i, 0)]=rid(i, 0), sz[rid(i, 0)]=1, sum[rid(i, 0)]=1;
		for(int i=1; i<=n1; ++i) fa[rid(i, 1)]=rid(i, 1), sz[rid(i, 1)]=1, sum[rid(i, 1)]=0;
		for(int i=1; i<=n2; ++i) fa[rid(i, 2)]=rid(i, 2), sz[rid(i, 2)]=1, sum[rid(i, 2)]=0;
		stk.clear();
	}
	bool check(){
		return sum[get(1)]==n;
	}
}U;
int ans[N];
void calc(int lp, int rp, int lv, int rv){
	if(lp>rp) return ;
	if(lv==rv){
		for(int i=lp; i<=rp; ++i){
			ans[i]=lv;
		}
		return ;
	}
	int midv=(lv+rv)>>1;
	int top=U.stk.size();
	for(int i=lv; i<=midv; ++i) {
		for(auto x:blk[i]){
			for(auto y:e[x]){
                if(y<=n) U.merge(x, y);
                else if(by[y-n]<=midv) U.merge(x, y);
			}
		}
	}
	int top2=U.stk.size();
	int L=lp, R=rp, mid, ret=lp-1;
	while(L<=R){
		mid=(L+R)>>1;
		int curtop=U.stk.size();
		for(int i=L; i<=mid; ++i){
			for(auto x:wht[i]){
				for(auto y:e[x]){
                    if(y<=n) U.merge(x, y);
                    else if(wy[y-n-n1]<=mid) U.merge(x, y);
				}
			}
		}
		if(!U.check()){
			ret=mid; L=mid+1;
		}
		else{
            R=mid-1;
            U.back(curtop);
		}
	}
	U.back(top2);
	calc(lp, ret, midv+1, rv);
	U.back(top);
	for(int i=lp; i<=ret; ++i) {
		for(auto x:wht[i]){
			for(auto y:e[x]){
                if(y<=n) U.merge(x, y);
                else if(wy[y-n-n1]<=mid) U.merge(x, y);
			}
		}	
	}
	calc(ret+1, rp, lv, midv);
    U.back(top);
}
ll sufsum[N];
void solve(){
	input();
	U.init();
    for(int i=0; i<len2; ++i) ans[i]=len1;
	calc(0, len2-1, 0, len1);
	sufsum[len1+1]=0;
	for(int i=len1; i>=1; --i){
		sufsum[i]=sufsum[i+1]+blk[i].size();
	}
	ll res=0;
	for(int i=0; i<len2; ++i){
        // cout<<i<<' '<<ans[i]<<endl;
		res+=sufsum[ans[i]+1]*wht[i+1].size();
	}
	printf("%lld\n", res);
}
int main(){
	read(T);
	while(T--){
		solve();
	}
	return 0;
}