#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int T,x,y,n;

int lowbit(int x){
    return x & (-x);
}
int bitc(int x){
    return __builtin_popcountll(x);
}

bool check(int x,int y){
    int c=bitc(c);
    int z=lowbit(y) * ((1<<c)-1);
    return z<=n;
}

signed main(){
    cin>>T;
    while(T--){
        scanf("%lld%lld%lld",&n,&x,&y);
        if(x==y) puts("0");
        else if(lowbit(x)==lowbit(y) || bitc(x)==bitc(y)) puts("1");
        else if(check(x,y) || check(y,x)) puts("2");
        else puts("3");
    }
}