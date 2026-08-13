#pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;
const int N=5e4+5,mod=998244353;

int T,n,m,k,q;

int rd(){
    int tot=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}
char s[N];
int bid(int x, int y){
    return (x-1)*m+y;
}
vector<int> e[N], g[N];
unordered_map<int, bool> h[N];
int stk[N], top; bool ins[N];
int dfn[N], tim, low[N], id[N], scccnt;
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
            id[x]=scccnt;
            x=stk[top--]; ins[x]=false;
        }while(low[x]!=dfn[x]);
    }
}
void clr(){
    for(int i=1; i<=n*m; ++i) dfn[i]=0, e[i].clear();
    for(int i=1; i<=scccnt; ++i) g[i].clear(), h[i].clear();
    tim=0; scccnt=0;
}
void dfs(int x, int rt){
    if(h[rt].find(x)!=h[rt].end()) return ;
    h[rt][x]=1;
    for(auto y:g[x]) dfs(y, rt);
}
void solve(){
    n=rd(); m=rd(); k=rd(); q=rd();
    for(int i=1; i<=n; ++i){
        scanf("%s", s+(i-1)*m+1);
    }
    clr();
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j)if(s[bid(i, j)]=='.'){
            if(i!=1){
                if(s[bid(i-1, j)]=='.'){
                    e[bid(i-1, j)].push_back(bid(i, j));
                    e[bid(i, j)].push_back(bid(i-1, j));
                }
            }
            if(j!=1){
                if(s[bid(i, j-1)]=='.'){
                    e[bid(i, j-1)].push_back(bid(i, j));
                    e[bid(i, j)].push_back(bid(i, j-1));
                }
            }
        }
    }
    for(int i=1, x, xx, y, yy; i<=k; ++i){
        x=rd(); y=rd(); xx=rd(); yy=rd();
        e[bid(x, y)].push_back(bid(xx, yy));
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j) if(s[bid(i, j)]=='.'){
            if(!dfn[bid(i, j)]) tarjan(bid(i, j));
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1, x; j<=m; ++j) if(s[bid(i, j)]=='.'){
            x=bid(i, j);
            for(auto y:e[x]) if(id[x]!=id[y]){
                g[id[x]].push_back(id[y]);
            }
        }
    }
    for(int i=1; i<=scccnt; ++i) {
        dfs(i, i);
        // cout<<h[i].size()<<' ';
    }
    // cout<<endl;
    // cout<<"-------------------------"<<endl;
    int x, y, xx, yy;
    while(q--){
        x=rd(); y=rd(); xx=rd(); yy=rd();
        x=id[bid(x, y)]; xx=id[bid(xx, yy)];
        if(h[x].find(xx)!=h[x].end()){
            putchar('1');
        }
        else{
            putchar('0');
        }
        putchar('\n');
    }
}
signed main(){
    T=rd();
    while(T--){
        solve();
    }
    
    
}