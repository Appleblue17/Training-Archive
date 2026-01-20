#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1505, M=205, mod=1e9+7;
typedef long long ll;
int n, m, q;
int b[N];
int a[N][M];
int f[15][N][M], G[15][N][M];
void build(int d, int l, int r){
    if(l==r){
        return ;
    }
    int mid=(l+r)>>1;
    build(d+1, l, mid); build(d+1, mid+1, r);
    for(int i=0; i<=m; ++i) f[d][mid][i]=a[mid][i];
    for(int i=mid-1; i>=l; --i){
        for(int j=0; j<=m; ++j){
            for(int k=j; k>=0; --k){
                f[d][i][j]=((ll)f[d][i+1][k]*a[i][j-k]+f[d][i][j])%mod;
            }
        }
    }
    for(int i=0; i<=m; ++i){
        for(int j=i; j>=0; --j){
            G[d][mid+1][i]=((ll)a[mid+1][j]*b[i-j]+G[d][mid+1][i])%mod;
        }
    }
    for(int i=mid+2; i<=r; ++i){
        for(int j=0; j<=m; ++j){
            for(int k=j; k>=0; --k){
                G[d][i][j]=((ll)G[d][i-1][k]*a[i][j-k]+G[d][i][j])%mod;
            }
        }
    }
}
int qry(int d, int l, int r, int L, int R){
    int mid=(l+r)>>1;
    if(R<mid) return qry(d+1, l, mid, L, R);
    if(L>mid+1) return qry(d+1, mid+1, r, L, R);
    int ret=0;
    if(R==mid){
        for(int i=0; i<=m; ++i) ret=((ll)f[d][L][i]*b[m-i]+ret)%mod;
        return ret;
    }
    if(L==mid+1){
        return G[d][R][m];
    }
    for(int i=0; i<=m; ++i){
        ret=((ll)f[d][L][i]*G[d][R][m-i]+ret)%mod;
    }
    return ret;
}
int main(){
    scanf("%d%d%d", &n, &m, &q);
    for(int i=m; i>=0; --i) scanf("%d", &b[i]);
    for(int i=1; i<=n; ++i){
        for(int j=0; j<=m; ++j) scanf("%d", &a[i][j]), a[i][j]%=mod;
    }
    build(0, 1, n);
    int l, r, ans;
    while(q--){
        scanf("%d%d", &l, &r);
        if(l==r){
            ans=0;
            for(int i=0; i<=m; ++i) ans=((ll)a[l][i]*b[m-i]+ans)%mod;
            printf("%d\n", ans);
            continue;
        }
        printf("%d\n", qry(0, 1, n, l, r));
    }
}
