#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=25,M=2e7+5,INF=1e9;
 
int n,m;
pair <int,int> p[N];
int w[N],mp[N];
int G[N],in[N];
 
int pre[M],dp[M];
 
inline int lbt(int mac){
    return __lg(mac & (-mac));
}
 
signed main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>p[i].first,p[i].second=i;
    sort(p,p+n);
    for(int i=0;i<n;i++) w[i]=p[i].first,mp[p[i].second]=i;
     
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v); u--,v--;
        u=mp[u],v=mp[v];
        G[u] |= 1<<v;
        in[v] |= 1<<u;
    }
     
    for(int mac=0;mac<(1<<n);mac++){
        int tmp=((1<<n)-1)^mac,tot=0;
        for(int S=tmp,i=lbt(S);S;S^=1<<i,i=lbt(S)){
            if((in[i] & mac)==in[i]) tot |= 1<<i;
        }
        pre[mac]=tot;
    }
     
    for(int mac=0;mac<(1<<n);mac++) dp[mac]=INF;
    dp[0]=0;
    for(int mac=0;mac<(1<<n);mac++){
        if(dp[mac]>=INF) continue;
        // cout<<mac<<" "<<pre[mac]<<endl;
         
        int tot=0;
        for(int S=pre[mac],i=lbt(S);S;S^=1<<i,i=lbt(S)){
            tot |= 1<<i;
            dp[mac | tot]=min(dp[mac | tot],dp[mac]+w[i]);
        }
    }
     
    cout<<dp[(1<<n)-1];
}
