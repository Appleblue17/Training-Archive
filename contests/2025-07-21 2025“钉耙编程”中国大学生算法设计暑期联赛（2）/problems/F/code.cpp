#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int T;
int n, m;
int a[N], b[N], rka[N], rkb[N];
int p[N];
int ans[N];
int tr[N];
void add(int x){
    for(; x<=n; x+=(x&-x)) ++tr[x];
}
int get(int x){
    int ret=0;
    for(; x; x-=(x&-x)) ret+=tr[x];
    return ret;
}
void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d", &a[i]); rka[a[i]]=i;
        p[i]=i;
    }
    for(int i=1; i<=n; ++i){
        scanf("%d", &b[i]); rkb[b[i]]=i;
    }
    sort(p+1, p+n+1, [&](int x, int y){return rka[x]<rka[y];});
    for(int i=1; i<=n; ++i){
        ans[i]=rka[i]+rkb[i]-2;
        tr[i]=0;
    }
    
    for(int i=1; i<=n; ++i){
        ans[p[i]]-=get(rkb[p[i]]);
        add(rkb[p[i]]);
    }
    for(int i=1; i<=n; ++i){
        printf("%d ", ans[i]);
    }
    putchar('\n');
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}