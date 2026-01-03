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
const int N=1e5+5;
int T, n, m;
int a[N], w[N];
int p[N], q[N];
int pre[N], suf[N];
int tr[N];
void upd(int x, int v){
    for(; x<=n; x+=(x&-x)) tr[x]=max(tr[x], v);
}
int get(int x){
    int ret=0;
    for(; x; x-=(x&-x)) ret=max(ret, tr[x]);
    return ret;
}
// const int B=2;
const int B=400;
int rk[N];
int bid[N], lp[N], rp[N];
int calc(int id1, int l, int id2, int r){
    int it1=lp[id1], it2=lp[id2];
    int ret=0, mx=0;
    while(it1<=rp[id1]||it2<=rp[id2]){
        if(it1>rp[id1]){
            if(rk[it2]>=r){
                ret=max(ret, mx+q[rk[it2]]);
            }
            ++it2;
        }
        else if(it2>rp[id2]){
            if(rk[it1]<=l){
                mx=max(mx, p[rk[it1]]);
            }
            ++it1;
        }
        else if(a[rk[it1]]<=a[rk[it2]]){
            if(rk[it1]<=l){
                mx=max(mx, p[rk[it1]]);
            }
            ++it1;
        }
        else{
            if(rk[it2]>=r){
                ret=max(ret, mx+q[rk[it2]]);
            }
            ++it2;
        }
    }
    return ret;
}
int dp[400][400];
int F[400][N], G[400][N];
int bigrk[N];
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n); read(m);
    for(int i=1; i<=n; ++i){
        read(a[i]); read(w[i]); rk[i]=i; bigrk[i]=i;
    }
    for(int i=1; i<=n; ++i){
        p[i]=get(a[i])+w[i];
        upd(a[i], p[i]);
        pre[i]=max(pre[i-1], p[i]);
    }
    for(int i=1; i<=n; ++i) tr[i]=0;
    for(int i=n; i>=1; --i){
        q[i]=get(n+1-a[i])+w[i];
        upd(n+1-a[i], q[i]);
        suf[i]=max(suf[i+1], q[i]);
    }
    for(int i=1; i<=n; ++i){
        bid[i]=(i+B-1)/B;
    }
    for(int i=1; i<=bid[n]; ++i){
        lp[i]=rp[i-1]+1; rp[i]=rp[i-1]+B;
    }
    rp[bid[n]]=n;
    for(int i=1; i<=bid[n]; ++i){
        sort(rk+lp[i], rk+rp[i]+1, [&](int x, int y){return a[x]<a[y];});
    }
    sort(bigrk+1, bigrk+n+1, [&](int x, int y){return a[x]<a[y];});
    for(int i=1; i<bid[n]; ++i){
        for(int j=bid[n]; j>i; --j){
            dp[i][j]=max(dp[i-1][j], dp[i][j+1]);
            dp[i][j]=max(dp[i][j], calc(i, rp[i], j, lp[j]));
        }
    }
    for(int i=1; i<bid[n]; ++i){
        for(int j=rp[i]+1; j<=n; ++j) F[i][j]=F[i-1][j];
        int it1=lp[i], it2=1;
        int mx=0;
        while(it1<=rp[i]||it2<=n){
            if(it1>rp[i]){
                if(bigrk[it2]>rp[i]){
                    F[i][bigrk[it2]]=max(F[i][bigrk[it2]], mx+q[bigrk[it2]]);
                }
                ++it2;
            }
            else if(it2>n){
                mx=max(mx, p[rk[it1]]);
                ++it1;
            }
            else if(a[rk[it1]]<=a[bigrk[it2]]){
                mx=max(mx, p[rk[it1]]);
                ++it1;
            }
            else{
                if(bigrk[it2]>rp[i]){
                    F[i][bigrk[it2]]=max(F[i][bigrk[it2]], mx+q[bigrk[it2]]);
                }
                ++it2;
            }
        }
    }
    for(int i=bid[n]; i>1; --i){
        for(int j=1; j<lp[i]; ++j) G[i][j]=G[i+1][j];
        int it1=rp[i], it2=n;
        int mx=0;
        while(it1>=lp[i]||it2>=1){
            if(it1<lp[i]){
                if(bigrk[it2]<lp[i]){
                    G[i][bigrk[it2]]=max(G[i][bigrk[it2]], mx+p[bigrk[it2]]);
                }
                --it2;
            }
            else if(it2<1){
                mx=max(mx, q[rk[it1]]);
                --it1;
            }
            else if(a[rk[it1]]>=a[bigrk[it2]]){
                mx=max(mx, q[rk[it1]]);
                --it1;
            }
            else{
                if(bigrk[it2]<lp[i]){
                    G[i][bigrk[it2]]=max(G[i][bigrk[it2]], mx+p[bigrk[it2]]);
                }
                --it2;
            }
        }
    }
    int l, r;
    while(m--){
        read(l); read(r);
        // for(int i=1; i<=n; ++i) tr[i]=0;
        // int tem=0;
        // for(int i=1; i<=n; ++i){
        //     if(i>=l&&i<=r) continue;
        //     p[i]=get(a[i])+w[i];
        //     upd(a[i], p[i]);
        //     tem=max(tem, p[i]);
        // }
        
        if(l==1){
            // assert(tem==suf[r+1]);
            printf("%d\n", suf[r+1]);
            continue;
        }
        if(r==n){
            // assert(tem==pre[l-1]);
            printf("%d\n", pre[l-1]);
            continue;
        }
        int ans=max(pre[l-1], suf[r+1]);
        --l; ++r;
        ans=max(ans, dp[bid[l]-1][bid[r]+1]);
        ans=max(ans, calc(bid[l], l, bid[r], r));
        for(int i=lp[bid[l]]; i<=l; ++i) ans=max(ans, G[bid[r]+1][i]);
        for(int i=r; i<=rp[bid[r]]; ++i) ans=max(ans, F[bid[l]-1][i]);
        printf("%d\n", ans);
        // assert(tem==ans);
    }
	return 0;
}

