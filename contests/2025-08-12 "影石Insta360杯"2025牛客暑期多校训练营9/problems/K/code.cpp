#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=40000;
typedef long long ll;
#define int long long
#define double long double
int n,X[N],Y[N],R[N];
double h;
inline double findh(double x,double y,int i){
    x = x-X[i];
    y = y-Y[i];
    double t = R[i]-x*x-y*y;
    if(t<0)return x*x+y*y;
    else return -sqrtl(t);
}
double dx,dy;
inline void findg(double x,double y,int i){
    double t = R[i]-(x-X[i])*(x-X[i])-(y-Y[i])*(y-Y[i]);
    if(t<0)return;
    dx = (x-X[i]);
    dy = (y-Y[i]);
}
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&X[i],&Y[i],&R[i]);
    }
    double x=0,y=0,lx=0,ly=0,step=100,temp=0.99;
    double ldx=0,ldy=0,lldx=0,lldy=0,alpha=0.9;
    int cnt=0;
    //bool f=1;
    while(step > 1e-9){
        cnt++;
        step *= temp;
        h=-1e9;int id=0;
        for(int i=1;i<=n;i++){
            double fh = findh(x,y,i);
            if(h<fh){
                h = fh;
                id=i;
            }
        }
        if(h>0){
            x = lx;
            y = ly;
            ldy = lldy;
            ldx = lldx;
            continue;
        }
        findg(x,y,id);
        lx = x;
        ly = y;
 
        dx += alpha*ldx;
        dy += alpha*ldy;
        lldy = ldy;
        lldx = ldx;
        ldy = dy;
        ldx = dx;
        //printf("x=%.10Lf,y=%.10Lf,dx=%.10Lf,dy=%.10Lf\n",x,y,dx,dy);
        double mo = sqrtl(dx*dx+dy*dy)+1e-9;
        //cout << mo << endl;
        dx /= mo;
        dy /= mo;
        x -= dx*step;
        y -= dy*step;
         
    }
    //cout << cnt << endl;
        h=-1e9;int id=0;
        for(int i=1;i<=n;i++){
            //cout << findh(x,y,i) << endl;
            if(h<findh(x,y,i)){
                h = findh(x,y,i);
                 
                id=i;
            }
        }
    //printf("%.10lf %.10lf %.10lf",x,y,h);
    printf("%.10Lf %.10Lf %.10Lf",x,y,h);
}
