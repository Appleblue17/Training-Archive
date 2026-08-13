#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=998244353;

int T,n,m,k;
pair <int,int> V[N];

int rd(){
    int tot=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}

signed main(){
    T=rd();
    while(T--){
        n=rd(),m=rd(),k=rd();
        int ans=0;
        for(int i=1;i<=m;i++){
            int x=rd(),y=rd();
            if(x>y) swap(x,y);
            V[i]={x,y};
        }
        sort(V+1,V+m+1);
        for(int l=1,r;l<=m;l=r+1){
            r=l;
            while(r+1<=m && V[r+1]==V[r]) r++;
            int len=r-l+1;
            ans=(ans+1ll*len*(len-1)/2%mod)%mod;
        }
        
        if(k>2) printf("0\n");
        else printf("%d\n",ans);
    }
    
    
}