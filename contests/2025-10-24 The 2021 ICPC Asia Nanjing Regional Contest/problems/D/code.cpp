#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
int T, n;
int a[N];
int tr[N];
void add(int x, int v){
    x=n+1-x;
    for(; x<=n; x+=(x&-x)) tr[x]+=v;
}
int get(int x){
    x=n+1-x;
    int ret=0;
    for(; x>0; x-=(x&-x)) ret+=tr[x];
    return ret;
}
ll ans[N];
int cnt[N];
void upd(int x){
    if(!cnt[x]) add(x, 1);
    cnt[x]++;
}
void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i=1; i<=n; ++i) tr[i]=0, cnt[i]=0;
    upd(a[1]);
    int pos=0;
    for(int i=2; i<=n; ++i){
        ans[i]=ans[i-1];
        upd(a[i]);
        if(a[i]>a[1]){
            ans[i]+=cnt[a[1]]-1;
            if(pos!=0) ans[i]+=(i-1-cnt[a[1]]-pos+2);
            swap(a[i], a[1]);
            ++ans[i];
            pos=0;
        }
        else if(a[i]==a[1]){
            if(pos==0) pos=i;
        }
        ans[i]+=get(a[i]+1);
        // cout<<a[i]<<' '<<get(a[i]+1)<<endl;
    }
    for(int i=1; i<=n; ++i){
        printf("%lld", ans[i]);
        putchar(" \n"[i==n]);
    }
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
