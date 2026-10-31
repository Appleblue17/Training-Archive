#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int T,n,m,k,a[N],x[N],y[N],z[N];
long long sum;
void solve(){
    sum=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        a[i]=0;
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
        a[x[i]] |= z[i];
        a[y[i]] |= z[i];
    }
    bool f=1;
    //cout << (a[1]&a[2]) << endl;
    for(int i=1;i<=m;i++){
        if((a[x[i]] & a[y[i]]) != z[i]){
            //printf("i=%d not satisfied\n",i);
            f=0;
        }
    }
    for(int i=1;i<=n;i++){
        //printf("a[%d]=%d\n",i,a[i]);
        sum += a[i];
    }
    if(!f)printf("-1\n");
    else printf("%lld\n",sum);
}

signed main(){
    cin>>T;
    while(T--){
        solve();
    }
    
    
}