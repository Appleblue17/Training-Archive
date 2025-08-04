#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define N 1000010
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ull,ull> puu;
//mt19937_64 rng(GetTickCount());
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int mo=1e9+7;
using namespace std;
ll a[N],b[N],bit[N],f[N],pos[N];
ll t,n,m,x,y,ans,k;
int lowbit(int x){
    return x & (-x);
}
void change(int id,ll x){
    //printf("change %d to %lld\n",id,x);
    for(int i=id;i<=n+1;i+=lowbit(i)){
        bit[i]=max(bit[i],x);
    }
}
ll query(int id){

    ll ret=0;
    for(int i=id;i>0;i-=lowbit(i)){
        ret = max(ret,bit[i]);
    }
    //printf("query %d return %lld\n",id,ret);
    return ret;
}
void solve(){
	ans=0;
	scanf("%lld",&n);
    for(int i=0;i<=n+1;i++){
        bit[i]=0;
    }
    ll mx = 0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
        pos[a[i]]=i;
	}
    pos[0]=0;pos[n+1]=n+1;
    for(int i=1;i<=n+1;i++){
        f[i]=0;
        if(pos[i-1]<pos[i])f[i] = f[i-1]+1;
        f[i] = max(f[i],query(pos[i]));
        change(pos[i],f[i]);
    }
    printf("%lld\n",n-f[n+1]+1);
}
int main(){
	int T;
    scanf("%d",&T);
	for(int i=1;i<=T;i++){
		solve();
	}
}