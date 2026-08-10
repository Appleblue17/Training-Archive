#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=3e5+5,INF=1e9;
int T,n,m;
vector <int> V[N];

signed main(){
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++) V[i].clear();
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int x; scanf("%d",&x);
                V[j].push_back(x);
            }
        }
        
        for(int i=1;i<=m;i++) sort(V[i].begin(),V[i].end());
        
        int ans=0,nw=0;
        for(int t=1;t<m;t++){
            int cur=0;
            for(int i=nw;i<n;i++){
                if(V[t][i]>V[t+1][cur]){
                    ans++;
                    cur++;
                }
            }
            nw=cur;
        }
        
        if(ans>=n) printf("YES\n");
        else printf("NO\n");
    }
}
