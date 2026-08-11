#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int T, n, m, w, ans[N];
char s[N];
void solve(){
    scanf("%d%d", &n, &w);
    scanf("%s",s+1);
    //int a1 = 2147483647;
    int a1 = 0x7FFFFFFF;
    ans[1] = w;
    for(int i=1;i<n;i++){
        if(s[i] == '|' || s[i] == '^')ans[i+1] = 0;
        else ans[i+1] = a1;
    }
    printf("Yes\n");
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    putchar('\n');
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}