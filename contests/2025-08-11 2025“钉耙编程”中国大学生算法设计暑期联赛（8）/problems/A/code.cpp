#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e4+5,M=51,INF=1e18;

int T,n,m,q;
int ans[N*10];

struct abc{
    int u,v,w,d;
}V[N];
bool operator <(abc X,abc Y){
    return X.w<Y.w;
}
int val[N];

struct que{
    int l,r,num;
};

int f[M][N],g[M][N],dp[M];

void solve(int l,int r,int o ,vector<que> Q){
    if(!Q.size()) return ;
    if(l==r){
        for(que x: Q){
            ans[x.num]=max(ans[x.num],V[l].d);
        }
        return ;
    }
    
    int mid=(l+r)>>1;
    vector<que> L,R;
    for(que x: Q){
        if(x.r<=mid) L.push_back(x);
        else if(x.l>mid) R.push_back(x);
    }
    
    solve(l,mid,o<<1,L);
    solve(mid+1,r,o<<1|1,R);
    
    int mx;
    for(int st=1;st<=n;st++){
        for(int i=1;i<=n;i++) dp[i]=-INF;
        dp[st]=0;
        mx=0;
        for(int i=mid;i>=l;i--){
            int u=V[i].u,v=V[i].v,d=V[i].d;
            dp[u]=max(dp[u],dp[v]+d);
            mx=max(mx,dp[u]);
            f[st][i]=mx;
        }
        
        for(int i=1;i<=n;i++) dp[i]=-INF;
        dp[st]=0;
        mx=0;
        for(int i=mid+1;i<=r;i++){
            int u=V[i].u,v=V[i].v,d=V[i].d;
            dp[v]=max(dp[v],dp[u]+d);
            mx=max(mx,dp[v]);
            g[st][i]=mx;
        }
    }
    
    
    for(que x: Q){
        if(x.r>mid && x.l<=mid){
            // cout<<l<<" "<<r<<" "<<mid<<endl;
            // cout<<"  "<<x.l<<" "<<x.r<<" "<<f[x.l]<<" "<<g[x.r]<<endl;
            for(int st=1;st<=n;st++){
                ans[x.num]=max(ans[x.num],f[st][x.l]+g[st][x.r]);
            }
        }
    }
}

signed main(){
    // freopen("2.txt","w",stdout);
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&q);
        for(int i=1;i<=m;i++){
            int u,v,w,d; scanf("%lld%lld%lld%lld",&u,&v,&w,&d);
            V[i]={u,v,w,d};
        }
        sort(V+1,V+m+1);
        
        for(int i=1;i<=m;i++) val[i]=V[i].w;
        // for(int i=1;i<=m;i++){
        //     cout<<" > "<<V[i].w<<"  "<<V[i].u<<" "<<V[i].v<<" "<<V[i].d<<endl;
        // }
        
        vector<que> Q;
        for(int i=1;i<=q;i++){
            int l,r; scanf("%lld%lld",&l,&r);
            l=lower_bound(val+1,val+m+1,l)-val;
            r=upper_bound(val+1,val+m+1,r)-val-1;
            
            // cout<<" # "<<l<<" "<<r<<endl;
            
            if(l<=r) Q.push_back((que){l,r,i});
            ans[i]=0;
        }
        solve(1,m,1,Q);
        
        for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
    }
}