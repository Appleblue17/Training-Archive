#include <bits/stdc++.h>
using namespace std;
#define int long long
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

bool feasible_lp(const vector<Line>& ls, long double& sx, long double& sy) {
    vector<pair<long double,long double>> pts;
    int n = ls.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a1 = ls[i].a, b1 = ls[i].b, c1 = ls[i].c;
            int a2 = ls[j].a, b2 = ls[j].b, c2 = ls[j].c;
            __int128 det = (__int128)a1 * b2 - (__int128)a2 * b1;
            if (det == 0) continue;
            __int128 numx = (__int128)c1 * b2 - (__int128)c2 * b1;
            __int128 numy = (__int128)a1 * c2 - (__int128)a2 * c1;
            long double x = (long double)numx / (long double)det;
            long double y = (long double)numy / (long double)det;
            bool ok = true;
            for (auto& L : ls) {
                if ((long double)L.a * x + (long double)L.b * y > (long double)L.c + 1e-9L) {
                    ok = false;
                    break;
                }
            }
            if (ok) pts.push_back({x, y});
        }
    }
    if (pts.empty()) return false;
    sx = sy = 0;
    for (auto& p : pts) {
        sx += p.first;
        sy += p.second;
    }
    sx /= pts.size();
    sy /= pts.size();
    return true;
}

bool solve_ilp(const vector<Line>& ls, int& X, int& Y) {
    long double x, y;
    if (!feasible_lp(ls, x, y)) return false;

    int rx = llroundl(x), ry = llroundl(y);
    if (fabsl(x - rx) < 1e-10L && fabsl(y - ry) < 1e-10L) {
        bool ok = true;
        for (auto& L : ls) {
            if ((__int128)L.a * rx + (__int128)L.b * ry > L.c) {
                ok = false;
                break;
            }
        }
        if (ok) {
            X = rx; Y = ry;
            return true;
        }
    }

    long double fx = fabsl(x - floorl(x));
    long double fy = fabsl(y - floorl(y));
    if (fx >= fy) {
        int fl = floorl(x);
        int ce = ceill(x);
        vector<Line> L1 = ls; L1.push_back({1, 0, fl});
        if (solve_ilp(L1, X, Y)) return true;
        vector<Line> L2 = ls; L2.push_back({-1, 0, -ce});
        return solve_ilp(L2, X, Y);
    } else {
        int fl = floorl(y);
        int ce = ceill(y);
        vector<Line> L1 = ls; L1.push_back({0, 1, fl});
        if (solve_ilp(L1, X, Y)) return true;
        vector<Line> L2 = ls; L2.push_back({0, -1, -ce});
        return solve_ilp(L2, X, Y);
    }
}
// -------------------------------------------

int T,a,b,c,g;

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
    
    cout<<ans<<endl;

    for(int k=ans-1;k>=0;k--){
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

        int s,t;
        if(solve_ilp(ls,s,t)){
            int x=A*t + C*s;
            int y=B*t - D*s;
            // cout<<"! find: "<<t<<","<<s<<" "<<x<<","<<y<<" "<<x+y<<endl;
            // cout<<"  X,Y = "<<X<<" "<<Y<<"  lim = "<<X+Y-K<<" "<<K<<endl;
            
            int xx=X-x,yy=Y-y;
            int val1=((x*b+y*c)*g+a)/K,val2=((xx*b+yy*c)*g+a)/K;
            cout<<val1<<" "<<val2<<endl;
            if(k){
                int nxt; cin>>nxt;
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

    cin>>a>>b>>c;
    b-=a, c-=a;
    g=__gcd(b,c);
    b/=g, c/=g;

    cin>>T;
    while(T--){
        int d;
        cin>>d; d-=a;
        int res=solve(d);
        if(!res) cout<<-1<<endl;
    }
}