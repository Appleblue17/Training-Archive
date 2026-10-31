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
#define double long double
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
ll a[N],b[N],rj[N];
ll t,n,m,x,y,ans,k,q;
double f(double r){
	//cout << r << endl;
	double ret=0;
	for(int i=1;i<=n;i++){
		double j = rj[i];
		double a;
		if(j >= r)a = (m+1)*(j-r)-m*(n-j)+r;
		else a = -m*(n-r)+r;
		ret += max(j,a)/(double)n;
	}
	//cout << ret << endl;
	return ret;
}
void solve(){
	ans=0;
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	int j=0;b[0]=0;b[n+1] = 2*n+1;
	for(int i=1;i<=n;i++){
		while(a[i] > b[j])j++;
		rj[i] = j-1;
		//printf("rj[%d]=%d\n",i,rj[i]);
	}
	double L=0,R=1e18,ML,MR;
	while(R-L > 1e-8){
		ML = L+(R-L)/3.0;
		MR = L+(R-L)*2/3.0;
		if(f(ML) < f(MR)){
			R = MR;
		}
		else{
			L = ML;
		}
	}
	printf("%.9LF\n",f((R+L)/2.0)/(double)n);
}
signed main(){
	int T;cin >> T;for(int i=1;i<=T;i++){
		solve();
	}
}
