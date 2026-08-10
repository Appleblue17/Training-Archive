#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,m;
char s[N];
struct info{
    int pre[26], suf[26];
    int ans, l, r;
    int p1[26], p2[26], lenth1, lenth2, cursta;
    void set(int x){
        l=r=x;
        for(register int i=0; i<26; ++i) pre[i]=n+1, suf[i]=0;
        pre[s[x]-'a']=suf[s[x]-'a']=x;
        ans=1;
        lenth1=lenth2=1;
        p1[0]=p2[0]=s[x]-'a';
        cursta=1<<p1[0];
    }
}tr[N<<2];
int vec[2][26][2];
int sz[2];
int cursta, op, lst, clen;
inline void work(info &ret, info &x, info &y){
    ret.l=x.l; ret.r=y.r;
    ret.ans=max(x.ans, y.ans);
    ret.cursta=x.cursta|y.cursta;
    cursta=x.cursta;
    for(register int i=0; i<26; ++i){
        ret.pre[i]=min(x.pre[i], y.pre[i]);
        ret.suf[i]=max(x.suf[i], y.suf[i]);
    }
    sz[0]=sz[1]=0;
    lst=x.l;
    for(register int i=0; i<x.lenth1; ++i){
        op=(x.r-lst+1)&1;
        vec[op][sz[op]][0]=x.r-lst+1, vec[op][sz[op]++][1]=cursta;
        if(lst+1<=x.suf[x.p1[i]]){
            op^=1;
            vec[op][sz[op]][0]=x.r-lst, vec[op][sz[op]++][1]=cursta;
        }
        cursta^=1<<x.p1[i];
        lst=max(lst, x.suf[x.p1[i]]+1);
    }
    cursta=y.cursta;
    lst=y.r;
    for(register int i=0; i<y.lenth2; ++i){
        clen=lst-y.l+1;
        op=(clen&1)^1;
        for(register int j=0; j<sz[op]; ++j){
            if(vec[op][j][0]+clen<=ret.ans) break;
            if(__builtin_parity(cursta|vec[op][j][1])){
                ret.ans=vec[op][j][0]+clen;
                break;
            }
        }
        if(lst-1>=y.pre[y.p2[i]]){
            --clen; op^=1;
            for(register int j=0; j<sz[op]; ++j){
                if(vec[op][j][0]+clen<=ret.ans) break;
                if(__builtin_parity(cursta|vec[op][j][1])){
                    ret.ans=vec[op][j][0]+clen;
                    break;
                }
            }
        }
        cursta^=1<<y.p2[i];
        lst=min(lst, y.pre[y.p2[i]]-1);
    }
    ret.lenth1=0;
    for(int i=0; i<x.lenth1; ++i) {
        if(y.suf[x.p1[i]]==0) ret.p1[ret.lenth1++]=x.p1[i];
    }
    for(int i=0; i<y.lenth1; ++i) ret.p1[ret.lenth1++]=y.p1[i];
    ret.lenth2=0;
    for(int i=0; i<y.lenth2; ++i) {
        if(x.suf[y.p2[i]]==0) ret.p2[ret.lenth2++]=y.p2[i];
    }
    for(int i=0; i<x.lenth2; ++i) ret.p2[ret.lenth2++]=x.p2[i];
}
void build(int p, int l, int r){
    if(l==r){
        tr[p].set(l);
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    work(tr[p], tr[p<<1], tr[p<<1|1]);
}
void mdf(int p, int l, int r, int x){
    if(l==r){
        tr[p].set(l);
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) mdf(p<<1, l, mid, x);
    else mdf(p<<1|1, mid+1, r, x);
    work(tr[p], tr[p<<1], tr[p<<1|1]);
}
int main(){
    // freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
    // freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s+1);
    build(1, 1, n);
    printf("%d\n", tr[1].ans);
    while(m--){
        int x; scanf("%d", &x);
        char c=getchar();
        while(c<'a'||c>'z') c=getchar();
        s[x]=c;
        mdf(1, 1, n, x);
        printf("%d\n", tr[1].ans);
    }
}
