#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,mod=998244353;
 
int T,n,m,l[N],r[N],mnr[N],ans[N];
 
void solve(){
     
}
 
signed main() {
     
    cin>>T;
    while(T--){
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n*2;i++){
            mnr[i]=n*2+1;
            ans[i]=-1;
        }
        for(int i=1;i<=m;i++){
            scanf("%lld%lld",&l[i],&r[i]);
            mnr[l[i]] = min(mnr[l[i]],r[i]);
        }
        int lst=n*2+1,cb=n;
        for(int i=n*2;i>=1;i--){
            if(cb == i)break;
            if(mnr[i] < lst){
                ans[i]=1;
                lst=i;
                cb--;
            }
        }
         
        for(int i=1;i<=cb;i++)ans[i]=1;
        int t=0;
        bool f=1;
        if(cb<=0)f=0;
        for(int i=1;i<=n*2;i++){
            t+=ans[i];
            if(t<0){
                f=0;
                break;
            }
        }
        if(t != 0)f=0;
        if(!f)printf("-1\n");
        else{
            for(int i=1;i<=n*2;i++){
                if(ans[i]==1)putchar('(');
                else putchar(')');
            }
            putchar('\n');
        }
    }
     
     
}
