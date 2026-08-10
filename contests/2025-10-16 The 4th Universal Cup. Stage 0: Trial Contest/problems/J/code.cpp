#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+5,mod=998244353;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}

void gmodn(int &x){
    x+=x>>31 & mod;
}
void gmod(int &x){
    x%=mod;
}

int mul[N],inv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

int binom(int m,int n){
    if(n<0 || m<0 || m<n) return 0;
    return mul[m]*inv[n]%mod*inv[m-n]%mod;
}

namespace NTT{
    int in,g[N];
    void pre(int tl){
        int l=__lg(tl)+1;
        int n=1<<l;
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
        reverse(f+1,f+n);
        for(int i=0;i<n;i++) f[i]=1ll*f[i]*in%mod;
    }
    int A[N],B[N],C[N];
    void solve(int *s,int *f,int *g,int n,int m){
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
        
        ntt(A,1<<lim);
        ntt(B,1<<lim);
        
        for(int i=0;i<(1<<lim);i++) C[i]=1ll*A[i]*B[i]%mod;
        intt(C,1<<lim);
        for(int i=0;i<=n+m;i++) s[i]=C[i];
    }
}


int trans(char c){
    if(c=='B') return 0;
    else if(c=='Y') return 1;
    else return 2;
}

int n;
char S[N];

vector <int> P[N*4][3][3];
int TMP[N];
void solve(int l,int r,int o){
    if(l==r){
        int x=trans(S[l]);
        
        for(int i=0;i<=2;i++){
            for(int j=i;j<=2;j++){
                P[o][i][j]={0,0};
            }
        }
        P[o][x][x]={0,1};
        
        return ;
    }
    
    int mid=(l+r)>>1;
    solve(l,mid,o<<1);
    solve(mid+1,r,o<<1|1);
    
    int ls=o<<1,rs=o<<1|1;
    int lenl=mid-l+1,lenr=r-mid,len=lenl+lenr;
    for(int i=0;i<=2;i++){
        for(int j=i;j<=2;j++){
            P[o][i][j].resize(len+1);
        }
    }
    
    for(int i=0;i<=2;i++){
        for(int j=i;j<=2;j++){
            for(int t=0;t<=lenl;t++) gmod(P[o][i][j][t]+=P[ls][i][j][t]);
            for(int t=0;t<=lenr;t++) gmod(P[o][i][j][t]+=P[rs][i][j][t]);
            
            for(int p=j;p<=2;p++){
                for(int q=p;q<=2;q++){
                    NTT::solve(TMP,P[ls][i][j].data(),P[rs][p][q].data(),lenl,lenr);
                    for(int t=0;t<=len;t++) gmod(P[o][i][q][t]+=TMP[t]);
                }
            }
        }
    }
    
    // cout<<l<<" "<<r<<" "<<o<<": "<<endl;
    // for(int i=0;i<=2;i++){
    //     for(int j=i;j<=2;j++){
    //         cout<<"  "<<i<<" "<<j<<" | ";
    //         for(int t=0;t<=len;t++) cout<<P[o][i][j][t]<<" ";
    //         cout<<endl;
    //     }
    // }
}

int F[N];
signed main(){
    init(N-5);
    NTT::pre(4e5);
    
    scanf("%s",S+1);
    n=strlen(S+1);
    solve(1,n,1);
    
    for(int i=0;i<=2;i++){
        for(int j=i;j<=2;j++){
            for(int t=1;t<=n;t++){
                gmod(F[t]+=P[1][i][j][t]);
            }
        }
    }
    
    int ans=0;
    // for(int i=0;i<=n;i++) cout<<F[i]<<" "; cout<<endl;
    for(int i=1;i<=n;i++){
        gmod(ans+=(binom(n,i)+mod-F[i])%mod*ksm(binom(n,i),mod-2)%mod);
    }
    cout<<ans;
}
