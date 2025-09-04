#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+5;

int T,n,k;
int a[N],b[N],c[N],d[N];

void proc(int *a,int n){
    for(int i=1;i<=n;i++){
        if(a[i]>=k){
            a[i+1]+=a[i]/k;
            a[i]%=k;
        }
        else if(a[i]<0){
            int d=(-a[i]+k-1)/k;
            a[i+1]-=d;
            a[i]+=d*k;
        }
    }
}

void mult(int *f,int *g,int n,int x){
    for(int i=1;i<=n;i++) g[i]=f[i]*x;
    proc(g,n-1);
}

bool cmp(int *f,int *g,int n){
    for(int i=1;i<=n;i++) d[i]=g[i]-f[i];
    proc(d,n-1);
    return (d[n]>=0);
}

bool solve(){
    for(int i=1;i<=n;i++) a[i]=b[i]=0;
    
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(i%2==0) a[i]*=-1;
    }
    for(int i=1;i<=n;i++){
        if(i%2) b[i]=1;
        else b[i]=-1;
    }
    
    proc(a,n-1);
    proc(b,n-1);
    if(a[n]<0){
        for(int i=1;i<=n;i++) a[i]=-a[i];
        proc(a,n-1);
    }
    if(b[n]<0){
        for(int i=1;i<=n;i++) b[i]=-b[i];
        proc(b,n-1);
    }
    
    // for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
    // for(int i=1;i<=n;i++) cout<<b[i]<<" "; cout<<endl;
    
    int deg=n;
    while(!b[deg]) deg--;
    // cout<<" deg = "<<deg<<endl;
    
    for(int i=n-deg;i>=0;i--){
        for(int t=30;t>=0;t--){
            mult(b,c,n-i,1<<t);
            
            // cout<<i<<": "<<t<<" - ";
            // for(int j=1;j<=n-i;j++) cout<<c[j]<<" "; cout<<endl;
            
            if(cmp(c,a+i,n-i)){
                // cout<<i<<": "<<t<<" - ";
                // for(int j=1;j<=deg+1;j++) cout<<c[j]<<" "; cout<<endl;
                
                // cout<<"  "; for(int j=1;j<=n;j++) cout<<a[j]<<" "; cout<<endl;
                for(int j=1;j<=n-i;j++){
                    a[j+i]-=c[j];
                }
                // cout<<"  "; for(int j=1;j<=n;j++) cout<<a[j]<<" "; cout<<endl;
                
                proc(a,n-1);
            }
        }
    }
    
    // for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
    
    for(int i=1;i<=n;i++) if(a[i]) return 0;
    return 1;
}

signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&n,&k);
        
        if(solve()) printf("Yes\n");
        else printf("No\n");
    }
}
