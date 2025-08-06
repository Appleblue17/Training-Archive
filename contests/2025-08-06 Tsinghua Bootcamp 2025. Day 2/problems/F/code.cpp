#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define double long double
const int N=1e6+5;
int n;

const double eps = 1e-9;
int dcmp(double x){return fabs(x)<eps? 0:(x<0?-1:1);}
#define Vector Point
struct Point{
    double x,y;
    Point(double x=0.0,double y=0.0):x(x),y(y){}
    friend Vector operator + (const Point& A, const Point& B){return Vector(A.x+B.x,A.y+B.y);}
    friend Vector operator - (const Point& A, const Point& B){return Vector(A.x-B.x,A.y-B.y);}
    friend Vector operator * (const Vector& A,const double& p){return Vector(A.x*p,A.y*p);}
    friend Vector operator / (const Vector& A,const double& p){return Vector(A.x/p,A.y/p);}
}st,ed,p[N],gret;
double offset=0;
struct Circle{
    Point c;
    double r;
    
    Circle(){}
    Circle(const Point& c,const double& r):c(c),r(r){}
} o;
struct jump{
    double len,ang,x,y;
    int id;
} a[N];
bool cmp1(jump a,jump b){
    return a.len > b.len;
}
bool cmp2(jump a,jump b){
    return a.id < b.id;
}

double Dot(const Vector& A,const Vector& B){return A.x*B.x+A.y*B.y;}
double Length(const Vector& A){return sqrt(Dot(A,A));}
Vector Rotate(const Vector& A, const double& rad){
    return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}
bool GetCircleIntersection(const Circle& A,const Circle& B){
    double d = Length(A.c-B.c);
    //if(dcmp(d)==0)return false;
    double sum = A.r + B.r;
    double sub = fabs(A.r - B.r);
    if(dcmp(d-sub)<=0)return false;
    double ang1 = acos((A.r*A.r + d*d - B.r*B.r)/(2.0*A.r*d));
    Vector v = (B.c - A.c) / d * A.r;
    gret = A.c + Rotate(v,ang1);
    return true;
}
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    st = Point(x,y);
    scanf("%d%d",&x,&y);
    ed = Point(x,y);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int u;
        scanf("%d",&u);
        a[i].len=u;
        a[i].id=i;
    }

    a[n+1].len = Length(ed-st);
    a[n+1].id = n+1;
    sort(a+1,a+n+2,cmp1);
    o = Circle(Point(0,0),a[1].len);
    Point cur = Point(0,0);
    bool f=0;

    for(int i=2;i<=n+1;i++){
        if(dcmp(a[i].len)==0){
            a[i].x = a[i].y = 0;
            continue;
        }
        Circle A = Circle(cur,a[i].len);
        if(GetCircleIntersection(o,A)){
            a[i].x = gret.x-cur.x;
            a[i].y = gret.y-cur.y;
            a[i].ang = atan2(a[i].y,a[i].x);
            f=1;
            //cout << '*' << endl;
        }
        else{
            a[i].ang=0;
            a[i].x = a[i].len;
            a[i].y = 0;
        }
        cur.x += a[i].x;
        cur.y += a[i].y;
        //cout << cur.x << endl << cur.y << endl;
    }
    
    if(dcmp(Length(cur-Point(0,0))-a[1].len) != 0){
        printf("Impossible\n");
        return 0;
    }

    a[1].x = -cur.x;
    a[1].y = -cur.y;
    a[1].ang = atan2(a[1].y,a[1].x);
    Point tt = st-ed;
    offset = atan2(tt.y,tt.x);
    int ttt=0;
    for(int i=1;i<=n+1;i++){
        if(a[i].id == n+1){
            ttt=i;
        }
    }
    offset = a[ttt].ang - offset;
    offset = -offset;
    //for(int i=1;i<=n+1;i++){
    //    printf("a[%d],id=%d:(%.5lf,%.5lf)\n",i,a[i].id,a[i].x,a[i].y);
    //}
    for(int i=1;i<=n+1;i++){
        Point tt = Point(a[i].x,a[i].y);
        tt = Rotate(tt,offset);
        a[i].x = tt.x;a[i].y = tt.y;
    }
    //for(int i=1;i<=n+1;i++){
    //    printf("a[%d],id=%d:(%.5lf,%.5lf)\n",i,a[i].id,a[i].x,a[i].y);
    //}
    sort(a+1,a+n+2,cmp2);
    cur = st;
    printf("Possible\n");
    for(int i=1;i<=n;i++){
        cur.x += a[i].x;
        cur.y += a[i].y;
        printf("%.10Lf %.10Lf\n",cur.x,cur.y);
        if(dcmp(Length(Point(a[i].x,a[i].y)) - a[i].len) != 0){
            printf("length wrong\n");
        }
    }
    if(dcmp(Length(ed - cur)) != 0){
        printf("destination wrong\n");
    }
}