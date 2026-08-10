#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n, m, q;
int pre[N], suf[N];
vector<int> vec[N], v1[N], v2[N];
struct node{
    int l, r, id;
    bool operator <(const node &t)const{
        return l<t.l;
    }
};
vector<node> ask[N];
int tr[N];
void add(int x, int v){
    ++x;
    for(; x; x-=(x&-x)) tr[x]+=v;
}
int get(int x){
    ++x;
    int ret=0;
    for(; x<=n+2; x+=(x&-x)) ret+=tr[x];
    return ret;
}
int rk[N];
int ans[N];
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1, k; i<=n; ++i){
        scanf("%d", &k);
        for(int j=1, x; j<=k; ++j){
            scanf("%d", &x);
            vec[i].push_back(x);
            v1[i].push_back(pre[x]);
            pre[x]=i;
        }
    }
    for(int i=1; i<=m; ++i) suf[i]=n+1;
    for(int i=n; i>=1; --i){
        for(auto t:vec[i]){
            v2[i].push_back(suf[t]);
            suf[t]=i;
        }
    }
    scanf("%d", &q);
    for(int i=1; i<=n; ++i) {
        int l, r, p;
        scanf("%d%d%d", &l, &r, &p);
        ask[p].push_back((node){l, r, i});
    }
    for(int i=1; i<=n; ++i){
        if(ask[i].empty()||vec[i].empty()) continue;
        for(int j=0; j<(int)vec[i].size(); ++j) rk[j]=j;
        sort(rk, rk+(int)vec[i].size(), [&](int x, int y){return v1[i][x]<v1[i][y];});
        sort(ask[i].begin(), ask[i].end());
        int it=0;
        for(auto t:ask[i]){
            while(it<(int)vec[i].size()&&v1[i][rk[it]]<t.l){
                add(v2[i][rk[it]], 1); ++it;
            }
            ans[t.id]=get(t.r+1);
        }
        for(int w=0; w<it; ++w) add(v2[i][rk[w]], -1);
    }
    for(int i=1; i<=q; ++i){
        printf("%d\n", ans[i]);
    }
    return 0;
}