#pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=998244353;

int T,n,m,k,q;

struct IO{
    static const int S=1<<21;
    char buf[S],*p1,*p2;int st[105],Top;
    ~IO(){clear();}
    inline void clear(){fwrite(buf,1,Top,stdout);Top=0;}
    inline void pc(const char c){Top==S&&(clear(),0);buf[Top++]=c;}
    inline char gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
    inline IO&operator >> (char&x){while(x=gc(),x==' '||x=='\n'||x=='\r');return *this;}
    template<typename T>inline IO&operator >> (T&x){
        x=0;bool f=0;char ch=gc();
       while(!isdigit(ch)){if(ch=='-') f^=1;ch=gc();}
        while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=gc();
        f?x=-x:0;return *this;
    }
    inline IO&operator << (const char c){pc(c);return *this;}
    template<typename T>inline IO&operator << (T x){
        if(x<0) pc('-'),x=-x;
        do{st[++st[0]]=x%10,x/=10;}while(x);
        while(st[0]) pc('0'+st[st[0]--]);return *this;
    }
}fin,fout;
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
    fin>>n>>m>>k>>q;
    for(int i=1; i<=n*m; ++i){
        s[i]=fin.gc();
        while(s[i]!='#'&&s[i]!='.') s[i]=fin.gc();
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
        fin>>x>>y>>xx>>yy;
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
        if(g[i].empty()) continue;
        dfs(i, i);
        // cout<<h[i].size()<<' ';
    }
    // cout<<endl;
    // cout<<"-------------------------"<<endl;
    int x, y, xx, yy;
    while(q--){
        fin>>x>>y>>xx>>yy;
        x=id[bid(x, y)]; xx=id[bid(xx, yy)];
        if(x==xx||h[x].find(xx)!=h[x].end()){
            fout.pc('1');
        }
        else{
            fout.pc('0');
        }
            fout.pc('\n');
    }
}
signed main(){
    fin>>T;
    while(T--){
        solve();
    }
    
    
}