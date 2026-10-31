#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,mod=998244353;
int T,n,m,ans;

int p[N],e[N],id;
void decomp(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i) continue;
        p[++id]=i; e[id]=0;
        while(n%i==0) n/=i,e[id]++;
    }
    if(n>1) p[++id]=n,e[id]=1;
}

void dfs(int d,int g,int phi,int q){
    if(d>id){
        // cout<<g<<" "<<phi<<" "<<q<<endl;
        ans=(ans+(m/q+1)%mod*(g%mod)%mod*(phi%mod)%mod)%mod;
        return ;
    }
    
    int x=p[d],c=e[d];
    phi=phi/x*(x-1);
    
    
    for(int i=0;i<=c;i++){
        dfs(d+1,g,phi,q);
        g*=x;
        if(!(i & 1)) q*=x;
        if(i<c-1) phi/=x;
        else phi/=x-1;
    }
}

signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&n,&m);
        ans=0;
        
        id=0;
        decomp(n);
        
        dfs(1,1,n,1);
        
        printf("%lld\n",ans);
    }
    
}