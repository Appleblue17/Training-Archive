#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+5,mod=998244353;
typedef long long ll;
int T, n;
char s1[N], s2[N], s3[N];
int sum[N][2], f[N][2];

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1ll;
    }
    return tot;
}
void gmod(int &x){
    x%=mod;
}

namespace NTT{
    int in,g[N];
    void pre(int tl){
        int l=__lg(tl)+1;
        int n=(1<<l);
        g[0]=1;
        g[n]=ksm(31,1<<(21-l));
        for(int i=l;i;i--) g[1<<(i-1)]=g[1<<i]*g[1<<i]%mod;
        for(int i=0;i<n;i++) g[i]=g[i & (i-1)]*g[i & (-i)]%mod;
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
                    v=(*t)*k[i]%mod;
                    gmod(k[i]=(*k)+mod-v);
                    gmod((*k)+=v);
                }
            }
        }
    }
    void intt(int *f,int n){
        int v;
        for(int i=1;i<n;i<<=1){
            for(int *t=g,*j=f;j!=f+n;j+=(i<<1),t++){
                for(int *k=j;k!=j+i;k++){
                    gmod(v=(*k)+k[i]);
                    k[i]=(*t)*(*k+mod-k[i])%mod;
                    *k=v;
                }
            }
        }
        reverse(f+1,f+n);
        for(int i=0;i<n;i++) f[i]=f[i]*in%mod;
    }
    
    int A[N],B[N],C[N];
    void solve(int *s,int *f,int *g,int n,int m){
        int lim=init(n+m);
        for(int i=0;i<(1<<lim);i++) A[i]=B[i]=0;
        for(int i=0;i<=n;i++) A[i]=f[i];
        for(int i=0;i<=m;i++) B[i]=g[i];
        ntt(A,1<<lim);
        ntt(B,1<<lim);
        for(int i=0;i<(1<<lim);i++) C[i]=A[i]*B[i]%mod;
        intt(C,1<<lim);
        for(int i=0;i<=n+m;i++) s[i]=C[i];
    }
}

int F[N],G[N],H[N];
int suf[N];

void solve(){
    scanf("%lld", &n);
    scanf("%s", s1+1);
    scanf("%s", s2+1);
    scanf("%s", s3+1);
    sum[n+1][0]=sum[n+1][1]=0;
    for(int i=n; i>=1; --i){
        sum[i][0]=sum[i+1][0]+(s2[i]=='0');
        sum[i][1]=sum[i+1][1]+(s2[i]=='1');
    }
    for(int i=1; i<=n; ++i){
        f[i][0]=f[i-1][0]+(s2[i]=='0');
        f[i][1]=f[i-1][1]+(s2[i]=='1');
    }
    for(int i=n+1; i<=n*2; ++i){
        f[i][0]=f[i-1][0]; f[i][1]=f[i-1][1];
    }
    
    ll ans=0;
    
    for(int t=0;t<=1;t++){
        for(int i=0;i<=n;i++) F[i]=G[i]=0;
        for(int i=0;i<=n;i++) if(s1[i]-'0'==t) F[i]=1;
        for(int i=0;i<=n;i++) if(s3[i]-'0'==t) G[i]=1;
        NTT::solve(H,F,G,n,n);
        
        for(int i=n+1;i<=n*2;i++) ans+=1ll*H[i]*sum[1+2*n-i][t];
        for(int i=n;i<=n*2;i++) ans+=1ll*H[i]*f[2*n-1-i][t];
        
        // for(int k=n+1; k<=n*2; ++k){
        //     for(int i=k-n; i<=n; ++i){
        //         if(s1[i]-'0'==t && s3[k-i]-'0'==t){
        //             ans+=sum[1+2*n-k][t];
        //         }
        //     }
        // }
    }
    
    for(int t=0;t<=1;t++){
        
        suf[n+1]=0;
        for(int i=n;i>=1;i--) suf[i]=suf[i+1]+(s1[i]-'0'==t);
        for(int j=1; j<=n; ++j){
            if(s3[j]-'0'!=t) continue;
            
            // for(int i=max(j,n-j); i<=n; ++i){
            //     if(s1[i]-'0'==t) tot++;
            // }
            ans-=suf[max(j,n-j)]*f[n-1-j][t];
        }
        
        suf[n+1]=0;
        for(int i=n;i>=1;i--) suf[i]=suf[i+1]+(s3[i]-'0'==t);
        for(int i=1; i<=n; ++i){
            if(s1[i]-'0'!=t) continue;
            // int tot=0;
            // for(int j=max(i+1, n-i); j<=n; ++j){
            //     if(s3[j]-'0'==t) tot++;
            // }
            ans-=suf[max(i+1,n-i)]*f[n-1-i][t];
        }
        
        // for(int i=1; i<=n; ++i){
        //     for(int j=n-i; j<=n; ++j){
        //         if(s1[i]-'0'==t && s3[j]-'0'==t){
        //             ans+=f[2*n-1-i-j][t];
        //         }
        //     }
        // }
        
    }
    
    printf("%lld\n", ans);
}


signed main(){
    NTT::pre(4e5);
    scanf("%lld", &T);
    while(T--){
        solve();
    }
    
}


