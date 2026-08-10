#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
#define int long long
const int N=6e5+5,INF=1e18;

void no(){
    printf("impossible");
    exit(0);
}

int n,m,k,stx,sty;
vector < pair<int,int> > G[N];
bool vis[N];

int col[N],A[N],B[N],id;
int mn[N],mx[N];
void dfs(int u){
    if(vis[u]) return ;
    vis[u]=1;
    
    int c=col[u];
    if(A[u]>0) mn[c]=max(mn[c],-B[u]);
    else mx[c]=min(mx[c],B[u]);
    
    for(pair<int,int> e: G[u]){
        int v=e.first,w=e.second;
        int nA=-A[u],nB=w-B[u];
        if(vis[v]){
            if(nA!=A[v] || nB!=B[v]) no();
            continue;
        }
        col[v]=c,A[v]=nA,B[v]=nB;
        dfs(v);
    }
}

signed main(){
    scanf("%lld%lld%lld%lld%lld",&n,&m,&k,&stx,&sty);
    
    for(int i=1;i<=k;i++){
        int x,y,w;
        scanf("%lld%lld%lld",&x,&y,&w); y+=n;
        G[x].push_back(MP(y,w));
        G[y].push_back(MP(x,w));
    }
    
    for(int u=1;u<=n+m;u++){
        if(vis[u]) continue;
        col[u]=++id;
        mn[id]=-INF,mx[id]=INF;
        A[u]=1,B[u]=0;
        dfs(u);
        
        if(mn[id]>mx[id]) no();
    }
    
    // for(int i=1;i<=n+m;i++){
    //     cout<<i<<": "<<col[i]<<" "<<A[i]<<" "<<B[i]<<endl;
    // }
    // for(int i=1;i<=id;i++) cout<<" col "<<i<<": "<<mn[i]<<" "<<mx[i]<<endl;
    
    sty+=n;
    int c1=col[stx],c2=col[sty];
    if(c1!=c2){
        int s1=0,s2=0;
        if(A[stx]>0) s1=mn[c1]*A[stx]+B[stx];
        else s1=mx[c1]*A[stx]+B[stx];
        
        if(A[sty]>0) s2=mn[c2]*A[sty]+B[sty];
        else s2=mx[c2]*A[sty]+B[sty];
        cout<<s1+s2;
    }
    else{
        int sA=A[stx]+A[sty],sB=B[stx]+B[sty];
        
        if(sA>0) cout<<sA*mn[c1]+sB;
        else cout<<sA*mx[c1]+sB;
    }
    
}
