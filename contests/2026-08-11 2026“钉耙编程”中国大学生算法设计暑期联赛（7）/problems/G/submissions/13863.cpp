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
const int N=6e5+5, inf=1e9;
int T, n, m;
struct sgt1{
    struct info{
        int mn, c0, c1;
        info(int _mn=0, int _c0=0, int _c1=0){
            mn=_mn; c0=_c0; c1=_c1;
        }
    };
    inline friend info operator +(info x, info y){
        info z;
        z.mn=min(x.mn, y.mn);
        if(z.mn==x.mn) z.c0+=x.c0, z.c1+=x.c1;
        else if(z.mn+1==x.mn) z.c1+=x.c0;
        if(z.mn==y.mn) z.c0+=y.c0, z.c1+=y.c1;
        else if(z.mn+1==y.mn) z.c1+=y.c0;
        return z;
    }
    inline friend info operator *(info x, int a){
        x.mn+=a; 
        return x;
    }
    info tr[N<<1];
    int tg[N<<1];
    void clr(int p, int l, int r){
        tr[p].mn=0; tr[p].c0=r-l+1; tr[p].c1=0; tg[p]=0;
        if(l==r) return ;
        int mid=(l+r)>>1;
        clr(p<<1, l, mid); clr(p<<1|1, mid+1, r);
    }
    inline void apply(int p, int v){
        tr[p]=tr[p]*v;
        tg[p]=tg[p]+v;
    }
    inline void down(int p){
        if(tg[p]){
            apply(p<<1, tg[p]);
            apply(p<<1|1, tg[p]);
            tg[p]=0;
        }
    }
    void mdf(int p, int l, int r, int L, int R, int v){
        if(L<=l&&r<=R){
            apply(p, v);
            return ;
        }
        down(p);
        int mid=(l+r)>>1;
        if(L<=mid) mdf(p<<1, l, mid, L, R, v);
        if(R>mid) mdf(p<<1|1, mid+1, r, L, R, v);
        tr[p]=tr[p<<1]+tr[p<<1|1];
    }
    info get(int p, int l, int r, int L, int R){
        if(L<=l&&r<=R){
            return tr[p];
        }
        down(p);
        int mid=(l+r)>>1;
        if(L>mid) return get(p<<1|1, mid+1, r, L, R);
        if(R<=mid) return get(p<<1, l, mid, L, R);
        return get(p<<1, l, mid, L, R)+get(p<<1|1, mid+1, r, L, R);
    }
}T1[20];
struct sgt2{
    struct info{
        int mn1, mn2;
        info(int _mn1=inf, int _mn2=inf){
            mn1=_mn1; mn2=_mn2;
        }
    };
    inline friend info operator +(info x, info y){
        info z;
        z.mn1=min(x.mn1, y.mn1);
        if(z.mn1==x.mn1) z.mn2=min(x.mn2, y.mn1);
        else z.mn2=min(x.mn1, y.mn2);
        return z;
    }
    info tr[N<<1];
    void clr(int p, int l, int r){
        tr[p].mn1=tr[p].mn2=inf;
        if(l==r) return ;
        int mid=(l+r)>>1;
        clr(p<<1, l, mid); clr(p<<1|1, mid+1, r);
    }
    void mdf(int p, int l, int r, int x, info v){
        if(l==r) {
            tr[p]=v; return ;
        }
        int mid=(l+r)>>1;
        if(x<=mid) mdf(p<<1, l, mid, x, v);
        else mdf(p<<1|1, mid+1, r, x, v);
        tr[p]=tr[p<<1]+tr[p<<1|1];
    }
    int fnd(int p, int l, int r, int L, int R){
        //L<=l, mn1<=R
        if(tr[p].mn1>R) return inf;
        if(l==r) return l;
        int mid=(l+r)>>1, ret=inf;
        if(L<=mid) ret=fnd(p<<1, l, mid, L, R);
        if(ret==inf) ret=fnd(p<<1|1, mid+1, r, L, R);
        return ret;
    }
    int fnd2(int p, int l, int r, int L, int R){
        if(tr[p].mn1>R) return inf;
        if(L<=l&&tr[p].mn2>R) return inf-1;
        if(l==r) return l;
        int mid=(l+r)>>1, ret=inf;
        if(L<=mid) ret=fnd2(p<<1, l, mid, L, R);
        if(ret==inf) ret=fnd2(p<<1|1, mid+1, r, L, R);
        else if(ret==inf-1) ret=fnd(p<<1|1, mid+1, r, L, R);
        return ret;
    }
}T2[20];

