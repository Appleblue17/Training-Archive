#pragma GCC optimize(2)
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
const int N=1e3+5, M=1e9;
int T, n=1000, B=31;
ll a[N]; 
int op[N];
ll a2[N]; int op2[N];
ll v[35];
mt19937_64 rnd(time(0));
void fnd(int sz){
    unordered_map<int, ll> h;
    while(true){
        ll msk=rnd()&((1ll<<sz)-1);
        ll sum=0;
        for(int i=0; i<sz; ++i) if((msk>>i)&1) sum=(sum+a2[i]%M+M)%M;
        if(h.find(sum)!=h.end()&&h[sum]!=msk){
            for(int i=0; i<sz; ++i){
                if((msk>>i)&1) op2[i]+=1;
                if((h[sum]>>i)&1) op2[i]-=1;
            }
            return ;
        }
        h[sum]=msk;
    }
}
int main(){
    // freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
    // freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    for(int i=1; i<=n; ++i) read(a[i]);
//     for(int i=1; i<=n; ++i) a[i]=rnd()%(1ll*M*M)+1;
    int id=0;
    for(int l=1, r=B; r<=n; l+=B, r+=B){
        ++id;
        for(int i=0; i<B; ++i) a2[i]=a[l+i]%M, op2[i]=0;
        fnd(B);
        for(int i=0; i<B; ++i) {
            op[i+l]=op2[i];
            if(op[i+l]) v[id]+=(op[i+l]==1)?a[i+l]:-a[i+l], v[id]%=1ll*M*M, v[id]+=1ll*M*M, v[id]%=1ll*M*M;
        }
    }
    for(int i=1; i<=id; ++i){
        // assert(v[i]%M==0);
        a2[i-1]=v[i]/M;
        op2[i-1]=0;
    }
    fnd(id);
    for(int i=1; i<=id; ++i){
        if(op2[i-1]==0){
            for(int j=(i-1)*B+1; j<=i*B; ++j) op[j]=0;
            continue;
        }
        if(op2[i-1]==-1){
            for(int j=(i-1)*B+1; j<=i*B; ++j) op[j]=-op[j];
        }
    }
    __int128 sum=0;
    for(int i=1; i<=n; ++i) if(op[i]) sum+=(op[i]==1)?a[i]:-a[i];
    if(sum<0){
        for(int i=1; i<=n; ++i) op[i]=-op[i];
    }
//     cout<<(ll)(sum%(1ll*M*M))<<endl;
    for(int i=1; i<=n; ++i) printf("%d", (op[i]<0)?2:op[i]);
    return 0;
}
