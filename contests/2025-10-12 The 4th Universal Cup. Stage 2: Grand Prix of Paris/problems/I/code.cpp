#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int mo = 998244353;
const int N=2e6+5;
int T,n,k,a[N][2],id[N];

#define v2 p2

struct p2{
    double x,y;
    p2(double x=0,double y=0):x(x),y(y){}
    friend v2 operator -(const p2& a,const p2& b){return v2(a.x-b.x,a.y-b.y);}
    friend v2 operator +(const p2& a,const p2& b){return v2(a.x+b.x,a.y+b.y);}
    friend v2 operator *(const p2& a,const double d){return v2(a.x*d,a.y*d);}
    friend v2 operator /(const p2& a,const double d){return v2(a.x/d,a.y/d);}
};

const double pi = acosl(-1);



struct l2{
    p2 P;
    v2 dir;
    double ang;
    l2(const p2& P,const v2& dir):P(P),dir(dir){ang = atan2(dir.y,dir.x);}
};

const double eps = 1e-5;

int dcmp(double x){
    return fabs(x)<eps?0:(x<0?-1:1);
}

double Dot(p2 a,p2 b){
    return a.x*b.x+a.y*b.y;
}

__float128 Cross(p2 a,p2 b){
    return (__float128)a.x*b.y-a.y*b.x;
}

p2 gp(const p2& P,const l2& L){return L.P + L.dir*(Dot(L.dir,P-L.P)/Dot(L.dir,L.dir));}

bool spi(const p2& a1,const p2& a2,const p2& b1,const p2& b2){
    __float128 c1 = Cross(a2-a1,b1-a1),c2 = Cross(a2-a1,b2-a1);
    __float128 c3 = Cross(b2-b1,a1-b1),c4 = Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}

//p2 segs[30][2];

void solve(){
    scanf("%lld",&n);
    vector<p2> p;
    //p2 O;
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        p.push_back(p2(x,y));
    }
    p.push_back(p[0]);
    //O = p[0];
    for(int i=n-2;i>=1;i--){
        l2 l = l2(p[i],p[i+1]-p[i]);
        
        for(int j=n;j>i+1;j--){
            p2 H = gp(p[j],l);
            p[j] = H+H-p[j];
        }
    }
    bool f=1;
    for(int i=1;i<=n-2;i++){
        p2 u=p[i],v=p[i+1];
        v2 d = v-u;
        u = u+d*(double)1e-5;
        v = v-d*(double)1e-5;
        if(!spi(p[n],p[0],u,v))f=0;
    }
    //for(int i=0;i<=n;i++){
        //printf("p[%lld]=(%.5Lf,%.5Lf)\n",i,p[i].x,p[i].y);
    //}
    if(f){
        printf("YES\n%.20Lf\n",atan2l(p[n].y-p[0].y,p[n].x-p[0].x)*(double)180.0/pi);
    }
    else{
        printf("NO\n");
    }
}

signed main(){
    scanf("%lld",&T);
    while(T--){
        solve();
    }
}
/*
p[0]=(0.00000,0.00000)
p[1]=(4.00000,0.00000)
p[2]=(5.00000,4.00000)
p[3]=(10.29412,1.17647)
p[4]=(11.29412,5.17647)
YES
24.6235647862
p[0]=(-809016994.00000,-587785252.00000)
p[1]=(309016994.00000,-951056516.00000)
p[2]=(1000000000.00000,0.00000)
p[3]=(2118033988.29036,-363271265.35746)
p[4]=(2809016994.85335,587785249.37366)
p[5]=(3927050982.59918,224513984.17372)
YES
9.7323013977
p[0]=(-1000000000.00000,0.00000)
p[1]=(-500000000.00000,-866025404.00000)
p[2]=(500000000.00000,-866025404.00000)
p[3]=(1000000000.00000,-1732050808.00000)
p[4]=(2000000000.18668,-1732050808.32334)
p[5]=(2499999999.81332,-2598076212.32334)
p[6]=(3500000000.00000,-2598076212.64668)
YES
-30.0000000124
*/
