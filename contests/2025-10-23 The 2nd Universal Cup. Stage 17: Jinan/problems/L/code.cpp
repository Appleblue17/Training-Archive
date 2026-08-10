#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5;
const ll INF=1e18;
int T,n,m;
int id;

vector < pair<int,int> > V[N];

ll dp[2][N];
int ct;

ll ans[N];

int fa[N];
int getf(int x){
    if(x==fa[x]) return x;
    return fa[x]=getf(fa[x]);
}

ll bl[N],SUM;

void upd(int pos,int lim){
    pos=getf(pos);
    while(pos<lim && bl[pos]<=0){
        int x=getf(pos+1);
        // cout<<lim<<" "<<pos<<" "<<x<<endl;
        if(x<lim) SUM+=bl[pos];
        bl[x]+=bl[pos];
        if(pos<lim) SUM-=bl[pos];
        bl[pos]-=bl[pos];
        
        fa[pos]=x;
        pos=x;
    }
}

signed main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) V[i].clear();
        
        id=0;
        for(int t=1;t<=m;t++){
            int l,r,v; scanf("%d%d%d",&l,&r,&v);
            l++;
            V[r].push_back({l,v});
        }
        
        ct=0;
        for(int i=0;i<=n+1;i++) dp[ct][i]=-INF;
        dp[ct][0]=0;
        
        for(int t=1;t<=n;t++){
            ct^=1;
            
            SUM=dp[ct^1][0];
            for(int i=0;i<=n;i++) bl[i]=dp[ct^1][i+1]-dp[ct^1][i];
            
            for(int i=0;i<=n+1;i++) fa[i]=i;
            
            dp[ct][0]=-INF;
            for(int i=1;i<=n+1;i++){
                ll sum=SUM;
                
                dp[ct][i]=sum;
                
                SUM+=bl[i-1];
                upd(i-1,i);
                
                for(pair<int,int> u: V[i]){
                    if(u.first<t) continue;
                    int l=u.first-1,val=u.second;
                    
                    l=getf(l);
                    bl[l]-=val;
                    if(l<i) SUM-=val;
                    SUM+=val;
                    
                    upd(l,i);
                }
            }
            
            // cout<<"   "<<t<<": ";
            // for(int i=1;i<=n+1;i++) cout<<dp[ct][i]<<" "; cout<<endl;
            ans[t]=dp[ct][n+1];
        }
        for(int i=n;i>=1;i--){
            printf("%lld",ans[i]);
            if(i>1) printf(" ");
        }
        printf("\n");
        
    }
    
}
