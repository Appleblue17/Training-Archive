#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e5+5, mod=998244353;
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1ll;
    }
    return tot;
}
void gmod(int &x){
    x-=mod;
    x+=x>>31 & mod;
}

int T, n;
char s[N];
struct node{
    int len, fa;
    int ch[26];
}sam[N];
int lst, cnt;
void extend(int c){
    int p=lst, np=lst=++cnt;
    sam[np].len=sam[p].len+1;
    for(; p&&!sam[p].ch[c]; p=sam[p].fa) sam[p].ch[c]=np;
    if(!p) sam[np].fa=1;
    else{
        int q=sam[p].ch[c];
        if(sam[q].len==sam[p].len+1) sam[np].fa=q;
        else{
            int nq=++cnt;
            sam[nq]=sam[q]; sam[nq].len=sam[p].len+1;
            sam[q].fa=sam[np].fa=nq;
            for(; p&&sam[p].ch[c]==q; p=sam[p].fa) sam[p].ch[c]=nq;
        }
    } 
}
int f[N], f_r[N];
int sum_i[N*20], sum_i1[N*20], sum_j1[N*20], sum_j[N*20], ls[N*20], rs[N*20], ans[N*20];
int rt[N], idx;
int gen(){
    ++idx;
    sum_i[idx]=sum_i1[idx]=sum_j[idx]=sum_j1[idx]=ls[idx]=rs[idx]=ans[idx]=0;
    return idx;
}
void build(int &p, int l, int r, int x){
    if(!p) p=gen();
    gmod(sum_i[p]+=f_r[x]);
    gmod(sum_i1[p]+=f_r[x+1]);
    gmod(sum_j[p]+=f[x]);
    gmod(sum_j1[p]+=f[x+1]);
    if(l==r){
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) build(ls[p], l, mid, x);
    else build(rs[p], mid+1, r, x);
}
int merge(int x, int y, int l, int r){
    if((!x)||(!y)) return x+y;
    if(l==r){
        gmod(ans[x]+=ans[y]);
        gmod(sum_i[x]+=sum_i[y]);
        gmod(sum_i1[x]+=sum_i1[y]);
        gmod(sum_j[x]+=sum_j[y]);
        gmod(sum_j1[x]+=sum_j1[y]);
        return x;
    }
    int mid=(l+r)>>1;
    ls[x]=merge(ls[x], ls[y], l, mid);
    rs[x]=merge(rs[x], rs[y], mid+1, r);
    gmod(ans[x]=ans[ls[x]]+ans[rs[x]]);
    gmod(ans[x]+=(1ll*sum_i[ls[x]]*sum_j1[rs[x]]%mod+3ll*sum_i1[ls[x]]*sum_j[rs[x]]%mod)%mod);
    gmod(sum_i1[x]=sum_i1[ls[x]]+sum_i1[rs[x]]);
    gmod(sum_i[x]=sum_i[ls[x]]+sum_i[rs[x]]);
    gmod(sum_j1[x]=sum_j1[ls[x]]+sum_j1[rs[x]]);
    gmod(sum_j[x]=sum_j[ls[x]]+sum_j[rs[x]]);
    return x;
}
int fin_ans[N];
int indeg[N];
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
vector<int> tem[N];
void solve(){
    scanf("%d", &n);
    scanf("%s", s+1);
    for(int i=1; i<=cnt; ++i){
        sam[i].len=0; sam[i].fa=0;
        for(int j=0; j<26; ++j) sam[i].ch[j]=0;
        indeg[i]=0;
        rt[i]=0;
    }
    lst=1; cnt=1;
    idx=0;
    for(int i=1; i<=n; ++i) extend(s[i]-'a'), build(rt[lst], 1, n, i);
    for(int i=1; i<=n; ++i) fin_ans[i]=0, tem[i].clear();
    int sum1=0;
    for(int i=2; i<=cnt; ++i) ++indeg[sam[i].fa];
    ++indeg[1];
    for(int i=2; i<=cnt; ++i) if(!indeg[i]){
        tem[sam[i].len].push_back(i);
    }
    priority_queue<pii> pq;
    for(int i=n; i>=1; --i){
        for(auto t:tem[i]){
            // cout<<t<<' '<<ans[rt[t]]<<endl;
            gmod(sum1+=ans[rt[t]]);
            pq.push(mapa(sam[sam[t].fa].len, t));
        }
        fin_ans[i]=sum1;
        // cout<<sum1<<' '<<sum2<<endl;
        while(!pq.empty()&&pq.top().fi==i-1){
            int x=pq.top().se; pq.pop();
            gmod(sum1+=mod-ans[rt[x]]);
            rt[sam[x].fa]=merge(rt[sam[x].fa], rt[x], 1, n);
            if(!--indeg[sam[x].fa]){
                tem[sam[sam[x].fa].len].push_back(sam[x].fa);
            }
        }
    }
    for(int i=1; i<=n; ++i) printf("%d\n", fin_ans[i]);
}
signed main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
    f[1]=1;
    for(int i=2; i<N; ++i) f[i]=(3ll*f[i-2]+f[i-1])%mod;
    f_r[1]=ksm(3, mod-2);
    for(int i=2; i<N; ++i) f_r[i]=1ll*f_r[1]*(f_r[i-2]-f_r[i-1]+mod)%mod;
    scanf("%d", &T);
    while(T--){
        solve();
    }
}