#include <bits/stdc++.h>
using namespace std;
const int N=1005;
typedef long long ll;
int T,n,m,k;
int dis[N][N],ma[N][N],r[N],c[N];
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair
queue<pii> q;
int dir[3][2] = {{0,1},{-1,0},{1,0}};
int ans;
void solve(){
    while(!q.empty()){
        pii v,u = q.front();
        q.pop();
        for(int o=0;o<3;o++){
            v.fi = u.fi + dir[o][0];
            v.se = u.se + dir[o][1];
            if(v.fi < 1 || v.fi > n)continue;
            if(v.se < 1 || v.se > m)continue;
            if(ma[v.fi][v.se])continue;
            if(dis[v.fi][v.se] != -1)continue;
            dis[v.fi][v.se] = dis[u.fi][u.se] + 1;
            q.push(v);
        }
    }
    ans = 1e9;
    for(int i=1;i<=n;i++){
        if(dis[i][m] == -1)continue;
        ans = min(ans,dis[i][m]);
    }
}
signed main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &n, &m, &k);
        for(int i=1;i<=k;i++){
            scanf("%d%d",&r[i],&c[i]);
        }
        while(!q.empty())q.pop();
        for(int s=0;s<(1<<k);s++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    ma[i][j]=0;
                    if(j == 1){
                        dis[i][j]=0;
                        q.push(mapa(i,j));
                    }
                    else{
                        dis[i][j]=-1;
                    }
                }
            }
            for(int i=1;i<=k;i++){
                if(s & (1<<(i-1))){
                    for(int j=r[i];j>=1;j--){
                        ma[j][c[i]]=1;
                    }
                }
                else{
                    for(int j=r[i];j<=n;j++){
                        ma[j][c[i]]=1;
                    }
                }
            }
            /*for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    cout << ma[i][j] << ' ';
                }
                cout << endl;
            }
            cout << endl;*/
            solve();
            if(ans == 1e9)printf("-1 ");
            else printf("%d ",ans);
        }
        putchar('\n');
    }
    
}


