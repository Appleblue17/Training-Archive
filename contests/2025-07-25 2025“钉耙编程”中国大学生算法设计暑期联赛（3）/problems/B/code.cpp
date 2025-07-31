#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=1e6+5;
int T,n,m;
int b[N],c[N];
inline void read(int &x){
    x=0; char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c-'0'), c=getchar();
}

int main(){
    read(T);
    while(T--){
        read(n); read(m);
        for(int i=1;i<=n;++i) read(b[i]);
        for(int i=1;i<=n;++i) read(c[i]);
        
        for(int i=2;i<=n;++i) b[i]=max(b[i],b[i-1]);
        for(int i=n-1;i>=1;--i) c[i]=min(c[i],c[i+1]);
        
        long long mn=0,mx=0;
        for(int i=1;i<=n;++i) mn+=b[i],mx+=c[i];
        if(mn<=m && m<=mx) printf("YES\n");
        else printf("NO\n");
    }
    
    
}