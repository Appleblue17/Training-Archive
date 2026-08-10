#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n;
int t[N];
int a[N];
vector<int> e[N];
bool ins[N];
bool vis[N];
int ans[N];
int dir[N];
void dfs(int x){
    if(vis[x]) return ;
    vis[x]=1;
    for(auto y:e[x]){
        if(vis[y]) continue;
        if(dir[y]==dir[x]){
            ans[y]=ans[x]+abs(a[y]-a[x])*2ll;
        }
        else{
            int tim=abs(a[y]-a[x]);
            ans[y]=tim+max(0ll, tim-ans[x]);
        }
        dfs(y);
    }
}
signed main(){
    scanf("%lld", &n);
    for(int i=1; i<=n; ++i){
        scanf("%lld", &t[i]);
        e[t[i]].push_back(i);
    }
    for(int i=1; i<=n; ++i){
        scanf("%lld", &a[i]);
    }
    for(int i=1; i<=n; ++i){
        if(a[t[i]]>a[i]) dir[i]=1;
        else dir[i]=0;
    }
    for(int i=1; i<=n; ++i){
        if(vis[i]) continue;
        int x=i;
        do{
            ins[x]=1; x=t[x];
        }while(!ins[x]);
        vector<int> cir;
        int p=x;
        do{
            cir.push_back(p); p=t[p];
        }while(p!=x);
        int mn=2e9, argmn=0;
        for(auto w:cir){
            if(dir[w]!=dir[t[w]]){
                int tim=abs(a[t[w]]-a[w]);
                if(tim<mn){
                    mn=tim; argmn=w;
                }
            }
        }
        ans[argmn]=mn;
        dfs(argmn);
    }
    for(int i=1; i<=n; ++i) printf("%lld ", ans[i]);
}
