#include<bits/stdc++.h>
using namespace std;
int main(){
    int l, r, b, k;
    cin>>l>>r>>b>>k;
    int t=(l+b-1)/b;
    cout<<1ll*k*b*t<<endl;
}
