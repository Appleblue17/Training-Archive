#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[N];
int T, n;
int tp[N];
void solve(){
    scanf("%s", s+1);
    n=strlen(s+1);
    for(int i=1; i<=n; ++i) {
        if(s[i]=='('||s[i]==')') tp[i]=1;
        else tp[i]=0;
    }
    tp[0]=-1;
    for(int o=1, l=1; l<=n; ++o){
        if(tp[l]==tp[l-1]){
            printf("No\n");
            return ;
        }
        if(o>2){
            printf("No\n");
            return ;
        }
        int r=l;
        while(r+1<=n&&tp[r+1]!=tp[r]){
            ++r;
        }
        for(int k=1; k<=r-l+1; ++k){
            if(r+k>n||tp[r+k]!=tp[r-k+1]){
                printf("No\n");
                return ;
            }
        }
        l+=2*(r-l+1);
    }
    printf("Yes\n");
}
signed main(){
    scanf("%d",&T);
    while(T--){
        solve();
    }
}
