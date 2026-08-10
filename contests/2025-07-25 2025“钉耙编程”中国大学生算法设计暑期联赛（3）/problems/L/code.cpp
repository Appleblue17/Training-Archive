#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
const int N=2e5+5,mod=1e9+7,inv2=(mod+1)/2;

int T,n;
pair <int,int> X[N],Y[N];

inline void read(int &x){
    x=0; char c=getchar();
    bool flag=0;
    if(c=='-') flag=1;
    while(c<'0'||c>'9') {
        c=getchar();
        if(c=='-') flag=1;
    }
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c-'0'), c=getchar();
    if(flag) x=-x;
}

signed main(){
    scanf("%d",&T);
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            int x,y,a; read(x), read(y), read(a);
            int nx=x+y,ny=x-y;
            
            X[i]=MP(nx,a);
            Y[i]=MP(ny,a);
        }
        
        long long ans=0;
        for(int f=0;f<=1;f++){
            sort(X+1,X+n+1);
            int A=0,S=0,AS=0;
            for(int i=1;i<=n;i++){
                int x=(X[i].first%mod+mod)%mod,a=X[i].second;
                
                ans+=1ll*a*x%mod*(i-1)%mod-1ll*a*S%mod+1ll*A*x%mod-AS;
                
                A=(A+a)%mod;
                S=(S+x)%mod;
                AS=(AS+1ll*a*x%mod)%mod;
            }
            swap(X,Y);
        }
        ans=(ans%mod+mod)%mod;
        
        printf("%lld\n",1ll*ans*inv2%mod);
    }
}