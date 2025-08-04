#include <bits/stdc++.h>
using namespace std;
const int N=8e5+5,mod=998244353,inv2=(mod+1)/2;
 
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1ll;
    }
    return tot;
}
 
int mul[N],inv[N],pw2[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return 1ll*mul[m]*inv[n]%mod*inv[m-n]%mod;
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

int T,n;
int a[N];
bool vis[N];
int p[N],id;

int cal(int x){
    return 1ll*(x+ksm(x,mod-2))%mod*inv2%mod*inv2%mod;
}

vector <int> P[N*4],Q[N*4];
int A[N],B[N];
void solve(int l,int r,int o){
    if(l==r){
        P[o]=vector<int>{1,cal(p[l])};
        Q[o]=vector<int>{0,p[l]};
        return ;
    }
    int mid=(l+r)>>1;
    int len=r-l+1,len1=mid-l+1,len2=r-mid;
    solve(l,mid,o<<1);
    solve(mid+1,r,o<<1|1);
    
    P[o].resize(len+1);
    Q[o].resize(len+1);
    NTT::solve(P[o].data(),P[o<<1].data(),P[o<<1|1].data(),len1,len2);
    
    NTT::solve(A,P[o<<1].data(),Q[o<<1|1].data(),len1,len2);
    NTT::solve(B,Q[o<<1].data(),P[o<<1|1].data(),len1,len2);
    for(int i=0;i<=len;i++) Q[o][i]=(A[i]+B[i])%mod;
}

int F[N],G[N];

signed main(){
    NTT::pre(4e5);
    init(N-5);
    
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]!=-1) vis[a[i]]=1;
        }
        id=0;
        for(int i=1;i<=n;i++) if(!vis[i]) p[++id]=i;
        
        if(!id){
            P[1]=vector<int>{1};
            Q[1]=vector<int>{0};
        }
        else solve(1,id,1);
        
        // for(int i=0;i<=id;i++) cout<<P[1][i]<<" "; cout<<endl;
        // for(int i=0;i<=id;i++) cout<<Q[1][i]<<" "; cout<<endl;
        
        int val=1,sum=0,ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]==-1) sum++;
            else{
                if(i==1) val=1ll*val*a[i]%mod;
                else val=1ll*val*cal(a[i])%mod;
            }
            int w=(i==n)?1:inv2;
            if(a[1]!=-1) gmod(ans+=1ll*P[1][sum]*val%mod*w%mod*mul[id-sum]%mod*mul[sum]%mod);
            else gmod(ans+=1ll*Q[1][sum]*val%mod*w%mod*mul[id-sum]%mod*mul[sum-1]%mod);
        }
        printf("%d\n",1ll*ans*inv[id]%mod);
    }
    
}