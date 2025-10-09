#include<bits/stdc++.h>
using namespace std;
#define int long long
#define i128 __int128
typedef pair<int,int> pii;
#define fi first 
#define se second 
#define mp make_pair
const int N=110000;
int n,m,e,x,y,ans[N];
pii ed[N],ba[N],so[N];

pii operator -(pii a,pii b){return mp(a.fi-b.fi,a.se-b.se);}
pii operator *(pii a,int d){return mp(a.fi*d,a.se*d);}

i128 Cross(pii a,pii b){
    return (i128)a.fi*(i128)b.se - (i128)a.se*(i128)b.fi;
}

i128 Dot(pii a,pii b){
    return (i128)a.fi*b.fi+(i128)a.se*b.se;
}

struct p2{
    pii v;
    int id;
    p2(int x,int y,int id):v(mp(x,y)),id(id){}
    p2(pii v,int id):v(v),id(id){}
};


pii o;

int qua(pii p){
    if(p.fi <= o.fi && p.se <= o.se)return 1;
    if(p.fi > o.fi && p.se <= o.se)return 2;
    if(p.fi > o.fi && p.se > o.se)return 3;
    if(p.fi <= o.fi && p.se > o.se)return 4;
}

bool cmp(pii a, pii b){
    if(qua(a) != qua(b)){
        return qua(a) < qua(b);
    }
    return Cross(a-o,b-o)>0;
}

bool cmpp2(p2 a,p2 b){
    return(cmp(a.v,b.v)); 
}


vector<p2> g[N];

vector<int> G[N];
int reach[N];
void dfs(int u){
    if(G[u].size()){
        if(!reach[G[u][0]]){
            reach[G[u][0]]=1;
            //printf("dfs reach %d,%d\n",u/101,u%101);
            dfs(G[u][0]);
        }
    }
}

int dcmp(i128 x){
    return x==0?0:(x<0?-1:1);
}

bool ison(pii p,pii a,pii b){
    return dcmp(Cross(a-p,b-p))==0 && dcmp(Dot(a-p,b-p))<0;
}

bool spi(pii a1,pii a2,pii b1,pii b2){
   // printf("segment proper intersection %lld %lld %lld %lld %lld %lld %lld %lld\n",a1.fi,a1.se,a2.fi,a2.se,b1.fi,b1.se,b2.fi,b2.se);
    if(ison(a1,b1,b2) || ison(a2,b1,b2) || ison(b1,a1,a2) || ison(b2,a1,a2))return true;
    i128 c1 = Cross(a2-a1,b1-a1),c2 = Cross(a2-a1,b2-a1);
    i128 c3 = Cross(b2-b1,a1-b1),c4 = Cross(b2-b1,a2-b1);
    //cout << c1 << ' ' << c2 << endl;
    return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4)<0;
}

signed main(){
    scanf("%lld%lld%lld",&n,&m,&e);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x,&y);
        ba[i]=mp(x,y);
    }
    for(int i=1;i<=m;i++){
        scanf("%lld%lld",&x,&y);
        so[i]=mp(x,y);
    }
    for(int i=1;i<=e;i++){
        scanf("%lld%lld",&x,&y);
        g[x].push_back(p2(ba[y],y));
        g[y].push_back(p2(ba[x],x));
        ed[i]=mp(x,y);
    }
    for(int i=1;i<=n;i++){
        if(!g[i].empty()){
            o = ba[i];
            sort(g[i].begin(),g[i].end(),cmpp2);
            for(int j=0;j<g[i].size();j++){
                //printf("i=%lld,g[i][%lld].id = %lld,(%lld,%lld)\n",i,j,g[i][j].id,g[i][j].v.fi,g[i][j].v.se);
                int u = g[i][j].id;
                int w = g[i][(j-1+g[i].size())%(g[i].size())].id;
                int v = i;
                G[u*101+v].push_back(v*101+w);
                //printf("add edge u=%lld,v=%lld,w=%lld\n",u,v,w);
            }
        }
    }
    
    for(int i=1;i<=e;i++){
        pii M = mp((ba[ed[i].fi].fi+ba[ed[i].se].fi),(ba[ed[i].fi].se + ba[ed[i].se].se));
        for(int j=1;j<=m;j++){
            bool f=1;
            for(int k=1;k<=e;k++){
                if(k == i)continue;
                if(spi(M,so[j]*2,ba[ed[k].fi]*2,ba[ed[k].se]*2)){
                    f=0;
                    //printf("j=%lld,i=%lld,intersect with k=%lld\n",j,i,k);
                }
            }
            if(f){
                // /printf("i=%d,j=%d,reachable\n",i,j);
                pii u = ba[ed[i].fi],v = ba[ed[i].se],p = so[j];
                if(Cross(v-u,p-u)>0){
                    reach[ed[i].fi*101+ed[i].se]=1;
                    //printf("reach %lld,%lld\n",ed[i].fi,ed[i].se);
                }
                else{
                    reach[ed[i].se*101+ed[i].fi]=1;
                    //printf("reach %lld,%lld\n",ed[i].se,ed[i].fi);
                }
            }
        }
    }
    
    for(int i=0;i<=11000;i++){
        if(reach[i]){
            dfs(i);
        }
    }
    for(int i=1;i<=e;i++){
        if(reach[ed[i].se*101+ed[i].fi] || reach[ed[i].fi*101+ed[i].se])printf("1");
        else printf("0");
    }
}

