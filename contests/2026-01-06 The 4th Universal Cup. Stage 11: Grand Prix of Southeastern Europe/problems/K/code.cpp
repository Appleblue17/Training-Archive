#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,INF=1e9;
int n,m;
int a[5];
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair

vector<pii> b;

bool within(int x,int l,int r){
    if(r < l)r += 4*n;
    if(x < l)x += 4*n;
    if(l <= x && x <= r)return 1;
    else return 0;
}

signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
        bool f=0;
        for(int j=1;j<=4;j+=2){
            if((a[j]!=0 && a[j] != n) && (a[j+1] != 0 && a[j+1] != n)){
                f=1;
                break;
            }
        }
        if(!f){
            int x;
            if(a[1] == 0)x = a[2];
            else if(a[1] == n)x = 3*n-a[2];
            else if(a[2] == n)x = n+a[1];
            else if(a[2] == 0)x = 4*n-a[1];
            
            int y;
            if(a[3] == 0)y = a[4];
            else if(a[3] == n)y = 3*n-a[4];
            else if(a[4] == n)y = n+a[3];
            else if(a[4] == 0)y = 4*n-a[3];
            //printf("b add %d,%d\n",x,y);
            b.push_back(mapa(x,y));
        }
    }
    
    int m = b.size();
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            if(within(b[i].fi,b[j].fi,b[j].se) != within(b[i].se,b[j].fi,b[j].se)){
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    
    
}
