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
const int N=1e6+5;
int Test, n, m;
int a[N];
struct sgt{
    int tr[N<<2];
    void mdf(int p, int l, int r, int x, int v){
        if(l==r){
            tr[p]=v;
            return ;
        }
        int mid=(l+r)>>1;
        if(x<=mid) mdf(p<<1, l, mid, x, v);
        else mdf(p<<1|1, mid+1, r, x, v);
        tr[p]=tr[p<<1]+tr[p<<1|1];
    }
    int get(int p, int l, int r, int L, int R){
        if(L<=l&&r<=R){
            return tr[p];
        }
        int mid=(l+r)>>1, ret=0;
        if(L<=mid) ret=get(p<<1, l, mid, L, R);
        if(R>mid) ret=ret+get(p<<1|1, mid+1, r, L, R);
        return ret;
    }
    int fndl(int p, int l, int r, int L, int R){
        if(!tr[p]) return -1;
        if(L<=l&&r<=R){
            if(l==r) return l;
            int mid=(l+r)>>1;
            if(tr[p<<1]) return fndl(p<<1, l, mid, L, R);
            return fndl(p<<1|1, mid+1, r, L, R);
        }
        int mid=(l+r)>>1, ret=-1;
        if(L<=mid) ret=fndl(p<<1, l, mid, L, R);
        if(ret==-1&&R>mid) ret=fndl(p<<1|1, mid+1, r, L, R);
        return ret;
    }
    int fndr(int p, int l, int r, int L, int R){
        if(!tr[p]) return -1;
        if(L<=l&&r<=R){
            if(l==r) return l;
            int mid=(l+r)>>1;
            if(tr[p<<1|1]) return fndr(p<<1|1, mid+1, r, L, R);
            return fndr(p<<1, l, mid, L, R);
        }
        int mid=(l+r)>>1, ret=-1;
        if(R>mid) ret=fndr(p<<1|1, mid+1, r, L, R);
        if(ret==-1&&L<=mid) ret=fndr(p<<1, l, mid, L, R);
        return ret;
    }
}T[4];
void solve(){
    read(n); read(m);
    for(int i=1; i<=n; ++i){
        read(a[i]);
        for(int o=0; o<3; ++o) T[o].mdf(1, 1, n, i, (a[i]==o));
        if(i>=2) T[3].mdf(1, 2, n, i, (a[i-1]>a[i]));
    }
    while(m--){
        int op;
        read(op);
        if(op==1){
            int x, v;
            read(x); read(v);
            for(int o=0; o<3; ++o) T[o].mdf(1, 1, n, x, (v==o));
            a[x]=v;
            if(x>=2) T[3].mdf(1, 2, n, x, (a[x-1]>a[x]));
            if(x+1<=n) T[3].mdf(1, 2, n, x+1, (a[x]>a[x+1]));
        }
        else{
            int l, r;
            read(l); read(r);
            if(l==r){
                printf("0\n");
                continue;
            }
            if(T[3].get(1, 2, n, l+1, r)==0){
                printf("0\n");
                continue;
            }
            int p2=T[2].fndl(1, 1, n, l, r), p0=T[0].fndr(1, 1, n, l, r);
            if(p2==-1||p0==-1){
                printf("1\n");
                continue;
            }
            if(T[1].get(1, 1, n, p2, p0)==0){
                printf("1\n");
            }
            else{
                printf("2\n");
            }
        }
    }
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(Test);
	while(Test--){
		solve();
	}
	return 0;
}