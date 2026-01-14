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
const int N=1e6+5;
const ll inf=1e18;
int T, n, m;
vector<int> e[N];
int dfn[N], pos[N], timer, dep[N];
void dfs0(int x, int fa){
    dep[x]=dep[fa]+1;
    dfn[++timer]=x; pos[x]=timer;
    for(auto y:e[x])if(y^fa){
        dfs0(y, x);
        dfn[++timer]=x;
    }
}
int lg[N], st[20][N];
inline int lca(int x, int y){
    x=pos[x]; y=pos[y];
    if(x>y) swap(x, y);
    int t=lg[y-x+1];
    return dep[st[t][x]]<dep[st[t][y-(1<<t)+1]]?st[t][x]:st[t][y-(1<<t)+1];
}
inline int dis(int x, int y){
    return dep[x]+dep[y]-2*dep[lca(x, y)];
}
int lp[N], rp[N];
int sz[N], mx[N];
int pre[N];
struct myheap{
    priority_queue<ll, vector<ll>, greater<ll> > p, q;
    void push(ll x){
        p.push(x);
    }
    void pop(ll x){
        q.push(x);
    }
    ll top(){
        while(!q.empty()&&p.top()==q.top()) p.pop(), q.pop();
        return p.top();
    }
}pq[N];
bool ban[N];
vector<int> cur;
void dfs(int x, int fa){
    sz[x]=1; mx[x]=0; cur.ep(x);
    for(auto y:e[x]) if(y!=fa&&!ban[y]){
        dfs(y, x);
        sz[x]+=sz[y]; mx[x]=max(mx[x], sz[y]);
    }
}
int solve(int u){
    cur.clear();
    dfs(u, 0);
    int rt=u;
    for(auto x:cur) if(max(mx[x], sz[u]-sz[x])<max(mx[rt], sz[u]-sz[rt])) rt=x;
    pq[rt].push(inf); ban[rt]=1;
    for(auto x:e[rt]) if(!ban[x]){
        int w=solve(x); pre[w]=rt;
    }
    return rt;
}
ll dp[N];
void ins(int x){
    // cout<<"ins"<<x<<endl;
    int t=x;
    while(t){
        pq[t].push(dp[x]+dis(x, t));
        t=pre[t];
    }
}
void del(int x){
    // cout<<"del"<<x<<endl;
    int t=x;
    while(t){
        pq[t].pop(dp[x]+dis(x, t));
        t=pre[t];
    }
}
ll qry(int x){
    int t=x; ll ret=inf;
    while(t){
        ret=min(ret, dis(t, x)+1+pq[t].top());
        t=pre[t];
    }
    return ret;
}
struct node{
    int x, tp, id;
    inline bool operator <(const node &t)const{
        if(x!=t.x) return x<t.x;
        return tp<t.tp;
    }
};
vector<node> bin;
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n); 
    for(int i=1, x, y; i<n; ++i){
        read(x); read(y);
        e[x].ep(y); e[y].ep(x);
    }
    dfs0(1, 0);
    for(int i=2; i<=timer; ++i) lg[i]=lg[i>>1]+1;
    for(int i=1; i<=timer; ++i) st[0][i]=dfn[i];
    for(int i=1; i<=lg[timer]; ++i){
        for(int j=1; j+(1<<i)-1<=timer; ++j){
            st[i][j]=dep[st[i-1][j]]<dep[st[i-1][j+(1<<(i-1))]]?st[i-1][j]:st[i-1][j+(1<<(i-1))];
        }
    }
    for(int i=1; i<=n; ++i){
        read(lp[i]); read(rp[i]);
    }
    if(max(lp[n], lp[1])<=min(rp[n], rp[1])){
        printf("%d\n", dis(1, n));
        return 0;
    }
    if(rp[n]<lp[1]){
        for(int i=1; i<=n; ++i){
            swap(lp[i], rp[i]);
            lp[i]=1e9-lp[i]; rp[i]=1e9-rp[i];
        }
    }
    solve(1);
    dp[1]=0;
    ins(1);
    bin.ep((node){rp[1], 1, 1});
    for(int i=2; i<=n; ++i){
        lp[i]=max(lp[i], lp[1]);
        if(lp[i]>rp[i]) continue;
        bin.ep((node){lp[i], 0, i});
        bin.ep((node){rp[i], 1, i});
    }
    sort(bin.begin(), bin.end());
    for(auto t:bin){
        if(t.tp==0){
            dp[t.id]=qry(t.id);
            ins(t.id);
        }
        else{
            del(t.id);
        }
    }
    printf("%lld\n", dp[n]-1);
	return 0;
}

