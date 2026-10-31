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
const int N=1e6+5, mod=998244353;
const int inf=(1<<30)-1;
int T, n, m;
int a[N];
struct node{
	int v1, v2, v3, id;
};
int lowbit(int x){
	return x&-x;
}
void solve(){
	read(n);
	for(int i=1; i<=n; ++i){
		read(a[i]);
	}
	vector<node> bin;
	bin.ep((node){a[1], a[1]^inf, inf, 1});
	ll ans=0;
	for(int i=2; i<=n; ++i){
		vector<node> nbin;
		for(auto t:bin){
			int nv1=t.v1&a[i], nv2=t.v2&(inf^a[i]), nv3=nv1|nv2;
			if(!nbin.empty()&&nbin.back().v3==nv3){
				continue;
			}
			nbin.push_back((node){nv1, nv2, nv3, t.id});
		}
		{
			int nv1=a[i], nv2(inf^a[i]), nv3=nv1|nv2;
			if(!nbin.empty()&&nbin.back().v3==nv3){
				continue;
			}
			nbin.push_back((node){nv1, nv2, nv3, i});
		}
		for(int j=0; j<(int)nbin.size(); ++j){
			node t=nbin[j];
			// cout<<t.v1<<' '<<t.v2<<' '<<lowbit(t.v3)<<endl;
			if(t.v3==inf) continue;
			int op=__lg(lowbit(t.v3+1));
			++op;
			int nxt=nbin[j+1].id;
			ans=(ans+1ll*(nxt-t.id)*op%mod*op)%mod;
			// cout<<"ans:"<<op<<' '<<t.id<<' '<<nxt-1<<endl;
		}
		// cout<<"---------------------"<<endl;
		if(!((a[i]^a[i-1])&1)){
			int nv1=a[i-1]&a[i], nv2=(inf^a[i-1])&(inf^a[i]), nv3=nv1|nv2;
			int op=(int)(__lg(lowbit(nv3+1)))+1;
			ans=(ans+mod-1ll*op*op%mod)%mod;
		}
		// cout<<ans<<endl;
		bin.swap(nbin);
	}
	printf("%lld\n", ans);
	// exit(0);
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
