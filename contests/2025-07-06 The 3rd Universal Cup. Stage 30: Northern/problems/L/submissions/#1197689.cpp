#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5,M=1e6+5,mod=998244353;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1;
    }
    return tot;
}

inline int rd(){
	int tot=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^'0'),c=getchar();
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

int p,m,k=32;
vector <int> A[N];

int V[N][66],st[N],id;

mt19937 rng(time(NULL));
int perm[N];
bool vis[N];

int a[M],e[M],ct;

vector <int> P[M];
priority_queue < pair<int,int> > que; 
int pid;
int TMP[N];

pair<int,int> solve(){
    // cout<<ct<<endl;
    pid=0;
    for(int i=1;i<=ct;i++){
        P[i].resize(e[i]+1);
        P[i].clear();
        P[i][0]=(1+mod-a[i])%mod;
        P[i][e[i]]=a[i];
        pid++;
        que.push(make_pair(-e[i],pid));
    }
    
    while(que.size()>1){
        pair<int,int> X,Y;
        X=que.top(); que.pop();
        Y=que.top(); que.pop();
        
        int x=X.second,y=Y.second;
        int lenl=-X.first,lenr=-Y.first;
        pid++;
        NTT::solve(TMP,P[x].data(),P[y].data(),lenl,lenr);
        int len=min(lenl+lenr,p-1);
        P[pid].resize(len+1);
        P[pid].clear();
        for(int i=0;i<=lenl+lenr;i++){
            P[pid][i%p]=(P[pid][i%p]+TMP[i])%mod;
        }
        que.push(make_pair(-len,pid));
    }
    
    pair<int,int> X=que.top();
    que.pop();
    return X;
}

int F[N],G[N],H[N];

queue <int> q;

signed main(){
    NTT::pre((1<<18)-1);
    p=rd(),m=rd();
    int imod=ksm(100000000,mod-2);
    for(int i=1;i<=m;i++){
        int a=rd(),q=rd();
        q=1ll*q*imod%mod;
        A[a].push_back(q);
    }
    
    for(int i=1;i<p;i++) perm[i]=i;
    shuffle(perm+1,perm+p,rng);
    for(int i=1;i<p;i++) q.push(i);
    
    while(q.size()){
        vector <int> tmp;
        for(int t=1;t<=300;t++){
            while(q.size() && vis[q.front()]) q.pop();
            if(!q.size()) break;
            tmp.push_back(q.front());
            q.pop();
        }
        if(!tmp.size()) break;
        
        int mx=-1,mxer;
        for(int x: tmp){
            int tot=0;
            for(int t=1;t<=k;t++){
                int y=x*t%p;
                if(!vis[y]) tot++;
            }
            if(tot>mx) mx=tot,mxer=x;
        }
        
        id++; st[id]=mxer;
        for(int t=1;t<=k;t++){
            int y=mxer*t%p;
            if(!vis[y]){
                vis[y]=1;
                V[id][t]=y;
            }
        }
        for(int x: tmp){
            if(x!=mxer) q.push(x);
        }
    }
    
    // cout<<id<<" "<<p/k<<endl;
    // return 0;
    
    F[0]=1;
    
    for(int t=1;t<=id;t++){
        int r=st[t];
        
        // cout<<t<<" "<<r<<": ";
        // for(int i=1;i<=k;i++) cout<<V[t][i]<<" ";
        // cout<<endl;
        
        ct=0;
        for(int i=1;i<=k;i++){
            int pos=V[t][i];
            if(!pos) continue;
            for(int x: A[pos]){
                a[++ct]=x;
                e[ct]=i;
            }
        }
        
        // for(int i=1;i<=ct;i++) cout<<"  "<<a[i]<<" "<<e[i]<<endl;
        // cout<<ct<<" "<<ct*k<<endl;
        if(!ct) continue;
        
        pair<int,int> ret=solve();
        int len=-ret.first,num=ret.second;
        
        for(int i=0;i<p;i++) G[i]=0;
        for(int i=0;i<=len;i++){
            gmod(G[i*r%p]+=P[num][i]);
        }
        // cout<<" G "; for(int i=0;i<p;i++) cout<<G[i]<<" "; cout<<endl;
        NTT::solve(H,F,G,p-1,p-1);
        // cout<<" H "; for(int i=0;i<2*p-1;i++) cout<<H[i]<<" "; cout<<endl;
        
        H[p*2-1]=0;
        for(int i=0;i<p;i++){
            F[i]=(H[i]+H[i+p])%mod;
        }
    }
    
    // for(int i=0;i<p;i++) cout<<F[i]<<" ";
    cout<<F[0];
}
