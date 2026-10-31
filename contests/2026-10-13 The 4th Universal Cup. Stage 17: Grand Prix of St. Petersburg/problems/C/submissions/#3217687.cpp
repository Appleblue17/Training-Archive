// #pragma GCC optimize(2)
// #pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("-falign-jumps")
// #pragma GCC optimize("-falign-loops")
// #pragma GCC optimize("-falign-labels")
// #pragma GCC optimize("-fdevirtualize")
// #pragma GCC optimize("-fcaller-saves")
// #pragma GCC optimize("-fcrossjumping")
// #pragma GCC optimize("-fthread-jumps")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-fwhole-program")
// #pragma GCC optimize("-freorder-blocks")
// #pragma GCC optimize("-fschedule-insns")
// #pragma GCC optimize("inline-functions")
// #pragma GCC optimize("-ftree-tail-merge")
// #pragma GCC optimize("-fschedule-insns2")
// #pragma GCC optimize("-fstrict-aliasing")
// #pragma GCC optimize("-fstrict-overflow")
// #pragma GCC optimize("-falign-functions")
// #pragma GCC optimize("-fcse-skip-blocks")
// #pragma GCC optimize("-fcse-follow-jumps")
// #pragma GCC optimize("-fsched-interblock")
// #pragma GCC optimize("-fpartial-inlining")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("-freorder-functions")
// #pragma GCC optimize("-findirect-inlining")
// #pragma GCC optimize("-frerun-cse-after-loop")
// #pragma GCC optimize("inline-small-functions")
// #pragma GCC optimize("-finline-small-functions")
// #pragma GCC optimize("-ftree-switch-conversion")
// #pragma GCC optimize("-foptimize-sibling-calls")
// #pragma GCC optimize("-fexpensive-optimizations")
// #pragma GCC optimize("-funsafe-loop-optimizations")
// #pragma GCC optimize("inline-functions-called-once")
// #pragma GCC optimize("-fdelete-null-pointer-checks")
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

