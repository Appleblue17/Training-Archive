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
char s[N];
int tim[N];
vector<pii> add[N], del[N];
int ans[N];
int lp[N], rp[N];
int tr[N];
void mdf(int x){
	for(; x; x-=(x&-x)) ++tr[x];
}
int get(int x){
	int ret=0;
	for(; x<=n; x+=(x&-x)) ret+=tr[x];
	return ret;
}
void solve(){
	read(n); read(m);
	scanf("%s", s+1);
	for(int i=1, l, r, k; i<=m; ++i){
		read(l); read(r); read(k);
		add[r].ep(k, i);
		del[n-l+1].ep(k, i);
	}
	vector<int> vec;
	for(int i=1; i<=n; ++i) {
		lp[i]=i-1, rp[i]=i+1;
		if(s[i]!=s[i-1]) vec.ep(i);
	}
	int cur=0;
	while(!vec.empty()){
		++cur;
		vector<int> vec2;
		for(auto t:vec){
			vec2.ep(rp[t]);
			rp[lp[t]]=rp[t];
			lp[rp[t]]=lp[t];
			tim[t]=cur;
		}
		vec.clear();
		for(auto t:vec2){
			if(t<1||t>n) continue;
			if(tim[t]) continue;
			if(s[t]!=s[lp[t]]) vec.ep(t);
		}
	}
	for(int i=1; i<=n; ++i){
		mdf(tim[i]);
		for(auto t:add[i]){
			ans[t.se]+=get(t.fi+1);
		}
	}
	reverse(s+1, s+n+1);
	for(int i=1; i<=n; ++i) {
		lp[i]=i-1, rp[i]=i+1;
		tr[i]=0; tim[i]=0;
		if(s[i]!=s[i-1]) vec.ep(i);
	}
	cur=0;
	while(!vec.empty()){
		++cur;
		vector<int> vec2;
		for(auto t:vec){
			vec2.ep(rp[t]);
			rp[lp[t]]=rp[t];
			lp[rp[t]]=lp[t];
			tim[t]=cur;
		}
		vec.clear();
		for(auto t:vec2){
			if(t<1||t>n) continue;
			if(tim[t]) continue;
			if(s[t]!=s[lp[t]]) vec.ep(t);
		}
	}
	for(int i=n; i>=1; --i){
		for(auto t:del[i]){
			ans[t.se]-=get(t.fi+1);
		}
		mdf(tim[i]);
	}
	for(int i=1; i<=m; ++i){
		printf("%d\n", max(0, ans[i]));
	}
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	// read(T);
	T=1;
	while(T--){
		solve();
	}
	return 0;
}

