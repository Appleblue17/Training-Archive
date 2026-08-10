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
int T, n; ll m;
mt19937_64 rnd(time(0));
inline ll ran(ll l, ll r){
    return rnd()%(r-l+1)+l;
}
int ans[20][1000];
void solve(){
    read(n); read(m);
    if(n<=16){
        if(ans[n][m]==-1) printf("-1\n");
        else{
            for(int i=0; i<n; ++i) printf("%d", (ans[n][m]>>i)&1);
            putchar('\n');
        }
        return ;
    }
    int t=sqrt(m);
    for(int i=1; i<=t+10&&i<=n; ++i) putchar(ran('0', '1'));
    for(int i=t+11; i<=n; ++i) putchar('0');
    putchar('\n');
}
int main(){
    memset(ans, -1, sizeof ans);
    for(n=1; n<=16; ++n){
        for(int s=0; s<(1<<n); ++s){
            map<pii, bool> h;
            for(int l=1; l<=n; ++l){
                int cur=0;
                for(int r=l; r<=n; ++r){
                    cur<<=1; cur+=(s>>(r-1))&1;
                    h[mapa(r-l+1, cur)]=1;
                }
            }
            ans[n][h.size()]=s;
        }
    }
    read(T);
    while(T--){
        solve();
    }
    return 0;
}
