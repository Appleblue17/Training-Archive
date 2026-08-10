#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define mp make_pair
const int N=55;
const int mod=998244353;
  
typedef pair<int,int> pii;
  
const int dir[4][2] = {{1,0},{0,-1},{0,1},{-1,0}};
  
int a[N][N],tar[N][N],pos[N][N],vis[N][N],dis[N][N];
 
vector<int> fans[3];
 
void addans(int x,int y,int z){
    //assert(pos[x][y]==1);
    //assert(pos[x+dir[z][0]][y+dir[z][1]]==0);
    if(pos[x+dir[z][0]][y+dir[z][1]]!=0)return;
    pos[x][y]=0;
    pos[x+dir[z][0]][y+dir[z][1]]=1;
    fans[0].push_back(x);
    fans[1].push_back(y);
    fans[2].push_back(z);
}
 
vector<int> sav[3];
 
void saveans(int x,int y,int z){
    sav[0].push_back(x);
    sav[1].push_back(y);
    sav[2].push_back(z);
}
  
int n,m,k;
char s[N];
  
void solve(){
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            a[i][j]=pos[i][j]=tar[i][j]=0;
        }
    }
    fans[0].clear();fans[1].clear();fans[2].clear();
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        for(int j=0;j<m;j++){
            if(s[j]=='#'){
                a[i][j+1]=1;
            }
            else if(s[j] == '@'){
                pos[i][j+1]=1;
            }
            else if(s[j] == '*'){
                tar[i][j+1]=1;
            }
            else if(s[j] == '!'){
                pos[i][j+1]=tar[i][j+1]=1;
            }
        }
    }
    for(int box=1;box<=50;box++){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            queue<pii> Q;
            if(!pos[i][j])continue;
            if(pos[i][j] && tar[i][j])continue;
            memset(vis,-1,sizeof(vis));
            memset(dis,0,sizeof(dis));
            dis[i][j]=1;
            vis[i][j]=0;
            Q.push(mp(i,j));
            while(!Q.empty()){
                pii u = Q.front();
                Q.pop();
                for(int d=0;d<=3;d++){
                    pii v = mp(u.first+dir[d][0],u.second+dir[d][1]);
                    if(v.first < 1 || v.first > n)continue;
                    if(v.second < 1 || v.second > m)continue;
                    if(a[v.fi][v.se])continue;
                    if(-1 == vis[v.fi][v.se]){
                        vis[v.first][v.second]=3-d;
                        dis[v.fi][v.se] = dis[u.fi][u.se]+1;
                        //printf("%lld %lld is reachable\n",v.first,v.second);
                        Q.push(v);
                    }
                }
            }
            pii v;
            int ans=0;
            for(int k=1;k<=n;k++){
                for(int l=1;l<=m;l++){
                    //printf("dis[%lld][%lld]=%lld\n",k,l,dis[k][l]);fflush(stdout);
                    if(dis[k][l]>ans && tar[k][l]){
                        if(tar[k][l] && pos[k][l])continue;
                        ans = dis[k][l];
                        v = mp(k,l);
                    }
                }
            }
            if(ans == 0){
                printf("-1\n");
                return;
            }
            vector<pii> route;
            vector<int> d;
            int C=0;
            while(v != mp(i,j)){
                //printf("v = %lld,%lld\n",v.fi,v.se);fflush(stdout);
                 
                int D = vis[v.fi][v.se];
                //printf("D=%lld\n",D);fflush(stdout);
                d.push_back(3-D);
                v.fi += dir[D][0];
                v.se += dir[D][1];
                route.push_back(v);
            }
            sav[0].clear();sav[1].clear();sav[2].clear();
            for(int i=d.size()-1;i>=0;i--){
                v = route[i];
                int D = d[i];
                pii w = mp(v.fi+dir[D][0],v.se+dir[D][1]);
                if(!pos[w.fi][w.se]){
                    addans(v.fi,v.se,D);
                }
                else{
                    saveans(v.fi,v.se,D);
                }
                v.fi += dir[D][0];
                v.se += dir[D][1];
            }
            for(int i=sav[0].size()-1;i>=0;i--){
                addans(sav[0][i],sav[1][i],sav[2][i]);
            }
            //printf("moved box from %lld %lld to %lld %lld\n",i,j,v.fi,v.se);
            assert(pos[v.fi][v.se]==1);
            assert(tar[v.fi][v.se]==1);
            //assert(a[v.fi][v.se]==0);
            //pos[v.fi][v.se]=0;
            //tar[v.fi][v.se]=0;
            //a[v.fi][v.se]=1;
        }
    }
 
    }
    cout << fans[0].size() << endl;
    for(int i=0;i<fans[0].size();i++){
        printf("%lld %lld ",fans[0][i],fans[1][i]);
        if(fans[2][i]==0)putchar('D');
        if(fans[2][i]==3)putchar('U');
        if(fans[2][i]==1)putchar('L');
        if(fans[2][i]==2)putchar('R');
        putchar('\n');
    }
     
}
  
signed main(){
    solve();
    //int T;scanf("%lld",&T);while(T--)solve();
}
