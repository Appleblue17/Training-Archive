#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int p1[N], p2[N];
int main(){
    cin>>n;
    int w=n*2;
    for(int i=n-((n+1)&1); i>=1; i-=2){
        p2[i]=w;
        --w;
    }
    w=1;
    for(int i=1; i<=n; ++i){
        if(p2[i]==0) p2[i]=w, ++w;
        if(p1[i]==0) p1[i]=w, ++w;
    }
    for(int i=1; i<=n; ++i) cout<<p1[i]<<' ';
    cout<<endl;
    for(int i=1; i<=n; ++i) cout<<p2[i]<<' ';
    cout<<endl;
}
