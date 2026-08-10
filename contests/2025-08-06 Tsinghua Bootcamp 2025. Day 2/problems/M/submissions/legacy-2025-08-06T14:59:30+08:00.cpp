#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+5,mod=1e9+7,INF=1e9;
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

int T,n,ans;
vector <int> Gr[N];

int mxlen[N],son[N];
void dfs0(int u,int fa){
    mxlen[u]=0; son[u]=0;
    for(int v: Gr[u]){
        if(v==fa) continue;
        dfs0(v,u);
        if(mxlen[v]+1>mxlen[u]){
            mxlen[u]=mxlen[v]+1;
            son[u]=v;
        }
    }
}

int F[N*3],G[N*3];
int *nf,*ng;
int *f[N],*g[N];

int a[N],b[N],c[N];

void dfs(int u,int fa,int l){
    if(!son[u]){
        l+=1;
        
        f[u]=nf+l;
        nf+=l*2;
        
        g[u]=ng+1;
        ng+=l*2;
        
        f[u][0]=1;
        return ;
    }
    
    int len=0;
    for(int v: Gr[u]){
        if(v==fa || v==son[u]) continue;
        dfs(v,u,mxlen[v]);
        len=max(len,mxlen[v]+1);
    }
    dfs(son[u],u,l);
    
    f[u]=f[son[u]]-1;
    g[u]=g[son[u]]+1;
    
    for(int i=0;i<=len;i++) a[i]=b[i]=c[i]=0;
    
    int tot=0;
    for(int v: Gr[u]){
        if(v==fa || v==son[u]) continue;
        int lenv=mxlen[v];
        
        for(int i=0;i<=lenv;i++){
            if(i>1) gmod(tot+=f[u][i-1]*g[v][i]%mod);
            gmod(tot+=g[u][i+1]*f[v][i]%mod);
        }
        for(int i=0;i<=lenv;i++){
            
            gmod(c[i+1]+=b[i+1]*f[v][i]%mod);
            gmod(b[i+1]+=a[i+1]*f[v][i]%mod);
            gmod(a[i+1]+=f[u][i+1]*f[v][i]%mod);
            gmod(f[u][i+1]+=f[v][i]);
            
            if(i>0) gmod(g[u][i-1]+=g[v][i]%mod);
        }
    }
    
    // cout<<"  > "<<u<<": "<<tot<<endl;
    gmod(tot+=g[u][0]);
    for(int i=1;i<=len;i++) gmod(tot+=c[i]);
    gmod(ans+=tot);
    
    gmod(f[u][0]+=1);
    for(int i=0;i<=len;i++) gmod(g[u][i]+=b[i]);
    
    // cout<<u<<": "<<len<<" "<<tot<<endl;
    // for(int i=0;i<=len;i++) cout<<f[u][i]<<" "; cout<<endl;
    // for(int i=0;i<=len;i++) cout<<g[u][i]<<" "; cout<<endl;
    // for(int i=0;i<=len;i++) cout<<a[i]<<" "; cout<<endl;
    // for(int i=0;i<=len;i++) cout<<b[i]<<" "; cout<<endl;
    // for(int i=0;i<=len;i++) cout<<c[i]<<" "; cout<<endl;    
}

signed main(){
    // freopen("1.txt","w",stdout);
    cin>>T;
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) Gr[i].clear();
        for(int i=0;i<=n*3;i++) F[i]=G[i]=0;
        nf=F,ng=G;
        
        for(int i=1;i<n;i++){
            int u,v; scanf("%lld%lld",&u,&v);
            Gr[u].push_back(v);
            Gr[v].push_back(u);
        }
        
        dfs0(1,0);
        // for(int i=1;i<=n;i++) cout<<mxlen[i]<<" "<<son[i]<<endl;
        
        ans=0;
        dfs(1,0,mxlen[1]);
        printf("%lld\n",ans);
    }
}