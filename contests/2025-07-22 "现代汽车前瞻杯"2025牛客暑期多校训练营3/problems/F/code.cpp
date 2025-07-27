#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int T,n,a, b;
signed main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d", &n, &a, &b);
        if(n<=a){
            printf("Sayonara\n");
            continue;
        }
        int res=n%(a+b);
        if(res>a){
            printf("0\n");
        }
        else{
            printf("%d\n", res);
        }
    }
     
}
