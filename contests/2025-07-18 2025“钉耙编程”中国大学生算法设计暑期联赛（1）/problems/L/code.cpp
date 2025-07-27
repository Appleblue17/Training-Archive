#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1.2e6+5,M=1e5+5,INF=1e9;
int lim=1e6;
int T,n,k;
int g[N];

signed main(){
    int id=0;
    for(int i=1;id<=lim;i++){
        for(int t=1;t<i;t++) g[++id]=i;
        g[++id]=1;
    }
    
    cin>>T;
    while(T--){
        scanf("%lld%lld",&n,&k);
        int x=g[n];
        if(x%k) puts("-1");
        else{
            int len=x/k,d=k;
            int A=n-1ll*len*(len-1)/2*d;
            int B=len;
            if(A%B) puts("-1");
            else{
                for(int i=0;i<len;i++) printf("%lld ",A/B+i*d);
                printf("\n");
            }
            
            // cout<<1.0*n/len-1.0*(len-1)*d/2<<endl;
        }
        
        
    }
    
}