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
int a[N];
void solve(){
    read(n); read(m);
    a[0]=0;
    for(int i=1; i<=n; ++i){
        read(a[i]); a[0]+=a[i];
    }
    for(int i=1, x, y; i<n; ++i){
        read(x); read(y);
    }
    for(int i=1, x; i<=m; ++i){
        read(x);
        if(a[x]) printf("0\n");
        else printf("%d\n", a[0]+1);
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