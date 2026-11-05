#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int T;scanf("%lld",&T);while(T--){
        int a,b,A,B;
        //cin >> a >> b >> A >> B;
        scanf("%lld%lld%lld%lld",&a,&b,&A,&B);
        int k = B/a-3;
        while(k*a < B)k++;
        k--;
        //cout << k << endl;
        A -= k*b;B -= k*a;
        if(A - 4*b <= 0){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
}