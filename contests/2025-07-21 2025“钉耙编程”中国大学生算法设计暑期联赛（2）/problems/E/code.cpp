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
int T, n;
int a[N], b[N], pos[N];
vector<int> vec;
int x;
void perform(int st, int c){
	for(int i=st; i<st+x; ++i) b[i-st]=a[i];
	for(int i=st; i<st+x; ++i) a[i]=b[(i-st+c)%x];
	for(int i=st; i<st+x; ++i) pos[a[i]]=i;
	while(c--) vec.ep(st);
}
void solve(){
	read(n);
	for(int i=1; i<=n; ++i) read(a[i]);
	if(n==2){
		if(a[1]==2){
			printf("2\n1\n1\n");
		}
		else{
			printf("2\n0\n");
		}
		return ;
	}
	x=100; vec.clear();
	while(2*x>=n) x-=2;
	printf("%d\n", x);
	for(int i=1; i<=n; ++i) pos[a[i]]=i;
	for(int i=n; i>=x; --i){
		int t=pos[i];
		while(t<=i-x+1){
			perform(t, 1); t+=x-1;
		}
		if(t!=i){
			perform(i-x+1, t-i+x);
		}
	}
	// cout<<vec.size()<<endl;
	for(int i=1; i<x-1; ++i){
		if(pos[i]==i) continue;
		int tim=0;
		while(pos[i]!=i+1) perform(i+1, 1), ++tim;
		perform(i+1, 1);
		for(int j=1; j*2<=x; ++j) perform(i+1, 1), perform(i, 1);
		while(tim!=x){
			++tim; perform(i+1, 1);
		}
	}
	// bool flag=1;
	// for(int i=1; i<=n; ++i) flag&=(a[i]==i);
	// cout<<flag<<endl;
	printf("%d\n", (int)vec.size());
	for(auto t:vec) printf("%d ", t);
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