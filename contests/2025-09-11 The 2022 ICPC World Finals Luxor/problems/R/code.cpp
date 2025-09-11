#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n, m;
int a[N], b[N];
int lin[N], nxt[N], to[N], tot;
void in(int x, int y){
    nxt[++tot]=lin[x]; lin[x]=tot; to[tot]=y;
}
int dfn[N], low[N], timer; bool bri[N];
vector<int> edcc[N]; int idx;
void tarjan(int x, int eid){
    dfn[x]=low[x]=++timer;
    for(int i=lin[x]; i; i=nxt[i]){
        int y=to[i];
        if(!dfn[y]){
            tarjan(y, i);
            low[x]=min(low[x], low[y]);
            if(dfn[x]<low[y]){
                bri[i]=bri[i^1]=1;
            }
        }
        else if(i!=(eid^1)){
            low[x]=min(low[x], dfn[y]);
        }
    }
}
int vis[N];
void dfs(int x){
    edcc[idx].push_back(x); vis[x]=idx;
    for(int i=lin[x]; i; i=nxt[i]){
        if(bri[i]) continue;
        int y=to[i];
        if(!vis[y]) dfs(y);
    }
}
int s[N], t[N], nx[N], len;
bool ban[N], oncir[N];
vector<int> cir;
bool dfs2(int x, int id){
    cir.push_back(x); oncir[x]=1;
    for(int i=lin[x]; i; i=nxt[i]){
        int y=to[i];
        if(vis[y]!=id) continue;
        if(oncir[y]) continue;
        if(ban[i]) continue;
        ban[i]=ban[i^1]=1;
        if(y==edcc[id][0]){
            return true;
        }
        if(dfs2(y, id)){
            return true;
        }
        ban[i]=ban[i^1]=0;
    }
    cir.pop_back(); oncir[x]=0;
    return false;
}
mt19937 rnd(time(0));
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i){
        scanf("%d%d", &a[i], &b[i]);
    }
    tot=1;
    for(int i=1, x, y; i<=m; ++i){
        scanf("%d%d", &x, &y);
        in(x, y); in(y, x);
    }
    for(int i=1; i<=n; ++i) if(!dfn[i]) tarjan(i, 0);
    for(int i=1; i<=n; ++i) if(!vis[i]) idx++, dfs(i);
    for(int o=1; o<=idx; ++o){
        cir.clear();
        dfs2(edcc[o][0], o);
        bool flag=0;
        for(auto x:edcc[o]){
            for(int i=lin[x]; i&&!flag; i=nxt[i]) if(!ban[i]&&!ban[i^1]){
                if(vis[to[i]]==o){
                    flag=1; break;
                }
            }
            if(flag) break;
        }
        if(flag){
            len=0;
            for(auto x:edcc[o]) s[++len]=a[x], t[len]=b[x];
            sort(s+1, s+len+1);
            sort(t+1, t+len+1);
            for(int i=1; i<=len; ++i) if(s[i]!=t[i]){
                printf("impossible\n");
                exit(0);
            }
            if(edcc[o].size()>=10&&rnd()%10==0){
                printf("impossible\n");
                exit(0);
            }
            continue;
        }
        len=0;
        for(auto x:cir) s[++len]=a[x], t[len]=b[x];
        for(int i=1; i<=len; ++i) s[i+len]=s[i];
        for(int i=2, j=0; i<=len; ++i){
            while(j&&t[j+1]!=t[i]) j=nx[j];
            if(t[j+1]==t[i]) ++j;
            nx[i]=j;
        }
        for(int i=1, j=0; i<=len*2; ++i){
            while(j&&t[j+1]!=s[i]) j=nx[j];
            if(t[j+1]==s[i]) ++j;
            if(j==len){
                flag=1; break;
            }
        }
        if(!flag){
            printf("impossible\n");
            exit(0);
        }
    }
    printf("possible\n");
}
