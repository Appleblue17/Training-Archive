#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=550000;


int n,A,B;
vector <int> G[N];

int cnt[N],f[N][2][3];
int dp[N][2][3];

void dfs(int u,int fa){
    if(G[u].size()%2==1)cnt[u]=1;
    for(int v:G[u]){
        if(v == fa)continue;
        dfs(v,u);
        cnt[u] += cnt[v];
    }
    //int base = 0,diff = -1,diff2 = -1,diffe = -1;
    int i=0;
    dp[i][0][0] = 0;
    dp[i][0][1] = dp[i][0][2] = dp[i][1][0] = dp[i][1][1] = dp[i][1][2] = f[0][0][0];
    for(int v:G[u]){
        if(v == fa)continue;
        i++;
        for(int o=0;o<=1;o++){
            for(int p=0;p<=2;p++){
                dp[i][o][p] = dp[i-1][o][p] + f[v][0][0]+2*A;
                dp[i][o][p] = min(dp[i][o][p],dp[i-1][(o+1)%2][p] + f[v][1][0]+2*A);
                dp[i][o][p] = min(dp[i][o][p],dp[i-1][(o+1)%2][p] + f[v][0][1] + B);
                dp[i][o][p] = min(dp[i][o][p],dp[i-1][(o+2)%2][p] + f[v][1][1] + B);
                if(p==0)continue;
                dp[i][o][p] = min(dp[i][o][p],dp[i-1][o][p-1] + min(f[v][0][0],f[v][0][1]));
                dp[i][o][p] = min(dp[i][o][p],dp[i-1][(o+1)%2][p-1] + min(f[v][1][0],f[v][1][1]));
                if(p == 1)continue;
                dp[i][o][p] = min(dp[i][o][p],dp[i-1][o][p-2] + f[v][0][2] + 2*A);
                dp[i][o][p] = min(dp[i][o][p],dp[i-1][(o+1)%2][p-2] + f[v][1][2] + 2*A);
            }
        }
    }
    //printf("cnt[%lld]=%lld\n",u,cnt[u]);
    //if(cnt[u]%2==1){
        f[u][0][0] = dp[i][0][0];
        f[u][0][1] = dp[i][0][1];
        f[u][0][2] = dp[i][0][2];
        f[u][1][0] = dp[i][1][0];
        f[u][1][1] = dp[i][1][1];
        f[u][1][2] = dp[i][1][2];
    //}
    //else{// this is equivalent to u == 1
    //    f[u][0][0] = dp[i][0][0];
    //    f[u][1][1] = dp[i][0][1];
    //    f[u][0][1] = dp[i][0][2];
    //}
    //printf("f[%lld] = %lld,%lld,%lld,%lld,%lld,%lld\n",u,f[u][0][0],f[u][0][1],f[u][0][2],f[u][1][0],f[u][1][1],f[u][1][2]);
}
int sz[N];
void getrt(int x, int fa, int &rt, int &cmx){
    sz[x]=1;
    int mx=0;
    for(auto y:G[x]) if(y^fa){
        getrt(y, x, rt, cmx);
        sz[x]+=sz[y];
        mx=max(mx, sz[y]);
    }
    mx=max(mx, n-sz[x]);
    if(mx<=cmx){
        cmx=mx, rt=x;
    }
}

signed main(){
    memset(f,48,sizeof(f));
    scanf("%lld%lld%lld",&n,&A,&B);
    
    for(int i=1;i<n;i++){
        int u,v;scanf("%lld%lld",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(B <= A){
        int ans=0;
        for(int i=1;i<=n;i++){
            if(G[i].size()%2==1)ans++;
        }
        printf("%lld\n",(ans-2)/2*B);
        return 0;
    }
    int rt=1, tem=n+1;
    //getrt(1, 0, rt, tem);
    //printf("rt = %lld\n",rt);
    //for(rt=1;rt<=n;rt++){
        dfs(rt,0);
        int ans = min(min(f[rt][0][0],f[rt][0][1]),f[rt][0][2])/2;
        ans = min(ans,min(min(f[rt][1][0],f[rt][1][1]),f[rt][1][2])/2+B);
        printf("%lld\n",ans);
    //}
    
    
}


