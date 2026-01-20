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
const int N=2e6+5;
int T, n, m;
int a[N], b[N];
int mx[N<<2], mn[N<<2];
int ql[N], qr[N], qv[N];
void mdf(int p, int l, int r, int L, int R, int v){
    if(L<=l&&r<=R) {
        mx[p]=max(mx[p], v);
        return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid) mdf(p<<1, l, mid, L, R, v);
    if(R>mid) mdf(p<<1|1, mid+1, r, L, R, v);
}
void build(int p, int l, int r, int v){
    v=max(v, mx[p]);
    if(l==r){
        b[l]=mn[p]=v;
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid, v); build(p<<1|1, mid+1, r, v);
    mn[p]=min(mn[p<<1], mn[p<<1|1]);
}
int get(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R) return mn[p];
    int mid=(l+r)>>1, ret=1e9;
    if(L<=mid) ret=get(p<<1, l, mid, L, R);
    if(R>mid) ret=min(ret, get(p<<1|1, mid+1, r, L, R));
    return ret;
}
unordered_map<int, vector<pii> > h;
ll tr[N<<2];
void upd(int p, int l, int r, int x, ll v){
    tr[p]=min(tr[p], v);
    if(l==r) return ;
    int mid=(l+r)>>1;
    if(x<=mid) upd(p<<1, l, mid, x, v);
    else upd(p<<1|1, mid+1, r, x, v);
}
void st(int p, int l, int r, int x){
    tr[p]=1e18;
    if(l==r) return ;
    int mid=(l+r)>>1;
    if(x<=mid) st(p<<1, l, mid, x);
    else st(p<<1|1, mid+1, r, x);
}
ll qry(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R) return tr[p];
    int mid=(l+r)>>1; ll ret=1e18;
    if(L<=mid) ret=qry(p<<1, l, mid, L, R);
    if(R>mid) ret=min(ret, qry(p<<1|1, mid+1, r, L, R));
    return ret;
}
void solve(){
    read(n); read(m);
    for(int i=1; i<=(n+1)*4; ++i) mx[i]=0, tr[i]=1e18;
    for(int i=1; i<=n; ++i) read(a[i]);
    for(int i=1; i<=m; ++i){
        read(ql[i]); read(qr[i]); read(qv[i]);
        mdf(1, 1, n, ql[i], qr[i], qv[i]);
    }
    build(1, 1, n, 0);
    for(int i=1; i<=m; ++i){
        if(get(1, 1, n, ql[i], qr[i])!=qv[i]){
            printf("-1\n");
            return ;
        }
    }
    ll ans=0;
    h.clear();
    for(int i=1; i<=n; ++i) if(a[i]<b[i]) ans+=b[i]-a[i];
    for(int i=1; i<=n; ++i) h[b[i]].ep(mapa(i, 0));
    for(int i=1; i<=m; ++i) h[qv[i]].ep(mapa(qr[i], i));
    for(auto [val, bin]:h){
        sort(bin.begin(), bin.end());
        int mx=0;
        upd(1, 0, n, 0, 0);
        for(auto t:bin){
            if(t.se==0){
                int cst=max(0, a[t.fi]-val);
                upd(1, 0, n, t.fi, qry(1, 0, n, mx, t.fi)+cst);
            }
            else{
                mx=max(mx, ql[t.se]);
            }
        }
        ans+=qry(1, 0, n, mx, n);
        for(auto t:bin) if(t.se==0){
            st(1, 0, n, t.fi);
        }
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

