#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define N 1000010
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ull,ull> puu;
//mt19937_64 rng(GetTickCount());
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int mo=1e9+7;
using namespace std;
ll a[N],b[N];
ll t,n,m,x,y,ans,k;
void solve(){
	ans=0;
	scanf("%lld",&n);
    ll mx = 0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
        mx = max(mx,a[i]);
	}
    if(n<=2)printf("0\n");
	else printf("%lld\n",mx*(n-3)+max(a[1],a[n]));
}
int main(){
	int T;
    scanf("%d",&T);
	for(int i=1;i<=T;i++){
		solve();
	}
}