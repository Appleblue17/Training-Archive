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
int T, n, m;
vector<int> vec;
bitset<1024> f[N];
vector<int> e[N];
int id[N];
int deg[N];
int ex[N], ey[N];
void solve(){
	read(n); read(m);
	for(int i=1; i<=n; ++i) e[i].clear();
	bool flg=0;
	for(int i=1; i<=m; ++i){
		read(ex[i]); read(ey[i]);
		if(ex[i]==ey[i]) flg=1;
	}
	if(flg){
		printf("-1\n");
		return ;
	}
	for(int i=1; i<=m; i+=512){
		vec.clear();
		for(int j=i; j<i+512&&j<=m; ++j){
			vec.ep(ex[j]); vec.ep(ey[j]);
		}
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		for(int j=0; j<(int)vec.size(); ++j) id[vec[j]]=j+1;
		for(int x=1; x<=n; ++x) {
			f[x]=0;
			if(id[x]!=0) f[x].set(id[x]-1, 1);
			for(auto y:e[x]){
				++deg[y];
			}
		}
		queue<int> que;
		for(int x=1; x<=n; ++x) if(!deg[x]) que.push(x);
		while(!que.empty()){
			int x=que.front(); que.pop();
			for(auto y:e[x]) {
				f[y]|=f[x];
				--deg[y];
				if(!deg[y]){
					que.push(y);
				}
			}
		}
		for(int j=i, c; j<i+512&&j<=m; ++j){
			if(f[ey[j]][id[ex[j]]-1]){
				printf("2 ");
			}
			else{
				c=id[ex[j]]-1;
				printf("1 ");
				for(auto t:vec){
					if(f[t][c]){
						f[t]|=f[ey[j]];
					}
				}
				e[ey[j]].ep(ex[j]);
			}
		}
		for(auto t:vec) id[t]=0;
	}
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