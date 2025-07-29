#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5;
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
int T, n, m;
int a[N];

struct Tree{
    bool tr[N<<2];
    void build(int p, int l, int r, int tp){
        if(l==r){
            tr[p]=0;
            if(tp==1){
                if(a[l]==0&&a[l-1]==1&&a[l-2]==2&&a[l-3]==1){
                    tr[p]=1;
                }
            }
            if(tp==2){
                if(a[l]==0&&a[l-1]==2&&a[l-2]==0&&a[l-3]==2){
                    tr[p]=1;
                }
            }
            if(tp==3){
                if(a[l]==0&&a[l-1]==0&&a[l-2]==2&&a[l-3]==1&&a[l-4]==2){
                    tr[p]=1;
                }
            }
            return ;
        }
        int mid=(l+r)>>1;
        build(p<<1, l, mid, tp); build(p<<1|1, mid+1, r, tp);
        tr[p]=tr[p<<1]|tr[p<<1|1];
    }
    void mdf(int p, int l, int r, int x, int tp){
        if(l==r){
            tr[p]=0;
            if(tp==1){
                if(a[l]==0&&a[l-1]==1&&a[l-2]==2&&a[l-3]==1){
                    tr[p]=1;
                }
            }
            if(tp==2){
                if(a[l]==0&&a[l-1]==2&&a[l-2]==0&&a[l-3]==2){
                    tr[p]=1;
                }
            }
            if(tp==3){
                if(a[l]==0&&a[l-1]==0&&a[l-2]==2&&a[l-3]==1&&a[l-4]==2){
                    tr[p]=1;
                }
            }
            return ;
        }
        int mid=(l+r)>>1;
        if(x<=mid) mdf(p<<1, l, mid, x, tp);
        else mdf(p<<1|1, mid+1, r, x, tp);
        tr[p]=tr[p<<1]|tr[p<<1|1];
    }
    bool get(int p, int l, int r, int L, int R){
        if(L>R) return 0;
        if(L<=l&&r<=R) return tr[p];
        int mid=(l+r)>>1; bool ret=0;
        if(L<=mid) ret=get(p<<1, l, mid, L, R);
        if(R>mid) ret|=get(p<<1|1, mid+1, r, L, R);
        return ret;
    }
}T1, T2, T3;
int mx[N<<2], occ[N<<2];
void build(int p, int l, int r){
	if(l==r){
		if(a[l]>=3) mx[p]=l;
		else mx[p]=0;
		if(a[l]==0) occ[p]=0;
		else occ[p]=l;
		return ;
	}
	int mid=(l+r)>>1;
	build(p<<1, l, mid); build(p<<1|1, mid+1, r);
	mx[p]=max(mx[p<<1], mx[p<<1|1]);
	occ[p]=max(occ[p<<1], occ[p<<1|1]);
}
void mdf(int p, int l, int r, int x){
	if(l==r){
		if(a[l]>=3) mx[p]=l;
		else mx[p]=0;
		if(a[l]==0) occ[p]=0;
		else occ[p]=l;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid) mdf(p<<1, l, mid, x);
	else mdf(p<<1|1, mid+1, r, x);
	mx[p]=max(mx[p<<1], mx[p<<1|1]);
	occ[p]=max(occ[p<<1], occ[p<<1|1]);
}
int get(int p, int l, int r, int L, int R){
	if(L>R) return 0;
	if(L<=l&&r<=R) return mx[p];
	int mid=(l+r)>>1, ret=0;
	if(L<=mid) ret=get(p<<1, l, mid, L, R);
	if(R>mid) ret=max(ret, get(p<<1|1, mid+1, r, L, R));
	return ret;
}
int fnd(int p, int l, int r, int L, int R){
	if(occ[p]==0) return R+1;
	if(L<=l&&r<=R){
		if(l==r) return l;
		int mid=(l+r)>>1;
		if(occ[p<<1]!=0) return fnd(p<<1, l, mid, L, R);
		return fnd(p<<1|1, mid+1, r, L, R);
	}
	int mid=(l+r)>>1, ret=R+1;
	if(L<=mid) ret=fnd(p<<1, l, mid, L, R);
	if(R>mid&&ret==R+1) ret=fnd(p<<1|1, mid+1, r, L, R);
	return ret;
}
int getsz(int x){
	return fnd(1, 1, n, x+1, n)-x-1;
}
int mx2[N<<2];
void clr(int p, int l, int r){
	mx2[p]=0;
	if(l==r) return ;
	int mid=(l+r)>>1;
	clr(p<<1, l, mid); clr(p<<1|1, mid+1, r);
}
void mdf2(int p, int l, int r, int x, int v){
	if(l==r){
		mx2[p]=v;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid) mdf2(p<<1, l, mid, x, v);
	else mdf2(p<<1|1, mid+1, r, x, v);
	mx2[p]=max(mx2[p<<1], mx2[p<<1|1]);
}
int get2(int p, int l, int r, int L, int R){
	if(L>R) return 0;
	if(L<=l&&r<=R) return mx2[p];
	int mid=(l+r)>>1, ret=0;
	if(L<=mid) ret=get2(p<<1, l, mid, L, R);
	if(R>mid) ret=max(ret, get2(p<<1|1, mid+1, r, L, R));
	return ret;
}
set<int> st;
void work(int x){
	int i=get(1, 1, n, 1, x);
	if(i==0) return ;
	if(i+a[i]+3>n){
		return ;
	}
	if(a[i+1]!=2){
		return ;
	}
	if(a[i+2]!=1){
		return ;
	}
	int sz=getsz(i+2);
	if(sz!=a[i]-3){
		return ;
	}
	if(a[i+2+sz+1]!=1){
		return ;
	}
	int sz2=getsz(i+2+sz+1);
	if(sz2<3){
		return ;
	}
	st.insert(i);
	mdf2(1, 1, n, i, a[i]+4);
}
void solve(){
	read(n); read(m);
    for(int i=1; i<=n; ++i){
		read(a[i]);
    }
    if(n>=4){
        T1.build(1, 4, n, 1);
        T2.build(1, 4, n, 2);
    }
    if(n>=5){
        T3.build(1, 5, n, 3);
    }
	build(1, 1, n);
	clr(1, 1, n);
	st.clear();
	for(int i=1; i<=n-6; ) {
		if(a[i]<3) {
			++i; continue;
		}
		if(i+a[i]+3>n){
			++i; continue;
		}
		if(a[i+1]!=2){
			++i; continue;
		}
		if(a[i+2]!=1){
			++i; continue;
		}
		int sz=getsz(i+2);
		if(sz!=a[i]-3){
			++i; continue;
		}
		if(a[i+2+sz+1]!=1){
			++i; continue;
		}
		int sz2=getsz(i+2+sz+1);
		if(sz2<3){
			++i; continue;
		}
		st.insert(i);
		mdf2(1, 1, n, i, a[i]+4);
		i=i+a[i]+4;
	}
	st.insert(0);
    int op, l, r; 
    while(m--){
		read(op); read(l); read(r);
        if(op==1){
			set<int>::iterator it=st.upper_bound(l);
			--it;
			if((*it)!=0&&(*it)+a[*it]+3>=l) {
				mdf2(1, 1, n, *it, 0);
				st.erase(it);
			}
            a[l]=r;
			mdf(1, 1, n, l);
			work(l);
            if(n>=4){
                for(int i=max(l, 4); i<=l+3&&i<=n; ++i) T1.mdf(1, 4, n, i, 1);
                for(int i=max(l, 4); i<=l+3&&i<=n; ++i) T2.mdf(1, 4, n, i, 2);
            }
            if(n>=5){
                for(int i=max(l, 5); i<=l+4&&i<=n; ++i) T3.mdf(1, 5, n, i, 3);
            }
        }
        else{
            int ans=0;
            if(n>=4){
                ans=max(ans, 4*T1.get(1, 4, n, l+3, r));
                ans=max(ans, 4*T2.get(1, 4, n, l+3, r));
            }
            if(n>=5){
                ans=max(ans, 5*T3.get(1, 5, n, l+4, r));
            }
			set<int>::iterator it=st.upper_bound(r);
			--it;
			if((*it)>=l&&(*it)+a[*it]+3<=r) ans=max(ans, a[*it]+4);
			ans=max(ans, get2(1, 1, n, l, (*it)-1));
            printf("%d\n", ans);
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
}