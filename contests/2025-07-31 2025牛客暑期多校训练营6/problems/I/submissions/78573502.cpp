#include <bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int n, m;
char s[N];
int cnt=1, lst=1;
struct node{
    int len, fa;
    int ch[26];
}sam[N];
int firpos[N], endpos[N];
void extend(int x){
    int p=lst, np=lst=++cnt;
    firpos[np]=x;
    int c=s[x]-'a';
    sam[np].len=sam[p].len+1;
    for(; p&&!sam[p].ch[c]; p=sam[p].fa) sam[p].ch[c]=np;
    if(!p) sam[np].fa=1;
    else{
        int q=sam[p].ch[c];
        if(sam[q].len==sam[p].len+1) sam[np].fa=q;
        else{
            int nq=++cnt;
            sam[nq]=sam[q]; sam[nq].len=sam[p].len+1;
            sam[q].fa=sam[np].fa=nq;
            firpos[nq]=firpos[q];
            for(; p&&sam[p].ch[c]==q; p=sam[p].fa) sam[p].ch[c]=nq;
        }
    }
}
struct T1{
    int mx[N<<2];
    void mdf(int p, int l, int r, int x, int v){
        if(l==r){
            mx[p]=max(mx[p], v);
            return ;
        }
        int mid=(l+r)>>1;
        if(x<=mid) mdf(p<<1, l, mid, x, v);
        else mdf(p<<1|1, mid+1, r, x, v);
        mx[p]=max(mx[p<<1], mx[p<<1|1]);
    }
    int get(int p, int l, int r, int L, int R){
        if(L<=l&&r<=R) return mx[p];
        int mid=(l+r)>>1, ret=0;
        if(L<=mid) ret=get(p<<1, l, mid, L, R);
        if(R>mid) ret=max(ret, get(p<<1|1, mid+1, r, L, R));
        return ret;
    }
}t1;
struct T2{
    struct data{
        int k, b, sx, ex;
    }a[N];
    int cnt=0;
    int calc(int id, int x){
        return a[id].k*x+a[id].b;
    }
    int mx[N<<2];
    void add(int sx, int sy, int ex, int ey){
        ++cnt;
        a[cnt].sx=sx; a[cnt].ex=ex;
        if(sx==ex){
            a[cnt].k=0; a[cnt].b=max(sy, ey);
        }
        else{
            a[cnt].k=-1;
            a[cnt].b=sx+sy;
        }
    }
    void upd(int p, int l, int r, int x){
        int mid=(l+r)>>1, &y=mx[p];
        if(calc(x, mid)>calc(y, mid)) swap(x, y);
        if(calc(x, l)>calc(y, l)) upd(p<<1, l, mid, x);
        if(calc(x, r)>calc(y, r)) upd(p<<1|1, mid+1, r, x);
    }
    void mdf(int p, int l, int r, int L, int R, int x){
        if(L<=l&&r<=R){
            upd(p, l, r, x);
            return ;
        }
        int mid=(l+r)>>1;
        if(L<=mid) mdf(p<<1, l, mid, L, R, x);
        if(R>mid) mdf(p<<1|1, mid+1, r, L, R, x);
    }
    int get(int p, int l, int r, int x){
        if(r<x||x<l) return 0;
        int mid=(l+r)>>1;
        int ret=calc(mx[p], x);
        if(l==r) return ret;
        return max(ret, max(get(p<<1, l, mid, x), get(p<<1|1, mid+1, r, x)));
    }
}t2;
vector<pair<int, int> > ask[N], ele[N];
int ans[N];
vector<int> e[N];
void dfs(int x){
    endpos[x]=firpos[x];
    for(auto y:e[x]){
        dfs(y);
        endpos[x]=max(endpos[x], endpos[y]);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    scanf("%s", s+1);
    for(int i=1; i<=n; ++i) extend(i);
    for(int i=2; i<=cnt; ++i) e[sam[i].fa].push_back(i), endpos[lst]=i;
    dfs(1);
    for(int i=2; i<=cnt; ++i){
        int sz=sam[i].len-sam[sam[i].fa].len;
        t2.add(endpos[i]-sam[i].len+1, sam[i].len, endpos[i]-sam[i].len+sz, sam[i].len-sz+1);
        ele[firpos[i]].push_back(make_pair(i, t2.cnt));
    }
    for(int i=1, x, y; i<=m; ++i){
        scanf("%d%d", &x, &y);
        ask[x].push_back(make_pair(y, i));
    }
    for(int i=1; i<=n; ++i){
        for(auto t:ele[i]){
            t2.mdf(1, 1, n, t2.a[t.second].sx, t2.a[t.second].ex, t.second);
            t1.mdf(1, 1, n, endpos[t.first]-sam[t.first].len+1, sam[t.first].len);
        }
        for(auto t:ask[i]){
            ans[t.second]=max(t1.get(1, 1, n, t.first, n), t2.get(1, 1, n, t.first));
        }
    }
    for(int i=1; i<=m; ++i) {
        printf("%d\n", ans[i]);
    }
}
