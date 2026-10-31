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
int Test, n, m, q;
char a[N], b[N], c[N];
struct SAM{
    int lst, cnt;
    int len[N], fa[N], ch[N][26];
    void init(){
        for(int i=1; i<=cnt; ++i){
            for(int j=0; j<26; ++j) ch[i][j]=0;
            fa[i]=len[i]=0;
        }
        lst=cnt=1;
    }
    void extend(int c){
        int p=lst, np=lst=++cnt;
        len[np]=len[p]+1;
        for(; p&&!ch[p][c]; p=fa[p]) ch[p][c]=np;
        if(!p) fa[np]=1;
        else{
            int q=ch[p][c];
            if(len[q]==len[p]+1) fa[np]=q;
            else{
                int nq=++cnt;
                for(int i=0; i<26; ++i) ch[nq][i]=ch[q][i];
                fa[nq]=fa[q];
                len[nq]=len[p]+1;
                fa[np]=fa[q]=nq;
                for(; p&&ch[p][c]==q; p=fa[p]) ch[p][c]=nq;
            }
        }
    }
}S1, S2;
struct DS{
    vector<int> e[N];
    int sz[N], son[N];
    void dfs(int x){
        sz[x]=1; son[x]=0;
        for(auto y:e[x]){
            dfs(y); sz[x]+=sz[y];
            if(sz[y]>sz[son[x]]) son[x]=y;
        }
    }
    int tp[N];
    int mn[N], mx[N];
    void dfs2(int x, int top){
        tp[x]=top;
        mn[top]=min(mn[top], S1.len[S1.fa[x]]);
        mx[top]=max(mx[top], S1.len[x]);
        cur[top]=mn[top];
        if(son[x]) dfs2(son[x], top);
        for(auto y:e[x]) if(y!=son[x]) dfs2(y, y);
    }
    int cur[N];
    int qry(int x, int l){
        int ret=0;
        while(x&&cur[tp[x]]<l){
            ret+=l-cur[tp[x]];
            cur[tp[x]]=l;
            x=S1.fa[tp[x]]; l=S1.len[x];
        }
        return ret;
    }
    void clr(int x){
        while(x){
            cur[tp[x]]=mn[tp[x]];
            x=S1.fa[tp[x]];
        }
    }
}T;
pii mat[N];
vector<int> edps[N];
int rt[N];
vector<int> e[N];
int sz[N], son[N];
void dfs(int x){
    sz[x]=1; son[x]=0;
    for(auto y:e[x]){
        dfs(y); sz[x]+=sz[y];
        if(sz[y]>sz[son[x]]) son[x]=y;
    }
}
ll ans[N];
void dfs2(int x, bool del){
    if(son[x]){
        for(auto y:e[x]) if(y!=son[x]) {
            dfs2(y, 1);
        }
        dfs2(son[x], 0);
        rt[x]=rt[son[x]]; ans[x]=ans[son[x]];
    }
    for(auto t:edps[x]){
        ans[x]+=T.qry(mat[t-1].fi, mat[t-1].se);
        if(rt[x]!=x) edps[rt[x]].ep(t);
    }
    for(auto y:e[x]) if(y!=son[x]){
        for(auto t:edps[rt[y]]){
            ans[x]+=T.qry(mat[t-1].fi, mat[t-1].se);
            edps[rt[x]].ep(t);
        }
    }
    if(del){
        for(auto t:edps[rt[x]]){
            T.clr(mat[t-1].fi);
        }
    }
    // cout<<"ans:"<<x<<' '<<ans[x]<<endl;
    // for(auto t:edps[rt[x]]){
    //     cout<<t<<' '<<mat[t-1].fi<<' '<<mat[t-1].se<<endl;
    // }
}
ll res[N];
void solve(){
    scanf("%s", a+1);
    n=strlen(a+1);
    scanf("%s", b+1);
    m=strlen(b+1);
    for(int i=1; i<=S1.cnt; ++i){
        T.e[i].clear(); T.mx[i]=0; T.cur[i]=0;
    }
    S1.init(); 
    for(int i=1; i<=n; ++i){
        S1.extend(a[i]-'a');
    }
    T.mn[1]=1e9;
    for(int i=2; i<=S1.cnt; ++i) {
        T.e[S1.fa[i]].ep(i); T.mn[i]=1e9;
        // cout<<S1.fa[i]<<' '<<i<<' '<<S1.len[i]<<endl;
    }
    T.dfs(1);
    T.dfs2(1, 1);
    mat[0]=mapa(1, 0);
    for(int i=1, p=1, l=0; i<=m; ++i){
        if(l==n) p=S1.fa[p], l=S1.len[p];
        while(p!=1&&!S1.ch[p][b[i]-'a']) p=S1.fa[p], l=S1.len[p];
        if(S1.ch[p][b[i]-'a']) p=S1.ch[p][b[i]-'a'], ++l;
        mat[i]=mapa(p, l);
    }
    for(int i=1; i<=S2.cnt; ++i){
        edps[i].clear(); e[i].clear(); ans[i]=0;
    }
    S2.init();
    for(int i=m; i>=1; --i){
        S2.extend(b[i]-'a');
        edps[S2.lst].ep(i);
    }
    rt[1]=1;
    for(int i=2; i<=S2.cnt; ++i){
        e[S2.fa[i]].ep(i); rt[i]=i; 
        // cout<<S2.fa[i]<<' '<<i<<' '<<S2.len[i]<<endl;
    }
    dfs(1);
    dfs2(1, 0);
    read(q);
    while(q--){
        scanf("%s", c+1);
        int len=strlen(c+1);
        int p=1, l=0;
        for(int i=len; i>=1; --i){
            if(l==m) p=S2.fa[p], l=S2.len[p];
            while(p!=1&&!S2.ch[p][c[i]-'a']) p=S2.fa[p], l=S2.len[p];
            if(S2.ch[p][c[i]-'a']) p=S2.ch[p][c[i]-'a'], ++l;
        }
        // cout<<p<<' '<<l<<endl;
        for(int i=l; i>=1; --i){
            if(S2.len[S2.fa[p]]==i) p=S2.fa[p];
            res[i]=ans[p];
        }
        for(int i=1; i<=l; ++i) printf("%lld ", res[i]+1);
        for(int i=l+1; i<=len; ++i) printf("0 ");
        putchar('\n');
    }
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(Test);
	while(Test--){
		solve();
	}
	return 0;
}
