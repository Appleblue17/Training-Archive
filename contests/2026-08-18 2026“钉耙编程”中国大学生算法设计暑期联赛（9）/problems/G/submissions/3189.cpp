#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int mod=998244353;
// #define int long long
int Test, n, m, w, t=5, a[N], c[N];
int v[5][N], b[N];
int rd(){
    char c=getchar();
    int tot=0;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}
mt19937 rnd(1234);
int val[5][N];
struct fenwick{
    int tr[N];
    void add(int x, int v){
        for(; x<=n; x+=(x&-x)) tr[x]=(tr[x]+v)%mod;
    }
    int get(int x){
        int ret=0;
        for(; x; x-=(x&-x)) ret=(ret+tr[x])%mod;
        return ret;
    }
}T[5];
void solve(){
    n=rd(); m=rd(); w=rd();
    unordered_map<int, int> h; 
    for(int i=1; i<=n; ++i) {
        a[i]=rd();
        h[a[i]]=rnd()%mod;
    }
    for(int i=1; i<=n; ++i) c[i]=rd();
    for(int j=0; j<t; ++j){
        int sum=0;
        for(int i=0; i<=w-2; ++i) v[j][i]=rnd()%mod, sum=(sum+v[j][i])%mod;
        v[j][w-1]=(mod-sum)%mod;
    }
    for(int j=0; j<t; ++j){
        for(int i=1; i<=n; ++i) T[j].tr[i]=0;
        int sum=0;
        for(int i=1; i<=n; ++i){
            val[j][i]=1ll*v[j][c[i]]*h[a[i]]%mod;
            T[j].add(i, val[j][i]);
            sum=(sum+val[j][i])%mod;
        }
    }
    int op, x, l, r, va, vc;
    for(int i=1; i<=m; ++i){
        op=rd();
        if(op==1){
            x=rd(); va=rd(); vc=rd();
            if(h.find(va)==h.end()) h[va]=rnd()%mod;
            for(int j=0; j<t; ++j){
                int nv=1ll*v[j][vc]*h[va]%mod;
                T[j].add(x, (nv+mod-val[j][x])%mod);
                val[j][x]=nv;
            }
            a[x]=va; c[x]=vc;
        }
        else{
            l=rd(); r=rd();
            bool flag=1;
            for(int j=0; j<t; ++j){
                // cout<<T[j].get(l-1)<<' '<<T[j].get(r)<<endl;
                if(T[j].get(l-1)!=T[j].get(r)){
                    flag=0; break;
                }
            }
            if(flag) printf("YES\n");
            else printf("NO\n");
        }
    }
}
signed main(){
    Test=rd();
    while(Test--){
        solve();
    }
    
    
}