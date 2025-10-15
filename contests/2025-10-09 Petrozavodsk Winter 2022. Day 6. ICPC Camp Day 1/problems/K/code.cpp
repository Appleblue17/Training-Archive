#include<bits/stdc++.h>
using namespace std;
int X,Y,a[30][30];
bool operated=0;
void interact(int x,int y){
    if(operated)return;
    if(a[x+10][y+10])return;
    printf("%d %d\n",x,y);fflush(stdout);
    
    a[x+10][y+10]=1;
    scanf("%d%d",&X,&Y);
    //printf("input: %d,%d\n",X,Y);
    operated = 1;
}
typedef pair<int,int> pii;
#define fi first
#define se second 
#define mapa make_pair
vector<pii> bo,bo2,bo3;
int dis(pii a,pii b){
    pii c = mapa(b.fi-a.fi,b.se-a.se);
    if(c.fi * c.se < 0){
        // manhattan
        return abs(c.fi)+abs(c.se);
    }
    else{
        return max(abs(c.fi),abs(c.se));
    }
}
vector<pii> nei(pii a){
    vector<pii> ret;
    ret.push_back(mapa(a.fi+1,a.se));
    ret.push_back(mapa(a.fi+1,a.se+1));
    ret.push_back(mapa(a.fi,a.se+1));
    ret.push_back(mapa(a.fi-1,a.se));
    ret.push_back(mapa(a.fi-1,a.se-1));
    ret.push_back(mapa(a.fi,a.se-1));
    return ret;
}
pii U;
bool cmp(pii a,pii b){

}
int main(){
    //freopen("2611.out","w",stdout);
    //interact(9,9);
    scanf("%d%d",&X,&Y);
    pii S = mapa(0,0);
    for(int i=0;i<=9;i++){
        bo.push_back(mapa(i,9));
    }
    for(int i=8;i>=0;i--){
        bo.push_back(mapa(9,i));
    }
    for(int i=8;i>=0;i--){
        bo.push_back(mapa(i,i-9));
    }
    for(int i=1;i<=9;i++){
        bo.push_back(mapa(-i,-9));
    }
    for(int i=-8;i<=0;i++){
        bo.push_back(mapa(-9,i));
    }
    for(int i=1;i<9;i++){
        bo.push_back(mapa(-9+i,i));
    }
    for(int i=0;i<bo.size();i+=2){
        bo2.push_back(bo[i]);
        //printf("bo2 push_back %d %d\n",bo[i].fi,bo[i].se);
    }
    while(1){
        operated = 0;
        if((X == 0 && Y == 7)){
            interact(1,9);
            interact(-1,8);
        }
        if(operated)continue;
        if(X == 7 && Y == 0){
            interact(9,1);
            interact(8,-1);
        }
        
        if(X == -7 && Y == -7){
            interact(-9,-8);
            interact(-8,-9);
        }
        //if(operated)continue;
        U = mapa(X,Y);
        if(dis(U,S) >= 8){
            //printf("*** immediate reaction ***\n");
            vector<pii> ne = nei(mapa(X,Y));
            for(pii u:ne){
                if(dis(u,S)==9){
                    interact(u.fi,u.se);
                    //printf("try nei %d,%d\n",u.fi,u.se);
                }
            }
        }
        //if(operated)continue;
        U = mapa(X,Y);
        

        pii l=mapa(0,0),r;
        int lid=0,rid=0,n = bo2.size();
        if(X == Y && X > 0)l = mapa(8,9);
        if(X == Y && X < 0)l = mapa(-9,-9);
        if(Y == 0 && X < 0)l = mapa(-9,-1);
        if(Y == 0 && X > 0)l = mapa(9,0);
        if(X == 0 && Y <= 0)l = mapa(1,-8);
        if(X == 0 && Y > 0)l = mapa(0,9);
        if(l == mapa(0,0)){
            int mindis = 100;
            for(pii u:bo2){
                mindis = min(mindis,dis(u,U));
            }
            bo3.clear();
            for(pii u:bo2){
                if(dis(u,U)==mindis){
                    bo3.push_back(u);
                }
            }
            int n3 = bo3.size();
            int j = n3/2;
            l = bo3[j];
        }
        //printf("U = %d,%d,l = %d,%d\n",U.fi,U.se,l.fi,l.se);
        for(int i=0;i<n;i++)if(bo2[i]==l)lid = i;
        rid = (lid+1)%n;
        //printf("lid = %d\n",lid);
        for(int i=0;i<n;i++){
            if(i%2==0){
                interact(bo2[lid].fi,bo2[lid].se);
                lid=(lid-1+n)%n;
            }
            else{
                interact(bo2[rid].fi,bo2[rid].se);
                rid=(rid+1)%n;
            }
        }
        //final filling work
        for(int i=0;i<bo.size();i++){
            interact(bo[i].fi,bo[i].se);
        }
        for(int i=-9;i<=9;i++){
            for(int j=-9;j<=9;j++){
                if(dis(mapa(i,j),S) <= 9 && mapa(i,j)!=U){
                    interact(i,j);
                }
            }
        }
        if(!operated)return 0;
    }
}
