#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int T,n,m;
int buc[N];

signed main(){
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++) buc[i]=0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(x<=m) buc[(x-1+m-i%m)%m]++;
        }
        int ans=0;
        for(int i=0;i<m;i++) ans=max(ans,buc[i]);
        printf("%d\n",n-ans);
    }
    
    
}