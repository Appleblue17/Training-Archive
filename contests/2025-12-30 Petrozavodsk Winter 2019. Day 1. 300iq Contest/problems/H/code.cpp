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
int n, m;
int C[21][21];
int lim[21];
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    read(n); read(m); m=(1<<n)-1-m;
	C[0][0]=1;
    for(int i=1; i<=n; ++i){
        C[i][0]=1;
        for(int j=1; j<=i; ++j) C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    for(int i=1; i<=n; ++i){
        for(int j=0; j<=n-i; ++j){
            if(m>=C[n-i][j]){
                m-=C[n-i][j]; lim[i]=j+1;
            }
            else{
                break;
            }
        }
    }
    int sum=0;
    for(int i=1; i<=n; ++i) sum+=lim[i];
    cout<<sum<<endl;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=lim[i]; ++j){
            cout<<i<<' '<<j<<endl;
        }
    }
    return 0;
}

