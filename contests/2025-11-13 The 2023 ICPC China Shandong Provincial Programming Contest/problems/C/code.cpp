#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5, mod1=998244353, mod2=993244853;
int T, n, m;
char ans[N];
vector<int> e[N];
int fa[N];
bool tag[N];
int dep[N];
int rt[N];
deque<int> que[N];
void dfs(int x){
    rt[x]=x;
    if(e[x].empty()){
        if(tag[x]){
            que[x].push_front(1e9);
            que[x].push_front(dep[x]);
        }
        return ;
    }
    int mx=0, argmx=0;
    for(auto y:e[x]){
        dep[y]=dep[x]+1;
        dfs(y);
        if(que[rt[y]].size()>=mx){
            mx=que[rt[y]].size();
            argmx=y;
        }
    }
    // if(x==0){
    //     for(auto t:que[rt[1]]) cout<<t<<' '; cout<<endl;
    //     for(auto t:que[rt[2]]) cout<<t<<' '; cout<<endl;
    // }
    sort(e[x].begin(), e[x].end(), [&](int u, int v){
        auto it1=que[rt[u]].begin();
        auto it2=que[rt[v]].begin();
        while(it1!=que[rt[u]].end()&&it2!=que[rt[v]].end()){
            if((*it1)==(*it2)){
                ++it1; ++it2;
                continue;
            }
            return (*it1)<(*it2);
        }
        if(que[rt[u]].size()==que[rt[v]].size()) return u<v;
        return que[rt[u]].size()>que[rt[v]].size();
    });
    rt[x]=rt[argmx];
    bool flag=0;
    vector<int> vec;
    bool add=0;
    for(int i=0; i<(int)e[x].size(); ++i) {
        ans[e[x][i]]=i+'a';
        if(e[x][i]==argmx) {
            if(add==0){
                add=1;
            }
            else{
                que[rt[x]].push_front(-dep[x]);
            }
            while(!vec.empty()){
                que[rt[x]].push_front(vec.back()); vec.pop_back();
            }
            flag=1; continue;
        }
        if(flag==0){
            if(add==0){
                add=1;
            }
            else{
                vec.push_back(-dep[x]);
            }
            for(auto t:que[rt[e[x][i]]]) vec.push_back(t);
        }
        else{
            if(add==0){
                add=1;
            }
            else{
                que[rt[x]].push_back(-dep[x]);
            }
            for(auto t:que[rt[e[x][i]]]) que[rt[x]].push_back(t);
        }
    }
    if(tag[x]){
        que[rt[x]].push_front(dep[x]);
    }
}
void solve(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<=n; ++i){
        tag[i]=0; e[i].clear();
        que[i].clear();
    }
    for(int i=1; i<=n; ++i){
        scanf("%d", &fa[i]);
        e[fa[i]].push_back(i);
    }
    for(int i=1, x; i<=m; ++i){
        scanf("%d", &x);
        tag[x]=1;
    }
    dfs(0);
    for(int i=1; i<=n; ++i) putchar(ans[i]);
    putchar('\n');
}
signed main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
