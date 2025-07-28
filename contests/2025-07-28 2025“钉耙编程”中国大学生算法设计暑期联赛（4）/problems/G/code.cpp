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

int L[N],R[N];

void del(int pos){
    int x=a[pos];
    
    if(x){
        L[pos]=R[pos]=pos;
    }
    else{
        if(pos-1>=1 && !a[pos-1]){
            R[pos-1]=pos-1;
            R[L[pos-1]]=pos-1;
        }
        if(pos+1<=n && !a[pos+1]){
            L[pos+1]=pos+1;
            L[R[pos+1]]=pos+1;
        }
        L[pos]=R[pos]=pos;
    }
}
void add(int pos){
    int x=a[pos];
    
    if(x){
        L[pos]=R[pos]=pos;
    }
    else{
        L[pos]=R[pos]=pos;
        if(pos-1>=1 && !a[pos-1]) L[pos]=L[pos-1];
        if(pos+1<=n && !a[pos+1]) R[pos]=R[pos+1];
        if(pos-1>=1 && !a[pos-1]){
            R[pos-1]=R[pos];
            R[L[pos-1]]=R[pos];
        }
        if(pos+1<=n && !a[pos+1]){
            L[pos+1]=L[pos];
            L[R[pos+1]]=L[pos];
        }
    }
}
int ask(int pos){
    if(pos==n || a[pos+1]) return pos+1;
    return R[pos+1]+1;
}

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
        int mid=(l+r)>>1, ret=0;
        if(L<=mid) ret=get(p<<1, l, mid, L, R);
        if(R>mid) ret|=get(p<<1|1, mid+1, r, L, R);
        return ret;
    }
}T1, T2, T3;
struct info{
    int l, r, st, len, ans;
}tr[N<<2];
int sz, sz2;
inline info operator +(info x, info y){
    info z;
    z.l=x.l; z.r=y.r;
    z.ans=max(x.ans, y.ans);
    if(x.st==0){
        z.st=y.st;
        z.len=y.len;
        return z;
    }
    if(x.len==1){
        if(a[y.l]!=2){
            z.st=y.st;
            z.len=y.len;
            return z;
        }
        if(y.l==y.r){
            z.st=x.st;
            z.len=2;
            return z;
        }
        if(a[y.l+1]!=1){
            z.st=y.st;
            z.len=y.len;
            return z;
        }
        if(y.l+1==y.r){
            z.st=x.st;
            z.len=3;
            return z;
        }
        sz=min(ask(y.l+1), y.r+1)-(y.l+1)-1;
        if(sz>x.st-3){
            z.st=y.st;
            z.len=y.len;
            return z;
        }
        if(y.l+2+sz-1==y.r){
            z.st=x.st;
            z.len=3+sz;
            return z;
        }
        if(sz!=x.st-3){
            z.st=y.st;
            z.len=y.len;
            return z;
        }
        if(a[y.l+2+sz]!=1){
            z.st=y.st;
            z.len=y.len;
            return z;
        }
        if(y.l+2+sz==y.r){
            z.st=x.st;
            z.len=3+sz+1;
            return z;
        }
        sz2=min(ask(y.l+2+sz), y.r+1)-(y.l+2+sz)-1;
        if(sz2>=3){
            z.ans=max(z.ans, x.st+4);
            z.st=y.st; z.len=y.len;
            return z;
        }
        if(y.l+2+sz+1+sz2-1==y.r){
            z.st=x.st;
            z.len=3+sz+1+sz2;
            return z;
        }
        z.st=y.st;
        z.len=y.len;
        return z;
    }
    if(x.len==2){
        if(a[y.l]!=1){
            z.st=y.st;
            z.len=y.len;
            return z;
        }
        if(y.l==y.r){
            z.st=x.st;
            z.len=3;
            return z;
        }
        sz=min(ask(y.l), y.r+1)-(y.l)-1;
        if(sz>x.st-3){
            z.st=y.st;
            z.len=y.len;
            return z;
        }
        if(y.l+1+sz-1==y.r){
            z.st=x.st;
            z.len=3+sz;
            return z;
        }
        if(sz!=x.st-3){
            z.st=y.st;
            z.len=y.len;
            return z;
        }
        if(a[y.l+1+sz]!=1){
            z.st=y.st;
            z.len=y.len;
            return z;
        }
        if(y.l+1+sz==y.r){
            z.st=x.st;
            z.len=3+sz+1;
            return z;
        }
        sz2=min(ask(y.l+1+sz), y.r+1)-(y.l+1+sz)-1;
        if(sz2>=3){
            z.ans=max(z.ans, x.st+4);
            z.st=y.st; z.len=y.len;
            return z;
        }
        if(y.l+1+sz+1+sz2-1==y.r){
            z.st=x.st;
            z.len=3+sz+1+sz2;
            return z;
        }
        z.st=y.st;
        z.len=y.len;
        return z;
    }
    if(x.len>=3&&x.len<=x.st){
        sz=min(ask(x.r), y.r+1)-(x.r)-1;
        if(sz>x.st-x.len){
            z.st=y.st;
            z.len=y.len;
            return z;
        }
        if(y.l+sz-1==y.r){
            z.st=x.st;
            z.len=x.len+sz;
            return z;
        }
        if(sz!=x.st-x.len){
            z.st=y.st;
            z.len=y.len;
            return z;
        }
        if(a[y.l+sz]!=1){
            z.st=y.st;
            z.len=y.len;
            return z;
        }
        if(y.l+sz==y.r){
            z.st=x.st;
            z.len=x.len+sz+1;
            return z;
        }
        sz2=min(ask(y.l+sz), y.r+1)-(y.l+sz)-1;
        if(sz2>=3){
            z.ans=max(z.ans, x.st+4);
            z.st=y.st; z.len=y.len;
            return z;
        }
        if(y.l+sz+1+sz2-1==y.r){
            z.st=x.st;
            z.len=x.len+sz+1+sz2;
            return z;
        }
        z.st=y.st;
        z.len=y.len;
        return z;
    }
    z.st=x.st; z.len=x.len;
    sz=min(ask(x.r), y.r+1)-(x.r)-1;
	if(sz+x.len>=x.st+4){
		z.ans=max(z.ans, x.st+4);
		z.st=y.st;
		z.len=y.len;
		return z;
	}
	if(y.l+sz-1==y.r){
		z.st=x.st;
		z.len=x.len+sz;
		return z;
	}
	z.st=y.st;
	z.len=y.len;
    return z;
}
void build(int p, int l, int r){
    if(l==r){
        tr[p].l=tr[p].r=l;
        if(a[l]>=3) tr[p].st=a[l], tr[p].len=1;
        else tr[p].st=0, tr[p].len=0;
        tr[p].ans=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    tr[p]=tr[p<<1]+tr[p<<1|1];
	// cout<<l<<' '<<r<<' '<<tr[p].st<<' '<<tr[p].len<<' '<<tr[p].ans<<endl;
}
void mdf(int p, int l, int r, int x){
    if(l==r){
        tr[p].l=tr[p].r=l;
        if(a[l]>=3) tr[p].st=a[l], tr[p].len=1;
        else tr[p].st=0, tr[p].len=0;
        tr[p].ans=0;
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) mdf(p<<1, l, mid, x);
    else mdf(p<<1|1, mid+1, r, x);
    tr[p]=tr[p<<1]+tr[p<<1|1];
}
info tem; bool flag;
void qry(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R){
        if(!flag) flag=1, tem=tr[p];
        else tem=tem+tr[p];
        return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid) qry(p<<1, l, mid, L, R);
    if(R>mid) qry(p<<1|1, mid+1, r, L, R);
}
void solve(){
	read(n); read(m);
    for(int i=1; i<=n; ++i){
		read(a[i]);
        L[i]=R[i]=i;
    }
    for(int i=1;i<=n;i++) add(i);
    if(n>=4){
        T1.build(1, 4, n, 1);
        T2.build(1, 4, n, 2);
    }
    if(n>=5){
        T3.build(1, 5, n, 3);
    }
    build(1, 1, n);
    int op, l, r; 
    while(m--){
		read(op); read(l); read(r);
        if(op==1){
            del(l);
            a[l]=r;
            add(l);
            if(n>=4){
                for(int i=max(l, 4); i<=l+3&&i<=n; ++i) T1.mdf(1, 4, n, i, 1);
                for(int i=max(l, 4); i<=l+3&&i<=n; ++i) T2.mdf(1, 4, n, i, 2);
            }
            if(n>=5){
                for(int i=max(l, 5); i<=l+4&&i<=n; ++i) T3.mdf(1, 5, n, i, 3);
            }
            mdf(1, 1, n, l);
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
            flag=0;
            qry(1, 1, n, l, r);
            ans=max(ans, tem.ans);
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