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
const int N=2e6+5, bd=3e5;
const ll inf=1e18;
int T, n, m;
char s[N];
ll a[N], b[N], c[N];
int fail[N], len[N], ch[N][26], dep[N];
ll sz[N];
int lst=0, cnt=1;
void init(){
    fail[0]=1; fail[1]=0;
    len[0]=0; len[1]=-1;
}
int get_fail(int x, int lim){
    while(s[lim-len[x]-1]!=s[lim]) x=fail[x];
    return x;
}
void ins(int c, int lim){
    int p=get_fail(lst, lim);
    if(!ch[p][c]){
        len[++cnt]=len[p]+2;
        int q=get_fail(fail[p], lim);
        fail[cnt]=ch[q][c];
        ch[p][c]=cnt;
    }
    lst=ch[p][c];
}
vector<int> e[N];
void dfs(int x){
    sz[x]=1;
    for(auto y:e[x]){
        dep[y]=dep[x]+1;
        dfs(y);
        sz[x]+=sz[y];
    }
}
struct data{
    ll k, b;
}w[N];
int idx;
ll calc(int id, int x){
    return w[id].k*x+w[id].b;
}
int mx[N*40], ls[N*40], rs[N*40], rt[N], tot;
void add(ll k, ll b){
    ++idx;
    w[idx].k=k; w[idx].b=b;
}
void upd(int &p, int l, int r, int x){
    if(!p) {
        p=++tot;
        mx[p]=x;
        return ;
    }
    int mid=(l+r)>>1, &y=mx[p];
    if(calc(x, mid-bd)>calc(y, mid-bd)) swap(x, y);
    if(calc(x, l-bd)>calc(y, l-bd)) upd(ls[p], l, mid, x);
    if(calc(x, r-bd)>calc(y, r-bd)) upd(rs[p], mid+1, r, x);
}
ll get(int p, int l, int r, int x){
    if(!p||r<x||x<l) return -inf;
    int mid=(l+r)>>1;
    ll ret=calc(mx[p], x-bd);
    if(l==r) return ret;
    return max(ret, max(get(ls[p], l, mid, x), get(rs[p], mid+1, r, x)));
}
ll ans=0;
ll dp[N];
int merge(int &u, int &v, int l, int r){
    if(!u||!v) return u+v;
    if(l==r){
        if(calc(mx[u], l-bd)<calc(mx[v], l-bd)) mx[u]=mx[v];
        return u;
    }
    upd(u, l, r, mx[v]);
    int mid=(l+r)>>1;
    ls[u]=merge(ls[u], ls[v], l, mid);
    rs[u]=merge(rs[u], rs[v], mid+1, r);
    return u;
}
void dfs2(int x){
    for(auto y:e[x]){
        dfs2(y);
        rt[x]=merge(rt[x], rt[y], 0, bd*2);
    }
    dp[x]=max(0ll, c[len[x]]*b[min((ll)m, sz[x])]+get(rt[x], 0, bd*2, bd+a[min((ll)m, sz[x])])-a[min((ll)m, sz[x])]*dep[x]);
    add(dep[x]+1, dp[x]);
    upd(rt[x], 0, bd*2, idx);
    // cout<<x<<' '<<dp[x]<<endl;
    ans=max(ans, dp[x]);
}
int main(){
    // freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
    // freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
    read(n); read(m);
    scanf("%s", s+1);
    init();
    for(int i=1; i<=n; ++i) ins(s[i]-'a', i);
    for(int i=1; i<=m; ++i) read(a[i]);
    for(int i=1; i<=m; ++i) read(b[i]);
    for(int i=0; i<=n; ++i) read(c[i]);
    for(int i=2; i<=cnt; ++i) {
        if(fail[i]==1) fail[i]=0;
        e[fail[i]].ep(i);
    }
    dfs(0);
    w[0].k=0; w[0].b=-inf;
    dfs2(0);
    printf("%lld\n", ans);
    return 0;
}
