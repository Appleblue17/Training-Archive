#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
 
int n,a[N],b[N],ans[N];
vector <int> G[N];
 
int siz[N],son[N];
void dfs0(int u,int fa){
    siz[u]=1;
    int mx=0;
    for(int v: G[u]){
        if(v==fa) continue;
        dfs0(v,u);
        siz[u]+=siz[v];
        if(siz[v]>mx) mx=siz[v],son[u]=v; 
    }
}
 
int fat[N],val[N];
int getf(int x){
    if(x==fat[x]) return x;
    return fat[x]=getf(fat[x]);
}
 
bool buc[N];
int nw,sum;
void add(int u){
    int x=getf(u);
     
    sum-=(val[x]==0);
    if(!buc[u]){
        buc[u]=1;
        nw++;
        val[x]++;
    }
    else{
        buc[u]=0;
        nw--;
        val[x]--;
    }
    sum+=(val[x]==0);
}
 
void dfss(int u,int fa,int g){
    int A=a[u],B=b[u];
     
    if(!fat[A]) fat[A]=A,sum++;
    if(!fat[B]) fat[B]=B,sum++;
     
    add(A),add(B);
     
    int x=getf(A),y=getf(B);
    fat[x]=y;
    val[y]+=val[x];
     
    for(int v: G[u]){
        if(v==fa || v==g) continue;
        dfss(v,u,g);
    }
}
 
void clear(int u,int fa){
    int A=a[u],B=b[u];
    fat[A]=fat[B]=0;
    val[A]=val[B]=0;
    buc[A]=buc[B]=0;
     
    for(int v: G[u]){
        if(v==fa) continue;
        clear(v,u);
    }
}
 
void dfs(int u,int fa){
    for(int v: G[u]){
        if(v==fa || v==son[u]) continue;
        dfs(v,u);
        nw=sum=0;
        clear(v,u);
    }
    if(son[u]) dfs(son[u],u);
    dfss(u,fa,son[u]);
    // cout<<u<<": "<<nw<<" "<<sum<<endl;
    ans[u]=nw/2+sum;
}
 
signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
     
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
     
    dfs0(1,0);
     
    dfs(1,0);
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}
