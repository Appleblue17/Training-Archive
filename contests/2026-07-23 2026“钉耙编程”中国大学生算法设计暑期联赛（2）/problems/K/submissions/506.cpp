#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,INF=1e18;
int T,n;
int a[N];

int tr[N][2],cnt;
int s[N];

void dfs0(int u){
    if(!u) return ;
    int ls=tr[u][0],rs=tr[u][1];
    dfs0(ls); dfs0(rs);
    s[u]+=s[ls]+s[rs];
}

int dfs(int d,int u,int k){
    if(!u) return 0;
    int ls=tr[u][0],rs=tr[u][1];
    int x=s[ls],y=s[rs],v=rs;
    if(x>y) swap(x,y),v=ls;
    
    if(y<=x+k) return max(x+y-k,0ll)*(1ll<<d);
    return (dfs(d+1,v,x+k)+2*x)*(1ll<<d);
}

signed main(){
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
}/gdfgdf