#include <bits/stdc++.h>  
#define LL long long  
#define lson l, m, rt<<1  
#define rson m+1, r, rt<<1|1  
#define PI 3.1415926535897932384626  
#define CLEAR(name, init) memset(name, init, sizeof(name))  
const double eps = 1e-6;  
const int MAXN = (int)1e9 + 5;  
using namespace std;  
  
#define Vector Point  
  
#define ChongHe 0  
#define NeiHan 1  
#define NeiQie 2  
#define INTERSECTING 3  
#define WaiQie 4  
#define XiangLi 5  
  
int dcmp(double x) { return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1); }  
  
struct Point {  
    double x, y;  
  
    Point(const Point& rhs): x(rhs.x), y(rhs.y) { } //拷贝构造函数  
    Point(double x = 0.0, double y = 0.0): x(x), y(y) { }   //构造函数  
  
    friend istream& operator >> (istream& in, Point& P) { return in >> P.x >> P.y; }  
    friend ostream& operator << (ostream& out, const Point& P) { return out << P.x << ' ' << P.y; }  
  
    friend Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }  
    friend Vector operator - (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }  
    friend Vector operator * (const Vector& A, const double& p) { return Vector(A.x*p, A.y*p); }  
    friend Vector operator / (const Vector& A, const double& p) { return Vector(A.x/p, A.y/p); }  
    friend bool operator == (const Point& A, const Point& B) { return dcmp(A.x-B.x) == 0 && dcmp(A.y-B.y) == 0; }  
    friend bool operator < (const Point& A, const Point& B) { return A.x < B.x || (A.x == B.x && A.y < B.y); }  
  
    void in(void) { scanf("%lf%lf", &x, &y); }  
    void out(void) { printf("%lf %lf", x, y); }  
};  
  
struct Line {  
    Point P;    //直线上一点  
    Vector dir; //方向向量(半平面交中该向量左侧表示相应的半平面)  
    double ang; //极角，即从x正半轴旋转到向量dir所需要的角（弧度）  
  
    Line() { }  //构造函数  
    Line(const Line& L): P(L.P), dir(L.dir), ang(L.ang) { }  
    Line(const Point& P, const Vector& dir): P(P), dir(dir) { ang = atan2(dir.y, dir.x); }  
  
    bool operator < (const Line& L) const { //极角排序  
        return ang < L.ang;  
    }  
  
    Point point(double t) { return P + dir*t; }  
};  
  
typedef vector<Point> Polygon;  
  
struct Circle {  
    Point c;    //圆心  
    double r;   //半径  
  
    Circle() { }  
    Circle(const Circle& rhs): c(rhs.c), r(rhs.r) { }  
    Circle(const Point& c, const double& r): c(c), r(r) { }  
  
    Point point(double ang) const { return Point(c.x + cos(ang)*r, c.y + sin(ang)*r); } //圆心角所对应的点  
    double area(void) const { return PI * r * r; }  
};  
  
double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }  //点积  
double Length(const Vector& A){ return sqrt(Dot(A, A)); }  
double Angle(const Vector& A, const Vector& B) { return acos(Dot(A, B)/Length(A)/Length(B)); }  //向量夹角  
double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }    //叉积  
double Area(const Point& A, const Point& B, const Point& C) { return fabs(Cross(B-A, C-A)); }  
  
//三边构成三角形的判定  
bool check_length(double a, double b, double c) {  
    return dcmp(a+b-c) > 0 && dcmp(fabs(a-b)-c) < 0;  
}  
bool isTriangle(double a, double b, double c) {  
    return check_length(a, b, c) && check_length(a, c, b) && check_length(b, c, a);  
}  
  
//平行四边形的判定（保证四边形顶点按顺序给出）  
bool isParallelogram(Polygon p) {  
    if (dcmp(Length(p[0]-p[1]) - Length(p[2]-p[3])) || dcmp(Length(p[0]-p[3]) - Length(p[2]-p[1]))) return false;  
    Line a = Line(p[0], p[1]-p[0]);  
    Line b = Line(p[1], p[2]-p[1]);  
    Line c = Line(p[3], p[2]-p[3]);  
    Line d = Line(p[0], p[3]-p[0]);  
    return dcmp(a.ang - c.ang) == 0 && dcmp(b.ang - d.ang) == 0;  
}  
  
