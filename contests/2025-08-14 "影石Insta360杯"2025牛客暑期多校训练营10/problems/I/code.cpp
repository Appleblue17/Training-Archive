#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=3e5+5,M=1e6+5;
int T,n,m;
vector<int> ans[1100000];
 
void fillcol(int &u,int v,int& x){
    //printf("filled col %d %d %d\n",u,v,x);
    ans[u][v] = x;
    for(int i=1;i<n;i++){
        if(i&1){
            u+=i;
        }
        else{
            u-=i;
        }
        if(u<=0)u+=n;
        if(u>n)u-=n;
        ans[u][v]=++x;
    }
    x++;
}
 
signed main(){
    cin >> n >> m;
    if(__gcd(n,m)>1){
        printf("NO\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans[i].push_back(0);
        }
        ans[i].push_back(0);
    }
    int u=1,v=1,x=1;
    for(int j=1;j<=m;j++){
        fillcol(u,v,x);
        if(j&1)
            v = (v+(x-1)-1+m)%m+1;
        else
            v = (v-(x-1)-1+m*n)%m+1;
    }
    printf("YES\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",ans[i][j]);
        }
        putchar('\n');
    }
}
