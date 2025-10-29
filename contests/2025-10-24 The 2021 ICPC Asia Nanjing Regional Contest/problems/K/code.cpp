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
typedef __int128 lint;
void write(lint x){
    if(x<10) {
        putchar('0'+x);
        return ;
    }
    write(x/10);
    putchar('0'+x%10);
}
const int N=1e6+5;
int T, n, m;
vector<int> e[N];
lint sum[10];
namespace task2{
    int deg[N];
    void solve(){
        for(int i=1; i<=n; ++i){
            deg[i]=e[i].size();
        }
        for(int i=1; i<=n; ++i){
            for(auto j:e[i]) if(i<j){
                int r=deg[i]+deg[j]-1;
                sum[2]+=m-r;
            }
        }
        sum[2]/=2;
        for(int i=1; i<=n; ++i){
            for(auto j:e[i]) if(i<j){
                sum[2]+=1ll*(n-3)*(deg[i]+deg[j]-2);
                --deg[i]; --deg[j];
            }
        }
    }
}
namespace task3{
    int deg[N];
    vector<int> g[N];
    bool ins[N];
    void solve(){
        for(int i=1; i<=n; ++i){
            deg[i]=e[i].size();
        }
        for(int i=1; i<=n; ++i){
            for(auto j:e[i]) if(i<j){
                sum[3]+=1ll*(deg[i]-1)*(deg[j]-1);
                if(deg[i]<deg[j]) g[i].ep(j);
                else g[j].ep(i);
            }
        }
        for(int i=1; i<=n; ++i){
            sum[3]+=1ll*deg[i]*(deg[i]-1)*(deg[i]-2)/6;
        }
        for(int u=1; u<=n; ++u){
            for(auto v:g[u]) ins[v]=1;
            for(auto v:g[u]){
                for(auto w:g[v]){
                    if(ins[w]) sum[3]+=n-3-3;
                }
            }
            for(auto v:g[u]) ins[v]=0;
        }
    }
}
namespace task41{
    int deg[N], cnt[N];
    vector<int> g[N];
    void solve(){
        for(int i=1; i<=n; ++i){
            deg[i]=e[i].size();
        }
        for(int u=1; u<=n; ++u){
            for(auto v:e[u]) if(deg[u]>deg[v]||(deg[u]==deg[v]&&u>v)) g[u].ep(v);
        }
        for(int a=1; a<=n; ++a){
            for(auto b:g[a]){
                for(auto c:e[b]) {
                    if(deg[a]<deg[c]||(deg[a]==deg[c]&&a<=c)) continue;
                    sum[4]+=cnt[c]++;
                }
            }
            for(auto b:g[a]) for(auto c:e[b]) cnt[c]=0;
        }
    }
}
namespace task42{
    int deg[N];
    vector<int> g[N];
    bool ins[N];
    void solve(){
        for(int i=1; i<=n; ++i){
            deg[i]=e[i].size();
        }
        for(int i=1; i<=n; ++i){
            for(auto j:e[i]) if(i<j){
                if(deg[i]<deg[j]) g[i].ep(j);
                else g[j].ep(i);
            }
        }
        for(int u=1; u<=n; ++u){
            for(auto v:g[u]) ins[v]=1;
            for(auto v:g[u]){
                for(auto w:g[v]){
                    if(ins[w]) {
                        sum[4]+=max(0, deg[u]-2);
                        sum[4]+=max(0, deg[v]-2);
                        sum[4]+=max(0, deg[w]-2);
                    }
                }
            }
            for(auto v:g[u]) ins[v]=0;
        }
    }
}
namespace task5{
    int deg[N];
    int idx;
    vector<pii> g[N];
    int ins[N];
    int cnt[N];
    void solve(){
        for(int i=1; i<=n; ++i){
            deg[i]=e[i].size();
        }
        for(int i=1; i<=n; ++i){
            for(auto j:e[i]) if(i<j){
                ++idx;
                if(deg[i]<deg[j]) g[i].ep(j, idx);
                else g[j].ep(i, idx);
            }
        }
        for(int u=1; u<=n; ++u){
            for(auto [v, id]:g[u]) ins[v]=id;
            for(auto [v, id1]:g[u]){
                for(auto [w, id2]:g[v]){
                    if(ins[w]) {
                        ++cnt[id1]; ++cnt[id2]; ++cnt[ins[w]];
                    }
                }
            }
            for(auto [v, id]:g[u]) ins[v]=0;
        }
        for(int i=1; i<=idx; ++i) sum[5]+=1ll*cnt[i]*(cnt[i]-1)/2;
    }
    
}
void solve(){
    read(n); read(m);
    for(int i=1, x, y; i<=m; ++i){
        read(x); read(y);
        e[x].ep(y); e[y].ep(x);
    }
    sum[0]=(lint)n*(n-1)*(n-2)*(n-3)/24;
    sum[1]=(lint)m*(n-2)*(n-3)/2;
    task2::solve();
    task3::solve();
    task41::solve();
    task42::solve();
    task5::solve();
    lint ans=0;
    for(int i=0; i<=4; i+=2) ans+=sum[i]-sum[i+1];
    if(ans<0) ans=-ans;
    write(ans);
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	solve();
	return 0;
}

