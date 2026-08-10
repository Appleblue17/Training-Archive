#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+5,INF=1e18;
int T,n,nn,m,k;

struct abc{
    int x,y,typ;
}p[N];
bool operator <(abc X,abc Y){
    return X.x<Y.x;
}
int pid;

map <int,int> mp;

signed main(){
    cin>>T;
    while(T--){
        scanf("%lld%lld",&n,&m); nn=2*n;
        pid=0;
        for(int i=1;i<=m;i++){
            int x,y; scanf("%lld%lld",&x,&y);
            p[++pid]={x,y,0};
        }
        
        scanf("%lld",&k);
        for(int i=1;i<=k;i++){
            int x,y; scanf("%lld%lld",&x,&y);
            p[++pid]={x,y,1};
        }
        sort(p+1,p+pid+1);
        
        mp.clear();
        mp[0]=0;
        for(int t=1;t<=pid;t++){
            int x=p[t].x,y=p[t].y,typ=p[t].typ;
            
            int A=y,B=2*n-y;
            A=(A+nn-x%nn)%nn;
            B=(B+nn-x%nn)%nn;
            
            if(!mp.count(A)) mp[A]=-INF;
            if(!mp.count(B)) mp[B]=-INF;
            if(!typ){
                int mx=max(mp[A],mp[B]);
                mp[A]=mp[B]=mx;
            }
            else{
                mp[A]++;
                mp[B]++;
            }
        }
        
        int ans=0;
        for(pair<int,int> x: mp) ans=max(ans,x.second);
        printf("%lld\n",ans);
    }
}
