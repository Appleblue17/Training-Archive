#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=110000,INF=1e9;
int T,a[N],t[N],n,f[N][3];
vector<int> g[N];

void dfs(int u,int fa){
    //printf("dfs %lld\n",u);
    int mx=0,mx2=0,mxid=-1,sum2=0;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v == fa)continue;
        dfs(v,u);
        //printf("u=%lld,=%lld\n",u,f[v][1] - f[v][2]);
        //printf("u=%lld,mx=%lld,mx2=%lld,mxid=%lld\n",u,mx,mx2,mxid);
        if(f[v][1] - f[v][2] > mx){
            mx2 = mx;
            mx = f[v][1]-f[v][2];
            mxid = v;
        }
        else if(f[v][1] - f[v][2] > mx2){
            mx2 = f[v][1]-f[v][2];
            
        }
        sum2 += f[v][2];
        //printf("u=%lld,mx=%lld,mx2=%lld,mxid=%lld\n",u,mx,mx2,mxid);
    }
    //printf("u=%lld,mx=%lld,mx2=%lld,mxid=%lld\n",u,mx,mx2,mxid);
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v == fa)continue;
        f[u][2] = max(f[u][2],f[v][0]+sum2-f[v][2]);
        if(t[v]==3){
            if(mxid == v){
                f[u][2] = max(f[u][2],f[v][0]+mx2+sum2-f[v][2]);
            }
            else{
                f[u][2] = max(f[u][2],f[v][0]+mx+sum2-f[v][2]);
            }
        }
    }
    //cout << mxid << endl;
    f[u][0]=f[u][2]+a[u];
    f[u][1] = sum2 + a[u];
    //printf("f[%lld]=%lld,%lld,%lld\n",u,f[u][0],f[u][1],f[u][2]);
}

void solve(){
    //cout << '*' << endl;
    dfs(1,0);
    //cout << '*' << endl;
    printf("%lld\n",f[1][0]);
}

signed main(){
    //freopen("H.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%lld",&t[i]);
            g[i].clear();
            f[i][0]=f[i][1]=f[i][2]=0;
        }
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%lld%lld",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        solve();
    }
}
