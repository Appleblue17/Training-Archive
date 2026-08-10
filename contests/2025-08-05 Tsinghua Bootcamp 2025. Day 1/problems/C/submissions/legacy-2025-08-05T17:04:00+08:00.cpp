#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5,mod=998244353;
void gmodn(int &x){x+=x>>31&mod;}
void gmod(int &x){x%=mod;}
int ksm(int x, int y){
    int ret=1;
    while(y){
        if(y & 1) ret=1ll*ret*x%mod;
        x=1ll*x*x%mod;
        y>>=1;
    }
    return ret;
}
namespace NTT{
    int in, g[N];
    void pre(int tl){
        int l=__lg(tl)+1;
        int n=(1<<l);
        g[0]=1;
        g[n]=ksm(31, 1<<(21-l));
        for(int i=l; i; i--) g[1<<(i-1)]=1ll*g[1<<i]*g[1<<i]%mod;
        for(int i=0; i<n; ++i) g[i]=1ll*g[i&(i-1)]*g[i&(-i)]%mod;
    }
    int init(int tl){
        int l=__lg(tl)+1;
        in=mod-((mod-1)>>l);
        return l;
    }
    void ntt(int *f, int n){
        int v;
        for(int i=(n>>1); i; i>>=1){
            for(int *t=g, *j=f; j!=f+n; j+=(i<<1), ++t){
                for(int *k=j; k!=j+i; ++k){
                    v=1ll*(*t)*k[i]%mod;
                    gmodn(k[i]=(*k)-v);
                    gmodn((*k)+=v-mod);
                }
            }
        }
    }
    void intt(int *f, int n){
        int v;
        for(int i=1; i<n; i<<=1){
            for(int *t=g, *j=f; j!=f+n; j+=(i<<1), ++t){
                for(int *k=j; k!=j+i; ++k){
                    gmodn(v=(*k)+k[i]-mod);
                    k[i]=1ll*(*t)*(*k-k[i]+mod)%mod;
                    *k=v;
                }
            }
        }
        reverse(f+1, f+n);
        for(int i=0; i<n; ++i) f[i]=1ll*f[i]*in%mod;
    }
    int A[N], B[N], C[N];
    void solve(int *s, int *f, int *g, int n, int m){
        // if(n+m<=150){
        //     for(int i=0; i<=n+m; ++i) C[i]=0;
        //     for(int i=0; i<=n; ++i){
        //         for(int j=0; j<=m; ++j){
        //             gmodn(C[i+j]+=1ll*f[i]*g[j]%mod-mod);
        //         }
        //     }
        //     for(int i=0; i<=n+m; ++i) s[i]=C[i];
        //     return ;
        // }
        int lim=init(n+m);
        for(int i=0; i<(1<<lim); ++i) A[i]=B[i]=0;
        for(int i=0; i<=n; ++i) A[i]=f[i];
        for(int i=0; i<=m; ++i) B[i]=g[i];
        ntt(A, (1<<lim));
        ntt(B, (1<<lim));
        for(int i=0; i<(1<<lim); ++i) C[i]=1ll*A[i]*B[i]%mod;
        intt(C, (1<<lim));
        for(int i=0; i<=n+m; ++i) s[i]=C[i];
    }
}

int n;
char S[N],T[N];

vector<int> get1(int x){
    x=(x+n)%n;
    int lst=(x+n-1)%n;
    
    int A=0,B=0;
    if(S[lst]=='W') B++;
    else if(S[lst]=='B') A++;
    
    if(S[x]=='W') B++;
    else if(S[x]=='B') A++;
    
    if(T[x]=='W') B++;
    else if(T[x]=='B') A++;
    
    return vector<int>{A,B,0};
}
int get2(int x){
    x=(x+n)%n;
    if(S[x]=='W') return 2;
    else if(S[x]=='B') return 1;
    else return 0;
}

vector <int> P[N*4],Q[N*4],R[N*4],W[N*4];

int A[N],B[N];

