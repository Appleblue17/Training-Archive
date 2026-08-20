#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
int T, n, m;
int a[N],b[N],id[N];
unordered_map<int,int> ma;
bool cmp(int i,int j){
    return ma[b[i]] < ma[b[j]];
}
void solve(){
    cin >> n >> m;
    ma.clear();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&a[(i-1)*m+j]);
            ma[a[(i-1)*m+j]] = (i-1)*m+j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&b[(i-1)*m+j]);
            id[(i-1)*m+j] = (i-1)*m+j;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%lld: %lld,%lld\n",(i-1)*m+j,a[(i-1)*m+j],b[(i-1)*m+j]);
            //id[(i-1)*m+j] = (i-1)*m+j;
        }
    }
    
    sort(id+1,id+n*m+1,cmp);
    cout << n << '*' << m << endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << i << ' ' << j << endl;
            cout << id[(i-1)*m+j] << endl;
        }
    }
    
    
}
signed main(){
    ios::sync_with_stdio(false);
    
    cin>>T;
    while(T--){
        solve();
    }
}