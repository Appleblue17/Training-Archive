#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1.1e6+5;
int n,m;
int a[N];

struct LB{
    int d[66],siz;
    void ins(int x){
        for(int i=62;i>=0;i--){
            if(x>>i & 1ll){
                if(!d[i]){
                    d[i]=x;
                    siz++;
                    return ;
                }
                x^=d[i];
            }
        }
    }
}B;

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    
    for(int i=1;i<n;i++) B.ins(a[i]^a[i+1]);
    if(B.siz==m) printf("Yes");
    else printf("No");
    
}
