#include <bits/stdc++.h>
using namespace std;
const int N=1100;
int T,n,m;
bool f[N][N],ans[N][N];

bool vis[N*4];

bool solve(int n,int m){
    if(n*m%2) return 0;
    memset(vis,0,sizeof(vis));
    
    bool fl=0;
    if(n>m) swap(n,m),fl=1;
    if(n<=10 && m>(1<<n)) return 0;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            f[i][j]=0;
    
    int k=min(10,n),id=0;
    
    int sm=m;
    if(m%2==1){
        for(int i=1;i<=n;i++) f[i][m]=1;
        for(int i=1;i<=n/2;i++) f[i*2][m]=0;
        m--;
        
        int tot=0;
        for(int i=1;i<=n/2;i++){
            tot |= 1<<min(i*2-2,k);
        }
        if(tot<(1<<k)) vis[tot]=1;
    }
    
    int l=max(1,n-1-m/2+1);
    // cout<<"l="<<l<<endl;
    for(int i=1;i<=n-1-l+1;i++){
        id++;
        for(int j=1;j<=n;j++) f[j][id]=1,f[j][id+m/2]=0;
        
        int mac=0;
        for(int j=1;j<=l;j++){
            mac |= 1<<min(j+i-2,k);
            f[j+i][id]=0;
            f[j+i][id+m/2]=1;
        }
        if(mac<(1<<k)){
            assert(!vis[mac]);
            // cout<<mac<<endl;
            vis[mac]=1;
        }
    }
    
    // cout<<id<<endl;
    
    for(int t=0;t<=k-1 && id<m/2;t++){
        for(int mac=0;mac<(1<<(k-1)) && id<m/2;mac++){
            if(vis[mac]) continue;
            int c=__builtin_popcount(mac);
            if(c!=t) continue;
            
            id++;
            for(int j=1;j<=n;j++) f[j][id]=1,f[j][id+m/2]=0;
            
            for(int j=0;j<k-1;j++){
                bool x=(mac>>j & 1);
                f[j+2][id]=x^1;
                f[j+2][id+m/2]=x;
            }
        }
    }
    
    if(id<m/2) return 0;
    
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sm;j++){
            if(!fl) ans[i][j]=f[i][j];
            else ans[j][i]=f[i][j];
        }
    }
    
    return 1;
}

signed main(){
    // freopen("C.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        // cout<<n<<" "<<m<<endl;
        
        if(n==2 && m==3){
            printf("YES\n011\n001\n");
        }
        else if(n==3 && m==2){
            printf("YES\n00\n01\n11\n");
        }
        else if(!solve(n,m)) printf("NO\n");
        else{
            
            int tot=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    tot+=ans[i][j];
            assert(tot==n*m/2);
            
            printf("YES\n");
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++) printf("%d",ans[i][j]);
                printf("\n");
            }
        }
    }
}
