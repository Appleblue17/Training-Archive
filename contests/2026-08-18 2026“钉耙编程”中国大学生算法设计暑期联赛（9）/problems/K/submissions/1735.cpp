#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=5500,mod=998244353;
int T,n;
vector <int> G[N];

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1;
    }
    return tot;
}

int v[N],id;

int lca[N][N];
int dep[N];
vector <int> sub[N];

void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    
    sub[u].clear(); sub[u].push_back(u);
    bool fl=1;
    for(int v: G[u]){
        if(v==fa) continue;
        fl=0;
        dfs(v,u);
        for(int x: sub[v]) sub[u].push_back(x);
    }
    if(fl) v[++id]=u;
    
    for(int v1: G[u]){
        if(v1==fa) continue;
        for(int v2: G[u]){
            if(v2==fa || v2==v1) continue;
            for(int x: sub[v1])
                for(int y: sub[v2])
                    lca[x][y]=u;
        }
    }
}

struct abc{
    int x,y;
};
bool operator <(abc X,abc Y){
    return 1ll*X.x*Y.y<1ll*Y.x*X.y;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) G[i].clear();
        id=0;
        
        for(int i=1;i<n;i++){
            int u,v; cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        dep[0]=-1;
        dfs(1,0);
        
        abc ans={0,1};
        for(int i=1;i<=id;i++){
            int x=v[i];
            abc tot={1,0};
            
            for(int j=1;j<=id;j++){
                if(i==j) continue;
                int y=v[j],lc=lca[x][y];
                
                // cout<<x<<" "<<y<<" "<<lc<<endl;
                
                int d1=dep[x]-dep[lc],d2=dep[y]-dep[lc];
                abc val={d2,d1+d2};
                if(val<tot) tot=val;
            }
            if(ans<tot) ans=tot;
        }
        // cout<<ans.x<<"/"<<ans.y<<endl;
        cout<<1ll*ans.x*ksm(ans.y,mod-2)%mod<<endl;
    }
    
    
}