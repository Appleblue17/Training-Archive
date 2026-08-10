#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mo = 998244353;
const int N=2e6+5;
int T,n,k,a[N][2],id[N];

int ksm(int a,int x,int p){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%p;
        a=a*a%p;
        x>>=1;
    }
    return tot;
}

int deg[N];
bool cmp(int i,int j){
    return a[i][1]<a[j][1];
}

void solve(){
    for(int i=1;i<=k;i++){
        id[i]=i;
    }
    sort(id+1,id+k+1,cmp);
    //cout << a[id[k]][0] << endl;
    int ans = 4+k*2,lid=n+1,rid=0,l=0,r=0;
    int lrow=a[id[1]][0],rrow=a[id[k]][0];
    for(int i=1;i<=k;i++){
        if(i != 1 && a[id[i]][1] == a[id[i-1]][1]){
            ans --;
        }
        if(i != k && a[id[i]][1] == a[id[i+1]][1]){
            ans --;
        }
        //printf("i=%lld,0=%lld,lid=%lld,rid=%lld,lrow=%lld,rrow=%lld\n",i,a[id[i]][0],lid,rid,lrow,rrow);
        if(a[id[i]][0] != lrow){
            lid = min(lid,a[id[i]][1]);
        }
        if(a[id[i]][0] != rrow){
            rid = max(rid,a[id[i]][1]);
        }
    }
    int fans=1;
    //printf("lid=%lld,rid=%lld\n",lid,rid);
    if(lid == n+1 || rid == 0){
        fans = ksm(2,ans-2,mo);
        printf("%lld\n",fans);
        return;
    }
    
    for(int i=1;i<=k;i++){
        if(a[id[i]][1] < lid){
            l++;
        }
    }
    for(int i=k;i>=1;i--){
        if(a[id[i]][1] > rid){
            r++;
        }
    }
    //cout << l << ' ' << r << endl;
    if(l != 0){
        ans -= l+1;
        fans = fans*(ksm(2,l,mo)+1)%mo;
    }
    if(r != 0){
        ans -= r+1;
        fans = fans*(ksm(2,r,mo)+1)%mo;
    }
    fans = fans*ksm(2,ans,mo)%mo;
    printf("%lld\n",fans);
}

signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<=k;i++){
            scanf("%lld%lld",&a[i][0],&a[i][1]);
        }
        solve();
    }
}
