#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+5,INF=1e18;

int T,n,m,ans;
int a[N];

int cal(int A,int B,int C,int D){
    int x,s=0;
    x=min(A,D); A-=x,D-=x,s+=x;
    x=min(B,C); B-=x,C-=x,s+=x;
    x=min(A,C); A-=x,C-=x,s+=x;
    s+=A+B+C+D;
    return s;
}

int f[N*4],dp[N*4],g[N*4];
void dfs(int l,int r,int u){
    if(l==r){
        f[u]=a[l];
        dp[u]=a[l],g[u]=a[l];
        return ;
    }
    int mid=(l+r)>>1,ls=u<<1,rs=u<<1|1;
    dfs(l,mid,ls);
    dfs(mid+1,r,rs);
    f[u]=min(f[ls],f[rs]);
    
    int A=g[ls],B=dp[ls]-g[ls],C=g[rs],D=dp[rs]-g[rs];
    dp[u]=cal(A,B,C,D);
    
    int L=0,R=f[u],tot=L;
    while(L<=R){
        int mid=(L+R)>>1;
        if(cal(A+max(0ll,mid-A)-mid,B,C+max(0ll,mid-C)-mid,D)+mid==dp[u]) tot=mid,L=mid+1;
        else R=mid-1;
    }
    g[u]=tot;
}

signed main(){
    cin>>T;
    while(T--){
        ans=0;
        scanf("%lld",&n);
        m=1<<n;
        for(int i=0;i<m;i++) scanf("%lld",&a[i]);
        
        dfs(0,m-1,1);
        int ans=dp[1];
        
        printf("%lld\n",ans);
    }
}