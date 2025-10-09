#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=50005;
int n, m;
int c[N][15];
int a[N];
set<pair<ll, int> > d[15][15];
#define fi first
#define se second
#define mapa make_pair
int dd[N][15];
void del(int x){
    for(int i=1; i<=m; ++i)if(dd[x][i]==1){
        for(int j=1; j<=m; ++j) if(dd[x][j]==0){
            d[i][j].erase(mapa(c[x][j]-c[x][i], x));
        }
    }
}
void add(int x){
    for(int i=1; i<=m; ++i)if(dd[x][i]==1){
        for(int j=1; j<=m; ++j) if(dd[x][j]==0){
            d[i][j].insert(mapa(c[x][j]-c[x][i], x));
        }
    }
}
vector<pair<ll, int> > e[N];
ll dis[N];
bool vis[N];
int fr[N];
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            scanf("%d", &c[i][j]);
        }
    }
    for(int i=1; i<=m; ++i){
        scanf("%d", &a[i]);
    }
    ll ans=0;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m+1; ++j) e[j].clear(), vis[j]=0, fr[j]=0;
        dis[m+1]=1e18;
        queue<int> pq;
        for(int j=1; j<=m; ++j){
            dis[j]=c[i][j];
            pq.push(j); vis[j]=1;
            for(int k=1; k<=m; ++k) if(!d[j][k].empty()){
                e[j].push_back(mapa((*d[j][k].begin()).fi, k));
            }
            if(a[j]>0){
                e[j].push_back(mapa(0ll, m+1));
            }
        }
        while(!pq.empty()){
            int x=pq.front(); pq.pop();
            vis[x]=0;
            for(auto edg:e[x]){
                int y=edg.se; ll z=edg.fi;
                if(dis[y]>dis[x]+z){
                    dis[y]=dis[x]+z;
                    fr[y]=x;
                    if(!vis[y]){
                        vis[y]=1;
                        pq.push(y);
                    }
                }
            }
        }
        ans+=dis[m+1];
        int p=fr[m+1];
        --a[p];
        // cout<<"cur:"<<i<<endl;
        // cout<<"dis:"<<dis[m+1]<<endl;
        while(fr[p]!=0){
            int q=fr[p];
            int w=(*d[q][p].begin()).se;
            del(w);
            dd[w][q]^=1; dd[w][p]^=1;
            add(w);
            // cout<<"back:"<<p<<' '<<q<<endl;
            p=q;
        }
        // cout<<"p:"<<p<<endl;
        del(i);
        dd[i][p]^=1;
        add(i);
    }
    printf("%lld\n", ans);
}

