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
int s[N], t[N], nx[N], len, p[N];
bool ban[N], oncir[N];
vector<int> cir;
bool dfs2(int x, int id){
    cir.push_back(x); oncir[x]=1;
    for(int i=lin[x]; i; i=nxt[i]){
        int y=to[i];
        if(vis[y]!=id) continue;
        if(ban[i]) continue;
        ban[i]=ban[i^1]=1;
        if(y==edcc[id][0]){
            return true;
        }
        if(oncir[y]) continue;
        if(dfs2(y, id)){
            return true;
        }
        ban[i]=ban[i^1]=0;
    }
    cir.pop_back(); oncir[x]=0;
    return false;
}
int col[N];
bool dfs3(int x, int fr, int cur){
    col[x]=cur;
    // cout<<x<<' '<<cur<<endl;
    for(int i=lin[x]; i; i=nxt[i]){
        if(bri[i]) continue;
        if(i==(fr^1)) continue;
        int y=to[i];
        if(col[y]!=-1){
            if(col[y]==(cur^1)){
                return true;
            }
            continue;
        }
        else{
            if(dfs3(y, i, cur^1)) return true;
        }
    }
    return false;
}
int dfn2[N], low2[N], timer2;
int stk[N], top;
int scccnt;
int scc[N];
void dfs0(int x, int fa, int eid, bool &flag){
    dfn2[x]=low2[x]=++timer2;
    stk[top++]=eid;
    for(int i=lin[x]; i; i=nxt[i]){
        if(bri[i]) continue;
        int y=to[i];
        if(y==fa) continue;
        if(!dfn2[y]){
            dfs0(y, x, i, flag);
            if(!flag) return ;
            low2[x]=min(low2[x], low2[y]);
            if(low2[y]==dfn2[x]){
                ++scccnt;
                int e_cnt=1;
                bool tag=1;
                while(1){
                    int u=stk[--top];
                    if(scc[to[u]]!=scccnt){
                        scc[to[u]]=scccnt;
                        ++e_cnt;
                    }
                    else{
                        tag=0;
                    }
                    if(u==i) break;
                }
                if(!tag){
                    flag=0; return ;
                }
            }
        }
        else if(dfn2[y]<dfn2[x]){
            low2[x]=min(low2[x], dfn2[y]);
            stk[top++]=i;
        }
    }
    if(stk[top-1]==eid) --top;
}
int tr[N];
void add(int x){
    for(; x<N; x+=(x&-x)) tr[x]^=1;
}
int get(int x){
    int ret=0;
    for(; x; x-=(x&-x)) ret^=tr[x];
    return ret;
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
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
    memset(col, -1, sizeof col);
    for(int o=1; o<=idx; ++o){
        cir.clear();
        dfs2(edcc[o][0], o);
        bool flag=1;
        dfs0(edcc[o][0], 0, 0, flag);
        bool flag2=0;
        for(auto x:edcc[o]){
            for(int i=lin[x]; i&&!flag2; i=nxt[i]) if(!ban[i]&&!ban[i^1]){
                if(vis[to[i]]==o){
                    // cout<<x<<' '<<to[i]<<endl;
                    flag2=1; break;
                }
            }
            if(flag2) break;
        }
        bool flag3=dfs3(edcc[o][0], 0, 0);
        if(!flag||(flag2&&flag3)){
            len=0;
            for(auto x:edcc[o]) s[++len]=a[x], t[len]=b[x];
            sort(s+1, s+len+1);
            sort(t+1, t+len+1);
            for(int i=1; i<=len; ++i) if(s[i]!=t[i]){
                printf("impossible\n");
                exit(0);
            }
            continue;
        }
        else if(flag2){
            len=0;
            unordered_map<int, bool> h;
            for(auto x:edcc[o]) s[++len]=a[x], t[len]=b[x], h[a[x]]=1;
            if((int)h.size()<len) continue;
            int w=0;
            for(int i=len; i>=1; --i) w^=get(s[i]), add(s[i]);
            for(int i=len; i>=1; --i) add(s[i]);
            for(int i=len; i>=1; --i) w^=get(t[i]), add(t[i]);
            for(int i=len; i>=1; --i) add(t[i]);
            if(w){
                printf("impossible\n");
                exit(0);
            }
            continue;
        }
        if(cir.empty()) {
            if(a[edcc[o][0]]!=b[edcc[o][0]]){
                printf("impossible\n");
                exit(0);
            }
            continue;
        }
        len=0;
        flag=0;
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
