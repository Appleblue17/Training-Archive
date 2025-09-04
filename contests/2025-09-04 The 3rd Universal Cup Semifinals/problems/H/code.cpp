#include<bits/stdc++.h>
using namespace std;
const int N=4005;
int T, n;
vector<int> e[N], g[N];
int col[N];
vector<pair<int, int> > vec;
void dfs(int x){
    bool flag=0;
    for(auto y:e[x]){
        dfs(y);
        if(col[y]==0) flag=1;
    }
    col[x]=flag;
    if(col[x]) vec.push_back(make_pair(1, x));
    else vec.push_back(make_pair(x, 1));
}
void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) e[i].clear();
    for(int i=2, x; i<=n; ++i){
        scanf("%d", &x);
        e[x].push_back(i);
    }
    vec.clear();
    dfs(1);
    printf("Yes\n");
    printf("%d\n", vec.size());
    for(auto t:vec){
        printf("%d %d\n", t.first, t.second);
    }
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
