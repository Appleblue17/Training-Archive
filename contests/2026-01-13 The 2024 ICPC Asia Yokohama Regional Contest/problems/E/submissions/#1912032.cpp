#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=55;
int n,m;
char S[N][N];
int fx[4][2]={{0,-1},{0,1},{-1,0},{1,0}};

bool vis[N][N];
int dfs(int x,int y){
    vis[x][y]=1;
    
    char c=S[x][y];
    if(c>='0' && c<='9') return c-'0';
    
    vector <int> V;
    for(int i=0;i<4;i++){
        int nx=x+fx[i][0],ny=y+fx[i][1];
        if(nx>=1 && nx<=n && ny>=1 && ny<=m && !vis[nx][ny] && S[nx][ny]!='.'){
            int ret=dfs(nx,ny);
            V.push_back(ret);
        }
    }
    sort(V.begin(),V.end());
    if(c=='#' || c=='P') return V[0];
    if(c=='+') return V[1]+V[0];
    if(c=='-') return V[1]-V[0];
    if(c=='*') return V[1]*V[0];
    if(c=='/') return V[1]/V[0];
}



signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("\n%s",S[i]+1);
    
    int stx,sty;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(S[i][j]=='P') stx=i,sty=j;
        }
    }
    
    cout<<dfs(stx,sty);
    
}
