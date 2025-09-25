#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
pair<ll, int> mx[N<<2];
ll tag[N<<2];
void build(int p, int l, int r){
    if(l==r){
        scanf("%lld", &mx[p].first);
        mx[p].second=l;
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    mx[p]=max(mx[p<<1], mx[p<<1|1]);
}
void down(int p){
    if(tag[p]!=0){
        tag[p<<1]+=tag[p]; tag[p<<1|1]+=tag[p];
        mx[p<<1].first+=tag[p]; mx[p<<1|1].first+=tag[p];
        tag[p]=0;
    }
}
void upd(int p, int l, int r, int x, ll v){
    if(l==r){
        mx[p].first=v;
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(x<=mid) upd(p<<1, l, mid, x, v);
    else upd(p<<1|1, mid+1, r, x, v);
    mx[p]=max(mx[p<<1], mx[p<<1|1]);
}
void dfs(int p, int l, int r){
    if(l==r){
        printf("%lld", mx[p].first);
        if(l!=n) putchar(' ');
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    dfs(p<<1, l, mid); dfs(p<<1|1, mid+1, r);
}
int main(){
    scanf("%d", &n);
    build(1, 1, n);
    int cnt=0;
    while(true){
        if(mx[1].first<=n-2) break;
        ll w=mx[1].first/(n-1), r=mx[1].first%(n-1);
        tag[1]+=w;
        upd(1, 1, n, mx[1].second, r);
        ++cnt;
        if(cnt==3*n){
            printf("Recurrent");
            return 0;
        }
    }
    dfs(1, 1, n);
}
