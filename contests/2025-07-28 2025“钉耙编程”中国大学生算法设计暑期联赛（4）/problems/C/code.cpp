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

const int mod=998244353;
//mod number
inline int plu(int x, int y){x+=y; return x>=mod?x-mod:x;}
inline int sub(int x, int y){x-=y; return x<0?x+mod:x;}
inline int fpow(int x, int y){
    int ret=1;
    while(y){
        if(y&1) ret=1ll*ret*x%mod;
        x=1ll*x*x%mod; y>>=1;
    }
    return ret;
}
inline int getinv(int x){return fpow(x, mod-2);}
int inv[3000000];
inline void init_inv(){
    inv[1]=1;
    for(int i=2; i<3000000; ++i) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
}
//modint
typedef vector<int> poly;
#define len(_) (int)_.size()
#define turn(_, __) _.resize(__)
inline void read(poly &x, int siz){
    turn(x, siz);
    for(int i=0; i<siz; ++i) read(x[i]);
}
inline void print(poly x){
    for(auto p:x) printf("%d ", p);
    putchar('\n');
}
inline void rev(poly &x, int lim){
    poly y=x;
    for(int i=0; i<lim; ++i) x[i]=y[lim-i-1];
}
inline poly plu(int v, poly x){
    x[0]=plu(x[0], v);
    return x;
}
inline poly sub(int v, poly x){
    for(int i=0; i<len(x); ++i) x[i]=mod-x[i];
    x[0]=plu(v, x[0]);
    return x;
}
inline poly mul(poly x, int v){
    for(int i=0; i<len(x); ++i) x[i]=1ll*x[i]*v%mod;
    return x;
}
inline poly plu(poly x, poly y){
    turn(x, max(len(x), len(y)));
    for(int i=0; i<len(x); ++i) x[i]=plu(x[i], y[i]);
    return x;
}
inline poly sub(poly x, poly y){
    turn(x, max(len(x), len(y)));
    for(int i=0; i<len(x); ++i) x[i]=sub(x[i], y[i]);
    return x;
}
inline poly mul(poly x, poly y){
    turn(x, max(len(x), len(y)));
    for(int i=0; i<len(x); ++i) x[i]=1ll*x[i]*y[i]%mod;
    return x;
}
//poly
int rid[3000000];
inline void init_rev(int lim){
    for(int i=0; i<lim; ++i)
    rid[i]=(rid[i>>1]>>1)|((i&1)?lim>>1:0);
}
//reverse id
const int coe=3, icoe=getinv(coe);
//root, inv_of_root
inline void ntt(poly &f, bool sgn, int lim){
    for(int i=0; i<lim; ++i) if(i<rid[i]) swap(f[i], f[rid[i]]);
    for(int p=2; p<=lim; p<<=1){
        int len=p>>1;
        int bs=fpow(sgn?coe:icoe, (mod-1)/p);
        for(int i=0; i<lim; i+=p){
            int w=1;
            for(int j=i; j<i+len; ++j){
                int tem=1ll*w*f[j+len]%mod;
                f[j+len]=sub(f[j], tem);
                f[j]=plu(f[j], tem);
                w=1ll*w*bs%mod;
            }
        }
    }
}
int mxlen=1e8;
inline poly Mul(poly f, poly g){
    int n=len(f), m=len(g), lim=1;
    for(; lim<=n+m-2; lim<<=1);
    init_rev(lim);
    turn(f, lim); turn(g, lim);
    ntt(f, 1, lim); ntt(g, 1, lim);
    f=mul(f, g); ntt(f, 0, lim);
    f=mul(f, getinv(lim));
    turn(f, min(n+m-1, mxlen));
    return f;
}
inline poly Inv(poly f){
    poly g=poly(1, getinv(f[0]));
    for(mxlen=2; mxlen<2*len(f); mxlen<<=1){
        poly h=f; turn(h, mxlen);
        g=Mul(g, sub(2, Mul(g, h)));
    }
    turn(g, len(f));
    return g;
}
inline poly Div(poly f, poly g, int n, int m){
    rev(f, n); rev(g, m); turn(g, n);
    for(int i=n-m+2; i<m; i++) g[i]=0;
    g=Inv(g); f=Mul(f, g);
    rev(f, n-m+1); turn(f, n-m+1);
    return f;
}
inline poly Sqrt(poly f){
    poly g=poly(1, 1);
    for(mxlen=2; mxlen<4*len(f); mxlen<<=1){
        poly h=f; turn(h, mxlen);
        g=Mul(plu(Mul(g, g), h), Inv(mul(g, 2)));
    }
    turn(g, len(f));
    return g;
}
inline poly Der(poly f){
    for(int i=0; i<len(f)-1; ++i) f[i]=(1ll+i)*f[i+1]%mod;
    turn(f, len(f)-1);
    return f;
}
inline poly Int(poly f){
    if(!inv[1]) init_inv();
    turn(f, len(f)+1);
    for(int i=len(f)-1; i; --i) f[i]=1ll*inv[i]*f[i-1]%mod;
    f[0]=0;
    return f;
}
inline poly Ln(poly f){
    poly g=Int(Mul(Der(f), Inv(f))); turn(g, len(f));
    return g;
}
inline poly Exp(poly f){
    poly g=poly(1, 1);
    for(mxlen=2; mxlen<4*len(f); mxlen<<=1){
        poly h=f; turn(h, mxlen);
        g=Mul(g, plu(sub(1, Ln(g)), h));
    }
    turn(g, len(f));
    return g;
}
inline poly Pow(poly f, int k){
    //be sure f_0=1 && k%=mod
    return Exp(mul(Ln(f), k));
}
const int N=1e6+5;
int T, n, m;
int eu[N], ev[N];
vector<pii> e[N];
int sz[N], a[N], b[N], f[N], son[N];
void dfs(int x, int fa){
	sz[x]=1; f[x]=fa; son[x]=0;
	for(auto edg:e[x]){
		int y=edg.fi;
		if(y==fa) continue;
		dfs(y, x);
		int id=edg.se;
		sz[x]+=sz[y];
		if(id>0){
			a[y]=ev[id]; b[y]=eu[id];
		}
		else{
			id=-id;
			a[y]=eu[id]; b[y]=ev[id];
		}
        if(a[y]-(sz[y]-a[y])>=a[son[x]]-(sz[son[x]]-a[son[x]])) son[x]=y;
	}
}
int seq[N], len;
poly calc(int l, int r){
    if(l>r){
        poly ret; ret.push_back(1);
        return ret;
    }
    if(l==r){
        poly ret; ret.push_back(1);
        for(int i=1; i<seq[l]; ++i) ret.push_back(0);
        ret.push_back(1);
        return ret; 
    }
    int all=0, sum=0, mn=n, mid=0;
    for(int i=l; i<=r; ++i) all+=seq[i];
    for(int i=l; i<=r; ++i) {
        sum+=seq[i];
        if(max(sum, all-sum)<=mn){
            mn=max(sum, all-sum); mid=i;
        }
    }
    return Mul(calc(l, mid), calc(mid+1, r));
}
void solve(){
	read(n);
	for(int i=1; i<=n; ++i) e[i].clear();
	for(int i=1, x, y; i<n; ++i){
		read(x); read(y); read(eu[i]); read(ev[i]);
		e[x].ep(y, i);
		e[y].ep(x, -i);
	}
	dfs(1, 0);
	int bs=n;
	for(int i=2; i<=n; ++i) {
		a[i]=max(a[i], sz[i]-a[i]), b[i]=max(b[i], n-sz[i]-b[i]);
		if(a[i]>sz[i]||b[i]>n-sz[i]){
			printf("0\n");
			return ;
		}
		bs=min(bs, a[i]+b[i]);
	}
	if(bs*2<n){
		printf("0\n");
		return ;
	}
	int ret=0;
	if(bs*2>n){
		a[1]=bs;
		bool flag=1;
		for(int i=1; i<=n; ++i){
			if(a[i]+b[i]==bs) continue;
			if(a[i]+n-sz[i]-b[i]==bs) continue;
			if(sz[i]-a[i]+b[i]==bs) {
				a[i]=sz[i]-a[i];
				continue;
			}
			flag=0; break;
		}
		for(int i=1; i<=n; ++i){
			int sum=0;
			for(auto edg:e[i]) {
				int y=edg.fi;
				if(y!=f[i]) sum+=a[y];
			}
			if(sum==a[i]) continue;
			if(sum+1==a[i]) continue;
			flag=0; break;
		}
		if(flag) ret=2;
		for(int i=2; i<=n; ++i) {
			a[i]=max(a[i], sz[i]-a[i]);
		}
	}
    if(n&1){
	    printf("%d\n", ret);
        return ;
    }
    bs=n/2;
    a[1]=bs;
    for(int i=1; i<=n; ++i)if(a[i]+n-sz[i]-b[i]!=bs){
        printf("%d\n", ret);
        return ;
    }
    ll mul=1;
    for(int i=1; i<=n; ++i){
        if(son[i]==0){
            continue;
        }
        int sum=0;
        len=0;
        ll tem=1;
        for(auto edg:e[i]){
            int y=edg.fi;
            if(y!=f[i]&&y!=son[i]) {
                sum+=sz[y]-a[y];
                if(a[y]==sz[y]-a[y]) tem=(tem+tem)%mod;
                else seq[++len]=a[y]-(sz[y]-a[y]);
            }
        }
        sort(seq+1, seq+len+1);
        poly f=calc(1, len);
        int res=0;
        int ask=a[i]-1-sum-a[son[i]];
        if(ask>=0&&ask<(int)f.size()) res=(res+f[ask])%mod;
        ask=a[i]-1-sum-sz[son[i]]+a[son[i]];
        if(ask>=0&&ask<(int)f.size()) res=(res+f[ask])%mod;
        if(a[i]!=sz[i]-a[i]){
            ask=sz[i]-a[i]-1-sum-a[son[i]];
            if(ask>=0&&ask<(int)f.size()) res=(res+f[ask])%mod;   
            ask=sz[i]-a[i]-1-sum-sz[son[i]]+a[son[i]];
            if(ask>=0&&ask<(int)f.size()) res=(res+f[ask])%mod;    
        }
        mul=mul*res%mod*tem%mod;
    }
    printf("%lld\n", (mul*2+ret)%mod);
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