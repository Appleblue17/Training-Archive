#include <bits/stdc++.h>
using namespace std;
const int N=1100,INF=1e9;
int n;
int main(){
    cin>>n;
    long long sum=0; int mx=0;
    for(int i=1, x; i<=n; ++i){
        cin>>x;
        sum+=x; mx=max(mx, x);
    }
    if(mx==0||sum-mx>=n){
        printf("Puss in Boots");
    }
    else{
        printf("Donkey");
    }
}
