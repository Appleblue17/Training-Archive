#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5, mxv=1e6;
int st;
int n, m;
int a[N];
int mxg[N<<2], mxf[N<<2], ans[N<<2];
struct myheap{
    priority_queue<int> p, q;
    int top(){
        while(!q.empty()&&p.top()==q.top()) p.pop(), q.pop();
        return p.top();
    }
    void push(int x){
        p.push(x);
    }
    void pop(int x){
        q.push(x);
    }
}f[N], g[N];
void build(int p, int l, int r){
    
    if(l==r){
        f[l].push(0); g[l].push(0);
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
}
int getg(int p, int l, int r, int L, int R){
    if(L>R) return 0;
    if(L<=l&&r<=R){
        return mxg[p];
    }
    int mid=(l+r)>>1, ret=0;
    if(L<=mid) ret=getg(p<<1, l, mid, L, R);
    if(R>mid) ret=max(ret, getg(p<<1|1, mid+1, r, L, R));
    return ret;
}
int getf(int p, int l, int r, int L, int R){
    if(L>R) return 0;
    if(L<=l&&r<=R){
        return mxf[p];
    }
    int mid=(l+r)>>1, ret=0;
    if(L<=mid) ret=getf(p<<1, l, mid, L, R);
    if(R>mid) ret=max(ret, getf(p<<1|1, mid+1, r, L, R));
    return ret;
}
void up(int p){
    mxg[p]=max(mxg[p<<1], mxg[p<<1|1]);
    mxf[p]=max(mxf[p<<1], mxf[p<<1|1]);
    ans[p]=max(max(ans[p<<1], ans[p<<1|1]), mxf[p<<1]+mxg[p<<1|1]);
}
void addg(int p, int l, int r, int x, int v){
    if(l==r){
        g[l].push(v);
        mxg[p]=g[l].top();
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) addg(p<<1, l, mid, x, v);
    else addg(p<<1|1, mid+1, r, x, v);
    up(p);
}
void delg(int p, int l, int r, int x, int v){
    if(l==r){
        g[l].pop(v);
        mxg[p]=g[l].top();
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) delg(p<<1, l, mid, x, v);
    else delg(p<<1|1, mid+1, r, x, v);
    up(p);
}

void addf(int p, int l, int r, int x, int v){
    if(l==r){
        f[l].push(v);
        mxf[p]=f[l].top();
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) addf(p<<1, l, mid, x, v);
    else addf(p<<1|1, mid+1, r, x, v);
    up(p);
}
void delf(int p, int l, int r, int x, int v){
    if(l==r){
        f[l].pop(v);
        mxf[p]=f[l].top();
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) delf(p<<1, l, mid, x, v);
    else delf(p<<1|1, mid+1, r, x, v);
    up(p);
}
char getop(){
    char c=getchar();
    while(c!='<'&&c!='>'&&c!='!') c=getchar();
    return c;
}
int ed;
int main(){
    // cout<<((&ed)-(&st)+1)/1024/1024<<endl;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i){
        scanf("%d", &a[i]);
    }
    build(1, 1, mxv);
    for(int i=n; i>=2; --i){
        addg(1, 1, mxv, a[i], getg(1, 1, mxv, a[i]+1, mxv)+1);
    }
    int it=1;
    char op; int v; int opt;
    while(m--){
        op=getop();
        if(op=='!'){
            scanf("%d", &v);
            a[it]=v;
            opt=ans[1];
            opt=max(opt, max(mxf[1], mxg[1]));
            opt=max(opt, getf(1, 1, mxv, 1, v-1)+1+getg(1, 1, mxv, v+1, mxv));
            printf("%d\n", opt);
        }
        else if(op=='<'){
            delf(1, 1, mxv, a[it-1], getf(1, 1, mxv, 1, a[it-1]-1)+1);
            addg(1, 1, mxv, a[it], getg(1, 1, mxv, a[it]+1, mxv)+1);
            --it;
        }
        else{
            delg(1, 1, mxv, a[it+1], getg(1, 1, mxv, a[it+1]+1, mxv)+1);
            addf(1, 1, mxv, a[it], getf(1, 1, mxv, 1, a[it]-1)+1);
            ++it;
        }
    }
}
