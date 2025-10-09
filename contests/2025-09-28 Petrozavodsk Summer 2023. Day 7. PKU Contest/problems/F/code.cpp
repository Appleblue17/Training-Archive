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
const int N=2e6+5;
mt19937 rnd(1234);
inline int ran(int l, int r){
    return rnd()%(r-l+1)+l;
}
struct SA{
    int n;
    char s[N];
    int x[N], y[N], c[N], sa[N], ht[N], rk[N];
    void get_sa(){
        for(int i=1; i<=n; ++i) c[x[i]=s[i]]++;
        int m='z';
        for(int i=2; i<=m; ++i) c[i]+=c[i-1];
        for(int i=n; i; --i) sa[c[x[i]]--]=i;
        for(int k=1; k<=n; k<<=1){
            int num=0;
            for(int i=n-k+1; i<=n; ++i) y[++num]=i;
            for(int i=1; i<=n; ++i){
                if(sa[i]>k) y[++num]=sa[i]-k;
            }
            for(int i=1; i<=m; ++i) c[i]=0;
            for(int i=1; i<=n; ++i) c[x[i]]++;
            for(int i=2; i<=m; ++i) c[i]+=c[i-1];
            for(int i=n; i; --i) sa[c[x[y[i]]]--]=y[i], y[i]=0;
            swap(x, y);
            x[sa[1]]=1; num=1;
            for(int i=2; i<=n; ++i) 
            x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?num:++num;
            if(num==n) break;
            m=num;
        }
    }
    void get_ht(){
        for(int i=1; i<=n; ++i) rk[sa[i]]=i;
        for(int i=1, k=0; i<=n; ++i){
            if(rk[i]==1) continue;
            if(k) --k;
            int j=sa[rk[i]-1];
            while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) ++k;
            ht[rk[i]]=k;
        }
    }
    int st[N][22], lg[N];
    void build(){
        for(int i=2; i<=n; ++i) lg[i]=lg[i>>1]+1;
        for(int i=1; i<=n; ++i) st[i][0]=ht[i];
        for(int t=1; t<=lg[n]; ++t){
            for(int i=1; i+(1<<t)-1<=n; ++i){
                st[i][t]=min(st[i][t-1], st[i+(1<<(t-1))][t-1]);
            }
        }
    }
    int t;
    inline int lcp(int x, int y){
        if(x==y) return n-x+1;
        x=rk[x]; y=rk[y];
        if(x>y) swap(x, y);
        ++x;
        t=lg[y-x+1];
        return min(st[x][t], st[y-(1<<t)+1][t]);
    }
}S;
int lb[N], rb[N], len[N];
int n, m, q;
int pa[N], pb[N];
inline bool check(int a1, int b1, int a2, int b2){
    int lcp=S.lcp(lb[pa[a2]]+len[pa[a1]], lb[pb[b1]+n]);
    if(lcp<min(len[pa[a2]]-len[pa[a1]], len[pb[b1]+n])){
        return S.s[lb[pb[b1]+n]+lcp]<S.s[lb[pa[a2]]+len[pa[a1]]+lcp];
    }
    if(len[pb[b1]+n]<=len[pa[a2]]-len[pa[a1]]){
        return true;
    }
    int lcp2=S.lcp(lb[pb[b2]+n], lb[pb[b1]+n]+len[pa[a2]]-len[pa[a1]]);
    if(lcp2<min(len[pb[b2]+n], len[pb[b1]+n]-(len[pa[a2]]-len[pa[a1]]))){
        return S.s[lb[pb[b1]+n]+len[pa[a2]]-len[pa[a1]]+lcp2]<S.s[lb[pb[b2]+n]+lcp2];
    }
    if(len[pb[b2]+n]<len[pb[b1]+n]-(len[pa[a2]]-len[pa[a1]])){
        return false;
    }
    return true;
}
inline bool check2(int a1, int b1, int a2, int b2){
    int lcp=S.lcp(lb[pa[a2]]+len[pa[a1]], lb[pb[b1]+n]);
    if(lcp<min(len[pa[a2]]-len[pa[a1]], len[pb[b1]+n])){
        return S.s[lb[pb[b1]+n]+lcp]>S.s[lb[pa[a2]]+len[pa[a1]]+lcp];
    }
    if(len[pb[b1]+n]<=len[pa[a2]]-len[pa[a1]]){
        return false;
    }
    int lcp2=S.lcp(lb[pb[b2]+n], lb[pb[b1]+n]+len[pa[a2]]-len[pa[a1]]);
    if(lcp2<min(len[pb[b2]+n], len[pb[b1]+n]-(len[pa[a2]]-len[pa[a1]]))){
        return S.s[lb[pb[b1]+n]+len[pa[a2]]-len[pa[a1]]+lcp2]>S.s[lb[pb[b2]+n]+lcp2];
    }
    if(len[pb[b2]+n]>=len[pb[b1]+n]-(len[pa[a2]]-len[pa[a1]])){
        return false;
    }
    return true;
}
inline bool check3(int a1, int b1, int a2){
    int lcp=S.lcp(lb[pa[a2]]+len[pa[a1]], lb[pb[b1]+n]);
    if(lcp<min(len[pa[a2]]-len[pa[a1]], len[pb[b1]+n])){
        return S.s[lb[pb[b1]+n]+lcp]<S.s[lb[pa[a2]]+len[pa[a1]]+lcp];
    }
    if(len[pb[b1]+n]<len[pa[a2]]-len[pa[a1]]){
        return true;
    }
    return false;
}
pii calc(vector<int> id, vector<int> lp, vector<int> rp, ll goal){
    ll sum=0;
    for(int i=0; i<(int)id.size(); ++i){
        sum+=rp[i]-lp[i]+1;
    }
    if(sum==1){
        for(int i=0; i<(int)id.size(); ++i){
            return mapa(id[i], lp[i]);
        }
        return mapa(-1, -1);
    }
    int curid=ran(0, id.size()-1);
    int curpos=ran(lp[curid], rp[curid]);
    vector<int> lid, llp, lrp, rid, rlp, rrp;
    // cout<<"???"<<id[curid]<<' '<<curpos<<endl;
    ll suml=0;
    for(int i=0; i<curid; ++i){
        int L=lp[i], R=rp[i], mid, ret=lp[i]-1;
        while(L<=R){
            mid=(L+R)>>1;
            if(check(id[i], mid, id[curid], curpos)){
                ret=mid;
                L=mid+1;
            }
            else{
                R=mid-1;
            }
        }
        if(lp[i]<=ret){
            suml+=ret-lp[i]+1;
            lid.ep(id[i]);
            llp.ep(lp[i]);
            lrp.ep(ret);
        }
        if(ret+1<=rp[i]){
            rid.ep(id[i]);
            rlp.ep(ret+1);
            rrp.ep(rp[i]);
        }
        // cout<<"!!!"<<id[i]<<' '<<lp[i]<<' '<<rp[i]<<' '<<ret<<endl;
    }
    if(curpos!=lp[curid]){
        lid.ep(id[curid]);
        llp.ep(lp[curid]);
        lrp.ep(curpos-1);
        suml+=curpos-lp[curid];
    }
    if(curpos!=rp[curid]){
        rid.ep(id[curid]);
        rlp.ep(curpos+1);
        rrp.ep(rp[curid]);
    }
    for(int i=curid+1; i<(int)id.size(); ++i){
        int L=lp[i], R=rp[i], mid, ret=lp[i]-1;
        while(L<=R){
            mid=(L+R)>>1;
            if(check2(id[curid], curpos, id[i], mid)){
                ret=mid;
                L=mid+1;
            }
            else{
                R=mid-1;
            }
        }
        if(lp[i]<=ret){
            suml+=ret-lp[i]+1;
            lid.ep(id[i]);
            llp.ep(lp[i]);
            lrp.ep(ret);
        }
        if(ret+1<=rp[i]){
            rid.ep(id[i]);
            rlp.ep(ret+1);
            rrp.ep(rp[i]);
        }
        // cout<<"###"<<id[i]<<' '<<lp[i]<<' '<<rp[i]<<' '<<ret<<endl;
    }
    if(suml+1==goal){
        return mapa(id[curid], curpos);
    }
    if(goal<=suml){
        return calc(lid, llp, lrp, goal);
    }
    else{
        return calc(rid, rlp, rrp, goal-suml-1);
    }
}
inline bool cmp(int x, int y){
    int t=S.lcp(lb[x], lb[y]);
    if(t<min(len[x], len[y])){
        return S.s[lb[x]+t]<S.s[lb[y]+t];
    }
    return len[x]<len[y];
}
inline bool cmp2(int x, int y){
    int t=S.lcp(lb[x+n], lb[y+n]);
    if(t<min(len[x+n], len[y+n])){
        return S.s[lb[x+n]+t]<S.s[lb[y+n]+t];
    }
    return len[x+n]<len[y+n];
}
int pre[N];
ll crk[N];
const int p1=998244353, p2=993244853;
struct hsh{
	int x, y;
	inline hsh operator +(const hsh &t){
		return (hsh){(x+t.x)%p1, (y+t.y)%p2};
	}
	inline hsh operator *(const hsh &t){
		return (hsh){(int)((ll)x*t.x%p1), (int)((ll)y*t.y%p2)};
	}
    inline ll hs(){
        return 1000000000ll*x+y;
    }
}bs;
unordered_map<ll, int> h;
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    read(n); read(m);
    bs=(hsh){131, 13331};
    for(int i=1; i<=n+m; ++i){
        lb[i]=rb[i-1]+1;
        scanf("%s", S.s+lb[i]);
        len[i]=strlen(S.s+lb[i]);
        rb[i]=lb[i]+len[i]-1;
        S.n+=len[i];
    }
    S.get_sa();
    S.get_ht();
    S.build();
    for(int i=1; i<=n; ++i) pa[i]=i, crk[i]=1ll*m*(i-1)+1;
    sort(pa+1, pa+n+1, cmp);
    for(int i=1; i<=m; ++i) pb[i]=i;
    sort(pb+1, pb+m+1, cmp2);
    for(int i=1; i<=n; ++i){
        hsh cur=(hsh){0, 0};
        for(int j=lb[pa[i]]; j<=rb[pa[i]]; ++j){
            cur=cur*bs+(hsh){S.s[j], S.s[j]};
            if(h.find(cur.hs())!=h.end()){
                pre[i]=h[cur.hs()];
            }
        }
        h[cur.hs()]=i;
    }
    for(int i=1; i<=n; ++i) {
        int x=pre[i];
        while(x){
            int L=1, R=m, mid, ret=0;
            while(L<=R){
                mid=(L+R)>>1;
                if(check3(x, mid, i)){
                    ret=mid; L=mid+1;
                }
                else{
                    R=mid-1;
                }
            }
            crk[i]-=m-ret; 
            x=pre[x];
        }
        // cout<<i<<' '<<crk[i]<<endl;
    }
    // exit(0);
    read(q);
    ll k;
    while(q--){
        read(k);
        int id=n;
        for(int i=1; i<n; ++i){
            if(crk[i]<=k&&k<crk[i+1]){
                id=i;
            }
        }
        vector<int> vec, lvec, rvec;
        k-=1ll*m*id;
        do{
            vec.ep(id);
            lvec.ep(1);
            rvec.ep(m);
            k+=m;
            id=pre[id];
        }while(id!=0);
        // cout<<k<<endl;
        reverse(vec.begin(), vec.end());
        pii res=calc(vec, lvec, rvec, k);
        printf("%d %d\n", pa[res.fi], pb[res.se]);
    }
	return 0;
}

