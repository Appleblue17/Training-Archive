#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=1e6+5,mod=998244353;

ull T,n,m,L,R,X;
ull a[N][2],sm[N*4][2],mk[N*4][2];



ull rd(){
    ull tot=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}

void build(int rt,int le,int ri){
    if(le == ri){
        sm[rt][0] = a[le][0];
        sm[rt][1] = a[le][1];
        mk[rt][0]=mk[rt][1]=0;
        return;
    }
    int mi = (le+ri)/2;
    build(rt*2,le,mi);
    build(rt*2+1,mi+1,ri);
    sm[rt][0] = sm[rt*2][0]+sm[rt*2+1][0];
    sm[rt][1] = sm[rt*2][1]+sm[rt*2+1][1];
    mk[rt][0]=mk[rt][1]=0;
}

void pushdown(ull rt,ull le,ull ri,ull o){
    mk[rt*2][o] += mk[rt][o];
    mk[rt*2+1][o] += mk[rt][o];
    sm[rt*2][o] += (ri-le+1)*mk[rt][o];
    sm[rt*2+1][o] += (ri-le+1)*mk[rt][o];
    mk[rt][o] = 0;
}

void mdf(ull rt,ull le,ull ri,ull o){
    printf("mdf %llu %llu %llu %llu\n",rt,le,ri,o);
    if(le >= L && ri <= R){
        mk[rt][o] += X;
        sm[rt][o] += X*(ri-le+1);
        return;
    }
    pushdown(rt,le,ri,o);
    int mi = (le+ri)/2;
    if(mi >= L)mdf(rt*2,le,mi,o);
    if(mi < R)mdf(rt*2+1,mi+1,ri,o);
    sm[rt][0] = sm[rt*2][0]+sm[rt*2+1][0];
    sm[rt][1] = sm[rt*2][1]+sm[rt*2+1][1];
}



ull query(int rt,int le,int ri,int o){
    printf("query %d %d %d %d\n",rt,le,ri,o);
    if(le >= L && ri <= R){
        printf("query %d %d %d %d return %lld\n",rt,le,ri,o,sm[rt][o]);
        return sm[rt][o];
    }
    pushdown(rt,le,ri,o);
    int mi = (le+ri)/2;
    ull ret=0;
    if(mi >= L)ret += query(rt*2,le,mi,o);
    if(mi < R)ret += query(rt*2+1,mi+1,ri,o);
    printf("query %d %d %d %d return %lld\n",rt,le,ri,o,ret);
    return ret;
}

void solve(){
    n=rd();m=rd();
    for(int i=1;i<=n;i++){
        a[i][0]=rd();a[i][1]=rd();
    }
    build(1,1,n);
    for(ull t=1;t<=m;t++){
        int typ;
        typ=rd();L=rd();R=rd();if(typ == 1)X = rd();
        if(typ == 1){
            mdf(1,1,n,1);
            X = -X*(t);
            mdf(1,1,n,0);
        }
        else{
            printf("%llu\n",query(1,1,n,0) + query(1,1,n,1)*(t));
        }
    }
}

signed main(){
    T=rd();
    while(T--){
        solve();
    }
}

query 1 1 4 0
query 1 1 4 0 return 6
query 1 1 4 1
query 1 1 4 1 return 6
12
mdf 1 1 4 1
mdf 2 1 2 1
mdf 1 1 4 0
mdf 2 1 2 0
query 1 1 4 0
query 2 1 2 0
query 2 1 2 0 return -1
query 3 3 4 0
query 6 3 3 0
query 6 3 3 0 return 1
query 3 3 4 0 return 1
query 1 1 4 0 return 0
query 1 1 4 1
query 2 1 2 1
query 2 1 2 1 return 5
query 3 3 4 1
query 6 3 3 1
query 6 3 3 1 return 1
query 3 3 4 1 return 1
query 1 1 4 1 return 6
18
query 1 1 4 0
query 2 1 2 0
query 5 2 2 0
query 5 2 2 0 return -2
query 2 1 2 0 return -2
query 3 3 4 0
query 3 3 4 0 return 3
query 1 1 4 0 return 1
query 1 1 4 1
query 2 1 2 1
query 5 2 2 1
query 5 2 2 1 return 3
query 2 1 2 1 return 3
query 3 3 4 1
query 3 3 4 1 return 3
query 1 1 4 1 return 6
25