#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=500,mod=998244353,inv2=(mod+1)/2;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1ll;
    }
    return tot;
}

int mul[N],inv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int C(int m,int n){
    if(m<n || m<0 || n<0) return 0;
    return 1ll*mul[m]*inv[n]%mod*inv[m-n]%mod;
}
int ID(int x){
    return (x & 1ll)?mod-1:1;
}

void gmod(int &x){
    x%=mod;
}
void gmodn(int &x){
    x+=(x>>31 & mod);
}

// namespace NTT{
//     int in,g[N];
//     void pre(int tl){
//         int l=__lg(tl)+1;
//         int n=(1<<l);
//         g[0]=1;
//         g[n]=ksm(31,1<<(21-l));
//         for(int i=l;i;i--) g[1<<(i-1)]=1ll*g[1<<i]*g[1<<i]%mod;
//         for(int i=0;i<n;i++) g[i]=1ll*g[i & (i-1)]*g[i & (-i)]%mod;
//     }
//     int init(int tl){
//         int l=__lg(tl)+1;
//         in=mod-((mod-1)>>l);
//         return l;
//     }
//     void ntt(int *f,int n){
//         int v;
//         for(int i=(n>>1);i;i>>=1)
//             for(int *t=g,*j=f;j!=f+n;j+=(i<<1),t++)
//                 for(int *k=j;k!=j+i;k++){
//                     v=1ll*(*t)*k[i]%mod;
//                     gmodn(k[i]=(*k)-v);
//                     gmodn((*k)+=v-mod);
//                 }
//     }
    
//     void intt(int *f,int n){
//         int v;
//         for(int i=1;i<n;i<<=1)
//             for(int *t=g,*j=f;j!=f+n;j+=(i<<1),t++)
//                 for(int *k=j;k!=j+i;k++){
//                     gmodn(v=(*k)+k[i]-mod);
//                     k[i]=1ll*(*t)*(*k+mod-k[i])%mod;
//                     *k=v;
//                 }
//         reverse(f+1,f+n);
//         for(int i=0;i<n;i++) f[i]=1ll*f[i]*in%mod;
//     }
    
//     int A[N],B[N],C[N];
//     void solve(int *s,int *f,int *g,int n,int m){
//         int lim=init(n+m);
//         for(int i=0;i<(1<<lim);i++) A[i]=B[i]=0;
//         for(int i=0;i<=n;i++) A[i]=f[i];
//         for(int i=0;i<=m;i++) B[i]=g[i];
//         ntt(A,1<<lim);
//         ntt(B,1<<lim);
        
//         for(int i=0;i<(1<<lim);i++) C[i]=1ll*A[i]*B[i]%mod;
//         intt(C,1<<lim);
//         for(int i=0;i<=n+m;i++) s[i]=C[i];
//     }
// }

int n;
int dp[N][N][N];

signed main(){
    // NTT::pre(4e5);
    init(N-5);
    
    cin>>n;
    dp[0][0][1]=1;
    for(int t=0;t<n;t++){
        for(int i=0;i<=t*2;i++){
            for(int j=0;j<=t+1;j++){
                int val=dp[t][i][j];
                if(!val) continue;
                gmod(dp[t+1][i+1][j]+=1ll*val*i%mod);
                gmod(dp[t+1][i+2][j]+=1ll*val*i%mod);
                gmod(dp[t+1][i+1][j+1]+=1ll*val*j%mod);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n*2;i++){
        for(int j=0;j<=n+1;j++){
            gmod(ans+=dp[n][i][j]);
        }
    }
    cout<<ans;
}
