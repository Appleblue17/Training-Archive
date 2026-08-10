#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e7+5;
typedef long long ll;

bool vis[M];
int pr[M],pid,mu[M];

void init(int lim){
    for(int i=2;i<=lim;i++){
        if(!vis[i]){
            pr[++pid]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=pid && i*pr[j]<=lim;j++){
            vis[i*pr[j]]=1;
            if(i%pr[j]) mu[i*pr[j]]=-mu[i];
            else break;
        }
    }
    mu[1]=1;
}
int n, m;
vector<int> e[N];
int a[N];
bool sta[N];
ll ans;
int sz[N];
void dfs(int x, int fa){
    if(sta[x]==1) sz[x]=1, ++ans;
    else sz[x]=0;
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y, x);
        if(sta[x]==0) continue;
        ans+=1ll*sz[x]*sz[y];
        sz[x]+=sz[y];
    }
}
void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) e[i].clear();
    for(int i=1, x, y; i<n; ++i){
        scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    vector<int> bin;
    for(int i=1; i*i<=m; ++i){
        if(m%i==0) {
            bin.push_back(i);
            if(i*i!=m) bin.push_back(m/i);
        }
    }
    ll res=0;
    for(auto d:bin){
        for(int i=1; i<=n; ++i){
            if(a[i]>m) {sta[i]=0; continue;}
            if(d%a[i]==0) sta[i]=1;
            else sta[i]=0;
        }
        ans=0;
        dfs(1, 0);
        // cout<<d<<' '<<ans<<' '<<mu[m/d]<<endl;
        res+=(ll)mu[m/d]*ans;
    }
    printf("%lld\n", res);
}

signed main(){
    init(M-5);
    // for(int i=1;i<=20;i++) cout<<mu[i]<<" ";
    // return 0;
    
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    
}