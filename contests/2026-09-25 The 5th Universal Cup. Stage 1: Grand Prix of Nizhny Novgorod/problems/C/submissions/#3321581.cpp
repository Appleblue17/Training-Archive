#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,int> pdi;
#define fi first
#define se second
#define mapa make_pair
typedef unsigned long long ull;
#define ep emplace_back
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=1e6+5;
const ld inf=log(1e9);
int n, m;
ld a[N];
struct event{
    int l, r; ld v;
    event(int _l, int _r, ld _v){l=_l; r=_r; v=_v;}
};
vector<event> bin[N];
int fa[N];
int gf(int x){
    if(x==fa[x]) return x;
    return fa[x]=gf(fa[x]);
}
bool merge(int x, int y){
    x=gf(x); y=gf(y);
    if(x==y) return false;
    fa[x]=y; return true;
}
pdi best[N];
pdi mn[N<<2], mn2[N<<2]; ld tag[N<<2];
void up(int p){
    if(mn[p<<1].fi<mn[p<<1|1].fi){
        mn[p]=mn[p<<1]; mn2[p]=mn2[p<<1];
        if(mn2[p<<1|1].se!=mn[p].se&&mn2[p<<1|1].fi<mn2[p].fi) mn2[p]=mn2[p<<1|1];
        if(mn[p<<1|1].se!=mn[p].se&&mn[p<<1|1].fi<mn2[p].fi) mn2[p]=mn[p<<1|1];
    }
    else{
        mn[p]=mn[p<<1|1]; mn2[p]=mn2[p<<1|1];
        if(mn2[p<<1].se!=mn[p].se&&mn2[p<<1].fi<mn2[p].fi) mn2[p]=mn2[p<<1];
        if(mn[p<<1].se!=mn[p].se&&mn[p<<1].fi<mn2[p].fi) mn2[p]=mn[p<<1];
    }
}
void clr(int p, int l, int r){
    tag[p]=0; 
    if(l==r) {
        mn[p]=mapa(-a[l], fa[l]);
        mn2[p]=mapa(1e9, 0);
        return ;
    }
    int mid=(l+r)>>1;
    clr(p<<1, l, mid); clr(p<<1|1, mid+1, r);
    up(p);
}
void clr2(int p, int l, int r){
    tag[p]=0; 
    if(l==r) {
        mn[p]=mapa(a[l], fa[l]);
        mn2[p]=mapa(1e9, 0);
        return ;
    }
    int mid=(l+r)>>1;
    clr2(p<<1, l, mid); clr2(p<<1|1, mid+1, r);
    up(p);
}
void apply(int p, ld v){
    mn[p].fi+=v; mn2[p].fi+=v; tag[p]+=v;
}
void down(int p){
    apply(p<<1, tag[p]); apply(p<<1|1, tag[p]); tag[p]=0;
}
void mdf(int p, int l, int r, int L, int R, ld v){
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
pdi ans, ans2;
void get(int p, int l, int r, int L, int R){
    if(L>R) return ;
    if(L<=l&&r<=R){
        if(ans.fi<mn[p].fi){
            if(mn2[p].se!=ans.se&&mn2[p].fi<ans2.fi) ans2=mn2[p];
            if(mn[p].se!=ans.se&&mn[p].fi<ans2.fi) ans2=mn[p];
        }
        else{
            pdi na, na2;
            na=mn[p]; na2=mn2[p];
            if(ans2.se!=na.se&&ans2.fi<na2.fi) na2=ans2;
            if(ans.se!=na.se&&ans.fi<na2.fi) na2=ans;
            ans=na; ans2=na2;
        }
        return ;
    }
    down(p);
    int mid=(l+r)>>1;
    if(L<=mid) get(p<<1, l, mid, L, R);
    if(R>mid) get(p<<1|1, mid+1, r, L, R);
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n); read(m);
    for(int i=1, x; i<=n; ++i){
        read(x); a[i]=log(x);
    }
    for(int i=1, l1, r1, l2, r2, c; i<=m; ++i){
        read(l1); read(r1); read(l2); read(r2); read(c);
        bin[l1].ep(l2, r2, log(c));
        bin[r1+1].ep(l2, r2, -log(c));
        bin[l2].ep(l1, r1, log(c));
        bin[r2+1].ep(l1, r1, -log(c));
        l1=max(l1, l2); r1=min(r1, r2);
        if(l1<=r1){
            bin[l1].ep(l1, r1, -log(c));
            bin[r1+1].ep(l1, r1, log(c));
        }
    }
    int cnt=n;
    ld sum=0;
    for(int i=1; i<=n; ++i) fa[i]=i;
    while(cnt>1){
        for(int i=1; i<=n; ++i) {
            fa[i]=gf(i); best[i]=mapa(1e9, 0);
        }
        clr(1, 1, n);
        for(int i=1; i<=n; ++i){
            for(auto [l, r, v]:bin[i]){
                mdf(1, 1, n, l, r, v);
            }
            ans=mapa(1e9, 0); ans2=mapa(1e9, 0);
            get(1, 1, n, 1, i-1);
            ans.fi+=a[i]; ans2.fi+=a[i];
            if(ans.se==fa[i]) best[fa[i]]=min(best[fa[i]], ans2);
            else best[fa[i]]=min(best[fa[i]], ans);
        }
        clr2(1, 1, n);
        for(int i=n; i>=1; --i){
            for(auto [l, r, v]:bin[i+1]){
                mdf(1, 1, n, l, r, -v);
            }
            ans=mapa(1e9, 0); ans2=mapa(1e9, 0);
            get(1, 1, n, i+1, n);
            ans.fi-=a[i]; ans2.fi-=a[i];
            if(ans.se==fa[i]) best[fa[i]]=min(best[fa[i]], ans2);
            else best[fa[i]]=min(best[fa[i]], ans);
        }
        vector<int> rt;
        for(int i=1; i<=n; ++i) if(i==fa[i]) rt.ep(i);
        for(auto x:rt){
            // cout<<x<<' '<<best[x].fi<<' '<<best[x].se<<endl;
            if(merge(best[x].se, x)){
                --cnt;
                sum+=exp(min(inf, best[x].fi));
            }
        }
    }
    sum=min(sum, (ld)1e9);
    printf("%.6Lf\n", sum);
	return 0;
}
