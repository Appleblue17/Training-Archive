#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __float128 ld;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define N 1000010
#define mapa make_pair
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

const ld eps = 1e-18;

ld myabs(ld x){
    return x<0?-x:x;
}

int dcmp(ld x){
    if(myabs(x)<eps) return 0;
    else return x<0? -1:1;
}
const int mo=1e9+7;
using namespace std;

struct Point{
    ld x,y;
    Point(ld x=0,ld y=0):x(x),y(y){}
    friend bool operator == (const Point& A, const Point& B) { return dcmp(A.x-B.x) == 0 && dcmp(A.y-B.y) == 0; }  
    friend bool operator < (const Point& A, const Point& B) { return A.x < B.x || (A.x == B.x && A.y < B.y); }  
  
};
typedef Point Vector;

Vector operator + (Vector A,Vector B){
    return Vector(A.x+B.x,A.y+B.y);
}
Vector operator - (Point A,Point B){
    return Vector(A.x-B.x,A.y-B.y);
}
Vector operator * (Vector A,ld p ){
    return Vector(A.x*p,A.y*p);
}
Vector operator / (Vector A,ld p ){
    return Vector(A.x/p,A.y/p);
}






ll t,n,m,X[N],Y[N],Z[N],ans,k;

vector<Point> a,b;
Point ra;Vector rv;
const ld pi = atan2l(0,-1);
ld Cross(Vector A,Vector B){
    return A.x*B.y - A.y*B.x;
}
Point GetLineIntersection(Point P,Vector v, Point Q, Vector w){
    Vector u = P-Q;
    ld t= Cross(w,u)/Cross(v,w);
    return P+v*t;
}
ld Dot(Vector A,Vector B){
    return A.x*B.x + A.y*B.y;
}
ld Length(Vector A){
    return sqrtl(Dot(A,A));
}
//void Perpendicular(Point A,Point B){
//
//}
bool fl;
Point CircumCircle(Point A,Point B,Point C){
    fl=0;
    Point m1 = (A+B)/2;
    Vector v1 = (A-B);
    swap(v1.x,v1.y);
    v1.y = -v1.y;

    Point m2 = (A+C )/2;
    Vector v2 = (C -A);
    swap(v2.x,v2.y);
    v2.y = -v2.y;

    if(v1.y*v2.x == v1.x * v2.y){
        fl=1;
        return Point(0,0);
    }

    return GetLineIntersection(m1,v1,m2,v2);
}

double DistanceToLine(Point P,Point A,Point B){
    Vector v1=B-A,v2 = P-A;
    return Cross(v1,v2)/Length(v1);
}

bool OnSegment(Point p,Point a1, Point a2){
    return dcmp(Cross(a1-p,a2-p))==0 && dcmp(Dot(a1-p,a2-p))<=0;
}

bool OnLineOutSegment(Point p,Point a1, Point a2){
    return dcmp(Cross(a1-p,a2-p))==0 && dcmp(Dot(a1-p,a2-p))>0;
}
typedef __int128 i128;

ld ori(Point a, Point b, Point c) { return Cross((b - a) , (c - a)); }

int AinCircleP(vector<Point> p, Point a) {
    if (ori(p[0], p[1], p[2]) < 0) {
        swap(p[1], p[2]);
    }
    __int128 det = 0;
    for (int i = 0; i < 3; i++)
        det += __int128(Dot(p[i],p[i]) - Dot(a,a)) * ori(a, p[(i + 1) % 3], p[(i + 2) % 3]);
    //printf("det = %lld\n",(long long)det);
    return dcmp(det); // in:1, on:0, out:-1
}

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

bool isOnSegment(const Point& P, const Point& A, const Point& B) {  
    //若允许点与端点重合，可将<0改为<=0  
    //if (P == A || P == B) return true;//如果不允许端点重合，对精度要求较极端可以打开
    return dcmp(Cross(A-P, B-P)) == 0 && dcmp(Dot(A-P, B-P)) < 0;  
    //return dcmp(Length(P-A) + Length(B-P) - Length(A-B)) == 0;
}  

bool isInPolygon(const Point& p, const vector<Point>& poly) {
    int n = poly.size();  
    if(n == 1)return p == poly[0];//如果保证n>=3可以省去
    if(n == 2)return isOnSegment(p,poly[0],poly[1]);
    for(int i = 0; i < n; i++) {  
        //若允许点在多边形边上，可关闭下行注释  
        if (isOnSegment(p, poly[(i+1)%n], poly[i])) return true;  
        if (Cross(poly[(i+1)%n]-poly[i], p-poly[i]) < 0) return false;  
    }  
    return true;  
}  

