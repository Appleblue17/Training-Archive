#pragma GCC optimize(2)
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
const int N=2e5+5;
const int B=2005;
// const int B=3;
int C[N][55];
int T, n, m, K, mod;
int a[N];
int pos[N], lp[N], rp[N];
int occ[N][55];
ll sum[55][55];
set<pii> vec[N];
int cnt[N];
int rt[N], idx;
void add1(int col, int l, int r){
	int sum=0;
	for(int i=1; i<=pos[n]; ++i){
		int cl=max(lp[i], l), cr=min(rp[i], r);
		sum+=max(0, cr-cl+1);
		occ[col][i]+=sum;
	}
}
void del1(int col, int l, int r){
	int sum=0;
	for(int i=1; i<=pos[n]; ++i){
		int cl=max(lp[i], l), cr=min(rp[i], r);
		sum+=max(0, cr-cl+1);
		occ[col][i]-=sum;
	}
}
void add2(int col){
	for(int i=1; i<=pos[n]; ++i){
		for(int j=i; j<=pos[n]; ++j){
			sum[i][j]+=C[occ[col][j]-occ[col][i-1]][K];
		}
	}
}
void del2(int col){
	for(int i=1; i<=pos[n]; ++i){
		for(int j=i; j<=pos[n]; ++j){
			sum[i][j]-=C[occ[col][j]-occ[col][i-1]][K];
		}
	}
}
void solve(){
	read(n); read(m); read(K); read(mod);
	C[0][0]=1%mod;
	for(int i=1; i<=n; ++i){
		C[i][0]=1%mod;
		for(int j=1; j<=K; ++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	for(int i=1; i<=n; ++i) pos[i]=(i-1)/B+1;
	for(int i=1; i<=pos[n]; ++i) lp[i]=rp[i-1]+1, rp[i]=rp[i-1]+B;
	rp[pos[n]]=n;
	set<pii> st;
	for(int i=1; i<=n+m; ++i) vec[i].clear();
	for(int i=1; i<=n; ++i) read(a[i]), st.insert(mapa(i, i)), vec[a[i]].insert(mapa(i, i));
	for(int i=1; i<=n+m; ++i) rt[i]=i;
	idx=n;
	for(int i=1; i<=pos[n]; ++i){
		for(int j=1; j<=n+m; ++j) occ[j][i]=occ[j][i-1];
		for(int j=lp[i]; j<=rp[i]; ++j) occ[a[j]][i]++;
	}
	for(int i=1; i<=pos[n]; ++i){
		sum[i][i-1]=0;
		for(int j=i; j<=pos[n]; ++j){
			sum[i][j]=sum[i][j-1];
			for(int k=lp[j]; k<=rp[j]; ++k){
				sum[i][j]-=C[cnt[a[k]]][K];
				++cnt[a[k]];
				sum[i][j]+=C[cnt[a[k]]][K];
			}
		}
		for(int j=1; j<=n+m; ++j) cnt[j]=0;
	}
	while(m--){
		int tp;
		read(tp);
		if(tp==1){
			int l, r, c; read(l); read(r); read(c); c=rt[c];
			set<pii>::iterator it=st.upper_bound(mapa(l, n)); --it;
			if((*it).fi<l){
				int tl=(*it).fi, tr=(*it).se;
				a[l]=a[tl];
				vec[a[l]].erase(*it);
				st.erase(it); 
				st.insert(mapa(tl, l-1)); st.insert(mapa(l, tr));
				vec[a[l]].insert(mapa(tl, l-1)); vec[a[l]].insert(mapa(l, tr));
			}
			it=st.upper_bound(mapa(r, n)); --it;
			if((*it).se>r){
				int tl=(*it).fi, tr=(*it).se;
				a[r+1]=a[tl];
				vec[a[r+1]].erase(*it);
				st.erase(it); 
				st.insert(mapa(tl, r)); st.insert(mapa(r+1, tr));
				vec[a[r+1]].insert(mapa(tl, r)); vec[a[r+1]].insert(mapa(r+1, tr));
			}
			it=st.lower_bound(mapa(l, 0)); set<pii>::iterator lit=it;
			while(it!=st.end()){
				if((*it).fi>r) break;
				vec[a[(*it).fi]].erase(*it);
				del2(a[(*it).fi]);
				del1(a[(*it).fi], (*it).fi, (*it).se);
				add2(a[(*it).fi]);
				++it;
			}
			st.erase(lit, it);
			st.insert(mapa(l, r));
			a[l]=c;
			vec[c].insert(mapa(l, r));
			del2(c);
			add1(c, l, r);
			add2(c);
		}
		else if(tp==2){
			int c1, c2; read(c1); read(c2);
			int r1=rt[c1], r2=rt[c2];
			if(r1==r2) {
				rt[c1]=++idx; rt[c2]=r1; 
				continue;
			}
			if(vec[r1].size()<vec[r2].size()) swap(r1, r2);
			del2(r1); del2(r2);
			for(auto t:vec[r2]){
				del1(r2, t.fi, t.se);
				a[t.fi]=r1;
				add1(r1, t.fi, t.se);
				vec[r1].insert(t);
			}
			add2(r1); add2(r2);
			vec[r2].clear();
			rt[c1]=++idx; rt[c2]=r1;  
		}
		else if(tp==3){
			int l, r; read(l); read(r);
			ll ans=sum[pos[l]][pos[r]];
			unordered_map<int, int> h;
			int ml=l, mr=r;
			{
				l=lp[pos[ml]]; r=ml-1;
				if(l<=r){
					set<pii>::iterator it=st.upper_bound(mapa(l, n)); --it;
					if((*it).fi<l){
						int tl=(*it).fi, tr=(*it).se;
						a[l]=a[tl];
						vec[a[l]].erase(*it);
						st.erase(it); 
						st.insert(mapa(tl, l-1)); st.insert(mapa(l, tr));
						vec[a[l]].insert(mapa(tl, l-1)); vec[a[l]].insert(mapa(l, tr));
					}
					it=st.upper_bound(mapa(r, n)); --it;
					if((*it).se>r){
						int tl=(*it).fi, tr=(*it).se;
						a[r+1]=a[tl];
						vec[a[r+1]].erase(*it);
						st.erase(it); 
						st.insert(mapa(tl, r)); st.insert(mapa(r+1, tr));
						vec[a[r+1]].insert(mapa(tl, r)); vec[a[r+1]].insert(mapa(r+1, tr));
					}
					it=st.lower_bound(mapa(l, 0)); 
					while(it!=st.end()){
						if((*it).fi>r) break;
						h[a[(*it).fi]]+=(*it).se-(*it).fi+1;
						++it;
					}
				}
			}
			{
				l=mr+1; r=rp[pos[mr]];
				if(l<=r){
					set<pii>::iterator it=st.upper_bound(mapa(l, n)); --it;
					if((*it).fi<l){
						int tl=(*it).fi, tr=(*it).se;
						a[l]=a[tl];
						vec[a[l]].erase(*it);
						st.erase(it); 
						st.insert(mapa(tl, l-1)); st.insert(mapa(l, tr));
						vec[a[l]].insert(mapa(tl, l-1)); vec[a[l]].insert(mapa(l, tr));
					}
					it=st.upper_bound(mapa(r, n)); --it;
					if((*it).se>r){
						int tl=(*it).fi, tr=(*it).se;
						a[r+1]=a[tl];
						vec[a[r+1]].erase(*it);
						st.erase(it); 
						st.insert(mapa(tl, r)); st.insert(mapa(r+1, tr));
						vec[a[r+1]].insert(mapa(tl, r)); vec[a[r+1]].insert(mapa(r+1, tr));
					}
					it=st.lower_bound(mapa(l, 0)); 
					while(it!=st.end()){
						if((*it).fi>r) break;
						h[a[(*it).fi]]+=(*it).se-(*it).fi+1;
						++it;
					}
				}
			}
			l=ml; r=mr;
			for(auto t:h) ans-=C[occ[t.fi][pos[r]]-occ[t.fi][pos[l]-1]][K], ans+=C[occ[t.fi][pos[r]]-occ[t.fi][pos[l]-1]-t.se][K];
			printf("%lld\n", ans%mod);
		}
	}
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	read(T);
	while(T--){
		solve();
	}
	return 0;
}