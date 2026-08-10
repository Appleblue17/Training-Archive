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
int ql[N], qr[N], qm[N];
struct sgmn{
	int tr[N<<2];
	void build(int p, int l, int r){
		if(l==r){
			tr[p]=l;
			return ;
		}
		int mid=(l+r)>>1;
		build(p<<1, l, mid); build(p<<1|1, mid+1, r);
		tr[p]=(a[tr[p<<1]]<a[tr[p<<1|1]])?tr[p<<1]:tr[p<<1|1];
	}
	int get(int p, int l, int r, int L, int R){
		if(L<=l&&r<=R){
			return tr[p];
		}
		int mid=(l+r)>>1, ret=0;
		if(L<=mid) ret=get(p<<1, l, mid, L, R);
		if(R>mid){
			int x=get(p<<1|1, mid+1, r, L, R);
			if(a[ret]>a[x]) ret=x;
		}
		return ret;
	}
}MN;
struct sgt{
	int tr[N<<2], tag[N<<2];
	void clr(int p, int l, int r){
		tr[p]=tag[p]=0;
		if(l==r) return ;
		int mid=(l+r)>>1;
		clr(p<<1, l, mid); clr(p<<1|1, mid+1, r);
	}
	void down(int p){
		if(tag[p]!=0){
			tr[p<<1]+=tag[p]; tr[p<<1|1]+=tag[p];
			tag[p<<1]+=tag[p]; tag[p<<1|1]+=tag[p];
			tag[p]=0;
		}
	}
	void add(int p, int l, int r, int L, int R, int v){
		if(L>R) return ;
		if(L<=l&&r<=R){
			tr[p]+=v; tag[p]+=v;
			return ;
		}
		int mid=(l+r)>>1;
		down(p);
		if(L<=mid) add(p<<1, l, mid, L, R, v);
		if(R>mid) add(p<<1|1, mid+1, r, L, R, v);
		tr[p]=max(tr[p<<1], tr[p<<1|1]);
	}
	int get(int p, int l, int r, int L, int R){
		if(L>R) return -1;
		if(L<=l&&r<=R){
			return tr[p];
		}
		int mid=(l+r)>>1, ret=0;
		down(p);
		if(L<=mid) ret=get(p<<1, l, mid, L, R);
		if(R>mid) ret=max(ret, get(p<<1|1, mid+1, r, L, R));
		return ret;
	}
}T;
int stk[N], top;
vector<int> qry[N];
int ans[N];
void solve(){
	read(n); read(m);
	a[0]=n+1; a[n+1]=n+1;
	for(int i=1; i<=n; ++i) read(a[i]);
	MN.build(1, 1, n);
	for(int i=1; i<=m; ++i) {
        read(ql[i]), read(qr[i]), qm[i]=MN.get(1, 1, n, ql[i], qr[i]), ans[i]=1;
    }
	for(int i=1; i<=n; ++i){
		qry[i].clear();
	}
	for(int i=1; i<=m; ++i){
		if(qm[i]!=qr[i]) qry[qr[i]].ep(i);
	}
	T.clr(1, 1, n);
	top=0;
	stk[0]=0;
	for(int i=1; i<=n; ++i){
		while(top&&a[stk[top]]>a[i]){
			--top;
		}
		T.add(1, 1, n, stk[top]+1, i-1, 1);
		stk[++top]=i;
		T.add(1, 1, n, i, i, top);
		for(auto id:qry[i]){
            // if(id==6){
            //     cout<<T.get(1, 1, n, qm[id]+1, qr[id])<<' '<<T.get(1, 1, n, qm[id], qm[id])<<endl;
            // }
			ans[id]=max(ans[id], T.get(1, 1, n, qm[id]+1, qr[id])-T.get(1, 1, n, qm[id], qm[id])+1);
		}
	}
	
	for(int i=1; i<=n; ++i){
		qry[i].clear();
	}
	for(int i=1; i<=m; ++i){
		if(qm[i]!=ql[i]) qry[ql[i]].ep(i);
	}
	T.clr(1, 1, n);
	top=0;
	stk[0]=n+1;
	for(int i=n; i>=1; --i){
		while(top&&a[stk[top]]>a[i]){
			--top;
		}
		T.add(1, 1, n, i+1, stk[top]-1, 1);
		stk[++top]=i;
		T.add(1, 1, n, i, i, top);
		for(auto id:qry[i]){
			ans[id]=max(ans[id], T.get(1, 1, n, ql[id], qm[id]-1)-T.get(1, 1, n, qm[id], qm[id])+1);
		}
	}
	for(int i=1; i<=m; ++i){
		printf("%d\n", ans[i]);
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