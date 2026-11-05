#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::int256_t;
#define int __int128
// #define int long long
#define ll long long
// #define i128 __int128
const int N=110,INF=9e18;

int exgcd(int a,int b,int& x,int& y){
    if(!b){
        x=1,y=0;
        return a;
    }
    int tmp=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return tmp;
}

int myfloor(int x,int y){
    assert(y>0);
    if(x>0) return x/y;
    else return -((-x+y-1)/y);
}
int myceil(int x,int y){
    assert(y>0);
    if(x>0) return (x+y-1)/y;
    else return -((-x)/y);
}

// ---------- 2-D integer feasibility ----------
struct Line {
    int a, b, c; // a*s + b*t <= c
};

bool feasible_lp(const vector<Line>& ls, long double& sx, long double& sy,
                 int& xlo, int& xhi, int& ylo, int& yhi) {
    vector<pair<long double,long double>> pts;
    int n = ls.size();
    bool got = false;
    int256_t xmn = 0, xmd = 1, xMx = 0, xMd = 1;
    int256_t ymn = 0, ymd = 1, yMx = 0, yMd = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int256_t a1 = ls[i].a, b1 = ls[i].b, c1 = ls[i].c;
            int256_t a2 = ls[j].a, b2 = ls[j].b, c2 = ls[j].c;
            int256_t det = a1 * b2 - a2 * b1;
            if (det == 0) continue;
            int256_t numx = c1 * b2 - c2 * b1;
            int256_t numy = a1 * c2 - a2 * c1;
            if (det < 0) { det = -det; numx = -numx; numy = -numy; }
            long double x = numx.convert_to<long double>() / det.convert_to<long double>();
            long double y = numy.convert_to<long double>() / det.convert_to<long double>();
            bool ok = true;
            for (auto& L : ls) {
                if ((int256_t)L.a * numx + (int256_t)L.b * numy > (int256_t)L.c * det) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                pts.push_back({x, y});
                if (!got) {
                    xmn = xMx = numx; xmd = xMd = det;
                    ymn = yMx = numy; ymd = yMd = det;
                    got = true;
                } else {
                    if (numx * xmd < xmn * det) { xmn = numx; xmd = det; }
                    if (numx * xMd > xMx * det) { xMx = numx; xMd = det; }
                    if (numy * ymd < ymn * det) { ymn = numy; ymd = det; }
                    if (numy * yMd > yMx * det) { yMx = numy; yMd = det; }
                }
            }
        }
    }
    if (!got) return false;

    auto ceil_div = [](int256_t num, int256_t den) -> int256_t {
        if (num >= 0) return (num + den - 1) / den;
        return -((-num) / den);
    };
    auto floor_div = [](int256_t num, int256_t den) -> int256_t {
        if (num >= 0) return num / den;
        return -((-num + den - 1) / den);
    };
    xlo = ceil_div(xmn, xmd).convert_to<__int128>();
    xhi = floor_div(xMx, xMd).convert_to<__int128>();
    ylo = ceil_div(ymn, ymd).convert_to<__int128>();
    yhi = floor_div(yMx, yMd).convert_to<__int128>();

    sx = sy = 0;
    for (auto& p : pts) {
        sx += p.first;
        sy += p.second;
    }
    sx /= pts.size();
    sy /= pts.size();
    return true;
}

int256_t floordiv256(int256_t n, int256_t d) {
    if (n >= 0) return n / d;
    return -((-n + d - 1) / d);
}
int256_t ceildiv256(int256_t n, int256_t d) {
    if (n >= 0) return (n + d - 1) / d;
    return -((-n) / d);
}

bool try_t_value(const vector<Line>& base, int tv, int& X, int& Y) {
    int256_t lo = -(((int256_t)1) << 240);
    int256_t hi =  (((int256_t)1) << 240);
    for (auto& L : base) {
        int256_t rem = (int256_t)L.c - (int256_t)L.b * tv;
        if (L.a == 0) {
            if (rem < 0) return false;
        } else if (L.a > 0) {
            hi = min(hi, floordiv256(rem, L.a));
        } else {
            lo = max(lo, -floordiv256(rem, -L.a));
        }
    }
    if (lo > hi) return false;
    int256_t sv = lo;
    for (auto& L : base) {
        if ((int256_t)L.a * sv + (int256_t)L.b * tv > (int256_t)L.c) return false;
    }
    X = sv.convert_to<__int128>();
    Y = tv;
    return true;
}

