#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,mod=1e9+7;
int n;
int pw[N];
void gmod(int &x){
    x%=mod;
}

struct abc{
    int d[66],siz;
    int ins(int x){
        for(int t=60;t>=0;t--){
            if(!(x>>t & 1)) continue;
            if(!d[t]){
                d[t]=x;
                siz++;
                return t;
            }
            x^=d[t];
        }
        return -1;
    }
}F,G[N];

bool vis[N];

signed main(){
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*2%mod;
    
    cin>>n;
    for(int i=1;i<=n;i++){
        int x; scanf("%lld",&x);
        // int x=n;
        
        int ret=F.ins(x);
        if(ret!=-1){
            G[ret]=F;
            G[ret].d[ret]=0;
            G[ret].siz--;
        }
        for(int t=0;t<=60;t++){
            if(t!=ret && F.d[t] && !vis[t]){
                G[t].ins(x);
                if(G[t].siz==F.siz) vis[t]=1;
            }
        }
        
        int tot=(i-F.siz)*pw[i-F.siz-1]%mod;
        for(int t=0;t<=60;t++){
            if(!F.d[t]) continue;
            int sz=G[t].siz;
            if(vis[t]) sz=F.siz;
            gmod(tot+=pw[i-sz-1]);
        }
        // cout<<tot<<endl;
        printf("%lld\n",(pw[i]+mod-tot)%mod);
    }
    
}
