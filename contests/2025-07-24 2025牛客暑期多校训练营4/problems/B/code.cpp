#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
const int N=1100000;
const int mod=998244353;
 
typedef pair<int,int> pii;
 
const int dir[3][2] = {{-1,0},{1,0},{0,-1}};
 
vector<int> a[N],vis[N],reachable[N];
 
int n,m,k;
char s[N];
 
void solve(){
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=0;i<=n;i++){
        a[i].clear();vis[i].clear();
        reachable[i].clear();
    }
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        for(int j=0;j<m;j++){
            a[i].push_back(s[j]-'0');
            vis[i].push_back(0);
            reachable[i].push_back(0);
        }
    }
    queue<pii> Q;
    Q.push(mp(1,0));
    reachable[1][0]=1;
    while(!Q.empty()){
        pii u = Q.front();
        Q.pop();
        for(int d=0;d<=2;d++){
            pii v = mp(u.first-dir[d][0],u.second-dir[d][1]);
            if(v.first < 1 || v.first > n)continue;
            if(v.second < 0 || v.second >= m)continue;
            if(!a[v.first][v.second] && !reachable[v.first][v.second]){
                reachable[v.first][v.second]=1;
                //printf("%lld %lld is reachable\n",v.first,v.second);
                Q.push(v);
            }
        }
         
    }
    queue<pii> q;
    for(int tim=1;tim<=m-k;tim++){
        for(int i=1;i<=n;i++){
            if(!vis[i][m-tim]){
                vis[i][m-tim]=tim;
                //printf("start bfs at %lld %lld,tim=%lld\n",i,m-tim,tim);
                q.push(mp(i,m-tim));
            }
        }
        while(!q.empty()){
            pii u = q.front();
            q.pop();
            for(int d=0;d<=2;d++){
                pii v = mp(u.first+dir[d][0],u.second+dir[d][1]);
                if(v.first < 1 || v.first > n)continue;
                if(v.second < 0 || v.second >= m)continue;
                if(!a[v.first][v.second] && !vis[v.first][v.second]){
                    vis[v.first][v.second]=tim;
                    //printf("visited %lld %lld at time = %lld\n",v.first,v.second,tim);
                    if(tim != 1 && m-tim - v.second >= k && reachable[v.first][v.second]){
                        printf("Yes\n");
                        return;
                    }
                    q.push(v);
                }
            }
        }
    }
    printf("No\n");
}
 
signed main(){
    int T;scanf("%lld",&T);while(T--)solve();
}
