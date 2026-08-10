#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m;
int a[N],b[N],c[N],id[N],f[N][3];
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair
vector<pii> t[N];

bool cmp(int i,int j){
    return b[i]<b[j];
}


signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        id[i]=i;
        f[i][0] = f[i][1] = f[i][2] = -1e10;
        
    }
    
    sort(id+1,id+n+1,cmp);
    id[n+1]=n+1;
    b[n+1]=0;
    
    for(int i=1;i<=n;i++){
        if(b[id[i]] != b[id[i+1]]){
            m++;
            t[m].push_back(mapa(a[id[i]],b[id[i]]));
            t[m].push_back(mapa(a[id[i]],c[id[i]]));
            t[m].push_back(mapa(b[id[i]],c[id[i]]));
        }
        else{
            m++;
            t[m].clear();
            t[m].push_back(mapa(a[id[i+1]],c[id[i]]));
            t[m].push_back(mapa(a[id[i]],c[id[i+1]]));
            i++;
        }
    }
    
    int ans = -1e10;
    id[0]=0;
    t[0].push_back(mapa(0,0));
    f[0][0]=0;
    for(int i=1;i<=m;i++){
        int l1,r1,l2,r2,val;
        for(int j=0;j<t[i-1].size();j++){
            l1 = t[i-1][j].fi;r1 = t[i-1][j].se;
            for(int k=0;k<t[i].size();k++){
                l2 = t[i][k].fi;r2 = t[i][k].se;val = r2-l2;
                //printf("i=%lld,j=%lld,k=%lld,%lld %lld %lld %lld\n",i,j,k,l1,r1,l2,r2);
                if(l1 == l2 && r1 == r2)continue;
                if(!(l1 < l2 && l2 < r1) && !(l1 < r2 && r2 < r1) && !(l2 < l1 && l1 < r2) && !(l2 < r1 && r1 < r2)){
                    f[i][k] = max(f[i][k],f[i-1][j]+val);
                    //printf("trans i=%lld,j=%lld,k=%lld,%lld %lld %lld %lld\n",i,j,k,l1,r1,l2,r2);
                }
                
            }
            
        }
        for(int k=0;k<t[i].size();k++){
            //printf("f[%lld][%lld]=%lld\n",i,k,f[i][k]);
            if(i == m)ans = max(ans,f[i][k]);
        }
    }
    
    if(ans<0)printf("-1\n");
    else printf("%lld\n",ans);
}
