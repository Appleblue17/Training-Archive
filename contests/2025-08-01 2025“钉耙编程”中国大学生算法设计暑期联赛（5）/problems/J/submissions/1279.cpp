#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=1e9+7;
int T,n;
double p[N];

double f[N];

signed main() {
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x; scanf("%d",&x);
            p[i]=1.0*x/1000;
        }
        
        f[n]=n;
        for(int i=n-1;i>=1;i--){
            f[i]=min(f[i+1],(1-p[i])*i+p[i]*(20+f[i+1]));
        }
        printf("%.12lf\n",f[1]);
    }
}