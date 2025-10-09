#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+5,mod=998244353,inv2=(mod+1)/2;

int n;
vector <int> G[N];
int deg[N];

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
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


void gmodn(int &x){ x+=x>>31 & mod; }
void gmod(int &x) { x%=mod; }

namespace NTT{
    int in,g[N];
    void pre(int tl) {
        int l=__lg(tl)+1;
        int n=(1 << l);
        g[0]=1;
        g[n]=ksm(31,1 << (21-l));
        for(int i=l;i;i--) g[1 << (i-1)]=1ll*g[1 << i]*g[1 << i]%mod;
        for(int i=0;i<n;i++) g[i]=1ll*g[i & (i-1)]*g[i & (-i)]%mod;
    }
    int init(int tl) {
        int l=__lg(tl)+1;
        in=mod-((mod-1) >> l);
        return l;
    }
    void ntt(int *f, int n) {
        int v;
        for(int i=(n>>1);i;i >>= 1)
            for(int *t=g,*j=f;j!=f+n;j+=(i << 1),t++)
                for(int *k=j;k!=j+i;k++){
                    v=1ll*(*t)*k[i]%mod;
                    gmodn(k[i]=(*k)-v);
                    gmodn((*k)+=v-mod);
                }
    }
    void intt(int *f, int n) {
        int v;
        for(int i=1;i<n;i<<=1)
            for(int *t=g,*j=f;j!=f+n;j+=(i << 1),t++)
                for(int *k=j;k!=j+i;k++){
                    gmodn(v=(*k)+k[i]-mod);
                    k[i]=1ll*(*t)*(*k-k[i]+mod)%mod;
                    *k=v;
                }
        reverse(f+1,f+n);
        for(int i=0;i<n;i++) f[i]=1ll*f[i]*in%mod;
    }
    
    int A[N],B[N],C[N];
    void solve(int *s,int* f,int* g,int n,int m){
        if(n+m<=150){
            for(int i=0;i<=n+m;i++) C[i]=0;
            for(int i=0;i<=n;i++)
                for(int j=0;j<=m;j++)
                    gmodn(C[i+j]+=1ll*f[i]*g[j]%mod-mod);
            for(int i=0;i<=n+m;i++) s[i]=C[i];
            return ;
        }
        int lim=init(n+m);
        for(int i=0;i<(1<<lim);i++) A[i]=B[i]=0;
        for(int i=0;i<=n;i++) A[i]=f[i];
        for(int i=0;i<=m;i++) B[i]=g[i];
        ntt(A,(1<<lim));
        ntt(B,(1<<lim));
        
        for(int i=0;i<(1<<lim);i++) C[i]=1ll*A[i]*B[i]%mod;
        intt(C,(1<<lim));
        for(int i=0;i<=n+m;i++) s[i]=C[i];
    }
}



int tot,siz[N];
int mx,mxer;
bool vis[N];

void getroot(int u,int fa){
	siz[u]=1;
	int tmp=0;
	for(int v: G[u]){
		if(v==fa || vis[v]) continue;
		getroot(v,u);
		siz[u]+=siz[v];
		tmp=max(tmp,siz[v]);
	}
	tmp=max(tmp,tot-siz[u]);
	if(tmp<mx) mx=tmp,mxer=u;
}

int buc0[N],buc1[N],f[N],g[N],h[N],sf[N],sg[N],sh[N];
int lim;

void dfs(int u,int fa,int dep){
    buc0[dep]++;
    gmod(buc1[dep]+=deg[u]);
    lim=max(lim,dep);
	for(int v: G[u]){
		if(v==fa || vis[v]) continue;
		dfs(v,u,dep+1);
	}
}

void solve(int w){
    w=(w+mod)%mod;
    // for(int i=0;i<=lim;i++) cout<<buc[i]<<" "; cout<<endl;
    
    NTT::solve(f,buc0,buc0,lim,lim);
    NTT::solve(g,buc0,buc1,lim,lim);
    NTT::solve(h,buc1,buc1,lim,lim);
    for(int i=0;i<=lim*2;i++){
        gmod(sf[i]+=w*f[i]%mod);
        gmod(sg[i]+=w*g[i]%mod);
        gmod(sh[i]+=w*h[i]%mod);
    }
    // for(int i=0;i<=lim*2;i++) cout<<F[i]<<" "; cout<<endl;
    
    for(int i=0;i<=lim;i++) buc0[i]=buc1[i]=0;
}

int F[N],P[N],Q[N],R[N];

void divide(int u){
	vis[u]=1;
	
    // cout<<u<<": "<<endl;
    lim=0;
	for(int v: G[u]){
		if(vis[v]) continue;
		dfs(v,u,1);
	}
	buc0[0]++,buc1[0]+=deg[u];
	solve(1);
    
	
	for(int v: G[u]){
		if(vis[v]) continue; 
        lim=0;
		dfs(v,u,1);
		solve(-1);
	}
	for(int v: G[u]){
		if(vis[v]) continue;
		getroot(v,u);
		tot=siz[v],mx=1e9;
		getroot(v,u);
		divide(mxer);
	}
}

signed main(){
    // freopen("1.txt","w",stdout);
    NTT::pre(2e5);
    init(N-5);
    
    scanf("%lld",&n);
    for(int i=1;i<n;i++){
        int u,v; scanf("%lld%lld",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    
    tot=n,mx=1e9;
	getroot(1,0);
    divide(mxer);
    
    for(int len=0;len<=n;len++)
        F[len+1]=(sh[len]+mod-4*sg[len]%mod+4*sf[len]%mod)%mod;
    
    for(int i=0;i<=n;i++){
        P[i]=inv[i];
        Q[i]=F[i]*mul[n-i]%mod;
    }
    NTT::solve(R,P,Q,n,n);
    for(int i=0;i<=n;i++) R[i]=R[i]*inv[n-i]%mod;
        
        
    for(int k=1;k<=n;k++){
        int tot=C(n-1,k-1)*(mod-2+mod-2*n%mod)%mod;
        gmod(tot+=R[k]);
        
        printf("%lld ",(C(n,k)*(n-1)%mod+tot*inv2%mod)%mod*mul[k]%mod);
    }
}
