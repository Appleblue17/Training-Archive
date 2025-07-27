#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
const int N=440,INF=1e18;
int T,n,a[N],s[N],ans[N];
 
vector <int> f[N][N],g[N][N];
 
int cal(int x){
    int t=0;
    while((1ll<<t)<x) t++;
    return t;
}
 
pair<int,int> p[N];
int id;
 
signed main() {
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
         
        for(int i=1;i<=n;i++){
            f[i][i].resize(1);
            g[i][i].resize(1);
            f[i][i][0]=g[i][i][0]=0;
        }
         
        for(int k=2;k<=n;k++){
            for(int l=1;l<=n-k+1;l++){
                int r=l+k-1;
                int val=cal(s[r]-s[l-1]);
                 
                id=0;
                for(int i=l;i<r;i++){
                    int l1=s[i]-s[l-1],l2=s[r]-s[i];
                    p[++id]=MP(abs(l1-l2),i);
                }
                sort(p+1,p+id+1);
                 
                f[l][r].clear();
                g[l][r].clear();
                 
                int mn=INF;
                for(int i=1;i<=id;i++){
                    int w=p[i].first,t=p[i].second;
                    int l1=s[t]-s[l-1],l2=s[r]-s[t];
                     
                    int x=upper_bound(f[l][t].begin(),f[l][t].end(),w)-f[l][t].begin()-1;
                    int y=upper_bound(f[t+1][r].begin(),f[t+1][r].end(),w)-f[t+1][r].begin()-1;
                     
                    f[l][r].push_back(w);
                    int tot=INF;
                     
                    if(x>=0 && y>=0 && g[l][t][x]<INF && g[t+1][r][y]<INF){
                        tot=g[l][t][x]+g[t+1][r][y]+min(l1,l2)*val;
                    }
                    if(k==n) ans[t]=tot;
                    tot=min(tot,mn);
                    mn=min(mn,tot);
                    g[l][r].push_back(tot);
                }
            }
        }
         
        for(int i=1;i<n;i++){
            if(ans[i]>=INF) printf("-1 ");
            else printf("%lld ",ans[i]);
        }
        printf("\n");
    }
     
}
