#include <bits/stdc++.h>
using namespace std;
const int N=210000;
typedef long long ll;
int T,n,m;
int x[N],y[N],z[N];
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair

unordered_map<int,int> mx,my,mz;
int sm[4];
signed main(){
    scanf("%d", &T);
    while(T--){
        mx.clear();my.clear();mz.clear();
        scanf("%d%d", &n, &m);
        for(int o=0;o<4;o++)sm[o]=0;
        for(int i=1;i<=n+m;i++){
            scanf("%d%d%d",&x[i],&y[i],&z[i]);
            mx[x[i]]++;
            my[y[i]]++;
            mz[z[i]]++;
            //sm[(x[i]&1)*2+(y[i]&1)]++;
        }
        bool f=1;
        for(int i=1;i<=n+m;i++){
            if(mx[x[i]]&1)f=0;
            if(my[y[i]]&1)f=0;
            if(mz[z[i]]&1)f=0;
        }
        //for(int o=0;o<4;o++){
            //if(sm[o]&1)f=0;
        //}
        if(f)printf("YES\n");
        else printf("NO\n");
        
    }
    
}


