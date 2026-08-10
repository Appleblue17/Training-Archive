#include<bits/stdc++.h>
using namespace std;
const int N=3300;
int n;
int a[N][N];

bool pr[N];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    
    fill(pr+1,pr+N,1);
    for(int i=2;i<N;i++){
        if(pr[i]){
            for(int j=i*2;j<N;j+=i) pr[j]=0;
        }
    }
    
    int t=2;
    while(!pr[n+t-1]) t++;
    // cout<<t<<endl;
    
    int nw=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<nw<<" ";
            // if(i<n) assert(__gcd(nw,nw+n+t-1)==1);
            // assert(nw<=n*(n+40));
            nw++;
        }
        cout<<endl;
        nw+=t-1;
    }
}
