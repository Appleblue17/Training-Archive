#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=310000;
int n,m,u[N],v[N],col[N],fa[N],vis[N];
const int p = 998244353;

int findfa(int x){
    if(fa[x]==x)return x;
    else return fa[x]=findfa(fa[x]);
}

void solve(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        fa[i]=i;vis[i]=0;
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u[i],&v[i],&col[i]);
        if(col[i]==1){
            int x = findfa(u[i]);
            int y = findfa(v[i]);
            if(x != y)fa[x]=y;
        }
    }
    int ans=1;
    for(int i=1;i<=m;i++){
        if(col[i]==0){
            //int x = findfa(u[i]);
            //int y = findfa(v[i]);
            ans++;
        }
    }
    for(int i=1;i<=n;i++){
        vis[findfa(i)]=1;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])ans--;
    }
    printf("%d\n",ans);
    
}
signed main(){
    int T;cin >> T;
    while(T--){
        solve();
    }
}
