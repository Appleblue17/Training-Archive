#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull N=1e6+5,mod=998244353;

ull T,n,m,L,R,X;
ull a[N][2],sm[N*4][2],mk[N*4][2];



ull rd(){
    ull tot=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}

void build(ull rt,ull le,ull ri){
    if(le == ri){
        sm[rt][0] = a[le][0];
        sm[rt][1] = a[le][1];
        mk[rt][0]=mk[rt][1]=0;
        return;
    }
    ull mi = (le+ri)/2;
    build(rt*2,le,mi);
    build(rt*2+1,mi+1,ri);
    sm[rt][0] = sm[rt*2][0]+sm[rt*2+1][0];
    sm[rt][1] = sm[rt*2][1]+sm[rt*2+1][1];
    mk[rt][0]=mk[rt][1]=0;
}

void pushdown(ull rt,ull le,ull ri,ull o){
    mk[rt*2][o] += mk[rt][o];
    mk[rt*2+1][o] += mk[rt][o];
    ull mi = (le+ri)/2;
    sm[rt*2][o] += (mi-le+1)*mk[rt][o];
    sm[rt*2+1][o] += (ri-mi)*mk[rt][o];
    mk[rt][o] = 0;
}

void mdf(ull rt,ull le,ull ri,ull o){
    //printf("mdf %llu %llu %llu %llu\n",rt,le,ri,o);
    if(le >= L && ri <= R){
        mk[rt][o] += X;
        sm[rt][o] += X*(ri-le+1);
        return;
    }
    pushdown(rt,le,ri,o);
    ull mi = (le+ri)/2;
    if(mi >= L)mdf(rt*2,le,mi,o);
    if(mi < R)mdf(rt*2+1,mi+1,ri,o);
    sm[rt][0] = sm[rt*2][0]+sm[rt*2+1][0];
    sm[rt][1] = sm[rt*2][1]+sm[rt*2+1][1];
}



ull query(ull rt,ull le,ull ri,ull o){
    //printf("query %d %d %d %d\n",rt,le,ri,o);
    if(le >= L && ri <= R){
        //printf("query %d %d %d %d return %lld\n",rt,le,ri,o,sm[rt][o]);
        return sm[rt][o];
    }
    pushdown(rt,le,ri,o);
    ull mi = (le+ri)/2;
    ull ret=0;
    if(mi >= L)ret += query(rt*2,le,mi,o);
    if(mi < R)ret += query(rt*2+1,mi+1,ri,o);
    //printf("query %d %d %d %d return %lld\n",rt,le,ri,o,ret);
    return ret;
}

void solve(){
    n=rd();m=rd();
    for(ull i=1;i<=n;i++){
        a[i][0]=rd();a[i][1]=rd();
    }
    build(1,1,n);
    for(ull t=1;t<=m;t++){
        ull typ;
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