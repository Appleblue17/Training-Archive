#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,INF=1e9;
int n,q;
int a[N],rem[N][20],sum[N][20],n2[N];
 
int calc(int val,int pos,int ed){
    for(int j=19;j>=0;j--){
        if(pos + n2[j] <= ed){//pos is not combined yet
            val = sum[pos][j] + (val-rem[pos][j]+n2[n2[j]])/n2[n2[j]];
            pos += n2[j];
        }
    }
    return val;
}
 
signed main() {
    scanf("%lld%lld",&n,&q);
    n2[0]=1;
    for(int i=1;i<N;i++){
        n2[i]=n2[i-1]*2;
        if(n2[i] >= 1e10)n2[i]=1e10;
    }
 
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<n;i++){
        sum[i][0]=(a[i+1]-a[i])/2;
        rem[i][0]=2-(a[i+1]-a[i])%2;
    }
    //cout << sum[4][0] << endl;
    for(int j=1;j<=19;j++){
        for(int i=1;i+n2[j]-1<=n-1;i++){
            sum[i][j] = sum[i+n2[j-1]][j-1]+(sum[i][j-1]-rem[i+n2[j-1]][j-1]+n2[n2[j-1]])/n2[n2[j-1]];
            __int128 t = (__int128)n2[n2[j-1]]-((__int128)sum[i][j-1]-rem[i+n2[j-1]][j-1]+n2[n2[j-1]])%n2[n2[j-1]];
            __int128 nr = (__int128)rem[i][j-1] + (t-1)*n2[n2[j-1]];
            if(nr>5e9)nr=5e9;
            rem[i][j] = nr;
 
        }
    }
 
    //cout << '*' << endl;
     
    while(q--){
        int st,ed; scanf("%lld%lld",&st,&ed);
        ed=n+1-ed;
        int pos=upper_bound(a+1,a+n+1,st)-a;
        if(pos>ed){
            printf("0\n");
            continue;
        }
        int val=a[pos]-st;
        if(pos==ed){
            printf("%lld\n",a[pos]-val/2-st);
            continue;
        }
 
        int ans = a[ed]-calc(val/2,pos,ed)-st;
 
        printf("%lld\n",ans);
    }
     
}
