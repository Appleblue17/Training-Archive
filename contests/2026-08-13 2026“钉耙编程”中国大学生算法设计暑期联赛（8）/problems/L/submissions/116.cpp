#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,mod=998244353;

int T,n,m,k;
pair <int,int> V[N];

signed main(){
    cin>>T;
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&k);
        int ans=0;
        for(int i=1;i<=m;i++){
            int x,y; scanf("%lld%lld",&x,&y);
            if(x>y) swap(x,y);
            V[i]={x,y};
        }
        sort(V+1,V+m+1);
        for(int l=1,r;l<=m;l=r+1){
            r=l;
            while(r+1<=m && V[r+1]==V[r]) r++;
            int len=r-l+1;
            ans=(ans+len*(len-1)/2)%mod;
        }
        
        if(k>2) printf("0\n");
        else printf("%lld\n",ans);
    }
    
    
}