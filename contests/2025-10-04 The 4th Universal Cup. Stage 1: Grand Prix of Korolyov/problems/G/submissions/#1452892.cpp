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
int deg[N];
bool del[N], vis[N];
int p[N];
mt19937 rnd(time(0));
int q[N], hh, tt;
int calc(int st){
    q[hh=tt=1]=st;
    int ret=0;
    while(hh<=tt){
        int x=q[hh++];
        vis[x]=1;
        ++ret;
        for(auto y:e[x]){
            if(!(--deg[y])&&!del[y]&&y!=st){
                q[++tt]=y;
            }
        }
    }
    for(int i=1; i<=tt; ++i) {
        for(auto y:e[q[i]]) if(!del[y]) ++deg[y];
    }
    return ret;
}
void solve(){
    read(n); read(m);
    for(int i=1; i<=n; ++i) p[i]=i;
    shuffle(p+1, p+n+1, rnd);
    for(int i=1, x, y; i<=m; ++i){
        read(x); read(y);
        e[x].ep(y); ++deg[y];
    }
    int dlt=0;
    queue<int> que;
    for(int i=1; i<=n; ++i) if(!deg[i]){
        que.push(i);
    }
    while(!que.empty()){
        int x=que.front(); que.pop();
        ++dlt; del[x]=1;
        for(auto y:e[x]){
            if(!(--deg[y])){
                que.push(y);
            }
        }
    }
    int ans=0;
    for(int i=1; i<=n; ++i) if(!del[p[i]]&&!vis[p[i]]){
        ans=max(ans, calc(p[i]));
    }
    printf("%d\n", ans+dlt);
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	solve();
	return 0;
}

