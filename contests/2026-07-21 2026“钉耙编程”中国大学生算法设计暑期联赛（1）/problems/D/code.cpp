#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;

struct fr{
    int a,b;
    
    fr(int a=0,int b=0):a(a),b(b){};
    
    friend bool operator<(const fr& A,const fr& B){
        return A.a*B.b < A.b*B.a;
    }
};

int T,n,ans;
int a[N],b[N],f[N],siz[N],h[N],pt[N];

vector<int> g[N];

priority_queue<fr> q[N];





void dfs0(int u){
    siz[u]=1;h[u]=0;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        dfs0(v);
        siz[u]+=siz[v];
        if(siz[v]>siz[h[u]]){
            h[u]=v;
        }
    }
}

void dfs(int u){
    if(g[u].size()){
        dfs(h[u]);
        pt[u] = pt[h[u]];
    }
    else{
        pt[u] = u;
        q[pt[u]].push(fr(a[u],b[u]));
        //printf("pt[%lld]")
        return;
    }
    //printf("pt[%lld]=%lld\n",u,pt[u]);
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v == h[u])continue;
        dfs(v);
        while(!q[pt[v]].empty()){
            //printf("u=%lld,pq insert %lld,%lld\n",u,q[pt[v]].top().a,q[pt[v]].top().b);
            q[pt[u]].push(q[pt[v]].top());
            q[pt[v]].pop();
        }
        
        
    }
    fr tmp;
    tmp.a=a[u],tmp.b=b[u];
    while(!q[pt[u]].empty() && (tmp < q[pt[u]].top() || u==1)){
        //printf("u=%lld,cur: %lld,%lld. top: %lld,%lld. Merged. ans+=%lld\n",u,tmp.a,tmp.b,q[pt[u]].top().a,q[pt[u]].top().b,q[pt[u]].top().a*tmp.b);
        ans += q[pt[u]].top().a*tmp.b;
        tmp.a += q[pt[u]].top().a;
        tmp.b += q[pt[u]].top().b;
        q[pt[u]].pop();
    }
    q[pt[u]].push(tmp);
    
}

void solve(){
    ans=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        g[i].clear();
        while(!q[i].empty())q[i].pop();
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&b[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&f[i]);
        if(i != 1)g[f[i]].push_back(i);
    }
    dfs0(1);
    dfs(1);
    printf("%lld\n",ans);
}

signed main(){
    scanf("%lld", &T);
    while(T--){
        solve();
    }
}