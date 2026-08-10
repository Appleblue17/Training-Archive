#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=4e5+5,mod=998244353;
int T,n,m;

int fa[19][N];

int getf(int *f,int x){
    if(f[x]==x) return x;
    return f[x]=getf(f,f[x]);
}

void merge(int t,int x,int y){
    int fx=getf(fa[t],x),fy=getf(fa[t],y);
    if(fx==fy) return ;
    fa[t][fx]=fy;
    
    // if(t==0){
    //     cout<<"merge "<<x<<" "<<y<<endl;
    // }
    
    if(t>0){
        merge(t-1,x,y);
        merge(t-1,x+(1<<(t-1)),y+(1<<(t-1)));
    }
}

void gmod(int &x){
    x%=mod;
}

bool vis[N];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n*2;i++) vis[i]=0;
        
        for(int t=0;t<=18;t++){
            for(int i=1;i<=n*2;i++){
                fa[t][i]=i;
            }
        }
        
        for(int i=1;i<=n;i++) merge(0,i,2*n-i+1);
        
        for(int i=1;i<=m;i++){
            int l,r; scanf("%d%d",&l,&r);
            int k=log2(r-l+1);
            merge(k,l,2*n-r+1);
        }
        
        int ans=1;
        int lst=0;
        for(int i=1;i<=n;i++){
            int fx=getf(fa[0],i);
            // cout<<fx<<" ";
            if(!vis[fx]){
                ans=1ll*ans*26%mod,lst=fx;
            }
            vis[fx]=1;
        }
        
        // cout<<lst<<endl;
        printf("%d\n",ans);
        for(int t=0;t<20;t++){
            for(int i=1;i<=n;i++){
                int fx=getf(fa[0],i);
                if(fx==lst) printf("%c",'a'+t);
                else printf("a");
            }
            printf("\n");
        }
    }
}