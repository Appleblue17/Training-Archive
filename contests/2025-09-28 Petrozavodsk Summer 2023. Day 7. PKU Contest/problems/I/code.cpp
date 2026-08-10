#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,mod=1e9+7;

int T_,n,ans;
vector <int> G[N];
char S[N],T[N];
int a[N],b[N];

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}
int mul[N],inv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return mul[m]*inv[n]%mod*inv[m-n]%mod;
}

void gmod(int &x){
    x%=mod;
}

bool col[N];
int son[N],siz[N];
void dfs0(int u,int fa){
    col[u]=col[fa]^1;
    siz[u]=1; son[u]=0;
    for(int v: G[u]){
        if(v==fa) continue;
        dfs0(v,u);
        if(siz[v]>siz[son[u]]) son[u]=v;
        siz[u]+=siz[v];
    }
}

int c,s;
struct abc{
    int d,w,S0,S1,T0;
    abc(){
        d=0,w=-1;
        S0=S1=T0=0;
    }
    
    void addW(){
        gmod(S0+=C(d,w+1)*C(c-d,s-w-1)%mod);
        gmod(S1+=(w+1)*C(d,w+1)%mod*C(c-d,s-w-1)%mod);
        gmod(T0+=C(d,w+1)*C(c-1-d,s-1-w-1)%mod);
        w++;
    }
    void delW(){
        gmod(S0+=mod-C(d,w)*C(c-d,s-w)%mod);
        gmod(S1+=mod-w*C(d,w)%mod*C(c-d,s-w)%mod);
        gmod(T0+=mod-C(d,w)*C(c-1-d,s-1-w)%mod);
        w--;
    }
    void addD(){
        gmod(S1+=mod-(w+1)*C(d,w)%mod*C(c-d-1,s-w-1)%mod+T0);
        gmod(S0+=mod-C(d,w)*C(c-d-1,s-w-1)%mod);
        if(d+1>c-1) T0=0;
        else gmod(T0+=mod-C(d,w)*C(c-1-d-1,s-1-w-1)%mod);
        
        d++;
    }
    void upd(int d_,int w_){
        while(w<w_) addW();
        while(w>w_) delW();
        while(d<d_) addD();
    }
}tmp,dp[N];

int p[N],q[N]; // #?
int f[N],g[N]; // sum
void dfs(int u,int fa){
    p[u]=(a[u]==2);
    q[u]=(b[u]==2);
    
    f[u]=(a[u]==1);
    g[u]=(b[u]!=0);
    
    for(int v: G[u]){
        if(v==fa) continue;
        dfs(v,u);
        p[u]+=p[v],q[u]+=q[v];
        f[u]+=f[v],g[u]+=g[v];
    }
}


int qry(int d,int w,abc &x){
    if(w<0) return (d*C(c-1,s-1)%mod+mod-w*C(c,s)%mod)%mod;
    
    x.upd(d,w);
    int s0=x.S0,s1=x.S1;
    return ((w*s0+mod-s1)%mod*2%mod+d*C(c-1,s-1)%mod+mod-w*C(c,s)%mod)%mod;
}

void dfss(int u,int fa){
    for(int v: G[u]){
        if(v==fa) continue;
        dfss(v,u);
    }
    int d=p[u]+q[u],w=g[u]-f[u];
    if(son[u]) dp[u]=dp[son[u]];
    else dp[u]=abc();
    int tot=qry(d,w,dp[u]);
    gmod(ans+=tot);
}

signed main(){
    // freopen("1.txt","w",stdout);
    init(N-5);
    
    scanf("%lld",&T_);
    while(T_--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<n;i++){
            int u,v; scanf("%lld%lld",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        scanf("\n%s",S+1);
        scanf("\n%s",T+1);
        
        dfs0(1,0);
        
        for(int i=1;i<=n;i++){
            if(S[i]=='?') a[i]=2;
            else a[i]=(S[i]-'0')^col[i];
            
            if(T[i]=='?') b[i]=2;
            else b[i]=(T[i]-'0')^col[i];
        }
        
        ans=0;
        dfs(1,0);
        
        c=p[1]+q[1],s=g[1]-f[1];
        dfss(1,0);
        
        printf("%lld\n",ans);
    }
}

