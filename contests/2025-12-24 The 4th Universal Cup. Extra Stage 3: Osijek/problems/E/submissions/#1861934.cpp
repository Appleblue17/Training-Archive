#include<bits/stdc++.h>
using namespace std;
const int N=2.2e6+6,INF=1e9;
int n;
int a[N], b[N];
int mx[N];
int sum;

int f[N];
void FWTor(int *f,int n){
    for(int k=1;k<n;k<<=1){
        for(int i=0;i<n;i+=(k<<1)){
            for(int j=i;j<i+k;j++){
                int x=j,y=j+k;
                f[y]+=f[x];
            }
        }
    }
}

int ans[N];

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i=20; i>=0; --i){
        for(int j=1; j<=n; ++j) {
            b[j]=(a[j]>>i)&1;
            b[j]^=b[j-1];
        }
        if(b[n]==1) {
            sum+=(1<<i);
            continue;
        }
        for(int j=1; j<n; ++j){
            if(b[j]) mx[j]+=1<<i;
        }
    }
    
    for(int i=1;i<n;i++) f[mx[i]]++;
    FWTor(f,1<<20);
    
    for(int i=0;i<=n+1;i++) ans[i]=INF;
    for(int mac=0;mac<(1<<20);mac++){
        ans[f[mac]]=min(ans[f[mac]],mac);
    }
    
    for(int i=n-1;i>=0;i--) ans[i]=min(ans[i],ans[i+1]);
    for(int i=0;i<n;i++) printf("%d ",ans[i]+sum);
}
