#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n, T;
char s[N];
int rk[450][N], dp[450][N];
int c[N], sa[N], y[N];
int tr[N];
void upd(int x, int v){
    for(; x; x-=(x&-x)) if(v>tr[x]) tr[x]=v;
}
int get(int x){
    int ret=0;
    for(; x<=n; x+=(x&-x)) if(tr[x]>ret) ret=tr[x];
    return ret;
}
void solve(){
    scanf("%s", s+1); n=strlen(s+1);
    int st=1;
    while(st<=n&&s[st]=='0') ++st;
    if(st==n+1){
        printf("1\n");
        return ;
    }
    int add=0;
    if(s[1]=='0') add=1;
    for(int i=st; i<=n; ++i) s[i-st+1]=s[i];
    n-=st-1;
    for(int i=n+1; i<=n*2; ++i) s[i]=0;
    int lim=1;
    while((lim+1)*(lim+2)<=2*n) ++lim;
    ++lim;
    lim=min(lim, n);
    for(int i=1; i<=n; ++i) c[rk[1][i]=(s[i]-'0'+1)]++;
    int m=10;
    for(int i=2; i<=m; ++i) c[i]+=c[i-1];
    for(int i=n; i; --i) sa[c[rk[1][i]]--]=i;
    for(int k=2; k<=lim; ++k){
        int num=0;
        for(int i=n-k+2; i<=n; ++i) y[++num]=i;
        for(int i=1; i<=n; ++i){
            if(sa[i]>k-1) y[++num]=sa[i]-(k-1);
        }
        for(int i=1; i<=m; ++i) c[i]=0;
        for(int i=1; i<=n; ++i) c[rk[k-1][i]]++;
        for(int i=2; i<=m; ++i) c[i]+=c[i-1];
        for(int i=n; i; --i) sa[c[rk[k-1][y[i]]]--]=y[i], y[i]=0;
        for(int i=1; i<=n; ++i) y[i]=rk[k-1][i];
        rk[k][sa[1]]=1; num=1;
        for(int i=2; i<=n; ++i)
        rk[k][sa[i]]=(y[sa[i]]==y[sa[i-1]]&&s[sa[i]+k-1]==s[sa[i-1]+k-1])?num:++num;
        m=num;
    }
    for(int k=1; k<=lim+1; ++k) for(int i=1; i<=n+1; ++i) dp[k][i]=0;
    for(int k=lim; k>=1; --k){
        int mx=0;
        for(int i=1; i<=n; ++i) tr[i]=0;
        for(int i=n-k+1; i>=1; --i){
            mx=max(mx, dp[k+1][i+k]);
            upd(rk[k][i+k], dp[k][i+k]);
            dp[k][i]=1+max(mx, get(rk[k][i]+1));
        }
    }
    int ans=0;
    for(int i=1; i<=n; ++i) ans=max(ans, dp[1][i]);
    printf("%d\n", ans+add);
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}