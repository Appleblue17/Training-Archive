#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
const int M=330,mod=998244353,inv2=(mod+1)/2;
  
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1ll;
    }
    return tot;
}
  
int mul[M],inv[M];
int S1[M][M];
  
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=1ll*mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
      
    S1[0][0]=1;
    for(int i=1;i<=lim;i++){
        for(int j=1;j<=i;j++) S1[i][j]=(1ll*(i-1)*S1[i-1][j]%mod+S1[i-1][j-1])%mod;
    }
}
void gmod(int &x){
    x%=mod;
}
int ID(int x){
    return (x & 1)?mod-1:1;
}
  
long long n,m;
queue <long long> q;
map <long long,long long> mp;
long long p[M],id;
 
int f[M][M],dep[M][M];
int ans[M];
  
int F[M],G[M];
 
signed main(){
    init(M-1);
    cin>>n;
    m=ceil(log2(n))*4;
     
    q.push(n);
    while(q.size()){
        long long x=q.front(); q.pop();
        if(x==1 || mp[x]) continue ;
        p[++id]=x;
        mp[x]=id;
        q.push((x+1)/2);
        q.push(x/2);
    }
    p[++id]=1; mp[1]=id;
 
    for(int i=0;i<=m;i++) dep[1][i]=i;
    for(int t=1;t<id;t++){
        long long x=p[t];
        int ls=mp[x/2],rs=mp[(x+1)/2];
        for(int i=0;i<=m;i++){
            gmod(dep[ls][i]+=1ll*dep[t][i]*i%mod);
            gmod(dep[rs][i]+=1ll*dep[t][i]*i%mod);
        }
    }
     
    for(int i=0;i<=m;i++) f[id][i]=i;
    for(int i=0;i<=m;i++) gmod(ans[i]+=dep[id][i]);
     
    for(int t=id-1;t>=1;t--){
        long long x=p[t];
        int ls=mp[x/2],rs=mp[(x+1)/2];
        for(int i=0;i<=m;i++){
            int wf=1ll*(f[ls][i]+f[rs][i])*inv2%mod;
            gmod(f[t][i]+=1ll*(1+wf+1ll*(wf+mod-i)*i%mod)%mod*i%mod);
              
            int tmp=1ll*f[ls][i]*f[rs][i]%mod;
            gmod(tmp+=mod-1ll*i*i%mod+1); // 不允许两边都不选
            gmod(ans[i]+=1ll*tmp*dep[t][i]%mod);
        }
    }
      
    for(int i=0;i<=m;i++){
        for(int j=0;i+j<=m;j++){
            F[i+j]=(F[i+j]+1ll*ans[i]*inv[i]%mod*inv[j]%mod*ID(j)%mod)%mod;
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=i;j++){
            G[j]=(G[j]+1ll*F[i]*S1[i][j]%mod*ID(i-j)%mod)%mod;
        }
    }
    int lim=min(200000ll,n*2);
    for(int i=1;i<=lim;i++){
        if(i<=m) printf("%d\n",G[i]);
        else printf("0\n");
    }
}
