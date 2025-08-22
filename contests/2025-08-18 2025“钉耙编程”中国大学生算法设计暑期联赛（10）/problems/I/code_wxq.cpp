#pragma GCC optimize(2)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
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
const int N=2e5+5;
int T, n, m, q;
char s[N];
using namespace __gnu_pbds;
gp_hash_table<ull, int> h[40];
int idx;
int nxt[40];
vector<int> pos[N*37];
int len[N*37];
ll ans[N];
int ql[N], qr[N];
int sum[N];
inline ll calc2(int x){
	return 1ll*x*(x-1)/2ll;
}
vector<int> add[N], ask[N];
int blk[N], cnt[N];
int bid[N], lp[N], rp[N];
void solve(){
	read(n); read(m); read(q);
	scanf("%s", s+1);
	if(m==1){
		int l, r;
		while(q--){
			read(l); read(r);
			printf("%lld\n", 1ll*(r-l)*(r-l+1)/2ll);
		}
		return ;
	}
	for(int i=1; i<=n; ++i){
		bid[i]=i>>9;
		cnt[i]=0;
		vector<int> ().swap(add[i]);
		vector<int> ().swap(ask[i]);
	}
	for(int i=1; i<=q; ++i) {
		read(ql[i]), read(qr[i]); 
		ans[i]=0; ask[qr[i]].ep(i);
	}
	rp[0]=(1<<9)-1; blk[0]=0;
	for(int i=1; i<=bid[n]; ++i){
		lp[i]=rp[i-1]+1;
		rp[i]=rp[i-1]+(1<<9);
		blk[i]=0;
	}
	rp[bid[n]]=n;
	for(int i=1; i<=idx; ++i) vector<int> ().swap(pos[i]);
	idx=0;
	for(int l=1; l<=n; ++l){
		ull cur=s[l];
		if(h[0].find(cur)==h[0].end()) h[0][cur]=++idx, len[idx]=1;
		pos[h[0][cur]].ep(l);
		nxt[1]=0;
		int it=0;
		for(int j=1; j<37&&l+j<=n; ++j){
			cur=cur*131+s[l+j];
			while(it!=0&&s[l+it]!=s[l+j]) it=nxt[it];
			if(s[l+it]==s[l+j]) ++it;
			nxt[j+1]=it;
			if(it==0){
				if(h[j].find(cur)==h[j].end()) h[j][cur]=++idx, len[idx]=j+1;
				pos[h[j][cur]].ep(l);
			}
		}
	}
	for(int i=0; i<37; ++i) gp_hash_table<ull, int> ().swap(h[i]); 
	vector<int> vec;
	for(int i=1; i<=idx; ++i) if(pos[i].size()!=1) vec.ep(i);
	sort(vec.begin(), vec.end(), [&](int x, int y){return pos[x].size()>pos[y].size();});
	int lim=min(500, (int)vec.size());
	for(int i=0; i<lim; ++i){
		for(auto t:pos[vec[i]]){
			++sum[t];
		}
		for(int j=2; j<=n; ++j) sum[j]+=sum[j-1];
		for(int j=1; j<=q; ++j){
			if(qr[j]-ql[j]+1<len[vec[i]]) continue;
			ans[j]+=calc2(sum[qr[j]-len[vec[i]]+1]-sum[ql[j]-1]);
		}
		for(int j=1; j<=n; ++j) sum[j]=0;
	}
	for(int i=lim, c; i<(int)vec.size(); ++i){
		c=vec[i];
		for(auto t:pos[c]) add[t+len[c]-1].ep(c);
	}
	int cl, cr;
	for(int i=1; i<=n; ++i){
		for(auto t:add[i]){
			for(int j=0; j<(int)pos[t].size(); ++j){
				if(pos[t][j]+len[t]>=i) break;
				++cnt[pos[t][j]];
				++blk[pos[t][j]>>9];
			}
		}
		for(auto t:ask[i]){
			cl=ql[t]; cr=qr[t];
			if((cl>>9)==(cr>>9)){
				for(int j=cl; j<=cr; ++j) ans[t]+=cnt[j];
				continue;
			}
			for(int j=cl; j<=rp[(cl>>9)]; ++j) ans[t]+=cnt[j];
			for(int j=lp[(cr>>9)]; j<=cr; ++j) ans[t]+=cnt[j];
			for(int j=(cl>>9)+1; j<(cr>>9); ++j) ans[t]+=blk[j];
		}
	}
	ll output=0;
	for(int i=1; i<=q; ++i) output^=ans[i]*i;
	printf("%lld\n", output);
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
