#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n;
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
int st[22][N], lg[N];
int al[N], ar[N];
int dp[N];
int get(int l, int r){
    int t=lg[r-l+1];
    return max(st[t][l], st[t][r-(1<<t)+1]);
}
void solve(){
    scanf("%d", &n);
    for(int i=2; i<=n; ++i) lg[i]=lg[i>>1]+1;
    for(int i=1; i<=n; ++i){
        scanf("%d%d", &al[i], &ar[i]);
        st[0][i]=al[i];
    }
    for(int i=1; i<=lg[n]; ++i){
        for(int j=1; j+(1<<i)-1<=n; ++j){
            st[i][j]=max(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
    dp[n+1]=0;
    mdf(1, 1, n+1, n+1, 0);
    for(int i=n; i>=1; --i){
        int l=i+1, r=n, mid, ret=i;
        while(l<=r){
            mid=(l+r)>>1;
            if(get(i+1, mid)<=ar[i]){
                ret=mid; l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        dp[i]=get(1, 1, n+1, i+1, ret+1)+1;
        mdf(1, 1, n+1, i, dp[i]);
    }
    printf("%d\n", dp[1]);
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}