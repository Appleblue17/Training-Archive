#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T, n;
vector<int> e[N];
int a[N], b[N];
unordered_map<int, int> ha[N], hb[N];
int rt[N];
int ans[N], sz[N], son[N];
void dfs(int x, int fa){
    sz[x]=1; son[x]=0;
    for(auto y:e[x]) if(y^fa){
        dfs(y, x);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]]) son[x]=y;
    }
}
#define fi first
#define se second
#define mapa make_pair
int cnt[N];
void dfs2(int x, int fa){
    if(!son[x]){
        cnt[x]=0;
        rt[x]=x;
        if(a[x]!=0&&a[x]==b[x]){
            ans[x]=1;
            return ;
        }
        ha[x][a[x]]++; hb[x][b[x]]++;
        cnt[x]+=2;
        if(a[x]==0||b[x]==0){
            ans[x]=1;
        }
        return ;
    }
    dfs2(son[x], x);
    rt[x]=rt[son[x]];
    if(a[x]!=0&&a[x]==b[x]){
        //gun mu
    }
    else {
        if(a[x]!=0&&hb[rt[x]][a[x]]!=0){
            --cnt[rt[x]];
            hb[rt[x]][a[x]]--;
        }
        else{
            ++cnt[rt[x]];
            ha[rt[x]][a[x]]++;
        }
        if(b[x]!=0&&ha[rt[x]][b[x]]!=0){
            --cnt[rt[x]];
            ha[rt[x]][b[x]]--;
        }
        else{
            ++cnt[rt[x]];
            hb[rt[x]][b[x]]++;
        }
    }
    for(auto y:e[x]) if(y!=fa&&y!=son[x]){
        dfs2(y, x);
        for(auto t:ha[rt[y]]){
            if(t.fi==0){
                cnt[rt[x]]+=t.se;
                ha[rt[x]][0]+=t.se;
            }
            else{
                int w=min(hb[rt[x]][t.fi], t.se);
                cnt[rt[x]]-=w;
                hb[rt[x]][t.fi]-=w;
                cnt[rt[x]]+=t.se-w;
                ha[rt[x]][t.fi]+=t.se-w;
            }
        }
        for(auto t:hb[rt[y]]){
            if(t.fi==0){
                cnt[rt[x]]+=t.se;
                hb[rt[x]][0]+=t.se;
            }
            else{
                int w=min(ha[rt[x]][t.fi], t.se);
                cnt[rt[x]]-=w;
                ha[rt[x]][t.fi]-=w;
                cnt[rt[x]]+=t.se-w;
                hb[rt[x]][t.fi]+=t.se-w;
            }
        }
    }
    if(2*(ha[rt[x]][0]+hb[rt[x]][0])>=cnt[rt[x]]){
        ans[x]=1;
    }
}
void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        e[i].clear(); ha[i].clear(); hb[i].clear(); ans[i]=0;
        scanf("%d", &a[i]);
    }
    for(int i=1; i<=n; ++i){
        scanf("%d", &b[i]);
    }
    for(int i=1, x, y; i<n; ++i){
        scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    dfs(1, 0);
    dfs2(1, 0);
    for(int i=1; i<=n; ++i) printf("%d", ans[i]);
    putchar('\n');
}
signed main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
    
}
