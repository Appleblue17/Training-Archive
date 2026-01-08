#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,INF=1e9;
int n,m;
int a[N],b[N];

signed main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    int ans=n;
    for(int t=0;t<m;t++){
        for(int i=0;i<n;i++) b[i]=(a[i]>>t & 1);
        
        int lst=-INF;
        for(int i=0;i<n*2;i++){
            if(!b[i%n]){
                if(lst==i-1){
                    if(b[(lst+n-1)%n] && b[(i+1)%n]) ;
                    else ans=1;
                }
                else{
                    // cout<<i<<" "<<lst<<endl;
                    ans=min(ans,i-lst-1);
                }
                lst=i;
            }
        }
    }
    
    cout<<ans;
}
