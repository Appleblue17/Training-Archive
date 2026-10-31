#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+5,INF=1e18;

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

int dp[N*4];
void dfs(int l,int r,int o){
    if(l==r){
        dp[o]=f[o];
        return ;
    }
    int mid=(l+r)>>1,ls=o<<1,rs=o<<1|1;
    dfs(l,mid,ls);
    dfs(mid+1,r,rs);
    if(f[ls]>f[rs]) swap(ls,rs);
    dp[o]=dp[rs]+max(0ll,dp[ls]-f[rs]);
    
    // cout<<o<<": "<<f[o]<<" "<<dp[o]<<endl;
}

signed main(){
    cin>>T;
    while(T--){
        ans=0;
        scanf("%lld",&n);
        m=1<<n;
        for(int i=0;i<m;i++) scanf("%lld",&a[i]);
        
        build(0,m-1,1);
        dfs(0,m-1,1);
        printf("%lld\n",dp[1]);
    }
}