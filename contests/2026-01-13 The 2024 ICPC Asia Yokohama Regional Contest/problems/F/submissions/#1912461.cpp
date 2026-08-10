#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
struct p2{
    double x,y;
    p2(double x,double y):x(x),y(y){}
    friend p2 operator + (p2 a,p2 b){return p2(a.x+b.x,a.y+b.y);}
    friend p2 operator - (p2 a,p2 b){return p2(a.x-b.x,a.y-b.y);}
    friend p2 operator * (p2 a,double p){return p2(a.x*p,a.y*p);}
    friend p2 operator / (p2 a,double p){return p2(a.x/p,a.y/p);}
};
double Dot(p2 a,p2 b){
    return a.x*b.x+a.y*b.y;
}
double Length(p2 a){
    return sqrtl(Dot(a,a));
}
p2 Rotate(p2 A,double rad){
    return p2(A.x*cosl(rad)-A.y*sinl(rad),A.x*sinl(rad)+A.y*cosl(rad));
}

vector<p2> st,p;

void getCCI(double ra,p2 a,double rb,p2 b){
    //printf("CCI ra=%.10Lf,%.10Lf,%.10Lf %.10Lf,%.10Lf\n",ra,a.x,a.y,b.x,b.y);
    
    p2 v = b-a;
    p2 u = v/Length(v)*ra;
    if(ra + rb < Length(v))return;
    double ang1 = acosl((Dot(v,v) + ra*ra - rb*rb)/2.0/Length(v)/ra);
    //cout << ang1 << endl;
    p2 A = Rotate(u,ang1)+a;
    p2 B = Rotate(u,-ang1)+a;
    p.push_back(A);
    p.push_back(B);
    //printf("CCI return %.10Lf,%.10Lf %.10Lf,%.10Lf\n",A.x,A.y,B.x,B.y);
}
void getCRI(double ra2,p2 A,int a,int b,int c){
    vector<p2> ret;
    if(A.x*A.x <= ra2){
        p2 u = p2(0,A.y);
        p2 t = p2(0,sqrt(ra2-A.x*A.x));
        ret.push_back(u+t);
        ret.push_back(u-t);
    }
    if(A.y*A.y <= ra2){
        p2 u = p2(A.x,0);
        p2 t = p2(sqrt(ra2-A.y*A.y),0);
        ret.push_back(u+t);
        ret.push_back(u-t);
    }
    
    A.x -= b;A.y -= a;
    p2 ofs = p2(b,a);
    
    if(A.x*A.x <= ra2){
        p2 u = p2(0,A.y);
        p2 t = p2(0,sqrt(ra2));
        ret.push_back(u+t+ofs);
        ret.push_back(u-t+ofs);
    }
    if(A.y*A.y <= ra2){
        p2 u = p2(A.x,0);
        p2 t = p2(sqrt(ra2),0);
        ret.push_back(u+t+ofs);
        ret.push_back(u-t+ofs);
    }
    
    
    for(p2 v:ret){
        if(v.y >= 0 && v.y <= a && v.x >= 0 && v.x <= b){
            p.push_back(v);
        }
    }
    
}
const double eps = 1e-12;

bool check(int a,int b,int c,double r2){
    //printf("check %.10Lf\n",r2);
    st.clear();p.clear();
    st.push_back(p2(-c,a));
    st.push_back(p2(0,c+a));
    st.push_back(p2(b+c,a+b));
    st.push_back(p2(-a,-c));
    
    for(int i=0;i<=3;i++){
        for(int j=i+1;j<=3;j++){
            getCCI(sqrt(r2),st[i],sqrt(r2),st[j]);
        }
        getCRI(r2,st[i],a,b,c);
    }
    p.push_back(p2(0,0));
    for(p2 u:p){
        
        if(u.x < -eps || u.y < -eps || u.x > b+eps || u.y > a+eps){
            continue;
        }
        
        //printf("found intersection %.10LF,%.10LF\n",u.x,u.y);
        
        bool f=1;
        for(int i=0;i<=3;i++){
            if(Dot(u-st[i],u-st[i]) < r2-eps){
                f=0;
            }
        }
        if(f)return 0;
        
    }
    //printf("failed\n");
    return 1;
    
    
    
}
double solve(int a,int b,int c){
    double L=1,R=(a+b)*(a+b) + (max(a,b)+c)*(max(a,b)+c),M;
    while(R-L > eps){
        M = (L+R)/2.0;
        if(check(a,b,c,M)){
            R = M;
        }
        else{
            L = M;
        }
    }
    return L;
}
signed main(){
    int a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    if(a>b)swap(a,b);
    if(b>c)swap(b,c);
    if(a>b)swap(a,b);
    if(b>c)swap(b,c);
    printf("%.12Lf\n",sqrtl(solve(a,b,c)));
}
