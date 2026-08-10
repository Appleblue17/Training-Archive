#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N];
int main(){
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];
    sort(a+1, a+n+1);
    int s=0;
    for(int i=1; i<=n; ++i){
        if(s>=a[i]) ++s;
        else --s;
    }
    cout<<s<<' ';
    s=0;
    for(int i=n; i>=1; --i){
        if(s>=a[i]) ++s;
        else --s;
    }
    cout<<s<<endl;
}
