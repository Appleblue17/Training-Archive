#include <bits/stdc++.h>
using namespace std;
#define OUT(t) putchar('0'+t)
const int N=440;
int n,k,l,m,x,y,ans[6];
bool f=0;

const int dict[6] = {0,-10,-10,-2,11,1};

void solve(){
    scanf("%d%d%d",&k,&l,&m);
    if(k == 0){
        swap(k,l);
        f=1;
    }
    if(l == 0){
        //x = -m/k
        int g = __gcd(m,k);
        m /= g;k /= g;
        int z=(m+3000)/k-1000;
        int l = (z+3000)%k;
        
        if(k != 3 && k != 1){
            printf("0 0 0 0 0 0\n");
            return;
        }
        
        if(k == 3){
            if(l == 1){
                for(int i=0;i<6;i++){
                    ans[i] = dict[i]+z;
                }
            }
            else{
                for(int i=0;i<6;i++){
                    ans[i] = -dict[i]+z+1;
                }
            }
        }
        else if(k == 1){
            x = y = 0;
        }
    }
    else{
        /*for(x=0;x<=1000;x++){
            if((-m-k*x) % l == 0){
                y = (-m-k*x)/l;
                break;
            }
        }*/
        int gc=__gcd(k,l);
        if(m%gc) 
        
    }
    
    printf("%d %d %d %d %d %d\n",x+l,y-k,x+k,y+l,y-k,y-l);
}


signed main(){
    int t;
    cin>>t;while(t--){
        solve();
    }
}
