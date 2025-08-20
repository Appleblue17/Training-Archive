#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5, mod=998244353;
typedef long long ll;
ll fpow(ll x, ll y){
    ll ret=1;
    while(y){
        if(y&1) ret=ret*x%mod;
        x=x*x%mod; y>>=1;
    }
    return ret;
}
int n, m;
int pw[N], ipw[N];
struct mat{
    int a[4][4];
    mat(){memset(a, 0, sizeof a);}
}tr[N<<2], emp;
inline mat operator *(mat x, mat y){
    mat ret;
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            for(int k=0; k<4; ++k){
                ret.a[i][j]=(1ll*x.a[i][k]*y.a[k][j]+ret.a[i][j])%mod;
            }
        }
    }
    return ret;
}
void build(int p, int l, int r){
    if(l==r){
        int x; scanf("%d", &x); --x;
        if(x==0){
            tr[p].a[0][0]=tr[p].a[1][2]=tr[p].a[2][1]=tr[p].a[3][3]=1;
            tr[p].a[1][3]=tr[p].a[2][3]=pw[l];
        }
        if(x==1){
            tr[p].a[0][2]=tr[p].a[1][1]=tr[p].a[2][0]=tr[p].a[3][3]=1;
            tr[p].a[0][3]=tr[p].a[2][3]=pw[l];
        }
        if(x==2){
            tr[p].a[0][1]=tr[p].a[1][0]=tr[p].a[2][2]=tr[p].a[3][3]=1;
            tr[p].a[0][3]=tr[p].a[1][3]=pw[l];
        }
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    tr[p]=tr[p<<1|1]*tr[p<<1];
}
void mdf(int p, int l, int r, int x, int v){
    if(l==r){
        tr[p]=emp;
        if(v==0){
            tr[p].a[0][0]=tr[p].a[1][2]=tr[p].a[2][1]=tr[p].a[3][3]=1;
            tr[p].a[1][3]=tr[p].a[2][3]=pw[l];
        }
        if(v==1){
            tr[p].a[0][2]=tr[p].a[1][1]=tr[p].a[2][0]=tr[p].a[3][3]=1;
            tr[p].a[0][3]=tr[p].a[2][3]=pw[l];
        }
        if(v==2){
            tr[p].a[0][1]=tr[p].a[1][0]=tr[p].a[2][2]=tr[p].a[3][3]=1;
            tr[p].a[0][3]=tr[p].a[1][3]=pw[l];
        }
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) mdf(p<<1, l, mid, x, v);
    else mdf(p<<1|1, mid+1, r, x, v);
    tr[p]=tr[p<<1|1]*tr[p<<1];
}
void get(int p, int l, int r, int L, int R, mat& tem){
    if(L<=l&&r<=R){
        tem=tem*tr[p];
        return ;
    }
    int mid=(l+r)>>1;
    if(R>mid) get(p<<1|1, mid+1, r, L, R, tem);
    if(L<=mid) get(p<<1, l, mid, L, R, tem);
}
int main(){
    pw[0]=1;
    for(int i=1; i<N; ++i) pw[i]=(pw[i-1]<<1)%mod;
    ipw[N-1]=fpow(pw[N-1], mod-2);
    for(int i=N-2; i>=0; --i) ipw[i]=(ipw[i+1]<<1)%mod;
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    while(m--){
        char s[2]; int x, y;
        scanf("%s", s);
        scanf("%d%d", &x, &y);
        if(s[0]=='s'){
            mat tem;
            tem.a[0][0]=1;
            get(1, 1, n, x, y, tem);
            printf("%lld\n", 1ll*tem.a[0][3]*ipw[x]%mod);
        }
        else{
            --y;
            mdf(1, 1, n, x, y);
        }
    }
}