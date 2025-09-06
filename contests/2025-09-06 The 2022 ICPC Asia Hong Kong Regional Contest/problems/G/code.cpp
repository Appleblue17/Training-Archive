#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int N=33,mod=998244353,inv2=(mod+1)/2;
int T,n,ans1,ans2;
double l1,l2,al,be;
const double pi = acos(-1);
double area1(double r,double theta){
    return r*r*theta/(2.0);
}
double h(double a,double b,double c){
    double p = (a+b+c)/2.0;
    return sqrt((p-a)*(p-b)*(p-c)*p);
}
void solve(){
    int t1,t2,t3,t4;
    scanf("%lld%lld%lld%lld",&t1,&t2,&t3,&t4);
    l1 = t1;l2 = t2;al = t3/180.0*pi;be = t4/180.0*pi;
    double A = area1(l1+l2,al)+area1(l2,be);
    //printf("A=%.10Lf\n",A);
    if(be <= pi/2.0){
        printf("%.10Lf\n",2*A);
        return;
    }
    double d = l1*cos(be-pi/2.0);
    double s=0;
    if(l1*sin(be-pi/2.0)<=l2){//cunzai
        if(be-pi/2 < 2*al){
            //cout << "1.1" << endl;
            s = d*d*tan(be-pi/2.0)/2.0-(be-pi/2.0)*d*d/2.0;
        }
        else{
            //cout << "1.2" << endl;
            //cout << d << endl;
            s = d*d*tan(be-pi/2.0)/2.0-area1(d,2*al)-d*d*tan(be-pi/2.0-2.0*al)/2.0;
            //cout << d*d*tan(be-pi/2.0)/2.0 << ' ' << area1(d,al) << ' ' << d*d*tan(be-pi/2.0-2.0*al)/2.0 << endl;
        }
    }
    else{
        double theta0,d0;
        double tt = sqrtl(1.0-l2*l2/l1/l1);
        //theta0 = acos(tt);
        //theta0 = pi/2 - atan2l(tt,sqrtl(1-tt*tt));
        //printf("%.20Lf\n",pi);
        //d0 = (2*l1*cosl(theta0) - sqrtl(4*l1*l1*cosl(theta0)*cosl(theta0)-4*l1*l1+4*l2*l2))/2.0;
        //cout << l2 << ' ' << l1 << endl;
        d0 = sqrtl(l1*l1+l2*l2-2*l1*l2*cos(pi-be));
        theta0 = (l1*l1+d0*d0-l2*l2)/2.0/l1/d0;
        theta0 = acos(theta0);
        double ss = h(d0,l1,l2);
        //cout << theta0 << ' ' << d0 << endl;
        if(theta0 < 2*al){
            //cout << "2.1" << endl;
            s = ss - area1(d0,theta0);
        }
        else{
            //cout << "2.2" << endl;
            double a = d0 / sin(pi-be+2*al) * sin(theta0 - 2*al);
            double b = d0 / sin(pi-be+2*al) * sin(be - theta0);
            //cout << d0 << ' ' << a << ' ' << b << endl;
            s = ss - area1(d0,2*al) - h(a,b,d0);
        }
    }
    printf("%.10Lf\n",2*(s+A));
}
signed main(){
    scanf("%d",&T);
    while(T--){
        solve();
    }
}
