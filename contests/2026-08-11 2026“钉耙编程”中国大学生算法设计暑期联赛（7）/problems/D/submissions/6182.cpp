#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=2e5+5,INF=1e9;

int T,n,m;

unordered_map <int,bool> F[N];
int deg[N];

vector <int> G[N];

const ull mask=mt19937_64(123)();
ull shift(ull x){
    x^=mask;
    x^=x<<13;
    x^=x>>7;
    x^=x<<17;
    x^=mask;
    return x;
}

ull has[N];
void dfs(int u,int fa){
    has[u]=1;
    for(int v: G[u]){
        if(v==fa) continue;
        dfs(v,u);
        has[u]+=shift(has[v]);
    }
}


int siz[N];
vector <int> C;
void dfs0(int u,int fa){
    siz[u]=1;
    int mx=0;
    for(int v: G[u]){
        if(v==fa) continue;
        dfs0(v,u);
        siz[u]+=siz[v];
        mx=max(mx,siz[v]);
    }
    mx=max(mx,m-siz[u]);
    if(mx<=m/2) C.push_back(u);
}

vector <int> ANS;
map <int,int> mp;

int main(){
    scanf("%d",&T);
    while(T--){
        ANS.clear();
        scanf("%d",&n);
        
        for(int i=1;i<=n;i++) G[i].clear(),F[i].clear(),deg[i]=0;
        C.clear();
        // cout<<"HELLO"<<endl;
        
        for(int i=1;i<n;i++){
            int u,v; scanf("%d%d",&u,&v);
            F[u][v]=1; F[v][u]=1;
            deg[u]++,deg[v]++;
        }
        
        for(int u=1;u<=n;u++){
            if(deg[u]!=2) continue;
            
            vector <int> tmp;
            for(auto e: F[u]){
                int v=e.first;
                if(e.second){
                    tmp.push_back(v);
                    F[v][u]=0;
                }
            }
            int x=tmp[0],y=tmp[1];
            F[x][y]=1,F[y][x]=1;
        }
        
        int rt=0; m=0;
        for(int u=1;u<=n;u++){
            if(deg[u]==2) continue;
            m++;
            rt=u;
            for(auto e: F[u]){
                int v=e.first;
                if(e.second) G[u].push_back(v);//,cout<<"add "<<u<<" "<<v<<endl;
            }
        }
        dfs0(rt,0);
        // cout<<"rt: "; for(int x: C) cout<<x<<" "; cout<<endl;
        
        
        if(C.size()==2){
            int x=C[0],y=C[1];
            dfs(x,y);
            dfs(y,x);
            
            ANS.push_back(1);
            if(has[x]==has[y]) ANS.push_back(2);
        }
        else{
            int rt=C[0];
            mp.clear();
            
            for(int v: G[rt]){
                dfs(v,rt);
                mp[has[v]]++;
            }
            
            int g=0;
            for(auto e: mp) g=__gcd(g,e.second);
            for(int i=1;i<=g;i++){
                if(g%i==0) ANS.push_back(i);
            }
        }
        printf("%d\n",ANS.size());
        for(int x: ANS) printf("%d ",x);
        printf("\n");
    }
    
}