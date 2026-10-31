#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=5e5+5,mod=998244353;
int T,n;
int A[N],B[N],C[N];
vector <int> V[N];

bool vis[N],pvis[N];
pair <int,int> ANS[N];
int p[N],id;


void dfs(int u){
    for(int x: V[u]){
        if(!pvis[x]){
            int v=0;
            if(!vis[A[x]]) v=A[x];
            if(!vis[B[x]]) v=B[x];
            if(!vis[C[x]]) v=C[x];
            
            if(!v) continue;
            pvis[x]=1;
            vis[v]=1;
            ANS[x]={u,v};
            dfs(v);
        }
    }
}


bool solve(){
    int u=B[n],pos=n;
    id=0;
    
    while(1){
        p[id++]=u;
        vis[u]=1; pvis[pos]=1;
        // cout<<u<<" "<<pos<<": ";
        
        vector<int> P;
        for(int x: V[u]){
            if(x!=pos) P.push_back(x);
        }
        // for(int x: P) cout<<x<<" "; cout<<endl;
        // assert(P.size()==2);
        
        int v=0,npos=0;
        
        for(int t: P){
            int s=vis[A[t]]+vis[B[t]]+vis[C[t]];
            if(s==2){
                if(!vis[A[t]]) v=A[t],npos=t;
                if(!vis[B[t]]) v=B[t],npos=t;
                if(!vis[C[t]]) v=C[t],npos=t;
                if(v) break;
            }
        }
        
        if(!v){
            for(int t: P){
                int s=vis[A[t]]+vis[B[t]]+vis[C[t]];
                if(s==1){
                    if(!vis[A[t]]) v=A[t],npos=t;
                    if(!vis[B[t]]) v=B[t],npos=t;
                    if(!vis[C[t]]) v=C[t],npos=t;
                    if(v) break;
                }
            }
        }
        
        if(!v && !npos) return 0;
        // cout<<" ! "<<npos<<": "<<u<<" "<<v<<endl;
        ANS[npos]={u,v};
        if(v==A[n]) break;
        u=v; pos=npos;
    }
    
    // cout<<"OK"<<endl;
    
    for(int i=0;i<id;i++){
        dfs(p[i]);
    }
    for(int i=1;i<=n;i++) if(!vis[i]) return 0;
    return 1;
}


signed main(){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) V[i].clear(),vis[i]=0,pvis[i]=0,ANS[i]={0,0};
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&A[i],&B[i],&C[i]);
            if(i<n){
                V[A[i]].push_back(i);
                V[B[i]].push_back(i);
                V[C[i]].push_back(i);
            }
            
        }
        
        if(!solve()) printf("NO\n");
        else{
            printf("YES\n");
            for(int i=1;i<n;i++) printf("%d %d\n",ANS[i].first,ANS[i].second);
            printf("-1 -1\n");
        }
    }
}