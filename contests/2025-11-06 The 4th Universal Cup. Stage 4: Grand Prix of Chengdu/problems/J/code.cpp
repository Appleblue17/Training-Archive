#include<bits/stdc++.h>
using namespace std;
//#define int long long
int T, n, m,k,b,ac,toa;
const int N=110000,M=15;
//int s[N][M];
void solve(){
    scanf("%d%d%d%d",&n,&m,&k,&b);
    ac = toa = 0;
    for(int i=1;i<=n;i++){
        int sm1=0,sm2=0;
        for(int j=1;j<=m;j++){
            int x;
            scanf("%d",&x);
            sm1 += x;
            if(x>0)x--;
            else x++;
            sm2+=x;
        }
        if(sm1 >= k)ac++;
        else if(sm2 >= k)toa++;
    }
    printf("%d\n",ac+min(toa,b));
}
signed main(){
    cin>>T;
    while(T--){
        solve();
    }
    
}
