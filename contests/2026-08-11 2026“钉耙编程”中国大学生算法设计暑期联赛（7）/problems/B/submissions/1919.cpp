#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int T, n, m;
vector<int> bin[N], e[N];
int a[N], b[N], c[N], d[N];
typedef pair<int, int> pii;
#define fi first
#define se second
void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) bin[i].clear();
    for(int i=1, x, y; i<=m; ++i){
        scanf("%d%d", &x, &y);
        if(x>y) swap(x, y);
        bin[x].push_back(y);
    }
    a[0]=n+1; b[0]=0;
    for(int i=1; i<=n; ++i){
        b[i]=b[i-1]; a[i]=a[i-1];
        for(auto j:bin[i]){
            b[i]=max(b[i], i);
            a[i]=min(a[i], j);
        }
    }
    c[n+1]=n+1; d[n+1]=0;
    for(int i=n; i>=1; --i){
        c[i]=c[i+1]; d[i]=d[i+1];
        for(auto j:bin[i]){
            d[i]=max(d[i], i);
            c[i]=min(c[i], j);
        }
    }
    for(int i=1; i<=n; ++i){
        cout<<a[i]<<' '<<b[i]<<endl;
    }
    cout<<"--------------"<<endl;
    for(int i=1; i<=n; ++i){
        cout<<c[i]<<' '<<d[i]<<endl;
    }
    cout<<"--------------"<<endl;
    for(int i=1; i<=n-2; ++i){
        if(1<=b[i]&&b[i]<a[i]&&a[i]<=d[i+1]&&d[i+1]<c[i+1]&&c[i+1]<=n){
            printf("Yes\n");
            printf("%d %d\n", a[i],c[i+1]);
            return ;
        }
    }
    {
        int x=0, y=0, z=n+1;
        for(int i=1; i<=n; ++i){
            for(auto j:bin[i]){
                x=max(x, j);
                y=max(y, i);
                z=min(z, j);
            }
        }
        if(1<=y&&y<z&&z<=x&&x<n){
            printf("Yes\n");
            printf("%d %d\n", z, n);
            return ;
        }
    }
    {
        int x=n+1, y=n+1, z=0;
        for(int i=1; i<=n; ++i){
            for(auto j:bin[i]){
                x=min(x, j);
                y=min(y, i);
                z=max(z, i);
            }
        }
        if(1<y&&y<=z&&z<x&&x<=n){
            printf("Yes\n");
            printf("%d %d\n", y, x);
            return ;
        }
    }
    printf("No\n");
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
2 1
2 2
2 2
--------------
2 2
3 2
4 0
--------------
Yes
2 3
2 1
2 2
2 2
--------------
2 2
3 2
4 0
--------------
Yes
2 3