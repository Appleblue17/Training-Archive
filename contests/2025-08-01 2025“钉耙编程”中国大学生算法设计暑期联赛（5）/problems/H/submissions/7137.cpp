#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=1e9+7;
typedef long long ll;
int T, n, n1, n2, m;
char s[N];
struct Trie{
    int tr[N][26], idx, tag[N];
    int nxt[N], dep[N];
    int anc[N];
    void dfs(int x, int curanc){
        if(tag[x]&&curanc==0) curanc=x;
        anc[x]=curanc;
        for(auto y:e[x]){
            dfs(y, curanc);
        }
    }
    void build(){
        queue<int> que;
        nxt[1]=1;
        for(int i=0; i<26; ++i) {
            if(tr[1][i]) que.push(tr[1][i]), nxt[tr[1][i]]=1, dep[tr[1][i]]=1;
            else tr[1][i]=1;
        }
        while(!que.empty()){
            int x=que.front(); que.pop();
            for(int i=0; i<26; ++i){
                if(tr[x][i]){
                    int v=tr[x][i];
                    dep[v]=dep[x]+1;
                    que.push(v);
                    nxt[v]=tr[nxt[x]][i];
                }
                else{
                    tr[x][i]=tr[nxt[x]][i];
                }
            }
        }
        for(int i=2; i<=idx; ++i) e[nxt[i]].push_back(i);
        dfs(1, 0);
        
    }
    vector<int> e[N];
    void clr(){
        for(int i=1; i<=idx; ++i) {
            for(int j=0; j<26; ++j) tr[i][j]=0;
            tag[i]=0; e[i].clear();
        }
        idx=1;
    }
    void ins(){
        m=strlen(s+1);
        int p=1;
        for(int j=1; j<=m; ++j){
            if(!tr[p][s[j]-'a']) tr[p][s[j]-'a']=++idx;
            p=tr[p][s[j]-'a'];
        }
        tag[p]=1;
    }
}t1, t2;
int u[N], v[N];
int tr[N*2];
void add(int x){
    for(; x; x-=(x&-x)) ++tr[x];
}
int get(int x){
    int ret=0;
    for(; x<=m*2; x+=(x&-x)) ret+=tr[x];
    return ret;
}
int rk[N];
void solve(){
    scanf("%d%d", &n1, &n2);
    t1.clr(); t2.clr();
    for(int i=1; i<=n1; ++i){
        scanf("%s", s+1);
        int m=strlen(s+1);
        reverse(s+1, s+m+1);
        t1.ins();
    }
    for(int i=1; i<=n2; ++i){
        scanf("%s", s+1);
        t2.ins();
    }
    t1.build(); t2.build();
    scanf("%s", s+1);
    m=strlen(s+1);
    int p=1;
    for(int i=m; i>=1; --i){
        p=t1.tr[p][s[i]-'a'];
        u[i]=t1.dep[t1.anc[p]];
    }
    p=1;
    for(int i=1; i<=m; ++i){
        p=t2.tr[p][s[i]-'a'];
        v[i]=t2.dep[t2.anc[p]];
    }
    for(int i=1; i<=m*2; ++i) tr[i]=0;
    for(int i=1; i<=m; ++i) rk[i]=i;
    sort(rk+1, rk+m+1, [&](int x, int y){return x-v[x]>y-v[y];});
    ll ans=0;
    int it=0;
    for(int i=m; i>=1; --i){
        while(it+1<=m&&rk[it+1]-v[rk[it+1]]+1>=i){
            ++it;
            if(v[rk[it]]!=0){
                add(rk[it]);
            }
        }
        if(u[i]!=0){
            ans+=get(i+u[i]-1);
        }
    }
    printf("%lld\n", ans);
}
int main() {
    scanf("%d", &T);
    while(T--){
        solve();
    }
    return 0;
}