#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,INF=1e18;
int T,n,m,s;

int a1[N],b1[N],id1;
int a2[N],b2[N],id2;

int solve(){
    if(s>=n*m) return 0;
    
    n--,m--;
    id1=id2=0;
    
    for(int l=1,r;l<=n;l=r+1){
        r=n/(n/l);
        // cout<<l<<" "<<r<<" "<<(n/l)+1<<endl;
        id1++;
        a1[id1]=l-1,b1[id1]=(n/l)+1;
    }
    a1[++id1]=n,b1[id1]=1;
    
    for(int l=1,r;l<=m;l=r+1){
        r=m/(m/l);
        // cout<<l<<" "<<r<<" "<<(n/l)+1<<endl;
        id2++;
        a2[id2]=l-1,b2[id2]=(m/l)+1;
    }
    a2[++id2]=m,b2[id2]=1;
    
    a2[id2+1]=INF;
    int ans=INF;
    int cur=id2+1;
    for(int i=1;i<=id1;i++){
        while(cur && b2[cur-1]<=s/b1[i]) cur--;
        ans=min(ans,a1[i]+a2[cur]);
    }
    return ans;
}

signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&s);
        int ans=solve();
        printf("%lld\n",ans);
    }
}
