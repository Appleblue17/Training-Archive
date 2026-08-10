#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+6;
int n, m, c;
ll a[N];
int main() {
    scanf("%d%d%d", &n, &m, &c);
    ll ans=0;
    for(int i=1; i<=n; ++i){
        scanf("%lld", &a[i]);
    }
    priority_queue<ll> p1, p2;
    for(int i=1; i<=m; ++i){
        p1.push((-a[i]-1ll*c*(m-i)));
        ans+=a[i];
    }
    for(int i=m+1; i<=n; ++i){
        p2.push(a[i]-1ll*c*(i-m));
    }
    while(true){
        if(p1.empty()) break;
        if(p2.empty()) break;
        if(-p1.top()>=p2.top()) break;
        ans+=p2.top()+p1.top();
        p1.pop(); p2.pop();
    }
    printf("%lld\n", ans);
}
