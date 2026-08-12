#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=1e6+5;
int T,n;
long long a[N],pre[N],suf[N];

bool solve(){
    bool fl=0;
    if(n%2==0){
        fl=1;
        reverse(a+1,a+n+1);
        a[n-1]+=a[n];
        n--;
    }
    
    pre[0]=0; suf[n+1]=0;
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]+a[i];
    int k=(n+1)/2;
    for(int i=1;i<k;i++){
        int x=k-i,y=k+i;
        if(pre[x]>suf[y]) return 1^fl;
        else if(pre[x]<suf[y]) return 0^fl;
    }
    return 0^fl;
}

signed main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        
        if(solve()) printf("YES\n");
        else printf("NO\n");
    }
}