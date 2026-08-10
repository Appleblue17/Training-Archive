#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,INF=1e18;
int T,n;
int d[N];
vector<int> bin[N];
int pos[N];
#define fi first
#define se second
#define mapa make_pair
void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &d[i]), bin[i].clear();
    if(n==1){
        if(d[1]==1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
        return;
    }
    if(n==2){
        if(d[1]==d[2]&&d[1]==2){
            printf("Yes\n1 2\n");
        }
        else{
            printf("No\n");
        }
        return;
    }
    int mn=1e9, mx=0;
    for(int i=1; i<=n; ++i){
        mn=min(mn, d[i]);
        mx=max(mx, d[i]);
    }
    if(mn==mx){
        printf("No\n");
        return;
    }
    for(int i=1; i<=n; ++i){
        bin[d[i]].push_back(i);
    }
    if(bin[mx].size()<2){
        printf("No\n");
        return;
    }
    vector<pair<int, int> > ans;
    if(mx&1){
        if(mn!=(mx+1)/2){
            printf("No\n");
            return;
        }
        if(bin[mn].size()!=1){
            printf("No\n");
            return;
        }
        int z=bin[mn][0], w=bin[mn][0];
        pos[mn]=z;
        for(int i=mn+1; i<=mx; ++i) {
            if(bin[i].size()<2){
                printf("No\n");
                return;
            }
            ans.push_back(mapa(z, bin[i].back())); z=bin[i].back(); bin[i].pop_back();
            ans.push_back(mapa(w, bin[i].back())); w=bin[i].back(); bin[i].pop_back();
            pos[i]=w;
            for(auto t:bin[i]) ans.push_back(mapa(pos[i-1], t));
        }
        printf("Yes\n");
        for(auto [x, y]:ans){
            printf("%d %d\n", x, y);
        }
    }
    else{
        if(mn!=mx/2+1){
            printf("No\n");
            return;
        }
        if(bin[mn].size()!=2){
            printf("No\n");
            return;
        }
        int z=bin[mn][0], w=bin[mn][1];
        ans.push_back(mapa(z, w));
        pos[mn]=z;
        for(int i=mn+1; i<=mx; ++i) {
            if(bin[i].size()<2){
                printf("No\n");
                return;
            }
            ans.push_back(mapa(z, bin[i].back())); z=bin[i].back(); bin[i].pop_back();
            ans.push_back(mapa(w, bin[i].back())); w=bin[i].back(); bin[i].pop_back();
            pos[i]=w;
            for(auto t:bin[i]) ans.push_back(mapa(pos[i-1], t));
        }
        printf("Yes\n");
        for(auto [x, y]:ans){
            printf("%d %d\n", x, y);
        }
    }
}
signed main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}