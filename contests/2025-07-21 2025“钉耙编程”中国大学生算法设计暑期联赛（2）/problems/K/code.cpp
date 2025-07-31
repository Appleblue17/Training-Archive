#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=6e5+6;
int T;
int n, m;
char s[N];
int a[N];
struct info{
    bool all0;
    int pre0, suf0, siz, st, ed;
    void set(int o){
        if(o==0){
            all0=1;
            pre0=1; suf0=1; siz=0; st=0; ed=0;
        }
        else{
            all0=0;
            pre0=0; suf0=0; siz=0; st=0; ed=0;
        }
    }
    void prt(){
        printf("all0:%d ", all0);
        printf("pre0:%d ", pre0);
        printf("suf0:%d ", suf0);
        printf("siz:%d ", siz);
        printf("st:%d ", st);
        printf("ed:%d\n", ed);
    }
}empty_info;
info operator +(info x, info y){
    info z=empty_info;
    z.all0=x.all0&y.all0;
    if(x.all0) z.pre0=x.pre0+y.pre0;
    else z.pre0=x.pre0;
    if(y.all0) z.suf0=x.suf0+y.suf0;
    else z.suf0=y.suf0;
    if(y.ed==1){
        z.ed=1; z.siz=y.siz; z.st=y.st;
        return z;
    }
    if(x.all0==1&&y.all0==1){
        z.siz=0; z.st=0; z.ed=0;
        return z;
    }
    if(x.all0==1&&y.all0==0){
        z.ed=y.ed; z.siz=y.siz; z.st=y.st;
        return z;
    }
    if(x.all0==0&&y.all0==1){
        z.ed=x.ed; z.siz=x.siz; z.st=x.st;
        return z;
    }
    if(x.siz!=0&&y.siz!=0){
        if(x.suf0+y.pre0==y.st+y.siz){
            if(x.st==y.st+y.siz+1){
                z.ed=x.ed; z.siz=x.siz+y.siz+1;
                z.st=y.st;
            }
            else{
                z.ed=1; z.st=y.st; z.siz=y.siz+1;
            }
        }
        else{
            z.ed=1; z.st=y.st, z.siz=y.siz;
        }
        return z;
    }
    if(x.siz==0&&y.siz!=0){
        if(x.suf0+y.pre0==y.st+y.siz){
            z.ed=0, z.siz=y.siz+1, z.st=y.st;
        }
        else{
            z.ed=1, z.siz=y.siz, z.st=y.st;
        }
        return z;
    }
    if(x.siz!=0&&y.siz==0){
        if(x.suf0+y.pre0==x.st-1){
            z.ed=x.ed, z.siz=x.siz+1, z.st=x.suf0+y.pre0;
        }
        else{
            z.ed=1; z.siz=1; z.st=x.suf0+y.pre0;
        }
        return z;
    }
    z.siz=1; z.st=x.suf0+y.pre0; z.ed=0;
    return z;
}
info tr[N<<2];
vector<info> vec;
void build(int p, int l, int r){
    if(l==r){
        tr[p].set(a[l]);
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    // cout<<l<<' '<<mid<<' '<<r<<endl;
    // tr[p<<1].prt(); tr[p<<1|1].prt();
    tr[p]=tr[p<<1]+tr[p<<1|1];
    // tr[p].prt();
    // printf("-------------------\n");
}
void mdf(int p, int l, int r, int x){
    if(l==r){
        a[l]^=1;
        tr[p].set(a[l]);
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) mdf(p<<1, l, mid, x);
    else mdf(p<<1|1, mid+1, r, x);
    
    tr[p]=tr[p<<1]+tr[p<<1|1];
}
void qry(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R) {
        vec.push_back(tr[p]);
        return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid) qry(p<<1, l, mid, L, R);
    if(R>mid) qry(p<<1|1, mid+1, r, L, R);
}
void solve(){
    scanf("%d%d", &n, &m);
    scanf("%s", s+1);
    for(int i=1; i<=n; ++i){
        a[i]=s[i]-'0';
    }
    build(1, 1, n);
    while(m--){
        int tp; scanf("%d", &tp);
        if(tp==1){
            int l, r; scanf("%d%d", &l, &r);
            vec.clear();
            qry(1, 1, n, l, r);
            for(int i=1; i<(int)vec.size(); ++i) vec[0]=vec[0]+vec[i];
            // vec[0].prt();
            if(vec[0].all0){
                printf("0\n");
                continue;
            }
            if(vec[0].siz==0){
                printf("%d\n", vec[0].suf0);
                continue;
            }
            if(vec[0].suf0!=vec[0].st-1){
                printf("%d\n", vec[0].suf0);
                continue;
            }
            printf("%d\n", 2*vec[0].siz+vec[0].st+vec[0].siz-1);
        }
        else{
            int x; scanf("%d", &x);
            mdf(1, 1, n, x);
        }
    }
}
int main(){
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        solve();
    }
}