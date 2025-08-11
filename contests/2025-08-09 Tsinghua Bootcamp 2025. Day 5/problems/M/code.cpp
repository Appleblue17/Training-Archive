#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=55;

bool check(int x){
    if(x==0 || x==1) return 0;
    for(int i=2;i<=x/i;i++){
        if(x%i==0) return 0;
    }
    return 1;
}
vector<int> p;
void solve(){
    int n;
    scanf("%lld",&n);
    vector<int> sy;
    for(int v:p){
        while(n%v==0){
            sy.push_back(v);
            n/=v;
        }
    }
    if(n!=1){
        printf("0\n");
        return;
    }
    if(sy.size()>=2){
        if(sy[0]*sy[1]<4000){
            printf("0\n");
            return;
        }
    }
    printf("1\n");
}

signed main(){
    for(int i=2;i<4000;i++){
        if(check(i))p.push_back(i);
    }
    int T;
    scanf("%lld",&T);
    while(T--)solve();
}