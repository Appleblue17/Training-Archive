#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=998244353;
// #define int long long
int Test, n, m;
int rd(){
    char c=getchar();
    int tot=0;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}
int a[N], b[N];
int idx;
int nxt[N];
int stk[N], top;
int cnt[N];
int f[22][N];
int jmp(int x, int lim){
    int ret=1;
    for(int i=20; i>=0; --i){
        if(f[i][x]>=lim) ret+=(1<<i), x=f[i][x];
    }
    return ret;
}
void solve(){
    n=rd();
    for(int i=1; i<=n; ++i) a[i]=rd(), b[i]=a[i];
    sort(b+1, b+n+1);
    m=unique(b+1, b+n+1)-b-1;
    for(int i=1; i<=n; ++i) a[i]=lower_bound(b+1, b+m+1, a[i])-b;
    top=0;
    for(int i=1; i<=n; ++i){
        while(a[stk[top]]>a[i]) --top;
        f[0][i]=stk[top];
        // cout<<i<<' '<<stk[top]<<endl;
        stk[++top]=i; cnt[i]=top;
    }
    for(int i=1; i<21; ++i){
        for(int j=1; j<=n; ++j) f[i][j]=f[i-1][f[i-1][j]];
    }
    // cout<<jmp(2, 2)<<endl;
    // exit(0);
    for(int i=2, j=0; i<=n; ++i){
        bool flg=0;
        while(true){
            if(jmp(i, i-(j+1)+1)==cnt[j+1]){
                flg=1; break;
            }
            if(j==0) break;
            j=nxt[j];
        }
        if(flg) ++j;
        nxt[i]=j;
    }
    for(int i=1; i<=n; ++i) printf("%d%c", nxt[i], " \n"[i==n]);
}
signed main(){
    // freopen("5.out", "w", stdout);
    Test=rd();
    while(Test--){
        solve();
    }
    
    
}