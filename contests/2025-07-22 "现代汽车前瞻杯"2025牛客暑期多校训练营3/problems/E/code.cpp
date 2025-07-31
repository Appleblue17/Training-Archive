#include <bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int T,n;
int D[N][20],len[N];
 
int a[N];
void init(int lim){
    for(int t=2;t<=lim;t++){
        if(!len[t]){
            long long x=t;
            for(int e=1;x<=lim;e++,x*=t){
                for(int i=x;i<=lim;i+=x){
                    D[i][++len[i]]=t;
                }
            }
        }
    }
}
 
bool buc[N];
 
signed main(){
    init(N-5);
     
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(n%2==1){
            puts("YES");
            continue;
        }
        if(n==2){
            if(a[1]==a[2]) puts("YES");
            else puts("NO");
            continue;
        }
         
        for(int i=1;i<=n;i++){
            int x=a[i];
            int c=len[x];
            for(int t=1;t<=c;t++){
                buc[D[x][t]]^=1;
            }
        }
         
        bool fl=1;
        for(int i=1;i<=n;i++){
            int x=a[i],c=len[x];
            for(int t=1;t<=c;t++){
                if(buc[D[x][t]]){
                    fl=0;
                    buc[D[x][t]]=0;
                }
            }
        }
        if(fl) puts("YES");
        else puts("NO");
    }
     
}
