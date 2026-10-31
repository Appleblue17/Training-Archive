#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n;
char a[N], b[N];
int sum[N];
void solve(){
    scanf("%d", &n);
    scanf("%s", a+1);
    scanf("%s", b+1);
    if(a[1]=='0'||a[n]=='0'||b[1]=='0'||b[n]=='0') {
        printf("-1\n");
        return ;
    }
    a[1]='?'; a[n]='?'; b[1]='?'; b[n]='?';
    sum[n+1]=0;
    for(int i=n; i>=1; --i){
        sum[i]=sum[i+1]+(a[i]=='1');
    }
    sum[0]=sum[1];
    vector<int> bd;
    bd.push_back(n);
    for(int i=1; i<=n; ++i){
        if(b[i]=='1'&&sum[i-1]>0){
            bd.push_back(i-1);
            if()
        }
    }
    sum[0]=0;
    for(int i=1; i<=n; ++i) {
        sum[i]=sum[i-1]+(b[i]=='1');
    }
    for(int i=1; i<=n; ++i){
        if(a[i]=='1'&&sum[i+1]>0){
            bd.push_back(i);
        }
    }
    sort(bd.begin(), bd.end());
    bd.erase(unique(bd.begin(), bd.end()), bd.end());
    for(auto t:bd){
        cout<<t<<' ';
    }
    cout<<endl;
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}