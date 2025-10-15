#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5;
int n,q,U,R;
int a[N];

int f[N*4],tag[N*4];

void upd(int o,int x){
    f[o]+=x,tag[o]+=x;
}
void pushdown(int o){
    upd(o<<1,tag[o]);
    upd(o<<1|1,tag[o]);
    tag[o]=0;
}
void modify(int l,int r,int o,int L,int R,int x){
    if(l>r) return ;
    if(L<=l && r<=R){
        upd(o,x);
        return ;
    }
    pushdown(o);
    int mid=(l+r)>>1;
    if(L<=mid) modify(l,mid,o<<1,L,R,x);
    if(R>mid) modify(mid+1,r,o<<1|1,L,R,x);
    f[o]=min(f[o<<1],f[o<<1|1]);
}

int query(int l,int r,int o){
    if(l>r) return -1;
    if(l==r){
        if(f[o]<=R) return l;
        else return -1;
    }
    pushdown(o);
    int mid=(l+r)>>1;
    if(f[o<<1]<=R) return query(l,mid,o<<1);
    else if(f[o<<1|1]<=R) return query(mid+1,r,o<<1|1);
    return -1;
}

void update(int pos,int x){
    int l=max(2ll,pos-U+1),r=pos;
    modify(2,n,1,l,r,x);
}

int c[N];
int lowbit(int x){
    return x & (-x);
}
void mdf(int x,int k){
    while(x<=n) c[x]+=k,x+=lowbit(x);
}
int qry(int x){
    int tot=0;
    while(x) tot+=c[x],x-=lowbit(x);
    return tot;
}

void solve(){
    if(n==1){
        printf("%lld\n",a[1]);
        return ;
    }
    
    int ret=query(2,n,1);
    // cout<<ret<<" "<<qry(ret)<<endl;
    if(ret==-1) printf("%lld\n",qry(n));
    else printf("%lld\n",qry(min(n,ret+U-1)));
}

// void pr(int l,int r,int o){
//     if(l==r){
//         cout<<"pr "<<l<<": "<<f[o]<<endl;
//         return ;
//     }
//     pushdown(o);
//     int mid=(l+r)>>1;
//     pr(l,mid,o<<1);
//     pr(mid+1,r,o<<1|1);
// }

signed main(){
    scanf("%lld%lld%lld",&n,&U,&R);
    U=min(U,n-1);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    
    for(int i=1;i<=n;i++) mdf(i,a[i]);
    for(int i=2;i<=n;i++){
        update(i,a[i]);
    }
    solve();
    
    scanf("%lld",&q);
    while(q--){
        int pos,x; scanf("%lld%lld",&pos,&x);
        if(pos>1) update(pos,x-a[pos]);
        mdf(pos,x-a[pos]);
        a[pos]=x;
        
        solve();
    }
}
