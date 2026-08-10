#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int MX = 1e9+10;

bitset<MX> ma;
bitset<MX> tb;
#define int long long
int n,m,l,r;

const int p = 1e9+7;

vector<int> C[18];



int solve2(){
    int ans=0;
    vector<int> a;
    for(int v=1;v<=min(17ll,m);v++){
        int u = v*2;
        if(v == 1)u=1;
        for(;u<C[v].size() && u <= n;u++){
            int x = C[v][u];
            if(x < l)continue;
            if(x > r)break;
            //printf("x=%lld\n",x);
            
                if(!ma[x]){
                    ma[x]=1;
                    a.push_back(x);
                    ans++;
                }
        }
    }
    for(int v:a)ma[v]=0;
    return ans;
}

int solve(){
    int ans=0;
    
    if(n >= r){
        ans = r-l+1;
        l = r+1;
        //printf("%lld\n",ans);
        return ans;
    }
    else if(n >= l){
        ans = n-l+1;
        l = n+1;
    }
    
    if(m == 1){
        //printf("%lld\n",ans);
        return ans;
    }
    
    int st = ceil((+1+sqrt(1+8*l))/2.0);
    int ed = floor((+1+sqrt(1+8*r))/2.0);
    //printf("st=%lld,ed=%lld\n",st,ed);
    if(st > n){
        ans+=0;
    }
    else if(ed > n){
        ans += n-st+1;
    }
    else{
        ans += ed-st+1;
    }
    
    //cout << ans << endl;
    
    if(m == 2){
        return ans;
    }
    
    vector<int> a;
    for(int v=3;v<=min(17ll,m);v++){
        int u = v*2;
        for(u=v*2;u<C[v].size() && u <= n;u++){
            int x = C[v][u];
            if(x < l)continue;
            if(x > r)break;
            //printf("x=%lld\n",x);
            
            if(x <= n*(n-1)/2 && tb[x]){
                continue;
            }
            
                if(!ma[x]){
                    ma[x]=1;
                    a.push_back(x);
                    ans++;
                }
        }
    }
    for(int v:a)ma[v]=0;
    return ans;
}

mt19937 rng(0);

signed main(){
    for(int i=1; i<=100000; ++i){
        if(i*(i-1)/2>1000000000) break;
        tb[i*(i-1)/2]=1;
    }
    C[0].push_back(0);
    for(int j=1;j<=2000;j++)C[0].push_back(1);
    for(int i=1;i<=17;i++){
        for(int j=0;j<i;j++){
            C[i].push_back(0);
        }
        C[i].push_back(1);
        for(int j=i+1;j<=2000;j++){
            if(C[i-1][j-1]+C[i][j-1] > 1e9){
                break;
            }
            C[i].push_back(C[i-1][j-1]+C[i][j-1]);
            // /printf("c[%lld][%lld]=%lld\n",i,j,C[i][j]);
            
        }
        
    }
    int t;cin >> t;while(t--){
        scanf("%lld%lld%lld%lld",&l,&r,&n,&m);
        //n = rng()%100+1;m = rng()%20+1;l = rng()%100+1;r = rng()%100+1;
        //if(l>r)swap(l,r);
        int yl=l,yr=r;
        //int ans2 = solve2();
        int ans1=solve();
        //if(ans1 != ans2){
        //    printf("ans1=%lld,bruteforce=%lld,l=%lld,r=%lld,n=%lld,m=%lld\n",ans1,ans2,yl,yr,n,m);
        //}
        printf("%lld\n",ans1);
    }
    
}
