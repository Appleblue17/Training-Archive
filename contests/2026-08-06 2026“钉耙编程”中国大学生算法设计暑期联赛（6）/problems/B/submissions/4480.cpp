#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1100,INF=1e18;
int T,n,m;
int a[N][N];

int fx[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
pair<int,int> v[6];

int cal0(int mac){
    int c=__builtin_popcount(mac);
    if(!c) return 0;
    if(c==1) return 6;
    if(c==2){
        if(mac==3 || mac==12) return 7;
        else return 11;
    }
    if(c==3) return 13;
    if(c==4) return 14;
    assert(0);
}

int cal1(int mac){
    int c=__builtin_popcount(mac);
    if(!c) return 6;
    if(c==1) return 11;
    if(c==2){
        if(mac==3 || mac==12) return 13;
        else return 15;
    }
    if(c==3) return 18;
    if(c==4) return 20;
    assert(0);
}
int cal2(int mac){
    int c=__builtin_popcount(mac);
    if(!c) return 7;
    if(c==1) return 13;
    if(c==2){
        if(mac==3 || mac==12) return 14;
        else return 18;
    }
    if(c==3) return 20;
    if(c==4) return 21;
    assert(0);
}

int cal(int mac,int typ){
    if(!typ) return cal0(mac);
    else return cal1(mac);
}

int sol(int x,int typ){
    int tot=0;
    int mac=15;
    for(int t=5;t>=1;t--){
        int R=min(v[t].first,x),L=max(v[t-1].first+1,2ll);
        mac ^= v[t].second;
        if(L>R) continue;
        // cout<<"  "<<t<<": "<<L<<" "<<R<<" "<<mac<<endl;
        tot+=max(0ll,R-L+1)*cal(mac,typ);
    }
    return tot;
}


signed main(){
    cin>>T;
    while(T--){
        scanf("%lld%lld",&n,&m);
        for(int i=0;i<=n+1;i++)
            for(int j=0;j<=m+1;j++)
                a[i][j]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%lld",&a[i][j]);
        
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                int x=a[i][j];
                if(!x) continue;
                // cout<<"start "<<i<<" "<<j<<endl;
                
                v[0]={0,0};
                for(int t=0;t<4;t++) v[t+1]={a[i+fx[t][0]][j+fx[t][1]],1<<t};
                v[5]={INF,0};
                sort(v,v+6);
                
                // for(int t=0;t<6;t++) cout<<v[t].first<<","<<v[t].second<<" | ";
                // cout<<endl;
                
                int tot=sol(x-1,0)+sol(x,1)-sol(x-1,1);
                // cout<<tot<<endl;
                // cout<<sol(x-1,0)<<endl;
                // cout<<sol(x,1)<<endl;
                // return 0;
                
                int mac=15;
                for(int t=0;t<6;t++){
                    if(v[t].first>=1) mac ^= v[t].second;
                }
                // cout<<" mac "<<mac<<endl;
                if(x==1) tot+=cal2(mac);
                else tot+=cal1(mac);
                
                // cout<<" get "<<tot<<endl;
                ans+=tot;
            }
        printf("%lld\n",ans);
    }
}