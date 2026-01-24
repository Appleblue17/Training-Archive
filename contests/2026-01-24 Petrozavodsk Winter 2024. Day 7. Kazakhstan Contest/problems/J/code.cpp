#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5;
int T,n;
int a[N];
priority_queue <int> q;
bool vis[N];
stack <int> sta;

signed main(){
    cin>>T;
    while(T--){
        while(q.size()) q.pop();
        while(sta.size()) sta.pop();
        
        long long A=0,B=0,C=0;
        scanf("%d",&n);
        for(int i=1;i<=n*3;i++) scanf("%d",&a[i]),vis[i]=0;
        for(int i=1;i<=n*3;i+=3){
            if(i>2) q.push(a[i-2]);
            if(i>1) q.push(a[i-1]);
            q.push(a[i]);
            int x=q.top(); q.pop();
            A+=x; vis[x]=1;
        }
        for(int i=n*3;i>=1;i--){
            if(vis[a[i]]){
                B+=sta.top(); sta.pop();
                C+=sta.top(); sta.pop();
            }
            else sta.push(a[i]);
        }
        
        printf("%lld %lld %lld\n",A,B,C);
    }
}
