#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=3e6+5;
int n, q,a[N],b[N];

int lis[N], len;
int qx[N], qy[N], qv[N];
struct tree{
    int tr[N<<2], mx[N<<2];
    multiset<int> bin[N];
    void up(int p){
        tr[p]=tr[p<<1]+tr[p<<1|1];
        mx[p]=max(mx[p<<1], mx[p<<1|1]);
    }
    void mdf(int p, int l, int r, int x, int v1, int v2){
        if(l==r){
            tr[p]+=v1;
            bin[l].insert(v2);
            mx[p]=*bin[l].rbegin();
            return ;
        }
        int mid=(l+r)>>1;
        if(x<=mid) mdf(p<<1, l, mid, x, v1, v2);
        else mdf(p<<1|1, mid+1, r, x, v1, v2);
        up(p);
    }
    void del(int p, int l, int r, int x, int v1, int v2){
        if(l==r){
            tr[p]-=v1;
            bin[l].erase(bin[l].find(v2));
            mx[p]=*bin[l].rbegin();
            return ;
        }
        int mid=(l+r)>>1;
        if(x<=mid) del(p<<1, l, mid, x, v1, v2);
        else del(p<<1|1, mid+1, r, x, v1, v2);
        up(p);
    }
    int get(int p, int l, int r, int L, int R){
        // cout<<p<<' '<<l<<' '<<r<<' '<<L<<' '<<R<<endl;
        if(L>R) return 0;
        if(L<=l&&r<=R){
            return tr[p];
        }
        int mid=(l+r)>>1, ret=0;
        if(L<=mid) ret=get(p<<1, l, mid, L, R);
        if(R>mid) ret+=get(p<<1|1, mid+1, r, L, R);
        return ret;
    }
    int get2(int p, int l, int r, int L, int R){
        if(L>R) return 0;
        if(L<=l&&r<=R){
            return mx[p];
        }
        int mid=(l+r)>>1, ret=0;
        if(L<=mid) ret=get2(p<<1, l, mid, L, R);
        if(R>mid) ret=max(ret, get2(p<<1|1, mid+1, r, L, R));
        return ret;
    }
}t1;
struct tree2{
    int tag[N<<2], mn[N<<2];
    void apply(int p, int v){
        tag[p]+=v; mn[p]+=v;
    }
    void down(int p){
        if(tag[p]!=0){
            apply(p<<1, tag[p]);
            apply(p<<1|1, tag[p]);
            tag[p]=0;
        }
    }
    void up(int p){
        mn[p]=min(mn[p<<1], mn[p<<1|1]);
    }
    void add(int p, int l, int r, int L, int R, int v){
        if(L>R) return ;
        if(L<=l&&r<=R){
            apply(p, v);
            return ;
        }
        int mid=(l+r)>>1;
        down(p);
        if(L<=mid) add(p<<1, l, mid, L, R, v);
        if(R>mid) add(p<<1|1, mid+1, r, L, R, v);
        up(p);
    }
    int qry(int p, int l, int r){
        if(l==r){
            return l;
        }
        down(p);
        int mid=(l+r)>>1;
        if(mn[p<<1|1]==0) return qry(p<<1|1, mid+1, r);
        return qry(p<<1, l, mid);
    }
}t2;
multiset<int> st;
void calc(){
    int mxa=*st.rbegin();
    int c=t1.get(1, 1, len, mxa+1, len);
    int mxa2=t1.get2(1, 1, len, mxa+1, len);
    
    t2.add(1, 1, len, mxa+1, len, 1);
    // cout<<"+"<<mxa<<' '<<len<<endl;
    int w=t2.qry(1, 1, len);
    t2.add(1, 1, len, mxa+1, len, -1);
    // cout<<w<<' '<<mxa2<<endl;
    if(mxa2>=w){
        printf("%d\n", c);
    }
    else{
        printf("%d\n", c+1);
    }
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
        lis[++len]=a[i];
        lis[++len]=b[i]; 
        lis[++len]=b[i]+1; 
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d%d",&qv[i],&qx[i],&qy[i]);
        lis[++len]=qx[i];
        lis[++len]=qy[i];
        lis[++len]=qy[i]+1;
    }
    sort(lis+1, lis+len+1);
    len=unique(lis+1, lis+len+1)-lis-1;
    // for(int i=1; i<=len; ++i) cout<<i<<' '<<lis[i]<<endl;
    for(int i=1; i<=len; ++i) t1.bin[i].insert(0);
    for(int i=1; i<=n; ++i){
        a[i]=lower_bound(lis+1, lis+len+1, a[i])-lis;
        b[i]=lower_bound(lis+1, lis+len+1, b[i])-lis;
    }
    for(int i=1; i<=q; ++i){
        qx[i]=lower_bound(lis+1, lis+len+1, qx[i])-lis;
        qy[i]=lower_bound(lis+1, lis+len+1, qy[i])-lis;
    }
    for(int i=1; i<=n; ++i){
        st.insert(a[i]);
        t1.mdf(1, 1, len, b[i], 1, a[i]);
        if(a[i]>b[i]) t2.add(1, 1, len, b[i]+1, a[i], 1)/*, cout<<"+"<<b[i]+1<<' '<<a[i]<<endl*/;
    }
    calc();
    for(int i=1; i<=q; ++i){
        int v, x, y; v=qv[i]; x=qx[i]; y=qy[i];
        st.erase(st.find(a[v]));
        t1.del(1, 1, len, b[v], 1, a[v]);
        if(a[v]>b[v]) t2.add(1, 1, len, b[v]+1, a[v], -1);
        a[v]=x; b[v]=y;
        st.insert(a[v]);
        t1.mdf(1, 1, len, b[v], 1, a[v]);
        
        if(a[v]>b[v]) t2.add(1, 1, len, b[v]+1, a[v], 1);
        calc();
    }
}