inline ll C3(ll len){
	return len*(len-1)*(len-2)/6;
}
char s[N], c[2];
struct info{
	ll sum[26], cnt[26], ans;
	
}tr[N<<2];
info operator +(const info &x, const info &y){
	info ret; ll presum=0, precnt=0;
	ret.ans=x.ans+y.ans;
	for(int i=0; i<26; i+=4){
		precnt+=x.cnt[i]; presum+=x.sum[i];
		ret.cnt[i]=x.cnt[i]+y.cnt[i];
		ret.sum[i]=x.sum[i]+y.sum[i];
		ret.sum[i]+=precnt*y.cnt[i];
		ret.ans+=precnt*(precnt-1)/2*y.cnt[i];
		ret.ans+=precnt*y.sum[i];
		
		precnt+=x.cnt[i+1]; presum+=x.sum[i+1];
		ret.cnt[i+1]=x.cnt[i+1]+y.cnt[i+1];
		ret.sum[i+1]=x.sum[i+1]+y.sum[i+1];
		ret.sum[i+1]+=precnt*y.cnt[i+1];
		ret.ans+=precnt*(precnt-1)/2*y.cnt[i+1];
		ret.ans+=precnt*y.sum[i+1];
		
		if(i==24) break;
		
		precnt+=x.cnt[i+2]; presum+=x.sum[i+2];
		ret.cnt[i+2]=x.cnt[i+2]+y.cnt[i+2];
		ret.sum[i+2]=x.sum[i+2]+y.sum[i+2];
		ret.sum[i+2]+=precnt*y.cnt[i+2];
		ret.ans+=precnt*(precnt-1)/2*y.cnt[i+2];
		ret.ans+=precnt*y.sum[i+2];
		
		precnt+=x.cnt[i+3]; presum+=x.sum[i+3];
		ret.cnt[i+3]=x.cnt[i+3]+y.cnt[i+3];
		ret.sum[i+3]=x.sum[i+3]+y.sum[i+3];
		ret.sum[i+3]+=precnt*y.cnt[i+3];
		ret.ans+=precnt*(precnt-1)/2*y.cnt[i+3];
		ret.ans+=precnt*y.sum[i+3];
	}
	return ret;
}
void work(info &x, info &y, info &ret){
	ll presum=0, precnt=0;
	ret.ans=x.ans+y.ans;
	for(int i=0; i<26; i+=4){
		precnt+=x.cnt[i]; presum+=x.sum[i];
		ret.cnt[i]=x.cnt[i]+y.cnt[i];
		ret.sum[i]=x.sum[i]+y.sum[i];
		ret.sum[i]+=precnt*y.cnt[i];
		ret.ans+=precnt*(precnt-1)/2*y.cnt[i];
		ret.ans+=precnt*y.sum[i];
		
		precnt+=x.cnt[i+1]; presum+=x.sum[i+1];
		ret.cnt[i+1]=x.cnt[i+1]+y.cnt[i+1];
		ret.sum[i+1]=x.sum[i+1]+y.sum[i+1];
		ret.sum[i+1]+=precnt*y.cnt[i+1];
		ret.ans+=precnt*(precnt-1)/2*y.cnt[i+1];
		ret.ans+=precnt*y.sum[i+1];
		
		if(i==24) break;
		
		precnt+=x.cnt[i+2]; presum+=x.sum[i+2];
		ret.cnt[i+2]=x.cnt[i+2]+y.cnt[i+2];
		ret.sum[i+2]=x.sum[i+2]+y.sum[i+2];
		ret.sum[i+2]+=precnt*y.cnt[i+2];
		ret.ans+=precnt*(precnt-1)/2*y.cnt[i+2];
		ret.ans+=precnt*y.sum[i+2];
		
		precnt+=x.cnt[i+3]; presum+=x.sum[i+3];
		ret.cnt[i+3]=x.cnt[i+3]+y.cnt[i+3];
		ret.sum[i+3]=x.sum[i+3]+y.sum[i+3];
		ret.sum[i+3]+=precnt*y.cnt[i+3];
		ret.ans+=precnt*(precnt-1)/2*y.cnt[i+3];
		ret.ans+=precnt*y.sum[i+3];
	}
}
int tag[N<<2], len[N<<2];
vector<int> tagbin[N<<2];
void apply(int p, vector<int> c){
	ll tem=0;
	for(int i=0; i<26; ++i) {
		tr[p].cnt[i]=c[i]; 
		tr[p].sum[i]=tem*(tem+1)/2;
		tem+=c[i]; 
		tr[p].sum[i]=tem*(tem+1)/2-tr[p].sum[i];
	}
	assert(tem==len[p]);
	tr[p].ans=C3(len[p]+1);
	tag[p]=1; tagbin[p]=c;
}
void down(int p){
	if(tag[p]){
		vector<int> tagl(26, 0); 
		int res=len[p<<1];
		for(int i=0; i<26; ++i){
			if(tagbin[p][i]<res){
				tagl[i]=tagbin[p][i]; tagbin[p][i]=0;
				res-=tagl[i];
			}
			else{
				tagl[i]=res;
				tagbin[p][i]-=res;
				break;
			}
		}
		apply(p<<1, tagl);
		apply(p<<1|1, tagbin[p]);
		tag[p]=0;
	}
}
void build(int p, int l, int r){
	len[p]=r-l+1; tag[p]=0; tagbin[p]=vector<int>(26, 0);
	if(l==r){
		vector<int> tg(26, 0); tg[s[l]-'A']=1;
		apply(p, tg);
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
vector<int> bin;
void mdf(int p, int l, int r, int L, int R){
	if(L<=l&&r<=R){
		vector<int> cur(26, 0);
		int res=len[p];
		for(int i=0; i<26; ++i){
			if(bin[i]<res){
				cur[i]=bin[i]; bin[i]=0;
				res-=cur[i];
			}
			else{
				cur[i]=res;
				bin[i]-=res;
				break;
			}
		}
		apply(p, cur);
		return ;
	}
	int mid=(l+r)>>1;
	down(p);
	if(L<=mid) mdf(p<<1, l, mid, L, R);
	if(R>mid) mdf(p<<1|1, mid+1, r, L, R);
	work(tr[p<<1], tr[p<<1|1], tr[p]);
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
			bin=vector<int>(26, 0); bin[c[1]-'A']=1;
			mdf(1, 1, n, l, l);
		}
		else {
			read(r);
			info cur=get(1, 1, n, l, r);
			printf("%lld\n", C3(r-l+2)-cur.ans);
			if(op==3){
				for(int i=0; i<26; ++i) bin[i]=cur.cnt[i];
				mdf(1, 1, n, l, r);
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
