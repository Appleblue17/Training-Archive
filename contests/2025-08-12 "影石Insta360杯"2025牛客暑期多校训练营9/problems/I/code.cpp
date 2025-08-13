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
const int N=1005;
int T, n, m;
int d1[N][N], d2[N][N], e1[N][N], e2[N][N];
struct edg{
    int x, y, z;
    inline bool operator <(const edg &t)const{
        return z<t.z;
    }
};
int fa[N];
int get(int x){
    if(x==fa[x]) return x;
    return fa[x]=get(fa[x]);
}
bool merge(int x, int y){
    x=get(x); y=get(y);
    if(x==y) return false;
    fa[x]=y;
    return true;
}
vector<int> e[N];
vector<int> tmp;
void dfs(int x, int fa){
    tmp.ep(x);
    for(auto y:e[x]) if(y^fa){
        bool flag=1;
        for(auto t:tmp){
            if(t==x) continue;
            int p1=d1[x][y]+e1[t][x], p2=d2[x][y]+e2[t][x];
            if(p1>p2) swap(p1, p2);
            if(p1!=d1[t][y]||p2!=d2[t][y]) {
                flag=0; break;
            }
        }
        if(!flag) {
            swap(d1[x][y], d2[x][y]), swap(d1[y][x], d2[y][x]);
        }
        flag=1;
        for(auto t:tmp){
            if(t==x) continue;
            int p1=d1[x][y]+e1[t][x], p2=d2[x][y]+e2[t][x];
            if(p1>p2) swap(p1, p2);
            if(p1!=d1[t][y]||p2!=d2[t][y]) {
                flag=0; break;
            }
        }
        assert(flag);
        for(auto t:tmp){
            e1[t][y]=e1[t][x]+d1[x][y];
            e2[t][y]=e2[t][x]+d2[x][y];
            e1[y][t]=e1[t][y];
            e2[y][t]=e2[t][y];
        }
        printf("%d %d %d %d\n", x, y, d1[x][y], d2[x][y]);
        dfs(y, x); 
    }
}
void solve(){
    read(n);
    for(int i=1; i<=n; ++i){
        e[i].clear(); fa[i]=i;
        for(int j=1; j<=n; ++j){
            read(d1[i][j]); e1[i][j]=e2[i][j]=0;
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            read(d2[i][j]); if(d1[i][j]>d2[i][j]) swap(d1[i][j], d2[i][j]);
        }
    }
    vector<edg> vec;
    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            vec.push_back((edg){i, j, d1[i][j]+d2[i][j]});
        }
    }
    sort(vec.begin(), vec.end());
    for(auto t:vec){
        if(merge(t.x, t.y)){
            e[t.x].ep(t.y);
            e[t.y].ep(t.x);
        }
    }
    tmp.clear();
    dfs(1, 0);
}
int main(){
    // freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
    // freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
    read(T);
    while(T--){
        solve();
    }
    return 0;
}
