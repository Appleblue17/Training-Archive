#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;

int T,n,k;
pair<int,int> p[N];

bool solve(){
    int tot=0;
    for(int i=1;i<=n;i++){
        int tme=p[i].first;
        tot+=p[i].second;
        if(tme*k<tot) return 0;
    }
    return 1;
}


signed main(){
    cin>>T;
    while(T--){
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<=n;i++) scanf("%lld%lld",&p[i].first,&p[i].second);
        sort(p+1,p+n+1);
        
        if(solve()) printf("Yes\n");
        else printf("No\n");
    }
}
