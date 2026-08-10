#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5,INF=1e18;
int T,n;
int a[N];

int tr[N][2],cnt;
int s[N],L[N],R[N];

void dfs0(int u){
    if(!u) return ;
    int ls=tr[u][0],rs=tr[u][1];
    if(!ls && !rs){
        // cout<<"! "<<u<<" "<<s[u]<<endl;
        L[u]=1,R[u]=s[u];
    }
    else{
        dfs0(ls); dfs0(rs);
        L[u]=L[ls]+L[rs];
        R[u]=R[ls]+R[rs];
    }
}

int dfs(int d,int u,int k){
    if(!u) return 0;
    int ls=tr[u][0],rs=tr[u][1];
    int lx=L[ls],rx=R[ls];
    int ly=L[rs],ry=R[rs];
    int v=rs;
    if(lx>ly) swap(lx,ly),swap(rx,ry),v=ls;
    
    int res=0;
    if(rx+k>=ly) res=max(ly-k+max(lx,ly-k),0ll)*(1ll<<d);
    else res=dfs(d+1,v,rx+k)+2*rx*(1ll<<d);
    
    // cout<<d<<" "<<k<<": "<<lx<<","<<rx<<"  "<<ly<<","<<ry<<" -> "<<res<<endl;
    return res;
}

signed main(){
    // freopen("test/3.out","w",stdout);
    cin >> T;
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        
        cnt=1;
        for(int i=1;i<=n;i++){
            int u=1;
            for(int t=0;t<50;t++){
                int c=(a[i]>>t & 1ll);
                if(!tr[u][c]) tr[u][c]=++cnt;
                u=tr[u][c];
            }
            s[u]++;
        }
        
        dfs0(1);
        int ans=dfs(0,1,1);
        printf("%lld\n",ans);
        
        for(int i=1;i<=cnt;i++){
            tr[i][0]=tr[i][1]=0;
            s[i]=0;
        }
    }
}