#include <bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int T,n;
vector <int> D[N];
int x,y;
int a[N];
void solve(){
    int cnt=0;
    int C=0;
    while(1){
        C++;
        if(x == y){
            printf("%d\n",cnt+1);
            return;
        }
        if((x&1)^(y&1)){
            printf("-1\n");
            return;
        }
        if((x%2==0) && (y%2==0)){
            x/=2;
            y/=2;
        }
        bool f=0;
        if(x > y){
            f=1;
            swap(x,y);
        }
        /*int t = (y-x-1)/2/x+1;
        y -= t*x;
        x += t*x;*/
        y -= x;
        x += x;
        if(f){
            swap(x,y);
        }
        cnt += 1;
        //cout << x << ' ' << y << endl;if(C >= 100)break;
    }
}
 
signed main(){
     
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&x,&y);
        solve();
    }
     
}
