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
char s[N];
int pre[N];
int rt[N], idx, ls[N*40], rs[N*40], sz[N*40];
ll sum[N*40];
void add(int &p, int q, int l, int r, int x){
	p=++idx;
	ls[p]=ls[q]; rs[p]=rs[q]; sz[p]=sz[q]+1; sum[p]=sum[q]+x;
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(x<=mid) add(ls[p], ls[q], l, mid, x);
	else add(rs[p], rs[q], mid+1, r, x);
}
ll getsum(int p, int q, int l, int r, int k){
	if(l==r){
		return 1ll*k*l-1ll*(sz[q]-sz[p]-k)*l;
	}
	int mid=(l+r)>>1; 
	if(sz[rs[q]]-sz[rs[p]]>=k){
		return getsum(rs[p], rs[q], mid+1, r, k)-(sum[ls[q]]-sum[ls[p]]);
	}
	else{
		return getsum(ls[p], ls[q], l, mid, k-(sz[rs[q]]-sz[rs[p]]))+(sum[rs[q]]-sum[rs[p]]);
	}
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	read(n); read(m);
	scanf("%s", s+1);
	for(int i=1; i<=n; ++i){
		pre[i]=pre[i-1]+(s[i]=='1'?1:-1);
		add(rt[i], rt[i-1], -n, n, pre[i]);
	}
	int l, r;
	while(m--){
		read(l); read(r);
		printf("%lld\n", getsum(rt[l-1], rt[r], -n, n, (r-l+1)>>1));
	}
	return 0;
}

