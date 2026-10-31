#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n,k;
char S[N];

namespace Alice{
    int a[N];
    int s[N];
    
    void solve(){
        for(int i=1;i<=n;i++) a[i]=-1;
        for(int i=1;i<=k;i++){
            int x; scanf("%d",&x); a[x]=1;
        }
        
        for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
        
        int mn=0,pos=0;
        for(int i=1;i<=n;i++){
            if(s[i]<mn) mn=s[i],pos=i;
        }
        a[pos]=1;
        
        for(int i=1;i<=n;i++) if(a[i]>0) printf("%d ",i);
        printf("\n");
    }
}

namespace Bob{
    int a[N];
    int s[N];
    
    void solve(){
        for(int i=1;i<=n;i++) a[i]=-1;
        for(int i=1;i<=k+1;i++){
            int x; scanf("%d",&x); a[x]=1;
        }
        
        for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
        
        int mn=0,pos=0;
        for(int i=1;i<=n;i++){
            if(s[i]<=mn) mn=s[i],pos=i;
        }
        printf("%d\n",pos%n+1);
    }
}


signed main(){
    scanf("%s",S);
    
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        if(S[0]=='A') Alice::solve();
        else Bob::solve();
    }
}