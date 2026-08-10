#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long double D;
const int N=11;
D INF=1e18,eps=1e-9;
int T,n,m;
D ans,curans,curx;
int sumw,SUMW;
int prei;
int a[N],h[N],w[N],vis[N];

struct Point{
    D x,y;
    Point(D x=0.0,D y=0.0):x(x),y(y){}
    friend Point operator -(const Point A, const Point B){return Point(A.x-B.x,A.y-B.y);}
} O;
typedef Point Vector;

D Cross(Vector A,Vector B){
    return A.x*B.y-A.y*B.x;
}
D Length(Vector A){
    return sqrt(A.x*A.x+A.y*A.y);
}

D f(D x){
    D tmp=0;
    for(int i=m;i>=1;i--){
        tmp = tmp+a[i];
        tmp = tmp*x;
    }
    return tmp;
}

D df(D x){
    D tmp=0;
    for(int i=m;i>=1;i--){
        tmp = tmp*x;
        tmp = tmp+a[i]*i;
    }
    __float128 tt = 1.0+(__float128)tmp*tmp;
    tt = sqrtl(tt);
    return (D)tt;
}

D simpson(D L,D R){
    int n=500;
    D h = (R-L)/(D)n;
    D ret=(df(L)+df(R))*h/3.0;
    D odd=0,even=0;
    for(int i=1;i<n;i+=2)odd += df(L+i*h)*h/3.0;
    for(int i=2;i<n;i+=2)even += df(L+i*h)*h/3.0;
    return ret+odd*4+even*2;
}

D nxtx(D X,D H,D h2){
    //printf("find next x from X=%.5Lf,H=%.5Lf,h2=%.5Lf\n",X,H,h2);
    __float128 le=X,ri=INF,mi=(le+ri)/2.0;
    D Y = f(X)+H;
    //printf("Y=%.5Lf\n",Y);
    Point A;A.x=X;A.y=Y;
    while(le < ri-eps){
        mi=(le+ri)/2.0;
        Point B = Point(mi,f(mi));
        //if(X == 0 && Y == 3){
        //    printf("B = %.5Lf,%.5Lf,Length = %.5Lf\n",B.x,B.y,Length(B-Point(X,f(X))));
        //}
        if(Cross(A-O,B-O)>0 && Length(B-Point(X,f(X)))>max(H,h2)){
            ri = mi;
        }
        else le=mi;
    }
    mi = (le+ri)/2.0;
    //printf("return %.5Lf\n",mi);
    return mi;
}

void dfs(int dep,int prei){
    if(dep >= n){
        ans = min(ans,curans);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            D tx = curx;
            if(dep==0)curx=0;
            else curx = nxtx(curx,h[prei],h[i]);
            D tans = curans;
            if(dep != 0){
                curans += (SUMW-sumw)*simpson(tx,curx);
                //cout << SUMW << ' ' << sumw << endl;
                //printf("prei=%lld,i=%lld,sumw=%lld,curans += %lld * %.5Lf\n",prei,i,sumw,SUMW-sumw,simpson(tx,curx));
            }
            //printf("dep=%lld,tx=%.5Lf,curx=%.5Lf,tans=%.5LF,curans=%.5LF\n",dep,tx,curx,tans,curans);

            sumw += w[i];
            dfs(dep+1,i);
            sumw -= w[i];

            curx=tx;
            curans = tans;
            vis[i]=0;
        }
    }
}
void output(long double x){
    static char s[25];
    sprintf(s,"%.4Le",x);
    for(int i:{0,1,2,3,4,5,6,7}) printf("%c",s[i]);
    printf("%c",s[strlen(s)-1]);
}

void solve(){
    
    ans = INF;
    if(n==1){
        printf("0.0000e+0\n");
        return;
    }
    sumw=0;curans=0;curx=0;
    dfs(0,0);
    output(ans);
    putchar('\n');
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        int x,y;
        cin >> n >> m >> x >> y;
        O.x=x;O.y=y;
        for(int i=1;i<=m;i++){
            cin >> a[i];
        }
        SUMW=0;
        for(int i=1;i<=n;i++){
            cin >> h[i] >> w[i];
            SUMW += w[i];
        }
        solve();
    }
}