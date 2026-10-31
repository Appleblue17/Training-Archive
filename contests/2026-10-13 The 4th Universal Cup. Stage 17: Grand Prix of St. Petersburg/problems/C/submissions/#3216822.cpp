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
const int N=3e5+5;
int T, n, m;

ll C3(ll len){
	return len*(len-1)*(len-2)/6;
}
char s[N], c[2];
struct info{
	ll sum[26], cnt[26], ans;
	friend info operator +(info x, info y){
		info ret; ll presum=0, precnt=0;
		ret.ans=x.ans+y.ans;
		for(int i=0; i<26; ++i){
			precnt+=x.cnt[i]; presum+=x.sum[i];
			ret.cnt[i]=x.cnt[i]+y.cnt[i];
			ret.sum[i]=x.sum[i]+y.sum[i];
			ret.sum[i]+=precnt*y.cnt[i];
			ret.ans+=precnt*(precnt-1)/2*y.cnt[i];
			ret.ans+=precnt*y.sum[i];
		}
		return ret;
	}
}tr[N<<2];
int tag[N<<2], len[N<<2];
void apply(int p, int c){
	for(int i=0; i<26; ++i) tr[p].cnt[i]=tr[p].sum[i]=0;
	tr[p].ans=C3(len[p]+1);
	tr[p].cnt[c]=len[p];
	tr[p].sum[c]=1ll*len[p]*(len[p]+1)/2ll;
	tag[p]=c;
}
void down(int p){
	if(tag[p]!=-1){
		apply(p<<1, tag[p]);
		apply(p<<1|1, tag[p]);
		tag[p]=-1;
	}
}
void build(int p, int l, int r){
	len[p]=r-l+1; tag[p]=-1;
	if(l==r){
		apply(p, s[l]-'A');
		return ;
	}
	int mid=(l+r)>>1;
	build(p<<1, l, mid); build(p<<1|1, mid+1, r);
	tr[p]=tr[p<<1]+tr[p<<1|1];
}
info get(int p, int l, int r, int L, int R){
	if(L<=l&&r<=R){
		return tr[p];
	}
	int mid=(l+r)>>1;
	down(p);
	if(L<=mid&&R>mid) return get(p<<1, l, mid, L, R)+get(p<<1|1, mid+1, r, L, R);
	if(L<=mid) return get(p<<1, l, mid, L, R);
	return get(p<<1|1, mid+1, r, L, R);
}
void mdf(int p, int l, int r, int L, int R, int c){
	if(L<=l&&r<=R){
		apply(p, c);
		return ;
	}
	int mid=(l+r)>>1;
	down(p);
	if(L<=mid) mdf(p<<1, l, mid, L, R, c);
	if(R>mid) mdf(p<<1|1, mid+1, r, L, R, c);
	tr[p]=tr[p<<1]+tr[p<<1|1];
	// cout<<"???"<<l<<' '<<r<<' '<<tr[p].ans<<endl;
}
void solve(){
	read(n); read(m);
	scanf("%s", s+1);
	
	build(1, 1, n);
	int op, l, r;
	while(m--){
		read(op); read(l);
		if(op==1){
			scanf("%s", c+1);
			mdf(1, 1, n, l, l, c[1]-'A');
		}
		else {
			read(r);
			info cur=get(1, 1, n, l, r);
			printf("%lld\n", C3(r-l+2)-cur.ans);
			if(op==3){
				for(int i=0; i<26; ++i){
					if(cur.cnt[i]) mdf(1, 1, n, l, l+cur.cnt[i]-1, i);
					// while(cur.cnt[i]) mdf(1, 1, n, l, l, i), ++l, --cur.cnt[i];
					l+=cur.cnt[i];
				}
				// cout<<"???"<<tr[1].ans<<endl;
				// exit(0);
			}
		}
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
