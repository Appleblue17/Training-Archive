#include <bits/stdc++.h>
using namespace std;
int T;
long long n,m;

signed main(){
    cin>>T;
    while(T--){
        scanf("%lld%lld",&n,&m);
        if(n<=60 && (1ll<<n)<=m) printf("Bob\n");
        else printf("Ana\n");
    }
}
