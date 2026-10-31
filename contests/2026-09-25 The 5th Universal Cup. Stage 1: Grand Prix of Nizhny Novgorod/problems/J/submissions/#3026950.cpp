#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1100000;
int n,w,a[N],sm[N],cur,t;

signed main(){
	scanf("%lld%lld",&n,&w);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	sm[n]=0;
	for(int i=n-1;i>=1;i--){
		sm[i] = sm[i+1] + a[i];
	}
	int ans = 1e18;
	cur = 0;
	for(int i=n;i>=1;i--){
		cur += sm[i];
		int t = n-i+2;
		int x = (w-cur-1)/a[n]+1;
		//printf("w-cur=%lld,t=%lld,x=%lld\n",w-cur,t,x);
		ans = min(ans,(x)/t + n-i);
	}
	printf("%lld\n",ans);
}
