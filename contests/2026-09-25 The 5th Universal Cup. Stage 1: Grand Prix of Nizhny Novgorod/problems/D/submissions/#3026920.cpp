#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=2e5+5,mod=998244353;
int T,n;
int a[N],buc[N];

bool solve(){
    int lim=(n+1)/2;
    for(int i=lim;i<=n;i++) if(!buc[i]) return 0;
    return 1;
}

signed main(){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<=n;i++) buc[i]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            buc[a[i]]=1;
        }
        printf("%d\n",solve());
    }
}