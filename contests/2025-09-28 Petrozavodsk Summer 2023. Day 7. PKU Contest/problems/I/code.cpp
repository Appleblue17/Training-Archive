#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,mod=1e9+7;

int T_,n;
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
void dfs0(int u,int fa){
    col[u]=col[fa]^1;
    for(int v: G[u]){
        if(v==fa) continue;
        dfs0(v,u);
    }
}

int a2[N],a3[N];
int c2[N],c3[N];
void dfs(int u,int fa){
    a2[u]=(a[u]==1);
    a3[u]=(a[u]==2);
    
    c2[u]=(b[u]==1);
    c3[u]=(b[u]==2);
    
    for(int v: G[u]){
        if(v==fa) continue;
        dfs(v,u);
        
        a2[u]+=a2[v];
        a3[u]+=a3[v];
        c2[u]+=c2[v];
        c3[u]+=c3[v];
    }
}

signed main(){
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
        
        dfs(1,0);
        
        int ans=0;
        for(int u=1;u<=n;u++){
            for(int t=-c3[u];t<=a3[u];t++){
                int w=abs(a2[u]-c2[u]+t)*C(a3[u]+c3[u],t+c3[u])%mod;
                int tot=C(a3[1]+c3[1]-a3[u]-c3[u],t+a2[1]-c2[1]+a3[1]-a3[u]);
                gmod(ans+=tot*w%mod);
            }
            // cout<<u<<": "<<tot<<endl;
        }
        cout<<ans<<endl;
    }
    
    
}
