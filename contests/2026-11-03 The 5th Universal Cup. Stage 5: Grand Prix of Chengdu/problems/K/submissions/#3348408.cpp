#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int T, n;
int a[N];
int dis[N];
bool check(int lim){
    int mn=a[1]-lim, mx=a[1]+lim;
    for(int i=2; i<=n; ++i){
        int lb=mx-dis[i], rb=mn+dis[i];
        int cl=a[i]-lim, cr=a[i]+lim;
        if(lb<cl&&rb>cr) return false;
        if(lb<cl){
        // cout<<"???"<<endl;
            mx=cr;
            // if(rb<cl) cout<<"!!!"<<endl;
            mn=max(rb, cl);
            continue;
        }
        if(rb>cr){
        // cout<<"???"<<endl;
            mn=cl;
            // if(lb>cr) cout<<"!!!"<<endl;
            mx=min(lb, cr);
            continue;
        }
        mn=cl; mx=cr;
    }
    return true;
}
void solve(){
    scanf("%lld", &n);
    for(int i=1; i<=n; ++i) scanf("%lld", &a[i]);
    for(int i=2; i<=n; ++i) scanf("%lld", &dis[i]);
    int lv=0, rv=2e9, mid, ret=-1;
    while(lv<=rv){
        mid=(lv+rv)>>1;
        if(check(mid)){
            ret=mid; rv=mid-1;
        }
        else{
            lv=mid+1;
        }
    }
    printf("%lld\n", ret);
}
signed main(){
    int T;scanf("%lld",&T);while(T--){
        solve();
    }
}