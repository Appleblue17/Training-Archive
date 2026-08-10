#include <bits/stdc++.h>
using namespace std;
const int N=1005;
typedef long long ll;
int T,n;
void solve(){
    scanf("%d", &n);
    printf("%d\n", n);
    for(int i=1; i<=n; ++i){
        printf("%d ", i);
    }
    putchar('\n');
    printf("%d ", n);
    for(int i=2; i<=n; ++i){
        printf("%d ", n*i-(n-i+1));
    }
}
signed main(){
    solve();
}


