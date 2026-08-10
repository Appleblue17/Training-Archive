#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=300+5;
int n,x[N],y[N],del[N];
int area2(int i,int j,int k){
    //printf("area2 %lld %lld %lld\n",i,j,k);
    //printf("area2 return %lld\n",abs((y[k]-y[j])*(x[i]-x[j]) - (y[i]-y[j])*(x[k]-x[j])));
    return abs((y[k]-y[j])*(x[i]-x[j]) - (y[i]-y[j])*(x[k]-x[j]));
}
int are(int j){
    int i=(j-2+n)%n+1,k=j%n+1;
    while(del[i])i=(i-2+n)%n+1;
    while(del[k])k=k%n+1;
    //printf("are j=%lld,i=%lld,k=%lld\n",j,i,k);
    return area2(i,j,k);
}

void inter(){
    int ans=1e18;
    int ret=0;
    for(int i=1;i<=n;i++){
        if(!del[i]){
            int tmp = are(i);
            if(ans > tmp){
                ans = tmp;
                ret=i;
            }
        }
    }
    printf("%lld\n",ret);fflush(stdout);
    del[ret]=1;
    scanf("%lld",&ret);
    //printf("read %lld\n",ret);
    del[ret]=1;
}

void solve(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x[i],&y[i]);
    }
    if(n%2==1){
        printf("Beatrice\n");fflush(stdout);
        int x=0;
        scanf("%lld",&x);
        //printf("read %lld\n",x);
        del[x]=1;
    }
    else{
        printf("Alberto\n");fflush(stdout);
    }
    for(int i=1;i<=(n-2)/2;i++){
        inter();
    }
}

signed main(){
    //int T;
    //scanf("%d",&T);
    //while(T--)
    solve();
    
}
