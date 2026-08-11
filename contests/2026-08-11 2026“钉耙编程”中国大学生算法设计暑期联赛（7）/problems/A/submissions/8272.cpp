#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+50, B=450, mod=998244353;
bool st;
int T,n;
char s[N];
int sl[N], sr[N], len[N];
int ans[N];
int lim;
vector<int> e[N];
int fa[N];
int sz[N], son[N], dfn[N], seq[N], timer, dep[N];
void dfs(int x){
    dep[x]=dep[fa[x]]+1;
    sz[x]=1; son[x]=0; dfn[x]=++timer; seq[timer]=x;
    for(auto y:e[x]){
        dfs(y); sz[x]+=sz[y];
        if(sz[y]>sz[son[x]]) son[x]=y;
    }
}
int tp[N], bot[N];
void dfs2(int x, int top){
    tp[x]=top; bot[top]=x;
    if(son[x]) dfs2(son[x], top);
    for(auto y:e[x]) if(y!=son[x]) dfs2(y, y);
}
int del[N], col[N];
int fnd(int x){
    while(x){
        if(del[tp[x]]){
            return x;
        }
        if(col[tp[x]]){
            if(dep[col[tp[x]]]<dep[x]) {int rt=col[tp[x]]; col[tp[x]]=x; return rt;}
            else return x;
        }
        if(x==bot[tp[x]]){
            del[tp[x]]=1;
        }
        else {
            col[tp[x]]=x;
        }
        x=fa[tp[x]];
    }
    return 0;
}
void clr(int x){
    while(x){
        del[tp[x]]=col[tp[x]]=0;
        x=fa[tp[x]];
    }
}
struct ACAM{
    int tr[N][26], idx;
    
    void build(){
        queue<int> que;
        fa[1]=1;
        for(int i=0; i<26; ++i){
            if(tr[1][i]) que.push(tr[1][i]), fa[tr[1][i]]=1;
            else tr[1][i]=1;
        }
        while(!que.empty()){
            int x=que.front(); que.pop();
            for(int i=0; i<26; ++i){
                if(tr[x][i]){
                    int v=tr[x][i];
                    que.push(v);
                    fa[v]=tr[fa[x]][i];
                }
                else{
                    tr[x][i]=tr[fa[x]][i];
                }
            }
        }
        for(int i=2; i<=idx; ++i) e[fa[i]].push_back(i);
        timer=0;
        fa[1]=0;
        dfs(1);
        dfs2(1, 1);
    }
    void clr(){
        for(int i=1; i<=idx; ++i) {
            for(int j=0; j<26; ++j) tr[i][j]=0;
            e[i].clear(); fa[i]=0;
        }
        idx=1;
    }
    void ins(int i){
        int p=1;
        for(int j=sl[i]; j<=sr[i]; ++j){
            if(!tr[p][s[j]-'a']) tr[p][s[j]-'a']=++idx;
            p=tr[p][s[j]-'a'];
        }
    }
}A;
int lp[N], rp[N], bid[N];
struct DS{
    int slf[N], tag[450];
    void clr(){
        for(int i=1; i<=sr[n]+1; ++i) slf[i]=0;
        for(int i=1; i<=bid[sr[n]+1]; ++i) tag[i]=0;
    }
    void add(int l, int r, int v){
        if(bid[l]==bid[r]){
            for(int i=l; i<=r; ++i) slf[i]=(slf[i]+v)%mod;
            return ;
        }
        for(int i=l; i<=rp[bid[l]]; ++i) slf[i]=(slf[i]+v)%mod;
        for(int i=lp[bid[r]]; i<=r; ++i) slf[i]=(slf[i]+v)%mod;
        for(int i=bid[l]+1; i<bid[r]; ++i) tag[i]=(tag[i]+v)%mod;
    }
    inline int get(int x){
        return slf[x]+tag[bid[x]];
    }
}D[450];
long long tmp[450];
bool ed;
void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) ans[i]=0;
    A.clr();
    for(int i=1; i<=n; ++i){
        sl[i]=sr[i-1]+1;
        scanf("%s", s+sl[i]);
        len[i]=strlen(s+sl[i]);
        sr[i]=sl[i]+len[i]-1;
        A.ins(i);
    }
    A.build();
    // for(int i=2; i<=A.idx; ++i) cout<<fa[i]<<' ';
    // cout<<endl;
    lim=1;
    while(1ll*(lim+1)*(lim+2)<=2*sr[n]) ++lim;
    for(int i=1; i<=sr[n]+1; ++i) bid[i]=(i-1)/B+1;
    for(int i=1; i<=bid[sr[n]+1]; ++i){
        lp[i]=rp[i-1]+1; rp[i]=rp[i-1]+B;
    }
    rp[bid[sr[n]+1]]=sr[n]+1;
    for(int i=1; i<=lim; ++i) D[i].clr();
    for(int i=1; i<=n; ++i){
        int p=1;
        for(int j=1; j<=len[i]&&j<=lim; ++j) tmp[j]=0;
        tmp[1]=1;
        for(int j=sl[i]; j<=sr[i]; ++j){
            p=A.tr[p][s[j]-'a'];
            int q=fnd(p);
            if(p==q) continue;
            for(int k=1; k<lim; ++k){
                tmp[k+1]=(tmp[k+1]+D[k].get(dfn[p]));
            }
            if(q!=0){
                for(int k=1; k<lim; ++k){
                    tmp[k+1]=(tmp[k+1]+mod*2-D[k].get(dfn[q]));
                }
            }
        }
        for(int j=1; j<=len[i]&&j<=lim; ++j){
            tmp[j]%=mod;
            ans[j]=(ans[j]+tmp[j])%mod;
            D[j].add(dfn[p], dfn[p]+sz[p]-1, tmp[j]);
        }
        p=1;
        for(int j=sl[i]; j<=sr[i]; ++j){
            p=A.tr[p][s[j]-'a'];
            clr(p);
        }
    }
    for(int i=0; i<n; ++i){
        printf("%d ", ans[n-i]);
    }
    putchar('\n');
}
int main(){
    // cout<<(&st-&ed)/1024/1024<<endl;
    scanf("%d",&T);
    while(T--){
        solve();
    }
}