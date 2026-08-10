#include<bits/stdc++.h>
#define int long long
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
ll a[27];
char s[N];
ll t,n,m,x,y,ans,k,q;
void solve(){
	ans=0;
	scanf("%lld",&n);
	scanf("%lld",&m);
	scanf("%s",s+1);
	int k = __gcd(n,m);
	int dcnt = n/k;
	if(dcnt % 2 == 0)k*=2,dcnt/=2;
	for(int j=1;j<=(k+1)/2;j++){
		memset(a,0,sizeof(a));
		int acnt = 0;
		for(int i=1;i<=n;i+=k){
			a[s[i+j-1]-'a']++;
			acnt++;
			if(i+j-1 != i+k-j)a[s[i+k-j]-'a']++,acnt++;
			//printf("check pos j=%lld %lld %lld\n",j,i+j-1,i+k-j);
		}
		int mx=0;
		for(int i=0;i<26;i++){
			mx = max(a[i],mx);
		}
		ans += acnt - mx;
	}

	printf("%lld\n",ans);
	
}
signed main(){
	int T;cin >> T;for(int i=1;i<=T;i++){
		solve();
	}
}