//梯形的判定  
bool isTrapezium(Polygon p) {  
    Line a = Line(p[0], p[1]-p[0]);  
    Line b = Line(p[1], p[2]-p[1]);  
    Line c = Line(p[3], p[2]-p[3]);  
    Line d = Line(p[0], p[3]-p[0]);  
    return (dcmp(a.ang - c.ang) == 0 && dcmp(b.ang - d.ang)) || (dcmp(a.ang - c.ang) && dcmp(b.ang - d.ang) == 0);  
}  
  
//菱形的判定  
bool isRhombus(Polygon p) {  
    if (!isParallelogram(p)) return false;  
    return dcmp(Length(p[1]-p[0]) - Length(p[2]-p[1])) == 0;  
}  
  
//矩形的判定  
bool isRectangle(Polygon p) {  
    if (!isParallelogram(p)) return false;  
    return dcmp(Length(p[2]-p[0]) - Length(p[3]-p[1])) == 0;  
}  
  
//正方形的判定  
bool isSquare(Polygon p) {  
    return isRectangle(p) && isRhombus(p);  
}  
  
//三点共线的判定  
bool isCollinear(Point A, Point B, Point C) {  
    return dcmp(Cross(B-A, C-B)) == 0;  
}  
  
//向量绕起点旋转  
Vector Rotate(const Vector& A, const double& rad) { return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad)); }  
  
//向量的单位法线(调用前请确保A 不是零向量)  
Vector Normal(const Vector& A) {  
    double len = Length(A);  
    return Vector(-A.y / len, A.x / len);  
}  
  
//两直线交点(用前确保两直线有唯一交点，当且仅当Cross(A.dir, B.dir)非0)  
Point GetLineIntersection(const Line& A, const Line& B) {  
    Vector u = A.P - B.P;  
    double t = Cross(B.dir, u) / Cross(A.dir, B.dir);  
    return A.P + A.dir*t;  
}  
  
//点到直线距离  
double DistanceToLine(const Point& P, const Line& L) {  
    Vector v1 = L.dir, v2 = P - L.P;  
    return fabs(Cross(v1, v2)) / Length(v1);  
}  
  
//点到线段距离  
double DistanceToSegment(const Point& P, const Point& A, const Point& B) {  
    if (A == B) return Length(P - A);  
    Vector v1 = B - A, v2 = P - A, v3 = P - B;  
    if (dcmp(Dot(v1, v2)) < 0) return Length(v2);  
    if (dcmp(Dot(v1, v3)) > 0) return Length(v3);  
    return fabs(Cross(v1, v2)) / Length(v1);  
}  
  
//点在直线上的投影  
Point GetLineProjection(const Point& P, const Line& L) { return L.P + L.dir*(Dot(L.dir, P - L.P)/Dot(L.dir, L.dir)); }  
  
//点在线段上的判定  
bool isOnSegment(const Point& P, const Point& A, const Point& B) {  
    //若允许点与端点重合，可关闭下面的注释  
    //if (P == A || P == B) return true;  
    // return dcmp(Cross(A-P, B-P)) == 0 && dcmp(Dot(A-P, B-P)) < 0;  
    return dcmp(Length(P-A) + Length(B-P) - Length(A-B)) == 0;  
}  
  
//线段相交判定  
bool SegmentProperIntersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {  
    //若允许在端点处相交，可适当关闭下面的注释  
    //if (isOnSegment(a1, b1, b2) || isOnSegment(a2, b1, b2) || isOnSegment(b1, a1, a2) || isOnSegment(b2, a1, a2)) return true;  
    double c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1);  
    double c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1, a2-b1);  
    return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;  
}  
  
//多边形的有向面积  
double PolygonArea(Polygon po) {  
    int n = po.size();  
    double area = 0.0;  
    for(int i = 1; i < n-1; i++) {  
        area += Cross(po[i]-po[0], po[i+1]-po[0]);  
    }  
    return area * 0.5;  
}  
  
//点在多边形内的判定(多边形顶点需按逆时针排列)  
bool isInPolygon(const Point& p, const Polygon& poly) {  
    int n = poly.size();  
    for(int i = 0; i < n; i++) {  
        //若允许点在多边形边上，可关闭下行注释  
        // if (isOnSegment(p, poly[(i+1)%n], poly[i])) return true;  
        if (Cross(poly[(i+1)%n]-poly[i], p-poly[i]) < 0) return false;  
    }  
    return true;  
}  
  
