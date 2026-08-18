#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int T,n,k,q;
int a[N],s[N];

int rd(){
    char c=getchar();
    int tot=0;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}

struct LB{
    int d[66];
    LB(){
        memset(d,0,sizeof(d));
    }
    void ins(int x){
        for(int i=60;i>=0;i--){
            if(x>>i & 1){
                if(!d[i]){
                    d[i]=x;
                    break;
                }
                else x^=d[i];
            }
        }
    }
    int qry(int x){
        for(int i=60;i>=0;i--){
            if(!(x>>i & 1)) x^=d[i];
        }
        return x;
    }
};

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    T=rd();
    while(T--){
        LB B;
        n=rd(),k=rd(),q=rd();
        for(int i=1;i<=n;i++) a[i]=rd(),s[i]=s[i-1]^a[i];
        for(int i=k;i<=n;i++) B.ins(s[i]^s[i-k]);
        while(q--){
            int x=rd();
            printf("%lld\n",B.qry(x));
        }
    }
    
}