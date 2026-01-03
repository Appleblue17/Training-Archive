#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
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
const int N=1e6+5;
const ll inf=1e15;
mt19937 rnd(1234);
int T, n, m; ll lim;
int a[N];
inline pli operator +(pli x, pli y){
    return mapa(x.fi+y.fi, x.se+y.se);
}
struct node{
    int ls, rs;
    int siz, pri;
    pli val, tag; ll sum;
}tr[N];
void apply(int x, pli v){
    tr[x].val=tr[x].val+v; tr[x].tag=tr[x].tag+v; tr[x].sum+=v.fi*tr[x].siz;
}
void down(int rt){
    if(tr[rt].rs) apply(tr[rt].rs, tr[rt].tag); 
    if(tr[rt].ls) apply(tr[rt].ls, tr[rt].tag); 
    tr[rt].tag=mapa(0, 0);
}
void push_up(int rt){
    tr[rt].siz=tr[tr[rt].ls].siz+tr[tr[rt].rs].siz+1;
    tr[rt].sum=tr[tr[rt].ls].sum+tr[tr[rt].rs].sum+tr[rt].val.fi;;
}
int Merge(int x, int y){
    if(x==0||y==0) return x+y;
    down(x); down(y);
    if(tr[x].pri<tr[y].pri){
        tr[x].rs=Merge(tr[x].rs, y);
        push_up(x);
        return x;
    }
    tr[y].ls=Merge(x, tr[y].ls);
    push_up(y);
    return y;
}
void Split(int rt, ll v, int &x, int &y){
    if(rt==0){
        x=y=0;
        return ;
    }
    down(rt);
    if(tr[rt].val.fi>=v*tr[rt].val.se){
        x=rt;
        Split(tr[rt].rs, v, tr[x].rs, y);
        push_up(x);
    }
    else{
        y=rt;
        Split(tr[rt].ls, v, x, tr[y].ls);
        push_up(y);
    }
}
ll get_k(int rt, int k){
    ll ret=0;
    down(rt);
    if(tr[tr[rt].ls].siz>=k){
        return get_k(tr[rt].ls, k);
    }
    ret=tr[tr[rt].ls].sum;
    k-=tr[tr[rt].ls].siz;
    ret+=tr[rt].val.fi;
    --k;
    if(k==0){
        return ret;
    }
    return ret+get_k(tr[rt].rs, k);
}
int idx;
int add_node(int rt, ll v){
    int A=0, B=0;
    Split(rt, v, A, B);
    ++idx; tr[idx].siz=1; tr[idx].pri=rnd();
    tr[idx].ls=tr[idx].rs=0;
    tr[idx].val=mapa(v*(m+1-tr[A].siz), m+1-tr[A].siz); tr[idx].sum=tr[idx].val.fi;
    tr[idx].tag=mapa(0, 0);
    if(B!=0) apply(B, mapa(-v, -1));
    return Merge(Merge(A, idx), B);
}
int Cut(int rt){
    if(!tr[rt].ls&&!tr[rt].rs) return 0;
    down(rt);
    if(tr[rt].rs) {
        tr[rt].rs=Cut(tr[rt].rs);
        push_up(rt);
        return rt;
    }
    return tr[rt].ls;
}
int rt;
void clr(){
    rt=1; idx=2;
    tr[1].ls=0; tr[1].rs=2; tr[1].siz=2; tr[1].pri=rnd(); tr[1].val=mapa(inf, 0); tr[1].sum=0; tr[1].tag=mapa(0, 0);
    tr[2].ls=tr[2].rs=0; tr[2].siz=1; tr[2].pri=rnd(); tr[2].val=mapa(-inf, 0); tr[2].sum=-inf; tr[2].tag=mapa(0, 0);
}
ll f[N], g[N];
bool check(int l, int r){
    if(r-l+1<m*2){
        return false;
    }
    clr();
    for(int i=l; i<=r; ++i){
        rt=add_node(rt, a[i]);
        if(tr[rt].siz>m+1) rt=Cut(rt);
        if(i-l+1>=m){
            f[i]=tr[rt].sum-inf;
        }
    }
    clr();
    for(int i=r; i>=l; --i){
        rt=add_node(rt, a[i]);
        if(tr[rt].siz>m+1) rt=Cut(rt);
        if(r-i+1>=m){
            g[i]=tr[rt].sum-inf;
        }
    }
    for(int i=l; i<r; ++i){
        if(i-l+1>=m&&r-i>=m){
            if(f[i]+g[i+1]>=lim) return true;
        }
    }
    return false;
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n); read(m); read(lim);
    for(int i=1; i<=n; ++i) read(a[i]);
    if(m*4>n){
        printf("%d\n", check(1, n));
        return 0;
    }
    int ans=0;
    for(int l=1; l<=n; ){
        int r=l;
        for(int i=0; r<=n; ++i){
            if(!check(l, min(r+(1<<i), n))){
                r+=(1<<i);
            }
            else{
                int lp=r+1, rp=min(r+(1<<i), n)-1, mid, ret=min(r+(1<<i), n);
                while(lp<=rp){
                    mid=(lp+rp)>>1;
                    if(check(l, mid)){
                        ret=mid; rp=mid-1;
                    }
                    else{
                        lp=mid+1;
                    }
                }
                r=ret; ++ans;
                break;
            }
        }
        l=r+1;
    }
    printf("%d\n", ans);
	return 0;
}

