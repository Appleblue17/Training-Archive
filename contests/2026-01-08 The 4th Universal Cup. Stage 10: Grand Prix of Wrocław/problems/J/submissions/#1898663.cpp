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
vector<int> e[N];
int col[N];
bool ins[N];
int num[5];
int cnt[N];
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n); read(m);
    for(int i=1, x, y; i<=m; ++i){
        read(x); read(y);
        e[x].ep(y); e[y].ep(x);
    }
    for(int i=1; i<=n; ++i) col[i]=1;
    set<int> st;
    for(int i=1; i<=n; ++i){
        for(auto j:e[i]) if(col[j]==col[i]) ++cnt[i];
        if(cnt[i]>=2) st.insert(i), ins[i]=1;
    }
    while(!st.empty()){
        int x=*st.begin(); st.erase(st.begin()); ins[x]=0;
        for(auto y:e[x]){
            if(col[x]==col[y]) --cnt[y];
        }
        for(int i=1; i<=4; ++i) num[i]=0;
        for(auto y:e[x]) num[col[y]]++;
        int mn=1e9, arg=0;
        for(int i=1; i<=4; ++i) if(num[i]<mn) {mn=num[i]; arg=i;}
        col[x]=arg; cnt[x]=mn;
        // cout<<x<<' '<<arg<<endl;
        for(auto y:e[x]){
            if(col[x]==col[y]) {
                ++cnt[y];
            }
            if(cnt[y]<=1&&ins[y]) st.erase(y), ins[y]=0;
            else if(cnt[y]>=2&&!ins[y]) st.insert(y), ins[y]=1;
        }
    }
    for(int i=1; i<=n; ++i) printf("%d ", col[i]);
	return 0;
}

