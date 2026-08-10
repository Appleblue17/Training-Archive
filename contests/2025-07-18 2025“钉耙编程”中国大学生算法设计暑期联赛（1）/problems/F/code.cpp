#include <bits/stdc++.h>
using namespace std;
int T, n, m;
const int N = 105;
int a[N][N];
typedef long long ll;
struct edg{
    int x, y; ll z;
    bool operator <(const edg &e)const{
        return z<e.z;
    }
};
int id(int x, int y){
    return (x-1)*m+y;
}
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
pii seq[N*N]; 
bool vis[N][N];
int fa[N*N];
ll val(pii x, pii y){
    return 114ll*abs(x.fi-y.fi)+5141ll*abs(x.se-y.se)+919810ll*abs(a[x.fi][x.se]-a[y.fi][y.se]);
}
int get(int x){
    if(x==fa[x]) return x;
    return fa[x]=get(fa[x]);
}
ll dis[N*N];
const ll inf=1e18;
void solve() {
    scanf("%d%d", &n, &m);
    int len=0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]); seq[++len]=mapa(i, j); vis[i][j]=1;
        }
    }
    sort(seq+1, seq+len+1, [&](pii x, pii y){return a[x.fi][x.se]<a[y.fi][y.se];});
    int cur=n*m;
    vector<pii> vec;
    bool flag=0;
    while(true){
        while(cur>=1&&vis[seq[cur].fi][seq[cur].se]==0) --cur;
        if(cur==0) break;
        queue<pii> que;
        que.push(seq[cur]);
        if(seq[cur].fi==1&&seq[cur].se==1) flag=1;
        vec.push_back(seq[cur]);
        vis[seq[cur].fi][seq[cur].se]=0;
        while(!que.empty()){
            int x=que.front().fi, y=que.front().se;
            que.pop();
            for(int d=0; d<4; ++d){
                int cx=x+dx[d], cy=y+dy[d];
                if(cx<1||cx>n||cy<1||cy>m) continue;
                if(a[cx][cy]>a[x][y]) continue;
                if(vis[cx][cy]==0) continue;
                vis[cx][cy]=0;
                que.push(mapa(cx, cy));
            }
        }
    }
    if(!flag) vec.push_back(mapa(1, 1));
    // for(auto t:vec){
    //     cout<<t.fi<<' '<<t.se<<endl;
    // }
    ll ans=(1ll<<34ll)*(vec.size()-1);
    vector<edg> e;
    for(int i=1; i<(int)vec.size(); ++i) dis[i]=val(vec[0], vec[i]);
    for(int i=1; i<(int)vec.size(); ++i){
        ll mn=inf; int id=0;
        for(int i=1; i<(int)vec.size(); ++i){
            if(dis[i]<mn){
                mn=dis[i]; id=i;
            }
        }
        ans+=dis[id]; dis[id]=inf;
        for(int i=1; i<(int)vec.size(); ++i){
            if(dis[i]==inf) continue;
            dis[i]=min(dis[i], val(vec[i], vec[id]));
        }
    }
    printf("%lld\n", ans);
}
int main() {
    scanf("%d", &T);
    while (T--) {
        solve();
    }
}