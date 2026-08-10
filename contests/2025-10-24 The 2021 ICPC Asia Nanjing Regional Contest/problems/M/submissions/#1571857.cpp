#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5,W=1e6;
int n,k,ans;
int a[N];
int buc[N],mx[N];

void solve(){
    scanf("%d",&n);
    bool neg=0,pos=0;
    int mn=1e9;
    long long ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<=0)neg=1;
        if(a[i]>=0)pos=1;
        mn = min(mn,abs(a[i]));
        ans += abs(a[i]);
    }
    if(n == 1){
        printf("%d\n",a[1]);
        return;
    }
    if(neg && pos){
        
    }
    else{
        ans -= mn*2;
    }
    printf("%lld\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--)solve();
}
