#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
const int N=8e5+5;

int ksm(int a,int x,int mod){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1;
    }
    return tot;
}
    
namespace NTT1{
    const int mod=998244353;
    void gmodn(int &x){
        x+=x>>31 & mod;
    }
    void gmod(int &x){
        x%=mod;
    }
    int ksm(int a,int x){
        int tot=1;
        while(x){
            if(x & 1ll) tot=1ll*tot*a%mod;
            a=1ll*a*a%mod;
            x>>=1;
        }
        return tot;
    }
    
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
        reverse(f+1,f+n+1);
        for(int i=0;i<n;i++) f[i]=1ll*f[i]*in%mod;
    }
    
    int A[N],B[N],C[N];
    void solve(int *s,int *f,int *g,int n,int m){
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

namespace NTT2{
    const int mod=469762049;
    void gmodn(int &x){
        x+=x>>31 & mod;
    }
    void gmod(int &x){
        x%=mod;
    }
    int ksm(int a,int x){
        int tot=1;
        while(x){
            if(x & 1ll) tot=1ll*tot*a%mod;
            a=1ll*a*a%mod;
            x>>=1;
        }
        return tot;
    }
    
    int in,g[N];
    void pre(int tl){
        int l=__lg(tl)+1;
        int n=(1<<l);
        g[0]=1;
        g[n]=ksm(53,1<<(21-l));
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
        reverse(f+1,f+n+1);
        for(int i=0;i<n;i++) f[i]=1ll*f[i]*in%mod;
    }
    
    int A[N],B[N],C[N];
    void solve(int *s,int *f,int *g,int n,int m){
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

namespace NTT3{
    const int mod=167772161;
    void gmodn(int &x){
        x+=x>>31 & mod;
    }
    void gmod(int &x){
        x%=mod;
    }
    int ksm(int a,int x){
        int tot=1;
        while(x){
            if(x & 1ll) tot=1ll*tot*a%mod;
            a=1ll*a*a%mod;
            x>>=1;
        }
        return tot;
    }
    
    int in,g[N];
    void pre(int tl){
        int l=__lg(tl)+1;
        int n=(1<<l);
        g[0]=1;
        g[n]=ksm(4,1<<(21-l));
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
        reverse(f+1,f+n+1);
        for(int i=0;i<n;i++) f[i]=1ll*f[i]*in%mod;
    }
    
    int A[N],B[N],C[N];
    void solve(int *s,int *f,int *g,int n,int m){
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

namespace EXCRT{
    const int mod1=998244353,mod2=469762049,mod3=167772161;
    
    __int128 solve(ll x1,ll x2,ll x3){
        ll k1=(x2+mod2-x1%mod2)%mod2*ksm(mod1,mod2-2,mod2)%mod2;
        ll x4=x1+k1*mod1;
        ll k4=(x3+mod3-x4%mod3)%mod3*ksm(mod1*mod2%mod3,mod3-2,mod3)%mod3;
        
        __int128 tot=x4+(__int128)k4*(__int128)mod1*mod2;
        assert(tot%mod1==x1);
        assert(tot%mod2==x2);
        assert(tot%mod3==x3);
        // if(tot%mod3!=x3){
        //     cout<<x1<<" "<<x2<<" "<<x3<<" "<<(ll)(tot%mod1)<<" "<<(ll)(tot%mod2)<<" "<<(ll)(tot%mod3)<<endl;
        // }
        
        return tot;
    }
}

int n,T;
int p[N],q[N],f[N];
int F[N],G[N],P[N],Q[N],R[N];

bool vis[N];
int mp[N],g[N],id;
vector <ll> V[N];

mt19937 rng(1234);

signed main(){
    NTT1::pre(4e5);
    NTT2::pre(4e5);
    NTT3::pre(4e5);
    
    scanf("%d%d",&n,&T);
    // for(int i=1;i<=n;i++) p[i]=i;
    // shuffle(p+1,p+n+1,rng);
    
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    
    for(int i=1;i<=n;i++) q[p[i]]=i;
    
    for(int u=1;u<=n;u++){
        if(vis[u]) continue;
        int x=u;
        int len=0;
        while(!vis[x]){
            vis[x]=1;
            x=p[x];
            f[++len]=x;
        }
        
        for(int i=0;i<=len;i++) F[i]=G[i]=0;
        for(int i=1;i<=len;i++){
            F[i]=F[i+len]=f[i];
            G[len-i]=q[f[i]];
        }
        NTT1::solve(P,F,G,len*2,len);
        NTT2::solve(Q,F,G,len*2,len);
        NTT3::solve(R,F,G,len*2,len);
        
        // cout<<len<<": "; for(int i=1;i<=len;i++) cout<<f[i]<<" "; cout<<endl;
        // for(int i=1;i<=len;i++) cout<<F[i]<<" "; cout<<endl;
        // for(int i=0;i<=len;i++) cout<<G[i]<<" "; cout<<endl;
        
        if(!mp[len]){
            mp[len]=++id;
            g[id]=len;
            V[id].resize(len);
        }
        int t=mp[len];
        
        for(int i=1;i<=len;i++){
            ll tot=EXCRT::solve(P[i+len],Q[i+len],R[i+len]);
            V[t][i%len]+=tot;
        }
        // cout<<endl;
    }
    
    while(T--){
        int k; scanf("%d",&k);
        ll ans=0;
        for(int i=1;i<=id;i++){
            int len=g[i];
            ans+=V[i][k%len];
        }
        printf("%lld\n",ans);
    }
}
