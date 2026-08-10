#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5,INF=1e9;

int T,n;
int A[N],B[N],C[N];
int v[N],vid;
int r[N],rid;

bool ans1[N],ans2[N];

vector < pair<int,int> > G[N];
void add(int u,int v,int w){
    G[u].push_back({v,w});
    if(v!=u) G[v].push_back({u,w});
}

bool vis[N];
int dfn[N],q[N],qid;
int fat[N],fate[N];

void dfs(int u,int fa){
    vis[u]=1;
    q[++qid]=u; dfn[u]=qid;
    
    for(pair<int,int> e: G[u]){
        int v=e.first;
        if(v==fa || vis[v]) continue;
        fat[v]=u; fate[v]=e.second;
        dfs(v,u);
    }
}

pair <int,int> mp[N]; int mpid;

// Euler
int cur[N];
bool viss[N];
void dfss(int u){
    for(int i=cur[u];i<(int)G[u].size();i=cur[u]){
        cur[u]++;
        int v=G[u][i].first,num=G[u][i].second;
        if(viss[num]) continue;
        viss[num]=1;
        
        int x=mp[num].first,y=mp[num].second;
        // cout<<" find "<<num<<": "<<x<<", "<<y<<" | "<<u<<" "<<v<<endl;
        
        if(C[x]==u) ans2[x]=0,ans2[y]=1;
        else ans2[x]=1,ans2[y]=0;
        dfss(v);
    }
}




void addans1(int x,int u){
    if(A[x]==u) ans1[x]=0;
    else if(B[x]==u) ans1[x]=1;
    else{
        // cout<<"  ??? "<<x<<" "<<u<<"  |  "<<A[x]<<" "<<B[x]<<endl;
        assert(0);
    }
}

bool vise[N];

bool solve(){
    for(int i=1;i<=n;i++) vise[i]=0;
    for(int i=1;i<=vid;i++) G[i].clear(),vis[i]=0;
    for(int i=1;i<=n;i++) add(A[i],B[i],i);
    
    mpid=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        qid=0;
        dfs(i,0);
        
        // cout<<"start "<<i<<endl;
        
        bool fl=0;
        for(int t=qid;t>=1;t--){
            int u=q[t];
            
            // cout<<"tree: "<<u<<" "<<fat[u]<<endl;
            
            vector <int> V;
            for(pair<int,int> e: G[u]){
                int v=e.first,num=e.second;
                if(!vise[num] && v!=fat[u]) V.push_back(num);
            }
            if(t>1 && !fl) V.push_back(fate[u]);
            fl=0;
            
            // cout<<u<<": "; for(int x: V) cout<<x<<" "; cout<<endl;
            
            while(V.size()>=2){
                int x=V.back(); V.pop_back();
                int y=V.back(); V.pop_back();
                // cout<<"   link "<<x<<" "<<y<<endl;
                
                mp[++mpid]={x,y};
                vise[x]=vise[y]=1;
                addans1(x,u); addans1(y,u);
            }
        }
        
    }
    if(mpid*2!=n) return 0;
    
    // cout<<"mapping "<<mpid<<endl;
    // for(int i=1;i<=mpid;i++) cout<<mp[i].first<<" "<<mp[i].second<<endl;
    // return 1;
    for(int i=1;i<=rid;i++) G[i].clear(),vis[i]=0,cur[i]=0;
    for(int i=1;i<=mpid;i++) viss[i]=0;
    
    for(int i=1;i<=mpid;i++){
        int u=mp[i].first,v=mp[i].second;
        add(C[u],C[v],i);
    }
    
    for(int i=1;i<=rid;i++){
        if(vis[i]) continue;
        // cout<<"path from "<<i<<": "<<endl;
        dfss(i);
        // cout<<endl;
    }
    
    return 1;
}

signed main(){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        vid=rid=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&A[i],&B[i],&C[i]);
            v[++vid]=A[i];
            v[++vid]=B[i];
            r[++rid]=C[i];
        }
        
        sort(v+1,v+vid+1);
        vid=unique(v+1,v+vid+1)-v-1;
        
        sort(r+1,r+rid+1);
        rid=unique(r+1,r+rid+1)-r-1;
        
        for(int i=1;i<=n;i++){
            A[i]=lower_bound(v+1,v+vid+1,A[i])-v;
            B[i]=lower_bound(v+1,v+vid+1,B[i])-v;
            C[i]=lower_bound(r+1,r+rid+1,C[i])-r;
        }
        // for(int i=1;i<=n;i++) cout<<A[i]<<" "<<B[i]<<" "<<C[i]<<endl;
        
        
        if(!solve()) printf("-1\n");
        else{
            for(int i=1;i<=n;i++) putchar(ans1[i]+'0'); printf("\n");
            for(int i=1;i<=n;i++) putchar(ans2[i]+'0'); printf("\n");
            
        }
    }
}