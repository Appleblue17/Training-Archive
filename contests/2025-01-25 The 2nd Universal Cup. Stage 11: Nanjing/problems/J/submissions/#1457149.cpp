#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
#define ep emplace_back
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=2e5+5;
int Task, n, m;
unordered_map<int, int> e[N];
int fa[N], val[N];
int str[N], len[N];
int nxt[N];
int ft[N][20];
struct trie{
    int rt[N], id[N*50], ls[N*50], rs[N*50];
    int idx;
    void clr(){
        for(int i=0; i<=n; ++i) rt[i]=0;
        for(int i=1; i<=idx; ++i) id[i]=ls[i]=rs[i]=0;
        idx=0;
    }
    int qry(int p, int l, int r, int x){
        if(!p) return 0;
        if(l==r) return id[p];
        int mid=(l+r)>>1;
        if(x<=mid) return qry(ls[p], l, mid, x);
        return qry(rs[p], mid+1, r, x);
    }
    void add(int &p, int l, int r, int x, int v){
        ++idx;
        ls[idx]=ls[p]; rs[idx]=rs[p]; 
        p=idx;
        if(l==r){
            id[p]=v;
            return ;
        }
        int mid=(l+r)>>1;
        if(x<=mid) add(ls[p], l, mid, x, v);
        else add(rs[p], mid+1, r, x, v);
    }
    void build(){
        queue<int> que;
        for(auto t:e[0]) que.push(t.se), add(rt[0], 1, n, t.fi, t.se), len[t.se]=1;
        while(!que.empty()){
            int x=que.front(); que.pop();
            rt[x]=rt[nxt[x]];
            for(auto t:e[x]){
                add(rt[x], 1, n, t.fi, t.se);
                que.push(t.se);
                len[t.se]=len[x]+1;
                nxt[t.se]=qry(rt[nxt[x]], 1, n, t.fi);
            }
        }
    }
}T;
int dfn[N], sz[N], timer;
void dfs0(int x){
    dfn[x]=++timer;
    sz[x]=1;
    ft[x][0]=fa[x];
    for(int i=1; i<20; ++i) ft[x][i]=ft[ft[x][i-1]][i-1];
    for(auto t:e[x]) {
        dfs0(t.se);
        sz[x]+=sz[t.se];
    }
}
int z[N];
int match[N];
inline int jump(int x, int d){
    if(d<=0) return x;
    for(int i=19; i>=0; --i) if((d>>i)&1) x=ft[x][i];
    return x;
}
void work(int x, int lst){
    int w=match[lst];
    if(dfn[x]<=dfn[w]&&dfn[w]<=dfn[x]+sz[x]-1){
        w=jump(w, len[w]-len[x]-z[len[x]-len[lst]+1]);
    }
    else{
        w=x;
    }
    int curlen=len[w]-len[x];
    while(curlen<m){
        if(e[w].find(str[curlen+1])==e[w].end()){
            break;
        }
        ++curlen;
        w=e[w][str[curlen]];
    }
    match[x]=w;
    for(auto t:e[x]){
        if(dfn[t.se]<=dfn[w]&&dfn[w]<=dfn[t.se]+sz[t.se]-1) work(t.se, x);
        else work(t.se, lst);
    }
}
int f[N], cnt[N];
vector<int> vec[N];
int get(int x){
    if(x==f[x]) return x;
    return f[x]=get(f[x]);
}
void solve(){
    read(n); read(m);
    for(int i=0; i<=n; ++i) e[i].clear(), nxt[i]=0;
    T.clr();
    for(int i=1; i<=n; ++i) read(fa[i]);
    for(int i=1; i<=n; ++i) {
        read(val[i]);
        e[fa[i]][val[i]]=i;
    }
    timer=0;
    dfs0(0);
    for(int i=1; i<=m; ++i) read(str[i]), z[i]=0;
    z[1]=m;
    for(int i=2, l=0, r=0; i<=m; ++i){
        if(i<=r) z[i]=min(z[i-l+1], r-i+1);
        while(i+z[i]<=m&&str[i+z[i]]==str[z[i]+1]) ++z[i];
        if(i+z[i]-1>r) l=i, r=i+z[i]-1;
    }
    T.build();
    match[0]=0;
    work(0, 0);
    ll add=0;
    for(int i=1; i<=n; ++i) f[i]=i, cnt[i]=1, add+=len[i];
    fa[0]=cnt[0]=0;
    for(int i=0; i<=m; ++i) vec[i].clear();
    for(int i=1; i<=n; ++i){
        // cout<<i<<' '<<match[i]<<' '<<len[match[i]]-len[i]<<endl;
        vec[len[match[i]]-len[i]].ep(i);
    }
    for(auto t:vec[0]) {
        // cout<<t<<' '<<nxt[t]<<endl;
        int u=get(nxt[t]);
        add+=1ll*cnt[t]*(len[u]-len[t]);
        cnt[u]+=cnt[t];
        f[t]=u;
    }
    int p=0;
    for(int i=1; i<=m; ++i){
        p=T.qry(T.rt[p], 1, n, str[i]);
        // cout<<cnt[0]<<endl;
        printf("%lld ", add+1ll*cnt[0]*len[p]+1ll*i*(n-cnt[0]));
        for(auto t:vec[i]) {
            int u=get(nxt[t]);
            add+=1ll*cnt[t]*(len[u]-len[t]);
            cnt[u]+=cnt[t];
            f[t]=u;
        }
    }
    putchar('\n');
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(Task);
	while(Task--){
		solve();
	}
	return 0;
}

