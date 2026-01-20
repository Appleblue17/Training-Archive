#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
#define int unsigned int
const int N=2e5+5;
const uint mod=(1<<20)-1;
int n, m;
uint C[20][N];
int len[N<<2];
uint f[N<<2][20], tag[N<<2];
void up(int p){
    for(int i=0; i<20; ++i){
        f[p][i]=0;
        for(int j=0; j<=i; ++j){
            f[p][i]+=f[p<<1][j]*f[p<<1|1][i-j];
        }
        f[p][i]&=mod;
    }
}
void build(int p, int l, int r){
    len[p]=r-l+1;
    if(l==r){
        scanf("%d", &f[p][1]);
        f[p][0]=1; f[p][1]--;
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    up(p);
}
uint g[20];
uint pw[20];
void apply(int p, int v){
    // cout<<"cur:"<<p<<"len:"<<len[p]<<endl;
    tag[p]+=v;
    pw[0]=1;
    for(int i=1; i<20; ++i) pw[i]=pw[i-1]*v;
    for(int i=0; i<20; ++i) g[i]=f[p][i];
    for(uint i=0; i<20; ++i){
        f[p][i]=0;
        for(int j=0; j<=i; ++j){
            if(i-j<=len[p]) f[p][i]+=pw[j]*C[j][len[p]-(i-j)]*g[i-j];
        }
        // cout<<f[p][i]<<' ';
        f[p][i]&=mod;
    }
    // cout<<endl;
}
void down(int p){
    if(tag[p]){
        apply(p<<1, tag[p]);
        apply(p<<1|1, tag[p]);
        tag[p]=0;
    }
}
void mdf(int p, int l, int r, int L, int R, int v){
    // if(l==r){
    if(L<=l&&r<=R){
        apply(p, v);
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(L<=mid) mdf(p<<1, l, mid, L, R, v);
    if(R>mid) mdf(p<<1|1, mid+1, r, L, R, v);
    up(p);
}
uint h[20];
void get(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R){
        for(int i=0; i<20; ++i) g[i]=h[i];
        for(int i=0; i<20; ++i){
            h[i]=0;
            for(int j=0; j<=i; ++j){
                h[i]+=g[j]*f[p][i-j];
            }
            h[i]&=mod;
        }
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(L<=mid) get(p<<1, l, mid, L, R);
    if(R>mid) get(p<<1|1, mid+1, r, L, R);
}
signed main(){
    scanf("%u%u", &n, &m);
    for(int i=0; i<=n; ++i) C[0][i]=1;
    for(int i=1; i<20; ++i){
        for(int j=i; j<=n; ++j){
            C[i][j]=(C[i][j-1]+C[i-1][j-1])&mod;
            // cout<<C[i][j]<<' ';
        }
        // cout<<endl;
    }
    build(1, 1, n);
    int op, l, r, v;
    while(m--){
        scanf("%u%u%u", &op, &l, &r);
        if(op==1){
            scanf("%u", &v);
            mdf(1, 1, n, l, r, v);
        }
        else{
            for(int i=1; i<20; ++i) h[i]=0;
            h[0]=1;
            get(1, 1, n, l, r);
            for(int i=1; i<20; ++i) h[0]+=h[i];
            printf("%u\n", h[0]&mod);
            // exit(0);
        }
    }
}
