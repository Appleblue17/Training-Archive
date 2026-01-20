#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
vector<int> a[33];

const int p = 1e9+7;

int ksm(int base,int n){
    int ret=1;
    while(n){
        if(n&1)ret = ret*base%p;
        base=base*base%p;
        n/=2;
    }
    return ret;
}

bool cmp(int a,int b){
    return a>b;
}

signed main(){
    
    //cout << (24*ksm(2,40) + 7*ksm(2,41))%p << endl;
    
    scanf("%lld%lld",&n,&k);
    
    for(int i=1;i<=n;i++){
        int x,len=0;
        scanf("%lld",&x);
        while((1<<len) <= x)len++;
        len--;
        //printf("x=%lld,len=%lld\n",x,len);
        a[len].push_back(x);
    }
    
    for(int i=0;i<=29;i++){
        sort(a[i].begin(),a[i].end(),cmp);
        int st = (int)a[i].size()-1;
        for(int j=st;j>=0;j--){
            if(k <= 0)break;
            a[i+1].push_back(a[i][j]*2);
            a[i].pop_back();
            k--;
            if(k <= 0)break;
        }
        if(k <= 0)break;
    }
    
    if(k > 0){
        sort(a[30].begin(),a[30].end());
        int r = k/n,id = k%n,ans=0;
        for(int i=0;i<a[30].size();i++){
            if(i < id)ans += a[30][i]*ksm(2,r+1)%p;
            else ans += a[30][i]*ksm(2,r)%p;
        }
        ans %= p;
        printf("%lld\n",ans);
    }
    else{
        int ans=0;
        for(int i=0;i<=30;i++){
            for(int v:a[i]){
                ans+=v;
            }
        }
        ans %= p;
        printf("%lld\n",ans);
    }
    
}
