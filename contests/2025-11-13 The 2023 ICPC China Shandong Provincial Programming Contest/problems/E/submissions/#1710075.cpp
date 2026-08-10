#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,INF=1e18;

int T,n,k,m,a,b;

int cal(int n){
    int x=1;
    n%=m;
    for(int i=0;;i++,n=n*k%m,x*=k){
        if(!n) return i;
        if(n+x-1>=m) return i;
    }
    return -1;
}

signed main(){
    cin>>T;
    while(T--){
        scanf("%lld%lld%lld%lld%lld",&n,&k,&m,&a,&b);
        if(n%m==0){
            printf("0\n");
            continue;
        }
        if(k==1){
            printf("-1\n");
            continue;
        }
        
        int ans=INF;
        
        int alc=0;
        while(1){
            int ret=cal(n);
            if(ret!=-1) ans=min(ans,alc*b+ret*a);
            
            // cout<<n<<" "<<ret<<endl;
            
            if(!n) break;
            
            n/=k;
            alc++;
        }
        printf("%lld\n",ans);
    }
}
