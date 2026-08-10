#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
void read(int &x){
    char c=getchar();
    x=0;
    for(; c<'0'||c>'9'; c=getchar());
    for(; c>='0'&&c<='9'; c=getchar()) x=(x<<1)+(x<<3)+(c^48);
}
const int N=1e6+5;
int T, n;
int a[N], ind[N], outd[N];
vector<int> e[N], g[N];
int dfn[N], tim, low[N], scc[N], scccnt, sccsz[N];
int stk[N], top; bool ins[N];
void tarjan(int x){
    low[x]=dfn[x]=++tim;
    stk[++top]=x; ins[x]=true;
    for(auto y:e[x]){
        if(!dfn[y]) tarjan(y), low[x]=min(low[x], low[y]);
        else if(ins[y]) low[x]=min(low[x], dfn[y]);
    }
    if(low[x]==dfn[x]){
        scccnt++;
        do{
            scc[x]=scccnt;
            x=stk[top--]; ins[x]=false;
        }while(low[x]!=dfn[x]);
    }
}
bool flag[N], flag2[N];
void solve(){
    read(n);
    for(int i=1; i<=n; ++i){
        read(a[i]);
        e[i].clear();
        dfn[i]=low[i]=0; ins[i]=0;
    }
    tim=0; top=0; scccnt=0;
    for(int i=1; i<=n; ++i){
        read(outd[i]);
    }
    
    for(int i=1; i<=n; ++i){
        for(int j=1, x; j<=outd[i]; ++j){
            read(x);
            e[i].push_back(x);
        }
    }
    for(int i=1; i<=n; ++i){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1; i<=scccnt; ++i){
        g[i].clear(); sccsz[i]=0; flag[i]=0; ind[i]=0; flag2[i]=0;
    }
    for(int x=1; x<=n; ++x){
        ++sccsz[scc[x]]; flag[scc[x]]|=(a[x]>0);
        for(auto y:e[x]){
            if(scc[x]!=scc[y]){
                g[scc[x]].push_back(scc[y]);
                ind[scc[y]]++;
            }
        }
    }
    queue<int> que;
    for(int i=1; i<=scccnt; ++i) {
        if(!ind[i]) que.push(i);
    }
    int ans=0;
    while(!que.empty()){
        int x=que.front(); que.pop();
        if(flag[x]&&sccsz[x]>1){
            ans+=sccsz[x]; flag2[x]=1;
        }
        else if(flag2[x]){
            ans+=sccsz[x];
        }
        for(auto y:g[x]){
            flag[y]|=flag[x]; flag2[y]|=flag2[x];
            if(!--ind[y]){
                que.push(y);
            }
        }
    }
    printf("%d\n", ans);
}
signed main(){
    read(T);
    while(T--){
        solve();
    }
}