#include <bits/stdc++.h>
using namespace std;
//#define double long double
#define v2 p2
const double eps = 1e-8;
int dcmp(double x){return fabs(x)<eps?0:(x<0?-1:1);}

struct p2{
    double x,y;
    p2(double x=0.0,double y=0.0):x(x),y(y){}
    friend v2 operator + (const v2& A,const v2& B){return v2(A.x+B.x,A.y+B.y);}
    friend v2 operator - (const v2& A,const v2& B){return v2(A.x-B.x,A.y-B.y);}
    friend v2 operator * (const v2& A,const double& p){return v2(A.x*p,A.y*p);}
};

struct l2 {  
    p2 P;    //直线上一点  
    v2 dir; //方向向量(半平面交中该向量左侧表示相应的半平面)  
    double ang; //极角，即从x正半轴旋转到向量dir所需要的角（弧度）  
  
    l2() { }  //构造函数  
    //l2(const l2& L): P(L.P), dir(L.dir), ang(L.ang) { }  别抄
    l2(const p2& P, const v2& dir): P(P), dir(dir) { ang = atan2(dir.y, dir.x); }  
  
    bool operator < (const l2& L) const { //极角排序  
        return ang < L.ang;  
    }  
  
    p2 point(double t) { return P + dir*t; }  
};



double Dot(const v2& A,const v2& B){
    return A.x * B.x + A.y * B.y;
}
double Length(v2 A){return sqrt(Dot(A,A));}
double Cross(v2 A,v2 B){return A.x*B.y - A.y * B.x;}


bool ison(const p2& P,const p2& A,const p2& B){
    return dcmp(Cross(A-P,B-P))==0 && dcmp(Dot(A-P,B-P))<=0;
}

bool Segment(const p2& a1,const p2& a2,const p2& b1,const p2& b2){
    //printf("S %.5lf %.5lf %.5lf %.5lf %.5lf %.5lf %.5lf %.5lf\n",a1.x,a1.y,a2.x,a2.y,b1.x,b1.y,b2.x,b2.y);
    if(ison(a1,b1,b2)||ison(a2,b1,b2)||ison(b1,a1,a2)||ison(b2,a1,a2))return 1;
    double c1 = Cross(a2-a1,b1-a1),c2 = Cross(a2-a1,b2-a1);
    double c3 = Cross(b2-b1,a1-b1),c4 = Cross(b2-b1,a2-b1);
    //printf("return %d\n",dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}

p2 Getl2Intersection(const l2& A, const l2& B) {  
    v2 u = A.P - B.P;  
    double t = Cross(B.dir, u) / Cross(A.dir, B.dir);  
    return A.P + A.dir*t;  
}



p2 A,B;


double H;

signed main(){
    int t1,t2,t3,t4,t5;
    scanf("%d%d%d%d%d",&t1,&t2,&t3,&t4,&t5);
    A = p2(t1,t2);B = p2(t3,t4);H=t5;
    scanf("%d%d%d%d%d",&t1,&t2,&t3,&t4,&t5);
    v2 U=p2(),V=p2();
    p2 K;
    double D,ans=1e9;
    for(int i=1;i<=8;i++){
        if(i%2==1){
            B = B+V*2;
            A = A+U*2;
            U = (B-A)*0.5;
            D = sqrt(Dot(U,U)*2+H*H);
            K = A;
        }
        else{
            V = v2(-U.y,U.x);
            K = A + U + V*(sqrt(Dot(U,U)+H*H)/sqrt(Dot(U,U)));
            D = 0;
        }
        //printf("A=(%.5lf,%.5lf),B=(%.5lf,%.5lf),D=%.5lf,K=(%.5lf,%.5lf)\n",A.x,A.y,B.x,B.y,D,K.x,K.y);
        double h,d;p2 a,b,u,v,k;
        a = p2(t1,t2);b = p2(t3,t4);h=t5;
        u=p2();v=p2();
        for(int j=1;j<=8;j++){
            double tans;
            bool f=1;
            if(j%2==1){
                b = b+v*2;
                a = a+u*2;
                u = (b-a)*0.5;
                d = sqrt(Dot(u,u)*2+h*h);
                k = a;
                tans = Length(K-k)+D+d;
            }
            else{
                v = v2(-u.y,u.x);
                k = a+u+v*(sqrt(Dot(u,u)+h*h)/sqrt(Dot(u,u)));
                d=0;
                
                tans = Length(K-k)+D+d;
                if(!Segment(K,k,a,b))f=0;
                
                
            }
            if(i%2==0){
                if(!Segment(K,k,A,B))f=0;
            }
            //printf("f=%d\n",(int)f);
            if(f && i%2==0 && j%2==0){
                p2 M1 = Getl2Intersection(l2(K,K-k),l2(A,A-B));
                p2 M2 = Getl2Intersection(l2(K,K-k),l2(a,b-a));
               // printf("%.10lf %.10lf %.10lf %.10lf\n",M1.x,M1.y,M2.x,M2.y);
                if(dcmp(Length(M1-K)-Length(M2-K))>0)f=0;
            }
            //printf("a=(%.5lf,%.5lf),b=(%.5lf,%.5lf),d=%.5lf,k=(%.5lf,%.5lf)\n",a.x,a.y,b.x,b.y,d,k.x,k.y);
            //printf("i=%d,j=%d,f=%d,tans=%.5lf\n",i,j,f,tans);
            if(f)ans = min(ans,tans);
        }
    }
    printf("%.9lf",ans);
}
