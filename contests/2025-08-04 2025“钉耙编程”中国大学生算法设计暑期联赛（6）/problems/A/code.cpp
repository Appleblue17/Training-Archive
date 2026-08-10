#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,INF=1e9;
int T,n,a[N];

signed main(){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        int tot=0,s=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            tot+=(a[i]==0);
            s+=(a[i]<0);
        }
        if(tot) printf("%d\n",tot);
        else{
            if(s%2==0) printf("0\n");
            else{
                int mn=INF;
                for(int i=1;i<=n;i++) mn=min(mn,abs(a[i]));
                printf("%d\n",mn+1);
            }
        }
        
        
    }
    
}