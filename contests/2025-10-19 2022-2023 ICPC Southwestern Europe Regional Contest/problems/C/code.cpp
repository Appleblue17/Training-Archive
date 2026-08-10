#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n, m;
char s[N];
int sum[N];
vector<int> vec;
// bool check(int lim){
//     long long cur=0;
//     cout<<lim<<endl;
//     for(int i=lim; i+1<(int)vec.size(); ++i){
//         int d=vec[i]-vec[i-lim+1]+1;
//         int l=vec[i-lim+1]-vec[i-lim]-1, r=vec[i+1]-vec[i]-1;
//         cout<<l<<' '<<r<<' '<<vec[i-lim+1]<<' '<<vec[i]<<endl;
//         for(int j=0; j<=l; ++j){
//             cout<<max(r-max(0, (n-d-j))+1, 0)<<endl;
//             cur+=max(r-max(0, (n-d-j))+1, 0);
//         }
//     }
//     return cur>=n;
// }
int main(){
    scanf("%d", &n); m=n*2-1;
    scanf("%s", s+1);
    int mx=0;
    // vec.push_back(0);
    for(int i=1; i<=m; ++i){
        sum[i]=sum[i-1]+(s[i]=='W');
        // if(s[i]=='W'){
        //     vec.push_back(i);
        // }
        if(i>=n) mx=max(mx, sum[i]-sum[i-n]);
    }
    // vec.push_back(m+1);
    // int L=mn, R=n, mid, ret=0;
    // while(L<=R){
    //     mid=(L+R)>>1;
    //     if(check(mid)){
    //         ret=mid; L=mid+1;
    //     }
    //     else{
    //         R=mid-1;
    //     }
    // }
    printf("%d\n", mx);
}
