#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define MAXN 1000010
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ull,ull> puu;
//mt19937_64 rng(GetTickCount());
template <typename T>inline void read(T &x){
    x=0;char c=getchar();bool f=0;
    for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
    for(;c>='0'&&c<='9';c=getchar())
    x=(x<<1)+(x<<3)+(c^48);
    x=(f?-x:x);
}
const int mo=1e9+7;
using namespace std;
ll n,x,y;
const double eps=1e-7;
 
#define Vector Point
 
#define pi 3.1415926535897932384626  
 
int dcmp(double x) { return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1); }  
 
struct Point {  
    double x, y;  
 
    Point(const Point& rhs): x(rhs.x), y(rhs.y) { } //拷贝构造函数  
    Point(double x = 0.0, double y = 0.0): x(x), y(y) { }   //构造函数  
 
    friend Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }  
    friend Vector operator - (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }  
    friend Vector operator * (const Vector& A, const double& p) { return Vector(A.x*p, A.y*p); }  
    friend Vector operator / (const Vector& A, const double& p) { return Vector(A.x/p, A.y/p); }  
    friend bool operator == (const Point& A, const Point& B) { return dcmp(A.x-B.x) == 0 && dcmp(A.y-B.y) == 0; }  
    friend bool operator < (const Point& A, const Point& B) { return A.x < B.x || (A.x == B.x && A.y < B.y); }  
   
    void in(void) { scanf("%lf%lf", &x, &y); }  
    void out(void) { printf("%lf %lf\n", x, y); }  
};
 
vector<Point> p;
 
double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }  //点积  
double Length(const Vector& A){ return sqrt(Dot(A, A)); }  
double Angle(const Vector& A, const Vector& B) { return acos(Dot(A, B)/Length(A)/Length(B)); }  //向量夹角  
double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }    //叉积  
 
bool isOnSegment(const Point& P, const Point& A, const Point& B) {  
    //若允许点与端点重合，可关闭下面的注释  
    //if (P == A || P == B) return true;  
    return dcmp(Cross(A-P, B-P)) == 0 && dcmp(Dot(A-P, B-P)) <= 0;  
    //return dcmp(Length(P-A) + Length(B-P) - Length(A-B)) == 0;  
}  
 
bool isInPolygon(Point& p, vector<Point>& poly) {  
    int n = poly.size();  
    for(int i = 0; i < n; i++) {  
        //若允许点在多边形边上，可关闭下行注释
        if (isOnSegment(p, poly[(i+1)%n], poly[i])) return true;  
        if (Cross(poly[(i+1)%n]-poly[i], p-poly[i]) < 0) return false;  
    }  
    return true;  
}
vector<double> a;
ll X[MAXN],Y[MAXN];
void solve(){
    scanf("%lld",&n);
    scanf("%lld",&x);
    scanf("%lld",&y);
    Point P;
    P.x=x;P.y=y;
    p.clear();
    for(int i=1;i<=n;i++){
        Point t;
        scanf("%lld%lld",&X[i],&Y[i]);
        t.x = X[i];t.y = Y[i];
        p.push_back(t);
    }
    if(!isInPolygon(P,p)){
        printf("%.10lf\n",2.0*pi);
        return;
    }
    else{
        ll mx=0;
        for(int i=1;i<=n;i++){
            mx = max(mx,(X[i]-x)*(X[i]-x)+(Y[i]-y)*(Y[i]-y));
        }
        a.clear();
        for(int i=0;i<p.size();i++){
            if((X[i+1]-x)*(X[i+1]-x)+(Y[i+1]-y)*(Y[i+1]-y) < mx)continue;
            a.push_back(atan2(p[i].y-P.y,p[i].x-P.x));
            //printf("a push_back %.5lf\n",atan2(p[i].y-P.y,p[i].x-P.x));
        }
        sort(a.begin(),a.end());
        a.push_back(a[0]+2*pi);
        double ans=0;
        for(int i=0;i+1<(int)a.size();i++){
            ans = max(ans,a[i+1]-a[i]);
        }
        printf("%.10lf\n",ans);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        solve();
    }
}
