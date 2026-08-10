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
void solve(){
    string s;
    cin>>s;
    if(s[0]==s[2]){
        printf("No\n");
        return ;
    }
    if(s[1]=='+'||s[1]=='*'){
        printf("Yes\n");
        return ;
    }
    if(s[1]=='-' && s[0]=='0'){
        printf("Yes\n");
        return ;
    }
    printf("No\n");
}
int main(){
    // freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
    // freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
    read(T);
    while(T--){
        solve();
    }
    return 0;
}
