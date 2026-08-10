#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=880,mod=998244353;
int T,n,m;
int a[N];

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
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return mul[m]*inv[n]%mod*inv[m-n]%mod;
}


void Gauss(int a[N][N],int *b,int *s,int n){
    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) cout<<a[i][j]<<" ";
    //     cout<<" : "<<b[i]<<endl;
    // }
    
    
    for(int k=1;k<=n;k++){
        int st=k;
        for(int i=k+1;i<=n;i++){
            if(a[i][k]>a[st][k]) st=i;
        }
        if(!a[st][k]) continue;
        
        for(int j=1;j<=n;j++) swap(a[k][j],a[st][j]);
        swap(b[k],b[st]);
        
        for(int i=k+1;i<=n;i++){
            int t=a[i][k]*ksm(a[k][k],mod-2)%mod;
            for(int j=1;j<=n;j++) gmod(a[i][j]+=mod-t*a[k][j]%mod);
            gmod(b[i]+=mod-t*b[k]%mod);
        }
    }
    for(int k=n;k>=1;k--){
        s[k]=b[k]*ksm(a[k][k],mod-2)%mod;
        for(int i=k;i>=1;i--){
            gmod(b[i]+=mod-a[i][k]*s[k]%mod);
            a[i][k]=0;
        }
    }
    // for(int i=1;i<=n;i++) cout<<s[i]<<" "; cout<<endl;
}

int A[N][N],B[N],f[N];

signed main(){
    init(N-5);
    
    cin>>T;
    while(T--){
        scanf("%lld%lld",&n,&m);
        
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=0;i<=2*m;i++){
            for(int j=0;j<=2*m;j++) A[i][j]=0;
            B[i]=0;
        }
        
        int alc=ksm(C(2*m,m),mod-2);
        for(int x=1;x<=m*2;x++){
            for(int i=0;i<=m;i++){
                int val=C(x,i)*C(2*m-x,m-i)%mod*alc%mod;
                if(!val) continue;
                gmod(A[x][2*i]+=val);
            }
            gmod(A[x][x]+=mod-1);
            B[x]=x*ksm(2*m,mod-2)%mod;
        }
        
        Gauss(A,B,f,2*m);
        
        int ans=0;
        for(int i=1;i<=n;i++) gmod(ans+=f[a[i]]);
        printf("%lld\n",(mod-ans)%mod);
    }
    
}