void solve(){
	ans=0;
	scanf("%lld",&n);
    ll mx = -1e18,mn = 0;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&X[i],&Y[i],&Z[i]);
        mx = max(mx,Z[i]);
	}
    for(int i=1;i<=n;i++){
        if(Z[i]== mx || Z[i] == mn){
            b.push_back(Point(X[i],Y[i]));
        }
        else{
            a.push_back(Point(X[i],Y[i]));
        }
    }
    map<pii,int> ma;
    for(Point u:a){
        ma[mapa(u.x,u.y)]++;
    }
    vector<Point> m;
        Point x;
        for(auto it=ma.begin();it!=ma.end();it++){
            x.x = it->first.fi;
            x.y = it->first.se;
            m.push_back(x);
            //printf("m add %d,%d\n",(int)x.x,(int)x.y);
        }
    if(m.size()>=3){
        Point m1 = (m[0]+m[1])/2;
        Vector v1 = (m[1]-m[0]);
        swap(v1.x,v1.y);
        v1.y = -v1.y;

        Point m2 = (m[0]+m[2])/2;
        Vector v2 = (m[2]-m[0]);
        swap(v2.x,v2.y);
        v2.y = -v2.y;
        vector<Point> pp;
        pp.push_back(m[0]);pp.push_back(m[1]);pp.push_back(m[2]);

        //printf("%.30LF\n",(long double)(v1.y*v2.x - v1.x*v2.y));

        if(dcmp(v1.y*v2.x - v1.x*v2.y) == 0){
            printf("not a penguin\n");
            return;
        }

        Point o = GetLineIntersection(m1,v1,m2,v2);
        //cout << o.x << 
        //printf("3. O(%Lf,%Lf)\n",(long double)o.x,(long double)o.y);
        ld l = Dot(m[0]-o,m[0]-o);
        
        for(int i=3;i<m.size();i++){
            //printf("l = %Lf, mi to O length = %Lf,dcmp = %d\n",l,Length(m[i]-o),dcmp(Length(m[i]-o)-l));
            if(AinCircleP(pp,m[i]) != 0){
                printf("not a penguin\n");
                return;
            }

        }
        for(Point u:b){
            //printf("%.30LF\n",(long double)(Dot(u-o,u-o)-l));
            //if(dcmp(Dot(u-o,u-o)-l) == 1){
            if(AinCircleP(pp,u) == -1){
                printf("not a penguin\n");
                return;
            }
        }
        printf("probably\n");
        return;
    }
    else if(m.size()==2){
        Point m1 = (m[0]+m[1])/2;
        Vector v1 = (m[1]-m[0]);
        swap(v1.x,v1.y);
        v1.y = -v1.y;
        vector<ld> to_left,to_right;
        for(Point u:b){
            if(OnSegment(u,m[0],m[1]))continue;
            else if(OnLineOutSegment(u,m[0],m[1])){
                //printf("out segment\n");
                printf("not a penguin\n");
                return;
            }
            Point m3 = CircumCircle(m[0],m[1],u);
            //printf("2. u(%Lf,%Lf),m3 = (%Lf,%Lf)\n",u.x,u.y,m3.x,m3.y);
            if(fl){
                printf("not a penguin\n");
                return;
            }
            ld pos;
            if(m3.x == m1.x){
                if(m3.y == m1.y){
                    pos=0;
                }
                else{
                    pos = (m3.y-m1.y)/v1.y;
                }
            }
            else{
                pos = (m3.x-m1.x)/v1.x;
            }
            //printf("pos=%Lf\n",pos);
            if(dcmp(DistanceToLine(u,m[0],m[1]))>0 ){// on the left, ans <= pos
                
                to_left.push_back(pos);
            }
            else{
                to_right.push_back(pos);
            }
        }
        if(to_left.empty() || to_right.empty()){
            printf("probably\n");
            return;
        }
        sort(to_left.begin(),to_left.end());
        sort(to_right.begin(),to_right.end());
        if(dcmp(to_left[0] - to_right[to_right.size()-1])>=0){
            printf("probably\n");
        }
        else printf("not a penguin\n");
    }
    else if(m.size()==1){
        Point o = m[0];
        vector<Point> C;
        C = ConvexHull(b);
        for(Point u:C){
            //printf("C contains (%.10LF,%.10LF)\n",(long double)u.x,(long double)u.y);
        }
        if(((!isInPolygon(o,C))) || find(C.begin(),C.end(),o)!=C.end()){
            printf("probably\n");
        }
        else printf("not a penguin\n");
    }
    else{
        printf("probably\n");
    }
}
int main(){
    //printf("%lf\n",atan2(0,1));
    //printf("%lf\n",atan2(1,0));
    //printf("%lf\n",atan2(0,-1));
    //printf("%lf\n",atan2(-1,0));
	//int t;
	//cin >> t;
	//for(int i=1;i<=t;i++){
		solve();
	//}
}

