#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=5e5+5,mod=998244353;
int T,n,pw[N];
int a[N];
 
bool vis[N];
int p[N],pid;
 
vector <int> V;
signed main(){
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*2%mod;
     
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),vis[i]=0;
        pid=0;
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            int x=i,tot=0;
            while(!vis[x]){
                vis[x]=1;
                x=a[x];
                tot++;
            }
            p[++pid]=tot;
        }
         
        V.clear();
        int cnt=0;
        for(int i=1;i<=pid;i++){
            if(p[i]%2==1) V.push_back(p[i]);
            else{
                if(p[i]>2) cnt++;
            }
        }
        if(V.size()>2){
            printf("0\n");
            continue;
        }
        else if(V.size()==2){
            printf("%lld\n",1ll*V[0]*V[1]%mod*pw[cnt]%mod);
        }
        else{
            int tot=0;
            for(int i=1;i<=pid;i++){
                tot=(tot+1ll*(p[i]/2)*(p[i]/2)%mod*pw[cnt-(p[i]>2)]%mod)%mod;
            }
            printf("%lld\n",tot);
        }
         
    }
}
