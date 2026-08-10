#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5; 
const int inf=1e18;
int T, n, m;
struct MAT{
    int a[4][4];
    MAT(){for(int i=0; i<4; ++i) for(int j=0; j<4; ++j) a[i][j]=-inf;}
    void set(int x){
        a[0][0]=0; a[1][0]=0; a[2][0]=0; a[3][0]=0; a[0][1]=x; a[1][2]=x; a[2][3]=x;
    }
};
inline MAT operator *(MAT x, MAT  y){
    MAT ret;
    for(int k=0; k<4; ++k){
        for(int i=0; i<4; ++i) if(x.a[i][k]>=0){
            for(int j=0; j<4; ++j) ret.a[i][j]=max(ret.a[i][j], x.a[i][k]+y.a[k][j]);
        }
    }
    return ret;
}
int a[N];
MAT tr[N<<2];
void build(int p, int l, int r){
    tr[p]=tr[0];
    if(l==r){
        tr[p].set(a[l]);
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    tr[p]=tr[p<<1]*tr[p<<1|1];
}
void mdf(int p, int l, int r, int x){
    if(l==r){
        tr[p].set(a[l]);
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) mdf(p<<1, l, mid, x);
    else mdf(p<<1|1, mid+1, r, x);
    tr[p]=tr[p<<1]*tr[p<<1|1];
}
MAT f[5];
void calc(){
    f[0]=f[4];
    f[0].a[0][0]=a[2];
    f[0].a[0][1]=a[3];
    f[0].a[0][2]=a[2]+a[3];
    f[0].a[0][3]=-inf;
    
    f[1]=f[4];
    f[1].a[0][0]=a[1];
    f[1].a[0][1]=a[1]+a[3];
    f[1].a[0][2]=-inf;
    f[1].a[0][3]=-inf;
    
    f[2]=f[4];
    f[2].a[0][0]=a[1]+a[2];
    f[2].a[0][1]=-inf;
    f[2].a[0][2]=-inf;
    f[2].a[0][3]=-inf;
    
    f[3]=f[4];
    f[3].a[0][0]=-inf;
    f[3].a[0][1]=-inf;
    f[3].a[0][2]=-inf;
    f[3].a[0][3]=a[1]+a[2]+a[3];
    
    f[1]=f[1]*tr[1];
    f[2]=f[2]*tr[1];
    f[3]=f[3]*tr[1];
    f[0]=f[0]*tr[1];
    int ans=0;
    ans=max(ans, f[0].a[0][0]);
    ans=max(ans, f[0].a[0][1]);
    ans=max(ans, f[0].a[0][2]);
    ans=max(ans, f[0].a[0][3]);
    ans=max(ans, f[1].a[0][0]);
    ans=max(ans, f[1].a[0][1]);
    ans=max(ans, f[1].a[0][2]);
    ans=max(ans, f[2].a[0][0]);
    ans=max(ans, f[2].a[0][1]);
    ans=max(ans, f[3].a[0][0]);
    printf("%lld\n", ans);
}
void solve(){
    scanf("%lld%lld", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%lld", &a[i]);
    build(1, 4, n);
    calc();
    while(m--){
        int x; scanf("%lld", &x);
        scanf("%lld", &a[x]);
        if(x>3) mdf(1, 4, n, x);
        calc();
    }
}
signed main(){
    // freopen("2.txt","w",stdout);
    scanf("%lld", &T);
    while(T--){
        solve();
    }
}