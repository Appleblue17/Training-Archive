#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N=10000;
const int M=10000;
const int INF=1e9;
char s[N];

#define Vector Point

const double eps = 1e-9;
const double PI = acos(-1);

int dcmp(double x) { return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1); }  
  
struct Point {  
    double x, y;  
    double Cang;
    int Cid;
  
    //Point(const Point& rhs): x(rhs.x), y(rhs.y) { } //拷贝构造函数  
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

vector<Point> p;
  
struct Line {  
    Point P;    //直线上一点  
    Vector dir; //方向向量(半平面交中该向量左侧表示相应的半平面)  
    double ang; //极角，即从x正半轴旋转到向量dir所需要的角（弧度）  
  
    Line() { }  //构造函数  
    //Line(const Line& L): P(L.P), dir(L.dir), ang(L.ang) { }  
    Line(const Point& P, const Vector& dir): P(P), dir(dir) { ang = atan2(dir.y, dir.x); }  
  
    bool operator < (const Line& L) const { //极角排序  
        return ang < L.ang;  
    }  
  
    Point point(double t) { return P + dir*t; }  
};
  
struct Circle {  
    Point c;    //圆心  
    double r;   //半径  
  
    Circle() { }  
    //Circle(const Circle& rhs): c(rhs.c), r(rhs.r) { }  
    Circle(const Point& c, const double& r): c(c), r(r) { }  
  
    Point point(double ang) const { return Point(c.x + cos(ang)*r, c.y + sin(ang)*r); } //圆心角所对应的点  
    double area(void) const { return PI * r * r; }  
} a[110];
  
double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }  //点积  
double Length(const Vector& A){ return sqrt(Dot(A, A)); }  
double Angle(const Vector& A, const Vector& B) { return acos(Dot(A, B)/Length(A)/Length(B)); }  //向量夹角  
double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }    //叉积  
double Area(const Point& A, const Point& B, const Point& C) { return fabs(Cross(B-A, C-A)); }  

vector<Point> ConvexHull(vector<Point> p) {  
    //预处理，删除重复点  
    sort(p.begin(), p.end());  
    p.erase(unique(p.begin(), p.end()), p.end());  
    int n = p.size(), m = 0;  
    vector<Point> res(n+1);  
    for(int i = 0; i < n; i++) {  
        while(m > 1 && Cross(res[m-1]-res[m-2], p[i]-res[m-2]) <= 0) m--;  
        res[m++] = p[i];  

    }  
    int k = m;  
    for(int i = n-2; i >= 0; i--) {  
        while(m > k && Cross(res[m-1]-res[m-2], p[i]-res[m-2]) <= 0) m--;  
        res[m++] = p[i];  

    }  
    m -= n > 1;  
    res.resize(m);  
    return res;  
}

Vector Rotate(const Vector& A, const double& rad) { return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad)); }  

