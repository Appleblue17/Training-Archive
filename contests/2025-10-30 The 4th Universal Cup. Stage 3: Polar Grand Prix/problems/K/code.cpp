#include<bits/stdc++.h>
using namespace std;
const int N=110000;
int n,a[N],k,mx;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(i == 1)k=a[i];
        else k = __gcd(k,a[i]);
        mx = max(mx,a[i]);
    }
    int cnt = mx/k-n;
    if(cnt % 3 == 0)printf("YES");
    else printf("NO");
}
