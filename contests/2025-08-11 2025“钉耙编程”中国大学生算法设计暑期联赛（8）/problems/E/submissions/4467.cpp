#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int T, n;
int mx[N];
int dep[N];
int fa[N];
void solve(){
    scanf("%lld", &n);
    for(int i=1; i<=n+2; ++i) mx[i]=0;
    dep[1]=0; fa[1]=1;
    scanf("%lld", &dep[2]); fa[2]=2;
    int idx=2, ed=2;
    int tp, x, z;
    int dt=0, dt2=0;
    for(int i=1; i<=n; ++i){
        scanf("%lld", &tp);
        if(tp==1){
            ++idx;
            scanf("%lld", &z);
            fa[idx]=idx; dep[idx]=dep[ed]+z;
            ed=idx;
            dt2=0;
        }
        else if(tp==2){
            scanf("%lld%lld", &x, &z);
            ++idx;
            fa[idx]=fa[x];
            dep[idx]=dep[x]+z;
            mx[fa[idx]]=max(mx[fa[idx]], dep[idx]-dep[fa[idx]]);
            if(mx[fa[idx]]==dep[fa[idx]]){
                dt=max(dt, dep[fa[idx]]);
            }
            if(mx[fa[idx]]==dep[ed]-dep[fa[idx]]){
                dt2=max(dt2, dep[ed]-dep[fa[idx]]);
            }
        }
        else{
            // cout<<dep[ed]<<' '<<dt<<' '<<dt2<<endl;
            printf("%lld\n", dep[ed]-dt-dt2);
        }
    }
}
signed main(){
    scanf("%lld", &T);
    while(T--){
        solve();
    }
}