struct sgt3{
    struct info{
        int mx1, mx2;
        info(int _mx1=0, int _mx2=0){
            mx1=_mx1; mx2=_mx2;
        }
    };
    inline friend info operator +(info x, info y){
        info z;
        z.mx1=max(x.mx1, y.mx1);
        if(z.mx1==x.mx1) z.mx2=max(x.mx2, y.mx1);
        else z.mx2=max(x.mx1, y.mx2);
        return z;
    }
    info tr[N<<1];
    void clr(int p, int l, int r){
        tr[p].mx1=tr[p].mx2=0;
        if(l==r) return ;
        int mid=(l+r)>>1;
        clr(p<<1, l, mid); clr(p<<1|1, mid+1, r);
    }
    void mdf(int p, int l, int r, int x, info v){
        if(l==r) {
            tr[p]=v; return ;
        }
        int mid=(l+r)>>1;
        if(x<=mid) mdf(p<<1, l, mid, x, v);
        else mdf(p<<1|1, mid+1, r, x, v);
        tr[p]=tr[p<<1]+tr[p<<1|1];
    }
    int fnd(int p, int l, int r, int L, int R){
        //L<=mx1, r<=R
        if(tr[p].mx1<L) return -1;
        if(l==r) return l;
        int mid=(l+r)>>1, ret=-1;
        if(R>mid) ret=fnd(p<<1|1, mid+1, r, L, R);
        if(ret==-1) ret=fnd(p<<1, l, mid, L, R);
        return ret;
    }
    int fnd2(int p, int l, int r, int L, int R){
        if(tr[p].mx1<L) return -1;
        if(L<=l&&tr[p].mx2<L) return 0;
        if(l==r) return l;
        int mid=(l+r)>>1, ret=-1;
        if(R>mid) ret=fnd2(p<<1|1, mid+1, r, L, R);
        if(ret==-1) ret=fnd2(p<<1, l, mid, L, R);
        else if(ret==0) ret=fnd(p<<1, l, mid, L, R);
        return ret;
    }
}T3[20];
multiset<int> s[N<<1];
unordered_map<int, int> id[20];
int idx;
void clr(int d, int p, int l, int r){
    T1[d].clr(p, l, r);
    if(l==r) return ;
    int mid=(l+r)>>1;
    T2[d].clr(p<<1, l, mid);
    T3[d].clr(p<<1|1, mid+1, r);
    clr(d+1, p<<1, l, mid); clr(d+1, p<<1|1, mid+1, r);
}
void add(int d, int p, int l, int r, int L, int R){
    T1[d].mdf(p, l, r, L, R, 1);
    if(l==r) return ;
    int mid=(l+r)>>1;
    if(L>mid) {
        add(d+1, p<<1|1, mid+1, r, L, R);
        return ;
    }
    if(R<=mid) {
        add(d+1, p<<1, l, mid, L, R);
        return ;
    }
    if(!id[d][L]) id[d][L]=++idx;
    if(!id[d][R]) id[d][R]=++idx;
    auto &mpl=s[id[d][L]], &mpr=s[id[d][R]];
    mpl.insert(R); mpr.insert(L);
    {
        sgt2::info f;
        auto it=mpl.begin();
        if(it!=mpl.end()) f.mn1=*it, ++it;
        if(it!=mpl.end()) f.mn2=*it;
        T2[d].mdf(p<<1, l, mid, L, f);
        // cout<<"T2:"<<L<<' '<<f.mn1<<' '<<f.mn2<<endl;
    }
    {
        sgt3::info f;
        auto it=mpr.end(); 
        if(it!=mpr.begin()) --it, f.mx1=*it;
        if(it!=mpr.begin()) --it, f.mx2=*it;
        T3[d].mdf(p<<1|1, mid+1, r, R, f);
        // cout<<"T3:"<<R<<' '<<f.mx1<<' '<<f.mx2<<endl;
    }
}
void del(int d, int p, int l, int r, int L, int R){
    T1[d].mdf(p, l, r, L, R, -1);
    if(l==r) return ;
    int mid=(l+r)>>1;
    if(L>mid) {
        del(d+1, p<<1|1, mid+1, r, L, R);
        return ;
    }
    if(R<=mid) {
        del(d+1, p<<1, l, mid, L, R);
        return ;
    }
    if(!id[d][L]) id[d][L]=++idx;
    if(!id[d][R]) id[d][R]=++idx;
    auto &mpl=s[id[d][L]], &mpr=s[id[d][R]];
    mpl.erase(mpl.find(R)); mpr.erase(mpr.find(L));
    {
        sgt2::info f;
        auto it=mpl.begin();
        if(it!=mpl.end()) f.mn1=*it, ++it;
        if(it!=mpl.end()) f.mn2=*it;
        T2[d].mdf(p<<1, l, mid, L, f);
    }
    {
        sgt3::info f;
        auto it=mpr.end(); 
        if(it!=mpr.begin()) --it, f.mx1=*it;
        if(it!=mpr.begin()) --it, f.mx2=*it;
        T3[d].mdf(p<<1|1, mid+1, r, R, f);
    }
}
int get(int d, int p, int l, int r, int L, int R, sgt2::info llim, sgt3::info rlim){
    // cout<<d<<' '<<p<<' '<<l<<' '<<r<<' '<<L<<' '<<R<<endl;
    if(L<=l&&r<=R){
        int l1=llim.mn1, l2=llim.mn2;
        int r1=rlim.mx1, r2=rlim.mx2;
        // cout<<l<<' '<<r<<endl;
        // cout<<l1<<' '<<l2<<' '<<r1<<' '<<r2<<endl;
        if(r1<l1){
            // cout<<"Type A:"<<endl;
            int ret=0;
            if(max(l, r2+1)<=min(r, r1)){
                sgt1::info f=T1[d].get(p, l, r, max(l, r2+1), min(r, r1));
                if(f.mn==0) ret+=f.c0;
            }
            if(max(l, l1)<=min(r, l2-1)){
                sgt1::info f=T1[d].get(p, l, r, max(l, l1), min(r, l2-1));
                if(f.mn==0) ret+=f.c0;
            }
            if(max(l, r1+1)<=min(r, l1-1)){
                sgt1::info f=T1[d].get(p, l, r, max(l, r1+1), min(r, l1-1));
                if(f.mn==0) ret+=f.c1;
                else if(f.mn==1) ret+=f.c0;
            }
            return ret;
        }
        if(r2<l2){
            int ret=0;
            if(r2+1<=l1-1){
                sgt1::info f=T1[d].get(p, l, r, max(l, r2+1), min(r, l1-1));
                if(f.mn==0) ret+=f.c0;
            }
            if(r1+1<=l2-1){
                sgt1::info f=T1[d].get(p, l, r, max(l, r1+1), min(r, l2-1));
                if(f.mn==0) ret+=f.c0;
            }
            return ret;
        }
        return 0;
    }
    int mid=(l+r)>>1;
    if(L>mid) return get(d+1, p<<1|1, mid+1, r, L, R, llim, rlim);
    if(R<=mid) return get(d+1, p<<1, l, mid, L, R, llim, rlim);
    // cout<<"here"<<endl;
    // cout<<T2[d].fnd(p<<1, l, mid, L, R)<<' '<<T2[d].fnd2(p<<1, l, mid, L, R)<<endl;
    int lv=get(d+1, p<<1, l, mid, L, R, llim+(sgt2::info){T2[d].fnd(p<<1, l, mid, L, R), T2[d].fnd2(p<<1, l, mid, L, R)}, rlim);
    // cout<<"there1"<<endl;
    // cout<<T3[d].fnd(p<<1|1, mid+1, r, L, R)<<' '<<T3[d].fnd2(p<<1|1, mid+1, r, L, R)<<endl;
    int rv=get(d+1, p<<1|1, mid+1, r, L, R, llim, rlim+(sgt3::info){T3[d].fnd(p<<1|1, mid+1, r, L, R), T3[d].fnd2(p<<1|1, mid+1, r, L, R)});
    // cout<<"there2"<<endl;
    return lv+rv;
}
void solve(){
    read(n); read(m);
    for(int i=0; i<20; ++i) id[i].clear();
    for(int i=1; i<=idx; ++i) s[i].clear();
    clr(0, 1, 1, n);
    for(int i=1, op, l, r; i<=m; ++i){
        read(op); read(l); read(r);
        // cout<<op<<' '<<l<<' '<<r<<endl;
        if(op==1) {
            add(0, 1, 1, n, l, r); 
            // cout<<"add:"<<l<<' '<<r<<endl;
        }
        else if(op==2) {
            del(0, 1, 1, n, l, r);
        }
        else {
            printf("%d\n", get(0, 1, 1, n, l, r, sgt2::info(inf, inf), sgt3::info(0, 0)));
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