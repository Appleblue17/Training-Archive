#include <bits/stdc++.h>
using namespace std;
int n;

signed main(){
    cin>>n;
    cout<<n*2+1<<endl;
    for(int i=1; i<=n*2+1; ++i){
        int st=i;
        for(int j=1; j<=n; ++j){
            if(st==n*2+1) st=1;
            else ++st;
            cout<<st<<' ';
        }
        cout<<endl;
    }
}
