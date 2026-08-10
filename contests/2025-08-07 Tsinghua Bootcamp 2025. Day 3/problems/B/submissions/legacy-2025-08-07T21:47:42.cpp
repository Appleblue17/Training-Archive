#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define int long long
//#define double long double
#define Vector Point
const double eps = 1e-9;
int n,m;
int dcmp(double x){return fabs(x)<eps?0:(x<0?-1:1);}
struct Point{
    double x,y;
    
    Point(double x=0.0,double y=0.0):x(x),y(y){}
    friend Vector operator - (const Point& A,const Point& B){return Vector(A.x-B.x,A.y-B.y);}
    friend Vector operator + (const Point& A,const Point& B){return Vector(A.x+B.x,A.y+B.y);}
    friend Vector operator * (const Point& A,const double& p){
        return Vector(A.x*p,A.y*p);
    }
    friend bool operator < (const Point& A, const Point& B) { return A.x < B.x || (A.x == B.x && A.y < B.y); }  
  
};
double Cross(const Vector& A,const Vector& B){
    return A.x*B.y-A.y*B.x;
}
double L,R,M,LS,RS;
struct Line{
    Point P;
    Vector dir;
    double ang;
    Line(){}
    //Line(const Line& L)
    Line(const Point& P,const Vector& dir):P(P),dir(dir){ang = atan2(dir.y,dir.x);}
    bool operator <(const Line& L)const{
        return ang < L.ang;
    }
};
double PolygonArea(vector<Point> po){
    int n = po.size();
    double area=0.0;
    for(int i=1;i<n-1;i++){
        area+=Cross(po[i]-po[0],po[i+1]-po[0]);
    }
    return area*0.5;
}
double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }  //点积  

bool isOnLeft(const Line& L,const Point& P){
    return dcmp(Cross(L.dir,P-L.P))>=0;
}
Point GetLineIntersection(const Line& A,const Line& B){
    Vector u = A.P - B.P;
    double t = Cross(B.dir,u)/Cross(A.dir,B.dir);
    return A.P + A.dir*t;
}

bool isOnSegment(const Point& P, const Point& A, const Point& B) {  
    //若允许点与端点重合，可将<0改为<=0  
    //if (P == A || P == B) return true;//如果不允许端点重合，对精度要求较极端可以打开
    return dcmp(Cross(A-P, B-P)) == 0 && dcmp(Dot(A-P, B-P)) < 0;  
    //return dcmp(Length(P-A) + Length(B-P) - Length(A-B)) == 0;
}  
double getIntersectArea(vector<Point> p,Line l){
    vector<Point> P;
    vector<Point> np,lsp;
    int ps = p.size();
    bool aleft=1,aright=1;
    for(int i=0;i<ps;i++){
        lsp.push_back(p[i]);
        //printf("getIntersect p contains %.5lf,%.5lf\n",p[i].x,p[i].y);fflush(stdout);
        if(isOnLeft(l,p[i]))aright=0;
        else aleft=0;
    }
    if(aleft){
        //return PolygonArea(p);
        if(p[0].x < 0)return LS;
        else return RS;
    }
    if(aright){
        return 0;
    }
    for(Point v:lsp)p.push_back(v);
    int u=0;
    while(isOnLeft(l,p[u]))u++;
    while(!isOnLeft(l,p[u]))u++;
    while(isOnLeft(l,p[u])){
        P.push_back(p[u]);
        //printf("upper half pushed %.5lf,%.5lf\n",p[u].x,p[u].y);
        u++;
    }
    for(int i=1;i<=ps;i++){
        if(isOnSegment(GetLineIntersection(l,Line(p[i-1],p[i]-p[i-1])),p[i-1],p[i])){
            np.push_back(GetLineIntersection(l,Line(p[i-1],p[i]-p[i-1])));
        }
    }
    if(!np.empty())sort(np.begin(),np.end());
    for(Point v:np){
        P.push_back(v);
    }
    //for(Point v:P){
    //    printf("result polygon contains(%.5lf,%.5lf)\n",v.x,v.y);
    //}
    return PolygonArea(P);
}
vector<Point> P1,P2;
//vector<Line> p1,p2;


bool check(double m){
    L=-4e12;R=4e12;
    int cnt=70;
    while(cnt--){
        M=(L+R)/2.0;
        Line l = Line(Point(0,M),Point(1,m));
        
        double LUP = getIntersectArea(P1,l);
        //printf("M=%.5lf,m=%.5lf,LUP=%.5lf\n",M,m,LUP);
        if(LUP > LS/2.0){
            L=M;
        }
        else R=M;
    }
    Line l = Line(Point(0,M),Point(1,m));
    double RD = getIntersectArea(P2,l);
    //printf("m=%.5lf,RUP = %.5lf\n",m,RD);
    if(RD > RS/2.0){
        return 0;
    }
    else return 1;
}
signed main(){
    //freopen("__.out","w",stdout);
    scanf("%lld",&n);
    double x,y;
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&x,&y);
        P1.push_back(Point(x,y));
    }
    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        scanf("%lf%lf",&x,&y);
        P2.push_back(Point(x,y));
    }
    LS = PolygonArea(P1);
    RS = PolygonArea(P2);
    //cout << LS << endl << RS << endl;
    /*P1.push_back(P1[0]);
    P2.push_back(P2[0]);
    for(int i=1;i<=n;i++){
        p1.push_back(Line(P1[i-1],P1[i]-P1[i-1]));
    }
    for(int i=1;i<=m;i++){
        p2.push_back(Line(P2[i-1],P2[i]-P2[i-1]));
    }
    P1.pop_back();
    P2.pop_back();*/
    //for(Line ll:p1){
    //    printf("p1 %.5lf %.5lf %.5lf %.5lf %.5lf\n",ll.P.x,ll.P.y,ll.dir.x,ll.dir.y,ll.ang);
    //}
    double l=-2e6,r=2e6,m;
    int cnt=50;
    while(cnt--){
        m=(l+r)/2.0;
        if(check(m)){
            r=m;
        }
        else{
            l=m;
        }
    }
    printf("%.4lf %.4lf\n",m,M);
}