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
char s[N], t[N];
int main(){
    // freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
    // freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    read(n); read(m);
    scanf("%s", s+1);
    while(m--){
        scanf("%s", t+1); int a; read(a);
        int lst=0;
        int len=strlen(t+1);
        ll ans=0;
        for(int i=1; i<=len; ++i){
            if(s[a+i-1]==t[i]){
                ++lst;
            }
            else{
                ans+=1ll*lst*(lst+1)/2ll;
                lst=0;
            }
        }
        ans+=1ll*lst*(lst+1)/2ll;
        printf("%lld\n", ans);
    }
    return 0;
}
