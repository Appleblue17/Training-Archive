#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
typedef long long ll;
int T, n;
int a[N];
int mx[N<<2], len[N<<2];
int push_up(int p, int l, int r, int v){
    if(v>=mx[p]) return 0;
    if(l==r){
        return 1;
    }
    int mid=(l+r)>>1;
    if(v<mx[p<<1]){
        return push_up(p<<1, l, mid, v)+len[p]-len[p<<1];
    }
    else{
        return push_up(p<<1|1, mid+1, r, v);
    }
}
void build(int p, int l, int r){
    if(l==r){
        mx[p]=a[l]; len[p]=1;
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    mx[p]=max(mx[p<<1], mx[p<<1|1]);
    len[p]=len[p<<1]+push_up(p<<1|1, mid+1, r, mx[p<<1]);
}
int get(int p, int l, int r, int L, int R, int &v){
    if(v>=mx[p]) return 0;
    if(L<=l&&r<=R){
        int ret=push_up(p, l, r, v);
        v=max(v, mx[p]);
        return ret;
    }
    int mid=(l+r)>>1, ret=0;
    if(L<=mid) ret+=get(p<<1, l, mid, L, R, v);
    if(R>mid) ret+=get(p<<1|1, mid+1, r, L, R, v);
    return ret;
}
int ans[N];
int pre[N], suf[N], val[N];
struct node{
    int l, r, v;
    bool operator <(const node &t)const{
        if(v!=t.v) return v>t.v;
        return l<t.l;
    }
};
int calc(int l1, int r1, int l2, int r2){
    int tem=0, ret=0;
    ret-=get(1, 1, n, l1, r1, tem);
    tem=0;
    ret-=get(1, 1, n, l2, r2, tem);
    tem=0;
    ret+=get(1, 1, n, l1, r2, tem);
    return ret;
}
void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    if(n==1){
        printf("1\n");
        return ;
    }
    build(1, 1, n);
    ans[n]=n;
    for(int i=1; i<=n; ++i) pre[i]=i, suf[i]=i;
    set<node> st;
    for(int i=1; i<n; ++i){
        val[i]=calc(i, i, i+1, i+1);
        st.insert((node){i, i, val[i]});
    }
    for(int i=n-1; i>=1; --i){
        node cur=*st.begin();
        // cout<<"in3"<<endl;
        ans[i]=ans[i+1]+cur.v;
        st.erase(st.begin());
        int l1=cur.l, r1=cur.r, l2=r1+1, r2=suf[l2];
        // cout<<"out3"<<endl;
        // cout<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<endl;
        if(r2!=n) st.erase(st.find((node){l2, r2, val[l2]}));
        pre[r2]=l1; suf[l1]=r2;
        if(l1!=1){
            // cout<<"in1"<<endl;
            int r3=l1-1, l3=pre[r3];
            st.erase(st.find((node){l3, r3, val[l3]}));
            val[l3]=calc(l3, r3, l1, r2);
            st.insert((node){l3, r3, val[l3]});
            // cout<<"out1"<<endl;
        }
        if(r2!=n){
            // cout<<"in2"<<endl;
            int l3=r2+1, r3=suf[l3];
            val[l1]=calc(l1, r2, l3, r3);
            st.insert((node){l1, r2, val[l1]});
            // cout<<"out2"<<endl;
        }
    }
    for(int i=1; i<=n; ++i) printf("%d ", ans[i]);
    putchar('\n');
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
