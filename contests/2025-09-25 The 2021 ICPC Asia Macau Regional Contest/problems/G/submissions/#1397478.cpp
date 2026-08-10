#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e6+5,INF=1e18;
int T,n,k;
int p[N],pos[N];
int pre[N][2];

int L[N][2],R[N][2];

int f[N*4];
void build(int l,int r,int o){
    f[o]=INF;
    if(l==r) return ;
    int mid=(l+r)>>1;
    build(l,mid,o<<1);
    build(mid+1,r,o<<1|1);
}
void modify(int l,int r,int o,int x,int k){
    if(l==r){
        f[o]=min(f[o],k);
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) modify(l,mid,o<<1,x,k);
    else modify(mid+1,r,o<<1|1,x,k);
    f[o]=min(f[o<<1],f[o<<1|1]);
}
int query(int l,int r,int o,int L,int R){
    // cout<<l<<" "<<r<<" "<<o<<endl;
    if(L>R) return INF;
    if(L<=l && r<=R) return f[o];
    int mid=(l+r)>>1,tot=INF;
    if(L<=mid) tot=min(tot,query(l,mid,o<<1,L,R));
    if(R>mid) tot=min(tot,query(mid+1,r,o<<1|1,L,R));
    return tot;
}

int dp[N][2];

int cal(int x){
    return (x%n+n)%n;
}

mt19937 rng(123);

signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&n,&k);
        for(int i=0;i<=n;i++) dp[i][0]=dp[i][1]=INF;
        for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
        
        // for(int i=1;i<=n;i++) p[i]=i;
        // shuffle(p+1,p+n+1,rng);
        
        
        for(int i=1;i<=n;i++) pos[p[i]]=i;
        pos[0]=1;
        // for(int i=0;i<=n;i++) cout<<pos[i]<<" "; cout<<endl;
        
        
        for(int i=0;i<=n;i++){
            L[i][0]=pos[i];
            R[i][0]=pos[i]+k-1;
            
            L[i][1]=pos[i]-k+1;
            R[i][1]=pos[i];
        }
        
        build(1,2*n,1);
        
        for(int i=n;i>=0;i--){
            pre[i][0]=query(1,2*n,1,R[i][0]+1,L[i][0]+n-1); // L[i][0] - R[i][0]
            pre[i][1]=query(1,2*n,1,R[i][1]+1,L[i][1]+n-1); // L[i][1] - R[i][1]
            
            modify(1,2*n,1,pos[i],i);
            modify(1,2*n,1,pos[i]+n,i);
            
            // cout<<i<<": "<<pre[i][0]<<" "<<pre[i][1]<<endl;
        }
        
        // cout<<"dp"<<endl;
        int ans=INF;
        dp[0][0]=0;
        for(int i=0;i<=n;i++){
            // cout<<i<<": "<<dp[i][0]<<" "<<dp[i][1]<<endl;
            
            for(int t=0;t<=1;t++){
                if(dp[i][t]>=INF) continue;
                int nxt=pre[i][t];
                if(nxt>n){
                    ans=min(ans,dp[i][t]);
                    continue;
                }
                
                dp[nxt][0]=min(dp[nxt][0],dp[i][t]+cal(L[i][t]-pos[nxt]));
                dp[nxt][1]=min(dp[nxt][1],dp[i][t]+cal(pos[nxt]-R[i][t]));
                // cout<<" -> "<<nxt<<" "<<0<<" "<<
            }
        }
        printf("%lld\n",ans);
    }
}
