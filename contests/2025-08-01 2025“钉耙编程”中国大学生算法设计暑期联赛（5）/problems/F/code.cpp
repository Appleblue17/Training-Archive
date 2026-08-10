#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int T,n,m,k,p;
int a[N],b[N];
int ans[4][2]={{0,0},{0,1},{0,1},{1,3}};

int sg_2(int x,int y){
    if(x == 3 && y==1)return 2;
    else{
        x = x%4;
        return ans[x][y];
    }
}

void solve(){
    scanf("%lld",&n);
    int fans=0;
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        fans ^= sg_2(x,y);
    }
    if(fans==0)printf("No\n");
    else printf("Yes\n");
}


//int sg[1100][2],vis[1100][2];

signed main() {
    int T;
    scanf("%lld",&T);
    while(T--)solve();
}