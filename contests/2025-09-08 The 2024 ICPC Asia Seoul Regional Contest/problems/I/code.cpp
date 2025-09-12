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
int n;
vector<int> p[3];
ll hs(int x, int y){
    return 1000000000ll*x+y;
}
unordered_map<ll, int> h[N];
int calc(int x, int y, int z){
    if(x==0&&y==0&&z==0) return 0;
    if(h[x].find(hs(y, z))!=h[x].end()) return h[x][hs(y, z)];
    int mx=p[0][x], id=0;
    if(p[1][y]>mx) mx=p[1][y], id=1;
    if(p[2][z]>mx) mx=p[2][z], id=2;
    if(id==0){
        int nx=upper_bound(p[0].begin(), p[0].end(), mx-10001)-p[0].begin()-1;
        int ny=upper_bound(p[1].begin(), p[1].end(), mx-10001)-p[1].begin()-1;
        int nz=upper_bound(p[2].begin(), p[2].end(), mx-10001)-p[2].begin()-1;
        return h[x][hs(y, z)]=1+min(calc(nx, ny, z), calc(nx, y, nz));
    }
    else if(id==1){
        int nx=upper_bound(p[0].begin(), p[0].end(), mx-10001)-p[0].begin()-1;
        int ny=upper_bound(p[1].begin(), p[1].end(), mx-10001)-p[1].begin()-1;
        return h[x][hs(y, z)]=calc(nx, ny, z)+1;
    }
    else{
        int nx=upper_bound(p[0].begin(), p[0].end(), mx-10001)-p[0].begin()-1;
        int nz=upper_bound(p[2].begin(), p[2].end(), mx-10001)-p[2].begin()-1;
        return h[x][hs(y, z)]=calc(nx, y, nz)+1;
    }
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
    read(n);
    p[0].ep(-1e9-1e8);
    p[1].ep(-1e9-1e8);
    p[2].ep(-1e9-1e8);
    for(int i=1, x, y; i<=n; ++i){
        read(x); read(y);
        if(y==0) p[0].ep(x);
        else if(y==9999) p[1].ep(x);
        else p[2].ep(x);
    }
    for(int i=0; i<3; ++i) sort(p[i].begin(), p[i].end());
    printf("%d\n", calc(p[0].size()-1, p[1].size()-1, p[2].size()-1));
}
