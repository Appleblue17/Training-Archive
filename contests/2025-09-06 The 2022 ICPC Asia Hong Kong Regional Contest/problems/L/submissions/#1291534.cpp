#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n, m, k;
int a[N], b[N], rk[N];
multiset<int> st;
int val[N];
int mx[N<<2], cnt[N<<2];
vector<int> vec;
void up(int p){
    mx[p]=max(mx[p<<1], mx[p<<1|1]);
    cnt[p]=cnt[p<<1]+cnt[p<<1|1];
}
void build(int p, int l, int r){
    if(l==r){
        if(!val[l]){
            cnt[p]=0;
            mx[p]=0;
            vec.push_back(l);
        }
        else{
            cnt[p]=1;
            mx[p]=a[l];
        }
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    up(p);
}
bool flg=0;
int get1(int p, int l, int r, int L, int R, int lim){
    if(L<=l&&r<=R){
        if(mx[p]<=lim) return cnt[p];
        if(l==r) {
            flg=1; return 0;
        }
        int mid=(l+r)>>1;
        if(mx[p<<1|1]>lim) return get1(p<<1|1, mid+1, r, L, R, lim);
        else return cnt[p<<1|1]+get1(p<<1, l, mid, L, R, lim);
    }
    int mid=(l+r)>>1, ret=0;
    if(R>mid) ret+=get1(p<<1|1, mid+1, r, L, R, lim);
    if(L<=mid&&!flg) ret+=get1(p<<1, l, mid, L, R, lim);
    return ret;
}
int get2(int p, int l, int r, int L, int R, int lim){
    if(L<=l&&r<=R){
        if(mx[p]<=lim) return cnt[p];
        if(l==r) {
            flg=1; return 0;
        }
        int mid=(l+r)>>1;
        if(mx[p<<1]>lim) return get2(p<<1, l, mid, L, R, lim);
        else return cnt[p<<1]+get2(p<<1|1, mid+1, r, L, R, lim);
    }
    int mid=(l+r)>>1, ret=0;
    if(L<=mid) ret+=get2(p<<1, l, mid, L, R, lim);
    if(R>mid&&!flg) ret+=get2(p<<1|1, mid+1, r, L, R, lim);
    return ret;
}
void mdf(int p, int l, int r, int x){
    if(l==r){
        cnt[p]=1;
        mx[p]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) mdf(p<<1, l, mid, x);
    else mdf(p<<1|1, mid+1, r, x);
    up(p);
}
void solve(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]); rk[a[i]]=i;
        val[i]=0;
    }
    for(int i=1; i<=m; ++i){
        scanf("%d", &b[i]);
        val[rk[b[i]]]=1;
    }
    st.clear();
    for(int i=1, l; i<=k; ++i) {
        scanf("%d", &l);
        st.insert(-l);
    }
    for(int i=2; i<=m; ++i){
        if(rk[b[i]]<rk[b[i-1]]){
            printf("NO\n");
            return ;
        }
    }
    if(m+k<n){
        printf("NO\n");
        return ;
    }
    vec.clear();
    build(1, 1, n);
    sort(vec.begin(), vec.end(), [&](int x, int y){return a[x]<a[y];});
    for(auto t:vec){
        flg=0;
        int cnt1=get1(1, 1, n, 1, t, a[t]);
        flg=0;
        int cnt2=get2(1, 1, n, t, n, a[t]);
        int sum=cnt1+cnt2+1;
        // cout<<t<<' '<<cnt1<<' '<<cnt2<<endl;
        multiset<int>::iterator it=st.lower_bound(-sum);
        if(it==st.end()){
            printf("NO\n");
            return ;
        }
        st.erase(it);
        mdf(1, 1, n, t);
    }
    printf("YES\n");
}

signed main(){
    scanf("%d",&T);
    while(T--){
        solve();
    }
}
