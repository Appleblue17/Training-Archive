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
    double ans = 1.5*n;
    printf("%.4lf\n",ans);
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}