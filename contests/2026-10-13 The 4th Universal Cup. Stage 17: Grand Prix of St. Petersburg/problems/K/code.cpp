#include <bits/stdc++.h>
using namespace std;
#define OUT(t) putchar('0'+t)
const int N=440;
int n;


// void solve(int n,int x){
//     if(!n) return ;
//     if(n==1){
//         OUT(4),OUT(0),OUT(2);
//         return ;
//     }
//     OUT(4),OUT(0);
//     for(int i=1;i<=n-1;i++) OUT(4),OUT(2),OUT(4),OUT(0);
//     OUT(0),OUT(2);
//     for(int i=1;i<=n-2;i++) OUT(0),OUT(4),OUT(0),OUT(2);
//     OUT(2);
//     solve(n-2,(x+4)%6);
// }


signed main(){
    cin>>n;
    
    for(int t=n;t>=1;t--){
        for(int i=1;i<=t;i++) OUT(4);
        for(int i=1;i<t;i++) OUT(0),OUT(2);
        OUT(0);
    }
    for(int i=1;i<=n;i++) OUT(2);
}
