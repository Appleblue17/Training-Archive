#include <bits/stdc++.h>
using namespace std;
#define Pii pair<int,int>
#define MP make_pair
const int N=1100,M=1e6+5;

int n,q;

int ID(int x,int y){
    return (x-1)*n+y;
}

int getf(int *f,int x){
    if(f[x]==x) return x;
    return f[x]=getf(f,f[x]);
}
void merge(int *f,int x,int y){
    int fx=getf(f,x),fy=getf(f,y);
    if(fx!=fy) f[fx]=fy;
}

int fa[M],ans[M];
void merge(int a,int b,int c,int d){
    if(!a || !b || !c || !d) return ;
    int x=getf(fa,ID(a,b)),y=getf(fa,ID(c,d));
    if(x==y) return ;
    // cout<<"merge "<<a<<","<<b<<" "<<c<<","<<d<<endl;
    
    fa[x]=y;
    ans[y] |= ans[x];
}

int fat[26][N],fat2[26][N*2];
vector<int> G[26][N];

bool check_parity(int c,int u){
    return getf(fat2[c],u)!=getf(fat2[c],u+n);
}

void upd(int c,int u,int v){
    int fu=getf(fat[c],u),fv=getf(fat[c],v);
    if(fu==fv){
        if(!check_parity(c,u) || !check_parity(c,v)){
            // cout<<"already not parity"<<endl;
            return; // already not parity
        }
        merge(fat2[c],u,v+n);
        merge(fat2[c],u+n,v);
        
        if(check_parity(c,u)){
            // cout<<"still parity"<<endl;
            return ; // still parity
        }
    }
    else{
        merge(fat2[c],u,v+n);
        merge(fat2[c],u+n,v);
    }
    
    int x=G[c][u].size()?G[c][u][0]:0,y=G[c][v].size()?G[c][v][0]:0;
    // cout<<" > "<<u<<" "<<v<<" "<<x<<" "<<y<<endl;
    
    if(x && y){
        merge(u,v,v,u);
        merge(u,v,x,u);
        merge(u,v,v,y);
        merge(u,v,x,y);
        
        merge(u,u,v,v);
        merge(u,u,x,v);
        merge(u,u,v,x);
    }
    else{
        // cout<<" go over"<<" "<<u<<" "<<v<<endl;
        for(int a=1;a<=n;a++){
            for(int b: G[c][a]){
                // cout<<" > "<<u<<" "<<v<<" "<<a<<" "<<b<<endl;
                merge(u,a,v,b);
                merge(a,u,b,v);
                
                merge(u,b,v,a);
                merge(b,u,a,v);
            }
        }
    }
    
    for(int a=1;a<=n;a++){
        int fa=getf(fat[c],a);
        if(fa!=a || fa==fu || fa==fv) continue;
        if(!G[c][a].size()) continue;
        int b=G[c][a][0];
        // cout<<" > mg "<<u<<" "<<v<<" "<<a<<" "<<b<<endl;
        
        merge(u,a,v,b);
        merge(a,u,b,v);
        
        merge(u,b,v,a);
        merge(b,u,a,v);
    }
    
    fat[c][fu]=fv;
    G[c][u].push_back(v);
    G[c][v].push_back(u);
}

signed main(){
    // freopen("L.txt","w",stdout);
    
    scanf("%d%d",&n,&q);
    
    for(int i=1;i<=n*n;i++) fa[i]=i;
    for(int i=1;i<=n;i++) ans[ID(i,i)]=1;
    
    for(int t=0;t<26;t++){
        for(int i=1;i<=n;i++) fat[t][i]=i;
        for(int i=1;i<=n*2;i++) fat2[t][i]=i;
    }
    
    while(q--){
        int typ,u,v;
        scanf("%d%d%d",&typ,&u,&v);
        if(typ==1){
            ans[getf(fa,ID(u,v))]=ans[getf(fa,ID(v,u))]=1;
            
            char c_; scanf(" %c",&c_);
            int c=c_-'a';
            
            // cout<<"link "<<u<<" "<<v<<" "<<c_<<endl;
            upd(c,u,v);
            // cout<<endl;
        }
        else{
            printf("%d\n",ans[getf(fa,ID(u,v))]);
        }
    }
    
}