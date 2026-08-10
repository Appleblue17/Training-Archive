#include<bits/stdc++.h>
using namespace std;
const int N=110000;
int T, n;
int a[N], b[N];
int pre[N];
void solve(){
    vector<pair<int, int> > vec;
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1; i<=n; ++i) scanf("%d", &b[i]);
    for(int x=n; x>=1; --x){
        int p1=0, p2=0;
        for(int i=1; i<=n; ++i){
            if(a[i]==x) p1=i;
            if(b[i]==x) p2=i;
        }
        if(p1<p2){
            printf("NO\n");
            return ;
        }
        if(p1==p2) continue;
        int mx=0;
        for(int i=p2; i<=p1; ++i)if(a[i]<=x){
            pre[i]=mx;
            if(a[i]>a[mx]) mx=i;
        }
        while(p1!=p2){
            swap(a[pre[p1]], a[p1]);
            vec.emplace_back(pre[p1], p1);
            p1=pre[p1];
        }
    }
    printf("YES\n");
    printf("%d\n", (int)vec.size());
    for(auto t:vec) printf("%d %d\n", min(t.first, t.second), max(t.first, t.second));
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