bool solve_ilp_rec(const vector<Line>& base, int xlo, int xhi,
                    int ylo, int yhi, int& X, int& Y) {
    vector<Line> ls = base;
    ls.push_back({1, 0, xhi});
    ls.push_back({-1, 0, -xlo});
    ls.push_back({0, 1, yhi});
    ls.push_back({0, -1, -ylo});

    long double x, y;
    int xmin, xmax, ymin, ymax;
    if (!feasible_lp(ls, x, y, xmin, xmax, ymin, ymax)) return false;

    auto exact = [&](int px, int py) -> bool {
        if (px < xlo || px > xhi || py < ylo || py > yhi) return false;
        for (auto& L : base) {
            if ((int256_t)L.a * px + (int256_t)L.b * py > (int256_t)L.c) return false;
        }
        return true;
    };

    int rx = llroundl(x), ry = llroundl(y);
    if (exact(rx, ry)) { X = rx; Y = ry; return true; }

    int fx0 = floorl(x), fx1 = ceill(x);
    int fy0 = floorl(y), fy1 = ceill(y);
    int cx[2] = {fx0, fx1}, cy[2] = {fy0, fy1};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (exact(cx[i], cy[j])) { X = cx[i]; Y = cy[j]; return true; }
        }
    }

    int nxlo = max(xlo, xmin);
    int nxhi = min(xhi, xmax);
    int nylo = max(ylo, ymin);
    int nyhi = min(yhi, ymax);

    if (nxlo > nxhi || nylo > nyhi) return false;
    if (nxlo == nxhi && nylo == nyhi) {
        if (exact(nxlo, nylo)) { X = nxlo; Y = nylo; return true; }
        return false;
    }

    int xr = nxhi - nxlo + 1;
    int yr = nyhi - nylo + 1;

    // Split the larger integer range at its midpoint.  Branch constraints are
    // kept as a box, so the LP always has only the original 6 + 4 lines.
    if (xr >= yr) {
        int mid = nxlo + (nxhi - nxlo) / 2;
        if (x <= (long double)mid) {
            if (solve_ilp_rec(base, nxlo, mid, nylo, nyhi, X, Y)) return true;
            return solve_ilp_rec(base, mid + 1, nxhi, nylo, nyhi, X, Y);
        } else {
            if (solve_ilp_rec(base, mid + 1, nxhi, nylo, nyhi, X, Y)) return true;
            return solve_ilp_rec(base, nxlo, mid, nylo, nyhi, X, Y);
        }
    } else {
        int mid = nylo + (nyhi - nylo) / 2;
        if (y <= (long double)mid) {
            if (solve_ilp_rec(base, nxlo, nxhi, nylo, mid, X, Y)) return true;
            return solve_ilp_rec(base, nxlo, nxhi, mid + 1, nyhi, X, Y);
        } else {
            if (solve_ilp_rec(base, nxlo, nxhi, mid + 1, nyhi, X, Y)) return true;
            return solve_ilp_rec(base, nxlo, nxhi, nylo, mid, X, Y);
        }
    }
}

