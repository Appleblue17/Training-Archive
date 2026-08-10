#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
#define ep emplace_back
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=1e6+5, mod=998244353;
int n, m;
int pw[N], a[N];
pii mn[N<<2], mx[N<<2]; int sz[N<<2], hs[N<<2];
int pre[N], suf[N], occ[N];
pii fnd(int p, int l, int r, pii x){
    if(l==r){
        if(mx[p]>=x) return mapa(hs[p], 1);
        else return mapa(0, 0);
    }
    if(mn[p]>=x) return mapa(hs[p], sz[p]);
    int mid=(l+r)>>1;
    if(mx[p<<1|1]>=x){
        int reths=(hs[p]+mod-(ll)hs[p<<1|1]*pw[sz[p]-sz[p<<1|1]]%mod)%mod;
        int retsz=sz[p]-sz[p<<1|1];
        pii rs_info=fnd(p<<1|1, mid+1, r, x);
        return mapa(((ll)rs_info.fi*pw[retsz]+reths)%mod, retsz+rs_info.se);
    }
    else{
        return fnd(p<<1, l, mid, x);
    }
}
void build(int p, int l, int r){
    if(l==r){
        mn[p]=mx[p]=mapa(a[l], -l);
        sz[p]=1; hs[p]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    mx[p]=max(mx[p<<1], mx[p<<1|1]);
    mn[p]=mn[p<<1|1];
    pii tem=fnd(p<<1, l, mid, mx[p<<1|1]);
    sz[p]=tem.se+sz[p<<1|1];
    hs[p]=((ll)hs[p<<1|1]*pw[tem.se]+tem.fi)%mod;
}
int reths, retsz; pii bound;
void ghs(int p, int l, int r, int L, int R){
    if(L<=l&&r<=R){
        pii cur=fnd(p, l, r, bound);
        // cout<<"ontree:"<<l<<' '<<r<<' '<<cur.fi<<' '<<cur.se<<' '<<bound.fi<<endl;
        reths=((ll)reths*pw[cur.se]+cur.fi)%mod;
        retsz+=cur.se;
        bound=max(bound, mx[p]);
        // cout<<reths<<' '<<retsz<<' '<<bound.fi<<endl;
        return ;
    }
    int mid=(l+r)>>1;
    if(R>mid) ghs(p<<1|1, mid+1, r, L, R);
    if(L<=mid) ghs(p<<1, l, mid, L, R);
}
vector<pii> qry[N];
int ans[N];
int stk1[N], top1, stk2[N], top2;
int w[N];
set<int> s1, s2;
int cnt[N];
struct seg{
    int mx[N<<2], mx2[N<<2];
    void mdf(int p, int l, int r, int L, int R, int v){
        if(L<=l&&r<=R) {
            mx[p]=max(mx[p], v);
            mx2[p]=max(mx2[p], v);
            return ;
        }
        if(l==r) return ;
        int mid=(l+r)>>1;
        if(L<=mid) mdf(p<<1, l, mid, L, R, v);
        if(R>mid) mdf(p<<1|1, mid+1, r, L, R, v);
        mx2[p]=max(max(mx2[p], mx2[p<<1]), mx2[p<<1|1]);
    }
    int gmx(int p, int l, int r, int L, int R){
        if(L>R) return 0;
        if(L<=l&&r<=R) return mx2[p];
        int mid=(l+r)>>1; int ret=mx[p];
        if(L<=mid) ret=max(ret, gmx(p<<1, l, mid, L, R));
        if(R>mid) ret=max(ret, gmx(p<<1|1, mid+1, r, L, R));
        return ret;
    }
    
}T1, T2;
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n); read(m);
    pw[0]=1;
    for(int i=1; i<=n+1; ++i) pw[i]=3ll*pw[i-1]%mod;
    for(int i=1; i<=n; ++i){
        read(a[i]); pre[i]=occ[a[i]]; suf[occ[a[i]]]=i;
        occ[a[i]]=i;
    }
    for(int i=1; i<=n; ++i) suf[occ[i]]=n+1;
    build(1, 1, n);
    for(int i=1, l, r; i<=m; ++i){
        read(l); read(r);
        qry[r].ep(l, i);
    }
    int mxl=1;
    for(int r=1; r<=n; ++r){
        // cout<<"rnd:"<<r<<endl;
        // cout<<"cur:"<<mxl<<endl;
        // for(int i=mxl; i<=pre[r]; ++i){
        //     int lst=0;
        //     while(top1&&a[stk1[top1]]<a[i]) {
        //         lst=a[stk1[top1]];
        //         --top1;
        //     }
        //     stk1[++top1]=i;
        // }
        
        T1.mdf(1, 1, n, 1, r, a[r]);
        for(int i=mxl; i<=pre[r]; ++i) T2.mdf(1, 1, n, 1, i, a[i]);
        
        // /*
        for(int i=mxl; i<=pre[r]; ++i){
            while(top1&&a[stk1[top1]]<a[i]) {
                if(stk1[top1]<mxl){
                    if(s1.find(stk1[top1])!=s1.end()){
                        s1.erase(s1.find(stk1[top1]));
                    }
                    if(s2.find(suf[stk1[top1]])!=s2.end()){
                        s2.erase(s2.find(suf[stk1[top1]]));
                    }
                }
                else{
                    --cnt[stk1[top1]];
                }
                --top1;
            }
            if(top1){
                w[stk1[top1]]=T1.gmx(1, 1, n, suf[stk1[top1]]+1, r)-T2.gmx(1, 1, n, stk1[top1]+1, pre[r]);
                if(w[stk1[top1]]<=0&&stk1[top1]<mxl){
                    if(s1.find(stk1[top1])!=s1.end()){
                        s1.erase(s1.find(stk1[top1]));
                        s2.insert(suf[stk1[top1]]);
                    }
                }
            }
            ++cnt[i];
            stk1[++top1]=i;
        }
        for(int i=mxl; i<=pre[r]; ++i) if(cnt[i]>0) {
            w[i]=T1.gmx(1, 1, n, suf[i]+1, r)-T2.gmx(1, 1, n, i+1, pre[r]);
            if(w[i]>0) s1.insert(i);
            else s2.insert(suf[i]); 
        }
        // */
        
        // while(top2&&a[stk2[top2]]<a[r]) {
        //     for(int j=stk2[top2-1]+1; j<=stk2[top2]; ++j){
        //         w[pre[j-1]]+=a[r]-a[stk2[top2]];
        //     }
        //     --top2;
        // }
        // w[pre[r-1]]+=a[r];
        // stk2[++top2]=r;
        
        // /*
        mxl=max(mxl, pre[r]+1);
        while(top2&&a[stk2[top2]]<a[r]) {
            set<int>::iterator it=s2.lower_bound(stk2[top2-1]);
            vector<int> vec;
            while(it!=s2.end()&&(*it)<stk2[top2]){
                w[pre[*it]]=T1.gmx(1, 1, n, suf[pre[*it]]+1, r)-T2.gmx(1, 1, n, pre[*it]+1, mxl-1);
                if(w[pre[*it]]>0){
                    vec.push_back(*it);
                    s1.insert(pre[*it]);
                }
                ++it;
            }
            for(auto t:vec) s2.erase(s2.find(t));
            --top2;
        }
        if(pre[r-1]){
            w[pre[r-1]]=T1.gmx(1, 1, n, suf[pre[r-1]]+1, r)-T2.gmx(1, 1, n, pre[r-1]+1, mxl-1);
            if(w[pre[r-1]]>0){
                if(s2.find(r-1)!=s2.end()){
                    s2.erase(s2.find(r-1));
                    s1.insert(pre[r-1]);
                }
            }
        }
        stk2[++top2]=r;
        // */
        
        // for(int i=1; i<=r; ++i) cout<<w[i]<<' ';
        // cout<<endl;
        
        
        for(auto [l, id]:qry[r]){
            if(l>=mxl){
                ans[id]=-1;
                continue;
            }
            int pos=stk1[top1];
            // for(int i=1; i<=top1; ++i) if(T1.gmx(1, 1, n, suf[stk1[i]]+1, r)-T2.gmx(1, 1, n, stk1[i]+1, mxl-1)>0&&stk1[i]>=l) {
            //     pos=stk1[i]; break;
            // }
            
            if(!s1.empty()&&s1.lower_bound(l)!=s1.end()){
                pos=*s1.lower_bound(l);
            }
            
            // cout<<pos<<endl;
            reths=0; retsz=0; bound=mapa(0, 0);
            ghs(1, 1, n, l, pos);
            int ret=reths, len=retsz;
            reths=0; retsz=0; bound=mapa(0, 0);
            if(suf[pos]+1<=r) ghs(1, 1, n, suf[pos]+1, r);
            ans[id]=((ll)reths*pw[len]+ret)%mod;
        }
    }
    
    for(int i=1; i<=m; ++i){
        printf("%d\n", ans[i]);
    }
	return 0;
}

