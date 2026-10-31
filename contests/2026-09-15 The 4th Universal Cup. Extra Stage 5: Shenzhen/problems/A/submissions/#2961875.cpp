#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;

void solve(){
    
    for(int i=1;i<=n/97;i++){
        int l=i*97,r=i*122;
        
        if(l<=n && n<=r){
            printf("Yes\n");
            int res=n-l;
            
            for(int t=1;t<=i;t++){
                int d=min(25,res);
                res-=d;
                putchar('a'+d);
            }
            putchar('\n');
            return ;
        }
        
    }
    printf("No\n");
}

signed main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        solve();
    }
    
}