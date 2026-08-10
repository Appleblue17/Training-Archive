#include<bits/stdc++.h>
using namespace std;
const int N=210000,M=11000,INF=1e9;

typedef pair<int,int> pii;
#define mp make_pair
#define int long long
#define fi first
#define se second
int n,k,h,xc,yc,xa,ya;

int vis[N];

signed main(){
    scanf("%lld%lld",&n,&h);
    if(h > n*n){
        printf("impossible");return 0;
    }
    if(h < 2*n-1){
        printf("impossible");return 0;
    }
    if(n == 1 && h == 1){
        printf("1");return 0;
    }
    if(n == 2 && h == 3){
        printf("3 1");return 0;
    }
    if(n == 2 && h == 4){
        printf("1 3");return 0;
    }
    if(n == 3 && h == 5){
        printf("5 3 1");return 0;
    }
    if(n == 3 && h == 6){
        printf("1 5 3");return 0;
    }
    if(n == 3 && h == 7){
        printf("impossible");return 0;
    }
    if(n == 3 && h == 8){
        printf("3 5 1");return 0;
    }
    if(n == 3 && h == 9){
        printf("1 3 5");return 0;
    }
    if(h == n*n-2){
        printf("impossible");return 0;
    }
    if(h == 2*n+1){
        vis[n]=vis[n-1]=vis[2]=1;
        printf("%d 3 %d ",n*2-1,n*2-3);
        for(int i=n;i>=1;i--){
            if(!vis[i])printf("%d ",2*i-1);
        }
        return 0;
    }
    for(int i=n;i>=1;i--){
        if(h - 2*i +1 >= 0 && h - 2*i + 1 != 2){
            vis[i]=1;
            h -= 2*i-1;
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i])printf("%d ",2*i-1);
    }
    for(int i=n;i>=1;i--){
        if(!vis[i])printf("%d ",2*i-1);
    }
}
