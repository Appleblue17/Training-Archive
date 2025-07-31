#pragma GCC Optimize(3)
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
#define pi 3.1415926535897932384626
typedef double ld;
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
const ld eps = 1e-9;
using namespace std;
ld R,d,a1;
ld theta,alpha,phi;
ld ans;
ld hat(ld D){//D length of big circle
    return 2*pi*R*R*(1-cos(D/(ld)R));
}
ld f(ld y){
    return R*(atan(sqrt(a1*a1-y*y)/sqrt(R*R-a1*a1))-alpha);
}
void solve(){
    ans=0;
    ld y0=0;
    ll t1,t2;
    scanf("%lld",&t1);
    scanf("%lld",&t2);
    R=t1;d=t2;
    int ta1,b1,c1,a2,b2,c2;
    scanf("%d%d%d%d%d%d",&ta1,&b1,&c1,&a2,&b2,&c2);
    theta = acos((ta1*a2+b1*b2+c1*c2)/(sqrt(ta1*ta1+b1*b1+c1*c1)*sqrt(a2*a2+b2*b2+c2*c2)));
    alpha = theta/2.0;
    phi = d/R;
    //printf("R=%.5Lf,d=%.5Lf,theta=%.5Lf,alpha=%.5Lf,phi=%.5Lf\n",R,d,theta,alpha,phi);fflush(stdout);
    if(d < R*pi/2.0){
        ans += hat(d);
        ans += (2*pi*R*R-hat(R*pi/2.0-d))*theta/2.0*2.0/pi;
    }
    else if(phi*2+theta > pi*2){
        ans = 4*pi*R*R;
    }
    else{
         
        phi = pi-phi;
        a1 = R*sin(phi);
        //cout << a1 << ' ' << R*sin(phi) << endl;
        //y0 = a1*a1 - (R*R-a1*a1)*tan(alpha)*tan(alpha);
        y0 = a1*a1 - (cos(phi)*cos(phi)*R*tan(alpha)*R*tan(alpha));
        y0 = sqrt(y0);
        //printf("y0=%.5Lf,a1=%.5Lf\n",y0,a1);fflush(stdout);
        int n=6000;
        ld h = y0/(ld)n;
        ans = f(0)+f(y0);
        ld odd_sum=0,even_sum=0;
        for(int i=1;i<n;i+=2){
            odd_sum += f(h*i)*4*h/3.0;
        }
        for(int i=2;i<n;i+=2){
            even_sum += f(h*i)*2*h/3.0;
        }
        ans *= h/3.0;
        ans += odd_sum+even_sum;
        ans = 4*pi*R*R - 4*ans;
    }
    printf("%.10lf\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        solve();
    }
}
