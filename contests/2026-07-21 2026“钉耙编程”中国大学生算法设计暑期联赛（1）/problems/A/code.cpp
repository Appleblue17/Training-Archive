#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n, m, x, y, T;
int a[N], b[N];
void solve(){
    scanf("%d%d%d%d", &x, &y, &n, &m);
    long long mnx=x, mxx=x, mny=y, mxy=y;
    for(int i=1; i<=n; ++i){
        scanf("%d", &a[i]);
        mnx=min(mnx, (long long)a[i]+x);
        mxx=max(mxx, (long long)a[i]+x);
    }
    for(int j=1; j<=m; ++j){
        scanf("%d", &b[j]);
        mny=min(mny, (long long)b[j]+y);
        mxy=max(mxy, (long long)b[j]+y);
    }
    printf("%lld\n", max(max(mnx*mxy, mxx*mny), max(mnx*mny, mxx*mxy)));
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}