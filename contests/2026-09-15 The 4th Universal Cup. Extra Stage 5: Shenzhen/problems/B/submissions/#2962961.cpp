#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=3e5+5,mod=998244353;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1;
    }
    return tot;
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

vector <int> F[N],P[N*4];
int ct;


int n,d,m,ans[N];

void NO(){
    for(int t=1;t<n;t++) printf("0\n");
    exit(0);
}

int X[N],Y[N],Z[N],W[N];


map < tuple<int,int,int>,int > mp; 
vector<int> V[N];
int id;

vector <int> G[N];
void add(int u,int v){
    int dx=X[u]-X[v],dy=Y[u]-Y[v],dz=Z[u]-Z[v];
    if(1ll*dx*dx+1ll*dy*dy+1ll*dz*dz<1ll*d*d){
        // cout<<" add "<<u<<" "<<v<<endl;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}



int col[N];

int NUM[2],VAL[2];
void dfs(int u){
    int c=col[u];
    // cout<<u<<" "<<c<<" "<<W[u]<<endl;
    NUM[c]++; VAL[c]=1ll*VAL[c]*W[u]%mod;
    for(int v: G[u]){
        if(col[v]==-1){
            col[v]=c^1;
            dfs(v);
        }
        else{
            if(col[v]!=c^1) NO();
        }
    }
}


void solve(int l,int r,int o){
    if(l==r){
        P[o]=F[l];
        return ;
    }
    int mid=(l+r)>>1;
    int ls=o<<1,rs=o<<1|1;
    solve(l,mid,ls);
    solve(mid+1,r,rs);
    
    int degl=P[ls].size()-1,degr=P[rs].size()-1;
    P[o].resize(degl+degr+1);
    NTT::solve(P[o].data(),P[ls].data(),P[rs].data(),degl,degr);
}

signed main(){
    NTT::pre(2e5);
    
    scanf("%d%d",&n,&d);
    m=max(1,(int)(d/1.8));
    // cout<<"m="<<m<<endl;
    
    for(int i=1;i<=n;i++){
        int x,y,z,w;
        scanf("%d%d%d%d",&x,&y,&z,&w);
        X[i]=x,Y[i]=y,Z[i]=z,W[i]=w;
        
        // int bx=x/m,by=y/m,bz=z/m;
        tuple<int,int,int> u={x/m,y/m,z/m};
        if(!mp[u]) mp[u]=++id;
        V[mp[u]].push_back(i);
        if(V[mp[u]].size()>2) NO();
    }
    
    for(int t=1;t<=id;t++){
        if(!V[t].size()) continue;
        if(V[t].size()==2){
            add(V[t][0],V[t][1]);
        }
        int u=V[t][0];
        // cout<<"u="<<u<<endl;
        int bx=X[u]/m,by=Y[u]/m,bz=Z[u]/m;
        // cout<<" bxyz="<<bx<<" "<<by<<" "<<bz<<endl;
        for(int i=bx-2;i<=bx+2;i++){
            for(int j=by-2;j<=by+2;j++){
                for(int k=bz-2;k<=bz+2;k++){
                    if(i==bx && j==by && k==bz) continue;
                    int d=mp[{i,j,k}];
                    if(d){
                        // cout<<t<<" "<<d<<": "<<bx<<" "<<by<<" "<<bz<<"  "<<i<<" "<<j<<" "<<k<<endl;
                        for(int x: V[t]){
                            for(int y: V[d]) add(x,y);
                        }
                    }
                }
            }
        }
    }
    
    memset(col,-1,sizeof(col));
    for(int u=1;u<=n;u++){
        if(col[u]!=-1) continue;
        col[u]=0;
        NUM[0]=NUM[1]=0;
        VAL[0]=VAL[1]=1;
        dfs(u);
        
        int deg=max(NUM[0],NUM[1]);
        ct++;
        F[ct].resize(deg+1);
        gmod(F[ct][NUM[0]]+=VAL[0]);
        gmod(F[ct][NUM[1]]+=VAL[1]);
        
        // cout<<"VAL "<<VAL[0]<<" "<<VAL[1]<<endl;
        // cout<<"F"<<ct<<": ";
        // for(int x: F[ct]) cout<<x<<" "; cout<<endl;
    }
    
    solve(1,ct,1);
    for(int i=0;i<P[1].size();i++) ans[i]=P[1][i];
    for(int i=1;i<n;i++) printf("%d\n",ans[i]);
}