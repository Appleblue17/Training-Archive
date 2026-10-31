#include <bits/stdc++.h>
using namespace std;
#define OUT(t) putchar('0'+t)
const int N=440;
int n,x[3],y[3];

#define v2 p2

struct p2{
    double x,y;
    p2(double x=0,double y=0):x(x),y(y){}
};

v2 operator + (v2 a,v2 b){return v2(a.x+b.x,a.y+b.y);}
v2 operator - (v2 a,v2 b){return v2(a.x-b.x,a.y-b.y);}

p2 CSO(p2 P1,p2 P2,p2 P3){
    double Bx = P2.x - P1.x, By = P2.y - P1.y;
    double Cx = P3.x - P1.x, Cy = P3.y - P1.y;
    double D = 2*(Bx*Cy -By*Cx);
    double cx = (Cy*(Bx*Bx+By*By) - By*(Cx*Cx+Cy*Cy))/D + P1.x;
    double cy = (Bx*(Cx*Cx+Cy*Cy) - Cx*(Bx*Bx+By*By))/D + P1.x;
    return p2(cx,cy);
}

void solve(){
    
}


signed main(){
    for(x[0]=-10;x[0]<=10;x[0]++){
        for(x[1]=-10;x[1]<=10;x[1]++){
            for(y[0]=-10;y[0]<=10;y[0]++){
                for(y[1]=-10;y[1]<=10;y[1]++){
                    for(y[2]=-10;y[2]<=10;y[2]++){
                        x[2]=1-x[0]-x[1];
                        p2 G = p2(1.0/3.0,(y[0]+y[1]+y[2])/3.0);
                        p2 O = CSO(p2(x[0],y[0]),p2(x[1],y[1]),p2(x[2],y[2]));
                        /*if(rand()%1000==0){
                            printf("%d %d %d %d\n",G.x,G.y,O.x,O.y);
                        }*/
                        if(O.x == 1.0/3.0){
                            printf("%lf %lf %lf %lf\n",G.x,G.y,O.x,O.y);
                            printf("%d %d %d %d %d %d\n",x[0],y[0],x[1],y[1],x[2],y[2]);
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
