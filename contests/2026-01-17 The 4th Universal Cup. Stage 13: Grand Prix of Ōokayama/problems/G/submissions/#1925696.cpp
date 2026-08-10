#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N=6e5+5,INF=1e9;

int n,x;

void solve(){
    scanf("%d%d",&n,&x);
    char c=getchar(),c1;
    int t1=1,mx=n,mn=n-x+1;
    while(c != '+' && c != '-')c=getchar();
    c1 = c;
    if(c1 == '-')t1=-1;
    printf("%d\n",t1*mx);fflush(stdout);mx--;
    for(int i=2;i<=x;i++){
        c=getchar();
        while(c != '+' && c != '-')c=getchar();
        if(c == c1){
            printf("%d\n",t1*mx);fflush(stdout);mx--;
        }
        else{
            printf("%d\n",-t1*mn);fflush(stdout);mn++;
        }
    }
    
}

signed main(){
    //printf("%d %d\n",(int)'+',(int)'-');
    int T;cin >> T;while(T--){
        solve();
    }
    
}
