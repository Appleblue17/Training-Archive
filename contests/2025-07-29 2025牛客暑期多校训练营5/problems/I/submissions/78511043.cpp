#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    scanf("%d",&n);
    if(n&1){
        printf("%d\n",(n+(n/2+1))*2);
    }
    else{
        printf("%d\n",(n+1+(n/2))*2);
    }
}