bool solve_ilp(const vector<Line>& ls, int& X, int& Y) {
    long double x, y;
    int xlo, xhi, ylo, yhi;
    if (!feasible_lp(ls, x, y, xlo, xhi, ylo, yhi)) return false;

    auto exact0 = [&](int px, int py) -> bool {
        for (auto& L : ls) {
            if ((int256_t)L.a * px + (int256_t)L.b * py > (int256_t)L.c) return false;
        }
        return true;
    };
    int rx = llroundl(x), ry = llroundl(y);
    if (exact0(rx, ry)) { X = rx; Y = ry; return true; }

    // Cheap heuristic requested: search integer points around the centroid.
    for (int dx = -3; dx <= 3; ++dx) {
        for (int dy = -3; dy <= 3; ++dy) {
            int px = rx + dx, py = ry + dy;
            if (exact0(px, py)) { X = px; Y = py; return true; }
        }
    }

    if (xlo > xhi || ylo > yhi) return false;

    // Also try the four corners and the midpoint of the exact integer box.
    int xs[2] = {xlo, xhi}, ys[2] = {ylo, yhi};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (exact0(xs[i], ys[j])) { X = xs[i]; Y = ys[j]; return true; }
        }
    }
    int xm = xlo + (xhi - xlo) / 2;
    int ym = ylo + (yhi - ylo) / 2;
    if (exact0(xm, ym)) { X = xm; Y = ym; return true; }

    // Fast path: fix the second variable t, then the constraints reduce to a
    // 1-D interval for the first variable s.  Sample t and try the interval's
    // left endpoint; this finds a point in a few tries when the feasible set
    // is not extremely thin.
    int256_t trange = (int256_t)yhi - (int256_t)ylo;
    auto try_t = [&](int tv) -> bool { return try_t_value(ls, tv, X, Y); };
    if (try_t(ylo) || try_t(yhi)) return true;
    int ty = llroundl(y);
    if (try_t(ty)) return true;
    if (ty > ylo && try_t(ty - 1)) return true;
    if (ty < yhi && try_t(ty + 1)) return true;

    if (trange <= 20000) {
        for (int tv = ylo; tv <= yhi; ++tv) {
            if (try_t(tv)) return true;
        }
    } else {
        unsigned long long rng = 88172645463325252ULL;
        rng ^= (unsigned long long)(long long)xlo;
        rng *= 0x9E3779B97F4A7C15ULL;
        rng ^= (unsigned long long)(long long)yhi;
        for (int it = 0; it < 20000; ++it) {
            rng ^= rng << 13; rng ^= rng >> 7; rng ^= rng << 17;
            unsigned long long r = rng >> 1;
            int256_t off = (trange * (int256_t)r) / (((int256_t)1) << 63);
            int tv = ylo + off.convert_to<__int128>();
            if (try_t(tv)) return true;
        }
    }
    return solve_ilp_rec(ls, xlo, xhi, ylo, yhi, X, Y);
}
bool add_k_interval(int base, int coef, int lo, int hi, int& klo, int& khi) {
    if (coef == 0) return base >= lo && base <= hi;
    if (coef > 0) {
        klo = max(klo, myceil(lo - base, coef));
        khi = min(khi, myfloor(hi - base, coef));
    } else {
        klo = max(klo, myceil(base - hi, -coef));
        khi = min(khi, myfloor(base - lo, -coef));
    }
    return true;
}

// Direct enumeration of the smaller of the two child coordinates.  This is
// exact and very fast when min(X,Y) is small, which happens near the bottom
// of the backward construction.
bool split_by_enum(int A, int B, int C, int D, int X, int Y, int K,
                   int& s_out, int& t_out) {
    const int BIGK = ((int)1) << 120;
    int L = X + Y - K;
    if (X <= Y) {
        int P = A, Q = C;
        int ap = P >= 0 ? P : -P;
        int aq = Q >= 0 ? Q : -Q;
        int al, be;
        int g = exgcd(ap, aq, al, be);
        int alpha = P >= 0 ? al : -al;
        int beta  = Q >= 0 ? be : -be;
        int dt = Q / g, ds = -P / g;
        int ydy = B * dt - D * ds;
        for (int xv = 0; xv <= X; ++xv) {
            if (xv % g) continue;
            int t0 = alpha * (xv / g);
            int s0 = beta  * (xv / g);
            int y0 = B * t0 - D * s0;
            int yl = max((int)0, L - xv);
            int yh = min(Y, K - xv);
            if (yl > yh) continue;
            int klo = -BIGK, khi = BIGK;
            if (!add_k_interval(y0, ydy, yl, yh, klo, khi)) continue;
            if (klo > khi) continue;
            int k = klo;
            int t = t0 + dt * k;
            int s = s0 + ds * k;
            int x = A * t + C * s;
            int y = B * t - D * s;
            if (x == xv && 0 <= y && y <= Y && L <= x + y && x + y <= K) {
                s_out = s; t_out = t;
                return true;
            }
        }
    } else {
        int P = B, Q = -D;
        int ap = P >= 0 ? P : -P;
        int aq = Q >= 0 ? Q : -Q;
        int al, be;
        int g = exgcd(ap, aq, al, be);
        int alpha = P >= 0 ? al : -al;
        int beta  = Q >= 0 ? be : -be;
        int dt = Q / g, ds = -P / g;
        int xdx = A * dt + C * ds;
        for (int yv = 0; yv <= Y; ++yv) {
            if (yv % g) continue;
            int t0 = alpha * (yv / g);
            int s0 = beta  * (yv / g);
            int x0 = A * t0 + C * s0;
            int xl = max((int)0, L - yv);
            int xh = min(X, K - yv);
            if (xl > xh) continue;
            int klo = -BIGK, khi = BIGK;
            if (!add_k_interval(x0, xdx, xl, xh, klo, khi)) continue;
            if (klo > khi) continue;
            int k = klo;
            int t = t0 + dt * k;
            int s = s0 + ds * k;
            int x = A * t + C * s;
            int y = B * t - D * s;
            if (y == yv && 0 <= x && x <= X && L <= x + y && x + y <= K) {
                s_out = s; t_out = t;
                return true;
            }
        }
    }
    return false;
}

