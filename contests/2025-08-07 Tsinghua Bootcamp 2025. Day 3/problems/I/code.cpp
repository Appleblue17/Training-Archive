#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int p[4][11];
int ans;
int eval(int dep){
    int ret=0;
    for(int l=1; l<=n; ){
        int r=l;
        while(r+1<=n&&p[dep][r+1]==p[dep][r]+1) ++r;
        ++ret;
        l=r+1;
    }
    return ret;
}
void perform(int o, int t, int i, int j, int k){
    int it=0;
    if(o==0){
        for(int o=j+1; o<=k; ++o) p[t][++it]=p[t-1][o];
        for(int o=1; o<=i; ++o) p[t][++it]=p[t-1][o];
        for(int o=k+1; o<=n; ++o) p[t][++it]=p[t-1][o];
        for(int o=i+1; o<=j; ++o) p[t][++it]=p[t-1][o];
    }
    else{
        for(int o=i+1; o<=j; ++o) p[t][++it]=p[t-1][o];
        for(int o=k+1; o<=n; ++o) p[t][++it]=p[t-1][o];
        for(int o=1; o<=i; ++o) p[t][++it]=p[t-1][o];
        for(int o=j+1; o<=k; ++o) p[t][++it]=p[t-1][o];
    }
}
unordered_map<ll, int> h[2];
ll hs(int dep){
    ll ret=0;
    for(int i=1; i<=n; ++i) ret=ret*10ll, ret+=p[dep][i]-1;
    return ret;
}
void solve(int id, int dep){
    ll cur=hs(dep);
    if(h[id].find(cur)==h[id].end()) h[id][cur]=dep;
    else if(h[id][cur]>dep){
        h[id][cur]=dep;
    }
    else{
        return ;
    }
    if(dep==3){
        return ;
    }
    for(int i=0; i<=n; ++i){
        for(int j=i; j<=n; ++j){
            for(int k=j; k<=n; ++k){
                perform(id, dep+1, i, j, k);
                solve(id, dep+1);
            }
        }
    }
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &p[0][i]);
    ans=min(n, 6);
    solve(0, 0);
    for(int i=1; i<=n; ++i) p[0][i]=i;
    solve(1, 0);
    for(auto t:h[0]){
        if(h[1].find(t.first)!=h[1].end()){
            ans=min(ans, t.second+h[1][t.first]);
        }
    }
    printf("%d\n", ans);
}