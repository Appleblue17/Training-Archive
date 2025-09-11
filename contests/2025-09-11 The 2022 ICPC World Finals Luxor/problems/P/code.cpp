#include<bits/stdc++.h>
using namespace std;
#define fail printf("impossible\n"), exit(0);
const int N=1e6+5;
int n, m;
char s[N];
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
vector<pii> e[N];
int tran(char x){
    if(x=='R') return 0;
    if(x=='G') return 2;
    if(x=='B') return 1;
}
vector<int> vec[N], bin[N];
int res[N];
void dfs(int x, int v){
    if(res[x]!=-1){
        if(res[x]!=v) fail
        return ;
    }
    res[x]=v;
    for(auto [y, id]:e[x]){
        dfs(y, (tran(s[id])+3-v)%3);
    }
}
vector<int> tem;
void dfs2(int x, int v, int &sum){
    if(res[x]!=-1){
        if(res[x]!=v) fail
        return ;
    }
    tem.push_back(x);
    res[x]=v; sum+=v;
    for(auto [y, id]:e[x]){
        dfs2(y, (tran(s[id])+3-v)%3, sum);
    }
}
int main(){
    scanf("%d%d", &n, &m);
    scanf("%s", s+1);
    memset(res, -1, sizeof res);
    for(int i=1, k, a; i<=m; ++i){
        scanf("%d", &k);
        while(k--){
            scanf("%d", &a);
            vec[i].push_back(a);
            bin[a].push_back(i);
        }
    }
    for(int i=1; i<=n; ++i) if(bin[i].empty()&&tran(s[i])!=0){
        fail
    }
    for(int i=1; i<=n; ++i) if(bin[i].size()==2){
        e[bin[i][0]].push_back(mapa(bin[i][1], i));
        e[bin[i][1]].push_back(mapa(bin[i][0], i));
    }
    for(int i=1; i<=n; ++i) if(bin[i].size()==1){
        dfs(bin[i][0], tran(s[i]));
    }
    for(int i=1; i<=m; ++i) if(res[i]==-1){
        int mn=1e9, argmn=-1, sum=0;
        dfs2(i, 0, sum);
        for(auto t:tem) res[t]=-1;
        tem.clear();
        if(sum<mn) mn=sum, argmn=0;
        sum=0;
        dfs2(i, 1, sum);
        for(auto t:tem) res[t]=-1;
        tem.clear();
        if(sum<mn) mn=sum, argmn=1;
        sum=0;
        dfs2(i, 2, sum);
        for(auto t:tem) res[t]=-1;
        tem.clear();
        if(sum<mn) mn=sum, argmn=2;
        sum=0;
        dfs2(i, argmn, sum);
        tem.clear();
    }
    res[0]=0;
    for(int i=1; i<=m; ++i){
        if(res[i]==-1) res[i]=0;
        res[0]+=res[i];
    }
    printf("%d\n", res[0]);
}
