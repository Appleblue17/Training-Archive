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
int T, n, m, k;
vector<int> e[N];
int col[N];
mt19937 rnd(1234);
int deg[N];
int c[2];
void solve(){
	read(n); read(m); read(k);
	for(int i=1; i<=n; ++i) {
		col[i]=0; deg[i]=0;
		e[i].clear();
	}
	for(int i=1, x, y; i<=m; ++i){
		read(x); read(y);
		e[x].ep(y); e[y].ep(x);
	}
	for(int i=1; i<=n; ++i){
		c[0]=c[1]=0;
		for(auto j:e[i]) if(j<i) {
			c[col[j]]++;
		}
		col[i]=c[1]<c[0];
	}
	set<pii> st;
	for(int i=1; i<=n; ++i){
		for(auto j:e[i]) if(col[i]!=col[j]&&i<j){
			++deg[i]; ++deg[j];
		}
	}
	for(int i=1; i<=n; ++i) st.insert(mapa(deg[i], i));
	while((*st.begin()).fi<=k){
		int id=(*st.begin()).se; st.erase(st.begin());
		for(auto x:e[id]) if(col[x]!=-1&&col[x]!=col[id]){
			st.erase(st.find(mapa(deg[x], x)));
			--deg[x];
			st.insert(mapa(deg[x], x));
		}
		col[id]=-1;
	}
	vector<int> vec[2];
	for(int i=1; i<=n; ++i) if(col[i]!=-1) vec[col[i]].ep(i);
	printf("%d ", (int)vec[0].size());
	for(auto t:vec[0]) printf("%d ", t);
	putchar('\n');
	printf("%d ", (int)vec[1].size());
	for(auto t:vec[1]) printf("%d ", t);
	putchar('\n');
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
