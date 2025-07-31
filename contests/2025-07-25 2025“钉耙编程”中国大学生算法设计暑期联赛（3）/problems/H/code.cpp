#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=2e6+5;
int T,n,m;
char s[N];
inline void read(int &x){
    x=0; char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c-'0'), c=getchar();
}
int op[N];
int main(){
    read(T);
    while(T--){
        read(n); 
        scanf("%s", s+1);
        for(int i=1; i<=n; ++i){
            op[i]=(s[i]-'0')==(i&1);
        }
        int ans=n;
        int pos=n+1;
        for(int i=1; i<=n; ++i){
            if(op[i]==0) pos=i;
        }
        if(pos==n+1) ans=min(ans, n/2);
        else{
            int sum=0;
            for(int i=1; i<=n; ++i) sum+=op[i];
            for(int i=1; i<=n; ++i) op[i+n]=op[i];
            for(int l=pos+1; l<=n+pos; ++l){
                if(op[l]==0) continue;
                int r=l;
                while(r+1<=pos+n&&op[r+1]==1){
                    ++r;
                }
                sum-=(r-l+1)/2;
                l=r;
            }
            ans=min(ans, sum);
        }
        
        for(int i=1; i<=n; ++i){
            op[i]=(s[i]-'0')!=(i&1);
        }
        pos=n+1;
        for(int i=1; i<=n; ++i){
            if(op[i]==0) pos=i;
        }
        if(pos==n+1) ans=min(ans, n/2);
        else{
            int sum=0;
            for(int i=1; i<=n; ++i) sum+=op[i];
            for(int i=1; i<=n; ++i) op[i+n]=op[i];
            for(int l=pos+1; l<=n+pos; ++l){
                if(op[l]==0) continue;
                int r=l;
                while(r+1<=pos+n&&op[r+1]==1){
                    ++r;
                }
                sum-=(r-l+1)/2;
                l=r;
            }
            ans=min(ans, sum);
        }
        printf("%d\n", ans);
    }
    
    
}