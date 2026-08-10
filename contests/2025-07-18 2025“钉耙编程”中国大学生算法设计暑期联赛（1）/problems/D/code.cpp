#include<bits/stdc++.h>
using namespace std;
const int N=3e6+6;
typedef long long ll;
int T, n, m;
char s[N];
struct node{
    int len, fa;
    int ch[26];
}empty_node;
node sam[N]; int cnt;
int edpos[N], occ[N];
ll sum1[N]; int sum2[N];
int extend(int c, int lst){
    if(sam[lst].ch[c]){
        int p=lst, q=sam[p].ch[c];
        if(sam[q].len==sam[p].len+1) return q;
        else{
            int nq=++cnt;
            sum1[nq]=sum1[q]; sum2[nq]=sum2[q];
            sam[nq]=sam[q]; sam[nq].len=sam[p].len+1;
            sam[q].fa=nq;
            for(; p&&sam[p].ch[c]==q; p=sam[p].fa) sam[p].ch[c]=nq;
            return nq;
        }
    }
    int p=lst, np=++cnt;
    sam[np].len=sam[p].len+1;
    for(; p&&!sam[p].ch[c]; p=sam[p].fa) sam[p].ch[c]=np;
    if(!p) sam[np].fa=1;
    else{
        int q=sam[p].ch[c];
        if(sam[q].len==sam[p].len+1) sam[np].fa=q;
        else{
            int nq=++cnt;
            sum1[nq]=sum1[q]; sum2[nq]=sum2[q];
            sam[nq]=sam[q]; sam[nq].len=sam[p].len+1;
            sam[np].fa=sam[q].fa=nq;
            for(; p&&sam[p].ch[c]==q; p=sam[p].fa) sam[p].ch[c]=nq;
        }
    }
    return np;
}
vector<int> e[N];
void dfs(int x){
    for(auto y:e[x]){
        dfs(y);
        occ[x]|=occ[y];
        edpos[x]=max(edpos[x], edpos[y]);
    }
    if(occ[x]){
        sum1[x]+=edpos[x];
        sum2[x]+=1;
    }
}
void solve(){
    for(int i=1; i<=cnt; ++i){
        sam[i]=empty_node; sum1[i]=sum2[i]=0; edpos[i]=0; occ[i]=0;
    }
    cnt=1;
    scanf("%d", &n);
    for(int _=1; _<=n; ++_){
        scanf("%s", s+1); m=strlen(s+1);
        reverse(s+1, s+m+1);
        for(int i=1; i<=cnt; ++i) edpos[i]=0, occ[i]=0;
        int lst=1;
        for(int i=1; i<=m; ++i) lst=extend(s[i]-'a', lst), edpos[lst]=m-i+1, occ[lst]=1;
        for(int i=1; i<=cnt; ++i) e[i].clear();
        for(int i=2; i<=cnt; ++i) e[sam[i].fa].push_back(i);
        dfs(1);
    }
    ll ans=0;
    for(int i=1; i<=cnt; ++i){
        if(sum2[i]>1){
            ans=max(ans, sum1[i]*sam[i].len);
        }
    }
    printf("%lld\n", ans);
}
int main(){
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        solve();
    }
}