#include <bits/stdc++.h>
const int N=210000;
typedef long long ll;

const long double eps = 1e-9;

typedef std::pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair
void solve(){
    int a,b,c,d;
    long double T,x,y,vx,x1,x2,vx1,vx2,yans,xans;
    scanf("%d%d%d%d",&a,&b,&c,&d);x=a;y=b;vx=c;
    scanf("%d%d%d%d",&a,&b,&c,&d);T = (b-a)/(long double)(c+d),yans = a+c*T;
    scanf("%d%d%d%d",&a,&b,&c,&d);x1=a;x2=b;vx1=c;vx2=d;
    
    if(c == 0 && d == 0){//
        long double pos = (x-x1 + vx*T);
        //printf("pos = %.5Lf\n",pos);
        for(int i=29;i>=0;i--){
            if(pos > (long double)(1<<i)*2*(x2-x1))pos -= (long double)(1<<i)*2*(x2-x1);
        }
        for(int i=29;i>=0;i--){
            if(pos < -(long double)(1<<i)*2*(x2-x1))pos += (long double)(1<<i)*2*(x2-x1);
        }
        while(pos > 2*(x2-x1))pos -= 2*(x2-x1);
        while(pos < 0)pos += 2*(x2-x1);
        //printf("pos = %.5Lf\n",pos);
        if(pos > (x2-x1)){
            pos = 2*(x2-x1)-pos;
        }
        printf("%.10Lf %.10Lf\n",x1+pos,yans);
        return;
    }
    while(T+eps>=0){
        //printf("In simulation,T = %.5lf,vx=%.5lf,x=%.5lf,x1=%.5lf,vx1=%.5lf,x2=%.5lf,vx2=%.5lf\n",T,vx,x,x1,vx1,x2,vx2);
        if(vx > 0){
            if(vx <= eps+vx2){
                xans = x + vx*T;
                printf("%.10LF %.10LF\n",xans,yans);
                return;
            }
            long double t = (x2-x)/(vx-vx2);
            //printf("%.5lf\n",t);
            if(vx <= eps+vx2 || t+eps>=T){
                xans = x + vx*T;
                printf("%.10LF %.10LF\n",xans,yans);
                return;
            }
            //x += t*vx;
            x2 += t*vx2;
            x1 -= t*vx1;
            x = x2;
            vx = -vx;
            T -= t;
        }
        else{
            if(vx1+vx+eps >= 0){
                xans = x + vx*T;
                printf("%.10LF %.10LF\n",xans,yans);
                return;
            }
            long double t = (x-x1)/(-vx-vx1);
            //printf("%.5lf\n",t);
            if(vx1+vx+eps >= 0 || t+eps>=T){
                xans = x + vx*T;
                printf("%.10LF %.10LF\n",xans,yans);
                return;
            }
            //x += t*vx;
            x2 += t*vx2;
            x1 -= t*vx1;
            x = x1;
            vx = -vx;
            T -= t;
        }
    }
    //printf("???");
}
signed main(){
    int T;
    scanf("%d", &T);
    while(T--){
        solve();
        
    }
    
}


