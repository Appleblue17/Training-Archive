#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T, n, m;
char s[N];
struct bignum{
    vector<char> a;
    int len;
    friend void operator +=(bignum &x, bignum &y){
        x.len=max(x.len, y.len);
        x.a.resize(x.len); 
        x.a.push_back(0);
        for(int i=0; i<y.len; ++i) {
            x.a[i]+=y.a[i];
            if(x.a[i]>=10){
                ++x.a[i+1];
                x.a[i]-=10;
            }
        }
        for(int i=y.len; i<x.len; ++i){
            if(x.a[i]>=10){
                ++x.a[i+1];
                x.a[i]-=10;
            }
        }
        if(x.a[x.len]) ++x.len;
        else x.a.pop_back();
    }
    friend bool operator <(bignum &x, bignum &y){
        if(x.len>y.len) return false;
        if(x.len<y.len) return true;
        for(int i=x.len-1; i>=0; --i){
            if(x.a[i]!=y.a[i]) return x.a[i]<y.a[i];
        }
        return false;
    }
}ans;
int bs;
int len[N];
int lp[N], rp[N];
bignum pre[N];
void dfs(int x, int sum, int cnt){
    if(len[x-1]>ans.len) return ;
    if(x==m+1){
        len[x]=n-sum; lp[x]=rp[x-1]+1; rp[x]=rp[x-1]+len[x];
        if(len[x]>ans.len) return ;
        pre[x].a.clear(); pre[x].len=0;
        for(int i=rp[x]; i>=lp[x]; --i) pre[x].len++, pre[x].a.push_back(s[i]-'0');
        pre[x]+=pre[x-1];
        if(pre[x]<ans) ans=pre[x];
        return ;
    }
    if(bs!=1&&sum+bs-1<n){
        len[x]=bs-1; lp[x]=rp[x-1]+1; rp[x]=rp[x-1]+len[x];
        pre[x].a.clear(); pre[x].len=0;
        for(int i=rp[x]; i>=lp[x]; --i) pre[x].len++, pre[x].a.push_back(s[i]-'0');
        pre[x]+=pre[x-1];
        if(pre[x]<ans) dfs(x+1, sum+bs-1, cnt);
    }
    if(sum+bs<n){
        len[x]=bs; lp[x]=rp[x-1]+1; rp[x]=rp[x-1]+len[x];
        pre[x].a.clear(); pre[x].len=0;
        for(int i=rp[x]; i>=lp[x]; --i) pre[x].len++, pre[x].a.push_back(s[i]-'0');
        pre[x]+=pre[x-1];
        if(pre[x]<ans) dfs(x+1, sum+bs, cnt);
    }
    if(sum+bs+1<n&&cnt<3){
        len[x]=bs+1; lp[x]=rp[x-1]+1; rp[x]=rp[x-1]+len[x];
        pre[x].a.clear(); pre[x].len=0;
        for(int i=rp[x]; i>=lp[x]; --i) pre[x].len++, pre[x].a.push_back(s[i]-'0');
        pre[x]+=pre[x-1];
        if(pre[x]<ans) dfs(x+1, sum+bs+1, cnt+1);
    }
}
void dfs2(int x, int sum, int cnt){
    if(len[x-1]>ans.len) return ;
    if(x==m+1){
        len[x]=n-sum; lp[x]=rp[x-1]+1; rp[x]=rp[x-1]+len[x];
        if(len[x]>ans.len) return ;
        pre[x].a.clear(); pre[x].len=0;
        for(int i=rp[x]; i>=lp[x]; --i) pre[x].len++, pre[x].a.push_back(s[i]-'0');
        pre[x]+=pre[x-1];
        if(pre[x]<ans) ans=pre[x];
        return ;
    }
    if(bs!=1&&sum+bs-1<n&&cnt<4){
        len[x]=bs-1; lp[x]=rp[x-1]+1; rp[x]=rp[x-1]+len[x];
        pre[x].a.clear(); pre[x].len=0;
        for(int i=rp[x]; i>=lp[x]; --i) pre[x].len++, pre[x].a.push_back(s[i]-'0');
        pre[x]+=pre[x-1];
        if(pre[x]<ans) dfs2(x+1, sum+bs-1, cnt+1);
    }
    if(sum+bs<n){
        len[x]=bs; lp[x]=rp[x-1]+1; rp[x]=rp[x-1]+len[x];
        pre[x].a.clear(); pre[x].len=0;
        for(int i=rp[x]; i>=lp[x]; --i) pre[x].len++, pre[x].a.push_back(s[i]-'0');
        pre[x]+=pre[x-1];
        if(pre[x]<ans) dfs2(x+1, sum+bs, cnt+1);
    }
    if(sum+bs+1<n){
        len[x]=bs+1; lp[x]=rp[x-1]+1; rp[x]=rp[x-1]+len[x];
        pre[x].a.clear(); pre[x].len=0;
        for(int i=rp[x]; i>=lp[x]; --i) pre[x].len++, pre[x].a.push_back(s[i]-'0');
        pre[x]+=pre[x-1];
        if(pre[x]<ans) dfs2(x+1, sum+bs+1, cnt);
    }
}
void solve(){
    scanf("%d%d", &n, &m);
    scanf("%s", s+1);
    bs=(n+m)/(m+1);
    ans.a.clear();
    ans.len=1e9;
    dfs(1, 0, 0);
    if(bs!=1){
        bs--;
        dfs2(1, 0, 0);
    }
    for(int i=ans.len-1; i>=0; --i) putchar('0'+ans.a[i]);
    putchar('\n');
}
int main(){
    // freopen("F.txt", "r", stdin);
    // freopen("F1.txt", "w", stdout);
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
