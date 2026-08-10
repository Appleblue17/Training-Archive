#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+56, inf=1e9;
int n;
pair<int, int> f[N];
signed main(){
    scanf("%d", &n);
    int sum=0;
    for(int i=1, x, y; i<=n; ++i){
        scanf("%lld", &x);
        if(i == n)sum += x;
        else sum += x*2;
    }
    printf("%lld\n",sum);
}