#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,INF=1e9;

int n,m;
int a[N];

int f[N][N];
int g[N];

int s(int t,int r){
    return r-1+t*m;
}

int q[N],head,tail;

signed main(){
    // freopen("1.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    
    for(int r=1;r<=m;r++){
        // cout<<r<<": "<<endl;
        
        int lim=(n-r)/m;
        
        int num=s(lim,r);
        for(int i=0;i<=num;i++){
            f[lim][i]=max(a[i+1],a[n-num+i]);
        }
        // for(int i=0;i<=num;i++) cout<<f[lim][i]<<" "; cout<<endl;
        
        for(int t=lim-1;t>=0;t--){
            num=s(t,r);
            
            head=1,tail=0;
            
            for(int i=0;i<=num+m;i++){
                while(tail>=head && f[t+1][q[tail]]>=f[t+1][i]) tail--;
                while(head<=tail && q[head]<=i-m) head++;
                q[++tail]=i;
                
                if(i>=m-1) g[i-m+1]=f[t+1][q[head]];
            }
            
            for(int i=0;i<=num;i++){
                f[t][i]=max(a[i+1]+g[i+1],a[n-num+i]+g[i]);
            }
            
            // cout<<t<<" "<<num<<": ";
            // for(int i=0;i<=num;i++) cout<<f[t][i]<<" "; cout<<endl;
        }
        
        int ans=INF;
        num=s(0,r);
        for(int i=0;i<=num;i++) ans=min(ans,f[0][i]);
        printf("%d ",ans);
        // cout<<endl;
    }
    
    
    
}