#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int T, n, dep[N], sm[N], cnt[N];
vector<int> g[N];
void dfs(int u){
    sm[u]=dep[u]=0;
    cnt[u]=1;
    priority_queue<int> d,s;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        dfs(v);
        d.push(-dep[v]);
        s.push(-cnt[v]);
        //printf("u=%lld,d add %lld,s add %lld\n",u,-dep[v]-1,-cnt[v]);
        sm[u] += sm[v];
        dep[u]=max(dep[u],dep[v]+1);
        cnt[u]+=cnt[v];
    }
    if(s.size() == 1){
        sm[u] += cnt[g[u][0]];
    }
    while(s.size()>1){
        int v = s.top();s.pop();int w = s.top();s.pop();
        sm[u] += -v-w;
        s.push(v+w);
    }
    while(d.size()>1){
        int v = d.top();d.pop();int w = d.top();d.pop();
        dep[u] = max(dep[u],-min(v,w)+1);
        d.push(min(v,w)-1);
    }
    //if(!d.empty())
    //    dep[u] = -d.top();
    //printf("u=%lld,dep=%lld,cnt=%lld,sm=%lld\n",u,dep[u],cnt[u],sm[u]);
}
void solve(){
    scanf("%lld", &n);
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
    for(int i=2;i<=n;i++){
        int x;
        scanf("%lld",&x);
        g[x].push_back(i);
    }
    //cout << '*' << endl;
    
    dfs(1);
    
    printf("%lld %lld\n",dep[1],sm[1]);
    
}
signed main(){
    scanf("%lld", &T);
    while(T--){
        solve();
    }
}