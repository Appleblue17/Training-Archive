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
const int N=1e6+5, mod=998244353;
int T, n, m;
int a[N];
mt19937_64 rng(1234);
ull hs[N][4];
int lst[N][4];
int cnt[N];
int dp[N];
ull pre[N];
void solve(){
    read(n);
    for(int i=1; i<=n; ++i){
        for(int j=0; j<3; ++j) hs[i][j]=rng();
        hs[i][3]=hs[i][0]^hs[i][1]^hs[i][2];
        for(int j=0; j<4; ++j) lst[i][j]=0;
        cnt[i]=0;
    }
    unordered_map<ull, int> h;
    int del=-1;
    dp[0]=1; h[0]+=1;
    for(int i=1; i<=n; ++i){
        read(a[i]);
        pre[i]=pre[i-1]^hs[a[i]][cnt[a[i]]];
        // cout<<pre[i]<<endl;
        ++cnt[a[i]]; cnt[a[i]]%=4;
        int cur=lst[a[i]][0];
        while(del+1<cur){
            ++del;
            h[pre[del]]=(h[pre[del]]+mod-dp[del])%mod;
        }
        // cout<<"i:"<<i<<endl;
        // cout<<"del:"<<del<<endl;
        dp[i]=h[pre[i]];
        // cout<<dp[i]<<endl;
        h[pre[i]]=(h[pre[i]]+dp[i])%mod;
        for(int j=0; j<3; ++j) lst[a[i]][j]=lst[a[i]][j+1];
        lst[a[i]][3]=i;
    }
    printf("%d\n", dp[n]);
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