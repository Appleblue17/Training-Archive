#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5, B=510;
int n, m;
ll a[N], tag[N], sum[N];
vector<int> fac[N];
int gd[B+5][B+5];
signed main(){
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%lld", &a[i]);
    for(int i=1; i<=n; ++i){
        for(int j=i; j<=n; j+=i){
            fac[j].push_back(i);
            sum[i]+=a[j];
        }
    }
    for(int i=1; i<=B; ++i){
        for(int j=0; j<B; ++j){
            gd[i][j]=__gcd(i, j);
        }
    }
    int tp, x, y;
    while(m--){
        scanf("%d%d", &tp, &x);
        if(tp==1){
            scanf("%d", &y);
            if(x<=B) tag[x]+=y;
            else{
                for(int i=x; i<=n; i+=x) a[i]+=y;
            }
            for(int i=1; i<=B; ++i) sum[i]+=1ll*y*((n/x)/(i/gd[i][x%i]));
        }
        else if(tp==2){
            scanf("%d", &y);
            for(auto t:fac[x]) a[t]+=y, sum[t]+=1ll*y*fac[x/t].size();
        }
        else if(tp==3){
            // cout<<tp<<' ';
            if(x<=B){
                printf("%lld\n", sum[x]);
                continue;
            }
            ll ans=0;
            for(int i=x; i<=n; i+=x) ans+=a[i];
            for(int i=1; i<=B; ++i){
                ans+=tag[i]*((n/i)/(x/gd[i][x%i]));
            }
            printf("%lld\n", ans);
        }
        else{
            // cout<<tp<<' ';
            ll ans=0;
            for(auto d:fac[x]) ans+=a[d]+tag[d]*fac[x/d].size();
            printf("%lld\n", ans);
        }
    }
}