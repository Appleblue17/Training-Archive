#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
// const int B=2;
const int B=2000;
int n, m, q, ans;
int a[N];
int bid[N];
int L[290], R[290];
int tr[290][N], rev[290][N], ver[290][N];
int mx[N<<2], mn[N<<2], tag[N<<2];
void build(int p, int l, int r){
    tag[p]=0;
    mx[p]=r; mn[p]=l;
    if(l==r){
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
}
void apply(int x, int v){
    tag[x]+=v; mn[x]+=v; mx[x]+=v;
}
void down(int p){
    if(tag[p]){
        apply(p<<1, tag[p]);
        apply(p<<1|1, tag[p]);
        tag[p]=0;
    }
}
void up(int p){
    mn[p]=min(mn[p<<1], mn[p<<1|1]);
    mx[p]=max(mx[p<<1], mx[p<<1|1]);
}
void mdf1(int p, int l, int r, int k){
    if(mx[p]<k){
        apply(p, 1);
        return ;
    }
    if(mn[p]>=k){
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    mdf1(p<<1, l, mid, k);
    mdf1(p<<1|1, mid+1, r, k);
    up(p);
}
void mdf2(int p, int l, int r, int k){
    if(mn[p]>k){
        apply(p, -1);
        return ;
    }
    if(mx[p]<=k){
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    mdf2(p<<1, l, mid, k);
    mdf2(p<<1|1, mid+1, r, k);
    up(p);
}
void dfs(int p, int l, int r, int o){
    if(l==r){
        tr[o][l]=mn[p]+tag[p/2];
        return ;
    }
    int mid=(l+r)>>1;
    tag[p<<1]+=tag[p]; tag[p<<1|1]+=tag[p];
    dfs(p<<1, l, mid, o); dfs(p<<1|1, mid+1, r, o);
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test2.out","w",stdout);
	read(n); read(m); read(q);
    for(int i=1; i<=m; ++i){
        read(a[i]);
        bid[i]=(i-1)/B+1;
    }
    for(int i=1; i<=bid[m]; ++i){
        L[i]=R[i-1]+1; R[i]=R[i-1]+B;
    }
    R[bid[m]]=m;
    for(int i=1; i<=bid[m]; ++i){
        build(1, 0, n-1);
        for(int j=L[i]; j<=R[i]; ++j){
            mdf1(1, 0, n-1, a[j]);
            mdf2(1, 0, n-1, a[j]);
        }
        dfs(1, 0, n-1, i);
        for(int j=n-1; j>tr[i][n-1]; --j) rev[i][j]=n;
        for(int j=n-1; j>=0; --j) rev[i][tr[i][j]]=j;
        for(int j=tr[i][0]-1; j>=0; --j) ver[i][j]=-1;
        for(int j=0; j<n; ++j) ver[i][tr[i][j]]=j;
        for(int j=tr[i][n-1]+1; j<n; ++j) ver[i][j]=n-1;
        // for(int j=0; j<n; ++j) cout<<tr[i][j]<<' ';
        // cout<<endl;
        // for(int j=0; j<n; ++j) cout<<rev[i][j]<<' ';
        // cout<<endl;
    }
    int t, l, r, p;
    while(q--){
        read(t); read(l); read(r); read(p);
        t=(t+ans)%2; l=(l+ans)%m+1; r=(r+ans)%m+1; p=(p+ans)%n;
        if(l>r) swap(l, r);
        if(t==0){
            if(bid[l]==bid[r]){
                for(register int i=l; i<=r; ++i){
                    if(p>a[i]) --p;
                    else if(p<a[i]) ++p;
                }
                printf("%d\n", ans=p);
                continue;
            }
            for(register int i=l; i<=R[bid[l]]; ++i) {
                if(p>a[i]) --p;
                else if(p<a[i]) ++p;
            }
            for(register int i=bid[l]+1; i<bid[r]; ++i) p=tr[i][p];
            for(register int i=L[bid[r]]; i<=r; ++i) {
                if(p>a[i]) --p;
                else if(p<a[i]) ++p;
            }
            printf("%d\n", ans=p);
            continue;
        }
        int lp=p, rp=p;
        if(bid[l]==bid[r]){
            for(int i=r; i>=l&&lp<=rp; --i){
                if(lp<=a[i]) --lp;
                else ++lp;
                if(rp>=a[i]) ++rp;
                else --rp;
            }
            lp=max(lp, 0); rp=min(rp, n-1);
            printf("%d\n", ans=max(0, rp-lp+1));
            continue;
        }
        for(register int i=r; i>=L[bid[r]]&&lp<=rp; --i){
            if(lp<=a[i]) --lp;
            else ++lp;
            if(rp>=a[i]) ++rp;
            else --rp;
        }
        lp=max(lp, 0); rp=min(rp, n-1);
        for(register int i=bid[r]-1; i>bid[l]&&lp<=rp; --i){
            lp=rev[i][lp]; rp=ver[i][rp];
        }
        for(register int i=R[bid[l]]; i>=l&&lp<=rp; --i){
            if(lp<=a[i]) --lp;
            else ++lp;
            if(rp>=a[i]) ++rp;
            else --rp;
        }
        lp=max(lp, 0); rp=min(rp, n-1);
        printf("%d\n", ans=max(0, rp-lp+1));
    }
	return 0;
}
