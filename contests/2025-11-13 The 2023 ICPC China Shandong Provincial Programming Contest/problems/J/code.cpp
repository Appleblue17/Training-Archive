#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;

int n,m,q,V;

int fa[66][N];
int getf(int *fa,int x){
    if(fa[x]==x) return x;
    return fa[x]=getf(fa,fa[x]);
}

void merge(int *fa,int x,int y){
    x=getf(fa,x);
    y=getf(fa,y);
    if(x!=y) fa[x]=y;
}


signed main(){
    cin>>n>>m>>q>>V;
    V--;
    
    
    for(int t=0;t<=60;t++){
        for(int i=1;i<=n;i++) fa[t][i]=i;
    }
    
    for(int i=1;i<=m;i++){
        int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
        
        if(V<0){
            merge(fa[0],u,v);
        }
        else{
            for(int t=0;t<=60;t++){
                if((V>>t & 1)) continue;
                
                int a=(V>>(t+1)),b=(w>>(t+1));
                if((w>>t & 1) && (a & b)==a){
                    merge(fa[t],u,v);
                }
            }
        }
    }
    
    while(q--){
        int x,y; scanf("%lld%lld",&x,&y);
        bool fl=0;
        for(int t=0;t<=60 && !fl;t++){
            if(getf(fa[t],x)==getf(fa[t],y)) fl=1;
        }
        if(fl) printf("Yes\n");
        else printf("No\n");
    }
}
