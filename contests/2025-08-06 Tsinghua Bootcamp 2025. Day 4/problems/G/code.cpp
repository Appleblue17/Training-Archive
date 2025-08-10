#include<bits/stdc++.h>
using namespace std;
int n,m,x1,y1_,x2,y2,x3,y3,X1,Y1_,X2,Y2,C1,C2;
int dist(int x1,int y1_,int x2,int y2){
    return fabs(x1-x2)+fabs(y1_-y2);
}
bool within(int l,int r,int x){
    if(l < r){
        return l<=x && x<=r;
    }
    else{
        return r<=x && x<=l;
    }
}
int ask(int x,int y){
    int ret=0;
    printf("ask %d %d\n",x,y);fflush(stdout);
    scanf("%d",&ret);
    return ret;
}
const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void sol(int x1,int y1_,int x2,int y2,int col1,int col2){
    if(dist(x1,y1_,x2,y2)==2){
        if(x1 != x2 && y1_ != y2){
            ask(x1,y2);
            ask(x2,y1_);
        }
        else{
            if(x1 == x2){
                ask(x1,(y1_+y2)/2);
                if(x1 != 1)ask(x1-1,(y1_+y2)/2);
                else ask(x1+1,(y1_+y2)/2);
            }
            else{//y1_ == y2;
                ask((x1+x2)/2,y1_);
                if(y1_ != 1)ask((x1+x2)/2,y1_-1);
                else ask((x1+x2)/2,y1_+1);
            }
        }
        printf("done\n");fflush(stdout);
        return;
    }
    int xu = (x1+x2)/2,yu = (y1_+y2)/2;
    if(dist(x1,y1_,xu,yu)%2==0){
        int nc = ask(xu,yu);
        if(nc != col1)sol(x1,y1_,xu,yu,col1,nc);
        else sol(x2,y2,xu,yu,col2,nc);
    }
    else{
        for(int d=0;d<4;d++){
            int xv = xu+dir[d][0],yv = yu+dir[d][1];
            if(!within(x1,x2,xv))continue;
            if(!within(y1_,y2,yv))continue;
            if(xv == x1 && yv == y1_)continue;
            if(xv == x2 && yv == y2)continue;
            int nc = ask(xv,yv);
            if(nc != col1)sol(x1,y1_,xv,yv,col1,nc);
            else sol(x2,y2,xv,yv,col2,nc);
            break;
        }
    }
}
void solve(){
    scanf("%d%d%d%d%d%d%d%d",&n,&m,&x1,&y1_,&x2,&y2,&x3,&y3);
    if(dist(x1,y1_,x2,y2)%2==0){
        X1=x1;Y1_=y1_;X2=x2;Y2=y2;C1=1;C2=2;
    }
    if(dist(x1,y1_,x3,y3)%2==0){
        X1=x1;Y1_=y1_;X2=x3;Y2=y3;C1=1;C2=3;
    }
    if(dist(x3,y3,x2,y2)%2==0){
        X1=x3;Y1_=y3;X2=x2;Y2=y2;C1=3;C2=2;
    }
    sol(X1,Y1_,X2,Y2,C1,C2);
}
signed main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
}