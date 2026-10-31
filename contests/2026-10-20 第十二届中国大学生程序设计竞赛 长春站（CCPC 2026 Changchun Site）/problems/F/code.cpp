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
const int N=105, mod=1e9+7;
int T, n, m;
int a[N];
int f[N][N][N];
int sum[N][N][N];
int C[N][N];
void solve(){
    read(n);
    for(int i=1; i<=n; ++i) read(a[i]);
    if(a[1]!=0&&a[1]!=-1&&a[n]!=0&&a[n]!=-1){
        printf("0\n");
        return ;
    }
    for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) for(int k=0; k<=n; ++k) f[i][j][k]=0;
    for(int i=1; i<=n; ++i) {
        if(i==1||i==n){
            if(a[i]==-1||a[i]==0) f[i][i][0]=1;
        }
        else{
            if(a[i]==-1||a[i]==1) f[i][i][1]=1;
        }
    }
    for(int len=2; len<=n; ++len){
        for(int l=1, r=len-1; r<=n; ++l, ++r){
            sum[l][r][0]=f[l][r][0];
            for(int t=1; t<=n; ++t) sum[l][r][t]=(sum[l][r][t-1]+f[l][r][t])%mod;
        }
        for(int l=1, r=len; r<=n; ++l, ++r){
            for(int x=l+1; x<r; ++x){
                for(int t=2; t<=n; ++t) if(a[x]==t||a[x]==-1){
                    if(l==1||r==n) continue;
                    f[l][r][t]=(f[l][r][t]+1ll*C[r-l][r-x]*f[l][x-1][t-1]%mod*sum[x+1][r][t-1])%mod;
                    f[l][r][t]=(f[l][r][t]+1ll*C[r-l][r-x]*sum[l][x-1][t-2]%mod*f[x+1][r][t-1])%mod;
                }
                if(a[x]==0||a[x]==-1){
                    if(l!=1&&r!=n){
                        
                    }
                    else if(l==1&&r==n){
                        f[l][r][0]=(f[l][r][0]+1ll*C[r-l][r-x]*sum[l][x-1][n]%mod*sum[x+1][r][n])%mod;
                    }
                    else if(l==1){
                        f[l][r][0]=(f[l][r][0]+1ll*C[r-l][r-x]*sum[l][x-1][n]%mod*(sum[x+1][r][n]+mod-f[x+1][r][0]))%mod;
                    }
                    else if(r==n){
                        f[l][r][0]=(f[l][r][0]+1ll*C[r-l][r-x]*(sum[l][x-1][n]+mod-f[l][x-1][0])%mod*sum[x+1][r][n])%mod;    
                    }
                }
            }
            {
                // x=l
                if(l==1){
                    if(a[l]==0||a[l]==-1){
                        if(r==n){
                            f[l][r][0]=(f[l][r][0]+sum[l+1][r][n])%mod;
                        }
                        else{
                            f[l][r][0]=(f[l][r][0]+sum[l+1][r][n])%mod;
                            f[l][r][0]=(f[l][r][0]+mod-f[l+1][r][0])%mod;
                        }
                    }
                }
                else{
                    if(a[l]==0||a[l]==-1){
                        if(r==n){
                            f[l][r][0]=(f[l][r][0]+sum[l+1][r][n])%mod;
                        }
                    }
                    for(int t=2; t<=n; ++t) if(a[l]==t||a[l]==-1){
                        if(l==1||r==n) continue;
                        f[l][r][t]=(f[l][r][t]+f[l+1][r][t-1])%mod;
                    }
                }
            }
            {
                // x=r
                if(r==n){
                    if(a[r]==0||a[r]==-1){
                        if(l==1){
                            f[l][r][0]=(f[l][r][0]+sum[l][r-1][n])%mod;
                        }
                        else{
                            f[l][r][0]=(f[l][r][0]+sum[l][r-1][n])%mod;
                            f[l][r][0]=(f[l][r][0]+mod-f[l][r-1][0])%mod;
                        }
                    }
                }
                else{
                    if(a[r]==0||a[r]==-1){
                        if(l==1){
                            f[l][r][0]=(f[l][r][0]+sum[l][r-1][n])%mod;
                        }
                    }
                    for(int t=2; t<=n; ++t) if(a[r]==t||a[r]==-1){
                        if(l==1||r==n) continue;
                        f[l][r][t]=(f[l][r][t]+f[l][r-1][t-1])%mod;
                    }
                }
            }
            // for(int t=0; t<=n; ++t){
            //     cout<<l<<' '<<r<<' '<<t<<' '<<f[l][r][t]<<endl;
            // }
        }
    }
    printf("%d\n", f[1][n][0]);
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    C[0][0]=1;
    for(int i=1; i<N; ++i){
        C[i][0]=1;
        for(int j=1; j<=i; ++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
	read(T);
	while(T--){
		solve();
	}
	return 0;
}
