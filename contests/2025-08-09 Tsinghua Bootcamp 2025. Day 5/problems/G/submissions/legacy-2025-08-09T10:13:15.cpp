#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n, m;
int main(){
    scanf("%d%d", &n, &m);
    if(n>=m){
        printf("-1\n");
        return 0;
    }
    int len=(m-1)/n+1;
    int cnt=(m-1)%n+1;
    // cout<<cnt<<endl;
    printf("%d 0 ", cnt);
    for(int i=3; i<=len; ++i) printf("%d ", cnt+i-2);
    return 0;
}