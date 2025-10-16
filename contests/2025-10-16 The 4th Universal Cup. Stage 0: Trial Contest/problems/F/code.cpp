#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef unsigned long long ull;
int T, n, m, U, R, D, L;
int len;
int a[N];
vector<char> h[N];
void solve(){
    cin>>n>>m>>U>>R>>D>>L;
    if(R<m-1||U<n-1){
        printf("impossible");
        return ;
    }
    for(int i=1; i<=n; ++i){
        h[i].clear();
        h[i].resize(m+1);
    }
    h[1][m]='*';
    R-=m-1; U-=n-1;
    int tem=R+D;
    for(int i=1; i<=m; ++i) a[i]=0;
    for(int i=1; i<=m; ++i){
        if(tem>n-1){
            a[i]=n-1;
            tem-=n-1;
        }
        else{
            a[i]=tem;
            break;
        }
    }
    a[0]=n-1;
    for(int i=1; i<m; ++i){
        for(int j=1; j<=a[i]; ++j){
            if(D){
                --D; h[j][i]='D';
            }
            else if(R){
                --R; h[j][i]='R';
            }
        }
        h[a[i]+1][i]='R';
        for(int j=a[i-1]+1; j>a[i]+1; --j) h[j][i]='U';
    }
    for(int j=a[m-1]+1; j>a[m]+1; --j) h[j][m]='U';
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(h[i][j]==0){
                if(L){
                    --L; h[i][j]='L';
                }
                else if(U){
                    --U; h[i][j]='U';
                }
            }
            putchar(h[i][j]);
        }
        if(i!=n) putchar('\n');
    }
}
signed main(){
    cin>>T;
    while(T--){
        solve();
        if(T) {
            putchar('\n');
            putchar('\n');
        }
    }
}
