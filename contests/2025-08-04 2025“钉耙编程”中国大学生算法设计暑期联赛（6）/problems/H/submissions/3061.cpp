#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1100,M=1e4+5,INF=1e18;
int T,n,m,k;
int a[N];

int f[M],g[M];

void dfs(int dep,int mac,int sum){
    if(dep==m){
        f[mac]=max(f[mac],sum);
        return ;
    }
    dfs(dep+1,mac,sum);
    dfs(dep+1,mac | (1<<dep),sum+a[dep]);
}


signed main(){
    cin>>T;
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&k);
        k=min(k,m);
        
        for(int mac=0;mac<(1<<m);mac++) f[mac]=g[mac]=-INF;
        
        for(int t=1;t<=n;t++){
            for(int j=0;j<m;j++) scanf("%lld",&a[j]);
            dfs(0,0,0);
        }
        
        // for(int mac=0;mac<(1<<m);mac++) cout<<f[mac]<<" "; cout<<endl;
        
        g[0]=0;
        for(int t=1;t<=k;t++){
            for(int mac=(1<<m)-1;mac>=0;mac--){
                for(int S=mac;;S=(S-1) & mac){
                    g[mac]=max(g[mac],g[S]+f[mac^S]);
                    // cout<<mac<<" "<<S<<" "<<(mac^S)<<endl;
                    if(!S) break;
                }
            }
        }
        
        // for(int mac=0;mac<(1<<m);mac++) cout<<g[mac]<<" "; cout<<endl;
        
        printf("%lld\n",g[(1<<m)-1]);
    }
    
}