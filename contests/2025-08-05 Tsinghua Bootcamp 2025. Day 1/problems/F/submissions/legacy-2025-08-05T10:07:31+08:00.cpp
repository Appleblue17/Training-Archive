#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, s;

bool check(int x){
    for(int i=1;i<=n;i++){
        if(x%i==0){
            int j=x/i;
            if(j>=1 && j<=m) return 1;
        }
        
        int A=x-n*m+m*i,B=2ll*i-n;
        if(A==0 && B==0) return 1;
        if(B!=0 && A%B==0){
            int j=A/B;
            if(j>=1 && j<=m) return 1;
        }
    }
    return 0;
}

signed main(){
    cin>>n>>m>>s;
    if(s==n*m) cout<<0;
    else if(s%n==0 || s%m==0) cout<<1;
    else if(check(s) || check(n*m-s)) cout<<2;
    else cout<<3;
    return 0;
}