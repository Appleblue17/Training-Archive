#include<bits/stdc++.h>
#define ll long long
#define int __int128
using namespace std;
const int N=1100000;
ll n,m,V,L,R;
ll s[N],a[N],b[N],c[N];


int sidx,sval;

int sp(int i,int j){
    if(j == 0)return 0;
    return (-b[i]*j*j+b[i]*j)/2+a[i]*j+c[i];
}

void slopeval(int x){
    //printf("slopeval %lld\n",x);
    sidx=0;sval=0;
    for(int i=1;i<=n;i++){
        int j = (a[i]-x-1)/b[i]+1;
        if(j <= 1){
            if(x < a[i]+c[i])j=1;
            else j=0;
        }
        if(j > s[i])j=s[i];
        sidx+=j;
        sval += sp(i,j);
    }
    //printf("slopeval result idx=%lld,val=%lld\n",sidx,sval);
}

int pointeval(int x){
    //printf("pointeval %lld\n",x);
    int l = -4e12,r=4e12,m;
    while(l<r){
        m = (l+r)>>1;
        slopeval(m);
        if(sidx <= x){
            r = m;
        }
        else{
            l = m+1;
        }
    }
    slopeval(l);
    int val = sval + l*(x-sidx);
    //printf("pointeval result=%lld\n",val);
    return val;
}


void solve(){
    scanf("%lld%lld%lld%lld%lld",&n,&m,&V,&L,&R);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld%lld",&s[i],&a[i],&b[i],&c[i]);
    }
    int ans=0;
    ans = max(ans,pointeval(L)+V);
    ans = max(ans,pointeval(R)+V);
    if(m > R){
        ans = max(ans,pointeval(m));
    }
    slopeval(0);
    if(sidx <= m){
        if(L <= sidx && sidx <= R){
            ans = max(ans,sval+V);
        }
        else ans = max(ans,sval);
    }
    printf("%lld\n",(ll)ans);
    
    
    
    
}
signed main(){
    //freopen("C.out","w",stdout);
    ll T;cin >> T;
    while(T--){
        solve();
    }
}
