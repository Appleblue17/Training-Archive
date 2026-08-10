#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n, m;
int f[N][20];
int dep[N];
vector<int> e[N];
int dfn[N], timer;
void dfs(int x){
    dfn[x]=++timer;
    dep[x]=dep[f[x][0]]+1;
    for(int i=1; i<20; ++i) f[x][i]=f[f[x][i-1]][i-1];
    for(auto y:e[x]){
        dfs(y);
    }
}
int lca(int x, int y){
    if(dep[x]<dep[y]) swap(x, y);
    for(int i=19; i>=0; --i) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return x;
    for(int i=19; i>=0; --i) if(f[x][i]^f[y][i]) x=f[x][i], y=f[y][i];
    return f[x][0];
}
int cnt[N], rk[N];
int p[N], len;
int jump(int x, int d){
    for(int i=19; i>=0; --i) if((d>>i)&1) x=f[x][i];
    return x;
}
bool ins[N];
vector<int> bin;
vector<int> g[N];
int deg[N];
int que[N], hh, tt;
int main(){
    scanf("%d", &n);
    for(int i=2; i<=n; ++i){
        scanf("%d", &f[i][0]);
        e[f[i][0]].push_back(i);
    }
    dfs(1);
    scanf("%d", &m);
    while(m--){
        scanf("%d", &len);
        for(int i=1; i<=len; ++i) scanf("%d", &p[i]), cnt[p[i]]++, rk[p[i]]=i;
        bool flag=0;
        for(int i=1; i<=len; ++i) {
            if(cnt[p[i]]>1) flag=1;
            cnt[p[i]]=0;
        }
        for(int i=1; i<len; ++i) if(dep[p[i]]>dep[p[i+1]]) flag=1;
        if(flag){
            printf("No\n");
            continue;
        }
        for(int l=1, r; l<=len; l=r+1){
            r=l;
            while(r+1<=len&&dep[p[l]]==dep[p[r+1]]) ++r;
            for(int i=l; i<r; ++i){
                int x=p[i], y=p[i+1], z=lca(x, y);
                int fx=jump(x, dep[x]-dep[z]-1), fy=jump(y, dep[y]-dep[z]-1);
                // cout<<x<<' '<<y<<' '<<fx<<' '<<fy<<' '<<z<<endl;
                if(fx!=fy){
                    if(!ins[fx]) ins[fx]=1, bin.push_back(fx);
                    if(!ins[fy]) ins[fy]=1, bin.push_back(fy);
                    if(rk[x]<rk[y]) g[fx].push_back(fy), deg[fy]++;
                    else g[fy].push_back(fx), deg[fx]++;
                }
            }
        }
        hh=1, tt=0;
        for(auto t:bin){
            if(deg[t]==0) que[++tt]=t;
        }
        while(hh<=tt){
            int x=que[hh++];
            for(auto y:g[x]){
                --deg[y];
                if(deg[y]==0){
                    que[++tt]=y;
                }
            }
        }
        if(tt==bin.size()) printf("Yes\n");
        else printf("No\n");
        for(auto t:bin){
            ins[t]=0;
            deg[t]=0;
            g[t].clear();
        }
        bin.clear();
    }
}
