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
// const int B=2;
const int B=350;
int n, m, q;
ll a[N], b[N];
int pos[N], lp[N], rp[N];
using namespace __gnu_pbds;
using les = less <ll>;
using ntp = null_type;
tree <ll, ntp, les, rb_tree_tag, tree_order_statistics_node_update> st;
ll sum[355][355]; int tag[355];
deque<ll> dq[355];
void rebuild(int id){
    tag[id]=0;
    if(m<=B){
        for(int i=0; i<m; ++i){
            sum[id][i]=0;
        }
        for(int i=lp[id]; i<=rp[id]; ++i){
            sum[id][i%m]+=dq[id][i-lp[id]]>>20ll;
        }
    }
}
int main(){
    // freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
    // freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
    read(n); read(m); read(q);
    for(int i=1; i<=n; ++i){
        read(a[i]); pos[i]=(i+B-1)/B;
        a[i]=(a[i]<<20ll)+i;
        st.insert(a[i]);
        b[i]=a[i];
    }
    for(int i=1; i<=pos[n]; ++i) {
        lp[i]=rp[i-1]+1; rp[i]=rp[i-1]+B;
    }
    rp[pos[n]]=n;
    sort(b+1, b+n+1);
    for(int i=1; i<=pos[n]; ++i){
        for(int j=lp[i]; j<=rp[i]; ++j){
            dq[i].push_back(b[j]);
        }
        rebuild(i);
    }
    ll x, y, z, ans=0;
    while(q--){
        read(x); read(y); read(z);
        x=1+(x+ans)%n; y=1+(y+ans)%inf; z=1+(z+ans)%n;
        ans=0;
        y=(y<<20ll)+x;
        int p1=st.order_of_key(a[x])+1;
        st.erase(a[x]);
        st.insert(y);
        int p2=st.order_of_key(y)+1;
        if(pos[p1]==pos[p2]){
            deque<ll> tem;
            for(auto t:dq[pos[p1]]){
                if(t==a[x]) continue;
                tem.push_back(t);
            }
            dq[pos[p1]].clear();
            bool ins=0;
            for(auto t:tem){
                if(t>y&&!ins){
                    dq[pos[p1]].push_back(y);
                    ins=1;
                }
                dq[pos[p1]].push_back(t);
            }
            if(!ins) dq[pos[p1]].push_back(y);
            rebuild(pos[p1]);
        }
        else if(p1<p2){
            deque<ll> tem;
            for(auto t:dq[pos[p1]]){
                if(t==a[x]) continue;
                tem.push_back(t);
            }
            dq[pos[p1]]=tem;
            dq[pos[p1]].push_back(dq[pos[p1]+1].front());
            rebuild(pos[p1]);
            for(int i=pos[p1]+1; i<pos[p2]; ++i){
                if(m<=B) sum[i][(lp[i]-tag[i]%m+m)%m]-=dq[i].front()>>20ll;
                dq[i].pop_front();
                --tag[i];
                dq[i].push_back(dq[i+1].front());
                if(m<=B) sum[i][(rp[i]-tag[i]%m+m)%m]+=dq[i].back()>>20ll;
            }
            dq[pos[p2]].pop_front();
            tem.clear();
            bool ins=0;
            for(auto t:dq[pos[p2]]){
                if(t>y&&!ins){
                    tem.push_back(y);
                    ins=1;
                }
                tem.push_back(t);
            }
            dq[pos[p2]]=tem;
            if(!ins) dq[pos[p2]].push_back(y);
            rebuild(pos[p2]);
        }
        else{
            deque<ll> tem;
            for(auto t:dq[pos[p1]]){
                if(t==a[x]) continue;
                tem.push_back(t);
            }
            dq[pos[p1]]=tem;
            dq[pos[p1]].push_front(dq[pos[p1]-1].back());
            rebuild(pos[p1]);
            for(int i=pos[p1]-1; i>pos[p2]; --i){
                if(m<=B) sum[i][(rp[i]-tag[i]%m+m)%m]-=dq[i].back()>>20ll;
                dq[i].pop_back();
                ++tag[i];
                dq[i].push_front(dq[i-1].back());
                if(m<=B) sum[i][(lp[i]-tag[i]%m+m)%m]+=dq[i].front()>>20ll;
            }
            dq[pos[p2]].pop_back();
            tem.clear();
            bool ins=0;
            for(auto t:dq[pos[p2]]){
                if(t>y&&!ins){
                    tem.push_back(y);
                    ins=1;
                }
                tem.push_back(t);
            }
            dq[pos[p2]]=tem;
            if(!ins) dq[pos[p2]].push_back(y);
            rebuild(pos[p2]);
        }
        a[x]=y;
        if(m<=B){
            for(int i=z; i>=lp[pos[z]]; --i){
                if(i%m==z%m) ans+=dq[pos[z]][i-lp[pos[z]]]>>20ll;
            }
            for(int i=pos[z]-1; i>=1; --i){
                ans+=sum[i][(z+m-tag[i]%m)%m];
            }
        }
        else{
            while(z>=1){
                ans+=dq[pos[z]][z-lp[pos[z]]]>>20ll;
                z-=m;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
