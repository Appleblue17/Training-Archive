// #pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int T, n;
int dp[N][2];
vector<int> vec;
vector< pair<int,int> > e[N];

void dfs(int x, int fa){
    // for(auto tmp:e[x]){
    for(int i=0;i<(int)e[x].size();i++){
        int y=e[x][i].first;
        if(y==fa) continue;
        vec.push_back(y);
        // cout<<vec.size()<<endl;
        dfs(y, x);
        // cout<<y<<" "<<dp[y][0]<<endl;
    }
}

void solve(){
    cin>>n;
    for(int i=1; i<=n; ++i) e[i].clear();
    for(int i=1, x, y; i<n; ++i){
        scanf("%d%d",&x,&y);
        e[x].push_back({y,i});
        e[y].push_back({x,i});
    }
    dfs(1, 0);
}
int main(){
    // freopen("tst.out", "w", stdout);
    cin>>T;
    while(T--){
        solve();
    }
}