Vector Polar(double angle) {
    return Vector(cos(angle), sin(angle));
}
vector<Point> resa,resb;
vector<Point> GetCommonTangents(const Circle& A, const Circle& B) {
    resa.clear();resb.clear();
    vector<Point> res;//可以改为vector<Line>等，按需要决定
    Vector v = B.c - A.c;
    double d = Length(v);
    if (dcmp(d) == 0) {
        if (dcmp(A.r - B.r) == 0) {
            // 同心且半径相等，有无数条公切线，但无法枚举，返回空
        }
        // 同心但半径不等，无公切线
        return res;
    }
    double base = atan2(v.y, v.x);
    double r_sum = A.r + B.r;
    double r_diff = fabs(A.r - B.r);

    // 计算外公切线 (d >= |r1 - r2| 时存在)
    if (dcmp(d - r_diff) >= 0) {
        double alpha = asin(r_diff / d);
        double angles[2] = { base + (PI / 2 - alpha), base - (PI / 2 - alpha) };
        //cout << base << ' ' << alpha << endl;
        for (int i = 0; i < 2; i++) {
            Vector unit_vec = Polar(angles[i]);
            //cout << angles[i] << ' ' << unit_vec << ' ' << A.r << ' ' << B.r << endl;
            Point p1 = A.c + unit_vec * A.r;
            Point p2 = B.c + unit_vec * B.r;
            Line line = Line(p1, p2 - p1);
            //TangentLine tl;
            //tl.line = line;
            //tl.point_on_first = p1;
            //tl.point_on_second = p2;
            //tl.type = 0; // external
            res.push_back(p1);res.push_back(p2);
            resa.push_back(p1);resb.push_back(p2);
        }
    }

    // 计算内公切线
    if (dcmp(d - r_sum) >= 0) { // 相离或外切
        double beta = acos(r_sum / d);
        double angles[2] = { base + (PI / 2 - beta), base - (PI / 2 - beta) };
        for (int i = 0; i < 2; i++) {
            Vector unit_vec = Polar(angles[i]);
            Point p1 = A.c + unit_vec * A.r;
            Point p2 = B.c - unit_vec * B.r; // 异侧
            Line line = Line(p1, p2 - p1);
            //TangentLine tl;
            //tl.line = line;
            //tl.point_on_first = p1;
            //tl.point_on_second = p2;
            //tl.type = 1; // internal
            //res.push_back(p1);res.push_back(p2);
            resa.push_back(p1);resb.push_back(p2);
        }
    } else if (dcmp(d - r_diff) == 0) { // 内切
        Point p = A.c + v * (A.r / d);
        Vector dir = Rotate(v, PI / 2);
        Line line = Line(p, dir);
        //TangentLine tl;
        //tl.line = line;
        //tl.point_on_first = p;
        //tl.point_on_second = p;
        //tl.type = 1; // internal
        //res.push_back(p);
        resa.push_back(p);resb.push_back(p);
        res.push_back(p);
    }
    sort(res.begin(), res.end());
    // unique将重复元素移至末尾，返回新逻辑结尾，返回点需要进行这个操作，返回边不需要
    auto last = unique(res.begin(), res.end());
    res.erase(last, res.end());
    return res;
}

double PolygonArea(vector<Point> po) {  
    int n = po.size();  
    double area = 0.0;  
    for(int i = 1; i < n-1; i++) {  
        area += Cross(po[i]-po[0], po[i+1]-po[0]);  
    }  
    return area * 0.5;  
}  

int n;

signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        int x,y,r;
        scanf("%lld%lld%lld",&x,&y,&r);
        a[i].c = Point(x,y);
        a[i].r = r;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            vector<Point> P = GetCommonTangents(a[i],a[j]);
            for(Point A:P){
                //printf("tangent points of circle %lld and %lld includes (%.5lf,%.5lf)\n",i,j,A.x,A.y);
                
                if(dcmp(Length(A-a[i].c)-a[i].r)==0){
                    A.Cid = i;
                    A.Cang = atan2((A-a[i].c).y,(A-a[i].c).x);
                }
                else{
                    A.Cid = j;
                    A.Cang = atan2((A-a[j].c).y,(A-a[j].c).x);
                }
                p.push_back(A);

            }
        }
    }
    //for(Point v:p){
    //    printf("p includes %.5lf,%.5lf,Cid=%lld\n",v.x,v.y,v.Cid);
    //}
    vector<Point> c = ConvexHull(p);
    double S = PolygonArea(c);
    ///cout << S << endl;
    double L = 0;
    c.push_back(c[0]);
    //for(Point v:c){
    //    printf("c includes %.5lf,%.5lf,Cid=%lld\n",v.x,v.y,v.Cid);
    //}
    for(int i=1;i<c.size();i++){
        if(c[i].Cid == c[i-1].Cid){
            //printf("Cang = %.5lf,%.5lf\n",c[i-1].Cang,c[i].Cang);
            double an = c[i].Cang - c[i-1].Cang;
            double r = a[c[i].Cid].r;
            Point cc = a[c[i].Cid].c;
            if(c[i].Cang < c[i-1].Cang)an = c[i].Cang - c[i-1].Cang + 2*PI;
            L += an*r;
            S += an*r*r*0.5-0.5*Cross(c[i-1]-cc,c[i]-cc);
        }
        else{
            L += Length(c[i]-c[i-1]);
        }
    }
    printf("%.10lf %.10lf\n",L,S);
}