#include<bits/stdc++.h>
using namespace std;
#define int long long
// const int N = 1e4+5;
// int sg[N],vis[N];
const int N=2e5+5;
int T, n, m;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("G.out", "w", stdout);
    // for(int i=1; i<N; ++i){
    //     memset(vis,0,sizeof(vis));
    //     for(int k=1; k<=i; ++k) if(__builtin_popcount(k)<=3){
    //         vis[sg[i-k]] = 1;
    //     }
    //     for(int k=0;k<N;k++){
    //         if(!vis[k]){
    //             sg[i] = k;
    //             break;
    //         }
    //     }
    //     printf("i=%d: %d\n",i,sg[i]);
    // }
    cin>>T;
    while(T--){
        cin>>n>>m;
        int sum=0;
        for(int i=1, x; i<=n; ++i){
            cin>>x;
            sum^=(x%((1ll<<(m+1))-1));
        }
        if(sum) printf("First\n");
        else printf("Second\n");
    }
}