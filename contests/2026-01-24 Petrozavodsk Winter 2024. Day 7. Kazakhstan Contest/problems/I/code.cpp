#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+5,mod=1e9+7,mod1=mod-1,inv2=(mod+1)/2;

int ksm(int a,int x){
    x=(x%mod1+mod1)%mod1;
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1ll;
    }
    return tot;
}

int mul[N],inv[N],pw[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
    
    pw[0]=10;
    for(int i=1;i<=lim;i++) pw[i]=1ll*pw[i-1]*pw[i-1]%mod;
}
int binom(int m,int n){
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

int n,m,ans=1;
int a[N],b[N];

int pos1[N],id1;
int pos2[N],id2;


int cal(int A,int B,int C,int D,int w){
    if(w==1) return 1;
    int alc=A*C+B*C+A*D;
    int tot0=ksm(w,alc);
    int x=1ll*w*ksm(w-1,mod-2)%mod,ix=ksm(x,mod-2);
    
    int tot=0;
    for(int i=0;i<=A;i++){
        // for(int j=0;j<=C;j++){
        //     int sum=-B*j-D*i-A*j-C*i+i*j;
        //     gmod(tot+=1ll*ID(i+j)*binom(A,i)%mod*binom(C,j)%mod*ksm(x,mod-1+sum)%mod);
        // }
        gmod(tot+=1ll*ID(i)*binom(A,i)%mod*ksm(ix,i*(C+D))%mod*ksm(1+mod-ksm(x,i-(A+B)),C)%mod);
    }
    return 1ll*tot*tot0%mod;
}

signed main(){
    init(N-5);
    
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    
    if(a[n]!=b[m]) return cout<<0,0;
    for(int i=n;i>=1;i--){
        if(a[i]!=a[i-1]) pos1[++id1]=i;
    }
    for(int i=m;i>=1;i--){
        if(b[i]!=b[i-1]) pos2[++id2]=i;
    }
    
    pos1[0]=n+1,pos2[0]=m+1;
    int i=0,j=0;
    while(i<id1 || j<id2){
        int x=pos1[i],y=pos2[j];
        
        if(i<id1 && j<id2){
            if(a[pos1[i+1]]>b[pos2[j+1]]) i++;
            else if(a[pos1[i+1]]<b[pos2[j+1]]) j++;
            else i++,j++;
        }
        else if(i<id1) i++;
        else if(j<id2) j++;
        
        int nx=pos1[i],ny=pos2[j];
        int A=x-nx,C=y-ny,B=n-x+1,D=m-y+1;
        
        ans=1ll*ans*cal(A,B,C,D,min(a[nx],b[ny]))%mod;
        // cout<<nx<<" "<<ny<<": "<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<min(a[nx],b[ny])<<" "<<ans<<endl;
    }
    cout<<ans;
    
    
}