//过定点作圆的切线  
int getTangents(const Point& P, const Circle& C, std::vector<Line>& L) {  
    Vector u = C.c - P;  
    double dis = Length(u);  
    if (dcmp(dis - C.r) < 0) return 0;  
    if (dcmp(dis - C.r) == 0) {  
        L.push_back(Line(P, Rotate(u, PI / 2.0)));  
        return 1;  
    }  
    double ang = asin(C.r / dis);  
    L.push_back(Line(P, Rotate(u, ang)));  
    L.push_back(Line(P, Rotate(u, -ang)));  
    return 2;  
}  
  
//直线和圆的交点  
int GetLineCircleIntersection(Line& L, const Circle& C, vector<Point>& sol) {  
    double t1, t2;  
    double a = L.dir.x, b = L.P.x - C.c.x, c = L.dir.y, d = L.P.y - C.c.y;  
    double e = a*a + c*c, f = 2.0*(a*b + c*d), g = b*b + d*d - C.r*C.r;  
    double delta = f*f - 4*e*g; //判别式  
    if (dcmp(delta) < 0) return 0;  //相离  
    if (dcmp(delta) == 0) { //相切  
      t1 = t2 = -f / (2 * e);  
      sol.push_back(L.point(t1));  
      return 1;  
    }  
    t1 = (-f - sqrt(delta)) / (2.0 * e); sol.push_back(L.point(t1));    // 相交  
    t2 = (-f + sqrt(delta)) / (2.0 * e); sol.push_back(L.point(t2));  
    return 2;  
}
const int N = 2100;
int n,m,r,a,x[N],y[N];

double fans[N];

Point st,ed;

void calc(){
    Line l(st,ed-st);
    vector<Point> lc;
    vector<Point> ll;
    vector<pair<double,int> > ans;
    Vector dir(ed-st);
    Vector dl = Rotate(dir,(double)a*PI/180.0);
    Vector dr = Rotate(dir,-(double)a*PI/180.0);
    ans.push_back(make_pair(0,0));
    //dir.out();
    for(int i=1;i<=m;i++){
        //printf("calc i=%d\n",i);fflush(stdout);
        Point A(x[i],y[i]);
        //A.out();cout << endl;
        Line l1(A,dl),l2(A,dr);
        ll.clear();
        ll.push_back(GetLineIntersection(l,l1));
        ll.push_back(GetLineIntersection(l,l2));
        Circle C(A,r);
        lc.clear();
        GetLineCircleIntersection(l,C,lc);
        if(lc.size()<=0)continue;
        //cout << '*' << endl;
        if(Dot(ll[0]-st,dir) > Dot(ll[1]-st,dir))swap(ll[0],ll[1]);
        if(lc.size()>=1 && Dot(lc[0]-st,dir) > Dot(lc[1]-st,dir))swap(lc[0],lc[1]);
        //cout << Length(dir) << ' ' << ll.size() << ' ' << lc.size() << endl;
        //lc[0].out();cout << endl;
        //if(lc.size()<=0)lc[1].out();cout << endl;
        
        double Cpos = Dot(lc[0]-st,dir)/Length(dir);
        double Lpos = Dot(ll[0]-st,dir)/Length(dir);
        //printf("Cpos=%.5lf,Lpos=%.5lf\n",Cpos,Lpos);fflush(stdout);
        if(Cpos < 0)Cpos = 0;
        if(Cpos > Lpos)continue;
        ans.push_back(make_pair(Cpos,1));
        ans.push_back(make_pair(Lpos,-1));
    }
    ans.push_back(make_pair(Length(dir),1));
    sort(ans.begin(),ans.end());
    double lastpos = 0;
    int cur=0;
    for(auto t:ans){
        double pos = t.first,val = t.second;
        if(val == 0)continue;
        fans[cur] += pos-lastpos;
        cur+=val;
        //printf("seg length=%.5lf,cur=%d\n",pos-lastpos,cur);
        lastpos = pos;
    }
}

int main(){
    int xx[N],yy[N];
    scanf("%d%d%d%d",&n,&m,&r,&a);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&xx[i],&yy[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    xx[n+1]=xx[1];yy[n+1]=yy[1];
    for(int i=1;i<=n;i++){
        st = Point(xx[i],yy[i]);
        ed = Point(xx[i+1],yy[i+1]);
        calc();
    }
    for(int i=0;i<=m;i++){
        printf("%.10lf\n",fans[i]);
    }
}