#include <bits/stdc++.h>
using namespace std;
const int N=110;
int T,n;
int a[N];


int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        a[n+1]=1440;
        int tot=0;
        for(int i=0;i<=n;i++){
            int x=a[i+1]-a[i];
            tot+=x/120;
        }
        if(tot>=2) puts("YES");
        else puts("NO");
    }
}
