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
int a[N], b[N];
mt19937_64 rnd(time(0));
ull hs[N];
ull tr[N*100], tag[N*100]; int ls[N*100], rs[N*100];
int idx, rt[N];
inline int gen(){
	++idx;
	tr[idx]=0; ls[idx]=0; rs[idx]=0; 
	return idx;
}
void mdf(int &p, int q, int l, int r, int x){
	p=gen();
	tr[p]=tr[q]; ls[p]=ls[q]; rs[p]=rs[q]; 
	tr[p]^=hs[x];
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid) mdf(ls[p], ls[q], l, mid, x);
	else mdf(rs[p], rs[q], mid+1, r, x);
}
vector<int> vec;
void pick(int p, int q, int l, int r){
	if(vec.size()==60) return ;
	if((tr[p]^tr[q])==0) return ;
	if(l==r){
		vec.push_back(l);
		return ;
	}
	int mid=(l+r)>>1;
	pick(ls[p], ls[q], l, mid); pick(rs[p], rs[q], mid+1, r);
}
int dp[61][61][61];
void init(){
	dp[0][0][0]=1;
	for(int i=0; i<60; ++i){
		for(int j=0; j<60; ++j){
			for(int k=0; k<60; ++k) if(dp[i][j][k]){
				dp[i+1][j][k+1]^=1;
				for(int w=0; w<=k; ++w) if((w&k)==w) dp[i+1][j+1][k-w]^=1;
			}
		}
	}
}
void solve(){
	read(n); 
	for(int i=1; i<=n; ++i) read(a[i]), b[i]=a[i];
	sort(b+1, b+n+1);
	int len=unique(b+1, b+n+1)-b-1;
	for(int i=1; i<=n; ++i) a[i]=lower_bound(b+1, b+len+1, a[i])-b;
	for(int i=1; i<=n; ++i) hs[i]=rnd();
	idx=0;
	for(int i=1; i<=n; ++i) mdf(rt[i], rt[i-1], 1, n, a[i]);
	read(m);
	int preans=0;
	while(m--){
		int l, r; ll k, v;
		read(l); read(r); read(k); read(v);
		l^=preans; r^=preans; k^=preans; v^=preans;
		vec.clear();
		pick(rt[r], rt[l-1], 1, n);
		if(vec.size()==60){
			printf("0\n");
			continue;
		}
		sort(vec.begin(), vec.end());
		if(!vec.empty()&&b[vec.back()]>v){
			printf("0\n");
			continue;
		}
		int ans=0;
		if(k&1){
			if((v-vec.size())&1){
				int t=__builtin_popcountll((k-1)/2);
				for(int i=0; i<=t; ++i){
					if((i&t)!=i) continue;
					ans^=dp[t-i][vec.size()][0];
				}
			}
		}
		else{
			ans=dp[__builtin_popcountll(k/2)][vec.size()][0];
		}
		printf("%d\n", ans);
		preans+=ans;
	}
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	init();
	read(T);
	while(T--){
		solve();
	}
	return 0;
}