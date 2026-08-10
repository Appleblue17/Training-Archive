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
int n;
int p[N], a[N];

int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n);
	for(int i=1; i<=n; ++i) read(p[i]), a[p[i]]=i;
	set<int> s, s2;
	s.insert(0);
	int ans=0;
	for(int i=1; i<=n; ++i){
		vector<int> vec, vec2;
		while(!s2.empty()){
			auto it=s2.upper_bound(a[i]);
			if(it==s2.end()) break;
			vec.ep(p[*it]);
			s2.erase(it);
		}
		sort(vec.begin(), vec.end());
		for(auto t:vec){
			auto it=s.upper_bound(t);
			--it;
			bool flag=0;
			if((*it)!=0) {
				--it;
				if((*it)==0) flag=1;
				++it;
				s.erase(it);
			}
			else{
				flag=1;
			}
			if(!flag) vec2.ep(a[t]);
		}
		for(auto t:vec2) s2.insert(t);
		s.insert(i);
		s2.insert(a[i]);
		ans=max(ans, (int)s.size()-2);
	}
	printf("%d\n", n-1-ans);
	return 0;
}