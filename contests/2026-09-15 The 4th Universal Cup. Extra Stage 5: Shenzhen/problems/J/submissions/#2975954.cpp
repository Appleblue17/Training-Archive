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
const int N=1e6+5, mod=998244353;
int n, m, q;
struct vec{
	int a[4];
	vec(){memset(a, 0, sizeof a);}
};
struct mat{
	int a[4][4];
	mat(){memset(a, 0, sizeof a);}
	inline bool check(){
		for(int i=0; i<4; ++i){
			for(int j=0; j<4; ++j){
				if(a[i][j]!=(i==j)) return true;
			}
		}
		return false;
	}
}bs;
inline mat operator *(mat x, mat y){
	mat z;
	for(int k=0; k<4; ++k){
		for(int i=0; i<4; ++i) if(x.a[i][k]){
			for(int j=0; j<4; ++j){
				z.a[i][j]=(1ll*x.a[i][k]*y.a[k][j]+z.a[i][j])%mod;
			}
		}
	}
	return z;
}
inline vec operator *(vec x, mat y){
	vec z;
	for(int k=0; k<4; ++k) if(x.a[k]){
		for(int j=0; j<4; ++j){
			z.a[j]=(1ll*x.a[k]*y.a[k][j]+z.a[j])%mod;
		}
	}
	return z;
}
vec operator +(vec x, vec y){
	for(int i=0; i<4; ++i) x.a[i]=(x.a[i]+y.a[i])%mod;
	return x;
}
int a[N], b[N], t[N], f[N], t0;
int ans[N];
int qu[N], qd[N];
vector<int> pls[N], sub[N];
vec tr[N<<2]; mat tag[N<<2];
void apply(int p, mat v){
	tr[p]=tr[p]*v; tag[p]=tag[p]*v;
}
void down(int p){
	if(tag[p].check()){
		apply(p<<1, tag[p]); apply(p<<1|1, tag[p]); 
		tag[p]=bs;
	}
}
void up(int p){
	tr[p]=tr[p<<1]+tr[p<<1|1];
}
void clr(int p, int l, int r){
	tag[p]=bs;
	if(l==r) {
		tr[p].a[0]=b[l]%mod;
		tr[p].a[1]=1;
		tr[p].a[2]=0;
		tr[p].a[3]=0;
		return ;
	}
	int mid=(l+r)>>1;
	clr(p<<1, l, mid); clr(p<<1|1, mid+1, r);
	up(p);
}
vec get(int p, int l, int r, int L, int R){
	if(L<=l&&r<=R) return tr[p];
	int mid=(l+r)>>1; 
	down(p);
	if(L>mid) return get(p<<1|1, mid+1, r, L, R);
	if(R<=mid) return get(p<<1, l, mid, L, R);
	return get(p<<1, l, mid, L, R)+get(p<<1|1, mid+1, r, L, R);
}
void mdf(int p, int l, int r, int L, int R, mat v){
	if(L<=l&&r<=R){
		apply(p, v);
		return ;
	}
	int mid=(l+r)>>1;
	down(p);
	if(L<=mid) mdf(p<<1, l, mid, L, R, v);
	if(R>mid) mdf(p<<1|1, mid+1, r, L, R, v);
	up(p);
}
int stk[N], top;
ll ax[N], ay[N];
bool cross(int i, int j, int k){
	ll x=ax[j]-ax[i], y=ay[j]-ay[i];
	ll xx=ax[k]-ax[j], yy=ay[k]-ay[j];
	return (__int128)x*yy>=(__int128)y*xx;
}
void solve(){
	read(n); read(m); read(q);
	for(int i=1; i<=n; ++i) read(a[i]);
	for(int i=1; i<=m; ++i) read(b[i]);
	for(int i=1; i<=n; ++i) read(t[i]);
	f[1]=t[1];
	for(int i=2; i<=n; ++i) f[i]=min(f[i-1], t[i]);
	read(t0);
	for(int i=1; i<=n; ++i) pls[i].clear(), sub[i].clear();
	for(int i=1, l, r; i<=q; ++i){
		read(l); read(r); read(qu[i]); read(qd[i]);
		pls[l].ep(i); if(r!=n) sub[r+1].ep(i);
		ans[i]=0;
	}
	clr(1, 1, m);
	top=0;
	for(int i=n; i>=1; --i){
		ax[i]=-t[i]; ay[i]=2ll*t0*a[i]; 
		while(top>1&&cross(stk[top-1], stk[top], i)){
			--top;
		}
		while(top&&ax[stk[top]]<=ax[i]) --top;
		stk[++top]=i;
		// for(int j=1; j<=top; ++j) cout<<ax[stk[j]]<<' '<<ay[stk[j]]<<endl;
		// cout<<"-------------"<<endl;
		if(top==1){
			mat cur;
			cur.a[0][0]=cur.a[1][1]=1; cur.a[3][3]=1;
			cur.a[0][2]=t[i]%mod; cur.a[1][2]=2ll*t0*a[i]%mod;
			mdf(1, 1, m, 1, m, cur);
		}
		else{
			int l=1, r=m, mid, ret=0;
			while(l<=r){
				mid=(l+r)>>1;
				if((ax[stk[top-1]]-ax[stk[top]])*b[mid]<=(ay[stk[top-1]]-ay[stk[top]])){
					ret=mid; l=mid+1;
				}
				else{
					r=mid-1;
				}
			}
			// cout<<"ret:"<<ret<<endl;
			if(ret!=0){
				mat cur;
				cur.a[0][0]=1; cur.a[1][1]=1; cur.a[3][3]=1;
				cur.a[0][2]=t[i]%mod; cur.a[1][2]=2ll*t0*a[i]%mod;
				mdf(1, 1, m, 1, ret, cur);
			}
		}
		{
			int l=1, r=top, mid, ret=top+1;
			// if(i==8){
			// 	cout<<"b, val1, val2="<<"inf "<<f[i]<<' '<<t[stk[1]]<<endl;
			// 	for(int j=2; j<=top; ++j){
			// 		int mid=j;
			// 		ll b=(ay[stk[mid-1]]-ay[stk[mid]])/(ax[stk[mid-1]]-ax[stk[mid]]);
			// 		cout<<ay[stk[mid-1]]<<' '<<ay[stk[mid]]<<' '<<ax[stk[mid-1]]<<' '<<ax[stk[mid]]<<endl;
			// 		ll val1=2ll*t0*a[i]+b*f[i];
			// 		ll val2=2ll*t0*a[stk[mid]]+b*t[stk[mid]];
			// 		cout<<"b, val1, val2="<<b<<' '<<val1<<' '<<val2<<endl;
			// 		// cout<<"stk:"<<stk[mid]<<endl;
			// 	}
			// 	cout<<"finish"<<endl;
			// }
			while(l<=r){
				mid=(l+r)>>1;
				ll val1, val2;
				if(mid==1){
					val1=f[i]; val2=t[stk[mid]];
				}
				else{
					ll b=min((ay[stk[mid-1]]-ay[stk[mid]])/(ax[stk[mid-1]]-ax[stk[mid]]), (ll)1e9);
					val1=2ll*t0*a[i]+b*f[i];
					val2=2ll*t0*a[stk[mid]]+b*t[stk[mid]];
				}
				// cout<<"mid, val1, val2="<<mid<<' '<<val1<<' '<<val2<<endl;
				if(val1<=val2){
					ret=mid;
					r=mid-1;
				}
				else{
					l=mid+1;
				}
			}
			// cout<<"fnd:"<<ret<<endl;
			// cout<<"top:"<<top<<endl;
			if(ret==1){
				ret=m;
			}
			if(ret==top+1){
				ret=0;
			}
			else{
				int lstret=ret-1;
				l=1, r=m, ret=0;
				// if(i==8) cout<<ay[stk[lstret-1]]<<' '<<ay[stk[lstret]]<<' '<<ax[stk[lstret-1]]<<' '<<ax[stk[lstret]]<<endl;
				while(l<=r){
					mid=(l+r)>>1;
					if(lstret-1!=0&&(ax[stk[lstret-1]]-ax[stk[lstret]])*b[mid]>(ay[stk[lstret-1]]-ay[stk[lstret]])){
						// if(i==8) cout<<mid<<endl;
						r=mid-1;
						continue;
					}
					if((ax[stk[lstret]]-ax[stk[lstret+1]])*b[mid]<=(ay[stk[lstret]]-ay[stk[lstret+1]])){
						ret=mid; l=mid+1;
						continue;
					}
					ll val1=2ll*t0*a[i]+1ll*b[mid]*f[i];
					ll val2=2ll*t0*a[stk[lstret]]+1ll*b[mid]*t[stk[lstret]];
					// cout<<"mid, val1, val2="<<mid<<' '<<val1<<' '<<val2<<endl;
					if(val1<=val2){
						ret=mid; l=mid+1;
					}
					else{
						r=mid-1;
					}
				}
			}
			// if(i==8){
			// 	cout<<ret<<endl;
			// 	// ret=2;
			// }
			if(ret!=0){
				mat cur;
				cur.a[0][0]=cur.a[1][1]=1; cur.a[2][2]=1; cur.a[3][3]=1;
				cur.a[0][3]=f[i]%mod; cur.a[1][3]=1ll*t0*a[i]%mod; 
				mdf(1, 1, m, 1, ret, cur);
			}
			if(ret!=m){
				mat cur;
				cur.a[0][0]=cur.a[1][1]=1; cur.a[2][2]=1; cur.a[3][3]=1;
				cur.a[1][3]=(mod-1ll*t0*a[i]%mod)%mod; cur.a[2][3]=1;
				mdf(1, 1, m, ret+1, m, cur);
			}
		}
		for(auto t:pls[i]){
			vec res=get(1, 1, m, qu[t], qd[t]);
			ans[t]=(ans[t]+res.a[3])%mod;
		}
		for(auto t:sub[i]){
			vec res=get(1, 1, m, qu[t], qd[t]);
			ans[t]=(ans[t]+mod-res.a[3])%mod;
		}
	}
	for(int i=1; i<=q; ++i){
		printf("%d ", ans[i]);
	}
	putchar('\n');
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	bs.a[0][0]=bs.a[1][1]=bs.a[2][2]=bs.a[3][3]=1;
	int T; read(T);
	while(T--){
		solve();
	}
	return 0;
}
