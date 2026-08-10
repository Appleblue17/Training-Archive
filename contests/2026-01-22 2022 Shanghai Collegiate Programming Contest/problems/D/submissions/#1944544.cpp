#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=1.1e6+5;

int P,Q,k,A,B;
int A_,B_;

int vis[N];
int cal(int x,int y){
    return (x<y)?y-x:x-y;
}

signed main(){
    cin>>P>>Q>>k;
    while(k--){
        cin>>A_>>B_;
        A=A_%P,B=B_%P;
        
        for(int i=0;i<Q;i++) vis[i]=-1;
        int x=A;
        while(1){
            // cout<<x<<" "<<x%Q<<endl;
            if(vis[x%Q]!=-1){
                if(__gcd(cal(x,vis[x%Q]),P)==Q) putchar('1');
                else putchar('0');
                break;
            }
            vis[x%Q]=x;
            x=(x*x%P+B)%P;
        }
    }
    
}
