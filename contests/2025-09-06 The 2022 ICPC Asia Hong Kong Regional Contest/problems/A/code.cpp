#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int T, n;
int p[N];
vector<int> e[N];
int f[N];
void dfs(int x){
    if(e[x].size()==0) {
        f[x]=1; return ;
    }
    if(e[x].size()==1){
        dfs(e[x][0]);
        f[x]=f[e[x][0]];
        return ;
    }
    int mx=0, mx2=0;
    for(auto y:e[x]){
        dfs(y); 
        if(f[y]>mx){
            mx2=mx; mx=f[y];
        }
        else if(f[y]>mx2){
            mx2=f[y];
        }
    }
    f[x]=max(mx, mx2+1);
}
void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) e[i].clear();
    for(int i=1; i<=n; ++i){
        scanf("%d", &p[i]);
        if(i!=1) e[p[i]].push_back(i);
    }
    dfs(1);
    printf("%d\n", f[1]);
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
