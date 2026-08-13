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
vector<int> e[N], g[N];
int d1[N], d2[N];
bool ins[N];
void solve(){
    read(n); 
    if(n==1){
        printf("YES\n");
        return ;
    }
    for(int i=1; i<=n; ++i) e[i].clear(), g[i].clear(), d1[i]=d2[i]=0, ins[i]=0;
    for(int i=1, x, y; i<n; ++i){
        read(x); read(y);
        ++d1[x]; ++d1[y];
        e[x].ep(y); e[y].ep(x);
    }
    for(int i=1, x, y; i<n; ++i){
        read(x); read(y);
        ++d2[x]; ++d2[y];
        g[x].ep(y); g[y].ep(x);
    }
    queue<int> que;
    int cnt=0;
    for(int i=1; i<=n; ++i){
        if(d1[i]==1&&d2[i]==1){
            que.push(i); ++cnt; ins[i]=1;
        }
    }
    while(!que.empty()){
        int x=que.front(); que.pop();
        for(auto y:e[x]){
            if(ins[y]) continue;
            --d1[y];
            if(d1[y]==1&&d2[y]==1){
                que.push(y); ins[y]=1; ++cnt;
            }
        }
        for(auto y:g[x]){
            if(ins[y]) continue;
            --d2[y];
            if(d1[y]==1&&d2[y]==1){
                que.push(y); ins[y]=1; ++cnt;
            }
        }
    }
    if(cnt==n){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
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