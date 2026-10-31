#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,x[N],y[N],a[N],b[N];

vector<int> g[9],ans;

int dct[6][3] = {
    {0,4,8},
    {2,4,6},
    {5,1,6},
    {5,7,0},
    {1,3,8},
    {2,3,7}
};

signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x[i],&y[i]);
        if(x[i] <= n/3)a[i] = 0;
        else if(x[i] <= n*2/3)a[i]=1;
        else a[i]=2;
        if(y[i] <= n/3)b[i] = 0;
        else if(y[i] <= n*2/3)b[i]=1;
        else b[i]=2;
        g[a[i]*3+b[i]].push_back(i);
    }
    
    for(int i=1;i<=n/3;i++){
        for(int o=0;o<6;o++){
            bool f=1;
            for(int j=0;j<3;j++){
                if(!g[dct[o][j]].size())f=0;
            }
            if(f){
                for(int j=0;j<3;j++){
                    ans.push_back(g[dct[o][j]].back());
                    g[dct[o][j]].pop_back();
                }
            }
        }
    }
    
    int sm=0;
    for(int i=0;i<ans.size();i+=3){
        int A = ans[i],B = ans[i+1],C = ans[i+2];
        sm += abs(x[A]-x[B]) + abs(y[A]-y[B]) + abs(x[A]-x[C]) + abs(y[A]-y[C]) + abs(x[C]-x[B]) + abs(y[C]-y[B]);
    }
    
    printf("%lld\n",sm);
    
    for(int i=0;i<ans.size();i++){
        printf("%lld ",ans[i]);
        if(i%3==2)printf("\n");
    }
    
}