#include <bits/stdc++.h>
using namespace std;
const int N=110000;
int T,n,m;

int a[N];

signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int x = a[1];
    bool f=1;
    for(int i=1;i<=n;i++){
        if(a[i]%x == 0 || a[i]/2 >= x){
            continue;
        }
        else{
            f=0;
        }
    }
    if(!f){
        x = a[1]/2;
    }
    printf("%d\n",x);
}
