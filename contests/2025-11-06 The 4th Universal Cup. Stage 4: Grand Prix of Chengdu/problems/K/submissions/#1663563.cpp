#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n, L, k;
int a[N];
int sum[N];
int mx[N<<2], tag[N<<2];
void clr(int p, int l, int r){
    mx[p]=0; tag[p]=0;
    if(l==r) return ;
    int mid=(l+r)>>1;
    clr(p<<1, l, mid); clr(p<<1|1, mid+1, r);
}
inline void apply(int p, int x){
    mx[p]+=x; tag[p]+=x;
}
inline void down(int p){
    if(tag[p]!=0){
        apply(p<<1, tag[p]);
        apply(p<<1|1, tag[p]);
        tag[p]=0;
    }
}
void mdf(int p, int l, int r, int L, int R, int v){
    if(L>R) return ;
    if(L<=l&&r<=R){
        apply(p, v);
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(L<=mid) mdf(p<<1, l, mid, L, R, v);
    if(R>mid) mdf(p<<1|1, mid+1, r, L, R, v);
    mx[p]=max(mx[p<<1], mx[p<<1|1]);
}
bool vis[N];
void solve(){
    scanf("%d%d%d", &n, &L, &k);
    for(int i=0; i<n*4; ++i) sum[i]=0, vis[i]=0;
    clr(1, 0, n*3);
    for(int i=1; i<=n; ++i){
        scanf("%d", &a[i]);
        sum[a[i]]++; sum[a[i]+L]--;
        vis[a[i]+L-1]=1;
    }
    for(int i=1; i<n*4; ++i) sum[i]+=sum[i-1];
    int base=0;
    for(int i=0; i<n*4; ++i){
        if(sum[i]==k){
            ++base;
            mdf(1, 0, n*3, max(0, i-L+1), min(n*3, i), -1);
        }
        if(sum[i]==k-1){
            mdf(1, 0, n*3, max(0, i-L+1), min(n*3, i), 1);
        }
    }
    int ans=base;
    for(int i=0; i<L; ++i){
        if(sum[i]==k){
            --base;
            mdf(1, 0, n*3, max(0, i-L+1), min(n*3, i), 2);
        }
        if(sum[i]==k-1){
            mdf(1, 0, n*3, max(0, i-L+1), min(n*3, i), -1);
        }
        if(sum[i]==k+1){
            ++base;
            mdf(1, 0, n*3, max(0, i-L+1), min(n*3, i), -1);
        }
    }
    if(vis[L-1]) ans=max(ans, base+mx[1]);
    for(int i=L; i<=n*3; ++i){
        if(sum[i-L]==k){
            ++base;
            mdf(1, 0, n*3, max(0, i-L-L+1), min(n*3, i-L), -2);
        }
        if(sum[i-L]==k-1){
            mdf(1, 0, n*3, max(0, i-L-L+1), min(n*3, i-L), 1);
        }
        if(sum[i-L]==k+1){
            --base;
            mdf(1, 0, n*3, max(0, i-L-L+1), min(n*3, i-L), 1);
        }
        
        
        if(sum[i]==k){
            --base;
            mdf(1, 0, n*3, max(0, i-L+1), min(n*3, i), 2);
        }
        if(sum[i]==k-1){
            mdf(1, 0, n*3, max(0, i-L+1), min(n*3, i), -1);
        }
        if(sum[i]==k+1){
            ++base;
            mdf(1, 0, n*3, max(0, i-L+1), min(n*3, i), -1);
        }
        
        if(vis[i]) ans=max(ans, base+mx[1]);
    }
    printf("%d\n", ans);
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
