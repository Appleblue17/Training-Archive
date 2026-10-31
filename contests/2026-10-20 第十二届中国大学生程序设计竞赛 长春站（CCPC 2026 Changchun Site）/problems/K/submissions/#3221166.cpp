#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n, m, q;
int qt[N], qx[N];
int jinl[N], jinr[N];
int fa[N][20], dep[N];
int lg[N];
int stl[20][N], str[20][N];
void build(){
    for(int i=2; i<=m; ++i) lg[i]=lg[i>>1]+1;
    for(int i=1; i<=m; ++i){
        if(qt[i]==0) stl[0][i]=qx[i], str[0][i]=n+1;
        else stl[0][i]=0, str[0][i]=qx[i];
    }
    for(int t=1; t<=lg[m]; ++t){
        for(int i=1; i+(1<<t)-1<=m; ++i){
            stl[t][i]=max(stl[t-1][i], stl[t-1][i+(1<<(t-1))]);
            str[t][i]=min(str[t-1][i], str[t-1][i+(1<<(t-1))]);
        }
    }
}
inline int gmx(int l, int r){
    int t=lg[r-l+1];
    return max(stl[t][l], stl[t][r-(1<<t)+1]);
}
inline int gmn(int l, int r){
    int t=lg[r-l+1];
    return min(str[t][l], str[t][r-(1<<t)+1]);
}
int main(){
    // freopen("K.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for(int i=1; i<=m; ++i){
        scanf("%d%d", &qt[i], &qx[i]);
    }
    build();
    vector<int> stk;
    for(int i=1; i<=m; ++i) {
        if(qt[i]==0) {
            while(!stk.empty()&&qx[i]>=qx[stk.back()]) stk.pop_back();
            if(!stk.empty()) fa[i][0]=stk.back(), dep[i]=dep[stk.back()]+1;
            stk.push_back(i);
        }
        if(!stk.empty()) jinl[i]=stk.back();
    }
    stk.clear();
    for(int i=1; i<=m; ++i) {
        if(qt[i]==1) {
            while(!stk.empty()&&qx[i]<=qx[stk.back()]) stk.pop_back();
            if(!stk.empty()) fa[i][0]=stk.back(), dep[i]=dep[stk.back()]+1;
            stk.push_back(i);
        }
        if(!stk.empty()) jinr[i]=stk.back();
    }
    for(int i=1; i<20; ++i){
        for(int j=1; j<=m; ++j) fa[j][i]=fa[fa[j][i-1]][i-1];
    }
    int l, r;
    while(q--){
        scanf("%d%d", &l, &r);
        int lv=l, rv=r, mid, ret=l;
        while(lv<=rv){
            mid=(lv+rv)>>1;
            if(gmx(mid, r)+1>=gmn(mid, r)){
                ret=mid; lv=mid+1;
            }
            else{
                rv=mid-1;
            }
        }
        int ans=0;
        int p=jinl[r];
        if(p>=ret){
            for(int i=19; i>=0; --i) if(fa[p][i]>=ret) p=fa[p][i];
            ans+=dep[jinl[r]]-dep[p]+1;
        }
        p=jinr[r];
        if(p>=ret){
            for(int i=19; i>=0; --i) if(fa[p][i]>=ret) p=fa[p][i];
            ans+=dep[jinr[r]]-dep[p]+1;
        }
        printf("%d\n", ans);
    }
}