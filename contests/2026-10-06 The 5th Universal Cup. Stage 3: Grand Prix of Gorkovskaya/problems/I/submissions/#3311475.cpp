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
const int inf=1e9;
int T, n, m;
int a[N];
int lp[N<<2], rp[N<<2];
struct MN_MX{
    int mn[N<<2], mx[N<<2];
    void build(int p, int l, int r){
        lp[p]=l; rp[p]=r;
        if(l==r){
            mn[p]=mx[p]=a[l];
            return ;
        }
        int mid=(l+r)>>1;
        build(p<<1, l, mid); build(p<<1|1, mid+1, r);
        mn[p]=min(mn[p<<1], mn[p<<1|1]);
        mx[p]=max(mx[p<<1], mx[p<<1|1]);
    }
    int gmx(int p, int l, int r, int L, int R){
        if(L<=l&&r<=R) return mx[p];
        int mid=(l+r)>>1, ret=-inf;
        if(L<=mid) ret=gmx(p<<1, l, mid, L, R);
        if(R>mid) ret=max(ret, gmx(p<<1|1, mid+1, r, L, R));
        return ret;
    }
    int gmn(int p, int l, int r, int L, int R){
        if(L<=l&&r<=R) return mn[p];
        int mid=(l+r)>>1, ret=inf;
        if(L<=mid) ret=gmn(p<<1, l, mid, L, R);
        if(R>mid) ret=min(ret, gmn(p<<1|1, mid+1, r, L, R));
        return ret;
    }
}T0;
vector<int> bin;
struct Query{
    int id, P, S;
};
vector<Query> qry[N<<2];
void split(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R){
        bin.ep(p);
        return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid) split(p<<1, l, mid, L, R);
    if(R>mid) split(p<<1|1, mid+1, r, L, R);
}
int pre[N], suf[N];
ll ans[N];
struct BIT{
    int lim;
    int c1[N]; ll c2[N];
    void add(int x, int v1, int v2){
        for(; x<=lim; x+=(x&-x)) c1[x]+=v1, c2[x]+=v2;
    }
    pair<int, ll> get(int x){
        int r1=0; ll r2=0;
        for(; x; x-=(x&-x)) r1+=c1[x], r2+=c2[x];
        return mapa(r1, r2);
    }
    void clr(int siz){
        lim=siz;
        for(int i=1; i<=lim; ++i) c1[i]=0, c2[i]=0;
    }
}T1;
int x[N], y[N], c[N];
int rk[N];
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n); read(m);
    for(int i=1; i<=n; ++i) read(a[i]);
    T0.build(1, 1, n);
    for(int o=1, l, r; o<=m; ++o){
        read(l); read(r);
        ans[o]=a[r]-a[l];
        if(r-l<=1) continue;
        bin.clear();
        split(1, 1, n, l+1, r-1);
        int P=a[l];
        for(int i=0; i<(int)bin.size(); ++i){
            pre[i]=P;
            P=max(P, T0.mx[bin[i]]);
        }
        int S=a[r];
        for(int i=(int)bin.size()-1; i>=0; --i){
            suf[i]=S;
            S=min(S, T0.mn[bin[i]]);
        }
        for(int i=0; i<(int)bin.size(); ++i){
            qry[bin[i]].push_back((Query){o, pre[i], suf[i]});
        }
    }
    for(int i=1; i<=n*4; ++i) {
        if(!lp[i]) continue;
        if(qry[i].empty()) continue;
        sort(qry[i].begin(), qry[i].end(), [&](Query u, Query v){return u.P+u.S<v.P+v.S;});
        for(int j=lp[i]; j<=rp[i]; ++j) c[j]=0;
        int p=-inf;
        for(int j=lp[i]; j<=rp[i]; ++j){
            c[j]=min(c[j], a[j]-p);
            p=max(p, a[j]);
        }
        int s=inf;
        for(int j=rp[i]; j>=lp[i]; --j){
            c[j]=min(c[j], s-a[j]);
            s=min(s, a[j]);
        }
        ll sum=0;
        for(int j=lp[i]; j<=rp[i]; ++j){
            rk[j]=j;
            sum+=c[j];
        }
        for(auto tem:qry[i]){
            ans[tem.id]+=sum;
        }
        vector<int> lis;
        for(int j=lp[i]; j<=rp[i]; ++j){
            x[j]=2*a[j]; y[j]=a[j]-c[j]; lis.ep(y[j]);
        }
        sort(rk+lp[i], rk+rp[i]+1, [&](int u, int v){return x[u]<x[v];});
        sort(lis.begin(), lis.end());
        lis.erase(unique(lis.begin(), lis.end()), lis.end());
        T1.clr(lis.size());
        int it=lp[i];
        for(auto tem:qry[i]){
            while(it<=rp[i]&&x[rk[it]]<=tem.P+tem.S){
                T1.add(lower_bound(lis.begin(), lis.end(), y[rk[it]])-lis.begin()+1, 1, y[rk[it]]);
                ++it;
            }
            pair<int, ll> info=T1.get(upper_bound(lis.begin(), lis.end(), tem.P)-lis.begin());
            ans[tem.id]+=info.se-1ll*tem.P*info.fi;
        }
        
        lis.clear();
        for(int j=lp[i]; j<=rp[i]; ++j){
            x[j]=2*a[j]; y[j]=-a[j]-c[j]; lis.ep(y[j]);
        }
        sort(lis.begin(), lis.end());
        lis.erase(unique(lis.begin(), lis.end()), lis.end());
        T1.clr(lis.size());
        it=rp[i];
        reverse(qry[i].begin(), qry[i].end());
        for(auto tem:qry[i]){
            while(it>=lp[i]&&x[rk[it]]>tem.P+tem.S){
                T1.add(lower_bound(lis.begin(), lis.end(), y[rk[it]])-lis.begin()+1, 1, y[rk[it]]);
                --it;
            }
            pair<int, ll> info=T1.get(upper_bound(lis.begin(), lis.end(), -tem.S)-lis.begin());
            ans[tem.id]+=info.se+1ll*tem.S*info.fi;
        }
    }
    for(int i=1; i<=m; ++i){
        printf("%lld\n", ans[i]);
    }
	return 0;
}
