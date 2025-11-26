#include <bits/stdc++.h>
using namespace std;
const int N=1005;
typedef long long ll;
int T,n,m;
ll a[N][N];
void solve(){
    ll ans=0;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            scanf("%lld", &a[i][j]);
        }
    }
    for(int i=1; i<n; ++i){
        vector<int> vec;
        for(int j=m; j>=1; --j){
            if(a[i][j]>0){
                while(!vec.empty()){
                    int x=vec.back(); vec.pop_back();
                    int w=min(-a[i][x], a[i][j]);
                    a[i][x]+=w; a[i][j]-=w;
                    if(a[i][x]<0) vec.push_back(x);
                    if(a[i][j]==0) break;
                }
            }
            else if(a[i][j]<0){
                vec.push_back(j);
            }
        }
        for(int j=1; j<=m; ++j){
            if(a[i][j]>0){
                a[i+1][j]+=a[i][j];
            }
            else{
                ans-=a[i][j];
            }
        }
    }
    vector<int> vec;
    for(int j=m; j>=1; --j){
        if(a[n][j]>0){
            while(!vec.empty()){
                int x=vec.back(); vec.pop_back();
                int w=min(-a[n][x], a[n][j]);
                a[n][x]+=w; a[n][j]-=w;
                if(a[n][x]<0) vec.push_back(x);
                if(a[n][j]==0) break;
            }
        }
        else if(a[n][j]<0){
            vec.push_back(j);
        }
    }
    for(int j=1; j<=m; ++j){
        ans+=abs(a[n][j]);
    }
    printf("%lld\n", ans);
}
signed main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
    
}


