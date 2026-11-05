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
int a[N][N];
int e[N][N], d[N];
ll S;
bool suc;
void dfs(int x, int y, int W){
    if(x==n){
        bool flg=1;
        for(int i=2; i<=n; ++i){
            for(int j=i+1; j<=n; ++j){
                if(a[i][j]!=W-d[i]-d[j]+e[i][j]){
                    flg=0; break;
                }
            }
            if(!flg) break;
        }
        if(flg) suc=1;
        return ;
    }
    int nx=x, ny=y+1;
    if(y==n) ++nx, ny=nx+1;
    e[x][y]=1;
    ++d[x]; ++d[y];
    dfs(nx, ny, W+1);
    if(suc) return ;
    --d[x]; --d[y];
    e[x][y]=0;
    dfs(nx, ny, W);
    if(suc) return ;
}
ll v[N];
bool check(int d1){
    d[1]=d1;
    ll W=(S-2ll*(n-3)*d1)/(n-3)/(n-4);
    for(int i=2; i<=n; ++i){
        ll rem=W*(n-4)-v[i]+d1;
        if(rem%(n-4)==0){
            d[i]=rem/(n-4);
            e[1][i]=0;
            if(d[i]<0||d[i]>=n){
                return false;
            }
        }
        else if((rem-1)%(n-4)==0){
            d[i]=(rem-1)/(n-4);
            e[1][i]=1;
            if(d[i]<0||d[i]>=n){
                return false;
            }
        }
        else{
            return false;
        }
    }
    for(int i=2; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            e[i][j]=a[i][j]-W+d[i]+d[j];
            if(e[i][j]!=0&&e[i][j]!=1){
                return false;
            }
        }
    }
    return true;
}
void solve(){
    read(n);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j) read(a[i][j]);
    }
    if(n<=5){
        suc=0;
        dfs(1, 2, 0);
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(j<i) printf("%d ", e[j][i]);
                else printf("%d ", e[i][j]);
            }
            putchar('\n');
        }
        return ;
    }
    S=0;
    for(int i=1; i<=n; ++i){
        v[i]=0;
        for(int j=1; j<=n; ++j) if(a[i][j]!=-1) S+=a[i][j], v[i]+=a[i][j];
    }
    vector<int> bin;
    for(int d1=0; d1<n; ++d1){
        if((S-2ll*(n-3)*d1)%((n-3)*(n-4))!=0) continue;
        ll W=(S-2ll*(n-3)*d1)/(n-3)/(n-4);
        assert(W*(n-3)*(n-4)+2ll*(n-3)*d1==S);
        if(W>n*(n-1)/2) continue;
        ll rem=W*(n-4)-v[2]+d1;
        if(rem>=0&&rem%(n-4)==0){
            bin.ep(d1);
        }
        else if(rem>=1&&(rem-1)%(n-4)==0){
            bin.ep(d1);
        }
    }
    for(auto t:bin) {
        if(check(t)){
            for(int i=1; i<=n; ++i){
                for(int j=1; j<=n; ++j){
                    if(j<i) printf("%d ", e[j][i]);
                    else printf("%d ", e[i][j]);
                }
                putchar('\n');
            }
            return ;
        }
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
