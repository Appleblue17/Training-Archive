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
const int N=1e6+5;
int Test, n, m, q;
unordered_map<int, int> id[2];
// 0: +1 -1  1: +1 +1
int fa[N];
int get(int x){
    if(x==fa[x]) return x;
    return fa[x]=get(fa[x]);
}
void merge(int x, int y){
    x=get(x); y=get(y);
    if(x==y) return ;
    fa[x]=y;
}
vector<int> b0[N], b1[N];
int cnt[N];
bool ins[N];
ll ans;
struct fenwick{
    int tr[N];
    void clr(){
        for(int i=1; i<=(n+m)*2; ++i) tr[i]=0;
    }
    void add(int x, int v){
        for(; x<=(n+m)*2; x+=(x&-x)) tr[x]+=v;
    }
    int get(int l, int r){
        int ret=0;
        for(; r; r-=(r&-r)) ret+=tr[r];
        for(--l; l; l-=(l&-l)) ret-=tr[l];
        return ret;
    }
}T[2][2];
void solve(){
    read(n); read(m); read(q);
    id[0].clear(); id[1].clear(); 
    for(int i=1; i<=n; ++i){
        id[0][i+1]=i+1; cnt[i+1]=min(i, m);
    }
    for(int i=2; i<=m; ++i){
        id[0][i+n]=i+n; cnt[i+n]=min(n, m-i+1);
    }
    for(int i=1; i<=n; ++i){
        id[1][i-1]=i-1+m+n+m; cnt[i-1+m+n+m]=min(n-i+1, m);
    }
    for(int i=2; i<=m; ++i){
        id[1][1-i]=1-i+m+n+m; cnt[1-i+m+n+m]=min(n, m-i+1);
    }
    for(int i=2; i<=2*m+2*n-1; ++i) {
        fa[i]=i, b0[i].clear(), b1[i].clear();
        ins[i]=0;
    }
    // for(int i=2; i<=2*m+2*n-1; ++i){
    //     cout<<cnt[i]<<' ';
    // }
    // exit(0);
    for(int i=1; i<=n; ++i){
        merge(id[0][i+1], id[1][i-1]);
    }
    for(int i=2; i<=n; ++i){
        merge(id[0][i+m], id[1][i-m]);
    }
    for(int i=1; i<=m; ++i){
        merge(id[0][i+1], id[1][1-i]);
    }
    for(int i=1; i<=m; ++i){
        merge(id[0][i+n], id[1][n-i]);
    }
    for(int i=2; i<=n+m; ++i){
        b0[get(i)].push_back(i);
    }
    for(int i=n+m+1; i<=2*m+2*n-1; ++i){
        b1[get(i)].push_back(i);
    }
    // for(int i=2; i<=2*m+2*n-1; ++i) if(i==get(i)){
    //     cout<<"group:"<<endl;
    //     for(auto t:b0[i]) cout<<t<<' '; cout<<endl;
    //     for(auto t:b1[i]) cout<<t<<' '; cout<<endl;
    // }
    int x, y, vx, vy;
    ans=0;
    T[0][0].clr(); T[0][1].clr(); T[1][0].clr(); T[1][1].clr(); 
    while(q--){
        read(x); read(y); read(vx); read(vy);
        if(vx<0) vy=-vy;
        int o=0, cid=x+y;
        if(vy==1) o=1;
        if(o==1) cid=x-y+m+n+m;
        cid=get(cid);
        if(ins[cid]) {
            printf("%lld ", ans);
            continue;
        }
        ins[cid]=1;
        for(auto t:b0[cid]){
            ans+=cnt[t];
            T[0][t&1].add(t, 1);
            int lx, ly;
            if(t>m) lx=t-m, ly=m;
            else lx=1, ly=t-1;
            int rx, ry;
            if(t>n) rx=n, ry=t-n;
            else rx=t-1, ry=1;
            ans-=T[1][id[1][lx-ly]&1].get(id[1][lx-ly], id[1][rx-ry]);
            // cout<<lx<<' '<<ly<<' '<<rx<<' '<<ry<<endl;
            // cout<<t<<' '<<cnt[t]-T[1][id[1][lx-ly]&1].get(id[1][lx-ly], id[1][rx-ry]);
            // cout<<endl;
        }
        
        for(auto t:b1[cid]){
            ans+=cnt[t];
            T[1][t&1].add(t, 1);
            t-=m+n+m;
            int lx, ly;
            if(1+t<=n&&1+t>=1) lx=1+t, ly=1;
            else lx=1, ly=1-t;
            int rx, ry;
            if(n-t<=m&&n-t>=1) rx=n, ry=n-t;
            else rx=m+t, ry=m;
            ans-=T[0][id[0][lx+ly]&1].get(id[0][lx+ly], id[0][rx+ry]);
            // cout<<lx<<' '<<ly<<' '<<rx<<' '<<ry<<endl;
            // cout<<t+m*2+n<<' '<<cnt[t+m*2+n]<<' '<<T[0][id[0][lx+ly]&1].get(id[0][lx+ly], id[0][rx+ry]);
            // cout<<endl;
        }
        // cout<<"----------------"<<endl;
        printf("%lld ", ans);
    }
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(Test);
	while(Test--){
		solve();
	}
	return 0;
}