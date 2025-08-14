#pragma GCC optimize(2)
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
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
const int N=1e5+5, inf=1e9;
int T, n, m, q;
ll a[N];
namespace task1{
    using namespace __gnu_pbds;
    using les = less <ll>;
    using ntp = null_type;
    tree <ll, ntp, les, rb_tree_tag, tree_order_statistics_node_update> tr[350], trall;
    int rk[N], id[N], sz[350];
    void solve(){
        for(int i=1; i<=n; ++i) a[i]=(a[i]<<31ll)+i;
        for(int i=1; i<=n; ++i) rk[i]=i;
        sort(rk+1, rk+n+1, [&](int x, int y){return a[x]<a[y];});
        for(int i=1; i<=n; ++i){
            id[i]=(i+m-1)/m; sz[id[i]]++;
            tr[id[i]].insert(a[rk[i]]);
            trall.insert(a[rk[i]]);
        }
        ll x, y, z; ll lstans=0;
        while(q--){
            read(x); read(y); read(z);
            x=1+(x+lstans)%n; y=1+(y+lstans)%inf;z=1+(z+lstans)%n;
            int pos1=trall.order_of_key(a[x])+1;
            trall.erase(a[x]);
            y=(y<<31ll)+x;
            trall.insert(y);
            int pos2=trall.order_of_key(y)+1;
            if(id[pos1]==id[pos2]){
                tr[id[pos1]].erase(a[x]);
                tr[id[pos1]].insert(y);
                a[x]=y;
            }
            else if(pos1<pos2){
                tr[id[pos1]].erase(a[x]);
                ll tem;
                for(int i=id[pos1]+1; i<=id[pos2]; ++i) {
                    tem=*tr[i].find_by_order(0);
                    tr[i-1].insert(tem);
                    tr[i].erase(tem);
                }
                tr[id[pos2]].insert(y);
                a[x]=y;
            }
            else{
                tr[id[pos1]].erase(a[x]);
                ll tem;
                for(int i=id[pos1]-1; i>=id[pos2]; --i) {
                    tem=*tr[i].find_by_order(sz[i]-1);
                    tr[i+1].insert(tem);
                    tr[i].erase(tem);
                }
                tr[id[pos2]].insert(y);
                a[x]=y;
            }
            lstans=0;
            for(int i=1; i<=id[z]; ++i) lstans+=(*tr[i].find_by_order((z-1)%m))>>31ll;
            printf("%lld\n", lstans);
        }
    }
}
namespace task2{
    using namespace __gnu_pbds;
    using les = less <ll>;
    using ntp = null_type;
    tree <ll, ntp, les, rb_tree_tag, tree_order_statistics_node_update> trall;
    int rk[N];
    mt19937 rnd(100000193);
    struct node{
        int ls, rs;
        int siz, pri;
        ll val; __int128 sum;
    }tr[N];
    int rt[N];
    int idx;
    void push_up(int rt){
        tr[rt].siz=1+tr[tr[rt].ls].siz+tr[tr[rt].rs].siz;
        tr[rt].sum=tr[rt].val+tr[tr[rt].ls].sum+tr[tr[rt].rs].sum;
        return ;
    }
    int Merge(int x, int y){
        if(x==0||y==0) return x+y;
        if(tr[x].pri<tr[y].pri){
            tr[x].rs=Merge(tr[x].rs, y);
            push_up(x);
            return x;
        }
        tr[y].ls=Merge(x, tr[y].ls);
        push_up(y);
        return y;
    }
    void Split(int rt, ll v, int &x, int &y){
        if(rt==0){
            x=y=0;
            return ;
        }
        if(tr[rt].val<=v){
            x=rt;
            Split(tr[rt].rs, v, tr[x].rs, y);
            push_up(x);
        }
        else{
            y=rt;
            Split(tr[rt].ls, v, x, tr[y].ls);
            push_up(y);
        }
    }
    ll getk(int x, int k){
        if(tr[tr[x].ls].siz>=k){
            return getk(tr[x].ls, k);
        }
        ll ret=(tr[tr[x].ls].sum+tr[x].val)>>31ll;
        k-=tr[tr[x].ls].siz+1;
        if(k!=0) ret+=getk(tr[x].rs, k);
        return ret;
    }
    int crt[N][3];
    void solve(){
        for(int i=1; i<=n; ++i) a[i]=(a[i]<<31ll)+i;
        for(int i=1; i<=n; ++i) rk[i]=i;
        sort(rk+1, rk+n+1, [&](int x, int y){return a[x]<a[y];});
        for(int i=1; i<=n; ++i){
            ++idx;
            tr[idx].val=tr[idx].sum=a[rk[i]]; tr[idx].pri=rnd();
            rt[(i-1)%m]=Merge(rt[(i-1)%m], idx);
            trall.insert(a[rk[i]]);
        }
        ll x, y, z; ll lstans=0;
        for(int o=n+1; o<=n+q; ++o){
            read(x); read(y); read(z);
            x=1+(x+lstans)%n; y=1+(y+lstans)%inf;z=1+(z+lstans)%n;
            if(a[x]==y){
                lstans=getk(rt[(z-1)%m], (z+m-1)/m);
                printf("%lld\n", lstans);
                continue;
            }
            int pos1=trall.order_of_key(a[x])+1;
            trall.erase(a[x]);
            y=(y<<31ll)+o;
            trall.insert(y);
            int pos2=trall.order_of_key(y)+1;
            int rt1, rt2, rt3, rt4;
            Split(rt[(pos1-1)%m], a[x]-1, rt1, rt2);
            Split(rt2, a[x], rt3, rt4);
            rt[(pos1-1)%m]=Merge(rt1, rt4);
            tr[rt3].val=tr[rt3].sum=y; tr[rt3].pri=rnd();
            int memrt3=rt3;
            if(a[x]<y){
                for(int i=0; i<m; ++i){
                    Split(rt[i], a[x], rt1, rt2);
                    Split(rt2, y, rt3, rt4);
                    crt[i][0]=rt1; crt[i][1]=rt4; crt[i][2]=rt3;
                }
                for(int i=0; i<m; ++i){
                    rt[i]=Merge(Merge(crt[i][0], crt[(i+1)%m][2]), crt[i][1]);
                }
            }
            else{
                for(int i=0; i<m; ++i){
                    Split(rt[i], y, rt1, rt2);
                    Split(rt2, a[x], rt3, rt4);
                    crt[i][0]=rt1; crt[i][1]=rt4; crt[i][2]=rt3;
                }
                for(int i=0; i<m; ++i){
                    rt[i]=Merge(Merge(crt[i][0], crt[(i+m-1)%m][2]), crt[i][1]);
                }
            }
            Split(rt[(pos2-1)%m], y, rt1, rt2);
            rt[(pos2-1)%m]=Merge(Merge(rt1, memrt3), rt2);
            a[x]=y;
            lstans=getk(rt[(z-1)%m], (z+m-1)/m);
            printf("%lld\n", lstans);
        }
    }
}
int main(){
    // freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
    // freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
    read(n); read(m); read(q);
    for(int i=1; i<=n; ++i){
        read(a[i]);
    }
    if(m>=400){
        task1::solve();
    }
    else{
        task2::solve();
    }
     
    return 0;
}
