#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1.2e6+5,mod=998244353;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}
void gmod(int &x){
    x%=mod;
}
void gmodn(int &x){
    x+=x>>31 & mod;
}

namespace NTT{
    int in,g[N];
    void pre(int tl){
        int l=__lg(tl)+1;
        int n=(1<<l);
        g[0]=1;
        g[n]=ksm(31,1<<(21-l));
        for(int i=l;i;i--) g[1<<(i-1)]=1ll*g[1<<i]*g[1<<i]%mod;
        for(int i=0;i<n;i++) g[i]=1ll*g[i & (i-1)]*g[i & (-i)]%mod;
    }
    int init(int tl){
        int l=__lg(tl)+1;
        in=mod-((mod-1)>>l);
        return l;
    }
    void ntt(int *f,int n){
        int v;
        for(int i=(n>>1);i;i>>=1){
            for(int *t=g,*j=f;j!=f+n;j+=(i<<1),t++){
                for(int *k=j;k!=j+i;k++){
                    v=1ll*(*t)*k[i]%mod;
                    gmodn(k[i]=(*k)-v);
                    gmodn((*k)+=v-mod);
                }
            }
        }
    }
    void intt(int *f,int n){
        int v;
        for(int i=1;i<n;i<<=1){
            for(int *t=g,*j=f;j!=f+n;j+=(i<<1),t++){
                for(int *k=j;k!=j+i;k++){
                    gmodn(v=(*k)+k[i]-mod);
                    k[i]=1ll*(*t)*(*k-k[i]+mod)%mod;
                    *k=v;
                }
            }
        }
        reverse(f+1,f+n);
        for(int i=0;i<n;i++) f[i]=1ll*f[i]*in%mod;
    }
    
    int A[N],B[N],C[N];
    void solve(int *s,int *f,int *g,int n,int m){
        if(n+m<=150){
            for(int i=0; i<=n+m; ++i) C[i]=0;
            for(int i=0; i<=n; ++i){
                for(int j=0; j<=m; ++j){
                    gmodn(C[i+j]+=1ll*f[i]*g[j]%mod-mod);
                }
            }
            for(int i=0; i<=n+m; ++i) s[i]=C[i];
            return ;
        }
        int lim=init(n+m);
        for(int i=0;i<(1<<lim);i++) A[i]=B[i]=0;
        for(int i=0;i<=n;i++) A[i]=f[i];
        for(int i=0;i<=m;i++) B[i]=g[i];
        ntt(A,1<<lim);
        ntt(B,1<<lim);
        
        for(int i=0;i<(1<<lim);i++) C[i]=1ll*A[i]*B[i]%mod;
        intt(C,1<<lim);
        for(int i=0;i<=n+m;i++) s[i]=C[i];
    }    
}
int n, m, K;
int fa[N];
int get(int x){
    if(x==fa[x]) return x;
    return fa[x]=get(fa[x]);
}
void merge(int x, int y){
    x=get(x); y=get(y);
    if(x==y) return ;
    fa[x]=y;
}
vector<int> e[N];
int sz[N];
bool vis[N];
int sum[2];
int len;
pair<int, int> item[N];
void dfs(int x, int id){
    sum[id]+=sz[x]; vis[x]=1;
    for(auto y:e[x]){
        if(vis[y]) continue;
        dfs(y, id^1);
    }
}
typedef vector<int> poly;
poly calc(int l, int r){
    if(l>r) {
        poly ret;
        ret.push_back(1);
        return ret;
    }
    if(l==r){
        poly ret;
        for(int i=max(item[l].first, item[l].second); i>=0; --i) ret.push_back(0);
        ret[item[l].first]++; ret[item[l].second]++;
        return ret;
    }
    int sum=0;
    for(int i=l; i<=r; ++i) sum+=max(item[i].first, item[i].second);
    int mn=1e9, mid=l-1, pre=0;
    for(int i=l; i<=r; ++i){
        pre+=max(item[i].first, item[i].second);
        if(max(pre, sum-pre)<=mn){
            mn=max(pre, sum-pre); mid=i;
        }
    }
    poly lp=calc(l, mid), rp=calc(mid+1, r);
    poly ret;
    ret.resize(lp.size()+rp.size()-1);
    NTT::solve(ret.data(), lp.data(), rp.data(), lp.size()-1, rp.size()-1);
    return ret;
}
void solve(){
    scanf("%d%d%d", &n, &m, &K);
    --n;
    for(int i=1; i<=n; ++i) fa[i]=i, vis[i]=0, e[i].clear(), sz[i]=0;
    vector<pair<int, int> > vec;
    while(K--){
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        --x; --y;
        if(c==1) merge(x, y);
        else vec.push_back(make_pair(x, y));
    }
    if(m*2==n){
        printf("No\n");
        return ;
    }
    for(int i=1; i<=n; ++i) sz[get(i)]++;
    for(auto t:vec){
        e[get(t.first)].push_back(get(t.second));
        e[get(t.second)].push_back(get(t.first));
    }
    len=0;
    for(int i=1; i<=n; ++i) if(i==get(i)&&!vis[i]){
        sum[0]=0; sum[1]=0;
        dfs(i, 0);
        item[++len]=make_pair(sum[0], sum[1]);
    }
    poly f=calc(1, len);
    if(f[m]<=4) printf("Yes\n");
    else printf("No\n");
}
signed main(){
    NTT::pre(1e6);
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
}