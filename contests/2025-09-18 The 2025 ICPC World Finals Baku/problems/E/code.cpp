#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5,M=4e5+5,INF=1e9;

int n,m;

int fa[M];
int getf(int x){
    if(x==fa[x]) return x;
    return fa[x]=getf(fa[x]);
}

vector <int> S[M];
set <int> R[M];

vector <int> in[N],out[N];
ll ans;
ll cal(int x){
    return 1ll*x*(x-1)/2;
}

int merge(int x,int y){
    if(x==y) return x;
    
    if(S[x].size()<S[y].size()) swap(x,y);
    ans-=cal(R[x].size());
    ans-=cal(R[y].size());
    
    for(int t: R[y]) R[x].insert(t);
    ans+=cal(R[x].size());
    
    for(int t: S[y]) S[x].push_back(t);
    fa[y]=x;
    return x;
}

int main(){
    // freopen("1.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) fa[i]=i;
    
    for(int t=1;t<=m;t++){
        int u,v; scanf("%d%d",&u,&v);
        
        S[t]={t};
        R[t].insert(u),R[t].insert(v);
        ans++;
        
        int y=t;
        for(int x: in[v]){
            x=getf(x);
            y=merge(y,x);
        }
        for(int x: out[u]){
            x=getf(x);
            y=merge(y,x);
        }
        
        in[v].push_back(y);
        out[u].push_back(y);
        
        printf("%lld\n",ans);
    }
}
