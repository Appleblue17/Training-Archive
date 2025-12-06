#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=2200;
int T,n;
int G[N][N];
vector <int> F[N];


signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int x; scanf("%d",&x);
            G[i][j]=G[j][i]=x;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            int lca=G[1][i]^G[1][j]^G[i][j];
            
            if(lca==i){
                F[j].push_back(i);
                // cout<<" > "<<i<<" "<<j<<endl;
            }
        }
    }
    
    for(int u=2;u<=n;u++){
        int fa=1;
        for(int v: F[u]){
            if(F[v].size()>=F[fa].size()) fa=v;
        }
        cout<<u<<" "<<fa<<endl;
    }
    
    
}
