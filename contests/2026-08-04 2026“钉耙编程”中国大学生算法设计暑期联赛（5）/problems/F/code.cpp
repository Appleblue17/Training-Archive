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
int T, n1, n2, n3;
char a[N], b[N], c[N];
int p[N], z[N];
void Z(char *s, int n){
	for(int i=1; i<=n; ++i) z[i]=0;
	z[1]=n;
	for(int i=2, l=0, r=0; i<=n; ++i){
		if(i<=r) z[i]=min(z[i-l+1], r-i+1);
		while(i+z[i]<=n&&s[i+z[i]]==s[z[i]+1]) ++z[i];
		if(i+z[i]-1>r) l=i, r=i+z[i]-1;
	}
}
void exkmp(char *s, int n, char *t, int m){
	for(int i=1; i<=n; ++i) p[i]=0;
	for(int i=1, l=0, r=0; i<=n; ++i){
		if(i<=r) p[i]=min(z[i-l+1], r-i+1);
		while(i+p[i]<=n&&s[i+p[i]]==t[p[i]+1]) ++p[i];
		if(i+p[i]-1>r) l=i, r=i+p[i]-1;
	}
}
int cnt[N];
vector<int> bin[N];
int pre[N], nxt[N];
int tr1[N], tr2[N];
void add(int x, int v1, int v2){
	for(; x<=n1; x+=(x&-x)) tr1[x]+=v1, tr2[x]+=v2;
}
int get1(int x){
	int ret=0;
	for(; x; x-=(x&-x)) ret+=tr1[x];
	return ret;
}
int get2(int x){
	int ret=0;
	for(; x; x-=(x&-x)) ret+=tr2[x];
	return ret;
}
void solve(){
	read(n1); read(n2); read(n3);
	scanf("%s", a+1);
	scanf("%s", b+1);
	scanf("%s", c+1);
	Z(a, n1);
	exkmp(c, n3, a, n1);
	for(int i=1; i<=n1; ++i) cnt[i]=0;
	for(int i=1; i<=n3; ++i) cnt[p[i]]++;
	for(int i=n1-1; i>=1; --i) cnt[i]+=cnt[i+1];
	exkmp(b, n2, a, n1);
	for(int i=0; i<=n1; ++i) bin[i].clear(), tr1[i]=tr2[i]=0;
	for(int i=1; i<=n2; ++i) bin[p[i]].ep(i);
	for(int i=1; i<=n2; ++i) pre[i]=i-1, nxt[i]=i+1, add(1, 1, 1);
	nxt[0]=1; pre[n2+1]=n2;
	ll ans=0;
	int tot=n2;
	for(int w=1; w<=n1; ++w){
		for(auto t:bin[w-1]){
			int l=pre[t], r=nxt[t];
			if(l!=0) add(t-l, -1, -(t-l));
			add(r-t, -1, -(r-t));
			nxt[l]=r; pre[r]=l;
			if(l!=0) add(r-l, 1, r-l);
			--tot;
		}
		int len=get2(w)+w*(tot-get1(w));
		ans+=1ll*len*cnt[w];
	}
	printf("%lld\n", ans);
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