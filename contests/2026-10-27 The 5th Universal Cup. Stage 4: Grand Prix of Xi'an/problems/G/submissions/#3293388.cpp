#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3300,INF=1e18;

int T,n,m,ans;
int a[N];

int f[N*4];
void build(int l,int r,int o){
    if(l==r){
        f[o]=a[l];
        return ;
    }
    int mid=(l+r)>>1,ls=o<<1,rs=o<<1|1;
    build(l,mid,ls);
    build(mid+1,r,rs);
    f[o]=min(f[ls],f[rs]);
}

int cal(int A,int B,int C,int D){
    int x,s=0;
    x=min(A,D); A-=x,D-=x,s+=x;
    x=min(B,C); B-=x,C-=x,s+=x;
    x=min(A,C); A-=x,C-=x,s+=x;
    s+=A+B+C+D;
    return s;
}

int dp[N*4],g[N*4];
void dfs(int l,int r,int u){
    if(l==r){
        dp[u]=f[u],g[u]=f[u];
        return ;
    }
    int mid=(l+r)>>1,ls=u<<1,rs=u<<1|1;
    dfs(l,mid,ls);
    dfs(mid+1,r,rs);
    
    int A=g[ls],B=dp[ls]-g[ls],C=g[rs],D=dp[rs]-g[rs];
    // cout<<"  "<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
    dp[u]=cal(A,B,C,D);
    
    // A=f[ls],B=dp[ls]-g[ls],C=f[rs],D=dp[rs]-g[rs];
    int L=0,R=f[u],tot=L;
    while(L<=R){
        int mid=(L+R)>>1;
        if(cal(A+max(0ll,mid-A)-mid,B,C+max(0ll,mid-C)-mid,D)+mid==dp[u]) tot=mid,L=mid+1;
        else R=mid-1;
    }
    g[u]=tot;
    
    // cout<<l<<" "<<r<<": "<<g[u]<<" "<<dp[u]<<endl;
}

signed main(){
    // freopen("G0.in","r",stdin);
    // freopen("G.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        scanf("%lld",&n);
        // int tans; cin>>tans;
        m=1<<n;
        for(int i=0;i<m;i++) scanf("%lld",&a[i]);
        
        build(0,m-1,1);
        dfs(0,m-1,1);
        int ans=dp[1];
        
        printf("%lld\n",ans);
    }
}