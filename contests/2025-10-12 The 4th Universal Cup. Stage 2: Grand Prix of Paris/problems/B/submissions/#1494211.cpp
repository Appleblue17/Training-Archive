#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,M=550,K=6,INF=1e18;

int T,n,k;
int a[N],b[N];

int f[K][M],g[K][M];

signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]);
        
        for(int i=0;i<=k;i++){
            for(int j=0;j<=100*i;j++){
                f[i][j]=g[i][j]=-INF;
            }
        }
        
        f[0][0]=g[0][0]=0;
        for(int t=1;t<=n;t++){
            if(a[t]<=100){
                for(int i=k-1;i>=0;i--){
                    for(int j=0;j<=100*i;j++){
                        if(f[i][j]<0) continue;
                        f[i+1][j+a[t]]=max(f[i+1][j+a[t]],f[i][j]+b[t]);
                    }
                }
            }
            else{
                for(int i=k-1;i>=0;i--){
                    for(int j=0;j<=100*i;j++){
                        if(g[i][j]<0) continue;
                        g[i+1][j+b[t]]=max(g[i+1][j+b[t]],g[i][j]+a[t]);
                    }
                }
            }
        }
        
        // for(int i=0;i<=k;i++){
        //     for(int j=0;j<=10;j++) cout<<f[i][j]<<" ";
        //     cout<<endl;
        // }
        
        int ans=0;
        for(int t=0;t<=k;t++){
            for(int i=0;i<=100*t;i++){
                if(f[t][i]<0) continue;
                for(int j=0;j<=100*(k-t);j++){
                    if(g[k-t][j]<0) continue;
                    ans=max(ans,(i+g[k-t][j])*(f[t][i]+j));
                }
            }
        }
        printf("%lld\n",ans);
    }
}