void solve(int l,int r,int o){
    if(l==r){
        P[o]=get1(l);
        Q[o]=R[o]=vector<int>{1,0,0};
        W[o]=vector<int>{0,0,0};
        return ;
    }
    int mid=(l+r)>>1;
    
    solve(l,mid,o<<1);
    solve(mid+1,r,o<<1|1);
    
    int len=(r-l+1)*2,lenl=(mid-l+1)*2,lenr=(r-mid)*2;
    P[o].resize(len+1);
    Q[o].resize(len+1);
    R[o].resize(len+1);
    W[o].resize(len+1);
    P[o].clear(),Q[o].clear(),R[o].clear(),W[o].clear();
    
    int k=get2(mid);
    
    NTT::solve(A,P[o<<1].data(),P[o<<1|1].data(),lenl,lenr);
    NTT::solve(B,R[o<<1].data(),Q[o<<1|1].data(),lenl,lenr);
    for(int i=0;i<=len;i++) gmod(P[o][i]+=A[i]);
    if(k==1) for(int i=0;i<=len;i++) gmod(P[o][i]+=mod-B[i]);
    else if(k==2) for(int i=0;i<=len-2;i++) gmod(P[o][i+2]+=mod-B[i]);
    
    NTT::solve(A,Q[o<<1].data(),P[o<<1|1].data(),lenl,lenr);
    NTT::solve(B,W[o<<1].data(),Q[o<<1|1].data(),lenl,lenr);
    for(int i=0;i<=len;i++) gmod(Q[o][i]+=A[i]);
    if(k==1) for(int i=0;i<=len;i++) gmod(Q[o][i]+=mod-B[i]);
    else if(k==2) for(int i=0;i<=len-2;i++) gmod(Q[o][i+2]+=mod-B[i]);
    
    NTT::solve(A,P[o<<1].data(),R[o<<1|1].data(),lenl,lenr);
    NTT::solve(B,R[o<<1].data(),W[o<<1|1].data(),lenl,lenr);
    for(int i=0;i<=len;i++) gmod(R[o][i]+=A[i]);
    if(k==1) for(int i=0;i<=len;i++) gmod(R[o][i]+=mod-B[i]);
    else if(k==2) for(int i=0;i<=len-2;i++) gmod(R[o][i+2]+=mod-B[i]);
    
    NTT::solve(A,Q[o<<1].data(),R[o<<1|1].data(),lenl,lenr);
    NTT::solve(B,W[o<<1].data(),W[o<<1|1].data(),lenl,lenr);
    for(int i=0;i<=len;i++) gmod(W[o][i]+=A[i]);
    if(k==1) for(int i=0;i<=len;i++) gmod(W[o][i]+=mod-B[i]);
    else if(k==2) for(int i=0;i<=len-2;i++) gmod(W[o][i+2]+=mod-B[i]);
    
    // cout<<l<<" "<<r<<" "<<o<<": "<<k<<endl;
    // for(int i=0;i<=len;i++) cout<<P[o][i]<<" "; cout<<endl;
    // for(int i=0;i<=len;i++) cout<<Q[o][i]<<" "; cout<<endl;
    // for(int i=0;i<=len;i++) cout<<R[o][i]<<" "; cout<<endl;
    // for(int i=0;i<=len;i++) cout<<W[o][i]<<" "; cout<<endl;
}

int ID(int x){
    return (x & 1)?mod-1:1;
}

int ANS[N];

signed main(){
    // freopen("2.txt","w",stdout);
    NTT::pre(3e5);
    scanf("%d",&n);
    scanf("\n%s",S);
    scanf("\n%s",T);
    
    int len,k;
    solve(1,n-1,1);
    len=(n-1)*2;
    // for(int i=0;i<=len;i++) cout<<P[1][i]<<" "; cout<<endl;
    vector <int> U=get1(0);
    for(int i=0;i<=len;i++){
        gmod(ANS[i]+=1ll*P[1][i]*U[0]%mod);
        gmod(ANS[i+1]+=1ll*P[1][i]*U[1]%mod);
    }
    
    len=(n-2)*2;
    k=get2(0);
    if(k==1) for(int i=0;i<=len;i++) gmod(ANS[i]+=mod-Q[1][i]);
    else if(k==2) for(int i=0;i<=len;i++) gmod(ANS[i+2]+=mod-Q[1][i]);
    
    len=(n-2)*2;
    k=get2(n-1);
    if(k==1) for(int i=0;i<=len;i++) gmod(ANS[i]+=mod-R[1][i]);
    else if(k==2) for(int i=0;i<=len;i++) gmod(ANS[i+2]+=mod-R[1][i]);
    
    int w=mod-2,sum=0;
    for(int i=0;i<n;i++){
        int k=get2(i);
        if(!k) w=0;
        else if(k==2) sum++;
    }
    // cout<<sum<<" "<<w<<endl;
    gmod(ANS[sum]+=w);
    
    for(int i=0;i<=n;i++) cout<<ANS[i]<<" ";
}