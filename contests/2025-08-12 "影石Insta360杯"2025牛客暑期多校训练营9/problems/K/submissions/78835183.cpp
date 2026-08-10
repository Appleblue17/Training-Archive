#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=40000;
typedef long long ll;
#define int long long
//#define double long double
int n,X[N],Y[N],R[N];
double rx,ry;
bool check(double h){
    double l = -128,r=128,m;
    int C=60;
    while(C--){
        m=(l+r)*0.5;
        int mnid,mxid;
        double mn=128,mx=-128;
        bool f=0;
        for(int i=1;i<=n;i++){
            double tt = R[i]-h*h-(m-X[i])*(m-X[i]);
            //cout << tt << endl;
            if(tt < 0){
                if(X[i] < m)r=m;
                else l=m;
                f=1;
                break;
            }
            double ansr = Y[i]+sqrt(tt),ansl = Y[i]-sqrt(tt);
            //printf("h=%.5lf,m=%.5lf,tt=%.5lf,ansl=%.5lf,ansr=%.5lf\n",h,m,tt,ansl,ansr);
            if(mn > ansr){
                mn = ansr;
                mnid = i;
            }
            if(mx < ansl){
                mx = ansl;
                mxid = i;
            }
        }
        if(f)continue;
        rx = m;ry = (mx+mn)*0.5;
        if(mx < mn){
            return 1;
        }
        //printf("h=%.5lf,m=%.5lf,mxid=%lld,mnid=%lld\n",h,m,);
        double zx = X[mnid] + (1.0*sqrt(R[mnid]-h*h))/(1.0*sqrt(R[mnid]-h*h)+sqrt(R[mxid]-h*h))*(1.0*X[mxid]-X[mnid]);
        if(zx < m)r = m;
        else l = m;
    }
    return 0;
}
signed main(){
    //freopen("108306K.in","r",stdin);
    //freopen("108306K.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&X[i],&Y[i],&R[i]);
    }
    double L=-200,R=-1,M;
    int C=60;
    while(C--){
        M=(L+R)*0.5;
        if(check(M))R=M;
        else L=M;
    }
    printf("%.10lf %.10lf %.10lf\n",rx,ry,M);
}
