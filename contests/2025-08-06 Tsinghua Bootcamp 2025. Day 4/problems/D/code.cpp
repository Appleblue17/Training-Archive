#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=1e6+5;
int T,n,m;
int a[N],b[N];
int p[N];

vector <int> V[N];

signed main(){
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);
        sort(a+1,a+n+1);
        
        int nw=n+1;
        for(int i=m;i>=1;i--){
            while(nw>=1 && a[nw-1]>=b[i]) nw--;
            p[i]=n-nw+1+i;
        }
        long long ans=0;
        
        int L=m+1;
        for(int i=m;i>=1;i--){
            // if(p[i]<i+1) continue;
            while(L-1>=1 && p[L-1]>=i+1) L--;
            ans+=max(0,i-L+1);
        }
        printf("%lld\n",ans);
        // for(int i=1;i<=m;i++) cout<<p[i]<<" ";
        // cout<<endl;
        
    }
}