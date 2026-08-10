#include <bits/stdc++.h>
using namespace std;
const int N=1100,INF=1e9;
int n,num;
bool G[N][N];

int in[N];

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        G[u][v]=G[v][u]=1;
        in[u]++,in[v]++;
    }
    int mx=-1,rt;
    for(int u=1;u<=n;u++){
        if(in[u]>mx) mx=in[u],rt=u;
    }
    
    cout<<n-mx-1<<endl;
    for(int t=1;t<=n-mx-1;t++){
        for(int i=1;i<=n;i++){
            if(i==rt) continue;
            if(in[i]>1 && G[rt][i]){
                for(int j=1;j<=n;j++){
                    if(j!=rt && j!=i && G[i][j]){
                        printf("%d %d %d\n",rt,i,j);
                        assert(G[rt][i] && G[i][j] && !G[rt][j]);
                        G[i][j]=G[j][i]=0;
                        G[rt][j]=G[j][rt]=1;
                        in[i]--,in[rt]++;
                        break;
                    }
                }
                break;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(i!=rt) assert(G[i][rt]);
    }
}
