#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T, n;
int a[N], b[N];
void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i=1; i<=n; ++i){
        scanf("%d", &b[i]);
    }
    int lst=n;
    for(int i=n; i>=1; --i){
        while(lst&&a[lst]!=b[i]) --lst;
        if(!lst){
            printf("%d\n", i);
            return ;
        }
        --lst;
    }
    printf("0\n");
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
