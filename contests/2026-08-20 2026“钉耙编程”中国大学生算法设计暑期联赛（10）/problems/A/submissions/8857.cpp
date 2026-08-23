#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
const int N=3e5+50;
int T, n, m;
struct SA{
	char s[N];
    int buc[N], rk[N], sa[N], od[N], id[N], ht[21][N], w, p;
    bool eq(int x, int y) {
        return od[x] == od[y] && od[x + w] == od[y + w];
    }
    void getSA() {
		int m=26;
        for(int i=0; i<=26; ++i) buc[i]=0;
        for (int i = 1; i <= n; ++i)
            ++buc[rk[i] = s[i]];
        for (int i = 1; i <= m; ++i)
            buc[i] += buc[i - 1];
        for (int i = n; i; --i)
            sa[buc[rk[i]]--] = i;
        for (int i = 1; i <= m; ++i)
            buc[i] = 0;
        w = 1;
        p = 0;
        while (true) {
            for (int i = n; i > n - w; --i)
                id[++p] = i;
            for (int i = 1; i <= n; ++i)
                if (sa[i] > w)
                    id[++p] = sa[i] - w;
            for (int i = 1; i <= n; ++i)
                ++buc[od[i] = rk[i]];
            for (int i = 1; i <= m; ++i)
                buc[i] += buc[i - 1];
            for (int i = n; i; --i)
                sa[buc[rk[id[i]]]--] = id[i];
            for (int i = 1; i <= m; ++i)
                buc[i] = 0;
            rk[sa[1]] = p = 1;
            for (int i = 2; i <= n; ++i) {
                if (!eq(sa[i], sa[i - 1]))
                    ++p;
                rk[sa[i]] = p;
            }
            if (p == n)
                break;
            w <<= 1, m = p, p = 0;
        }
    }
    void build() {
        s[n + 1] = '!';
        for (int i = 1, k = 0; i <= n; ++i) {
            if (k)
                --k;
            if (rk[i] == 1)
                continue;
            while (s[i + k] == s[sa[rk[i] - 1] + k])
                ++k;
            ht[0][rk[i]] = k;
        }
        for (int t = 1; t < 21; ++t)
            for (int i = 2; i + (1 << t) - 1 <= n; ++i)
                ht[t][i] = min(ht[t - 1][i], ht[t - 1][i + (1 << (t - 1))]);
    }
    int qry(int x, int y) {
		if(y>n) return 0;
        if (x == y)
            return n - x + 1;
        x = rk[x], y = rk[y];
        if (x > y)
            swap(x, y);
        int k = __lg(y - x);
        return min(ht[k][x + 1], ht[k][y - (1 << k) + 1]);
    }
}A, B;
char s[N];
int stk[N], top;
vector<pii> bin[N];
void work(int l, int r){
	int len=r-l+1;
	int la=A.qry(l, r+1);
	int lb=B.qry(n-r+1, n-l+2);
	if(lb<len&&la+lb>=len){
        l-=lb; r+=la;
        if(r==n) --r;
        for(int p=len*2; l+p-1<=r; p+=2*len){
            bin[p/2].ep(l, r-p+1);
        }
	}
}
int tr[N<<2], sz[N<<2], tag[N<<2];
void apply(int p, int v){
    tr[p]+=v; tag[p]+=v;
}
void down(int p){
    if(tag[p]) apply(p<<1, tag[p]), apply(p<<1|1, tag[p]), tag[p]=0;
}
void up(int p){
    tr[p]=max(tr[p<<1], tr[p<<1|1]);
    sz[p]=0;
    if(tr[p]==tr[p<<1]) sz[p]+=sz[p<<1];
    if(tr[p]==tr[p<<1|1]) sz[p]+=sz[p<<1|1];
}
void build(int p, int l, int r){
    tr[p]=0; sz[p]=r-l+1;
    if(l==r) return ;
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
}
void mdf(int p, int l, int r, int L, int R, int v){
    if(L<=l&&r<=R){
        apply(p, v); return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(L<=mid) mdf(p<<1, l, mid, L, R, v);
    if(R>mid) mdf(p<<1|1, mid+1, r, L, R, v);
    up(p);
}
void solve(){
    read(n); read(m);
	scanf("%s", s+1);
	for(int i=1; i<=n; ++i){
		A.s[i]=B.s[n-i+1]=s[i]-'a'+1;
        bin[i].clear();
	}
	A.getSA(); A.build();
	B.getSA(); B.build();
	top=0;
	for(int i=n; i; --i){
		while(top&&A.rk[i]>A.rk[stk[top]]){
			--top;
		}
		if(top){
			work(i, stk[top]-1);
		}
		stk[++top]=i;
	}
	top=0;
	for(int i=n; i; --i){
		while(top&&A.rk[i]<A.rk[stk[top]]){
			--top;
		}
		if(top){
			work(i, stk[top]-1);
		}
		stk[++top]=i;
	}
    build(1, 1, n);
    ll ans=0;
    for(int i=1; 1ll*m*(i+i-m+1)<=n*2; ++i){
        if(i>m-1){
            for(auto [l, r]:bin[i-m+1]){
                ll rl=l-1ll*(i-m)*(i-m+1)/2;
                ll rr=r-1ll*(i-m)*(i-m+1)/2;
                rl=(rl%n+n)%n+1;
                rr=(rr%n+n)%n+1;
                // cout<<l<<' '<<r<<' '<<-1<<endl;
                if(rl<=rr) mdf(1, 1, n, rl, rr, -1);
                else mdf(1, 1, n, rl, n, -1), mdf(1, 1, n, 1, rr, -1);
            }
        }
        for(auto [l, r]:bin[i]){
            ll rl=l-1ll*i*(i-1)/2;
            ll rr=r-1ll*i*(i-1)/2;
            rl=(rl%n+n)%n+1;
            rr=(rr%n+n)%n+1;
            // cout<<l<<' '<<r<<' '<<1<<endl;
            if(rl<=rr) mdf(1, 1, n, rl, rr, 1);
            else mdf(1, 1, n, rl, n, 1), mdf(1, 1, n, 1, rr, 1);
        }
        if(tr[1]==m-1) ans+=sz[1];
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