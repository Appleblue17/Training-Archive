#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,INF=1e18;

struct p2{
    int x,y;
    p2(int x,int y):x(x),y(y){}
    friend p2 operator - (p2 a,p2 b){return p2(a.x-b.x,a.y-b.y);}
};

vector<p2> p;

int Cross(p2 a,p2 b){
    return a.x*b.y-a.y*b.x;
}

int area2(p2 a,p2 b,p2 c){
    return abs(Cross(b-a,c-a));
}

void solve(){
    int n,k,S=0,fans=0,j=0;
    p.clear();
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        p.push_back(p2(x,y));
    }
    
    for(int i=0;i<n;i++){
        p.push_back(p[i]);
    }
    for(int i=0;i+2<=k;i++){
        S += area2(p[i],p[i+1],p[k]);
    }
    j=k;
    for(int i=0;i<n;i++){
        while(j <= i+k)j++;
        while(j+1 < i+n && area2(p[i],p[i+k],p[j]) < area2(p[i],p[i+k],p[j+1]))j++;
        //printf("i=%lld,j=%lld\n",i,j);fflush(stdout);
        //cout << S+area2(p[i],p[i+k],p[j]) << endl;
        fans = max(fans,S+area2(p[i],p[i+k],p[j]));
        S -= area2(p[i],p[i+1],p[i+k]);
        S += area2(p[i+1],p[i+k],p[i+k+1]);
    }
    printf("%.10Lf\n",(long double)fans/2.0);
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--){
        solve();
    }
}
