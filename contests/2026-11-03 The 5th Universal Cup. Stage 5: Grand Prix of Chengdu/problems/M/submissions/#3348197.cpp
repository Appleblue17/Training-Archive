#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n;
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
        tr[p]=min(tr[p<<1], tr[p<<1|1]);
    }
    int get(int p, int l, int r, int L, int R){
        if(L<=l&&r<=R){
            return tr[p];
        }
        int mid=(l+r)>>1, ret=1e9;
        if(L<=mid) ret=get(p<<1, l, mid, L, R);
        if(R>mid) ret=min(ret, get(p<<1|1, mid+1, r, L, R));
        return ret;
    }
}T1, T2;
int al[N], ar[N];
int dp[N];
void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d%d", &al[i], &ar[i]);
        T2.mdf(1, 1, n, i, -al[i]);
    }
    dp[n+1]=0;
    T1.mdf(1, 1, n+1, n+1, 0);
    for(int i=n; i>=1; --i){
        int l=i+1, r=n, mid, ret=i;
        while(l<=r){
            mid=(l+r)>>1;
            if(-T2.get(1, 1, n, i+1, mid)<=ar[i]){
                ret=mid; l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        dp[i]=T1.get(1, 1, n+1, i+1, ret+1)+1;
        T1.mdf(1, 1, n+1, i, dp[i]);
    }
    printf("%d\n", dp[1]);
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}