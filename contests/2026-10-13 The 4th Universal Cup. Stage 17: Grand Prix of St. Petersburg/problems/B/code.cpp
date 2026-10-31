#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int n;
int lid[N], rid[N], idx;
int ans[N][300];
void build(int p, int l, int r){
    if(l==r){
        lid[p]=idx; rid[p]=idx; ++idx;
        for(int i=0; i<=n+1; ++i) ans[lid[p]][i]=-l;
        return ;
    }
    if(l+1==r){
        lid[p]=idx; rid[p]=idx; idx=rid[p]+1;
        for(int i=0; i<=n+1; ++i) ans[lid[p]][i]=lid[p];
        ans[lid[p]][0]=-l;
        ans[lid[p]][l]=-r;
        return ;
    }
    int mid=(l+r)>>1;
    lid[p]=idx; rid[p]=idx+(mid-l+1); idx=rid[p]+1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    for(int i=lid[p]; i<rid[p]; ++i){
        ans[i][0]=lid[p<<1];
        for(int v=1; v<=n+1; ++v){
            if(l<=v&&v<=mid) ans[i][v]=i+1;
            else ans[i][v]=i;
        }
    }
    ans[rid[p]][0]=lid[p<<1|1];
    for(int v=1; v<=n+1; ++v){
        // if(l<=v&&v<=mid) continue;
        ans[rid[p]][v]=rid[p];
    }
}
int main(){
    // freopen("B.out", "w", stdout);
    scanf("%d", &n);
    build(1, 1, n+1);
    printf("%d\n", idx);
    for(int i=0; i<idx; ++i){
        for(int j=0; j<=n+1; ++j) printf("%d ", ans[i][j]);
        putchar('\n');
    }
}