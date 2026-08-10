#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int T, n, m;
int a[N];
vector<int> e[N];
int cur[N];
vector<int> pat;
int indeg[N], outdeg[N];
void dfs(int u){
    for(int i=cur[u]; i<(int)e[u].size(); i=cur[u]){
        cur[u]++;
        dfs(e[u][i]);
    }
    pat.push_back(u);
}
void solve(){
    scanf("%d", &n);
    for(int i=0; i<=n; ++i){
        scanf("%d", &a[i]);
        e[i].clear(); cur[i]=0;
    }
    pat.clear();
    for(int i=1; i<=n; ++i){
        if(a[i-1]==0||a[i]<a[i-1]){
            printf("Impossible\n");
            return ;
        }
        for(int j=1; j<=a[i-1]; ++j){
            e[i-1].push_back(i);
            e[i].push_back(i-1);
        }
        a[i]-=a[i-1];
    }
    if(a[n]!=0){
        printf("Impossible\n");
        return ;
    }
    dfs(0);
    reverse(pat.begin(), pat.end());
    for(int i=1; i<(int)pat.size(); ++i){
        if(pat[i]>pat[i-1]) putchar('R');
        else putchar('L');
    }
    putchar('\n');
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
