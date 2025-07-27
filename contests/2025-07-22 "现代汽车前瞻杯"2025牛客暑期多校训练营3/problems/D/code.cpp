#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int T,n,a;
char S[N];
 
signed main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&a);
        scanf("\n%s",S+1);
         
        bool fl=0;
        int sum=0;
        for(int l=1,r;l<=n;l=r+1){
            r=l;
            while(r+1<=n && S[r+1]==S[l]) r++;
             
            if(S[l]=='0' && r-l+1>=a+1) fl=1;
            if(S[l]=='1' && r-l+1>=a) fl=1;
            if(S[l]=='1') sum+=r-l+1;
        }
        if(fl) printf("%d\n",n);
        else printf("%d\n",sum);
    }
     
}
