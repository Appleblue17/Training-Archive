#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,LIM=1e9;
int T,n,k,m;
int U[44][N],X[N],Y[N];
vector <int> G[N];

int V[44][N];
int r[N];

bool solve(int d){
    if(d>40) return 0;
    // cout<<"U"<<d<<": ";
    // for(int i=1;i<=n;i++) cout<<U[d][i]<<" "; cout<<endl; 
    
    bool fl=1;
    for(int i=1;i<=n && fl;i++) if(U[d][i]) fl=0;
    if(fl){
        for(int i=1;i<=n;i++) V[d][i]=0;
        return 1;
    }
    
    for(int i=1;i<=n;i++) r[i]=U[d][i]%k;
    for(int i=1;i<=n;i++){
        int tot=(U[d][i]-r[i])/k;
        for(int v: G[i]) tot-=r[v];
        U[d+1][i]=tot;
    }
    
    if(!solve(d+1)) return 0;
    
    for(int i=1;i<=n;i++) r[i]=U[d][i]%k;
    for(int i=1;i<=n;i++){
        V[d][i]=V[d+1][i]*k+r[i];
    }
    
    // cout<<"V"<<d<<": ";
    // for(int i=1;i<=n;i++) cout<<V[d][i]<<" "; cout<<endl; 
    return 1;
}

signed main(){
    scanf("%lld", &T);
    while(T--){
        scanf("%lld%lld%lld",&n,&k,&m);
        for(int i=1;i<=n;i++) G[i].clear();
        
        for(int i=1;i<=n;i++) scanf("%lld",&U[0][i]);
        for(int i=1;i<=m;i++) scanf("%lld",&X[i]);
        for(int i=1;i<=m;i++) scanf("%lld",&Y[i]);
        for(int i=1;i<=m;i++) G[X[i]].push_back(Y[i]);
        
        if(solve(0)){
            bool fl=1;
            for(int i=1;i<=n;i++) if(abs(V[0][i]>LIM)) fl=0;
            if(!fl) printf("No Solution\n");
            else{
                for(int i=1;i<=n;i++) printf("%lld ",V[0][i]);
                printf("\n");
            }
        }
        else printf("No Solution\n");
    }
}