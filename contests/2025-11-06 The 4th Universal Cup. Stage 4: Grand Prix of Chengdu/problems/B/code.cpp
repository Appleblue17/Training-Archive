#include<bits/stdc++.h>
using namespace std;
#define int long long
int T, n, m,k,R,a[10],c[10],l,base[70][70],ret[70][70],temp[70][70];
void solve(){
    scanf("%lld%lld%lld%lld",&n,&m,&k,&R);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&a[i],&c[i]);
    }
    l=n;
    n = 1<<n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            base[i][j]=-2e15;
            ret[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int cost = 0,eff = 0;
            for(int o=0;o<l;o++){
                if(i & (1<<o)){//this turn
                    eff += a[o];
                    if(j & (1<<o)){//last turn
                        cost += c[o]+k;
                    }
                    else cost += c[o];
                }
            }
            if(cost > m){
                base[i][j] = -2e15;
            }
            else{
                base[i][j] = eff;
            }
        }
    }
    //for(int i=0;i<n;i++){
    //    for(int j=0;j<n;j++){
    //        printf("base[%lld][%lld]=%lld\n",i,j,base[i][j]);
    //    }
    //}
    while(R){
        if(R&1){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    temp[i][j] = ret[i][j];
                }
            }
            for(int j=0;j<n;j++){
                for(int i=0;i<n;i++){
                    ret[i][j]=-2e15;
                    for(int k=0;k<n;k++){
                        ret[i][j] = max(ret[i][j],temp[i][k]+base[k][j]);
                    }
                }
            }
            //ret *= base;
        }
        //base*=base;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    temp[i][j] = base[i][j];
                }
            }
            for(int j=0;j<n;j++){
                for(int i=0;i<n;i++){
                    base[i][j]=-2e15;
                    for(int k=0;k<n;k++){
                        base[i][j] = max(base[i][j],temp[i][k]+temp[k][j]);
                    }
                }
            }
        R/=2;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans = max(ans,ret[i][0]);
    }
    printf("%lld\n",ans);
}
signed main(){
    cin>>T;
    while(T--){
        solve();
    }
    
}
