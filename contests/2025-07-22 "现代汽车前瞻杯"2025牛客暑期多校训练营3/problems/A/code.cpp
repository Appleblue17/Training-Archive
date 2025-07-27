#include <bits/stdc++.h>
using namespace std;
const int N=1500;
int T,n;
int a[N][N];
int f[N], p[N];
signed main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d", &n);
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j) a[i][j]=0;
        }
        for(int i=1; i<=n; ++i){
            scanf("%d", &f[i]); p[i]=i;
        }
        sort(p+1, p+n+1, [&](int x, int y){return f[x]<f[y];});
        for(int i=1; i<=n; ++i){
            if(f[p[i]]==1) continue;
            a[p[i]][p[i]]=1;
            for(int j=1; j<=f[p[i]]-2; ++j) a[p[i]][p[j]]=j+1, a[p[j]][p[i]]=j+1;
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j) printf("%d ", a[i][j]);
            putchar('\n');
        }
    }
     
}
