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
int T, n, m;
pii a[N], b[N];
void solve2(){
    printf("%d\n", n+1);
    set<pii> st;
    vector<pii> vec;
    for(int i=n; i>=1; --i){
        if(st.empty()) st.insert(mapa(a[i].se, i));
        else{
            set<pii>::iterator it=st.lower_bound(mapa(a[i].se, 0));
            if(it==st.end()){
                st.insert(mapa(a[i].se, i));
            }
            else {
                vec.ep(a[i].se, a[(*it).se].fi);
                st.erase(it);
            }
        }
    }
    m=st.size();
    for(int i=1; !st.empty(); ++i){
        b[i]=a[(*st.begin()).se];
        st.erase(st.begin());
    }
    printf("%d\n", (int)vec.size()+1);
    printf("%d ", m+1);
    printf("%d ", b[1].se);
    for(int i=1; i<=m; ++i){
        if(i&1) printf("%d ", b[i].fi);
        else printf("%d ", b[i].se);    
    }
    putchar('\n');
    for(auto t:vec){
        printf("2 %d %d\n", t.fi, t.se);
    }
}
int mn[N], mx[N], rev[N];
bool vis[N];
bool check(){
    mn[0]=n+1;
    for(int i=1; i<=n; ++i){
        mn[i]=min(mn[i-1], a[i].se);
        if((i&1)&&mn[i]==n-i+1) return false;
        rev[a[i].se]=i;
    }
    mx[n+1]=0;
    for(int i=n; i>=1; --i) mx[i]=max(mx[i+1], rev[i]), vis[i]=0;
    return true;
}
void solve1(){
    printf("%d\n", n);
    vector<vector<int> > ans;
    for(int l=1; l<=n;){
        int it=l;
        vector<int> tem;
        tem.push_back(a[it].se); vis[it]=1;
        while(true){
            it=mx[a[it].se];
            tem.ep(it+n); vis[it]=1;
            if(mn[it]==n-it+1) break;
            it=rev[mn[it]]; 
            tem.ep(a[it].se); vis[it]=1;
        }
        int lst=0;
        for(int i=it; i>=l; --i) if(!vis[i]){
            if(lst==0) lst=i;
            else{
                if(a[i].se<a[lst].se) tem.ep(a[i].se), tem.ep(lst+n);
                else tem.ep(a[lst].se), tem.ep(i+n);
                lst=0;
            }
        }
        ans.ep(tem);
        l=it+1;
    }
    printf("%d\n", (int)ans.size());
    for(auto t:ans){
        printf("%d ", (int)t.size());
        for(auto x:t) printf("%d ", x);
        putchar('\n');
    }
}
void solve(){
    read(n);
    for(int i=1; i<=n; ++i) read(a[i].fi), read(a[i].se);
    sort(a+1, a+n+1);
    if(check()) solve1();
    else solve2();
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(T);
	while(T--){
		solve();
	}
	return 0;
}

