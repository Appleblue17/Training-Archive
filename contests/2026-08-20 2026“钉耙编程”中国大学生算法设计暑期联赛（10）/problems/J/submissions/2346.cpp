#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
int T, n, m;
int a[N],b[N],f[N];
unordered_map<int,int> ma;
//bool cmp(int i,int j){
//    return ma[b[i]] < ma[b[j]];
//}

#define lowbit(x) (x&(-x))
int bit[N];

void change(int x,int y){
    for(;x<N;x+=lowbit(x)){
        bit[x] = max(bit[x],y);
    }
}

int query(int x){
    int ret=0;
    for(;x>0;x-=lowbit(x)){
        ret = max(ret,bit[x]);
    }
    return ret;
}

void solve(){
    memset(bit,0,sizeof(bit));
    cin >> n >> m;
    ma.clear();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&a[(i-1)*m+j]);
            ma[a[(i-1)*m+j]] = (i-1)*m+j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&b[(i-1)*m+j]);
            //id[(i-1)*m+j] = (i-1)*m+j;
            b[(i-1)*m+j] = ma[b[(i-1)*m+j]];
        }
    }
    int ans=0;
    for(int i=1;i<=n*m;i++){
        //printf("b[%lld]=%lld\n",i,b[i]);
        f[i] = query(b[i])+1;
        //printf("f[%lld]=%lld\n",i,f[i]);
        change(b[i],f[i]);
        ans = max(ans,f[i]);
    }
    
    printf("%lld\n",n*m-ans);
    
    
    
    
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //printf("%lld: %lld,%lld\n",(i-1)*m+j,a[(i-1)*m+j],b[(i-1)*m+j]);
            //id[(i-1)*m+j] = (i-1)*m+j;
        }
    }*/
    
    
    
    
}
signed main(){
    //ios::sync_with_stdio(false);
    
    cin>>T;
    while(T--){
        solve();
    }
}