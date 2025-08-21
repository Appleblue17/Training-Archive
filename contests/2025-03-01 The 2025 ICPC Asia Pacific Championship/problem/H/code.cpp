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
const int N=105;
int T, n;
// char s[N];
// int f[N], g[N];
bool get(int x){
	cout<<"type "<<x<<endl;
	// return s[x]=='r';
	string s;
	cin>>s;
	return s=="rose";
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		// scanf("%s", s+1);
		// n=strlen(s+1);
		// for(int i=1; i<=n; ++i) f[i]=f[i-1]+(s[i]=='l');
		// g[n]=0;
		// for(int i=n-1; i>=0; --i) g[i]=g[i+1]+(s[i+1]=='r');
		int l=1, r=n, mid, ret=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(get(mid)){
				ret=mid; l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		int v1, v2;
		cout<<"multi "<<ret<<endl;
		// v1=f[ret]*g[ret];
		cin>>v1;
		if(ret!=n){
			cout<<"multi "<<ret+1<<endl;
			// v2=f[ret+1]*g[ret+1];
			cin>>v2;
			if(v1==0&&v2==0){
				if(ret==0){
					cout<<"answer "<<0<<endl;
					// assert(f[0]==g[0]);
					continue;
				}
				else{
					cout<<"multi "<<ret-1<<endl;
					// v2=f[ret-1]*g[ret-1];
					cin>>v2;
					if(v1==0&&v2==0){
						cout<<"answer "<<ret<<endl;
						// assert(f[ret]==g[ret]);
						continue;
					}
					int l0=v2-v1;
					int r1=v1/l0;
					int allr=r1+ret-l0;
					cout<<"answer "<<allr<<endl;
					// assert(f[allr]==g[allr]);
					continue;
				}
			}
			int r1=v2-v1;
			int l0=v1/r1;
			int allr=r1+ret-l0;
			cout<<"answer "<<allr<<endl;
			// assert(f[allr]==g[allr]);
		}
		else{
			cout<<"multi "<<ret-1<<endl;
			// v2=f[ret-1]*g[ret-1];
			cin>>v2;
			if(v1==0&&v2==0){
				cout<<"answer "<<n<<endl;
				// assert(f[n]==g[n]);
				continue;
			}
			int l0=v2-v1;
			int r1=v1/l0;
			int allr=r1+ret-l0;
			cout<<"answer "<<allr<<endl;
			// assert(f[allr]==g[allr]);
		}
	}
	return 0;
}