// -------------------------------------------
ll T,a_,b_,c_;
int a,b,c,g;

bool solve(int d){
    int u,v;
    exgcd(b,c,u,v);
    
    int ans=-1,X=0,Y=0;
    for(int k=0;k<=60;k++){
        int K=(1ll<<k);
        int s=d*K;

        if(s%g) continue;
        s/=g;
        int x0=u*s,y0=v*s;
        // x=x0+c*t, y=y0-b*t
        int L=-INF,R=INF;

        // x>=0  ->  c*t >= -x0
        L=max(L,myceil(-x0,c));
        // y>=0  ->  b*t <= y0
        R=min(R,myfloor(y0,b));
        // x+y<=K ->  (x0+y0)+(c-b)t <= K
        R=min(R,myfloor(K-x0-y0,c-b)); // c>b

        if(L<=R){
            int t=L;
            X=x0+c*t, Y=y0-b*t;
            // cout<<"! find k="<<k<<", "<<L<<","<<R<<" | "<<t<<" "<<X<<" "<<Y<<endl;
            ans=k;
            break;
        }
    }
    if(ans==-1) return 0;
    
    cout<<(ll)ans<<endl;
    int lst=d;
    for(int k=ans-1;k>=0;k--){
        if(lst==0 || lst==b*g || lst==c*g){
            cout<<(ll)(lst+a)<<" "<<(ll)(lst+a)<<endl;
            if(k){
                ll nxt; cin>>nxt;
            }
            continue;
        }
        
        int K=(1ll<<k);
        int h=__gcd(g,K);
        int A=K/h*u, B=K/h*v, C=c, D=b;
        // x=A*t+C*s, y=B*t-D*s
        
        // cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;

        // Constraints on (s,t) from:
        // x = A*t + C*s >= 0
        // x = A*t + C*s <= X
        // y = B*t - D*s >= 0
        // y = B*t - D*s <= Y
        // x+y >= X+Y-K
        // x+y <= K
        vector<Line> ls = {
            { -C,      -A,       0 },          // x >= 0        : -C*s - A*t <= 0
            {  C,       A,       X },          // x <= X        :  C*s + A*t <= X
            {  D,      -B,       0 },          // y >= 0        :  D*s - B*t <= 0
            { -D,       B,       Y },          // y <= Y        : -D*s + B*t <= Y
            { -(C-D),  -(A+B),  -(X+Y-K) },    // x+y >= X+Y-K  : -(C-D)s - (A+B)t <= -(X+Y-K)
            {   C-D,    A+B,     K }           // x+y <= K      :  (C-D)s + (A+B)t <= K
        }; // as+bt<=c

        int s=0,t=0;
        bool got=false;
        if(min(X,Y) <= 200000) got=split_by_enum(A,B,C,D,X,Y,K,s,t);
        if(!got) got=solve_ilp(ls,s,t);
        if(got){
            int x=A*t + C*s;
            int y=B*t - D*s;
            // cout<<"! find: "<<t<<","<<s<<" "<<x<<","<<y<<" "<<x+y<<endl;
            // cout<<"  X,Y = "<<X<<" "<<Y<<"  lim = "<<X+Y-K<<" "<<K<<endl;
            
            int xx=X-x,yy=Y-y;
            int val1=((x*b+y*c)*g)/K+a,val2=((xx*b+yy*c)*g)/K+a;
            cout<<(ll)val1<<" "<<(ll)val2<<endl;
            if(k){
                ll nxt; cin>>nxt; lst=nxt-a;
                // cout<<"> "<<nxt<<endl;
                if(nxt==val1) X=x,Y=y;
                else X=xx,Y=yy;
            }
        }
        else assert(0);
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a_>>b_>>c_; a=a_,b=b_,c=c_;
    b-=a, c-=a;
    g=__gcd(b,c);
    b/=g, c/=g;

    cin>>T;
    while(T--){
        ll d; cin>>d;
        // cout<<"get "<<d<<endl;
        d-=a;
        int res=solve(d);
        if(!res) cout<<-1<<endl;
    }
}