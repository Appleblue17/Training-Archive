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
int a[N];
int f[N][20], g[N][20];
int mex(int x, int y, int z){
	int it=0;
	while((it==x)||(it==y)||(it==z)) ++it;
	return it;
}
int tr1[20][20], tr2[20][70000], tr3[70000][20];
bool flag[N];
int dp[N][4], dp2[N][4];
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n);
	for(int i=1; i<=n; ++i) {
		read(a[i]);
		if(a[i]<=3) f[i][1]=1<<a[i];
		else g[i][1]=1<<3;
	}
	for(int i=0; i<(1<<4); ++i){
		for(int j=0; j<(1<<4); ++j){
			for(int c1=0; c1<4; ++c1) if((i>>c1)&1){
				for(int c2=0; c2<4; ++c2) if((j>>c2)&1){
					tr1[i][j]|=(1<<(c1*4+c2));
				}
			}
		}
	}
	for(int i=0; i<(1<<4); ++i){
		for(int j=0; j<(1<<16); ++j){
			for(int c1=0; c1<4; ++c1) if((i>>c1)&1){
				for(int c2=0; c2<4; ++c2) {
					for(int c3=0; c3<4; ++c3) if((j>>(c2*4+c3))&1){
						tr2[i][j]|=1<<(mex(c1, c2, c3));
						tr3[j][i]|=1<<(mex(c1, c2, c3));
					}
				}
			}
		}
	}
	for(int len=2; len<=16; ++len){
		for(int l=1, r=len; r<=n; ++l, ++r){
			for(int c=1, d=len-1; d>0; ++c, --d){
				if((c&1)&&(d&1)){
					f[l][len]|=tr1[f[l][c]][f[l+c][d]];
					g[l][len]|=tr1[g[l][c]][f[l+c][d]];
					g[l][len]|=tr1[f[l][c]][g[l+c][d]];
					g[l][len]|=tr1[g[l][c]][g[l+c][d]];
				}
				else if((c&1)&&!(d&1)){
					f[l][len]|=tr2[f[l][c]][f[l+c][d]];
					f[l][len]|=tr2[f[l][c]][g[l+c][d]];
					f[l][len]|=tr2[g[l][c]][f[l+c][d]];
					f[l][len]|=tr2[g[l][c]][g[l+c][d]];
				}
				else if(!(c&1)&&(d&1)){
					f[l][len]|=tr3[f[l][c]][f[l+c][d]];
					f[l][len]|=tr3[f[l][c]][g[l+c][d]];
					f[l][len]|=tr3[g[l][c]][f[l+c][d]];
					f[l][len]|=tr3[g[l][c]][g[l+c][d]];
				}
				// else {
				// 	for(int c1=0; c1<4; ++c1) {
				// 		for(int c2=0; c2<4; ++c2) if((f[l][c]>>(c1*4+c2))&1){
				// 			for(int c3=0; c3<4; ++c3) {
				// 				for(int c4=0; c4<4; ++c4) if((f[l+c][d]>>(c3*4+c4))&1){
				// 					f[l][len]|=1<<(mex(c1, c2, c3)*4+c4);
				// 					f[l][len]|=1<<(c1*4+mex(c2, c3, c4));
				// 				}
				// 			}
				// 		}
				// 	}
				// }
			}
		}
	}
	
	flag[n+1]=1; a[n+1]=1e9;
	for(int i=n; i>=1; --i){
		if(a[i]>a[i+1]) break;
		flag[i]=1;
	}
	int ans=1e9;
	memset(dp, 0x3f, sizeof dp);
	memset(dp2, 0x3f, sizeof dp2);
	dp[0][0]=0;
	for(int i=1; i<=n+1; ++i){
		if(flag[i]){
			for(int j=0; j<4&&j<=a[i]; ++j){
				// cout<<i<<' '<<j<<' '<<dp[i-1][j]<<' '<<dp2[i-1][j]<<endl;
				ans=min(ans, dp[i-1][j]);
				ans=min(ans, dp2[i-1][j]);
			}
		}
		for(int j=0; j<4; ++j){
			dp[i-1][j]=min(dp[i-1][j], dp2[i-1][j]);
			dp2[i+1][j]=min(dp2[i+1][j], dp2[i-1][j]+1);
			for(int k=j; k<4; ++k){
				dp2[i+16][k]=min(dp2[i+16][k], dp[i-1][j]+8);
			}
			if(j<=a[i]&&a[i]<=3){
				dp[i][a[i]]=min(dp[i][a[i]], dp[i-1][j]);
				if(a[i]<=a[i+1]&&a[i+1]<=3){
					dp[i+1][a[i+1]]=min(dp[i+1][a[i+1]], dp[i-1][j]);
				}
			}
			for(int len=3; len<=16; ++len){
				if(len&1){
					for(int c1=j; c1<4; ++c1) if((f[i][len]>>c1)&1){
						dp[i+len-1][c1]=min(dp[i+len-1][c1], dp[i-1][j]+((len-1)/2));
					}
				}
				else{
					for(int c1=j; c1<4; ++c1) {
						for(int c2=c1; c2<4; ++c2) if((f[i][len]>>(c1*4+c2))&1){
							dp[i+len-1][c2]=min(dp[i+len-1][c2], dp[i-1][j]+((len-2)/2));
						}
					}
				}
			}
		}
	}
	if(ans==1e9) ans=-1;
	printf("%d\n", ans);
	return 0;
}

