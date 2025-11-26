#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5500,mod=998244353,INF=1e9;

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

int mul[N],inv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
int binom(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return mul[m]*inv[n]%mod*inv[m-n]%mod;
}
int S2(int x){
    return x*(x+1)/2;
}

int n,a[N],b[N],c[N],d[N],e[N];

int f[N][N],g[N][N];
int F0[N],F1[N],F2[N];
int G0[N],G1[N],G2[N];

int CB[N],CC[N],SB[N],SC[N],CD[N],CE[N];
int C0[N],C1[N];

int cal1(int d,int t){
    if(d>=0) return (d>=t);
    else return max((-d)-t+1,0ll);
}
bool check(int d,int t){
    if(t<0) return 0;
    if(d>=0) return (d==t);
    return t<=(-d);
}
int getval(int *s,int l,int r){
    if(l>0) return (s[r]+mod-s[l-1])%mod;
    else return s[r];
}

signed main(){
    init(N-5);
    cin>>n;
    int m=0;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),m=max(m,abs(a[i]));
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&d[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&e[i]);
    
    int alc=1;
    for(int i=0;i<=n+1;i++){
        if(b[i]>=0) CB[i]=1,SB[i]=b[i];
        else CB[i]=-b[i]+1,SB[i]=S2(-b[i]);
        
        if(c[i]>=0) CC[i]=1,SC[i]=c[i];
        else CC[i]=-c[i]+1,SC[i]=S2(-c[i]);
        
        if(d[i]>=0) CD[i]=1;
        else CD[i]=-d[i]+1;
        
        if(e[i]>=0) CE[i]=1;
        else CE[i]=-e[i]+1;
        
        C0[i]=CB[i]*CD[i]%mod;
        C1[i]=CC[i]*CE[i]%mod;
        
        int CA=(a[i]>=0)?1:(-a[i]+1);
        alc=alc*C0[i]%mod*C1[i]%mod*CA%mod;
    }
    
    e[0]=INF; d[n+1]=INF;
    
    f[0][0]=1;
    for(int i=1;i<=n+1;i++){
        
        for(int j=0;j<=m;j++){
            F0[j]=F1[j]=F2[j]=0;
            G0[j]=G1[j]=G2[j]=0;
        }
        F0[0]=f[i-1][0];
        G0[0]=g[i-1][0];
        for(int j=1;j<=m;j++){
            gmod(F0[j]=F0[j-1]+f[i-1][j]);
            gmod(F1[j]=F1[j-1]+f[i-1][j]*j%mod);
            gmod(F2[j]=F2[j-1]+f[i-1][j]*j%mod*j%mod);
            
            gmod(G0[j]=G0[j-1]+g[i-1][j]);
            gmod(G1[j]=G1[j-1]+g[i-1][j]*j%mod);
            gmod(G2[j]=G2[j-1]+g[i-1][j]*j%mod*j%mod);
        }
        
        
        for(int j=0;j<=m;j++){
            if(!check(a[i],j)) continue;
            
            if(d[i]>=0){
                int L=j-min(j,d[i]),R=j;
                
                int val1=C1[i-1]*CB[i]%mod;
                gmod(f[i][j]+=getval(F0,L,R)*val1%mod);
                gmod(g[i][j]+=getval(G0,L,R)*val1%mod);
                
                int val2=C1[i-1]*SB[i]%mod;
                gmod(g[i][j]+=getval(F0,L,R)*val2%mod*j%mod);
                gmod(g[i][j]+=mod-getval(F1,L,R)*val2%mod);
                
                // for(int t=0;t<=min(j,d[i]);t++){
                //     int val1=C1[i-1]*CB[i]%mod;
                //     int val2=C1[i-1]*SB[i]%mod*(-(j-t)+j)%mod;
                    
                //     gmod(f[i][j]+=f[i-1][j-t]*val1%mod);
                //     gmod(g[i][j]+=g[i-1][j-t]*val1%mod);
                //     gmod(g[i][j]+=f[i-1][j-t]*val2%mod);
                // }
            }
            else{
                int x=-d[i];
                int L=j-min(j,x),R=j;
                
                int val1=C1[i-1]*CB[i]%mod;
                gmod(f[i][j]+=getval(F0,L,R)*val1%mod*(x+mod-j+1)%mod);
                gmod(f[i][j]+=getval(F1,L,R)*val1%mod);
                
                gmod(g[i][j]+=getval(G0,L,R)*val1%mod*(x+mod-j+1)%mod);
                gmod(g[i][j]+=getval(G1,L,R)*val1%mod);
                
                int val2=C1[i-1]*SB[i]%mod;
                gmod(g[i][j]+=getval(F0,L,R)*val2%mod*j%mod*(x+mod-j+1)%mod);
                gmod(g[i][j]+=getval(F1,L,R)*val2%mod*(2*j-x-1+mod)%mod);
                gmod(g[i][j]+=mod-getval(F2,L,R)*val2%mod);
                
                // for(int t=0;t<=min(j,x);t++){
                //     int s=j-t;
                //     int val1=C1[i-1]*CB[i]%mod*(s+(x-j+1))%mod;
                //     int val2=C1[i-1]%mod*SB[i]%mod*(-s*s%mod+s*(2*j-x-1)+j*(x-j+1))%mod;
                    
                //     gmod(f[i][j]+=f[i-1][j-t]*val1%mod);
                //     gmod(g[i][j]+=g[i-1][j-t]*val1%mod);
                //     gmod(g[i][j]+=f[i-1][j-t]*val2%mod);
                // }
            }
            
            if(e[i-1]>=0){
                int L=j+1,R=j+min(m-j,e[i-1]);
                
                int val1=C0[i]*CC[i-1]%mod;
                gmod(f[i][j]+=getval(F0,L,R)*val1%mod);
                gmod(g[i][j]+=getval(G0,L,R)*val1%mod);
                
                int val2=C0[i]*SC[i-1]%mod;
                gmod(g[i][j]+=mod-getval(F0,L,R)*val2%mod*j%mod);
                gmod(g[i][j]+=getval(F1,L,R)*val2%mod);
                
                // for(int t=1;t<=min(m-j,e[i-1]);t++){
                //     int val1=C0[i]*CC[i-1]%mod;
                //     int val2=C0[i]*SC[i-1]%mod*((j+t)-j)%mod;
                    
                //     gmod(f[i][j]+=f[i-1][j+t]*val1%mod);
                //     gmod(g[i][j]+=g[i-1][j+t]*val1%mod);
                //     gmod(g[i][j]+=f[i-1][j+t]*val2%mod);
                // }
            }
            else{
                int x=-e[i-1];
                int L=j+1,R=j+min(m-j,x);
                
                int val1=C0[i]*CC[i-1]%mod;
                gmod(f[i][j]+=getval(F0,L,R)*val1%mod*(x+j+1)%mod);
                gmod(f[i][j]+=mod-getval(F1,L,R)*val1%mod);
                
                gmod(g[i][j]+=getval(G0,L,R)*val1%mod*(x+j+1)%mod);
                gmod(g[i][j]+=mod-getval(G1,L,R)*val1%mod);
                
                int val2=C0[i]*SC[i-1]%mod;
                gmod(g[i][j]+=mod-getval(F0,L,R)*val2%mod*j%mod*(x+j+1)%mod);
                gmod(g[i][j]+=getval(F1,L,R)*val2%mod*(x+2*j+1)%mod);
                gmod(g[i][j]+=mod-getval(F2,L,R)*val2%mod);
                
                // for(int t=1;t<=min(m-j,x);t++){
                //     int s=j+t;
                //     int val1=C0[i]*CC[i-1]%mod*(x-s+j+1)%mod;
                //     int val2=C0[i]*SC[i-1]%mod*(mod-s*s%mod+s*(x+2*j+1)%mod+mod-j*(x+j+1)%mod)%mod;
                    
                //     gmod(f[i][j]+=f[i-1][j+t]*val1%mod);
                //     gmod(g[i][j]+=g[i-1][j+t]*val1%mod);
                //     gmod(g[i][j]+=f[i-1][j+t]*val2%mod);
                // }
            }
            
        }
    }
    
    cout<<g[n+1][0]<<" "<<(alc+mod-f[n+1][0])%mod;
    
}
