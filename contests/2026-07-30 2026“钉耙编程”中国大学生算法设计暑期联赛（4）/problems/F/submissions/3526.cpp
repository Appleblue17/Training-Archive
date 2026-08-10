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
int a[N],vis[N],ans[N];
ll n,m;
bool cmp(int a,int b){
	if(a > n/2+1)a = n+1-a;
	if(b > n/2+1)b = n+1-b;
	return a<b;
}

int c[10] = {0,1,2,3,4,5,6,7,8,9};
int mi(int ed){
	vector<int> v;
	for(int i=1;i<=ed;i++){
		v.push_back(c[i]);
	}
	sort(v.begin(),v.end());
	return v[ed/2];
}
int mians(int ed){
	vector<int> v;
	for(int i=1;i<=ed;i++){
		v.push_back(ans[i]);
	}
	sort(v.begin(),v.end());
	return v[ed/2];
}

bool solve(){
	
	sort(a+1,a+m+1,cmp);
	//for(int i=1;i<=m;i++){
	//	printf("a[%lld]=%lld\n",i,a[i]);
	//}
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	int L=1,R=n;
	//ans[1] = a[1];
	//vis[a[1]]=1;
	//if(a[1] == L)L++;
	//if(a[1] == R)R--;
	for(int i=1;i<=m;i++){
		if(a[i] < i || a[i] > n-i+1){
			printf("-1\n");
			return 0;
		}
		if(vis[a[i]]){
			if(a[i] > m){
				while(vis[R])R--;
				ans[i*2-1] = R;
				vis[R]=1;
			}
			else{
				while(vis[L])L++;
				ans[i*2-1] = L;
				vis[L]=1;
			}
		}
		else{
			ans[i*2-1] = a[i];
			vis[a[i]]=1;
		}
		

		if(a[i] > m){
			while(vis[L])L++;
			ans[i*2] = L;
			vis[L]=1;
		}
		else if(a[i] < m){
			while(vis[R])R--;
			ans[i*2] = R;
			vis[R]=1;
		}
		else{
			for(int j=i;j<m;j++){
				while(vis[L])L++;
				while(vis[R])R--;
				ans[j*2] = L;
				ans[j*2+1] = R;
				vis[L]=1;
				vis[R]=1;
			}
			break;
		}

		
	}
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(vis[ans[i]]){
			printf("WA: duplicate");
			for(int i=1;i<=m;i++){
				printf("%lld ",a[i]);
			}
			putchar('\n');
		}
		vis[ans[i]]=1;
		printf("%lld ",ans[i]);
	}
	putchar('\n');
	for(int i=1;i<=m;i++){
		/*if(mians(i*2-1) != a[i]){
			printf("WA: incorrect");
			for(int i=1;i<=m;i++){
				printf("%lld ",a[i]);
			}
			putchar('\n');
		}*/
	}
	
	return 1;
}

signed main(){
	
	int T;cin >> T;for(int i=1;i<=T;i++){
		scanf("%lld",&n);
		m = (n+1)/2;
		for(int i=1;i<=n;i++){
			vis[i]=0;ans[i]=0;
		}
		int j=0;
		for(int i=1;i<=n+m;i++){
			int x;
			scanf("%lld",&x);
			if(!vis[x]){
				vis[x]=1;
				continue;
			}
			a[++j] = x;
			
		}
		/*n = 9;m = 5;
		next_permutation(c+1,c+n+1);
		for(int i=1;i<=n;i++){
			vis[i]=0;ans[i]=0;
			//printf("c[%lld]=%lld\n",i,c[i]);
		}
		for(int i=1;i<=m;i++){
			a[i] = mi(i*2-1);
		}*/
		if(!solve()){
			/*printf("WA: no solution");
			for(int i=1;i<=m;i++){
				printf("%lld ",a[i]);
			}
			putchar('\n');*/
		}
	}
}